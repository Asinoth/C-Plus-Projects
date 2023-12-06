#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXS 100
#define UNKNOWN -1


struct authors
{
         char *firstName;
         char *surName;
};

struct book
{
        char *author;
        struct authors *Auth;
        int numAuthors;
        char *titlos;
        char *oikos;
        char *isnb;
        int xronos;
        char *site;
        int selides;
        float timh;
        int apo8ema;
        int found;
}*catalog[100];

int line=0;

int read()
{
        int i=0, lastchar, numAuthor=0;
        char s[100][1000], *p, *writers, fileName[20];

        printf("Dwste to onoma tou arxeiou pou 8elete na diavasei to programma: ");
        scanf("%s", &fileName);
        FILE *fp;
        if ((fp = fopen(fileName, "r")) == NULL)
        {
                printf("To arxeio den vre8hke\n");
                return 0;
        }

        while ( !feof(fp) )
        {
                 fgets(s[line],1000,fp);
                lastchar = strlen(s[line])-1;
                if (s[line][lastchar] == '\n')
                        s[line][lastchar] = '\0';

                if ( feof(fp) == 0 )
                {
                        catalog[line] = (struct book *) malloc( sizeof(struct book) );

                        catalog[line]->Auth = (struct authors *) malloc( sizeof(struct authors) );
                        catalog[line]->titlos = (char *) malloc(MAXS * sizeof(char) );
                        catalog[line]->oikos = (char *) malloc(MAXS * sizeof(char) );
                        catalog[line]->isnb = (char *) malloc(MAXS * sizeof(char) );
                        catalog[line]->site = (char *) malloc(MAXS * sizeof(char) );
                        catalog[line]->found = 0;

                        p = strtok(s[line], ",");
                        while (p)
                        {

                                if (i==0)
                                        catalog[line]->author = p;
                                else if (i==1)
                                        catalog[line]->titlos = p;
                                else if (i==2)
                                        catalog[line]->oikos = p;
                                else if (i==3)
                                        catalog[line]->isnb = p;
                                else if (i==4)
                                        catalog[line]->xronos = atoi(p);
                                else if (i==5)
                                        catalog[line]->site = p;
                                else if (i==6)
                                        catalog[line]->selides = atoi(p);
                                else if (i==7)
                                        catalog[line]->timh = atof(p);
                                else if (i==8)
                                        catalog[line]->apo8ema = atoi(p);

                                p = strtok('\0', ",");
                                i++;
                        }

                        writers = strtok( catalog[line]->author, " και");
                        while (writers)
                        {
                                if (numAuthor % 2 == 0)
                                        catalog[line]->Auth[numAuthor/2].firstName = strdup(writers);
                                else
                                        catalog[line]->Auth[numAuthor/2].surName = strdup(writers);

                                writers = strtok('\0', " και");
                                numAuthor++;
                        }

                        catalog[line]->numAuthors = numAuthor/2;
                        numAuthor=0;
                        line++;
                        i=0;
                }
        }

        fclose(fp);

}

void printrecord(int i)
{
        int j;
        
        for(j=0; j< catalog[i]->numAuthors; j++)
        {
                if (j == catalog[i]->numAuthors -1)
                        printf("%s %s,", catalog[i]->Auth[j].firstName, catalog[i]->Auth[j].surName);
                else
                        printf("%s %s & ", catalog[i]->Auth[j].firstName, catalog[i]->Auth[j].surName);
        }

         printf("%s,%s,%s,%d,%s,%d,%.2f,%d\n",  catalog[i]->titlos, catalog[i]->oikos,
         catalog[i]->isnb, catalog[i]->xronos, catalog[i]->site, catalog[i]->selides, catalog[i]->timh, catalog[i]->apo8ema);
}
void printbooks()
{
        int j, i, NothingFound=0;

        for (i=0; i<line; i++)
        {
                if ( (catalog[i]->found == 1) && (catalog[i]->timh != '\0') )
                {
                        printrecord(i);
                }
                else
                        NothingFound++;
        }

        if (NothingFound > line)
                printf("\nDen Vre8hke Kanena Vivlio.\n\n");
}

void sortbyyear()
{
        int i,j;
        struct book *temp;

        for (i = (line - 1); i >= 0; i--)
        {
                for (j = 1; j <= i; j++)
                {
                        if (catalog[j-1]->xronos > catalog[j]->xronos )
                        {
                                temp = catalog[j-1];
                                catalog[j-1] = catalog[j];
                                catalog[j] = temp;
                        }
                        else if (catalog[j-1]->xronos == catalog[j]->xronos )
                        {
                                if (catalog[j-1]->timh > catalog[j]->timh )
                                {
                                        temp = catalog[j-1];
                                        catalog[j-1] = catalog[j];
                                        catalog[j] = temp;
                                }

                        }
                }
        }
}

void sortbyprice()
{
        int i,j;
        struct book *temp;

        for (i = (line - 1); i >= 0; i--)
        {
                for (j = 1; j <= i; j++)
                {
                        if (catalog[j-1]->timh > catalog[j]->timh )
                        {
                                temp = catalog[j-1];
                                catalog[j-1] = catalog[j];
                                catalog[j] = temp;
                        }
                }
        }
}

void searchName()
{
        int i, j;
        char str[20];

        printf("Dwste string pros anazhthsh: ");
        scanf("%s", &str);

        for (i=0; i<line; i++)
        {
                for(j=0; j< catalog[i]->numAuthors; j++)
                {
                        if ( (strstr(catalog[i]->titlos,str) != '\0') || (strstr(catalog[i]->Auth[j].firstName,str) != '\0') ||
                                (strstr(catalog[i]->Auth[j].surName,str) != '\0') )
                        {
                                catalog[i]->found = 1;
                        }
                }
        }

        printbooks();
}

void searchAuthor()
{
        int i, j;
        char str[20];

        printf("Dwste epwnumo pros anazhthsh: ");
        scanf("%s", &str);

        for (i=0; i<line; i++)
        {
                for(j=0; j< catalog[i]->numAuthors; j++)
                {
                        if ( strstr(catalog[i]->Auth[j].surName,str) != '\0')
                        {
                                catalog[i]->found = 1;
                        }
                }
        }

        printbooks();

}

void newbook()
{
        int i=0;
        char tmp[100];

        catalog[line] = (struct book *) malloc( sizeof(struct book) );

        catalog[line]->Auth = (struct authors *) malloc( sizeof(struct authors) );
        catalog[line]->titlos = (char *) malloc(MAXS * sizeof(char) );
        catalog[line]->oikos = (char *) malloc(MAXS * sizeof(char) );
        catalog[line]->isnb = (char *) malloc(MAXS * sizeof(char) );
        catalog[line]->site = (char *) malloc(MAXS * sizeof(char) );
        catalog[line]->found = 0;


        printf("Dwste ta stoixeia tou vivliou pou 8elete na eisagete.\n\n");
        printf("Posoi einai oi suggrafeis tou vivliou: ");
        scanf("%d", &catalog[line]->numAuthors);

        for(i=0; i < catalog[line]->numAuthors; i++)
        {
                printf("Dwste to onoma tou %dou suggrafea: ", i+1);
                scanf("%s", &tmp);
                catalog[line]->Auth[i].firstName = strdup(tmp);
                printf("Dwste to epwnumo tou %dou suggrafea: ", i+1);
                scanf("%s", &tmp);
                catalog[line]->Auth[i].surName = strdup(tmp);
        }

        printf("Dwste ton titlo tou vivliou: ");
        gets(tmp);
        gets(tmp);
        catalog[line]->titlos = strdup(tmp);
        printf("Dwste ton oiko tou: ");
        scanf("%s", &tmp);
        catalog[line]->oikos = strdup(tmp);
        printf("Dwste to isnb tou: ");
        scanf("%s", &tmp);
        catalog[line]->isnb = strdup(tmp);
        printf("Dwste ton xrono ekdoshs tou: ");
        scanf("%d", &catalog[line]->xronos);
        printf("Dwste to site tou: ");
        scanf("%s", &tmp);
        catalog[line]->site = strdup(tmp);
        printf("Dwste ton ari8mo twn selidwn tou: ");
        scanf("%d", &catalog[line]->selides);
        printf("Dwste thn timh tou: ");
        scanf("%f", &catalog[line]->timh);
        printf("Dwste to apo8ema tou: ");
        scanf("%d", &catalog[line]->apo8ema);

        line++;
        printf("To vivlio kataxwrh8hke epityxws.\n");
        sortbyprice();
}

void deletebook()
{
        int j, i;
        char str[10];

        searchName();

        for (i=0; i<line; i++)
        {
                if ( (catalog[i]->found == 1) && (catalog[i]->timh != '\0') )
                {
                        printf("\n8elete na diagrapsete to vivlio:\n");
                        printrecord(i);

                        printf("Plhktrologiste nai/oxi: ");
                        scanf("%s", &str);
                        if (!strcmp(str,"nai"))
                        {
                                printf("To vivlio diagrafhke.\n");
                                catalog[i]->timh = '\0';
                        }
                }
        }
}

void renamebook()
{
        int j, i, sel=1;
        char str[10], tmp[50];

        searchName();

        for (i=0; i<line; i++)
        {
                if ( (catalog[i]->found == 1) && (catalog[i]->timh != '\0') )
                {
                        printf("\n8elete na dior8wsete to vivlio:\n");
                        printrecord(i);

                        printf("Plhktrologiste nai/oxi: ");
                        scanf("%s", &str);
                        while ( !strcmp(str,"nai") )
                        {
                                printf("Ti 8elete na dior8wsete?\n");
                                printf("1.suggrafeis\n2.titlos\n3.oikos\n");
                                printf("4.isnb\n5.xronos ekdoshs\n6.site\n");
                                printf("7.ari8mos selidwn\n8.timh\n9.apo8ema\n");
                                printf("Dwste opoiodhpote allo ari8mo gia termatismo.\n");
                                scanf("%d", &sel);

                                if (sel == 1)
                                {
                                        printf("Posoi einai oi suggrafeis tou vivliou: ");
                                        scanf("%d", &catalog[i]->numAuthors);
                                        for(j=0; j < catalog[i]->numAuthors; j++)
                                        {
                                                printf("Dwste to onoma tou %dou suggrafea: ", j+1);
                                                scanf("%s", &tmp);
                                                catalog[i]->Auth[j].firstName = strdup(tmp);

                                                printf("Dwste to epwnumo tou %dou suggrafea: ", j+1);
                                                scanf("%s", &tmp);
                                                catalog[i]->Auth[j].surName = strdup(tmp);
                                        }
                                }
                                else if (sel == 2)
                                {
                                        printf("Dwste ton titlo tou vivliou: ");
                                        gets(tmp);
                                        gets(tmp);
                                        catalog[i]->titlos = strdup(tmp);
                                }
                                else if (sel == 3)
                                {
                                        printf("Dwste ton oiko tou: ");
                                        scanf("%s", &tmp);
                                        catalog[i]->oikos = strdup(tmp);
                                }
                                else if (sel == 4)
                                {
                                        printf("Dwste to isnb tou: ");
                                        scanf("%s", &tmp);
                                        catalog[i]->isnb = strdup(tmp);
                                }
                                else if (sel == 5)
                                {
                                        printf("Dwste ton xrono ekdoshs tou: ");
                                        scanf("%d", &catalog[i]->xronos);
                                }
                                else if (sel == 6)
                                {
                                        printf("Dwste to site tou: ");
                                        scanf("%s", &tmp);
                                        catalog[i]->site = strdup(tmp);
                                }
                                else if (sel == 7)
                                {
                                        printf("Dwste ton ari8mo twn selidwn tou: ");
                                        scanf("%d", &catalog[i]->selides);
                                }
                                else if (sel == 8)
                                {
                                        printf("Dwste thn timh tou: ");
                                        scanf("%f", &catalog[i]->timh);
                                }
                                else if (sel == 9)
                                {
                                        printf("Dwste to apo8ema tou: ");
                                        scanf("%d", &catalog[i]->apo8ema);
                                }
                                else
                                {
                                        printf("H dior8wsh oloklhrw8hke.\n");
                                        break;
                                }
                        }
                }
        }
}
        
void buybook()
{
        int j, i, Numbook;
        char str[10], tmp[50];

        searchName();
        
        for (i=0; i<line; i++)
        {
                if ( (catalog[i]->found == 1) && (catalog[i]->timh != '\0') )
                {
                        printf("\n8elete na agorasete to vivlio:\n");
                        for(j=0; j< catalog[i]->numAuthors; j++)
                        {
                                if (j == catalog[i]->numAuthors -1)
                                        printf("%s %s,", catalog[i]->Auth[j].firstName, catalog[i]->Auth[j].surName);
                                else
                                        printf("%s %s & ", catalog[i]->Auth[j].firstName, catalog[i]->Auth[j].surName);
                        }
                        printf("%s,%s,%s,%d,%s,%d,%.2f,%d\n",  catalog[i]->titlos, catalog[i]->oikos,
                        catalog[i]->isnb, catalog[i]->xronos, catalog[i]->site, catalog[i]->selides, catalog[i]->timh, catalog[i]->apo8ema);

                        printf("Plhktrologiste nai/oxi: ");
                        scanf("%s", &str);
                        if ( !strcmp(str,"nai") )
                        {
                                printf("Posa 8elete na agorasete: ");
                                scanf("%d", &Numbook);
                                while (Numbook > catalog[i]->apo8ema)
                                {
                                        printf("Yparxoun mono %d dia8esima vivlia.\n", catalog[i]->apo8ema);
                                        printf("3anadwste ton ari8mo vivliwn pou 8elete na agorasete: ");
                                        scanf("%d", &Numbook);
                                }
                                
                                catalog[i]->apo8ema = catalog[i]->apo8ema - Numbook;
                                printf("Ari8mos vivliwn pou apomenoun: %d\n", catalog[i]->apo8ema);
                        }
                }
                                        
        }
}

int main(void)
{
        int sel=-1, i;
        char str[20];

        read();

        while ( sel != 0 )
        {

                printf("\n--- MENU ---\n");
                printf("\nTi 8elete na kanete...Epile3te enan ari8mo.\n");
                printf("1. Ektypwsh vivliwn ws pros thn timh.\n2. Ektypwsh vivliwn ws pros thn xronia.\n");
                printf("3. Genikh Anazhthsh.\n4. Anazhthsh vivliwn suggrafea.\n");
                printf("5. Eisagwsh neou vivliou.\n6. Diagrafh vivliou.\n");
                printf("7. Dior8wsh vivliou.\n8. Agora vivliou.\n0.Termatismos Programmatos.\n\n");


                scanf("%d",&sel);
                while ( (sel>8) || (sel<0) )
                {
                        printf("\nLa8os eisodos...Prospa8eiste 3ana.\n");
                        printf("Dwste enan ari8mo meta3u 1-9: ");
                        scanf("%d",&sel);
                }

                if (sel == 1)
                {
                        for (i=0; i<line; i++)
                                catalog[i]->found = 1;

                        sortbyprice();
                        printbooks();
                }
                else if (sel == 2)
                {
                        for (i=0; i<line; i++)
                                catalog[i]->found = 1;

                        sortbyyear();
                        printbooks();
                }
                else if (sel == 3)
                {
                        searchName();
                }
                else if (sel == 4)
                {
                        searchAuthor();
                }
                else if (sel == 5)
                {
                        newbook();
                }
                else if (sel == 6)
                {
                        deletebook();
                }
                else if (sel == 7)
                {
                        renamebook();
                }
                else if (sel == 8)
                {
                     buybook();
                }

                for (i=0; i<line; i++)
                        catalog[i]->found = 0;
        }


        printf("\nTelos Programmatos.\n");
        return 0;
}
