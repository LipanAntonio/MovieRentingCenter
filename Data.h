#ifndef Data_HEADER
#define Data_HEADER

class Data {
private:
	int Ziua;
	int Luna;
	int An;

public:
	Data();
	~Data();

	void Afisare_Data();

	bool operator==(Data Argument);
};

#endif