#ifndef TRUCTURE_H_INCLUDED
#define TRUCTURE_H_INCLUDED
#include<string.h>
#define MAX_LEN 50
struct matiere
{
    char nom[MAX_LEN];
    int code;
    char nom_prof[MAX_LEN];
    int credi ;
    int heurs;
    int niveaux;
};
struct salle
{
    char nom_s[MAX_LEN];
    int nmb_machine;
};
struct prof
{
    char nom[MAX_LEN];
    char nom_mat[MAX_LEN];
    int nivaux ;
};
struct jours
{
char *p[8];
};
typedef enum
{
    true,
    false,
}booleen;
typedef struct infomat
{
    char nom[MAX_LEN];
    int code;
    char nom_prof[MAX_LEN];
    int credi ;
    int heurs;
    int niveaux;
    struct infomat *point;
}listeElement, *list;
typedef struct infoalou
{
     char nom_mt[MAX_LEN];
     char nom_sl[MAX_LEN];
     char nom_g[MAX_LEN];
     struct infoalou *next;
}infoalou, *list2;

#endif // TRUCTURE_H_INCLUDED
