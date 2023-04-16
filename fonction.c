#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <windows.h>
#define MAX_LEN 50
#include "structure.h"
struct salle s;

void color(int t,int f)
{
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(H,f*16+t);
}
void gotoxy(int x, int y)
{
   HANDLE hConsoleOutput;
   COORD dwCursorPosition;
   //cout.flush();
   dwCursorPosition.X = x;
   dwCursorPosition.Y = y;
   hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
   SetConsoleCursorPosition(hConsoleOutput,dwCursorPosition);
}
void cadre (int x1 ,int x2 ,int y1 ,int y2,int c )
{
    int i;
    color(c,0);
    for (i=x1;i<=x2;i++)
    {
        gotoxy(i,y1);
        printf("%c",196);
         gotoxy(i,y2);
        printf("%c",196);
    }
    for (i=y1;i<=y2;i++)
    {
        gotoxy(x1,i);
        printf("%c",179);
         gotoxy(x2,i);
        printf("%c",179);
    }
     gotoxy(x1,y1);
    printf("%c",218);
     gotoxy(x2,y1);
    printf("%c",191);
     gotoxy(x1,y2);
    printf("%c",192);
     gotoxy(x2,y2);
    printf("%c",217);

}
void salle_tp()
{
    int i=1,n;
    printf("\n  entrer le nombre de salle a ajouter\t");
    scanf("%d",&n);
    while(i<=n)
    {
        printf("\n\n\tentrer les infortion de la salle %d",i);
        printf("\n\n\t\tentrer le nom de la salle de tp:\t");
        scanf("%s",s.nom_s);
        /*do
        {
            printf("\n\n\t\tentrer le nom de la salle de tp:\t");
            scanf("%s",&s.nom_s);
            t=1;
            for(i=0;i<sizeof(s.nom_s);i++)
            {
                if(s.nom_s[i]>z||s.nom_s[i]<a)
                {
                    t=0;
                }
            }
        }while(t=0);*/
        printf("\n\n\t\tentrer le nombre de marchine de ls salle de tp:\t");
        scanf("%d",&s.nmb_machine);
        i++;
         FILE *salle=fopen("salle.txt","a+");
        if(salle!=NULL)
        {
            fprintf(salle,"%s ",s.nom_s);
            fprintf(salle," %d\n",s.nmb_machine);
            fclose(salle);
        }
        else
        {
            printf("Erreur d'ouverture ");
            fclose(salle);
             exit(-1);
        }
    }
}
void matiere ()
{
    struct matiere m;
    int n;
    printf("\n  \t\t\tvous enregistrer la quantieme UE\t");
    scanf("%d",&n);
    printf("\n\n\t\t\t\t---------------------%d---------------------",n);
    printf("\n\n\t\t\t\t  entrer le nom de la UE\t");
    scanf("%s",m.nom);
    printf("\n\t\t\t\t  entrer le code de UE\t");
    scanf("%d",&m.code);
    printf("\n\t\t\t\t  entrer le nom du prof\t");
    scanf("%s",m.nom_prof);
    printf("\n\t\t\t\t  entrer le nombre de credi de UE\t");
    scanf("%d",&m.credi);
    printf("\n\t\t\t\t  entrer le nombre heurs de UE\t");
    scanf("%d",&m.heurs);
    printf("\n\t\t\t\t  entrer le niveaux\t");
    scanf("%d",&m.niveaux);
    FILE *UE=fopen("UE.txt","a+");
    if(UE!=NULL)
    {
        fprintf(UE,"%s ",m.nom);
        fprintf(UE," %d ",m.code);
        fprintf(UE," %s ",m.nom_prof);
        fprintf(UE," %d ",m.credi);
        fprintf(UE," %d ",m.heurs);
        fprintf(UE," %d \n",m.niveaux);
        fclose(UE);
    }
    else
    {
        printf("Erreur d'ouverture ");
        fclose(UE);
        exit(-1);
    }
    cadre(56,98,23,27,11);
    gotoxy(57,24);
    system("pause");
    cadre(56,98,23,27,11);
    int r;
    gotoxy(57,24);
    printf("vouler vous retourner au menu ou quiter ?");
    gotoxy(57,25);
    printf("retourner(1)/quiter(0)\t ");
    scanf("%d",&r);
    if(r==1)
    {
        system("cls");
        menu();

    }
    else
    {
        cadre(56,98,23,27,11);
        gotoxy(57,24);
        printf("si vous voullez vraiment quiter cliquer  ");
        gotoxy(57,25);
        printf("sur une autre touche         ");
        printf("\n\n\n");
        color(15,0);
        exit(-1);
    }
}
int nmb()
{
    int n=0;
    char text[MAX_LEN];
    FILE *info_aloue=fopen("info_aloue.txt","r");
    if(info_aloue!=NULL)
    {
        while(fgets(text,299,info_aloue)!=NULL)
        {
           n++;
        }
        fclose(info_aloue);
    }
    else
    {
        printf("erreur");
    }
    return n;
}
int nmb1()
{
    int n=0;
    char text[MAX_LEN];
    FILE *UE=fopen("UE.txt","r");
    if(UE!=NULL)
    {
        while(fgets(text,299,UE)!=NULL)
        {
           n++;
        }
        fclose(UE);
    }
    else
    {
        printf("erreur");
    }
    return n;
}
list new_list(void)
{
    return NULL;
}
list2 new_list2(void)
{
    return NULL;
}
boolean is_empty_list(list li)
{
    if(li==NULL)
    {
        return false;
    }
    return true;
}
boolean is_empty_list2(list2 li)
{
    if(li==NULL)
    {
        return false;
    }
    return true;
}
int list_length(list2 li)
{
   int n=0;
   if(!is_empty_list2(li))
   {
       while(li!=NULL)
        {
            n++;
            li=li->next;
        }
   }

   return n;
}
void  print_liste(list li)
{
    if(is_empty_list(li))
    {
        printf("rien a afficher, la liste est vide");
        return;
    }
    while(li!= NULL)
    {
       printf("[%s]",li->nom);
       printf("[%s]",li->nom_prof);
       printf("[%d]",li->code);
       printf("[%d]",li->credi);
       printf("[%d]",li->heurs);
       printf("[%d]",li->niveaux);
       li = li->point;
       printf("\n\n");
    }
}
void  print_liste2(list2 li)
{
    if(is_empty_list2(li))
    {
        printf("rien a afficher, la liste est vide");
        return;
    }
    while(li!= NULL)
    {
       printf("%s",li->nom_mt);
       printf("%s",li->nom_sl);
       printf("%s",li->nom_g);
       li = li->next;
       printf("\n\n");
    }
}
list ajoute_liste(list li,char nm[50],int c,char np[50],int cr,int h,int ni)
{
    listeElement *element;
    element=malloc(sizeof(*element));
    if(element==NULL)
    {
       printf("erreur : probleme allocation dynamique\n");
       exit(-1);
    }
     strcpy(element->nom,nm);
     strcpy(element->nom_prof,np);
     element->code=c;
     element->credi=cr;
     element->heurs=h;
     element->niveaux=ni;
     element->point = NULL;
     if(is_empty_list(li))
     {
        return element;
     }
     listeElement *temp;
     temp = li;
     while(temp->point != NULL)
     {
         temp = temp->point;
     }
     temp->point=element;
     return li;
}
list2 ajoute_liste2(list2 li,char nm[50],char ns[50],char ng[50])
{
    infoalou *element;
    element=malloc(sizeof(*element));
    if(element==NULL)
    {
       printf("erreur : probleme allocation dynamique\n");
       exit(-1);
    }
     strcpy(element->nom_mt,nm);
     strcpy(element->nom_sl,ns);
     strcpy(element->nom_g,ng);
     element->next = NULL;
     if(is_empty_list2(li))
     {
        return element;
     }
     infoalou  *temp;
     temp = li;
     while(temp->next != NULL)
     {
         temp = temp->next;
     }
     temp->next=element;
     return li;
}
void aloue ()
{
    int n1,n2,n3,n4,n=0,i=1,j=1,th;
    char t2[MAX_LEN],t1[MAX_LEN];
    int c;
    n=nmb1();
    list mylist = new_list();
    FILE *UE=fopen("UE.txt","r");
    if(UE!=NULL)
    {
        while(j<=n)
        {
            fscanf(UE,"%s %d %s %d %d %d",t1,&n1,t2,&n2,&n3,&n4);
            mylist=ajoute_liste(mylist,t1,n1,t2,n2,n3,n4);
            j++;
        }
         fclose(UE);
    }
    else
    {
        printf("erreur");
        fclose(UE);
        exit(-1);
    }
    struct prof p;
    int choix=0,g1,g2,h,m=0;
    printf("\n\t\t\tentrer votre nom\t");
    scanf("%s",p.nom);
    printf("\n\t\t\tentrer la matier donc vous est le prof\t");
    scanf("%s",p.nom_mat);
    printf("\n\t\t\tentrer le niveaux\t");
    scanf("%d",&p.nivaux);
    while(mylist!=NULL)
    {
        n1=strcmp(mylist->nom_prof,p.nom);
        n2=strcmp(mylist->nom,p.nom_mat);
        if((n2==0)&&(n1==0)&&(p.nivaux==mylist->niveaux))
        {
            m=1;
            FILE *salle=fopen("salle.txt","r");
            FILE *info_aloue=fopen("info_aloue.txt","a+");
            if(salle!=NULL)
            {
                fscanf(salle,"%s %d",t1,&n1);
                fclose(salle);
            }
            else
            {
                printf("erreur");
                fclose(UE);
                exit(-1);
            }
            printf("\n\t\t\tvous souhaitez reserver la salle pour combien de temp\t");
            scanf("%d",&th);
            printf("\n\t\t\tvooler vous reserver pour tout la chasse ou juste pour un groupe \n\n\t\t\t    tout la classe(1)/un seul groupe(2)\t");
            scanf("%d",&choix);
            if(choix!=1 && choix!=2)
            {
                do
                {
                    printf("\n\t\t\t\tvotre choix ne correspont a occun des deux");
                    printf("\n\n\t\t\t\t tout la classe(1)/un seul groupe(2)\t");
                    scanf("%d",&choix);
                }while(choix!=1 && choix!=2);
            }
            if(choix==1)
            {
                printf("\n\t\t\t\tentrer le nombre eleve dans le premier groupe\t");
                scanf("%d",&g1);
                printf("\n\t\t\t\tentrer le nombre eleve dans le deusieme groupe\t");
                scanf("%d",&g2);
                h=g1/n1;
                if(g1%n1>0)
                {
                    h++;
                }
                while(i<=(h*th))
                {
                   fprintf(info_aloue,"%s (%s) G_1\n",p.nom_mat,t1);
                   i++;
                }
                i=1;
                h=g2/n1;
                if(g2%n1>0)
                {
                    h++;
                }
                while(i<=(h*th))
                {

                   fprintf(info_aloue,"%s (%s) G_2\n",p.nom_mat,t1);
                   i++;
                }
            }
            if(choix==2)
            {
                printf("\n\t\t\t\tde kel groupe sagi t'il\n\n\t\t\t\t\t(1)/(2)\t");
                scanf("%d",&c);
                if(c != 1 && c!= 2)
                {
                    do
                    {
                        printf("\n\t\t\t\tse groupe n'esiste pas\n");
                        printf("\n\t\t\t\t\tde kel groupe sagi t'il\n\n\t\t\t\t\t(1)/(2)\t");
                        scanf("%d",&c);
                    }while(c!=1 && c!=2);
                }
                printf("\n\t\t\t\ tentrer le nombre eleve dans ce groupe\t");
                scanf("%d",&g2);
                h=g2/n1;
                if(g2%n1>0)
                {
                    h++;
                }
                while(i<=(h*th))
                {
                   fprintf(info_aloue,"%s (%s) G_%d\n",p.nom_mat,t1,c);
                   i++;
                }
            }
        }
       mylist = mylist->point;
    }
    if (m==0)
    {
         printf("\n\n\t\t\tvous n'avez pas le droit d aloue la salle\n");
    }
    cadre(56,98,33,37,11);
    gotoxy(57,34);
    system("pause");
    cadre(56,98,33,37,11);
    int r;
    gotoxy(57,34);
    printf("vouler vous retourner au menu ou quiter ?");
    gotoxy(57,35);
    printf("retourner(1)/quiter(0)\t ");
    scanf("%d",&r);
    if(r==1)
    {
        system("cls");
        menu();

    }
    else
    {
        cadre(56,98,33,37,11);
        gotoxy(57,34);
        printf("si vous voullez vraiment quiter cliquer  ");
        gotoxy(57,35);
        printf("sur une autre touche         ");
        printf("\n\n\n");
        color(15,0);
        exit(-1);
    }
}
void emploi_temp(list2 li)
{
    int m=0;
    system("cls");
    list2  temp=li;
    printf("\n\n\t  ------------------------------EMPLOI DE TEMP DE LA SEMAINE----------------------------");
    //**************************ligne_une********************//
    gotoxy(9,5);
    printf("horaire");
    cadre(5,21,4,6,14);
    gotoxy(25,5);
    printf("lundi");
    cadre(5,37,4,6,14);
    gotoxy(42,5);
    printf("mardi");
    cadre(5,53,4,6,14);
    gotoxy(57,5);
    printf("mercridi");
    cadre(5,69,4,6,14);
    gotoxy(73,5);
    printf("jeudi");
    cadre(5,85,4,6,14);
    gotoxy(89,5);
    printf("vendredi");
    cadre(5,101,4,6,14);
    //**************************colone_1********************//
    gotoxy(9,7);
    printf("8h a 9h");
    cadre(5,21,6,9,14);
    gotoxy(9,10);
    printf("9h a 10h");
    cadre(5,21,9,12,14);
    gotoxy(9,13);
    printf("10h a 11h");
    cadre(5,21,12,15,14);
    gotoxy(9,16);
    printf("11h a 12h");
    cadre(5,21,15,18,14);
    gotoxy(9,19);
    printf("13h a 14h");
    cadre(5,21,18,21,14);
    gotoxy(9,22);
    printf("14h a 15h");
    cadre(5,21,21,24,14);
    gotoxy(9,25);
    printf("15h a 16h");
    cadre(5,21,24,27,14);
    gotoxy(9,28);
    printf("16h a 17h");
    cadre(5,21,27,30,14);
    gotoxy(9,7);
    color(15,0);
    //**************************colone_2********************//
    if(temp->next==NULL)
    {
        if(m==0)
        {
            gotoxy(24,7);
            printf("%s (%s)",temp->nom_mt,temp->nom_g);
            gotoxy(24,8);
            printf("%s",temp->nom_sl);
            cadre(5,37,6,9,15);
        }
        else
        {
            gotoxy(24,7);
            printf("heur libre");
            cadre(5,37,6,9,15);
        }
    }
    else
    {
        gotoxy(24,7);
        printf("%s (%s)",temp->nom_mt,temp->nom_g);
        gotoxy(24,8);
        printf("%s",temp->nom_sl);
        cadre(5,37,6,9,15);
        temp=temp->next;
    }
     if(temp->next==NULL)
    {
        if(m==0)
        {
            gotoxy(24,10);
            printf("%s (%s)",temp->nom_mt,temp->nom_g);
            gotoxy(24,11);
            printf("%s",temp->nom_sl);
            cadre(5,37,9,12,15);
        }
        else
        {
            gotoxy(24,7);
            printf("heur libre");
            cadre(5,37,9,12,15);
        }
    }
    else
    {
        gotoxy(24,10);
        printf("%s (%s)",temp->nom_mt,temp->nom_g);
        gotoxy(24,11);
        printf("%s",temp->nom_sl);
        cadre(5,37,9,12,15);
        temp=temp->next;
    }
    if(temp->next==NULL)
    {
        if(m==0)
        {
            gotoxy(24,13);
            printf("%s (%s)",temp->nom_mt,temp->nom_g);
            gotoxy(24,14);
            printf("%s",temp->nom_sl);
            cadre(5,37,12,15,15);
        }
        else
        {
            gotoxy(24,13);
            printf("heur libre");
            cadre(5,37,12,15,15);
        }
    }
    else
    {
        gotoxy(24,13);
        printf("%s (%s)",temp->nom_mt,temp->nom_g);
        gotoxy(24,14);
        printf("%s",temp->nom_sl);
        cadre(5,37,12,15,15);
        temp=temp->next;
    }
     if(temp->next==NULL)
    {
        if(m==0)
        {
            gotoxy(24,16);
            printf("%s (%s)",temp->nom_mt,temp->nom_g);
            gotoxy(24,17);
            printf("%s",temp->nom_sl);
            cadre(5,37,15,18,15);
        }
        else
        {
            gotoxy(24,16);
            printf("heur libre");
            cadre(5,37,15,18,15);
        }
    }
    else
    {
        gotoxy(24,16);
        printf("%s (%s)",temp->nom_mt,temp->nom_g);
        gotoxy(24,17);
        printf("%s",temp->nom_sl);
        cadre(5,37,15,18,15);
        temp=temp->next;
    }
     if(temp->next==NULL)
    {
        if(m==0)
        {
            gotoxy(24,19);
            printf("%s (%s)",temp->nom_mt,temp->nom_g);
            gotoxy(24,20);
            printf("%s",temp->nom_sl);
            cadre(5,37,18,21,15);
        }
        else
        {
            gotoxy(24,19);
            printf("heur libre");
            cadre(5,37,18,21,15);
        }
    }
    else
    {
        gotoxy(24,19);
        printf("%s (%s)",temp->nom_mt,temp->nom_g);
        gotoxy(24,20);
        printf("%s",temp->nom_sl);
        cadre(5,37,18,21,15);
        temp=temp->next;
    }
     if(temp->next==NULL)
    {
        if(m==0)
        {
             gotoxy(24,22);
            printf("%s (%s)",temp->nom_mt,temp->nom_g);
            gotoxy(24,23);
            printf("%s",temp->nom_sl);
            cadre(5,37,21,24,15);
        }
        else
        {
            gotoxy(24,22);
            printf("heur libre");
             cadre(5,37,21,24,15);
        }
    }
    else
    {
        gotoxy(24,22);
        printf("%s (%s)",temp->nom_mt,temp->nom_g);
        gotoxy(24,23);
        printf("%s",temp->nom_sl);
        cadre(5,37,21,24,15);
        temp=temp->next;
    }
     if(temp->next==NULL)
    {
        if(m==0)
        {
            gotoxy(24,25);
            printf("%s (%s)",temp->nom_mt,temp->nom_g);
            gotoxy(24,26);
            printf("%s",temp->nom_sl);
            cadre(5,37,24,27,15);
        }
        else
        {
            gotoxy(24,25);
            printf("heur libre");
            cadre(5,37,24,27,15);
        }
    }
    else
    {
        gotoxy(24,25);
        printf("%s (%s)",temp->nom_mt,temp->nom_g);
        gotoxy(24,26);
        printf("%s",temp->nom_sl);
        cadre(5,37,24,27,15);
        temp=temp->next;
    }
     if(temp->next==NULL)
    {
        if(m==0)
        {
            gotoxy(24,28);
            printf("%s (%s)",temp->nom_mt,temp->nom_g);
            gotoxy(24,29);
            printf("%s",temp->nom_sl);
            cadre(5,37,27,30,15);
        }
        else
        {
            gotoxy(24,28);
            printf("heur libre");
            cadre(5,37,27,30,15);
        }
    }
    else
    {
        gotoxy(24,28);
        printf("%s (%s)",temp->nom_mt,temp->nom_g);
        gotoxy(24,29);
        printf("%s",temp->nom_sl);
        cadre(5,37,27,30,15);
        temp=temp->next;
    }
    //**************************colone_3********************//
    if(temp->next==NULL)
    {
        if(m==0)
        {
            gotoxy(41,7);
            printf("%s (%s)",temp->nom_mt,temp->nom_g);
            gotoxy(41,8);
            printf("%s",temp->nom_sl);
            cadre(5,53,6,9,15);
            m++;
        }
        else
        {
            gotoxy(41,7);
            printf("heur libre");
            cadre(5,53,6,9,15);
        }
    }
    else
    {
        gotoxy(41,7);
        printf("%s (%s)",temp->nom_mt,temp->nom_g);
        gotoxy(41,8);
        printf("%s",temp->nom_sl);
        cadre(5,53,6,9,15);
        temp=temp->next;
    }
    if(temp->next==NULL)
    {
        if(m==0)
        {
            gotoxy(41,10);
            printf("%s (%s)",temp->nom_mt,temp->nom_g);
            gotoxy(41,11);
            printf("%s",temp->nom_sl);
            cadre(5,53,9,12,15);
            m++;
        }
        else
        {
            gotoxy(41,10);
            printf("heur libre");
            cadre(5,53,9,12,15);
        }
    }
    else
    {
        gotoxy(41,10);
        printf("%s (%s)",temp->nom_mt,temp->nom_g);
        gotoxy(41,11);
        printf("%s",temp->nom_sl);
        cadre(5,53,9,12,15);
        temp=temp->next;
    }
    if(temp->next==NULL)
    {
        if(m==0)
        {
            gotoxy(41,13);
            printf("%s (%s)",temp->nom_mt,temp->nom_g);
            gotoxy(41,14);
            printf("%s",temp->nom_sl);
            cadre(5,53,12,15,15);
            m++;
        }
        else
        {
            gotoxy(41,13);
            printf("heur libre");
            cadre(5,53,12,15,15);
        }
    }
    else
    {
        gotoxy(41,13);
        printf("%s (%s)",temp->nom_mt,temp->nom_g);
        gotoxy(41,14);
        printf("%s",temp->nom_sl);
        cadre(5,53,12,15,15);
        temp=temp->next;
    }
    if(temp->next==NULL)
    {
        if(m==0)
        {
            gotoxy(41,16);
            printf("%s (%s)",temp->nom_mt,temp->nom_g);
            gotoxy(41,17);
            printf("%s",temp->nom_sl);
            cadre(5,53,15,18,15);
            m++;
        }
        else
        {
            gotoxy(41,16);
            printf("heur libre");
            cadre(5,53,15,18,15);
        }
    }
    else
    {
        gotoxy(41,16);
        printf("%s (%s)",temp->nom_mt,temp->nom_g);
        gotoxy(41,17);
        printf("%s",temp->nom_sl);
        cadre(5,53,15,18,15);
        temp=temp->next;
    }
    if(temp->next==NULL)
    {
        if(m==0)
        {
            gotoxy(41,19);
            printf("%s (%s)",temp->nom_mt,temp->nom_g);
            gotoxy(41,20);
            printf("%s",temp->nom_sl);
            cadre(5,53,18,21,15);
            m++;
        }
        else
        {
            gotoxy(41,19);
            printf("heur libre");
            cadre(5,53,18,21,15);
        }
    }
    else
    {
        gotoxy(41,19);
        printf("%s (%s)",temp->nom_mt,temp->nom_g);
        gotoxy(41,20);
        printf("%s",temp->nom_sl);
        cadre(5,53,18,21,15);
        temp=temp->next;
    }
    if(temp->next==NULL)
    {
        if(m==0)
        {
            gotoxy(41,22);
            printf("%s (%s)",temp->nom_mt,temp->nom_g);
            gotoxy(41,23);
            printf("%s",temp->nom_sl);
            cadre(5,53,21,24,15);
            m++;
        }
        else
        {
            gotoxy(41,22);
            printf("heur libre");
            cadre(5,53,21,24,15);
        }
    }
    else
    {
        gotoxy(41,22);
        printf("%s (%s)",temp->nom_mt,temp->nom_g);
        gotoxy(41,23);
        printf("%s",temp->nom_sl);
        cadre(5,53,21,24,15);
        temp=temp->next;
    }
    if(temp->next==NULL)
    {
        if(m==0)
        {
            gotoxy(41,25);
            printf("%s (%s)",temp->nom_mt,temp->nom_g);
            gotoxy(41,26);
            printf("%s",temp->nom_sl);
            cadre(5,53,24,27,15);
            m++;
        }
        else
        {
            gotoxy(41,25);
            printf("heur libre");
            cadre(5,53,24,27,15);
        }
    }
    else
    {
        gotoxy(41,25);
        printf("%s (%s)",temp->nom_mt,temp->nom_g);
        gotoxy(41,26);
        printf("%s",temp->nom_sl);
        cadre(5,53,24,27,15);
        temp=temp->next;
    }
    if(temp->next==NULL)
    {
        if(m==0)
        {
            gotoxy(41,28);
            printf("%s (%s)",temp->nom_mt,temp->nom_g);
            gotoxy(41,29);
            printf("%s",temp->nom_sl);
            cadre(5,53,27,30,15);
            m++;
        }
        else
        {
            gotoxy(41,28);
            printf("heur libre");
            cadre(5,53,27,30,15);
        }
    }
    else
    {
        gotoxy(41,28);
        printf("%s (%s)",temp->nom_mt,temp->nom_g);
        gotoxy(41,29);
        printf("%s",temp->nom_sl);
        cadre(5,53,27,30,15);
        temp=temp->next;
    }
    //**************************colone_4********************/
    if(temp->next==NULL)
    {
        if(m==0)
        {
            gotoxy(56,7);
            printf("%s (%s)",temp->nom_mt,temp->nom_g);
            gotoxy(56,8);
            printf("%s",temp->nom_sl);
            cadre(5,69,6,9,15);
            m++;
        }
        else
        {
            gotoxy(56,7);
            printf("heur libre");
            cadre(5,69,6,9,15);
        }
    }
    else
    {
        gotoxy(56,7);
        printf("%s (%s)",temp->nom_mt,temp->nom_g);
        gotoxy(56,8);
        printf("%s",temp->nom_sl);
        cadre(5,69,6,9,15);
        temp=temp->next;
    }
     if(temp->next==NULL)
    {
        if(m==0)
        {
            gotoxy(56,10);
            printf("%s (%s)",temp->nom_mt,temp->nom_g);
            gotoxy(56,11);
            printf("%s",temp->nom_sl);
            cadre(5,69,9,12,15);
            m++;
        }
        else
        {
            gotoxy(56,10);
            printf("heur libre");
            cadre(5,69,9,12,15);
        }
    }
    else
    {
        gotoxy(56,10);
        printf("%s (%s)",temp->nom_mt,temp->nom_g);
        gotoxy(56,11);
        printf("%s",temp->nom_sl);
        cadre(5,69,9,12,15);
        temp=temp->next;
    }
     if(temp->next==NULL)
    {
        if(m==0)
        {
            gotoxy(56,13);
            printf("%s (%s)",temp->nom_mt,temp->nom_g);
            gotoxy(56,14);
            printf("%s",temp->nom_sl);
            cadre(5,69,12,15,15);
            m++;
        }
        else
        {
            gotoxy(56,13);
            printf("heur libre");
            cadre(5,69,12,15,15);
        }
    }
    else
    {
        gotoxy(56,13);
        printf("%s (%s)",temp->nom_mt,temp->nom_g);
        gotoxy(56,14);
        printf("%s",temp->nom_sl);
        cadre(5,69,12,15,15);
        temp=temp->next;
    }
     if(temp->next==NULL)
    {
        if(m==0)
        {
            gotoxy(56,16);
            printf("%s (%s)",temp->nom_mt,temp->nom_g);
            gotoxy(56,17);
            printf("%s",temp->nom_sl);
            cadre(5,69,15,18,15);
            m++;
        }
        else
        {
            gotoxy(56,16);
            printf("heur libre");
            cadre(5,69,15,18,15);
        }
    }
    else
    {
        gotoxy(56,16);
        printf("%s (%s)",temp->nom_mt,temp->nom_g);
        gotoxy(56,17);
        printf("%s",temp->nom_sl);
        cadre(5,69,15,18,15);
        temp=temp->next;
    }
     if(temp->next==NULL)
    {
        if(m==0)
        {
            gotoxy(56,19);
            printf("%s (%s)",temp->nom_mt,temp->nom_g);
            gotoxy(56,20);
            printf("%s",temp->nom_sl);
            cadre(5,69,18,21,15);
            m++;
        }
        else
        {
            gotoxy(56,19);
            printf("heur libre");
            cadre(5,69,18,21,15);
        }
    }
    else
    {
        gotoxy(56,19);
        printf("%s (%s)",temp->nom_mt,temp->nom_g);
        gotoxy(56,20);
        printf("%s",temp->nom_sl);
        cadre(5,69,18,21,15);
        temp=temp->next;
    }
     if(temp->next==NULL)
    {
        if(m==0)
        {
            gotoxy(56,22);
            printf("%s (%s)",temp->nom_mt,temp->nom_g);
            gotoxy(56,23);
            printf("%s",temp->nom_sl);
            cadre(5,69,21,24,15);
            m++;
        }
        else
        {
            gotoxy(56,22);
            printf("heur libre");
            cadre(5,69,21,24,15);
        }
    }
    else
    {
        gotoxy(56,22);
        printf("%s (%s)",temp->nom_mt,temp->nom_g);
        gotoxy(56,23);
        printf("%s",temp->nom_sl);
        cadre(5,69,21,24,15);
        temp=temp->next;
    }
     if(temp->next==NULL)
    {
        if(m==0)
        {
            gotoxy(56,25);
            printf("%s (%s)",temp->nom_mt,temp->nom_g);
            gotoxy(56,26);
            printf("%s",temp->nom_sl);
            cadre(5,69,24,27 ,15);
            m++;
        }
        else
        {
            gotoxy(56,25);
            printf("heur libre");
            cadre(5,69,24,27,15);
        }
    }
    else
    {
        gotoxy(56,25);
        printf("%s (%s)",temp->nom_mt,temp->nom_g);
        gotoxy(56,26);
        printf("%s",temp->nom_sl);
        cadre(5,69,24,27,15);
        temp=temp->next;
    }
     if(temp->next==NULL)
    {
        if(m==0)
        {
            gotoxy(56,28);
            printf("%s (%s)",temp->nom_mt,temp->nom_g);
            gotoxy(56,29);
            printf("%s",temp->nom_sl);
            cadre(5,69,27,30,15);
            m++;
        }
        else
        {
            gotoxy(56,28);
            printf("heur libre");
            cadre(5,69,27,30,15);
        }
    }
    else
    {
        gotoxy(56,28);
        printf("%s (%s)",temp->nom_mt,temp->nom_g);
        gotoxy(56,29);
        printf("%s",temp->nom_sl);
        cadre(5,69,27,30,15);
        temp=temp->next;
    }
    //**************************colone_5********************/
   if(temp->next==NULL)
    {
        if(m==0)
        {
            gotoxy(72,7);
            printf("%s (%s)",temp->nom_mt,temp->nom_g);
            gotoxy(72,8);
            printf("%s",temp->nom_sl);
            cadre(5,85,6,9,15);
            m++;
        }
        else
        {
            gotoxy(72,7);
            printf("heur libre");
            cadre(5,85,6,9,15);
        }
    }
    else
    {
        gotoxy(72,7);
        printf("%s (%s)",temp->nom_mt,temp->nom_g);
        gotoxy(72,8);
        printf("%s",temp->nom_sl);
        cadre(5,85,6,9,15);
        temp=temp->next;
    }
    if(temp->next==NULL)
    {
        if(m==0)
        {
            gotoxy(72,10);
            printf("%s (%s)",temp->nom_mt,temp->nom_g);
            gotoxy(72,11);
            printf("%s",temp->nom_sl);
            cadre(5,85,9,12,15);
            m++;
        }
        else
        {
            gotoxy(72,10);
            printf("heur libre");
            cadre(5,85,9,12,15);
        }
    }
    else
    {
        gotoxy(72,10);
        printf("%s (%s)",temp->nom_mt,temp->nom_g);
        gotoxy(72,11);
        printf("%s",temp->nom_sl);
        cadre(5,85,9,12,15);
        temp=temp->next;
    }
    if(temp->next==NULL)
    {
        if(m==0)
        {
            gotoxy(72,13);
            printf("%s (%s)",temp->nom_mt,temp->nom_g);
            gotoxy(72,14);
            printf("%s",temp->nom_sl);
            cadre(5,85,12,15,15);
            m++;
        }
        else
        {
            gotoxy(72,13);
            printf("heur libre");
            cadre(5,85,12,15,15);
        }
    }
    else
    {
        gotoxy(72,13);
        printf("%s (%s)",temp->nom_mt,temp->nom_g);
        gotoxy(72,14);
        printf("%s",temp->nom_sl);
        cadre(5,85,12,15,15);
        temp=temp->next;
    }
    if(temp->next==NULL)
    {
        if(m==0)
        {
            gotoxy(72,16);
            printf("%s (%s)",temp->nom_mt,temp->nom_g);
            gotoxy(72,17);
            printf("%s",temp->nom_sl);
            cadre(5,85,15,18,15);
            m++;
        }
        else
        {
            gotoxy(72,16);
            printf("heur libre");
            cadre(5,85,15,18,15);
        }
    }
    else
    {
        gotoxy(72,16);
        printf("%s (%s)",temp->nom_mt,temp->nom_g);
        gotoxy(72,17);
        printf("%s",temp->nom_sl);
        cadre(5,85,15,18,15);
        temp=temp->next;
    }
    if(temp->next==NULL)
    {
        if(m==0)
        {
            gotoxy(72,19);
            printf("%s (%s)",temp->nom_mt,temp->nom_g);
            gotoxy(72,20);
            printf("%s",temp->nom_sl);
            cadre(5,85,18,21,15);
            m++;
        }
        else
        {
            gotoxy(72,19);
            printf("heur libre");
            cadre(5,85,18,21,15);
        }
    }
    else
    {
        gotoxy(72,19);
        printf("%s (%s)",temp->nom_mt,temp->nom_g);
        gotoxy(72,20);
        printf("%s",temp->nom_sl);
        cadre(5,85,18,21,15);
        temp=temp->next;
    }
    if(temp->next==NULL)
    {
        if(m==0)
        {
            gotoxy(72,22);
            printf("%s (%s)",temp->nom_mt,temp->nom_g);
            gotoxy(72,23);
            printf("%s",temp->nom_sl);
            cadre(5,85,21,24,15);
            m++;
        }
        else
        {
            gotoxy(72,22);
            printf("heur libre");
            cadre(5,85,21,24,15);
        }
    }
    else
    {
        gotoxy(72,22);
        printf("%s (%s)",temp->nom_mt,temp->nom_g);
        gotoxy(72,23);
        printf("%s",temp->nom_sl);
        cadre(5,85,21,24,15);
        temp=temp->next;
    }
    if(temp->next==NULL)
    {
        if(m==0)
        {
            gotoxy(72,25);
            printf("%s (%s)",temp->nom_mt,temp->nom_g);
            gotoxy(72,26);
            printf("%s",temp->nom_sl);
            cadre(5,85,24,27,15);
            m++;
        }
        else
        {
            gotoxy(72,25);
            printf("heur libre");
            cadre(5,85,24,27,15);
        }
    }
    else
    {
        gotoxy(72,25);
        printf("%s (%s)",temp->nom_mt,temp->nom_g);
        gotoxy(72,26);
        printf("%s",temp->nom_sl);
        cadre(5,85,24,27,15);
        temp=temp->next;
    }
    if(temp->next==NULL)
    {
        if(m==0)
        {
            gotoxy(72,28);
            printf("%s (%s)",temp->nom_mt,temp->nom_g);
            gotoxy(72,29);
            printf("%s",temp->nom_sl);
            cadre(5,85,27,30,15);
            m++;
        }
        else
        {
            gotoxy(72,28);
            printf("heur libre");
            cadre(5,85,27,30,15);
        }
    }
    else
    {
        gotoxy(72,28);
        printf("%s (%s)",temp->nom_mt,temp->nom_g);
        gotoxy(72,29);
        printf("%s",temp->nom_sl);
        cadre(5,85,27,30,15);
        temp=temp->next;
    }
    //**************************colone_6********************/
    if(temp->next==NULL)
    {
        if(m==0)
        {
            gotoxy(88,7);
            printf("%s (%s)",temp->nom_mt,temp->nom_g);
            gotoxy(88,8);
            printf("%s",temp->nom_sl);
            cadre(5,101,6,9,15);
            m++;
        }
        else
        {
            gotoxy(88,7);
            printf("heur libre");
            cadre(5,101,6,9,15);
        }
    }
    else
    {
        gotoxy(88,7);
        printf("%s (%s)",temp->nom_mt,temp->nom_g);
        gotoxy(88,8);
        printf("%s",temp->nom_sl);
        cadre(5,101,6,9,15);
        temp=temp->next;
    }
     if(temp->next==NULL)
    {
        if(m==0)
        {
            gotoxy(88,10);
            printf("%s (%s)",temp->nom_mt,temp->nom_g);
            gotoxy(88,11);
            printf("%s",temp->nom_sl);
            cadre(5,101,9,12,15);
            m++;
        }
        else
        {
            gotoxy(88,10);
            printf("heur libre");
            cadre(5,101,9,12,15);
        }
    }
    else
    {
        gotoxy(88,10);
        printf("%s (%s)",temp->nom_mt,temp->nom_g);
        gotoxy(88,11);
        printf("%s",temp->nom_sl);
        cadre(5,101,9,12,15);
        temp=temp->next;
    }
     if(temp->next==NULL)
    {
        if(m==0)
        {
            gotoxy(88,13);
            printf("%s (%s)",temp->nom_mt,temp->nom_g);
            gotoxy(88,14);
            printf("%s",temp->nom_sl);
            cadre(5,101,12,15,15);
            m++;
        }
        else
        {
            gotoxy(88,13);
            printf("heur libre");
            cadre(5,101,12,15,15);
        }
    }
    else
    {
        gotoxy(88,13);
        printf("%s (%s)",temp->nom_mt,temp->nom_g);
        gotoxy(88,14);
        printf("%s",temp->nom_sl);
        cadre(5,101,12,15,15);
        temp=temp->next;
    }
     if(temp->next==NULL)
    {
        if(m==0)
        {
            gotoxy(88,16);
            printf("%s (%s)",temp->nom_mt,temp->nom_g);
            gotoxy(88,17);
            printf("%s",temp->nom_sl);
            cadre(5,101,15,18,15);
            m++;
        }
        else
        {
            gotoxy(88,16);
            printf("heur libre");
            cadre(5,101,15,18,15);
        }
    }
    else
    {
        gotoxy(88,16);
        printf("%s (%s)",temp->nom_mt,temp->nom_g);
        gotoxy(88,17);
        printf("%s",temp->nom_sl);
        cadre(5,101,15,18,15);
        temp=temp->next;
    }
     if(temp->next==NULL)
    {
        if(m==0)
        {
            gotoxy(88,19);
            printf("%s (%s)",temp->nom_mt,temp->nom_g);
            gotoxy(88,20);
            printf("%s",temp->nom_sl);
            cadre(5,101,18,21,15);
            m++;
        }
        else
        {
            gotoxy(88,19);
            printf("heur libre");
            cadre(5,101,18,21,15);
        }
    }
    else
    {
        gotoxy(88,19);
        printf("%s (%s)",temp->nom_mt,temp->nom_g);
        gotoxy(88,20);
        printf("%s",temp->nom_sl);
        cadre(5,101,18,21,15);
        temp=temp->next;
    }
     if(temp->next==NULL)
    {
        if(m==0)
        {
            gotoxy(88,22);
            printf("%s (%s)",temp->nom_mt,temp->nom_g);
            gotoxy(88,23);
            printf("%s",temp->nom_sl);
            cadre(5,101,21,24,15);
            m++;
        }
        else
        {
            gotoxy(88,22);
            printf("heur libre");
            cadre(5,101,21,24,15);
        }
    }
    else
    {
        gotoxy(88,22);
        printf("%s (%s)",temp->nom_mt,temp->nom_g);
        gotoxy(88,23);
        printf("%s",temp->nom_sl);
        cadre(5,101,21,24,15);
        temp=temp->next;
    }
     if(temp->next==NULL)
    {
        if(m==0)
        {
            gotoxy(88,25);
            printf("%s (%s)",temp->nom_mt,temp->nom_g);
            gotoxy(88,26);
            printf("%s",temp->nom_sl);
            cadre(5,101,24,27,15);
            m++;
        }
        else
        {
            gotoxy(88,25);
            printf("heur libre");
            cadre(5,101,24,27,15);
        }
    }
    else
    {
        gotoxy(88,25);
        printf("%s (%s)",temp->nom_mt,temp->nom_g);
        gotoxy(88,26);
        printf("%s",temp->nom_sl);
        cadre(5,101,24,27,15);
        temp=temp->next;
    }
     if(temp->next==NULL)
    {
        if(m==0)
        {
            gotoxy(88,28);
            printf("%s (%s)",temp->nom_mt,temp->nom_g);
            gotoxy(88,29);
            printf("%s",temp->nom_sl);
            cadre(5,101,27,30,15);
            m++;
        }
        else
        {
            gotoxy(88,28);
            printf("heur libre");
            cadre(5,101,27,30,15);
        }
    }
    else
    {
        gotoxy(88,28);
        printf("%s (%s)",temp->nom_mt,temp->nom_g);
        gotoxy(88,29);
        printf("%s",temp->nom_sl);
        cadre(5,101,27,30,15);
        temp=temp->next;
    }
    cadre(5,101,4,30,14);
     printf("\n\n");
     int f =0;
    while(m==0)
    {
        cadre(56,98,33+f,37+f,11);
        gotoxy(57,34+f);
        printf("emploi de temps de le semaine suivente");
        gotoxy(57,35+f);
        system("pause");
        f=f+34;
        color(11,0);
       // printf("\n\n\n\t  ------------------------------EMPLOI DE TEMP DE LA SEMAINE SUIVANTE----------------------------");
        color(11,0);
        //**************************ligne_une********************//
        gotoxy(9,5+f);
        printf("horaire");
        cadre(5,21,4+f,6+f,14);
        gotoxy(25,5+f);
        printf("lundi");
        cadre(5,37,4+f,6+f,14);
        gotoxy(42,5+f);
        printf("mardi");
        cadre(5,53,4+f,6+f,14);
        gotoxy(57,5+f);
        printf("mercridi");
        cadre(5,69,4+f,6+f,14);
        gotoxy(73,5+f);
        printf("jeudi");
        cadre(5,85,4+f,6+f,14);
        gotoxy(89,5+f);
        printf("vendredi");
        cadre(5,101,4+f,6+f,14);
        //**************************colone_1********************//
        gotoxy(9,7+f);
        printf("8h a 9h");
        cadre(5,21,6+f,9+f,14);
        gotoxy(9,10+f);
        printf("9h a 10h");
        cadre(5,21,9+f,12+f,14);
        gotoxy(9,13+f);
        printf("10h a 11h");
        cadre(5,21,12+f,15+f,14);
        gotoxy(9,16+f);
        printf("11h a 12h");
        cadre(5,21,15+f,18+f,14);
        gotoxy(9,19+f);
        printf("13h a 14h");
        cadre(5,21,18+f,21+f,14);
        gotoxy(9,22+f);
        printf("14h a 15h");
        cadre(5,21,21+f,24+f,14);
        gotoxy(9,25+f);
        printf("15h a 16h");
        cadre(5,21,24+f,27+f,14);
        gotoxy(9,28+f);
        printf("16h a 17h");
        cadre(5,21,27+f,30+f,14);
        //gotoxy(9,7+f);
        color(15,0);
        //**************************colone_2********************//
        if(temp->next==NULL)
        {
            if(m==0)
            {
                gotoxy(24,7+f);
                printf("%s (%s)",temp->nom_mt,temp->nom_g);
                gotoxy(24,8+f);
                printf("%s",temp->nom_sl);
                cadre(5,37,6+f,9+f,15);
            }
            else
            {
                gotoxy(24,7+f);
                printf("heur libre");
                cadre(5,37,6+f,9+f,15);
            }
        }
        else
        {
            gotoxy(24,7+f);
            printf("%s (%s)",temp->nom_mt,temp->nom_g);
            gotoxy(24,8+f);
            printf("%s",temp->nom_sl);
            cadre(5,37,6+f,9+f,15);
            temp=temp->next;
        }
         if(temp->next==NULL)
        {
            if(m==0)
            {
                gotoxy(24,10+f);
                printf("%s (%s)",temp->nom_mt,temp->nom_g);
                gotoxy(24,11+f);
                printf("%s",temp->nom_sl);
                cadre(5,37,9+f,12+f,15);
            }
            else
            {
                gotoxy(24,7+f);
                printf("heur libre");
                cadre(5,37,9+f,12+f,15);
            }
        }
        else
        {
            gotoxy(24,10+f);
            printf("%s (%s)",temp->nom_mt,temp->nom_g);
            gotoxy(24,11+f);
            printf("%s",temp->nom_sl);
            cadre(5,37,9+f,12+f,15);
            temp=temp->next;
        }
        if(temp->next==NULL)
        {
            if(m==0)
            {
                gotoxy(24,13+f);
                printf("%s (%s)",temp->nom_mt,temp->nom_g);
                gotoxy(24,14+f);
                printf("%s",temp->nom_sl);
                cadre(5,37,12+f,15+f,15);
            }
            else
            {
                gotoxy(24,13+f);
                printf("heur libre");
                cadre(5,37,12+f,15+f,15);
            }
        }
        else
        {
            gotoxy(24,13+f);
            printf("%s (%s)",temp->nom_mt,temp->nom_g);
            gotoxy(24,14+f);
            printf("%s",temp->nom_sl);
            cadre(5,37,12+f,15+f,15);
            temp=temp->next;
        }
         if(temp->next==NULL)
        {
            if(m==0)
            {
                gotoxy(24,16+f);
                printf("%s (%s)",temp->nom_mt,temp->nom_g);
                gotoxy(24,17+f);
                printf("%s",temp->nom_sl);
                cadre(5,37,15+f,18+f,15);
            }
            else
            {
                gotoxy(24,16+f);
                printf("heur libre");
                cadre(5,37,15+f,18+f,15);
            }
        }
        else
        {
            gotoxy(24,16+f);
            printf("%s (%s)",temp->nom_mt,temp->nom_g);
            gotoxy(24,17+f);
            printf("%s",temp->nom_sl);
            cadre(5,37,15+f,18+f,15);
            temp=temp->next;
        }
         if(temp->next==NULL)
        {
            if(m==0)
            {
                gotoxy(24,19+f);
                printf("%s (%s)",temp->nom_mt,temp->nom_g);
                gotoxy(24,20);
                printf("%s",temp->nom_sl);
                cadre(5,37,18+f,21+f,15);
            }
            else
            {
                gotoxy(24,19+f);
                printf("heur libre");
                cadre(5,37,18+f,21+f,15);
            }
        }
        else
        {
            gotoxy(24,19+f);
            printf("%s (%s)",temp->nom_mt,temp->nom_g);
            gotoxy(24,20+f);
            printf("%s",temp->nom_sl);
            cadre(5,37,18+f,21+f,15);
            temp=temp->next;
        }
         if(temp->next==NULL)
        {
            if(m==0)
            {
                 gotoxy(24,22+f);
                printf("%s (%s)",temp->nom_mt,temp->nom_g);
                gotoxy(24,23+f);
                printf("%s",temp->nom_sl);
                cadre(5,37,21+f,24+f,15);
            }
            else
            {
                gotoxy(24,22+f);
                printf("heur libre");
                 cadre(5,37,21+f,24+f,15);
            }
        }
        else
        {
            gotoxy(24,22+f);
            printf("%s (%s)",temp->nom_mt,temp->nom_g);
            gotoxy(24,23+f);
            printf("%s",temp->nom_sl);
            cadre(5,37,21+f,24+f,15);
            temp=temp->next;
        }
         if(temp->next==NULL)
        {
            if(m==0)
            {
                gotoxy(24,25+f);
                printf("%s (%s)",temp->nom_mt,temp->nom_g);
                gotoxy(24,26+f);
                printf("%s",temp->nom_sl);
                cadre(5,37,24+f,27+f,15);
            }
            else
            {
                gotoxy(24,25+f);
                printf("heur libre");
                cadre(5,37,24+f,27+f,15);
            }
        }
        else
        {
            gotoxy(24,25+f);
            printf("%s (%s)",temp->nom_mt,temp->nom_g);
            gotoxy(24,26+f);
            printf("%s",temp->nom_sl);
            cadre(5,37,24+f,27+f,15);
            temp=temp->next;
        }
         if(temp->next==NULL)
        {
            if(m==0)
            {
                gotoxy(24,28+f);
                printf("%s (%s)",temp->nom_mt,temp->nom_g);
                gotoxy(24,29+f);
                printf("%s",temp->nom_sl);
                cadre(5,37,27+f,30+f,15);
            }
            else
            {
                gotoxy(24,28+f);
                printf("heur libre");
                cadre(5,37,27+f,30+f,15);
            }
        }
        else
        {
            gotoxy(24,28+f);
            printf("%s (%s)",temp->nom_mt,temp->nom_g);
            gotoxy(24,29+f);
            printf("%s",temp->nom_sl);
            cadre(5,37,27+f,30+f,15);
            temp=temp->next;
        }
        //**************************colone_3********************//
        if(temp->next==NULL)
        {
            if(m==0)
            {
                gotoxy(41,7+f);
                printf("%s (%s)",temp->nom_mt,temp->nom_g);
                gotoxy(41,8+f);
                printf("%s",temp->nom_sl);
                cadre(5,53,6+f,9+f,15);
                m++;
            }
            else
            {
                gotoxy(41,7+f);
                printf("heur libre");
                cadre(5,53,6+f,9+f,15);
            }
        }
        else
        {
            gotoxy(41,7+f);
            printf("%s (%s)",temp->nom_mt,temp->nom_g);
            gotoxy(41,8+f);
            printf("%s",temp->nom_sl);
            cadre(5,53,6+f,9+f,15);
            temp=temp->next;
        }
        if(temp->next==NULL)
        {
            if(m==0)
            {
                gotoxy(41,10+f);
                printf("%s (%s)",temp->nom_mt,temp->nom_g);
                gotoxy(41,11+f);
                printf("%s",temp->nom_sl);
                cadre(5,53,9+f,12+f,15);
                m++;
            }
            else
            {
                gotoxy(41,10+f);
                printf("heur libre");
                cadre(5,53,9+f,12+f,15);
            }
        }
        else
        {
            gotoxy(41,10+f);
            printf("%s (%s)",temp->nom_mt,temp->nom_g);
            gotoxy(41,11+f);
            printf("%s",temp->nom_sl);
            cadre(5,53,9+f,12+f,15);
            temp=temp->next;
        }
        if(temp->next==NULL)
        {
            if(m==0)
            {
                gotoxy(41,13+f);
                printf("%s (%s)",temp->nom_mt,temp->nom_g);
                gotoxy(41,14+f);
                printf("%s",temp->nom_sl);
                cadre(5,53,12+f,15+f,15);
                m++;
            }
            else
            {
                gotoxy(41,13+f);
                printf("heur libre");
                cadre(5,53,12+f,15+f,15);
            }
        }
        else
        {
            gotoxy(41,13+f);
            printf("%s (%s)",temp->nom_mt,temp->nom_g);
            gotoxy(41,14+f);
            printf("%s",temp->nom_sl);
            cadre(5,53,12+f,15+f,15);
            temp=temp->next;
        }
        if(temp->next==NULL)
        {
            if(m==0)
            {
                gotoxy(41,16+f);
                printf("%s (%s)",temp->nom_mt,temp->nom_g);
                gotoxy(41,17+f);
                printf("%s",temp->nom_sl);
                cadre(5,53,15+f,18+f,15);
                m++;
            }
            else
            {
                gotoxy(41,16+f);
                printf("heur libre");
                cadre(5,53,15+f,18+f,15);
            }
        }
        else
        {
            gotoxy(41,16+f);
            printf("%s (%s)",temp->nom_mt,temp->nom_g);
            gotoxy(41,17+f);
            printf("%s",temp->nom_sl);
            cadre(5,53,15+f,18+f,15);
            temp=temp->next;
        }
        if(temp->next==NULL)
        {
            if(m==0)
            {
                gotoxy(41,19+f);
                printf("%s (%s)",temp->nom_mt,temp->nom_g);
                gotoxy(41,20+f);
                printf("%s",temp->nom_sl);
                cadre(5,53,18+f,21+f,15);
                m++;
            }
            else
            {
                gotoxy(41,19+f);
                printf("heur libre");
                cadre(5,53,18+f,21+f,15);
            }
        }
        else
        {
            gotoxy(41,19+f);
            printf("%s (%s)",temp->nom_mt,temp->nom_g);
            gotoxy(41,20);
            printf("%s",temp->nom_sl);
            cadre(5,53,18+f,21+f,15);
            temp=temp->next;
        }
        if(temp->next==NULL)
        {
            if(m==0)
            {
                gotoxy(41,22+f);
                printf("%s (%s)",temp->nom_mt,temp->nom_g);
                gotoxy(41,23+f);
                printf("%s",temp->nom_sl);
                cadre(5,53,21+f,24+f,15);
                m++;
            }
            else
            {
                gotoxy(41,22+f);
                printf("heur libre");
                cadre(5,53,21+f,24+f,15);
            }
        }
        else
        {
            gotoxy(41,22+f);
            printf("%s (%s)",temp->nom_mt,temp->nom_g);
            gotoxy(41,23+f);
            printf("%s",temp->nom_sl);
            cadre(5,53,21+f,24+f,15);
            temp=temp->next;
        }
        if(temp->next==NULL)
        {
            if(m==0)
            {
                gotoxy(41,25+f);
                printf("%s (%s)",temp->nom_mt,temp->nom_g);
                gotoxy(41,26+f);
                printf("%s",temp->nom_sl);
                cadre(5,53,24+f,27+f,15);
                m++;
            }
            else
            {
                gotoxy(41,25+f);
                printf("heur libre");
                cadre(5,53,24+f,27+f,15);
            }
        }
        else
        {
            gotoxy(41,25+f);
            printf("%s (%s)",temp->nom_mt,temp->nom_g);
            gotoxy(41,26+f);
            printf("%s",temp->nom_sl);
            cadre(5,53,24+f,27+f,15);
            temp=temp->next;
        }
        if(temp->next==NULL)
        {
            if(m==0)
            {
                gotoxy(41,28+f);
                printf("%s (%s)",temp->nom_mt,temp->nom_g);
                gotoxy(41,29+f);
                printf("%s",temp->nom_sl);
                cadre(5,53,27+f,30+f,15);
                m++;
            }
            else
            {
                gotoxy(41,28+f);
                printf("heur libre");
                cadre(5,53,27+f,30+f,15);
            }
        }
        else
        {
            gotoxy(41,28+f);
            printf("%s (%s)",temp->nom_mt,temp->nom_g);
            gotoxy(41,29+f);
            printf("%s",temp->nom_sl);
            cadre(5,53,27+f,30+f,15);
            temp=temp->next;
        }
        //**************************colone_4********************/
        if(temp->next==NULL)
        {
            if(m==0)
            {
                gotoxy(56,7+f);
                printf("%s (%s)",temp->nom_mt,temp->nom_g);
                gotoxy(56,8+f);
                printf("%s",temp->nom_sl);
                cadre(5,69,6+f,9+f,15);
                m++;
            }
            else
            {
                gotoxy(56,7+f);
                printf("heure libre");
                cadre(5,69,6+f,9+f,15);
            }
        }
        else
        {
            gotoxy(56,7+f);
            printf("%s (%s)",temp->nom_mt,temp->nom_g);
            gotoxy(56,8+f);
            printf("%s",temp->nom_sl);
            cadre(5,69,6+f,9+f,15);
            temp=temp->next;
        }
         if(temp->next==NULL)
        {
            if(m==0)
            {
                gotoxy(56,10+f);
                printf("%s (%s)",temp->nom_mt,temp->nom_g);
                gotoxy(56,11+f);
                printf("%s",temp->nom_sl);
                cadre(5,69,9+f,12+f,15);
                m++;
            }
            else
            {
                gotoxy(56,10+f);
                printf("heur libre");
                cadre(5,69,9+f,12+f,15);
            }
        }
        else
        {
            gotoxy(56,10+f);
            printf("%s (%s)",temp->nom_mt,temp->nom_g);
            gotoxy(56,11+f);
            printf("%s",temp->nom_sl);
            cadre(5,69,9+f,12+f,15);
            temp=temp->next;
        }
         if(temp->next==NULL)
        {
            if(m==0)
            {
                gotoxy(56,13+f);
                printf("%s (%s)",temp->nom_mt,temp->nom_g);
                gotoxy(56,14+f);
                printf("%s",temp->nom_sl);
                cadre(5,69,12+f,15+f,15);
                m++;
            }
            else
            {
                gotoxy(56,13+f);
                printf("heur libre");
                cadre(5,69,12+f,15+f,15);
            }
        }
        else
        {
            gotoxy(56,13+f);
            printf("%s (%s)",temp->nom_mt,temp->nom_g);
            gotoxy(56,14+f);
            printf("%s",temp->nom_sl);
            cadre(5,69,12+f,15+f,15);
            temp=temp->next;
        }
         if(temp->next==NULL)
        {
            if(m==0)
            {
                gotoxy(56,16+f);
                printf("%s (%s)",temp->nom_mt,temp->nom_g);
                gotoxy(56,17+f);
                printf("%s",temp->nom_sl);
                cadre(5,69,15+f,18+f,15);
                m++;
            }
            else
            {
                gotoxy(56,16+f);
                printf("heur libre");
                cadre(5,69,15+f,18+f,15);
            }
        }
        else
        {
            gotoxy(56,16+f);
            printf("%s (%s)",temp->nom_mt,temp->nom_g);
            gotoxy(56,17+f);
            printf("%s",temp->nom_sl);
            cadre(5,69,15+f,18+f,15);
            temp=temp->next;
        }
         if(temp->next==NULL)
        {
            if(m==0)
            {
                gotoxy(56,19+f);
                printf("%s (%s)",temp->nom_mt,temp->nom_g);
                gotoxy(56,20+f);
                printf("%s",temp->nom_sl);
                cadre(5,69,18+f,21+f,15);
                m++;
            }
            else
            {
                gotoxy(56,19+f);
                printf("heur libre");
                cadre(5,69,18+f,21+f,15);
            }
        }
        else
        {
            gotoxy(56,19+f);
            printf("%s (%s)",temp->nom_mt,temp->nom_g);
            gotoxy(56,20+f);
            printf("%s",temp->nom_sl);
            cadre(5,69,18+f,21+f,15);
            temp=temp->next;
        }
         if(temp->next==NULL)
        {
            if(m==0)
            {
                gotoxy(56,22+f);
                printf("%s (%s)",temp->nom_mt,temp->nom_g);
                gotoxy(56,23+f);
                printf("%s",temp->nom_sl);
                cadre(5,69,21+f,24+f,15);
                m++;
            }
            else
            {
                gotoxy(56,22+f);
                printf("heur libre");
                cadre(5,69,21+f,24+f,15);
            }
        }
        else
        {
            gotoxy(56,22+f);
            printf("%s (%s)",temp->nom_mt,temp->nom_g);
            gotoxy(56,23+f);
            printf("%s",temp->nom_sl);
            cadre(5,69,21+f,24+f,15);
            temp=temp->next;
        }
         if(temp->next==NULL)
        {
            if(m==0)
            {
                gotoxy(56,25+f);
                printf("%s (%s)",temp->nom_mt,temp->nom_g);
                gotoxy(56,26+f);
                printf("%s",temp->nom_sl);
                cadre(5,69,24+f,27+f,15);
                m++;
            }
            else
            {
                gotoxy(56,25+f);
                printf("heur libre");
                cadre(5,69,24+f,27+f,15);
            }
        }
        else
        {
            gotoxy(56,25+f);
            printf("%s (%s)",temp->nom_mt,temp->nom_g);
            gotoxy(56,26+f);
            printf("%s",temp->nom_sl);
            cadre(5,69,24+f,27+f,15);
            temp=temp->next;
        }
         if(temp->next==NULL)
        {
            if(m==0)
            {
                gotoxy(56,28+f);
                printf("%s (%s)",temp->nom_mt,temp->nom_g);
                gotoxy(56,29+f);
                printf("%s",temp->nom_sl);
                cadre(5,69,27+f,30+f,15);
                m++;
            }
            else
            {
                gotoxy(56,28+f);
                printf("heur libre");
                cadre(5,69,27+f,30+f,15);
            }
        }
        else
        {
            gotoxy(56,28+f);
            printf("%s (%s)",temp->nom_mt,temp->nom_g);
            gotoxy(56,29+f);
            printf("%s",temp->nom_sl);
            cadre(5,69,27+f,30+f,15);
            temp=temp->next;
        }
        //**************************colone_5********************/
       if(temp->next==NULL)
        {
            if(m==0)
            {
                gotoxy(72,7+f);
                printf("%s (%s)",temp->nom_mt,temp->nom_g);
                gotoxy(72,8+f);
                printf("%s",temp->nom_sl);
                cadre(5,85,6+f,9+f,15);
                m++;
            }
            else
            {
                gotoxy(72,7+f);
                printf("heur libre");
                cadre(5,85,6+f,9+f,15);
            }
        }
        else
        {
            gotoxy(72,7+f);
            printf("%s (%s)",temp->nom_mt,temp->nom_g);
            gotoxy(72,8+f);
            printf("%s",temp->nom_sl);
            cadre(5,85,6+f,9+f,15);
            temp=temp->next;
        }
        if(temp->next==NULL)
        {
            if(m==0)
            {
                gotoxy(72,10+f);
                printf("%s (%s)",temp->nom_mt,temp->nom_g);
                gotoxy(72,11+f);
                printf("%s",temp->nom_sl);
                cadre(5,85,9+f,12+f,15);
                m++;
            }
            else
            {
                gotoxy(72,10+f);
                printf("heur libre");
                cadre(5,85,9+f,12+f,15);
            }
        }
        else
        {
            gotoxy(72,10+f);
            printf("%s (%s)",temp->nom_mt,temp->nom_g);
            gotoxy(72,11+f);
            printf("%s",temp->nom_sl);
            cadre(5,85,9+f,12+f,15);
            temp=temp->next;
        }
        if(temp->next==NULL)
        {
            if(m==0)
            {
                gotoxy(72,13+f);
                printf("%s (%s)",temp->nom_mt,temp->nom_g);
                gotoxy(72,14+f);
                printf("%s",temp->nom_sl);
                cadre(5,85,12+f,15+f,15);
                m++;
            }
            else
            {
                gotoxy(72,13+f);
                printf("heur libre");
                cadre(5,85,12+f,15+f,15);
            }
        }
        else
        {
            gotoxy(72,13+f);
            printf("%s (%s)",temp->nom_mt,temp->nom_g);
            gotoxy(72,14+f);
            printf("%s",temp->nom_sl);
            cadre(5,85,12+f,15+f,15);
            temp=temp->next;
        }
        if(temp->next==NULL)
        {
            if(m==0)
            {
                gotoxy(72,16+f);
                printf("%s (%s)",temp->nom_mt,temp->nom_g);
                gotoxy(72,17+f);
                printf("%s",temp->nom_sl);
                cadre(5,85,15+f,18+f,15);
                m++;
            }
            else
            {
                gotoxy(72,16+f);
                printf("heur libre");
                cadre(5,85,15+f,18+f,15);
            }
        }
        else
        {
            gotoxy(72,16+f);
            printf("%s (%s)",temp->nom_mt,temp->nom_g);
            gotoxy(72,17+f);
            printf("%s",temp->nom_sl);
            cadre(5,85,15+f,18+f,15);
            temp=temp->next;
        }
        if(temp->next==NULL)
        {
            if(m==0)
            {
                gotoxy(72,19+f);
                printf("%s (%s)",temp->nom_mt,temp->nom_g);
                gotoxy(72,20+f);
                printf("%s",temp->nom_sl);
                cadre(5,85,18+f,21+f,15);
                m++;
            }
            else
            {
                gotoxy(72,19+f);
                printf("heur libre");
                cadre(5,85,18+f,21+f,15);
            }
        }
        else
        {
            gotoxy(72,19+f);
            printf("%s (%s)",temp->nom_mt,temp->nom_g);
            gotoxy(72,20+f);
            printf("%s",temp->nom_sl);
            cadre(5,85,18+f,21+f,15);
            temp=temp->next;
        }
        if(temp->next==NULL)
        {
            if(m==0)
            {
                gotoxy(72,22+f);
                printf("%s (%s)",temp->nom_mt,temp->nom_g);
                gotoxy(72,23+f);
                printf("%s",temp->nom_sl);
                cadre(5,85,21+f,24+f,15);
                m++;
            }
            else
            {
                gotoxy(72,22+f);
                printf("heur libre");
                cadre(5,85,21+f,24+f,15);
            }
        }
        else
        {
            gotoxy(72,22+f);
            printf("%s (%s)",temp->nom_mt,temp->nom_g);
            gotoxy(72,23+f);
            printf("%s",temp->nom_sl);
            cadre(5,85,21+f,24+f,15);
            temp=temp->next;
        }
        if(temp->next==NULL)
        {
            if(m==0)
            {
                gotoxy(72,25+f);
                printf("%s (%s)",temp->nom_mt,temp->nom_g);
                gotoxy(72,26+f);
                printf("%s",temp->nom_sl);
                cadre(5,85,24+f,27+f,15);
                m++;
            }
            else
            {
                gotoxy(72,25+f);
                printf("heur libre");
                cadre(5,85,24+f,27+f,15);
            }
        }
        else
        {
            gotoxy(72,25+f);
            printf("%s (%s)",temp->nom_mt,temp->nom_g);
            gotoxy(72,26+f);
            printf("%s",temp->nom_sl);
            cadre(5,85,24+f,27+f,15);
            temp=temp->next;
        }
        if(temp->next==NULL)
        {
            if(m==0)
            {
                gotoxy(72,28+f);
                printf("%s (%s)",temp->nom_mt,temp->nom_g);
                gotoxy(72,29+f);
                printf("%s",temp->nom_sl);
                cadre(5,85,27+f,30+f,15);
                m++;
            }
            else
            {
                gotoxy(72,28+f);
                printf("heur libre");
                cadre(5,85,27+f,30+f,15);
            }
        }
        else
        {
            gotoxy(72,28+f);
            printf("%s (%s)",temp->nom_mt,temp->nom_g);
            gotoxy(72,29+f);
            printf("%s",temp->nom_sl);
            cadre(5,85,27+f,30+f,15);
            temp=temp->next;
        }
        //**************************colone_6********************/
        if(temp->next==NULL)
        {
            if(m==0)
            {
                gotoxy(88,7+f);
                printf("%s (%s)",temp->nom_mt,temp->nom_g);
                gotoxy(88,8+f);
                printf("%s",temp->nom_sl);
                cadre(5,101,6+f,9+f,15);
                m++;
            }
            else
            {
                gotoxy(88,7+f);
                printf("heur libre");
                cadre(5,101,6+f,9+f,15);
            }
        }
        else
        {
            gotoxy(88,7+f);
            printf("%s (%s)",temp->nom_mt,temp->nom_g);
            gotoxy(88,8+f);
            printf("%s",temp->nom_sl);
            cadre(5,101,6+f,9+f,15);
            temp=temp->next;
        }
         if(temp->next==NULL)
        {
            if(m==0)
            {
                gotoxy(88,10+f);
                printf("%s (%s)",temp->nom_mt,temp->nom_g);
                gotoxy(88,11+f);
                printf("%s",temp->nom_sl);
                cadre(5,101,9+f,12+f,15);
                m++;
            }
            else
            {
                gotoxy(88,10+f);
                printf("heur libre");
                cadre(5,101,9+f,12+f,15);
            }
        }
        else
        {
            gotoxy(88,10+f);
            printf("%s (%s)",temp->nom_mt,temp->nom_g);
            gotoxy(88,11+f);
            printf("%s",temp->nom_sl);
            cadre(5,101,9+f,12+f,15);
            temp=temp->next;
        }
         if(temp->next==NULL)
        {
            if(m==0)
            {
                gotoxy(88,13+f);
                printf("%s (%s)",temp->nom_mt,temp->nom_g);
                gotoxy(88,14+f);
                printf("%s",temp->nom_sl);
                cadre(5,101,12+f,15+f,15);
                m++;
            }
            else
            {
                gotoxy(88,13+f);
                printf("heur libre");
                cadre(5,101,12+f,15+f,15);
            }
        }
        else
        {
            gotoxy(88,13+f);
            printf("%s (%s)",temp->nom_mt,temp->nom_g);
            gotoxy(88,14+f);
            printf("%s",temp->nom_sl);
            cadre(5,101,12+f,15+f,15);
            temp=temp->next;
        }
         if(temp->next==NULL)
        {
            if(m==0)
            {
                gotoxy(88,16+f);
                printf("%s (%s)",temp->nom_mt,temp->nom_g);
                gotoxy(88,17+f);
                printf("%s",temp->nom_sl);
                cadre(5,101,15+f,18+f,15);
                m++;
            }
            else
            {
                gotoxy(88,16+f);
                printf("heur libre");
                cadre(5,101,15+f,18+f,15);
            }
        }
        else
        {
            gotoxy(88,16+f);
            printf("%s (%s)",temp->nom_mt,temp->nom_g);
            gotoxy(88,17+f);
            printf("%s",temp->nom_sl);
            cadre(5,101,15+f,18+f,15);
            temp=temp->next;
        }
         if(temp->next==NULL)
        {
            if(m==0)
            {
                gotoxy(88,19+f);
                printf("%s (%s)",temp->nom_mt,temp->nom_g);
                gotoxy(88,20+f);
                printf("%s",temp->nom_sl);
                cadre(5,101,18+f,21+f,15);
                m++;
            }
            else
            {
                gotoxy(88,19+f);
                printf("heur libre");
                cadre(5,101,18+f,21+f,15);
            }
        }
        else
        {
            gotoxy(88,19+f);
            printf("%s (%s)",temp->nom_mt,temp->nom_g);
            gotoxy(88,20+f);
            printf("%s",temp->nom_sl);
            cadre(5,101,18+f,21+f,15);
            temp=temp->next;
        }
         if(temp->next==NULL)
        {
            if(m==0)
            {
                gotoxy(88,22+f);
                printf("%s (%s)",temp->nom_mt,temp->nom_g);
                gotoxy(88,23+f);
                printf("%s",temp->nom_sl);
                cadre(5,101,21+f,24+f,15);
                m++;
            }
            else
            {
                gotoxy(88,22+f);
                printf("heur libre");
                cadre(5,101,21+f,24+f,15);
            }
        }
        else
        {
            gotoxy(88,22+f);
            printf("%s (%s)",temp->nom_mt,temp->nom_g);
            gotoxy(88,23+f);
            printf("%s",temp->nom_sl);
            cadre(5,101,21+f,24+f,15);
            temp=temp->next;
        }
         if(temp->next==NULL)
        {
            if(m==0)
            {
                gotoxy(88,25+f);
                printf("%s (%s)",temp->nom_mt,temp->nom_g);
                gotoxy(88,26+f);
                printf("%s",temp->nom_sl);
                cadre(5,101,24+f,27+f,15);
                m++;
            }
            else
            {
                gotoxy(88,25+f);
                printf("heur libre");
                cadre(5,101,24+f,27+f,15);
            }
        }
        else
        {
            gotoxy(88,25+f);
            printf("%s (%s)",temp->nom_mt,temp->nom_g);
            gotoxy(88,26+f);
            printf("%s",temp->nom_sl);
            cadre(5,101,24+f,27+f,15);
            temp=temp->next;
        }
         if(temp->next==NULL)
        {
            if(m==0)
            {
                gotoxy(88,28+f);
                printf("%s (%s)",temp->nom_mt,temp->nom_g);
                gotoxy(88,29+f);
                printf("%s",temp->nom_sl);
                cadre(5,101,27+f,30+f,15);
                m++;
            }
            else
            {
                gotoxy(88,28+f);
                printf("heur libre");
                cadre(5,101,27+f,30+f,15);
            }
        }
        else
        {
            gotoxy(88,28+f);
            printf("%s (%s)",temp->nom_mt,temp->nom_g);
            gotoxy(88,29+f);
            printf("%s",temp->nom_sl);
            cadre(5,101,27+f,30+f,15);
            temp=temp->next;
        }
        cadre(5,101,4+f,30+f,14);
    }
    cadre(56,98,33+f,37+f,11);
    gotoxy(57,34+f);
    system("pause");
    cadre(56,98,33+f,37+f,11);
    int r;
    gotoxy(57,34+f);
    printf("vouler vous retourner au menu ou quiter ?");
    gotoxy(57,35+f);
    printf("retourner(1)/quiter(0)\t ");
    scanf("%d",&r);
    if(r==1)
    {
        system("cls");
        menu();

    }
    else
    {
        cadre(56,98,33+f,37+f,11);
        gotoxy(57,34+f);
        printf("si vous voullez vraiment quiter cliquer  ");
        gotoxy(57,35+f);
        printf("sur une autre touche         ");
        printf("\n\n\n");
        color(15,0);
        exit(-1);
    }
}
void nmb_aloue(list2 li)
{
    color(15,0);
     if(is_empty_list2(li))
    {
        printf("\n\n\t\t\taucune alocation n'a ete fait\n\n");
        return;
    }
    printf("\n\n\n\n\t\t\tle nombre d alocation est de: \t%d\n\n",list_length(li));
    printf("\n\n\t");
    system("pause");
    cadre(56,98,20,24,11);
    int r;
    gotoxy(57,21);
    printf("vouler vous retourner au menu ou quiter ?");
    gotoxy(57,22);
    printf("retourner(1)/quiter(0)\t ");
    scanf("%d",&r);
    if(r==1)
    {
        system("cls");
        menu();

    }
    else
    {
        cadre(56,98,20,24,11);
        gotoxy(57,21);
        printf("si vous voullez vraiment quiter cliquer  ");
        gotoxy(57,22);
        printf("sur une autre touche         ");
        printf("\n\n\n");
        color(15,0);
        exit(-1);
    }
}
void nmb_mt_aloue(list2 li)
{
     if(is_empty_list2(li))
    {
        printf("\n\n\t\t\taucune alocation n'a ete fait\n\n");
        return;
    }
    int n1,n2,n3,n4,n=0,j=1;
    char t2[MAX_LEN],t1[MAX_LEN];
    n=nmb1();
    list mylist = new_list();
    FILE *UE=fopen("UE.txt","r");
    if(UE!=NULL)
    {
        while(j<=n)
        {
            fscanf(UE,"%s %d %s %d %d %d",t1,&n1,t2,&n2,&n3,&n4);
            mylist=ajoute_liste(mylist,t1,n1,t2,n2,n3,n4);
            j++;
        }
         fclose(UE);
    }
    else
    {
        printf("erreur");
        fclose(UE);
        exit(-1);
    }
    list tp1=mylist;
    list2 tp2=li;
    int s,m;
    printf("\n\t\t\tliste des alocation par matierre");
    while(tp1!= NULL)
    {
        s=0;
        while(tp2!= NULL)
        {
            m=strcmp(tp1->nom,tp2->nom_mt);
            if(m==0)
            {
                s++;
            }
            tp2=tp2->next;
        }
       printf("\n\n\t\t\t\t%s a %d alocotion",tp1->nom,s);
       tp1 = tp1->point;
       tp2=li;
    }
    cadre(56,98,23,27,11);
    gotoxy(57,24);
    system("pause");
    cadre(56,98,23,27,11);
    int r;
    gotoxy(57,24);
    printf("vouler vous retourner au menu ou quiter ?");
    gotoxy(57,25);
    printf("retourner(1)/quiter(0)\t ");
    scanf("%d",&r);
    if(r==1)
    {
        system("cls");
        menu();

    }
    else
    {
        cadre(56,98,23,27,11);
        gotoxy(57,24);
        printf("si vous voullez vraiment quiter cliquer  ");
        gotoxy(57,25);
        printf("sur une autre touche         ");
        printf("\n\n\n");
        color(15,0);
        exit(-1);
    }
}
