#!/bin/bash
# 
#=====================================#
# Script de Création de noveau module #
#=====================================#
#
#====================#
# Fonction du Script #
#====================#
#
#Création d'une fonction d'espacement pour de la lisibilité
space(){
  	echo ""
  	echo ""
}
#
#Création du cpp
creercpp(){
  	echo "     Création du fichier .cpp en cours"
  	touch $rep.cpp
	echo "//" >> $rep.cpp
	echo "//Fichier Cpp - Projet Space Wars" >> $rep.cpp
	echo "//Etudiant: Deborguere Tony - Tekeli Baris - Touat Malik - Qi Zhiwen" >> $rep.cpp
	echo "//" >> $rep.cpp
	echo "//===================================================================" >> $rep.cpp
	echo "//" >> $rep.cpp
	echo "// Régle de nommage des fonctions:" >> $rep.cpp
	echo "//      - Majuscule à chaque mot sauf le premier (exemple: maSuperFonction())." >> $rep.cpp
	echo "//      - Nom explicite commençant par un verbe." >> $rep.cpp
	echo "// " >> $rep.cpp
	echo "// Régle de nommage des variable:" >> $rep.cpp
	echo "//      - écrit en minusicle avec une  '_' pour séparer chaque mot (exemple: ma_super_variable)." >> $rep.cpp
	echo "//      - Nom explicite." >> $rep.cpp
	echo "//" >> $rep.cpp
	echo "// Régle de nommage des Classe:" >> $rep.cpp
	echo "//      - Commençant par une Majuscule, mot séparé par un '_' (exemple: Ma_Classe)." >> $rep.cpp
	echo "//      - Nom explicite." >> $rep.cpp
	echo "//" >> $rep.cpp
	echo "// Régle de nommage des fichiers sources:" >> $rep.cpp
	echo "//      - Nom en minisucule, mot séparer par un '_'." >> $rep.cpp
	echo "//      - Nom explicite." >> $rep.cpp
	echo "//" >> $rep.cpp
	echo "// Commentaire:" >> $rep.cpp
	echo "//      - Voir pour résoudre le fais que les appuies sur le clavier se fasse deux fois." >> $rep.cpp
	echo "//      - Penser à séparer le code." >> $rep.cpp
	echo "//" >> $rep.cpp
	echo "//===================================================================" >> $rep.cpp
	echo "//" >> $rep.cpp
	echo "#include \"$rep.hpp\"" >> $rep.cpp
	echo "// Début du code" >> $rep.cpp
  	echo "     Ajout du modéle dans le fichiers"
} 
#
#Création du hpp
creerhpp(){
  	echo "     Création du fichier .hpp en cours"
  	touch $rep.hpp
	echo "//" >> $rep.hpp
	echo "//Fichier Hpp - Projet Space Wars" >> $rep.hpp
	echo "//Etudiant: Deborguere Tony - Tekeli Baris - Touat Malik - Qi Zhiwen" >> $rep.hpp
	echo "//" >> $rep.hpp
	echo "//===================================================================" >> $rep.hpp
	echo "//" >> $rep.hpp
	echo "// Régle de nommage des fonctions:" >> $rep.hpp
	echo "//      - Majuscule à chaque mot sauf le premier (exemple: maSuperFonction())." >> $rep.hpp
	echo "//      - Nom explicite commençant par un verbe." >> $rep.hpp
	echo "// " >> $rep.hpp
	echo "// Régle de nommage des variable:" >> $rep.hpp
	echo "//      - écrit en minusicle avec une  '_' pour séparer chaque mot (exemple: ma_super_variable)." >> $rep.hpp
	echo "//      - Nom explicite." >> $rep.hpp
	echo "//" >> $rep.hpp
	echo "// Régle de nommage des Classe:" >> $rep.hpp
	echo "//      - Commençant par une Majuscule, mot séparé par un '_' (exemple: Ma_Classe)." >> $rep.hpp
	echo "//      - Nom explicite." >> $rep.hpp
	echo "//" >> $rep.hpp
	echo "// Régle de nommage des fichiers sources:" >> $rep.hpp
	echo "//      - Nom en minisucule, mot séparer par un '_'." >> $rep.hpp
	echo "//      - Nom explicite." >> $rep.hpp
	echo "//" >> $rep.hpp
	echo "// Commentaire:" >> $rep.hpp
	echo "//      - Voir pour résoudre le fais que les appuies sur le clavier se fasse deux fois." >> $rep.hpp
	echo "//      - Penser à séparer le code." >> $rep.hpp
	echo "//" >> $rep.hpp
	echo "//===================================================================" >> $rep.hpp
	echo "//" >> $rep.hpp
	echo "#ifndef ${rep^^}_HPP_" >> $rep.hpp
	echo "#define ${rep^^}_HPP_" >> $rep.hpp
  	echo "" >> $rep.hpp
  	echo "#endif" >> $rep.hpp
  	echo "     Ajout du modéle dans le fichiers"
} 
#
#Finalisation du script
finir(){
	space
	echo "Les fichiers on été crées"
	echo ""
	echo "Liste des fichiers dans le dossier /src:"
	echo "----------------------------------------"
	echo ""
	ls -C
	space
	echo "============================================================"
	echo "                        Fin du script                       "
	echo "============================================================"
	sleep 1
	clear
} 
#
#================#
# Code du Script #
#================#
#
#
#On nettoie le terminal
clear
#Début du script
echo "============================================================"
echo "         Script de création de module automatique"
echo "============================================================"
echo "" 
echo " Vous pouvez lancer ce script avec des arguments 1 arguments correspondant à 1 modules"
#
#
#On regarde si on a des arguments
if [ $# -ne 0 ]; then
	space
    echo "$# arguments on était detectés: Traitement des arguments..."
    #Pour chaque argument on crée les fichiers
	for rep in $*
	do
		echo ""
	    echo "Traitement de l'argument $rep :"
	    echo "-------------------------------"
	    creerhpp
	    creercpp
	done
	finir
#Sinon on demande le nom module à créer
else
	space
    echo -n "Quel modules souhaitez vous créer ? "
    read rep
    echo "Un fichier nommée $nommod.hpp et $nommod.cpp sera créer dans votre dossier."
    echo -n "Souhaitez vous continuez (O/N) ?"
    read cfr
    if [ "$cfr" = "o" ] || [ "$cfr" = "O" ]; then
    	echo "Création des fichiers en cours"
    	creerhpp
	    creercpp
	    finir
    	exit 0
	elif [ "$cfr" = "n" ] || [ "$cfr" = "N" ]; then
		space
		echo "=== === === === ==="
    	echo "Abandon du script. "
    	echo "=== === === === ==="
    	exit 0
	else
    	echo "Il faut taper O ou N!! Pas $cfr"
    	exit 1
	fi
fi
#on est pas censè arrivé ici
exit 0