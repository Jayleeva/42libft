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
# define                                                                    (alors on définit)

# include <librairie_nécessaire.h>                                          (inclure la librairie nommée entre <>)
# include "fichier_nécessaire.extension"                                    (inclure le fichier nommé entre <>)

type_retour  nom_fonction(type_param1 param1, type_param2 param2);          (définir prototype d'une fonction)
                                                                            ex.
                                                                            char  *ft_strchr(const char *s, int c);

#endif                                                                      (fin de la condition)
```
**ATTENTION :** la séparation entre la # et les mots-clés comme define et include est un ESPACE et non une tabulation, bien qu'elle serve d'indentation.

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

La cible **re** sert à éviter que le Makefile relink. C'est elle qui va lancer le **fclean** (qui lui-même lancera le **clean**) sur **all**, pour s'assurer que tout est effacé avant d'être recréé lorsqu'il y a eu changements et recompilation. 

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
au lieu de les retaper entièrement à chaque fois que vous voudrez écrire une règle de compilation et de potentiellement en modifier chaque itération si vous décidez de les changer. Cependant, dans ce projet, nous n'en avons besoin qu'une seule fois, et il n'y pas de raison de les changer puisqu'ils sont obligatoires, ce n'est donc pas vraiment nécessaire. A vous de voir!

Pour eviter que mon Makefile relink, j'ai crée des fichiers .o. Pour cela, j'ai créé une variable SRC à laquelle j'ai assigné tous mes fichiers .c (j'ai évité la wildcard car bien qu'autorisée, elle demande de la prudence dans son utilisation), puis une variable OBJ à laquelle j'ai assigné $(SRC:.c=.o), ce qui permet de copier les noms des fichiers .c en changeant leur extension en .o, m'évitant ainsi de tout recopier à chaque modification et de potentiellement me tromper. Ensuite, je les ai inclus dans la règle qui compile mes fichiers .c en mettant les .o comme cible et les .c comme dépendances avec le header: 
```
%.o : %.c libft.h
```
Le % signifie "n'importe quelle suite de caractères", ce qui permet d'accéder à tous les fichiers dont les noms finissent par .o puis par .c. Ainsi, pour chaque fichier .o, le Makefile sait qu'il doit chercher le .c correspondant ainsi que le header pour appliquer la règle qui suit.

Reste le **.PHONY**. Je ne sais pas s'il est obligatoire, mais j'ai préféré l'utiliser pour parer à toute éventualité. Son rôle est lié à la façon dont fonctionne un Makefile: en effet, ce dernier se base sur la date de modification des fichiers pour savoir s'il doit recompiler lorsque la commande make est lancée ou si ce n'est pas nécessaire. Or, il est possible de changer ces dates sans effectuer de modification, ou de faire des modifications puis de changer la date pour faire croire qu'il n'y en a pas eu. Le **.PHONY** permet de contrer ce problème, bien que je n'aie pas compris comment exactement.

# Première partie
## isalpha
**Vérifie si l'int reçu correspond à un char alphabétique (majuscule ou minuscule)**

Une condition vérifie si le int reçu en argument correspond à un char alphabétique. Si c'est le cas, la fonction retourne 1, sinon, elle retourne 0.
## isdigit
**Vérifie si l'int reçu correspond à un char numérique (de 0 à 9)**

Une condition vérifie si le int reçu en argument correspond à un char numérique. Si c'est le cas, la fonction retourne 1, sinon, elle retourne 0.
## isalnum
**Vérifie si l'int reçu correspond à un char alphanumérique (alphabétique ou numérique)**

Une condition vérifie si le int reçu en argument correspond à un char alphanumérique (alphabétique ou numérique). Si c'est le cas, la fonction retourne 1, sinon, elle retourne 0. 
*J'ai utilisé les fonctions précédentes au lieu de les réécrire entièrement. Les lecteurs attentifs verront que j'ai mis comme condition : "si le retour de ft_isalpha est non nul" au lieu de "est égal à 1". C'est parce qu'en réalité, is_alpha peut donner des résultats non nuls différents de 1 en fonction de l'environnement sur lequel elle est appelée. Vu que nos projets ne sont testés que sur Mac, il n'est pas nécessaire de s'en soucier, mais je l'ai laissé tel quel pour me rappeler de cette spécificité.*
## isascii
**Vérifie si l'int reçu correspond à un char de la table ascii**

Une condition vérifie si le int reçu en argument correspond à un char présent sur la table ascii. Si c'est le cas, la fonction retourne 1, sinon, elle retourne 0.
## isprint
**Vérifie si l'int reçu correspond à un char imprimable**

Une condition vérifie si le int reçu en argument correspond à un char imprimable. Si c'est le cas, la fonction retourne 1, sinon, elle retourne 0.
## strlen
**Mesure la longueur de l'argument reçu**

Une boucle while incrémente un index tant que la chaîne de caractères reçue en argument n'a pas été parcourue entièrement. Une fois la condition de sortie remplie, la fonction s'arrête. Elle retourne l'index, soit la longueur de la chaîne reçue.
## memset
**Assigne le int reçu dans le pointeur reçu de son 1er au nombre reçu de bytes**

Une chaîne de caractères est créée et prend la valeur du pointeur sur void reçu en argument. Une boucle while cast en unsigned char le int reçu en argument et en assigne la valeur à l'endroit indexé de la chaîne de caractères, et incrémente l'index. Elle tourne tant que l'index est plus petit que le size_t reçu en argument. Une fois la condition de sortie remplie, la fonction s'arrête. Elle retourne le pointeur reçu.
## bzero
**Assigne la valeur '\0' dans le pointeur reçu de son 1er au nombre reçu de bytes**

Une chaîne de caractères est créée et prend la valeur du pointeur sur void reçu en argument. Une boucle while assigne '\0' à l'endroit indexé de la chaîne de charactères, et incrémente l'index. Elle tourne tant que l'index est plus petit que le size_t reçu en argument. Une fois la condition de sortie remplie, la fonction s'arrête. Elle ne retourne rien.
## memcpy
**Assigne la valeur des bytes de la source reçue dans le pointeur de la destination de son 1er au nombre reçu de bytes**

Une chaîne de caractères variable et une constante sont créées et prennent la valeur des pointeurs sur void reçus en arguments (destination et source). Une condition vérifie si ET la destination ET la source sont nulles, si c'est le cas, la fonction renvoie NULL et s'arrête, sinon, elle poursuit. Une boucle while assigne à l'endroit indexé de la destination la valeur de l'endroit indexé de la source, et incrémente l'index. Elle tourne tant que l'index est plus petit que le size_t reçu en argument. Une fois la condition de sortie remplie, la fonction s'arrête. Elle retourne le pointeur sur la destination. FAIBLESSE: en cas de chevauchement, le comportement est indéfini.
## memmove
**Idem, mais en parant aux chevauchements (part du nombre reçu de bytes et va jusqu'au 1er)**

Même chose que memcpy, à une différence. Dans la boucle, une condition vérifie si la source est placée avant la destination dans la mémoire. Si c'est le cas, pour éviter d'effacer la source en modifiant la destination, la copie se fait dans le sens inverse, en partant de la fin au lieu de partir du début. Sinon, elle se fait comme précédemment.
## strlcpy
**Fait appel à memcpy *//(et memmove ?!?)//* pour copier une source dans une destination**

La fonction memcpy est appelée en passant des arguments différents selon la longueur de la source reçue en argument et celle du size_t reçu en argument (correspondant à la longueur totale que la destination aura à la fin de la fonction). Si cette longueur + 1 est plus petite que le size_t reçu, on passe la longueur + 1 comme dernier argument. Si le size_t reçu est différent de 0, on passe le size_t -1 en dernier argument, et on assigne '\0' au dernier byte de la destination. La fonction retourne la longueur de la source. *// En fonction de si la source est placée avant la destination dans la mémoire, on appelle soit la fonction memcpy soit la fonction memmove ?!? //*
## strlcat
**Concatène les chaînes de caractères reçues jusqu'au nombre reçu de bytes**

La fonction strlen est appelée pour mesurer la longueur de la destination reçue en arguments. Une condition vérifie si le size_t reçu en argument (correspondant à la longueur totale que la destination aura à la la fin de la fonction) est plus petit ou égal à la longueur de la destination intitiale. Si c'est le cas, la fonction s'arrête et retourne l'addition de la longueur de la source (mesurée avec strlen) et du size_t reçu. Sinon, une boucle while assigne la valeur à l'endroit indexé de la source à l'endroit indexé de la destination et incrémente l'index de la source. L'index de la destination est la somme de la longueur de la destination initiale et de l'index de la source, ce qui permet de copier la source à la suite de la destination initiale. La boucle tourne tant que la source n'a pas été entièrement parcourue ET tant que l'index de la source est plus petit que la longueur reçue en argument moins la longueur de la destination initiale moins 1. Une fois la condition de sortie remplie, une condition vérifie si la longueur reçue est différente de 0. Si c'est le cas, la valeur '\0' est ajoutée à l'endroit indexé de la destination. La fonction retourne l'addition des longueurs de la destination et de la source.

## toupper
**Vérifie si l'int reçu correspond à une lettre minuscule et si oui, la transforme en majuscule.**

Une condition vérifie si l'int reçu en argument correspond à une lettre minuscule. Si c'est le cas, on le décrémente de 32 afin de le transformer en majuscule. La fonction retourne l'int reçu.

## tolower
**Vérifie si l'int reçu correspond à une lettre majuscule et si oui, la transforme en minuscule.**

Une condition vérifie si l'int reçu en argument correspond à une lettre majuscule. Si c'est le cas, on l'incrémente de 32 afin de le transformer en minuscule. La fonction retourne l'int reçu.

## strchr
**Cherche la première itération du int reçu dans la chaîne de caractères reçue**

Le int reçu est cast en unsigned char. Une condition vérifie si ce unsigned char est un '\0'. Si c'est le cas, la fonction s'arrête et retourne le dernier caractère de la chaîne reçue, calculé par strlen et casté en char * puisque la chaîne est une constante. Sinon, une boucle while vérifie si le char indexé correspond au int reçu et incrémente l'index. Si c'est le cas, la fonction s'arrête et retourne le char indexé, casté en char * (l'int reçu a été trouvé). La  boucle tourne tant que la chaîne reçue n'a pas été entièrement parcourue. Une fois la condition de sortie remplie, la fonction s'arrête et retourne NULL (l'int reçu n'a pas été trouvé).

## strrchr
**Cherche la dernière itération du int reçu dans la chaîne de caractères reçue**

Même logique que strchr, à quelques différences. Une variable qui servira à retourner le résultat est créée et on l'initialise à NULL; la boucle tourne tant que l'index est plus petit ou égal à la longueur de la chaîne reçue (mesurée avec strlen); si le char indexé correspond au int reçu, le pointeur est assigné à la variable de retour, ce qui le met à jour à chaque fois qu'on tombe sur l'int recherché. Une fois la condition de sortie remplie, la fonction s'arrête et retourne la variable de retour (si aucune itération du int reçu n'a été trouvé, la valeur retournée sera NULL, sinon, on retourne l'adresse de la dernière itération).

## strncmp
**Compare les chaînes de caractères reçues du 1er au nombre de bytes reçu**

Une boucle while compare le char indexé de la chaîne 1 avec celui de la chaîne 2, puis incrémente l'index. Si l'un est différent de l'autre, la fonction s'arrête et retourne la substraction du 2ème au 1er (les n premiers caractères des deux chaînes ne sont pas identiques). La boucle tourne tant qu'au moins une des deux chaînes n'a pas été entièrement parcourue, ET tant que l'index est plus petit que le nombre de bytes reçu. Une fois la condition de sortie remplie, la fontion s'arrête et retourne 0 (les n premiers caractères des deux chaînes sont identiques).

## memchr
**Cherche la première itération du int reçu dans le pointeur reçu, de son 1er au nombre reçu de bytes**

Une variable de type const char* est créée et prend la valeur du pointeur reçu en argument. Le int reçu est cast en unsigned char. Une boucle while exécute une condition qui vérifie si le char indexé est identique au int casté en unsigned char, et incrémente l'index. Si c'est le cas, la fonction s'arrête et retourne l'adresse du char indexé, castée en void * (l'int reçu a été trouvé). La boucle tourne tant que l'index est plus petit que le nombre de bytes reçu. Une fois la condition de sortie remplie, la fonction s'arrête et retourne NULL (l'int reçu n'a pas été trouvé).

## memcmp
**Compare les pointeurs reçus du 1er au nombre de bytes reçu**

Même logique que strncmp, à une différence. Deux char * sont créés et prennent la valeur des pointeurs reçus en arguments, castés en char *. C'est ces chaînes de caractères qui seront comparées.

## strnstr
**Cherche la chaîne de caractères 2 dans la chaîne de caractères 1, de son 1er au nombre reçu de bytes**

Une condition vérifie si la chaîne 2 est vide OU si les deux chaînes sont identiques. Si c'est le cas, la fonction s'arrête et retourne la chaîne 1, castée en char *. Sinon, une boucle while exécute une seconde boucle while qui incrémente un index j tant que le char indexé par j de la chaîne 2 est identique au char indexé par i + j de la chaîne 1 ET tant que i + j est plus petit que le nombre reçu de bytes ET tant que la chaîne 1 n'a pas été parcourue entièrement. Une fois que la condition de sortie de la 2ème boucle est remplie, une condition vérifie si la chaîne 2 a été entièrement parcourue. Si c'est le cas, la fonction s'arrête et retourne le pointeur à l'index i de la chaîne 1, casté en char * (la chaîne 2 a été trouvée dans les n premiers caractères de la chaîne 1). Sinon, l'index i est incrémenté. La première boucle tourne tant que l'index i est plus petit que le nombre reçu de bytes ET tant que la chaîne 1 n'a pas été entièrement parcourue. Une fois que la condition de sortie de la 1ère boucle est remplie, la fonction s'arrête et retourne NULL (la chaîne 2 n'a pas été trouvée dans les n premiers caractères de la chaîne 1).

## atoi
**Transforme la chaîne de caractères reçue en int**

Une boucle while parcourt la chaîne de caractères et incrémente un index i. Elle tourne tant que le char indexé est un espace blanc. Une fois la condition de sortie remplie, une condition vérifie si le char indexé est un + OU un -: si c'est le cas, une condition vérifie si le char qui suit n'est pas un numéro: si c'est le cas, la fonction s'arrête et retourne 0. Sinon, une condition vérifie si le char indexé est spécifiquement un -. Si c'est le cas, la variable n initialisée à 1 est assignée à -1. Dans tous les cas, l'index i est incrémenté. Une boucle while parcourt la suite de la chaîne de caractères et réassigne la variable de résultat initialisée à 0 en la multipliant par 10 et lui additionnant le char indexé - 48 (parce que le char '9' par ex se traduit par l'int 57, or nous voulons l'int 9), puis incrémente l'index i. Elle tourne tant que le char indexé est un numéro. Une fois la condition de sortie remplie, la fonction s'arrête et retourne la variable de résultat.

## calloc
**Alloue de la mémoire au nombre reçu de bytes de la taille reçue et y assigne la valeur 0**

Une variable de type pointeur sur int est déclarée. La fonction malloc est appelée sur ce pointeur pour nelem * elsize (nombre de bytes * taille des bytes). Une condition vérifie si l'allocation a échoué; si c'est le cas, la fonction s'arrête et retourne NULL. Sinon, une boucle while assigne la valeur 0 au pointeur indexé et incrémente l'index. Elle tourne tant que l'index est plus petit que l'espace alloué. Une fois la condition de sortie remplie, la fonction s'arrête et retourne le pointeur casté en pointeur sur void.

## strdup
**Alloue suffisamment de mémoire puis duplique la chaîne de caractères reçue**

Une variable de type pointeur sur char est déclarée. La fonction malloc est appelée sur ce pointeur pour (ft_strlen(chaîne reçue) + 1) * sizeof(char). Une condition vérifie si l'allocation a échoué; si c'est le cas, la fonction s'arrête et retourne NULL. Sinon, une boucle while assigne la valeur du char indexé à celui du pointeur, puis incrémente l'index. Elle tourne tant que la chaîne reçue n'a pas été entièrement parcourue. Une fois la condition de sortie remplie, la valeur '\0' marquant la fin de la chaîne est assignée au dernier char du pointeur. La fonction retourne le pointeur.

