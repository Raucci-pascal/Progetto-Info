#include <iostream>
#include<fstream>
#include<vector>
#include<map>

using namespace std;


void menu (char &scelta){


    cout<<"=======GESTIONE UNIVERSITARIA======="<<endl;

    cout<<"0. Carica dati da file"<<endl;
    cout<<"1. Cerca dei corsi di uno studente (matricola)"<<endl;
    cout<<"2. Cerca dei corsi di uno studente (cognome)"<<endl;
    cout<<"3. Elenca studenti iscritti ad un corso"<<endl;
    cout<<"4. Stampa dati esami di un corso"<<endl;
    cout<<"5. Numero di studenti per corso"<<endl;
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
    string descr_materia;
    string matricola;
    string cognome;
    string nome;


};


struct s_nome{

    string nome;
    string cognome;

};

void caricamentoMappe(map<string,vector<string>> &matr,map<string,vector<string>> &cogno, map<string, vector<s_nome>> &name){

    ifstream fin("corsi_studenti.csv");

    string labels;
    getline(fin,labels); //lettura etichette


    while(!fin.eof()){
        studente x;
        getline(fin,x.codice,',');
        getline(fin,x.descrizione,',');
        getline(fin,x.cod_materia,',');
        getline(fin,x.descr_materia,',');
        getline(fin,x.matricola,',');
        getline(fin,x.cognome,',');
        getline(fin,x.nome);

        matr[x.matricola].push_back(x.codice);
        cogno[x.cognome].push_back(x.codice);

        s_nome y;

        y.nome = x.nome;
        y.cognome = x.cognome;

        vector<s_nome> tmp = name[x.codice];

        //ctmp.size()

        name[x.codice].push_back(y);


    }

    fin.close();




}


int main()
{

    char scelta;


    map<string,vector<string>>s;

    map<string,vector<string>> stud;

    map<string, vector<s_nome>>name;

    string matricola;

    menu(scelta);


    while(scelta != 'X' or 'x'){


        switch(scelta){

            case '0':

                caricamentoMappe(s,stud,name);

                break;

            case '1':

                cout<<"Inserisci la matricola"<<endl;
                cin>>matricola;

                cout<<s[matricola][0]<<endl;

                break;

            case '2':{

                string surname;

                cout<<"Cognome:"<<endl;
                cin>>surname;

                cout<<stud[surname][0]<<endl;

                break;
            }

            case '3':{

                string cors;

                cout<<"Corso:"<<endl;
                cin>>cors;

                for(auto elem : name[cors]){

                    cout<<elem.nome<<" "<<elem.cognome<<endl;

                }

                break;
            }
        }





        menu(scelta);

   }



}
