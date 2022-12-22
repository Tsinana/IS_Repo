#include <fstream>   
#include <vector>  
#include <set> 
#include <string>
#include <algorithm>

using namespace std;

char getRandomRule()
{
	if (rand() % 2 == 0)
		return 'R';
	else
		return 'W';
}

bool next_comb(std::vector<int>& LO, int n, int m);

int main()
{
	ofstream fout;
	fout.open("output.txt");

	ifstream fin;
	fin.open("input.txt");

	int n, m;
	fin >> n;
	fin >> m;
	int inp = 0;
	fin >> inp;

	fin.close();

	///матрица A[1:n; 1:m] прав доступа субъектов s1, s2, …, sn к объектам o1, o2, … , om
	vector <vector<char>> A(n, vector<char>(m));
	///LS[i] – значение уровня допуска субъекта si
	vector <int> LS(n);
	///LO[j] – значение уровня секретности объекта oj
	vector <int> LO(m);
	///компьютерная система CS = (n,m, A, LS, LO) соответствует критерию безопасности Белла – Лападулы?
	bool isSecretNornal = true;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (inp == 0)
				fin >> A[i][j];
			else
				A[i][j] = getRandomRule();
		}
	}

	fout << "\nВывод матрицы A" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			fout << A[i][j] << ' ';
		}
		fout << endl;
	}


	for (int i = 0; i < n * m; i++) {
		for (int j = 0; j < m * n; j++) {
			bool all_ok = true;

			for (int i1 = 0; i1 < n; i1++) {
				for (int j1 = 0; j1 < m; j1++) {
					//not write down                         // not read up
					if (((LS[i1] >= LO[j1] && A[i1][j1] == 'W') || (LS[i1] <= LO[j1] && A[i1][j1] == 'R'))) {
						all_ok = false;
						i1 = n;
						j1 = m;
					}
				}
			}
			if (all_ok) {
				fout << "LS: ";
				for (int i = 0; i < n; i++)
					fout << LS[i] << ' ';
				fout << endl << "LO: ";
				for (int i = 0; i < m; i++)
					fout << LO[i] << ' ';
				return 0;
			}

			if (true != next_comb(LO, n, m))
				return 0;
		}
		for (int j = 0; j < m; j++)
			LO[j] = 0;

		if (true != next_comb(LS, n, m))
			return 0;
	}
	fout << "\n-(\n";

	fout.close();
}

bool next_comb(std::vector<int>& LO, int n, int m)
{
	int j = m - 1;
	while (LO[j] == n && j >= 0)
		j--;
	if (j < 0)
		return false;
	if (LO[j] >= n)
		j--;
	LO[j]++;
	if (j == m - 1)
		return true;
	for (int k = j + 1; k < m; k++)
		LO[k] = LO[j];
	return true;
}
