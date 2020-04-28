#include <cstdlib>
#include <iostream>
#include "cas.hpp"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int h;
    int m;
    int s;
    cas c1; //Konstruktor bez parametrů -> systémový čas nastaven v cpp
    cas c2(0,0,0); //Konstruktor s parametry
    cas c3;
    cas c4(c1);//
    cout<<"objekt vytvoreny vychozim konstruktorem: "<<c1.getCas()<<endl; 
    cout<<"pocet sekund od pulnoci: "<<c1.casOdPulnoci()<<endl;
    cout<<"objekt vytvoreny se zadanym parametrem: "<<c2.getCas()<<endl;
    cout<<"pocet sekund od pulnoci: "<<c2.casOdPulnoci()<<endl;
    cout<<"Objekt vytvoren kopirovacim konstruktorem: "<<c4.getCas()<<endl;
    do{
        cout<<"Zadejte hodiny: ";
        cin>>h;
        cout<<"Zadejte minuty: ";
        cin>>m;
        cout<<"Zadejte sekundy: ";
        cin>>s;
        if(c3.setCas(h,m,s)){
            cout<<"Cas po zmene: "<<c3.getCas()<<endl;
            cout<<"pocet sekund od pulnoci: "<<c3.casOdPulnoci()<<endl;
        }
        else
            cout<<"chybne zadany cas"<<endl;
        cout<<"zadejte pocet sekund: ";
        cin>>s;
        if(c3.sekundyNaCas(s))
            cout<<"Cas po zmene: "<<c3.getCas()<<endl;
        else
            cout<<"chybny pocet sekund"<<endl;
    }while(true);
    return 0;
}

