Premier projet du cursus 42

# Consignes:
**Créer une librairie contenant des fonctions de base que l'on pourra réutiliser dans les projets suivants.**

La première partie est composée de répliques exactes de fonctions de la libc (défauts compris). 
La deuxième partie quant à elle est constituée d'imitations (avec des variations) ainsi que de fonctions absentes de la libc. 
Le header (libft.h) contient les prototypes des fonctions ainsi que tous les include nécessaires à leur fonctionnement.
Le Makefile contient les règles nécessaires pour compiler le projet et créer ainsi le programme libft.a.

# Libft.h
Le fichier libft.h est un header: il sert à définir les prototypes des fonctions et les include en un seul et même endroit. Il suffit alors de compiler le header avec les fichiers .c que vous voulez, sans vous soucier de quel fichier .c contient quelle fonction et include: tout est dans le header; pas besoin de les recopier dans chaque fichier .c.

Pour écrire un header, on utilise la structure suivante:
```
#ifndef                                                                     (si rien n'est défini)
# def                                                                       (alors on définit)

# include <librairie_nécessaire.h>                                          (inclure la librairie nommée entre <>)

type_retour  nom_fonction(type_param1 param1, type_param2 param2);          (définir prototype d'une fonction)
                                                                            ex.
                                                                            char  *ft_strchr(const char *s, int c);

#endif                                                                      (fin de la condition)
```
**ATTENTION :** la séparation entre la # et les mots-clés comme def et include est un ESPACE et non une tabulation.

# Makefile
Un Makefile sert à faciliter la compilation d'un programme: une fois les règles établies dans ce fichier, il n'y a plus qu'à lancer la commande "make" et votre programme est compilé! 

Il y a de nombreuses façons d'écrire un Makefile. Les consignes de 42 exigent les choses suivantes:
- Ecrire son Makefile de façon à ce qu'il ne relink pas, c'est-à-dire qu'il ne recompile pas si aucun fichier n'a été modifié et vous le signale via le message suivant dans la sortie : "make: 'votre_fichier' is up to date". Vous pouvez vérifier si votre Makefile relink en lançant simplement la commande "make" plusieurs fois de suite sans modifier aucun fichier. S'il recompile, il "relink".
- Des règles doivent être spécifiées pour $(NAME), all, clean, fclean, et re.
- Le Makefile doit compiler le programme avec les flags -Wall -Wextra -Werror (comme toujours à 42).

Basiquement, un Makefile est composé de cibles, de dépendances et de règles. Chaque cible a des règles qui s'appliquent à elle, et peut avoir des dépendances. Pour A, on a besoin de B : B est donc une dépendance de A. On peut optimiser notre fichier en utilisant des variables, généralement nommées en majuscules. Voici la syntaxe générale:

```
NOM_VARIABLE1 = variable1

Cible : Dépendance1 Dépendance2
    commande $(NOM_VARIABLE1)
```
La variable NAME définira le nom de votre programme, ici libft.a.

La cible **all** sert à nommer tous les fichiers que vous voulez que votre Makefile crée. Ici, nous n'en avons besoin que d'un, libft.a, soit $(NAME).

La cible **clean** sert à nettoyer les fichiers dont on n'a plus besoin. Ici, il s'agit des fichiers .o (objets) qui seront créés lors d'une première compilation; si vous modifiez un ou plusieurs fichiers .c et relancez la commande make, le Makefile saura qu'il doit d'abord nettoyer les .o avant d'en recréer.

La cible **fclean** sert à nettoyer le programme lui-même une fois qu'on n'en a plus besoin, c'est-à-dire lorsque des modifications ont été faites et qu'il est recompilé. Pour cela, il doit d'abord nettoyer les fichiers .o, c'est pourquoi **clean** est une dépendance de **fclean**.

La cible **re** sert à éviter que le Makefile relink. C'est lui qui va lancer le **fclean** (qui lui-même lancera le **clean**) sur **all**, pour s'assurer que tout est effacé avant d'être recréé lorsqu'il y a eu des changements et recompilation. 

Voilà pour les obligations. Pour le reste, vous êtes libres d'organiser votre Makefile comme vous le souhaitez.

Par exemple, vous pouvez créer une variable CFLAGS et lui assigner les flags demandés par la consigne,
```
CFLAGS = -Wall -Wextra -Werror
```
ainsi, vous n'aurez plus qu'à écrire: 
```
cc $(CFLAGS)
```
au lieu de les retaper entièrement à chaque fois que vous voudrez écrire une règle de compilation et de potentiellement en modifier chaque itération si vous décidez de les changer. Cependant, dans ce projet, nous n'en avons besoin qu'une seule fois, et il n'y pas de raisons de les changer puisqu'ils sont obligatoires, ce n'est donc pas vraiment nécessaire. A vous de voir!
