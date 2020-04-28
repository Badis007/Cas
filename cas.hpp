#ifndef CAS_HPP
#define CAS_HPP
#include <string>

class cas {
public:
    cas(); //Konstruktor bez parametrů -> nastavení v cpp
    cas(int, int, int); //Konstruktor s parametry
    cas(const cas& orig); //Kopírovací konstruktor
    virtual ~cas(); //Destruktor
    bool setCas(int, int, int); 
    std::string getCas()const;
    int casOdPulnoci()const;
    bool sekundyNaCas(int);
    int getHodiny()const; 
    int getMinuty()const;
    int getSekundy()const;
private:
    int sekundy;
    int minuty;
    int hodiny;
    void systemovyCas();
    bool platnostCasu(int, int, int)const;
};

#endif /* CAS_HPP */

