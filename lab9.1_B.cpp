#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h> 

using namespace std;enum Specialty { КН, МЕ, ТН, ІФ, ФІ };string strSpecialty[] = { "КН","МЕ","ТН","ІФ","ФІ" };struct Student{	string prizv;	Specialty specialty;	short unsigned kurs;	short unsigned physics;	short unsigned math;	union 	{		short unsigned programming;		short unsigned methods;		short unsigned pedagogika;	};	};void Create(Student* s, const int N);void Print(Student* s, const int N);double BestAverage(Student* s, const int N);double physics_five_four(Student* s, const int N);int main(){	SetConsoleCP(1251);	SetConsoleOutputCP(1251);	int N;	cout << "Введіть кількість студентів: "; cin >> N;	Student* s = new Student[N];	Create(s, N);	Print(s, N);	cout << "| Найбільший середній бал: " << fixed << setprecision(2) << BestAverage(s, N) << setw(82) << "|" << endl;	cout << "| Процент студентів які отримали з фізики " << char(34) << "4" << char(34) << " або " << char(34) << "5" << char(34) << ": " << fixed << setw(6) << setprecision(2) << physics_five_four(s, N) << "%" << setw(51) << "|" << endl;	cout << "=================================================================================================================" << endl;	delete[] s;}void Create(Student* s, const int N){	int kurs, specialty;	for (int i = 0; i < N; i++)	{		cout << "Студент№ " << i + 1 << ":" << endl;
		cin.get();
		cin.sync();
		cout << "  прізвище: "; getline(cin, s[i].prizv);
		cout << "  курс: "; cin >> s[i].kurs;
		cout << "  спеціальність (0 - Комп'ютерні науки, 1 - Математика та економіка, 2 - Трудове навчання, 3 - Інформатика, 4 - Фізика та інформатика): "; cin >> specialty;
		s[i].specialty = (Specialty)specialty;
		cout << "  оцінка з фізики: "; cin >> s[i].physics;
		cout << "  оцінка з математики: "; cin >> s[i].math;
		switch (specialty)		{		case 0:			cout << "  оцінка з програмування: "; cin >> s[i].programming;			break;		case 3:			cout << "  оцінка з чисельних методів: "; cin >> s[i].methods;			break;		case 1:		case 2:		case 4:			cout << "  оцінка з педагогіки: "; cin >> s[i].pedagogika;			break;		}	}}void Print(Student* s, const int N)
{
	cout << "================================================================================================================="
		<< endl;
	cout << "| №  | Прізвище     | Курс | Спеціальність | Фізика | Математика | Програмування | Чисельні методи | Педагогіка |"
		<< endl;
	cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < N; i++)
	{
		cout << "| " << setw(2) << right << i + 1 << " "
			<< "| " << setw(13) << left << s[i].prizv
			<< "| " << setw(3) << right << s[i].kurs << "  "
			<< "| " << setw(8) << right << strSpecialty[s[i].specialty] << "      "
			<< "| " << setw(4) << right << s[i].physics << "   "
			<< "| " << setw(6) << right << s[i].math << "     ";
			switch (s[i].specialty)
			{			case 0:				cout << "| " << setw(7) << right << s[i].programming << "       |" << setw(18) << "|" << setw(13) << "|" << endl;				break;			case 3:				cout << "| " << setw(15) << "|" << setw(10) << right << s[i].methods << "       |" << setw(13) << "|" << endl;				break;			case 1:			case 2:			case 4:				cout << "| " << setw(15) << "|" << setw(18) << "|" << right << setw(7) << s[i].pedagogika << "     |" << endl;				break;			}			cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
	}
	cout << "=================================================================================================================" << endl;
}double BestAverage(Student* s, const int N){	double best = 0;	double tmp;	for (int i = 0; i < N; i++)	{		switch (s[i].specialty)		{		case 0:			tmp = (s[i].physics + s[i].math + s[i].programming) / 3.;			break;		case 3:			tmp = (s[i].physics + s[i].math + s[i].methods) / 3.;			break;		case 1:		case 2:		case 4:			tmp = (s[i].physics + s[i].math + s[i].pedagogika) / 3.;			break;		}		if (tmp > best)			best = tmp;	}	return best;}double physics_five_four(Student* s, const int N){	int k = 0;	for (int i = 0; i < N; i++)		if (s[i].physics == 4 || s[i].physics == 5)			k++;	return 100.0 * k / N;}