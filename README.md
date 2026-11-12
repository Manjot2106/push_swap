# push_swap

*Projet réalisé dans le cadre du cursus 42 par msingh.*

Trier une liste d'entiers avec deux piles et un jeu d'instructions limité, en produisant **le moins d'instructions possible**.

- **Pile A** : contient au départ tous les nombres passés en argument.
- **Pile B** : vide au départ, sert de pile auxiliaire.

| Instruction | Effet |
|---|---|
| `sa` / `sb` / `ss` | échange les deux premiers éléments de A / B / des deux |
| `pa` / `pb` | déplace le sommet de B vers A / de A vers B |
| `ra` / `rb` / `rr` | rotation vers le haut (le premier devient le dernier) |
| `rra` / `rrb` / `rrr` | rotation vers le bas (le dernier devient le premier) |

## Compilation et utilisation

```bash
make            # push_swap
make bonus      # checker
```

```bash
./push_swap 4 67 3 87 23          # affiche la liste des instructions
./push_swap "4 67 3 87 23"        # les nombres peuvent aussi être passés en une seule chaîne
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG   # OK si la pile est triée
ARG=$(shuf -i 1-1000 -n 100 | tr '\n' ' '); ./push_swap $ARG | wc -l
```

En cas d'entrée invalide (caractère non numérique, dépassement d'`int`, doublon), le programme affiche `Error` sur la sortie d'erreur. Sans argument, il n'affiche rien.

## Algorithme

L'approche est une variante de l'algorithme « Turk » : on vide A dans B de façon grossièrement ordonnée, puis on réinsère chaque élément de B dans A en choisissant à chaque fois **le coup le moins cher**.

1. **Pré-tri vers B** (`sort_b`, `push_sort_b`). Tant que A contient plus de 3 éléments, on pousse le sommet de A dans B. Si la valeur est supérieure à la moyenne de A (`calc_mean`), on fait aussi `rb` : les grandes valeurs vont au fond de B, les petites restent en haut. Cela réduit le coût des réinsertions.
2. **Tri de 3 éléments** (`ft_sort_three`). Les 3 éléments restants dans A sont triés en au plus 2 instructions.
3. **Réinsertion au moindre coût** (`push_sort_a`). Pour chaque élément de B :
   - on cherche sa **cible** dans A : le plus petit élément de A qui lui est supérieur, ou le minimum de A s'il n'y en a aucun (`target_pos_in_a`) ;
   - on calcule 4 coûts possibles (`compute_array_costs`) : tout en rotation vers le haut (`rr` partagés), tout vers le bas (`rrr` partagés), ou en sens opposés (`ra` + `rrb`, `rra` + `rb`) ;
   - on retient l'élément et la combinaison la moins chère (`pick_best_array_move`), on l'exécute (`exec_array_choice`), puis `pa`.
4. **Rotation finale** (`finish_rotate`). On ramène le minimum en haut de A, par le chemin le plus court.

### Organisation du code

| Fichier | Rôle |
|---|---|
| `push_swap.c` | `main`, lecture des arguments (séparés ou en une seule chaîne) |
| `parsing.c`, `stack_init.c` | validation (syntaxe, débordement, doublons) et création de la pile chaînée |
| `swap.c`, `push.c`, `rotate.c`, `rrotate.c` | les 11 instructions |
| `ft_sort.c`, `ft_sort0.c` | étapes de l'algorithme |
| `ft_array.c`, `ft_cheapest.c`, `ft_exec.c`, `ft_rot_ops.c` | calcul des cibles, des coûts et exécution du meilleur coup |
| `utils.c`, `ft_utils.c`, `free.c` | outils (min/max, longueurs, moyenne) et libération |
| `bonus/checker.c` | lit des instructions sur l'entrée standard, les applique et affiche `OK` ou `KO` |

## Résultats

Mesurés sur 20 tirages aléatoires par taille :

| Nombre d'éléments | Instructions (pire cas) | Barème maximal 42 |
|---|---|---|
| 3 | 2 | ≤ 3 |
| 5 | 10 | ≤ 12 |
| 100 | 641 | < 700 |
| 500 | 4 808 | ≤ 5 500 |

Le `checker` a validé tous les tris et valgrind ne signale aucune fuite, y compris dans les cas d'erreur.

## Ressources

- Sujet officiel push_swap (42)
- [Push Swap: Turk Algorithm Explained in 6 Steps](https://pure-forest.medium.com/push-swap-turk-algorithm-explained-in-6-steps-4c6650a458c0)
- [Push Swap (guide Medium)](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)
- Visualiseurs push_swap de la communauté

### Usage de l'IA

L'IA a été utilisée uniquement pour la rédaction et la structuration du README. Elle n'a pas servi à implémenter le programme, à générer le code source ni à faire les choix algorithmiques.
