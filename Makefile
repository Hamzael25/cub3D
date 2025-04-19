# ————————————————————————————————————————————————————————————————————————————————
# Variables communes
# ————————————————————————————————————————————————————————————————————————————————
NAME         := ./cub3D
NAME_SHORT   := cub3D

CC           := gcc -g3
CFLAGS       := -Wall -Wextra -Werror

_CLEAR       := \033[0K\r\c
_OK          := [\033[32mOK\033[0m]

SRC_DIR      := srcs
OBJ_DIR      := .objs/
INC_DIR      := includes
LIBFT_DIR    := libft
MLX_DIR      := mlx_linux

MLX_A        := $(MLX_DIR)/libmlx.a
LIBFT_A      := $(LIBFT_DIR)/libft.a

HEADER       := $(INC_DIR)/cub3d.h

SRCS_MAP     := $(addprefix $(SRC_DIR)/map/, check_map.c)
SRCS_PLAY    := $(addprefix $(SRC_DIR)/play/, game.c key.c move.c raycasting.c raycast.c stage.c)
SRCS_PARSER  := $(addprefix $(SRC_DIR)/parser/, file.c parsing.c variable.c)
SRCS_UTILS   := $(addprefix $(SRC_DIR)/utils/, init.c free.c parsing_utils.c utils.c raycasting_utils.c)
SRCS_MAIN    := $(addprefix $(SRC_DIR)/, main.c)

OBJS_MAP     := $(patsubst $(SRC_DIR)/map/%.c,    $(OBJ_DIR)/map/%.o,    $(SRCS_MAP))
OBJS_PLAY    := $(patsubst $(SRC_DIR)/play/%.c,   $(OBJ_DIR)/play/%.o,   $(SRCS_PLAY))
OBJS_PARSER  := $(patsubst $(SRC_DIR)/parser/%.c, $(OBJ_DIR)/parser/%.o, $(SRCS_PARSER))
OBJS_UTILS   := $(patsubst $(SRC_DIR)/utils/%.c,  $(OBJ_DIR)/utils/%.o,  $(SRCS_UTILS))
OBJS_MAIN    := $(patsubst $(SRC_DIR)/%.c,        $(OBJ_DIR)/%.o,        $(SRCS_MAIN))

COMPOSE_FILE := docker-compose.yml

# ————————————————————————————————————————————————————————————————————————————————
# Aide & cible par défaut
# ————————————————————————————————————————————————————————————————————————————————
.PHONY: all help
all: help

help:
	@printf "\nUsage: make <target>\n\n"
	@printf "  compile        Compile le projet (libft + mlx_linux + cub3D)\n"
	@printf "  clean          Supprime l'exécutable cub3D et le dossier .objs/\n"
	@printf "  re             Relance proprement la compilation (clean + compile)\n\n"
	@printf "  build          Build uniquement l'image Docker\n"
	@printf "  up             Build + run du conteneur + compile + bash interactif\n"
	@printf "  down           Stoppe et supprime les conteneurs Docker\n"
	@printf "  reset          down → build → up (relance complète)\n"
	@printf "  prune          Nettoyage complet Docker (images, volumes, réseaux)\n"

# ————————————————————————————————————————————————————————————————————————————————
# Compilation native (Linux)
# ————————————————————————————————————————————————————————————————————————————————
.PHONY: compile $(LIBFT_A) $(MLX_A)
compile: $(LIBFT_A) $(MLX_A) $(NAME)

$(NAME): $(OBJS_MAP) $(OBJS_PLAY) $(OBJS_PARSER) $(OBJS_UTILS) $(OBJS_MAIN)
	@$(CC) $(CFLAGS) $^ -o $@ \
	    -L$(MLX_DIR) -L$(LIBFT_DIR) -lmlx -lft -lXext -lX11 -lm
	@echo "$(_OK) $(NAME_SHORT) compiled"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER)
	@printf "[..] compiling $*.c\r\c"
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@
	@printf "$(_CLEAR)"

$(LIBFT_A):
	@printf "[..] libft... compiling\r\c"
	@$(MAKE) -C $(LIBFT_DIR) -s
	@printf "$(_CLEAR)"

$(MLX_A):
	@printf "[..] mlx_linux... compiling\r\c"
	@$(MAKE) -C $(MLX_DIR) > /dev/null 2>&1
	@printf "$(_CLEAR)"


# ————————————————————————————————————————————————————————————————————————————————
# Nettoyage
# ————————————————————————————————————————————————————————————————————————————————
.PHONY: clean re
clean:
	-	@rm -f $(NAME)
	-	@rm -rf $(OBJ_DIR)
	-	@$(MAKE) -C $(LIBFT_DIR) clean -s
	-	@rm -rf $(LIBFT_A)
	-	@echo "[✅] $(NAME_SHORT) et $(OBJ_DIR) supprimés"

re: clean compile

# ————————————————————————————————————————————————————————————————————————————————
# Commandes Docker (host only)
# ————————————————————————————————————————————————————————————————————————————————
.PHONY: build docker_compose_up docker_compose_down up down reset prune

build:
	@echo "[…] Building Docker image…"
	@docker compose -f $(COMPOSE_FILE) build \
		&& echo "[✅] Image built" \
		|| echo "[❌] Build failed"

docker_compose_up:
	@docker compose -f $(COMPOSE_FILE) up -d && \
		echo "[✅] Conteneurs lancés" || \
		echo "[❌] Échec du lancement des conteneurs"

docker_compose_down:
	@docker compose -f $(COMPOSE_FILE) down --volumes --remove-orphans && \
		echo "[✅] Conteneurs arrétés" || \
		echo "[❌] Échec de l'arrêt des conteneurs"

up: build
	@echo "[…] Starting container, compiling inside…"
	@docker compose -f $(COMPOSE_FILE) run --rm cub3d \
		bash -c "make compile && exec bash"
	@echo "[…] Container exited — stopping services…"
	@docker compose -f $(COMPOSE_FILE) down --volumes --remove-orphans \
		&& echo "[✅] Docker services stopped"

down: docker_compose_down

reset: down build up

prune:
	@echo "[…] Pruning Docker system…"
	@docker system prune --all --force \
		&& docker volume prune --force \
		&& docker network prune --force \
		&& echo "[✅] Docker runed" \
		|| echo "[❌] Docker Prune failed"
