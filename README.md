# Space Wars

 ![Logo Space invaders](http://www.kirikoo.net/images/14Anonyme-20160607-115428.png)

## Table des matières
- [TODO Liste](#TODO)
- [Principe de Fonctionement](#Les Régles)
- [Contact](#Nous contactez)
- [Lancement du jeu](#Pré-requis)



## TODO:

Voici une liste non exhaustive des taches qui ont été ou sont encore à accomplir d'ici la fin du projets.

- [x] Création du cahiers des charges.
- [x] Mise en place du GitHub.
- [x] Création du menu d'accueil.
- [x] Création de l'interface du jeu.
- [x] Création du jeu - Solo.
- [x] Implémentation de la partie réseaux (client / serveur).
- [x] Création du jeu - JvJ

Ce projet est un exercice de fin d'année pour notres licences, nous avons donc plusieurs critères à respecter. Nous sommes donc tenu d'utiliser la bibliothèque multimédia SFML **(Version 2.3.2)** ainsi qu'implémenter une partie réseaux à notre jeu.

*Les dates du projet sont fixées du 6 Juin au 24 Juin 2016*

## Les Régles:

Space Wars est un clone de Space Invaders : un jeu d’arcade. Le principe est de détruire des vagues d’aliens au moyen d’un missile en se déplaçant horizontalement sur l’écran. Ce jeu fait parti des classiques du jeu vidéo au même titre que Pac-Man et d’autres de ses contemporains.

	— Le jeu commence avec un vaisseau qui a 3 points de vie et une vague de 5 x 11,
	  soit 55 aliens.

	— Le joueur, qui incarne le vaisseau, a la possibilité de se déplacer uniquement à
	  l’horizontal.

	— Le vaisseau tire des laser très rapide.

	— Un seul laser du vaisseau peut être présent sur la carte à la fois, ce qui veut dire
	  que pour tirer un laser, le précédent (si existant) doit être détruit.

	— La vague d’ennemis se déplace horizontalement et descend petit à petit.

	— Si la vague descend au point de toucher le vaisseau, alors celui-ci perd 1 point de
	  vie et la vague remonte de 3 lignes.

	— Si le joueur atteint 0 point de vie, la partie est terminée.

	— Entre la vague et le vaisseau, il y a 3 boucliers.

	— Les boucliers seront détruits petit à petit après chaque impact avec un missile
	  (adverse ou allié).

	— Les missiles du vaisseau vont uniquement de bas en haut, et ceux de l’ennemi
	  de haut en bas. Les missiles progressent uniquement verticalement et ne peuvent
	  être déviés.

	— Un alien touché par un missile se voit détruit avec celui-ci.

	— La vague est constituée de 3 types d’aliens:
		— 1er et 2e rang : type 1 -> 10 points.
		— 3e et 4e rang : type 2 -> 20 points.
		— 5e rang : type 3 -> 50 points.

	— Si le vaisseau est touché par un missile, le vaisseau perd 1 point de vie et le missile
	  est détruit.

	— Si un alien est derrière un autre alien, seul celui qui est devant peut tirer.

	— Le but du jeu est de détruire tous les aliens sur la carte.

## Contacts:

[DEBORGUERE TONY](t.deborguere@gmail.com)

[TEKELI BARIS](tekelibaris@gmail.com)

[TOUAT MALIK ](mal.touat@gmail.com)

[QI ZHIWEN ](531940615@qq.com)

## Lancement du jeu:

  Space Wars fonctionne sur tous système d'exploitation qui possède les dépendances du programme.
Il est écrit en C++ et utilise l'API SFML; vous devez donc avoir installé SFML sous sa version 2.3.2 minimale de préférence sur votre machine.
Il en va de même pour la librairie libboost-dev et pkg-config.

####Pour un systéme linux:

```
apt-get install libboost-dev

apt-get install pkg-config

apt-get intall libsfml-all
```
Après quoi, vous pouvez lancer la compilation du jeu en allant dans le dossier du projet dans un terminal et en tapant les lignes de commande suivantes:

```
make
```

Pour lancer le jeu, il vous suffit de faire:

`./bin/main.out`
