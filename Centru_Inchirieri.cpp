#include "Header.h"

Centru_Inchirieri::Centru_Inchirieri() {  // Prealocarea pentru a evita
                                          // realocarea la adaugarea filmelor.
    m_Lista_Filme.reserve(20);
};
Centru_Inchirieri::~Centru_Inchirieri() {};

void Centru_Inchirieri::Listare_Filme() {  // Afisarea listei filmelor din
                                           // vectorul m_Lista_Filme.
    for (unsigned int i = 0; i < m_Lista_Filme.size(); i++) {
        if (i < 9) {
            std::cout << "0";
        }
        std::cout << i + 1 << ".";
        m_Lista_Filme[i].Afisare_Titlu();
        std::cout << "\n";
    }
};

void Centru_Inchirieri::Adaugare_Film(
    Film var) {  // Adaugare film in vectorul m_Lista_Filme.
    this->m_Lista_Filme.push_back(var);
}

int Centru_Inchirieri::Inchiriate_Centru_Zi(
    Data Var_Data) {  // Afiseaza numarul de filme inchiriate intr-o anumita zi.
    int rezultat = 0;

    for (unsigned int i = 0; i < m_Lista_Filme.size(); i++) {
        if (m_Lista_Filme[i].Inchiriat_Zi(Var_Data)) {
            rezultat++;
        }
    }
    return rezultat;
}

int Centru_Inchirieri::Inchiriate_Centru_Total() {  // Afiseaza numarul de filme
                                                    // inchiriate in total de-a
                                                    // lungul timpului.
    int rezultat = 0;
    for (unsigned int i = 0; i < m_Lista_Filme.size(); i++) {
        rezultat += m_Lista_Filme[i].Zile_Inchiriate();
    }
    return rezultat;
}

int Centru_Inchirieri::Marime_Lista_Filme() {  // Returneaza numarul filmelor.
    if (!m_Lista_Filme.empty()) {
        return m_Lista_Filme.size();
    }
    return 0;
}

Film* Centru_Inchirieri::ListaFilme_IndexGetter(
    int Index) {  // Returneaza pointer la un film de pe pozitia Index.
    return &m_Lista_Filme[Index];
}

void Centru_Inchirieri::Listare_Filme_Disponibile(
    Data Data_Disp) {  // Listeaza disponibilitatea tuturor filmelor la data
                       // Data_Disp.
    for (unsigned int i = 0; i < m_Lista_Filme.size(); i++) {
        m_Lista_Filme[i].Afisare_Disponibilitate(Data_Disp);
    }
}
