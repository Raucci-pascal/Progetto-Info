#include <iostream>
#include<fstream>
#include<vector>

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



struct studente{

    string codice;
    string descrizione;
    string cod_materia;
    string data_materia;
    string matricola;
    string cognome;
    string nome;


};

void inputVector(vector<studente> &s){

    studente x;

    ifstream fin("corsi_studenti.csv");

    string labels;
    getline(fin,labels); //lettura etichette


    while(!fin.eof()){

        getline(fin,x.codice,',');
        getline(fin,x.descrizione,',');
        getline(fin,x.cod_materia,',');
        getline(fin,x.data_materia,',');
        getline(fin,x.matricola,',');
        getline(fin,x.cognome,',');
        getline(fin,x.nome,',');

        s.push_back(x);


    }

    fin.close();




}


int main()
{

    char scelta;


    vector<studente> s;

    menu(scelta);


    while(scelta != 'X'){


        switch(scelta){

            case '0':

                inputVector(s);

        }



   }



}
