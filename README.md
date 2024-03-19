# Projet de Micro-contrôleur - Chronomètre

Ce fichier Readme contient des informations sur le projet de micro-contrôleur pour un chronomètre à deux boutons, un jaune et un rouge. 

Le chronomètre permet de démarrer, arrêter et réinitialiser le compteur.

## Fonctionnalités :

Le micro-contrôleur est conçu pour offrir les fonctionnalités suivantes :

```
Démarrer le chronomètre : Lorsque le bouton jaune est enfoncé, le chronomètre démarre et commence à compter le temps écoulé.
```
```
Arrêter le chronomètre : En appuyant sur le bouton rouge, le chronomètre s'arrête, enregistrant le temps écoulé.
```
```
Réinitialiser le chronomètre : Si le bouton d'arrêt est enfoncé alors que le chronomètre est déjà arrêté, le compteur est réinitialisé à zéro, prêt pour un nouveau départ.
```

## Affichage :

```
Le micro-contrôleur affiche la valeur du compteur en brut, et la valeur qui est stockée en mémoire.
```
```
Lors d'un redémmarage, le compteur ne prends pas la valeur stockée dans la mémoire. Aucun chronomêtre ne reprend une valeur quand on eteinds ce dernier.
```
## Configuration logicielle

Le projet de micro-contrôleur nécessite un environnement de développement approprié. Voici les outils recommandés pour le développement et la programmation :

    Langage de programmation : C
    Environnement de développement intégré (IDE) : KeilU Vision5
    Démarrer le projet : Dans le dossier "Projet", lancer le fichier "projet" contenant l'extension uVision5


le projet lancé, des indications supplémentaires sont affichés par le micro-controller.

# TODO

 - Lors d'un second démarrage, le chrono ne prends pas en compte l'ancienne valeur d'arrêt, ce serait un plus de l'ajouter.

## Contributor

Savinien Barbotaud
