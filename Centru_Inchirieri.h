#ifndef Centru_Inchirieri_HEADER
#define Centru_Inchirieri_HEADER

class Centru_Inchirieri {
private:
	std::vector<class Film> m_Lista_Filme;

public:
	Centru_Inchirieri();
	~Centru_Inchirieri();

	void Listare_Filme();

	void Adaugare_Film(class Film var);

	int Inchiriate_Centru_Zi(class Data Var_Data);

	int Inchiriate_Centru_Total();

	int Marime_Lista_Filme();

	class Film* ListaFilme_IndexGetter(int Index);

	void Listare_Filme_Disponibile(class Data Data_Disp);
};

#endif