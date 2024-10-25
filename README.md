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
- La librairie doit être créée avec la commande ar et non libtool.

Basiquement, un Makefile est composé de cibles, de dépendances et de règles. Chaque cible a des règles qui s'appliquent à elle, et peut avoir des dépendances. Pour A, on a besoin de B : B est donc une dépendance de A. On peut optimiser notre fichier en utilisant des variables, généralement nommées en majuscules. Voici la syntaxe générale:

```
NOM_VARIABLE1 = variable1

Cible : Dépendance1 Dépendance2
    commande $(NOM_VARIABLE1)
```
La variable NAME définira le nom de votre programme, ici libft.a.

La cible **all** sert à nommer tous les fichiers que vous voulez que votre Makefile crée. Ici, nous n'en avons besoin que d'un, libft.a, soit $(NAME).

La cible **clean** sert à nettoyer les fichiers dont on n'a plus besoin. Dans mon Makefile, il s'agit des fichiers .o (objets) qui seront créés lors d'une première compilation sur la base de mes fichiers .c; si je modifie un ou plusieurs fichiers .c et relance la commande make, le Makefile saura qu'il doit d'abord nettoyer les .o avant d'en recréer.

La cible **fclean** sert à nettoyer le programme lui-même une fois qu'on n'en a plus besoin, c'est-à-dire lorsque des modifications ont été faites et qu'il est recompilé. Pour cela, il doit d'abord nettoyer mes fichiers .o, c'est pourquoi **clean** est une dépendance de **fclean**.

La cible **re** sert à éviter que le Makefile relink. C'est lui qui va lancer le **fclean** (qui lui-même lancera le **clean**) sur **all**, pour s'assurer que tout est effacé avant d'être recréé lorsqu'il y a eu des changements et recompilation. 

La commande **ar** crée une archive des fichiers qui lui sont donnés comme sources. Le flag **rcs** sert à: remplacer les fichiers s'il y en a de nouveaux (r), créer la librairie si elle n'existe pas déjà (c), et créer un index à l'intérieur pour accéder aux fonctions plus facilement (s). On les utilise dans une règle appliquée à NAME: pour créer libft.a (cible), on a besoin des sources (dépendances). 

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

Je ne sais pas si il est obligatoire de créer des fichiers .o; j'ai trouvé cette option et l'ai appliquée. Pour cela, j'ai créé une variable SRC à laquelle j'ai assigné tous mes fichiers .c (j'ai évité la wildcard car bien qu'autorisée, elle demande de la prudence dans son utilisation), puis une variable OBJ à laquelle j'ai assigné $(SRC:.c=.o), ce qui permet de copier les noms des fichiers .c en changeant leur extension en .o, m'évitant ainsi de tout recopier à chaque modification et potentiellement me tromper. Ensuite, je les ai inclus dans la règle qui compile mes fichiers .c en mettant les .o comme cible et les .c comme dépendances avec le header: 
```
%.o : %.c libft.h
```
Le % signifie "n'importe quelle suite de caractères", ce qui permet d'accéder à tous les fichiers dont les noms finissent par .o puis par .c. Ainsi, pour chaque fichier .o, le Makefile sait qu'il doit chercher le .c correspondant ainsi que le header pour appliquer la règle qui suit.

Reste le **.PHONY**. A nouveau, je ne sais pas s'il est obligatoire, mais j'ai préféré l'utiliser pour parer à toute éventualité. Son rôle est lié à la façon dont fonctionne un Makefile: en effet, ce dernier se base sur la date de modification des fichiers pour savoir s'il doit recompiler lorsque la commande make est lancée ou si ce n'est pas nécessaire. Or, il est possible de changer ces dates sans effectuer de modification, ou de faire des modifications puis de changer la date pour faire croire qu'il n'y en a pas eu. Le **.PHONY** permet de contrer ce problème, bien que je n'aie pas compris comment exactement.
