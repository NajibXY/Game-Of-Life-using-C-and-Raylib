# Simulation du Jeu de la Vie en C++ avec la bibliothèque Raylib 

## Auteur : [Najib El khadir](https://github.com/NajibXY)

## 1. Motivations

<img align="right" src="https://github.com/NajibXY/Game-Of-Life-using-CPP-and-Raylib/blob/master/gifs/main.gif">

Le jeu de la vie est un des exemples les plus marquants en matière d'IA développementale par le contraste entre la simplicité des règles initiales imposées aux agents et la complexité des comportements émergents. 
Cela reste un cas d'école pour tout ce qui touche aux comportements émergents et aux systèmes intelligents bio-inspirés; ainsi qu'une introduction visuelle fascinante vers les courants de l'IA qui sont un peu moins à la mode de nos jours. 
Il me tenait donc à coeur de commencer ma série de projets d'Avril 2024 par ce classique.  
</br> </br>
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

- Randomisation de la grille (Touche R)
- Nettoyage de la grille (Touche E)
- Accélération et Ralentissement de la simulation (Touches S, D & F)
- Mettre en pause / Reprendre la simulation (Touche Espace)
- Jouer une étape (Touche G)
- Modifier le taux de la randomisation (Touches K, L & J)  
![](https://github.com/NajibXY/Game-Of-Life-using-CPP-and-Raylib/blob/master/gifs/randomization.gif)

### Patterns et oscillateurs implémentés

- Il est également possible d'activer et de désactiver manuellement des cases avec les clics de la souris.
  
- Ont été également implémentés les patterns prédéfinis suivants (la navigation pour la sélection des formes à dessiner se fait avec les touche O & P) :
  + Le Point (pour des formes customisés) :  
      ![](https://github.com/NajibXY/Game-Of-Life-using-CPP-and-Raylib/blob/master/gifs/dot.gif)

  + Le Glider : https://conwaylife.com/wiki/Glider  
      ![](https://github.com/NajibXY/Game-Of-Life-using-CPP-and-Raylib/blob/master/gifs/glider.gif)

  + Le Blinker : https://conwaylife.com/wiki/Blinker  
      ![](https://github.com/NajibXY/Game-Of-Life-using-CPP-and-Raylib/blob/master/gifs/blinker.gif)

  + Le Gosper Glider Gun : https://conwaylife.com/wiki/Gosper_glider_gun  
      ![](https://github.com/NajibXY/Game-Of-Life-using-CPP-and-Raylib/blob/master/gifs/glider-gun.gif)
    
  + Le Pulsar : https://conwaylife.com/wiki/Pulsar  
      ![](https://github.com/NajibXY/Game-Of-Life-using-CPP-and-Raylib/blob/master/gifs/pulsar.gif)

## 5. Améliorations possibles

- Customization de la taille de la grille
- Customization de la grille initiale avec un fichier de seed
- Mémorisation des étapes et retour en arrière dans le déroulement étape par étape
- Sauvegarde d'une run de l'initialisation à la stabilisation
- Implémentation de plus d'oscillateurs et de formes
- Implémentation de variations du jeu de la vie (règles différentes, dimensionnalité et propriétés différentes de l'espace) : https://conwaylife.com/wiki/Conway%27s_Game_of_Life#Variations_on_Life
</br>
</br>

## 6. Exécuter le projet

- Si vous souhaitez vous amusez avec la simulation, vous pouvez télécharger le .exe présent dans le dépôt principal : [game_of_life.exe](https://github.com/NajibXY/Game-Of-Life-using-CPP-and-Raylib/blob/master/game_of_life.exe)
  
### Pré-requis 

- Installation de C++ (14 de préférence)
- Installation de Raylib pour C++ : https://www.raylib.com/

## Compilation, duplication, amélioration du projet

- Télécharger ou Forker le projet
- Ouvrir le projet dans VS Code via le fichier main.code-workspace
- F5 pour compiler et exécuter
- A partir de là vous pouvez effectuer toutes les modifications que vous souhaitez sur le fork du projet

  
