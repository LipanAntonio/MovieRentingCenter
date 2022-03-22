#include "Header.h"
std::ifstream Lista_Filme("Lista_Filme.txt");

int main() {
    Centru_Inchirieri Centru = Centru_Inchirieri();
    bool Semafor = 1;
    std::string Titlu_Film;

    while (std::getline(Lista_Filme, Titlu_Film)) {  // Realizarea citirii
                                                     // filmelor din fisierul de
                                                     // intrare Lista_Filme.txt
        Film z(Titlu_Film);
        Centru.Adaugare_Film(z);
    }

    while (Semafor) {  // Meniul prin care se apeleaza functionalitatile
                       // sistemului de gestionare
        int x;
        std::cout << "\nAlegeti dintre una din optiunile de mai jos:\n";
        std::cout << "1.Verificare disponibilitate filme.\n";
        std::cout << "2.Inchiriere film.\n";
        std::cout << "3.Numarul de zile in care a fost inchiriat un film.\n";
        std::cout
            << "4.Numarul filmelor inchiriate la nivel de centru intr-o zi.\n";
        std::cout << "5.Numarul total de inchirieri.\n";
        std::cout << "6.Finalizarea utilizarii.\n";
        std::cin >> x;

        switch (x) {
        case 1: {
            system("CLS");

            Data Data_Disponibilitate = Data();
            Centru.Listare_Filme_Disponibile(Data_Disponibilitate);
            break;
        }
        case 2: {
            system("CLS");

            std::cout << "Alegeti unul dintre urmatoarele filme:\n";
            Centru.Listare_Filme();

            int Index;
            do {
                std::cout << "\nIntroduceti o valoare intre 1 si "
                    << Centru.Marime_Lista_Filme() << "\n";
                std::cin >> Index;
            } while ((Index < 1) || (Index > Centru.Marime_Lista_Filme()));
            Index--;

            system("CLS");

            Data Data_Inchiriere = Data();

            Centru.ListaFilme_IndexGetter(Index)->InchiriereFilm(Data_Inchiriere);
            break;
        }

        case 3: {
            system("CLS");
            std::cout << "Alegeti unul dintre urmatoarele filme:\n";
            Centru.Listare_Filme();
            std::cout << "Introduceti o valoare intre 1 si "
                << Centru.Marime_Lista_Filme();
            std::cout << "\n";

            int Index;
            do {
                std::cin >> Index;
            } while ((Index < 1) || (Index > Centru.Marime_Lista_Filme()));
            Index--;

            std::cout << "\nFilmul ales a fost inchiriat pentru ";
            std::cout << Centru.ListaFilme_IndexGetter(Index)->Zile_Inchiriate();
            std::cout << " zile.\n";
            break;
        }
        case 4: {
            system("CLS");

            Data Data_Verificare = Data();

            std::cout << "\nIn data aleasa sunt inchiriate ";
            std::cout << Centru.Inchiriate_Centru_Zi(Data_Verificare);
            std::cout << " filme";
            std::cout << "\n";
            break;
        }
        case 5: {
            system("CLS");
            std::cout << "\nPana in prezent au fost efectuate ";
            std::cout << Centru.Inchiriate_Centru_Total();
            std::cout << " inchirieri.\n";
            break;
        }
        case 6: {
            Semafor = 0;
            break;
        }
        default: {
            system("CLS");
            std::cout << "Alegeti o optiune VALIDA!\n";
            break;
        }
        }
    }

    return 0;
}
