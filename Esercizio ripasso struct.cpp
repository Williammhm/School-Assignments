#include <iostream>
using namespace std;

struct giocatore{
    string nome;
    string ruolo;
    int golSegnati;
};

void inserimento(int nrG, giocatore arr[]);

void stampa(int nrG, giocatore arr[]);

void ordinamentoGol(int nrG, giocatore arr[]);

void ricercaNome(int nrG, giocatore arr[]);

void ordinamentoRuolo(int nrG, giocatore arr[]);

int main(){
    int nrG; //numero giocatori
    cout<<"Inserire il numero di giocatori\n";
    cin>>nrG;
    cout<<"\n";
    while(nrG>50){
        cout<<"Invalido, inserire un valore minore o uguale a 50\n\n";

        cout<<"Inserire il numero di giocatori\n";
        cin>>nrG;
        cout<<"\n";
    }
    cout<<"\n";

    giocatore arr[nrG];

    int scelta = 0;
    while(scelta!=6){
        cout<<"Menu\n";
        cout<<"1 | Inserimento giocatori\n";
        cout<<"2 | Stampa della squadra\n";
        cout<<"3 | Ordinamento per gol segnati\n";
        cout<<"4 | Ricerca per nome\n";
        cout<<"5 | Ordinamento per ruolo\n";
        cout<<"6 | Esci dal programma\n";
        cout<<"Immetti un valore:\n";
        cin>>scelta;
        cout<<"\n";

        switch(scelta){
            case 1:
                inserimento(nrG, arr);
                break;
                
            case 2:
                stampa(nrG, arr);
                break;

            case 3:
                ordinamentoGol(nrG, arr);
                break;

            case 4:
                ricercaNome(nrG, arr);
                break;
            
            case 5:
                ordinamentoRuolo(nrG, arr);
                break;
        }
    }
}

void inserimento(int nrG, giocatore arr[]){
    for(int i= 0; i<nrG; i++){
        cout<<"|Inserire il nome del giocatore["<<i+1<<"]\n";
        cin>>arr[i].nome;
        cout<<"|Inserire il ruolo del giocatore["<<i+1<<"]\n";
        cout<<"1 = Portiere | 2 = Difensore | 3 = Centrocampista | 4 = Attaccante\n";
        int sceltaRuolo = 0;
        cin>>sceltaRuolo;

        bool continua=true;

        while(continua==true){
            if(sceltaRuolo == 1){
                arr[i].ruolo = "Portiere";
                continua=false;
            }
            else if(sceltaRuolo == 2){
                arr[i].ruolo = "Difensore";
                continua=false;
            }

            else if(sceltaRuolo == 3){
                arr[i].ruolo = "Centrocampista";
                continua=false;
            }

            else if(sceltaRuolo == 4){
                arr[i].ruolo = "Attaccante";
                continua=false;
             }

            else{
                cout<<"Immettere una scelta valida\n";
                cout<<"1 = Portiere | 2 = Difensore | 3 = Centrocampista | 4 = Attaccante\n";
                cin>>sceltaRuolo;
                continua=true;
            }
        }


        cout<<"|Inserire il numero di goal segnati del giocatore["<<i+1<<"]\n";
        cin>>arr[i].golSegnati;
        while(arr[i].golSegnati < 0){
            cout<<"Valore non valido Inserire un numero >= 0: ";
            cin>>arr[i].golSegnati;
        }
        cout<<"\n";
        }
}

void stampa(int nrG, giocatore arr[]){
    for(int i=0; i<nrG; i++){
        cout<<"|Nome Giocatore["<<i+1<<"] = "<<arr[i].nome<<"\n";
        cout<<"|Ruolo Giocatore["<<i+1<<"] = "<<arr[i].ruolo<<"\n";
        cout<<"|Numero Gol Giocatore["<<i+1<<"] = "<<arr[i].golSegnati<<"\n";
        cout<<"\n";
    }
}
            

void ordinamentoGol(int nrG, giocatore arr[]){
    for (int i=0; i<nrG-1; i++){
        for(int j=0; j<nrG-i-1; j++){
            if(arr[j].golSegnati>arr[j+1].golSegnati){
                giocatore temp;
                temp = arr[j];
                arr[j]= arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void ricercaNome(int nrG, giocatore arr[]){
    string sceltaNome;
    cout<<"Inserire il nome che vuoi cercare nel registro";
    cin>>sceltaNome;
    bool trovato = false;

    for(int i=0; i<nrG; i++){
        if (sceltaNome == arr[i].nome){
            cout<<"Nome del giocatore trovato nella "<<i+1<<" posizione dell'array\n\n";
            trovato = true;
        }
    }

    if(trovato==false){
        cout<<"Il nome non e stato trovato nel registro";
    }   
}

void ordinamentoRuolo(int nrG, giocatore arr[]){
    for (int i=0; i<nrG-1; i++){
            for(int j=0; j<nrG-i-1; j++){
                if(arr[j].ruolo>arr[j+1].ruolo){
                    giocatore temp;
                    temp = arr[j];
                    arr[j]= arr[j+1];
                    arr[j+1] = temp;
                }
            }
        }
}