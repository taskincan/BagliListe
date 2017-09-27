#include "stdio.h"
#include "stdlib.h"
#include "conio.h"

typedef struct tamsayi{
	int veri;//Veriyi tutar.
	struct tamsayi *next;//Sonraki verinin adresini tutar.
}sayi;

sayi *head=NULL;//Ba�lang�� adresi NULL tan�mlan�r.
sayi *onceki,*ileri,*temp;

char menu(void);
void ekle(void);
void sil(void);
void listele(void);
void say(void);

int main()
{
	while(1)//Fonksiyon i�lemi bittikten sonra men� tekrar �al���r.
	{
	switch(menu())
	{
		case 'e' : ekle();break;
		case 's' : sil();break;
		case 'l' : listele();break;
		case 'c' : say();break;
		case 'q' : goto cikis;//��k�� talimat� verildi�inde while d�ng�s�nden ��kar.
		default:
			system("cls");//Ekran� temizler.
			printf("\nSecenekler arasinda yok\n");
	}
	}
cikis:
	return 0;
}

char menu(void)
{
	char a;
	printf("\n-----MENU-----\n");
	printf("E - Ekle\n");
	printf("S - Sil\n");
	printf("L - Listele\n");
	printf("C - Say\n");
	printf("Q - Cikis\n");
	printf("Secenek : ");
	a = getch();
	return a;
}
void ekle()
{
	sayi *yeni = (sayi *)malloc(sizeof(sayi));//Kullan�c�dan al�nacak de�er i�in sayi tipinde bellek alan� ayr�l�r.

	system("cls");//Ekran� temizler.
	printf("\nEklenecek sayiyi girin : ");//Kullan�c�dan say� istenir.

	scanf("%d",&yeni->veri);//Kullan�c�n�n girdi�i veri yeni olu�turulacak d���m�n veri k�sm�na atan�r.
	yeni->next = NULL;//Sona eklenece�i i�in yeni olu�turulan d���m�n next pointer�na NULL de�er atan�r.

	temp=head;//D�ng�de kullan�lacak d���m ba�lang�� olarak atan�r.
	while (head!=NULL && temp->next!=NULL)//Son de�ere gelene kadar d�ng� devam eder.
	{temp=temp->next;}

		if (head==NULL)//Liste bo�sa eklenen d���m ba�lang�� de�eri olarak atan�r.
		{head=yeni;}
		else 
		{temp->next = yeni;}//Son de�er ile yeni eklenen de�er aras�nda ba� olu�turulur.
	
	system("cls");//Ekran� temizler.
	printf("Sayi eklendi\n\n");
}
void sil()
{
	int at;//Silmek istedi�imiz say�.

	if (head==NULL)//Ba�lang�� NULL ise liste bo� demektir.
	{printf("\nListe bos!!!");}

	system("cls");//Ekran� temizler.
	printf("\nSilinecek sayiyi girin : ");
	scanf("%d",&at);//Kullan�c�dan silmek istedi�i de�er al�n�r.

	onceki=NULL;//�nceki de�erin silinecek de�erle olan ba�� kopar�l�r.
	temp=head;//D�ng�de kullan�lacak d���m ba�lang�� olarak atan�r.

	while (temp!=NULL && temp->veri!=at)
	{
		onceki=temp;//�nceki d���m�n verisini tutar.
		temp=temp->next;//Sonraki d���m�n adresini tutar.
	}

	if (temp==NULL)//Arama esnas�nda ge�ici d���me de�er atanmad�ysa girilen say� listede yok demektir.
	{
		printf("\nSayi listede yok");
		main();
	}

	if (onceki==NULL)//Silinen de�er ilk s�radaysa sonraki de�eri belirten adres head olarak tan�mlan�r.
	{head=temp->next;}
	else 
	{onceki->next = temp->next;}//Silinen d���mden �nceki d���m ile sonraki d���m aras�nda ba� olu�turulur.


	free(temp);//temp i�in ayr�lan belle�i bo�alt�r.
	system("cls");//Ekran� temizler.
	printf("Sayi listeden silindi\n\n");
}

void listele()
{
	int i=1;

	printf("\nLISTE : \n");

	for(ileri=head;ileri!=NULL;ileri=ileri->next)//NULL de�ere ula�ana kadar d�ng� �al���r.
	{
		printf("\n%d. sayi = %d\n",i,ileri->veri);//Herhangi bir de�er bulununca s�ras�yla birlikte ekrana yazd�r�l�r.
		i++;
	}

	if (head==NULL)//Ba�lang�� NULL ise liste bo� demektir.
	{
		printf("\nListe bos!!!\n");
	}

	system("pause");//Herhangi bir tu�a bas�lana kadar i�lem yap�lmaz.
	system("cls");//Ekran� temizler.
}

void say()
{
	int counter=0;

	for(ileri=head;ileri!=NULL;ileri=ileri->next) //NULL de�ere ula�ana kadar d�ng� �al���r.
	{counter++;}//�al��an her i�lem i�in sayac� artt�r.

	if (counter==0)//De�er bulunamad�ysa liste bo� demektir.
	{
		system("cls");//Ekran� temizler.
		printf("\nListe bos!!!\n");
	}
	else//Eleman say�s�n� g�ster.
	{
		system("cls");//Ekran� temizler.
		printf("\n%d tane elaman var\n\n",counter);
	}
}




