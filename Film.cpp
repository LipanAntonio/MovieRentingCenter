#include "Header.h"

Film::Film(std::string Titlu) : m_Titlu(Titlu) {}
Film::~Film() {}

void Film::InchiriereFilm(Data Data1) {  // Adauga data inchirierii in vectorul
                                         // m_Date_Inchiriere daca aceasta nu
                                         // este deja.

    if (m_Date_Inchiriere.empty()) {  // Daca nu a fost inchiriat niciodata adauga
                                      // fara verificare.
        this->m_Date_Inchiriere.push_back(Data1);
        std::cout << "\n";
        this->Afisare_Titlu();
        std::cout << " a fost inchiriat in data de ";
        Data1.Afisare_Data();
        std::cout << "\n";
    }
    else if (Inchiriat_Zi(Data1)) {  // Daca nu e gol verifica daca a mai fost
                                    // inchiriat in data aleasa.
        std::cout << "\n";
        this->Afisare_Titlu();
        std::cout << " este deja inchiriat in data de ";
        Data1.Afisare_Data();
        std::cout << "\n";
    }
    else {  // Daca cele doua conditii de mai sus nu sunt implinite, adauga data
           // in vector.
        this->m_Date_Inchiriere.push_back(Data1);
        std::cout << "\n";
        this->Afisare_Titlu();
        std::cout << " a fost inchiriat in data de ";
        Data1.Afisare_Data();
        std::cout << "\n";
    }
}

void Film::Afisare_Titlu() { std::cout << this->m_Titlu; }

void Film::Afisare_Disponibilitate(
    Data Data_Disp) {  // Verifica daca data aleasa este inscrisa in vectorul
                       // m_Date_Inchiriere si afiseaza mesaj

    if (Inchiriat_Zi(Data_Disp)) {
        this->Afisare_Titlu();
        std::cout << " - Indisponibil\n";
    }
    else {
        this->Afisare_Titlu();
        std::cout << " - Disponibil\n";
    }
}

bool Film::Inchiriat_Zi(
    Data Var) {  // Verifica daca un film este inchiriat in data Var.
    if (m_Date_Inchiriere.empty()) {
        return 0;
    }
    else {
        for (unsigned int i = 0; i < m_Date_Inchiriere.size(); i++) {
            if (Var == m_Date_Inchiriere[i]) {
                return 1;
            }
        }
    }
    return 0;
}

int Film::Zile_Inchiriate() {  // Returneaza marimea vectorului
                               // m_Date_Inchiriere, reprezentand numarul de
                               // inchirieri al filmului.

    if (!m_Date_Inchiriere.empty()) {
        return m_Date_Inchiriere.size();
    }
    return 0;
}