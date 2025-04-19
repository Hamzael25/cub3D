# 🕹️ cub3D

**cub3D** est un petit moteur 3D en **C** basé sur un algorithme de **raycasting** (à la Wolfenstein 3D) pour générer une vue pseudo‑3D à partir de cartes 2D. <br>L’affichage est assuré avec **MiniLibX**, une bibliothèque graphique fournie par l’école 42. <br>Le projet peut se compiler nativement sous Linux ou s’exécuter via Docker sur n’importe quel OS (macOS/Windows/WSL).

---
## ⚙️ Prérequis

| OS | Prérequis | Notes |
|----|-----------|-------|
| **Linux** | `gcc`, `make`, `libx11-dev`, `libxext-dev`, `libbsd-dev` | Permet la compilation native. |
| **macOS** | **Docker Desktop**<br/>**XQuartz** | 1. Installez **Docker Desktop** (dmg ou `brew install --cask docker`).<br/>2. `brew install --cask xquartz`(si Xquartz non installé).<br/>3. Ouvrez **XQuartz** → *Preferences ▸ Security* : cochez **“Allow connections from network clients”**.<br/>4. Quittez/relancez XQuartz puis, dans le Terminal : `xhost + 127.0.0.1`.<br/>Ces étapes configurent le serveur X11 indispensable pour afficher la fenêtre du jeu depuis le conteneur Docker. |
| **Windows 10/11** | **WSL 2** + **Docker Desktop** | Lancer les commandes Docker depuis WSL ou PowerShell. |

---
## 🚀 Lancer le projet (méthode universelle)

```bash
git clone https://github.com/Hamzael25/cub3D.git
cd cub3D
make up
```

1. Build l’image Docker (Ubuntu 22.04 + deps)
2. Lance le conteneur
3. Compile **cub3D**
4. Ouvre un bash interactif dans `/cub3d`

### Exemple : lancer une map

Plusieurs fichiers `.cub` de test sont disponibles dans le dossier `maps/`. Vous pouvez les lancer en spécifiant leur nom.<br>Exemple de map valide :

```bash
./cub3D maps/val_big_map.cub
```

### Quitter le conteneur

```bash
exit    # ou Ctrl+D
```
> ℹ️ Dans le bash Docker seules les cibles code (`make compile`, `make clean`, `make re`) fonctionnent.<br>
> Pour les cibles Docker (`make down`, `make reset`, …), quittez d’abord le bash avec `exit`, puis lancez‑les depuis votre terminal hôte.

---
### Compilation native (Linux seulement)

```bash
sudo apt update && sudo apt install -y build-essential libx11-dev libxext-dev libbsd-dev
make compile
./cub3D maps/map1.cub
```
> ✅ Vous pouvez utiliser `make compile`, `make clean` ou `make re` directement **dans le bash Linux**.
> ⚠️ En revanche, **ne lancez pas `make compile` hors Docker** (depuis macOS ou Windows), cela échouera à cause des dépendances Linux spécifiques à `mlx_linux`.

---
## 🏗️ Commandes Makefile

| Commande | Action |
|----------|--------|
| `make compile` | Compile libft + mlx_linux + cub3D (Linux natif) |
| `make clean` | Supprime exécutables et dossiers `.objs/` |
| `make re` | `clean` puis re‑compile |
| `make build` | Construit l’image Docker |
| `make up` | build → run conteneur → compile → bash interactif |
| `make down` | Arrête et supprime les conteneurs |
| `make reset` | `clean` → `down` → `build` → `up` |
| `make prune` | Nettoie Docker (images/volumes/réseaux) |

---
## 🎮 Contrôles

| Action | Touche |
|--------|--------|
| Avancer | **W** |
| Reculer | **S** |
| Pas gauche | **A** |
| Pas droit | **D** |
| Rotation gauche | **←** |
| Rotation droite | **→** |

Amusez-vous bien ! 🎉

