#ifndef Film_HEADER
#define Film_HEADER

class Film {
private:
	std::string m_Titlu;
	std::vector<class Data> m_Date_Inchiriere;

public:
	Film(std::string Titlu);

	~Film();

	void InchiriereFilm(class Data Data1);

	void Afisare_Titlu();

	void Afisare_Disponibilitate(class Data Data_Disp);

	bool Inchiriat_Zi(class Data Var);

	int Zile_Inchiriate();
};

#endif