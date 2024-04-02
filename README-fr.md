# Simulation du Jeu de la Vie en C++ avec la bibliothèque Raylib

![](https://github.com/Your_Repository_Name/Your_GIF_Name.gif](https://github.com/NajibXY/Game-Of-Life-using-CPP-and-Raylib/blob/master/gifs/main.gif)

## 1. Motivations

Le jeu de la vie est un des exemples les plus marquants en matière d'IA développementale par le contraste entre la simplicité des règles initiales imposées aux agents et la complexité des comportements émergents. 
Cela reste un cas d'école pour tout ce qui touche aux comportements émergents et aux systèmes intelligents bio-inspirés; ainsi qu'une introduction visuelle fascinante vers les courants de l'IA qui sont un peu moins à la mode de nos jours. 
Il me tenait donc à coeur de commencer ma série de projets d'Avril 2024 par ce classique.

## 2. Technologies utilisées

- C++14
- Librairie Raylib pour le développement de jeu vidéo : cela fait quelques temps que je tenais à tester cette librairie simple d'utilisation qui offre de très bon outils pour le développement de jeux (et plus généralement d'interfaces) 2D.
- Le template utilisé pour la configuration du projet Raylib provient de ce dépôt : https://github.com/educ8s/Raylib-CPP-Starter-Template-for-VSCODE-V2

## 3. Règles de la simulation

- Sous-population : Si la cellule est en vie et a moins de deux voisins vivants, elle meurt à la prochaine itération
- Stase : Si la cellule est en vie et a un nombre de voisins vivants égal à 2 ou 3, elle reste en vie à la prochaine itération
- Sur-population : Si la cellule est en vie et a plus de trois voisins vivants, elle meurt à la prochaine itération
- Reproduction : Si la cellule n'est pas active et a un nombre de voisins vivants égal à 3, elle vit à la prochaine itération

## 4. Fonctionnalités implémentées

### Randomisation de la grille

- Dot (for custom shapes)
- Glider https://conwaylife.com/wiki/Glider
- Blinker (Randomly between vertical blinker, horizontal blinker, angel blinker and another type of blinkers) https://conwaylife.com/wiki/Blinker
- Gosper glider gun https://conwaylife.com/wiki/Gosper_glider_gun
- Basic Pulsar https://conwaylife.com/wiki/Pulsar

## 5. Améliorations possibles

- Seed input
- Grid size modification
- Step backward
- Memorize steps
- Save run
- Add more shapes
- Add variations of Game of Life
