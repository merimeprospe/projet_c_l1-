#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <windows.h>
#define MAX_LEN 50
#include "structure.h"
#include "fonction.h"
void menu()
{
    int n=0,i=1;
    char t2[MAX_LEN],t1[MAX_LEN],t3[MAX_LEN];
    n=nmb();
    list2 mylist2 = new_list2();
    FILE *info_aloue=fopen("info_aloue.txt","r");
    if(info_aloue!=NULL)
    {
        while(i<=n)
        {
            fscanf(info_aloue,"%s %s %s",t1,t2,t3);
            mylist2=ajoute_liste2(mylist2,t1,t2,t3);
            i++;
        }
         fclose(info_aloue);
    }
    else
    {
        printf("erreur");
        fclose(info_aloue);
        exit(-1);
    }
    int choise ;
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 11);
    printf("\n\n");
    printf("\t\t#########################################################################\n");
    printf("\t\t#       BIENVENUE DANS NOTRE PROGRAMME DE GESTION DE SALLE DE TP        #\n");
    printf("\t\t#                     *** NOMS DES PROGRAMMEUR ***                      #\n");
    printf("\t\t#########################################################################\n");
   // cadre(10,60,7,18,14);
    gotoxy(11,10);
    SetConsoleTextAttribute(h, 14);
    printf("\t\t\t      ( MENU DE NOTRE PROGRAMME )");
    gotoxy(11,12);
    SetConsoleTextAttribute(h, 14);
    printf("\t\t---------------------------------------------------------\n");
    SetConsoleTextAttribute(h, 7);
    gotoxy(11,14);
    printf("\t\t     1-  AJOUTER UNE NOUVELLE MATIERRE   \n");
    gotoxy(11,15);
    printf("\t\t     2-  ALOUE LA SALLE   \n");
    gotoxy(11,16);
    printf("\t\t     3-  AVOIR L'EMPLOIS DE TEMPS  \n");
    gotoxy(11,17);
    printf("\t\t     4-  NOMBRE D'ALOCATION DEJA EFFECTUER   \n");
    gotoxy(11,18);
    printf("\t\t     5-  NOMBRE D'ALOCATION PAS MATIERRE   \n");
    gotoxy(11,19);
    printf("\t\t     6-  Sortir (Quit) \n");
    SetConsoleTextAttribute(h, 14);
    gotoxy(11,21);
    printf("\t--------------------------------------------------------------------------\n\n\n");
    cadre(8,98,8,23,11);
    gotoxy(11,24);
    printf("\n\t---------------------------------------------\n");
    printf("\t---------------------------------------------\n");
    printf("\tentrer le numero qui convient a votre besoin\n\t\tchoise:\t");
    scanf("%d",&choise);
    printf("\t---------------------------------------------\n");
    if(choise>=6||choise<=0)
    {
        if (choise!=6)
        {
            int r;
            cadre(56,98,26,29,12);
            gotoxy(57,27);
            printf("choix introuvabble voulervous ressayer");
            gotoxy(57,28);
            printf("OUI(1)/NON(0):\t");
            scanf("%d",&r);

            if(r==1)
            {
                system("cls");
                menu();
            }
            else
            {
                cadre(56,98,26,29,14);
                gotoxy(57,27);
                printf("si vous voullez vraiment quiter cliquer");
                gotoxy(57,28);
                printf("sur une autre touche");
                printf("\n\n\n");
                SetConsoleTextAttribute(h, 7);
                return;
            }
        }
        else
        {
            cadre(56,98,26,29,14);
            gotoxy(57,27);
            printf("si vous voullez vraiment quiter cliquer");
            gotoxy(57,28);
            printf("sur une autre touche");
            printf("\n\n\n");
            SetConsoleTextAttribute(h, 7);
            exit(-1);
        }
     }
    cadre(56,98,26,29,11);
    gotoxy(57,27);
    system("pause");
    system("cls");
    switch(choise)
    {
        case 1:{
                   SetConsoleTextAttribute(h, 11);
                   printf("\n\t\t----------------------------------------------------------------------------------\n");
                   SetConsoleTextAttribute(h, 7);
                   matiere();
                   break;

               }
        case 2:{
                   SetConsoleTextAttribute(h, 11);
                   printf("\n\t\t----------------------------------------------------------------------------------\n");
                   SetConsoleTextAttribute(h, 7);
                   aloue();
                   break;
                }
        case 3:{
                   SetConsoleTextAttribute(h, 11);
                   printf("\n\t\t----------------------------------------------------------------------------------\n");
                   emploi_temp(mylist2);
                   break;
                                  }
        case 4:{
                   SetConsoleTextAttribute(h, 11);
                   printf("\n\t\t----------------------------------------------------------------------------------\n");
                   nmb_aloue(mylist2);
                   break;
               }
        case 5:{
                   SetConsoleTextAttribute(h, 11);
                   printf("\n\t\t----------------------------------------------------------------------------------\n");
                   SetConsoleTextAttribute(h, 7);
                   nmb_mt_aloue(mylist2);
                   break;
               }
    }
}
int main()
{
    color(11,0);
    printf("\n\n\n\n\t\t\t***************       ***************      ***************\n");
    printf("\t\t\t*                     *                           *\n");
    printf("\t\t\t*                     *                           *\n");
    printf("\t\t\t*                     *                           *\n");
    printf("\t\t\t*                     *                           *\n");
    printf("\t\t\t*                     *                           *\n");
    printf("\t\t\t*                     *                           *\n");
    printf("\t\t\t*      ********       **************              *\n");
    printf("\t\t\t*             *                    *              *\n");
    printf("\t\t\t*             *                    *              *\n");
    printf("\t\t\t*             *                    *              *\n");
    printf("\t\t\t*             *                    *              *\n");
    printf("\t\t\t*             *                    *              *\n");
    printf("\t\t\t*             *                    *              *\n");
    printf("\t\t\t*             *                    *              *\n");
    printf("\t\t\t***************       **************              *\n");
    color(14,0);
    printf("\n\t\t\t(GECTION DE LA SALLE DE TP)");
    cadre(63,105,23,26,11);
    gotoxy(64,24);
    system("pause");
    system("cls");
    menu();
    return 0;

}
