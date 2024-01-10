# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hamzaelouardi <hamzaelouardi@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/13 15:15:32 by hel-ouar          #+#    #+#              #
#    Updated: 2023/12/02 16:10:03 by hamzaelouar      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nom de l'exécutable
NAME = libft.a

# Compilateur et options de compilation
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Répertoires objets
OBJ_DIR = .objs

# Dépendances générales
HEADER = libft.h

# Chemins complets des fichiers source pour chaque sous-dossier
SRCS =	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
		ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c \
		ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
		ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c \
		ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
		ft_strlen.c ft_strmapi.c ft_strncmp.c ft_substr.c ft_strnstr.c ft_strrchr.c \
		ft_strtrim.c ft_tolower.c ft_toupper.c ft_nbr.c ft_put.c \
		ft_printf.c get_next_line_utils.c get_next_line.c ft_free.c\
		ft_sort_int_tab.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c\
		ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c\
		ft_lstiter.c ft_lstmap.c ft_split_2char.c ft_split_3char.c\
		ft_split4.c ft_dnbr.c ft_dput.c ft_dprintf.c ft_tablen.c ft_gc_ctx_create.c \
		ft_gc_ctx_delete.c ft_gc_ctx_transfer.c ft_gc_ctx_wild_manip.c \
		ft_gc_global.c ft_gc_ptr_utils.c ft_gc_static.c ft_split_token.c \
		ft_strncpy.c ft_strndup.c ft_split_space.c ft_strcpy2.c ft_list.c \
		ft_split_cub.c \

# Fichiers objets mandatory correspondants
OBJS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRCS))

# Compilation et édition de liens
all: $(NAME)

# Règle pour construire l'exécutable
$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)

# Construction des fichiers objets mandatory
$(OBJ_DIR)/%.o: %.c $(HEADER)
	@mkdir -p $(@D)
	@${CC} ${FLAGS} -I./ -c $< -o $@

# Règles de nettoyage
clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
