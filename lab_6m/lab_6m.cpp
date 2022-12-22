#include <iostream>   
#include <fstream> 
#include <vector>  
#include <string>

using namespace std;

char getRandomRule()
{
	if (rand() % 2 == 0)
		return 'R';
	else
		return 'W';
}


int main()
{
	ofstream fout;
	fout.open("output.txt");

	ifstream fin;
	fin.open("input.txt");

	setlocale(LC_ALL, "RUS");
	int n, m;
	fin >> n;
	fin >> m;
	int inp = 0;
	fin >> inp;

	///матрица A[1:n; 1:m] прав доступа субъектов s1, s2, …, sn к объектам o1, o2, … , om
	vector <vector<char>> A(n, vector<char>(m));
	///LS[i] – значение уровня допуска субъекта si
	vector <int> LS(n);
	///LO[j] – значение уровня секретности объекта oj
	vector <int> LO(m);
	///компьютерная система CS = (n,m, A, LS, LO) соответствует критерию безопасности Белла – Лападулы?
	bool isSecretNornal = true;

	//заполнение матрицы
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (inp == 0)
				fin >> A[i][j];
			else
				A[i][j] = getRandomRule();
		}
	}
	fin.close();
	fout << "\nВывод матрицы A" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			fout << A[i][j] << ' ';
		}
		fout << endl;
	}

	fout << "\nLS" << endl;
	for (int i = 0; i < n; i++) {
		if (inp == 0)
			fin >> LS[i];
		else
			LS[i] = rand() % 3 + 1;
		fout << LS[i] << " ";
	}
	fout << endl;

	fout << "\nLO" << endl;
	for (int i = 0; i < m; i++) {
		if (inp == 0)
			fin >> LO[i];
		else
			LO[i] = rand() % 3 + 1;
		fout << LO[i] << " ";
	}
	fout << endl;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			//not write down                         // not read up
			if (((LS[i] > LO[j] && A[i][j] == 'W') || (LS[i] < LO[j] && A[i][j] == 'R'))) {
				isSecretNornal = false;
			}
		}
	}

	fout << "\nКритерию безопасности Белла - Лападулы";
	if (isSecretNornal)
		fout << " есть" << endl;
	else
		fout << " нет" << endl;
	fout.close();
}