#include "stdio.h"
#include "stdlib.h"
#include "conio.h"

typedef struct tamsayi{
	int veri;//Veriyi tutar.
	struct tamsayi *next;//Sonraki verinin adresini tutar.
}sayi;

sayi *head=NULL;//Baþlangýç adresi NULL tanýmlanýr.
sayi *onceki,*ileri,*temp;

char menu(void);
void ekle(void);
void sil(void);
void listele(void);
void say(void);

int main()
{
	while(1)//Fonksiyon iþlemi bittikten sonra menü tekrar çalýþýr.
	{
	switch(menu())
	{
		case 'e' : ekle();break;
		case 's' : sil();break;
		case 'l' : listele();break;
		case 'c' : say();break;
		case 'q' : goto cikis;//Çýkýþ talimatý verildiðinde while döngüsünden çýkar.
		default:
			system("cls");//Ekraný temizler.
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
	sayi *yeni = (sayi *)malloc(sizeof(sayi));//Kullanýcýdan alýnacak deðer için sayi tipinde bellek alaný ayrýlýr.

	system("cls");//Ekraný temizler.
	printf("\nEklenecek sayiyi girin : ");//Kullanýcýdan sayý istenir.

	scanf("%d",&yeni->veri);//Kullanýcýnýn girdiði veri yeni oluþturulacak düðümün veri kýsmýna atanýr.
	yeni->next = NULL;//Sona ekleneceði için yeni oluþturulan düðümün next pointerýna NULL deðer atanýr.

	temp=head;//Döngüde kullanýlacak düðüm baþlangýç olarak atanýr.
	while (head!=NULL && temp->next!=NULL)//Son deðere gelene kadar döngü devam eder.
	{temp=temp->next;}

		if (head==NULL)//Liste boþsa eklenen düðüm baþlangýç deðeri olarak atanýr.
		{head=yeni;}
		else 
		{temp->next = yeni;}//Son deðer ile yeni eklenen deðer arasýnda bað oluþturulur.
	
	system("cls");//Ekraný temizler.
	printf("Sayi eklendi\n\n");
}
void sil()
{
	int at;//Silmek istediðimiz sayý.

	if (head==NULL)//Baþlangýç NULL ise liste boþ demektir.
	{printf("\nListe bos!!!");}

	system("cls");//Ekraný temizler.
	printf("\nSilinecek sayiyi girin : ");
	scanf("%d",&at);//Kullanýcýdan silmek istediði deðer alýnýr.

	onceki=NULL;//Önceki deðerin silinecek deðerle olan baðý koparýlýr.
	temp=head;//Döngüde kullanýlacak düðüm baþlangýç olarak atanýr.

	while (temp!=NULL && temp->veri!=at)
	{
		onceki=temp;//Önceki düðümün verisini tutar.
		temp=temp->next;//Sonraki düðümün adresini tutar.
	}

	if (temp==NULL)//Arama esnasýnda geçici düðüme deðer atanmadýysa girilen sayý listede yok demektir.
	{
		printf("\nSayi listede yok");
		main();
	}

	if (onceki==NULL)//Silinen deðer ilk sýradaysa sonraki deðeri belirten adres head olarak tanýmlanýr.
	{head=temp->next;}
	else 
	{onceki->next = temp->next;}//Silinen düðümden önceki düðüm ile sonraki düðüm arasýnda bað oluþturulur.


	free(temp);//temp için ayrýlan belleði boþaltýr.
	system("cls");//Ekraný temizler.
	printf("Sayi listeden silindi\n\n");
}

void listele()
{
	int i=1;

	printf("\nLISTE : \n");

	for(ileri=head;ileri!=NULL;ileri=ileri->next)//NULL deðere ulaþana kadar döngü çalýþýr.
	{
		printf("\n%d. sayi = %d\n",i,ileri->veri);//Herhangi bir deðer bulununca sýrasýyla birlikte ekrana yazdýrýlýr.
		i++;
	}

	if (head==NULL)//Baþlangýç NULL ise liste boþ demektir.
	{
		printf("\nListe bos!!!\n");
	}

	system("pause");//Herhangi bir tuþa basýlana kadar iþlem yapýlmaz.
	system("cls");//Ekraný temizler.
}

void say()
{
	int counter=0;

	for(ileri=head;ileri!=NULL;ileri=ileri->next) //NULL deðere ulaþana kadar döngü çalýþýr.
	{counter++;}//Çalýþan her iþlem için sayacý arttýr.

	if (counter==0)//Deðer bulunamadýysa liste boþ demektir.
	{
		system("cls");//Ekraný temizler.
		printf("\nListe bos!!!\n");
	}
	else//Eleman sayýsýný göster.
	{
		system("cls");//Ekraný temizler.
		printf("\n%d tane elaman var\n\n",counter);
	}
}




