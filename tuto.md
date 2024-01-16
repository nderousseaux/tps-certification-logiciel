# Frama-c 

## Lancement 

```bash
frama-c -rte -wp moncode.c
```

## Expressions 

```
formula ::= expr
            | expr rel expr
            | formule ==> formule
            | formule <==> formule
            | formule && formule
            | formule || formule
            | \forall type ident ; formule
            | \exists type ident ; formule
rel ::= == | != | < | <= | > | >=
```
## pré et post conditions 

```c
Syntaxe de pré et post-conditions :
/*@ 
requires ...;     Conditions requises pour le bon fonctionnement du programme
assigns ...;      Les variables qui vont être modifié
ensures ...;      Les conditions qui doivent être vrai à la sortie du programme
*/
```
Pour nommer une condition : ```requires nom: blablou cond```
## Les boucles

```c
/*@ 
loop invariant ...; Ce qui ne varie pas à chaque tour de boucle
                    Astuce : "Qu'est ce qui est vrai jusqu'ici ?"
loop assigns ...;   Variable qui varient :)
loop variant ...;   Entier naturel stictement décroissante
*/
```

## Utils 

- Le prédicat ```\valid(x)``` spécifie que x pointe vers une zone mémoire valide.  
- Le prédicat ```\valid(&t[0..n-1])``` spécifie que les zones mémoire t[i] pour i dans [0... n-1] sont valides.
- Le prédicat ```\separated(x, y, ...)``` spécifie que les pointeurs x et y correspondent à des zones mémoires distinctes. Comme pour valid on peut également parler des cases d’un tableau.
  
- On désigne le résultat de la fonction par ```\result```.
- On désigne l’ancienne valeur d’une variable x par ```\old(x)```.

- La commande ```assigns``` permet de spécifier quels sont les variables modifiées. Exemple
```assings t[0..n-1]``` permet de spécifier que le tableau t est modifié. La commande ```assigns \nothing``` permet de spécifier que la fonction ne réalise pas d’effet de bord.

## Remarque 

- `\forall` utiliser `==>` et `\exists` utiliser le `&&`