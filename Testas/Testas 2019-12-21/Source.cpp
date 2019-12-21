#include <fstream>
#include <iostream>

using namespace std;

const char FV[] = "Tekstas.txt";
const char FD[] = "Rezultatai.txt";

int specialsymbol(ifstream& get)
{
	int kiek = 0, n = 0;
	char A[256];
	for (n = 0; 1; n++)
	{
		get.get(A[n]);

		if (A[n] == '\n' || A[n] == '\r')
		{
			break;
		}
	}


	for (int i = 0; i < n; i++)
	{
		if (A[i] == ',')
		{
			kiek++;
		}
		if (A[i] == ' ')
		{
			kiek++;
		}
		if (A[i] == '.')
		{
			kiek++;
		}
	}
	return kiek;
}

void spausdinimas(int eiluteje, int eilute, ofstream& print, int daugiausiaEiluteje)
{
	print << "Eilutes Nr. : " << eilute << " , joje skyrikliu: " << eiluteje << endl;
}


void veiksmas(ifstream& get, int& eiluteje, int& eilute, int& daugiausia, int& daugiausiaEiluteje, ofstream& print)
{
	int kiek = 0;
	while (!get.eof())
	{
		eilute++;
		kiek = specialsymbol(get);
		eiluteje = kiek;
		spausdinimas(eiluteje, eilute, print, daugiausiaEiluteje);
		if (kiek > daugiausia)
		{
			daugiausia = kiek;
			daugiausiaEiluteje = eilute;
		}
	}
}

int main()
{
	int eiluteje, eilute = 0, daugiausia = 0, daugiausiaEiluteje;
	ifstream get(FV);
	ofstream print(FD);
	veiksmas(get, eiluteje, eilute, daugiausia, daugiausiaEiluteje, print);
	print << "Eilutes Nr., kurioje daugiausia skyrikliu: " << daugiausiaEiluteje << endl;
	system("pause");
	return 0;
}