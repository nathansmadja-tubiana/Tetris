# Tetris

Ce jeu est constitué d'une grille de taille variable (10x10 par défaut) dans lequel on place des pièces pour compléter les lignes et gagner des points.

Vous perdez lorsqu'une pièce atteint le sommet de la grille.

Si vous tardez trop à choisir un emplacement, la pièce sera placée aléatoirement !

Votre meilleur score sera conservé, essayez de le battre !


Pour lancer la partie :
- Exécuter le MakeFile avec la commande `make`
- Lancer le jeu avec `./tetris`
- Vous pouvez ajouter des options :
  - `-d <[1-5]>` permet de régler le niveau de difficulté (1=normal). Cela affecte le temps disponible pour poser une pièce.
  - `-h <int>` permet de régler la hauteur de la grille
  - `-l <int>` permet de régler la largeur de la grille