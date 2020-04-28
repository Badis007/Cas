#include "cas.hpp"
#include <ctime>

cas::cas() { //cas c1
   systemovyCas(); 
}
cas::cas(int hodiny, int minuty, int sekundy){ //Zadání hodnot v mainu "na tvrdo" cas c2
    if(platnostCasu(hodiny, minuty, sekundy)){
        this->hodiny=hodiny;
        this->minuty=minuty;
        this->sekundy=sekundy;
    }
    else{
        systemovyCas();
    }
}

cas::cas(const cas& orig) { //Kopírovací konstruktor
     this->hodiny = orig.getHodiny();
     this->minuty = orig.getMinuty();
     this->sekundy = orig.getSekundy();
}



cas::~cas() {
}
 
 
 //Jebky pro kopírovací konstruktor
int cas::getHodiny()const{
    return this->hodiny;
}

int cas::getMinuty()const{
    return this->minuty;
}

int cas::getSekundy()const{
    return this->sekundy;
}

void cas::systemovyCas(){ //local_time na referencích
  time_t rawtime;
  struct tm * timeinfo;
  time ( &rawtime );
  timeinfo = localtime ( &rawtime );
  this->hodiny = timeinfo ->tm_hour; //uložení hodin,minut,sekund do proměnných
  this->minuty = timeinfo ->tm_min;
  this->sekundy = timeinfo ->tm_sec;
  return;
}

std::string cas::getCas() const{ //
    std::string cas="";
    cas+=this->hodiny<10 ? "0" : ""; //Když je hodina menší než 10, musí se přídat 0 např "09"
    cas+=std::to_string(this->hodiny); //Přičtení hodiny do stringu "09"
    cas+=":"; //přidání znaku do stringu za hodinu např "09:""
    cas+=this->minuty<10 ? "0" : ""; //To stejné s minutou a sekundou
    cas+=std::to_string(this->minuty);
    cas+=":";
    cas+=this->sekundy<10 ? "0" : "";
    cas+=std::to_string(this->sekundy);
    return cas; //funkce vrátí string v podobě např "09:10:32"
}

bool cas::platnostCasu(int hodiny, int minuty, int sekundy) const{ //Fuknce pro ověření platnosti času
    if(hodiny<0 || hodiny>23) //Když jsou hodiny menší než 0 nebo 23 vrátí false
        return false;
    if(minuty<0 || minuty>59)
        return false;
    if(sekundy<0 || sekundy>59)
        return false;
    return true; //Když čas splní všechny podmínky vrátí true, při porušení jedné z nich vrátí false
}

bool cas::setCas(int hodiny, int minuty, int sekundy){ //Zadané hodnoty uživatelem
        if(platnostCasu(hodiny, minuty, sekundy)){
        this->hodiny=hodiny;
        this->minuty=minuty;
        this->sekundy=sekundy;
        return true;
        }
        else{
            return false;
        }
}

int cas::casOdPulnoci() const{ //Zadané hodiny od půlnoci převede na sekundy
    return this->hodiny*3600+this->minuty*60+this->sekundy;
}

bool cas::sekundyNaCas(int sekundy){ //Převedení sekund na platný čas
    if(sekundy>86399 || sekundy<0) //Když zadá sekundy přesahující jeden den nebo záporné vrátí false
        return false;
    this->hodiny = sekundy/3600; 
    this->minuty = (sekundy-hodiny*3600)/60; 
    this->sekundy = sekundy%60; 
    return true;
}
