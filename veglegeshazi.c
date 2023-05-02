#include <stdio.h>              //szükséges header fájlok include-olása
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "C:\\.vscode\ccc\nagyhazi\debugmalloc.h"

typedef struct jatekosok {
char nev[100];  
int kor; 
int suly;
int magassag;
char csapat[50];
struct jatekosok* next;
} jatekosok;                    //játékosok adatait tartalmazó egyirányban láncolt lista

typedef struct csapatok {
char csapatnev [50];
char edzonev [50];
int arany;
struct csapatok* next;
} csapatok;                     //csapatok adatait tartalmazó egyirányban láncolt lista

typedef struct adatok {
char nev[100];
char csapatnev[50];
double pontok;
double kosarpasszok;
double lepattanok;
struct adatok* next;
} adatok;                       //adatokat tartalmazó egyirányban láncolt lista

jatekosok *pop_front(jatekosok *head)           //segédfüggvény játékosok lista feloldását segítő függvény (előadás diából vettem és alakítottam át)
{
	if (head != NULL)           // nem üres 
	{
		jatekosok *p = head;
		head = head->next;
		free(p);
	}
	return head;
}

void dispose_list(jatekosok *head)          //segédfüggvény játékosok lista felszabadítására használt függvény (előadás diából vettem és alakítottam át)
{
	while (head != NULL)
		head = pop_front(head);
}

jatekosok *push_front(jatekosok *head, char nev[100], int kor, int suly, int magassag, char csapat[50])          //segédfüggvény ha a lista eddig üres létrehoz egy új listát, majda későbbi ciklusokban ehhez a listához fűz hozzá új elemeket (előadás diából vettem és alakítottam át)
{
	jatekosok *p = (jatekosok*)malloc(sizeof(jatekosok));
	strcpy(p->nev, nev);        //ha a lista eddig üres, akkor új listát kell létrehozni
    p->kor = kor;
    p->suly = suly;
    p->magassag = magassag;
    strcpy(p->csapat, csapat);
	p->next = head;
	head = p;
	return head;
}

jatekosok *push_back(jatekosok *head, char nev[100], int kor, int suly, int magassag, char csapat[50])          //segédfüggvény hozzáfűz játékosokat a meglévő listához, vagy ha a lista még nem létezik, létrehozza azt (előadás diából vettem és alakítottam át)
{
	jatekosok *p;

	if (head == NULL)   //üres lista kezelése (itt egy új listát hozunk létre)
		return push_front(head, nev, kor, suly, magassag, csapat);

	for(p=head; p->next != NULL; p = p->next); //lista mostani végének megtalálása
	p->next = (jatekosok*)malloc(sizeof(jatekosok));  //oda új listaelem beszúrása
	strcpy(p->next->nev, nev);
    p->next->kor = kor;
    p->next->suly = suly;
    p->next->magassag = magassag;
    strcpy(p->next->csapat, csapat);  //adatok megadása
	p->next->next = NULL;
    return head;                                        //új lista visszaadása
}

csapatok *pop_front2(csapatok *head)        //segédfüggvény csapatok listájának feloldását segítő függvény (előadás diából vettem és alakítottam át)
{
	if (head != NULL)           // nem üres 
	{
		csapatok *p = head;
		head = head->next;
		free(p);
	}
	return head;
}

void dispose_list2(csapatok *head)          //segédfüggvény csapatok lista felszabadítására használt függvény (előadás diából vettem és alakítottam át)
{
	while (head != NULL)
		head = pop_front2(head);
}

csapatok *push_front2(csapatok *head, char csapatnev[50], char edzonev[50], int arany)          //segédfüggvény ha a lista eddig üres létrehoz egy új listát, majda későbbi ciklusokban ehhez a listához fűz hozzá új elemeket (előadás diából vettem és alakítottam át)
{
	csapatok *p = (csapatok*)malloc(sizeof(csapatok));
	strcpy(p->csapatnev, csapatnev);        //ha a lista eddig üres, akkor új listát kell létrehozni
    strcpy(p->edzonev, edzonev);
    p->arany = arany;
	p->next = head;
	head = p;
	return head;
}

csapatok *push_back2(csapatok *head, char csapatnev[50], char edzonev[50], int arany)          //segédfüggvény hozzáfűz csapatokat a meglévő listához, vagy ha a lista még nem létezik, létrehozza azt (előadás diából vettem és alakítottam át)
{
	csapatok *p;

	if (head == NULL)   //üres lista kezelése (itt egy új listát hozunk létre)
		return push_front2(head,csapatnev,edzonev,arany);

	for (p = head; p->next != NULL; p = p->next); //lista mostani végének megtalálása
	p->next = (csapatok*)malloc(sizeof(csapatok));  //oda új listaelem beszúrása
	strcpy(p->next->csapatnev, csapatnev);
    strcpy(p->next->edzonev, edzonev);  //adatok megadása
    p->next->arany = arany;
	p->next->next = NULL;
	return head;                                        //új lista visszaadása
}

adatok *pop_front3(adatok *head)        //segédfüggvény adatok listájának feloldását segítő függvény (előadás diából vettem és alakítottam át)
{
	if (head != NULL)           // nem üres 
	{
		adatok *p = head;
		head = head->next;
		free(p);
	}
	return head;
}

void dispose_list3(adatok *head)          //segédfüggvény adatok lista felszabadítására használt függvény (előadás diából vettem és alakítottam át)
{
	while (head != NULL)
		head = pop_front3(head);
}

adatok *push_front3(adatok *head, char nev[100], char csapatnev[50], double pontok, double kosarpasszok, double lepattanok)          //segédfüggvény ha a lista eddig üres létrehoz egy új listát, majda későbbi ciklusokban ehhez a listához fűz hozzá új elemeket (előadás diából vettem és alakítottam át)
{
	adatok *p = (adatok*)malloc(sizeof(adatok));
	strcpy(p->nev, nev);        //ha a lista eddig üres, akkor új listát kell létrehozni
    strcpy(p->csapatnev, csapatnev);
    p->pontok = pontok;
    p->kosarpasszok = kosarpasszok;
    p->lepattanok = lepattanok;
	p->next = head;
	head = p;
	return head;
}

adatok *push_back3(adatok *head, char nev[100], char csapatnev[50], double pontok, double kosarpasszok, double lepattanok)          //segédfüggvény hozzáfűz adatokat a meglévő listához, vagy ha a lista még nem létezik, létrehozza azt (előadás diából vettem és alakítottam át)
{
	adatok *p;

	if (head == NULL)   //üres lista kezelése (itt egy új listát hozunk létre)
		return push_front3(head,nev, csapatnev, pontok, kosarpasszok, lepattanok);

	for (p = head; p->next != NULL; p = p->next); //lista mostani végének megtalálása
	p->next = (adatok*)malloc(sizeof(adatok));  //oda új listaelem beszúrása
	strcpy(p->next->nev, nev);
    strcpy(p->next->csapatnev, csapatnev);  //adatok megadása
    p->next->pontok = pontok;
    p->next->kosarpasszok = kosarpasszok;
    p->next->lepattanok = lepattanok;
	p->next->next = NULL;
	return head;                                        //új lista visszaadása
}

jatekosok* beolvasjatekosok(jatekosok* head)  /*első főfüggvény, ez a játékosok.txt fájlból kiszedi az adatokat és azokat egy láncolt listába fűzi bele*/
{
    FILE *jatekosokfajl = fopen("jatekosoktext.txt", "rt");
    int kor, suly, magassag;
    char korc[20], sulyc[20], magassagc[20];
    char nev[100], csapat[50];
    if(jatekosokfajl==NULL)
    printf("Nem sikerult beolvasni a jatekosok.txt fajlt!");        //ha nem sikerül beolvasni a fájlt NULL pointert adunk vissza
    char line[200];
    char delimiter[] = ";";
    while(!feof(jatekosokfajl) && !ferror(jatekosokfajl))
    {
        if(fgets(line, 200 + 1, jatekosokfajl) != NULL)             //beolvasom soronként a játékosok adatait
        {
            strcpy(nev, strtok(line, delimiter));
            strcpy(korc, strtok(NULL, delimiter));
            strcpy(sulyc, strtok(NULL, delimiter));
            strcpy(magassagc, strtok(NULL, delimiter));             //majd az adatokat strtok-kal belehelyezem a megfelelő változóba
            strcpy(csapat, strtok(NULL, delimiter));
            kor = atoi(korc);                                       //mivel a strtok függvény csak stringekkel tud dolgozni, itt létrehozok az inteknek, vagy double-öknek egy ideiglenes stringet, majd abba másolom be az adatokat, és ezután ezeket atoi()függvénnyel visszaalakítom intre, vagy double-re
            suly = atoi(sulyc);
            magassag = atoi(magassagc);
            head = push_back(head, nev, kor, suly, magassag, csapat);   //a lista végére fűzöm az új sorokat
        }
        
    }fclose(jatekosokfajl);

return head;
}

csapatok* beolvascsapatok(csapatok* head2)                          /*második főfüggvény, ez a csapatok.txt fájlból kiszedi az adatokat és azokat egy láncolt listába fűzi bele*/
{
    FILE *csapatokfajl = fopen("csapatoktext.txt", "rt");
    int arany;
    char aranyc[20];
    char csapatnev[50], edzonev[50];
    if(csapatokfajl==NULL)
    printf("Nem sikerult beolvasni a csapatok.txt fajlt!");         //ha nem sikerül beolvasni a fájlt NULL pointert adunk vissza
    char line[200];
    char delimiter[] = ";";
    while(!feof(csapatokfajl) && !ferror(csapatokfajl))
    {
        if(fgets(line, 200 + 1, csapatokfajl) != NULL)              //beolvasom soronként a csapatok adatait
        {
            strcpy(csapatnev, strtok(line, delimiter));
            strcpy(edzonev, strtok(NULL, delimiter));
            strcpy(aranyc, strtok(NULL, delimiter));                //majd az adatokat strtok-kal belehelyezem a megfelelő változóba
            arany = atoi(aranyc);                                   //mivel a strtok függvény csak stringekkel tud dolgozni, itt létrehozok az inteknek, vagy double-öknek egy ideiglenes stringet, majd abba másolom be az adatokat, és ezután ezeket atoi()függvénnyel visszaalakítom intre, vagy double-re
            head2 = push_back2(head2, csapatnev, edzonev, arany);   //a lista végére fűzöm az új sorokat
        }
        
    }fclose(csapatokfajl);

return head2;
}

adatok* beolvasadatok(adatok* head3)                                /*harmadik főfüggvény, ez a adatok.txt fájlból kiszedi az adatokat és azokat egy láncolt listába fűzi bele*/
{
    FILE *adatokfajl = fopen("adatoktext.txt", "rt");
    double pontok, kosarpasszok, lepattanok;
    char pontokc[20], kosarpasszokc[20], lepattanokc[20];
    char nev[100], csapatnev[50];
    if(adatokfajl==NULL)
    printf("Nem sikerult beolvasni az adatok.txt fajlt!");            //ha nem sikerül beolvasni a fájlt NULL pointert adunk vissza
    char line[200];
    char delimiter[] = ";";
    while(!feof(adatokfajl) && !ferror(adatokfajl))
    {
        if(fgets(line, 200 + 1, adatokfajl) != NULL)                  //beolvasom soronként az adatokat
        {
            strcpy(nev, strtok(line, delimiter));
            strcpy(csapatnev, strtok(NULL, delimiter));
            strcpy(pontokc, strtok(NULL, delimiter));                 //majd az adatokat strtok-kal belehelyezem a megfelelő változóba
			strcpy(kosarpasszokc, strtok(NULL, delimiter));
			strcpy(lepattanokc, strtok(NULL, delimiter));
            pontok = atof(pontokc);                                   //mivel a strtok függvény csak stringekkel tud dolgozni, itt létrehozok az inteknek, vagy double-öknek egy ideiglenes stringet, majd abba másolom be az adatokat, és ezután ezeket atoi()függvénnyel visszaalakítom intre, vagy double-re
			kosarpasszok = atof(kosarpasszokc);
			lepattanok = atof(lepattanokc);
            head3 = push_back3(head3, nev, csapatnev, pontok, kosarpasszok, lepattanok);    //a lista végére fűzöm az új sorokat
        }
        
    }fclose(adatokfajl);

return head3;
}

jatekosok* kereso1(jatekosok* head, char input[100])    //megkeresi a játékosok láncolt listában a felhasználó által beírt nevűvel egyező elemet és átad egy erre az elemre mutató pointert
{
    jatekosok* ptr1 = NULL;                             //kinullázom a pointer ha esetleg a listában nem szereplő nevet adna meg a felhasználó, akkor tudjam, hogy baj van
    for(jatekosok* i = head; i!=NULL;i = i->next)
    {
        if(strcmp(input,i->nev)==0)                     
        {
            ptr1 = i;
        }
    }
    return ptr1;
}

csapatok* kereso2(jatekosok* ptr1, csapatok* head2)     //megkeresi a csapatok láncolt listában a felhasználó által beírt játékos csapatának az elemét és visszaad egy arra az elemre mutató pointert
{
    csapatok* ptr2 = NULL;                              //kinullázom a pointer ha esetleg a csapatok listában nem találná meg a program a csapat nevét, akkor tudjam, hogy baj van
    for(csapatok* j = head2;j!=NULL;j=j->next)
    {
        if(strcmp(ptr1->csapat,j->csapatnev)==0)
        {
            ptr2 = j;
        }
    }
    return ptr2;
}

adatok* kereso3(jatekosok* ptr1, adatok* head3)         //megkeresi az adatok láncolt listában a felhasználó által beírt játékos adatának az elemét és visszaad egy arra az elemre mutató pointert
{
    adatok* ptr3 = NULL;                                //kinullázom a pointer ha esetleg az adatok listában nem találná meg a program afelhasználó által beírt játékos adatait, akkor tudjam, hogy baj van
    for(adatok* k = head3; k!=NULL; k=k->next)
    {
        if(strcmp(ptr1->nev, k->nev) == 0)
        {
            ptr3 = k;
        }
    }
    return ptr3;
}

void kereso4(jatekosok* ptr1, csapatok* ptr2,adatok* ptr3, jatekosok* head1, adatok* head3)     //a program főfüggvénye ez csinálja a dolgok nagy részét
{
    int szamlalo1=0, szamlalo2=0;                       //számláló arra, ha nincs nála rosszabbul/jobban teljesítő játékos, akkor a program tudja ezt
    for(adatok* l = head3; l!=NULL; l = l->next)        //elindít egy ciklust, hogy megnézze az összes adatok láncolt listában tárolt elemet
    {
        if((ptr2->arany>0) && (strcmp(ptr1->csapat, l->csapatnev) == 0))    //ha a csapat többet nyert mint vesztett(vagy ugyanannyit), és a cikluson belüli pointer ugyanarra a játékosnevű cellára mutat, akkor belép a ciklusba
        {
            if(((l->pontok+l->kosarpasszok+l->lepattanok)/3)>((ptr3->pontok+ptr3->kosarpasszok+ptr3->lepattanok)/3))    //ha jobb nála egy játékos
            {

                for(jatekosok* m = head1; m!=NULL;m = m->next)      //megnézi az inputnál jobb játékosok adatait
                {
                    if(strcmp(l->nev, m->nev) == 0)
                    {
                        printf("\nNala jobban teljesito Jatekos :\n\tNeve : %s\n\tKora : %d\n\tSulya : %d kg\n\tMagassaga : %d cm\n\tCsapata : %s\n\n", m->nev, m->kor, m->suly, m->magassag, m->csapat);
                    }       //majd kiírja az adatokat
                }
            }
            if(((l->pontok+l->kosarpasszok+l->lepattanok)/3)<((ptr3->pontok+ptr3->kosarpasszok+ptr3->lepattanok)/3)) //ha rosszabb nála a játékos a számlálóhoz egyet hozzáad
            {
                szamlalo1++;
            }            
            if(szamlalo1==4)    //ha nincs nála jobban teljesítő játékos, akkor írja ki azt(mert öten vannak egy csapat kezdő ötjében)
                {
                    printf("\nNincs nala jobban teljesito jatekos a csapatban!\n\n");
                }
        }
        else if((ptr2->arany<=0) && (strcmp(ptr1->csapat, l->csapatnev) == 0))  //ha a csapat többet vesztett mint nyert, és a cikluson belüli pointer ugyanarra a játékosnevű cellára mutat, akkor belép a ciklusba
        {
            if(((l->pontok+l->kosarpasszok+l->lepattanok)/3)<((ptr3->pontok+ptr3->kosarpasszok+ptr3->lepattanok)/3))       //ha rosszabb nála egy játékos
            {
                for(jatekosok* n = head1; n!=NULL;n = n->next)      //megnézi az inputnál rosszabb játékosok adatait
                {
                    if(strcmp(l->nev, n->nev) == 0)         
                    {
                        printf("\nNala rosszabbul teljesito Jatekos :\n\tNeve : %s\n\tKora : %d\n\tSulya : %d kg\n\tMagassaga : %d cm\n\tCsapata : %s\n\n", n->nev, n->kor, n->suly, n->magassag, n->csapat);
                    }           //írja ki a nála rosszabbul teljesítő játékosokat
                }
            }
            if(((l->pontok+l->kosarpasszok+l->lepattanok)/3)>((ptr3->pontok+ptr3->kosarpasszok+ptr3->lepattanok)/3))        //ha egy játékos jobban teljesített nála, növelje a változót
            {
                szamlalo2++;
            }            
        }
    }
    if(szamlalo2==4)                            //ha nincs nála rosszabbul teljesítő játékos, akkor írja ki azt(mert öten vannak egy csapat kezdő ötjében)
        {
            printf("\nNincs nala rosszabbul teljesito jatekos a csapatban!\n\n");
        }
}

int main(void)
{
    jatekosok* head = NULL;     									//memóriafoglalás a három láncolt lista elejének
	csapatok* head2 = NULL;
	adatok* head3 = NULL;
	char input[100];
	printf("Irjon be egy idei szezonban jatszo NBA jatkost : ");    
	fgets(input,100,stdin);                                         //bekér egy játékosnevet, majd ezt a nevet belerakja az input stringbe 
        if(input[strlen(input)-1] = '\n')
            input[strlen (input) - 1] = '\0';                       //az input string végéről eltávolítja az esetleges új sor karaktert
    
    head = beolvasjatekosok(head);
	head2 = beolvascsapatok(head2);
	head3 = beolvasadatok(head3); 									//összes adat beolvasása láncolt listákba

    jatekosok* ptr1 = kereso1(head, input);                         //megkeresi a játékosok láncolt listában a felhasználó által beírt játékost
    if(ptr1==NULL)
    {
        printf("\nAz idei szezonban nem jatszik ilyen jatekos!\n\n");
    }

    csapatok* ptr2 = kereso2(ptr1, head2);                          //megkeresi a csapatok láncolt listában a felhasználó által beírt játékos csapatát
	if(ptr2==NULL)
    {
        printf("\nAz idei szezonban nincs ilyen csapat!\n\n");
    }
    
    adatok* ptr3 = kereso3(ptr1, head3);                            //megkeresi az adatok láncolt listában a felhasználó által beírt játékos adatait
    if(ptr3==NULL)
    {
        printf("\nNem talalhatok az adatok!\n\n");
    }
    
    kereso4(ptr1, ptr2, ptr3, head, head3);                         //A program fő függvénye, megkapja a beírt játékos elemre mutató pointert, a játékos csapatára mutató pointert, a játékos adataira mutató pointert, a játékosok láncolt lista kezdőelemét, és az adatok láncolt lista kezdőelemét 

    dispose_list(head);
	dispose_list2(head2);
	dispose_list3(head3); 											//összes láncolt lista felszabadítása (memóriaszivárgás megszüntetése)
    
    _sleep(10000);                                                   //a programot 3 másodperccel késlelteti, ha az exe fájlt nyitnánk meg legyen idő megnézni, a stdoutput-ot
	return 0;
}