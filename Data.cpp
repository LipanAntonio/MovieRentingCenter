#include "Header.h"

Data::Data() {
    int Ziua, Luna, An;
    std::cout << "Introduceti data dorita.";
    std::cout << "\nZiua:";
    std::cin >> Ziua;
    std::cout << "\nLuna:";
    std::cin >> Luna;
    std::cout << "\nAnul:";
    std::cin >> An;
    this->Ziua = Ziua;
    this->Luna = Luna;
    this->An = An;
}
Data::~Data() {}

void Data::Afisare_Data() {
    std::cout << this->Ziua << "." << this->Luna << "." << this->An;
}

bool Data::operator==(Data Argument) {
    if ((Argument.Ziua == this->Ziua) && (Argument.Luna == this->Luna) &&
        (Argument.An == this->An)) {
        return 1;
    }
    return 0;
}
