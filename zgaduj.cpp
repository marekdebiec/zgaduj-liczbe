#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void Start ();
void GetResults ();

int  i, j, life, maxrand;
char c;


void
Start ()
{
     i = 0;
     j = 0;
     life = 0;
     maxrand = 6;

     cout << "Wybierz poziom trudosci:\n"; 
     cout << "1 : Latwy (0-15)\n";
     cout << "2 : Sredni (0-30)\n";
     cout << "3 : Trudny (0-50)\n";
     cout << "lub wpisz inny klawisz by wyjsc\n";
     c = 30;

     cin >> c;                   
     cout << "\n";

     switch (c)
     {
        case '1' : maxrand = 15;  
        break;
        case '2' : maxrand = 30;
        break;
        case '3' : maxrand = 50;
        break;
        default : exit(0);
        break;
     }

     life = 5;         
     srand( (unsigned)time( NULL ) ); 
     j = rand() % maxrand;  

     GetResults();

}


void
GetResults ()
{
     if (life <= 0)
        
     {
        cout << "Przegrales !\n\n";
        Start();
     }

     cout << "Wybierz numer: \n";
     cin >> i;          

     if ((i>maxrand) || (i<0)) 
     {
        cout << "Blad: numer nie miedzy 0 i \n" << maxrand;
        GetResults();
     }

     if (i == j)
     {
        cout << "Wygrales !\n\n"; 
        Start();
     }

     else if (i>j)
     {
        cout << "Za duzy\n";
        life = life - 1;    // -1 to the user's "life"
        cout << "Pozostalo prob: " << life << "\n\n";
        GetResults();
     }

     else if (i<j)
     {
        cout << "Za maly\n";
        life = life - 1;
        cout << "Pozostalo prob:\n" << life << "\n\n";
        GetResults();
     }
}


int
main ()
{
     cout << "** Gra Jackpot**\n";
     cout << "Celem gry jest wybrac numer. Bedziesz wpisywal\n";
     cout << "numer (masz 5 prob)\n";
     cout << "Jackpot powie ci czy numer jest za duzy\n\n";
     Start();
     return 0;
}