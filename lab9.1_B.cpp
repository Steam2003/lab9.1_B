#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h> 

using namespace std;enum Specialty { ��, ��, ��, ��, Բ };string strSpecialty[] = { "��","��","��","��","Բ" };struct Student{	string prizv;	Specialty specialty;	short unsigned kurs;	short unsigned physics;	short unsigned math;	union 	{		short unsigned programming;		short unsigned methods;		short unsigned pedagogika;	};	};void Create(Student* s, const int N);void Print(Student* s, const int N);double BestAverage(Student* s, const int N);double physics_five_four(Student* s, const int N);int main(){	SetConsoleCP(1251);	SetConsoleOutputCP(1251);	int N;	cout << "������ ������� ��������: "; cin >> N;	Student* s = new Student[N];	Create(s, N);	Print(s, N);	cout << "| ��������� ������� ���: " << fixed << setprecision(2) << BestAverage(s, N) << setw(82) << "|" << endl;	cout << "| ������� �������� �� �������� � ������ " << char(34) << "4" << char(34) << " ��� " << char(34) << "5" << char(34) << ": " << fixed << setw(6) << setprecision(2) << physics_five_four(s, N) << "%" << setw(51) << "|" << endl;	cout << "=================================================================================================================" << endl;	delete[] s;}void Create(Student* s, const int N){	int kurs, specialty;	for (int i = 0; i < N; i++)	{		cout << "������� " << i + 1 << ":" << endl;
		cin.get();
		cin.sync();
		cout << "  �������: "; getline(cin, s[i].prizv);
		cout << "  ����: "; cin >> s[i].kurs;
		cout << "  ������������ (0 - ����'����� �����, 1 - ���������� �� ��������, 2 - ������� ��������, 3 - �����������, 4 - Գ���� �� �����������): "; cin >> specialty;
		s[i].specialty = (Specialty)specialty;
		cout << "  ������ � ������: "; cin >> s[i].physics;
		cout << "  ������ � ����������: "; cin >> s[i].math;
		switch (specialty)		{		case 0:			cout << "  ������ � �������������: "; cin >> s[i].programming;			break;		case 3:			cout << "  ������ � ��������� ������: "; cin >> s[i].methods;			break;		case 1:		case 2:		case 4:			cout << "  ������ � ���������: "; cin >> s[i].pedagogika;			break;		}	}}void Print(Student* s, const int N)
{
	cout << "================================================================================================================="
		<< endl;
	cout << "| �  | �������     | ���� | ������������ | Գ���� | ���������� | ������������� | ������� ������ | ��������� |"
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