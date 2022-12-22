#include <iostream>   
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
	setlocale(LC_ALL, "RUS");
	int n, m;
	cout << "Введите число субъектов" << endl;
	cin >> n;
	cout << "Введите число объектов" << endl;
	cin >> m;
	cout << "Введите 0 для ручного ввода" << endl;
	int inp = 0;
	cin >> inp;

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
				cin >> A[i][j];
			else
				A[i][j] = getRandomRule();
		}
	}

	cout << "\nВывод матрицы A" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << A[i][j] << ' ';
		}
		cout << endl;
	}

	cout << "\nLS" << endl;
	for (int i = 0; i < n; i++) {
		if (inp == 0)
			cin >> LS[i];
		else
			LS[i] = rand() % 3 + 1;
		cout << LS[i] << " ";
	}
	cout << endl;

	cout << "\nLO" << endl;
	for (int i = 0; i < m; i++) {
		if (inp == 0)
			cin >> LO[i];
		else
			LO[i] = rand() % 3 + 1;
		cout << LO[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			//not write down                         // not read up
			if (((LS[i] > LO[j] && A[i][j] == 'W') || (LS[i] < LO[j] && A[i][j] == 'R'))) {
				isSecretNornal = false;
			}
		}
	}

	cout << "\nКритерию безопасности Белла - Лападулы";
	if (isSecretNornal)
		cout << " есть" << endl;
	else
		cout << " нет" << endl;
}