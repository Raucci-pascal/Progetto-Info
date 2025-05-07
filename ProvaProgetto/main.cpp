#include <iostream>
#include<fstream>
using namespace std;


void menu (char &scelta){


    cout<<"=======GESTIONE UNIVERSITARIA======="<<endl;

    cout<<"0. Carica dati da file"<<endl;
    cout<<"1. Cerca dei corsi di uno studente ((matricola))"<<endl;
    cout<<"2. Carica dati da file (cognome)"<<endl;
    cout<<"3. Elenca studenti iscritti ad un corso"<<endl;
    cout<<"4. Stampa dati esami di un corso"<<endl;
    cout<<"5. Numero di srudenti per corso"<<endl;
    cout<<"6. Numero di materie per corso"<<endl;
    cout<<"7. Cerca materie per descrizione"<<endl;
    cout<<"8. Inserisci nuovo studente"<<endl;
    cout<<"9. Salva i dati sul file"<<endl;
    cout<<"X. Esci"<<endl;


    cin>>scelta;

}


int main()
{
   char scelta;


   menu(scelta);


   while(scelta != 'X'){


        switch(scelta){

            case 0:






        }



   }



}
