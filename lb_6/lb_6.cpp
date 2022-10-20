#include <iostream>
#include <fstream>
#include <list>
#include <string>
using namespace std;

bool IsSafe(int, int, char*, int*, int*);
bool NextComboRepeat(int*, int, int);


void Generating_all_combinations_with_repetitions(int k, int N) {
	list<int> list_st;
	int* set = new int[N];
	for (int i = 0; i < N; i++) 
		set[i] = i + 1;
	
	int index = 0;
	Generating_all_combinations_with_repetitions(0, 0, list_st, N, k, index, set);
}

void Generating_all_combinations_with_repetitions(int num, int last, list<int> list_st, int N, int k, int &index, int* set) {
	int x;
	if (num == k) {
		string str_int = "";

		for (int j : list_st)
			str_int += j;
		x = stoi(str_int);
	} else
		for (int i = last; i < N; i++) {
			list_st.push_back(set[i]);
			Generating_all_combinations_with_repetitions(num + 1, i, list_st, N, k, index, set);
			list_st.pop_back();
		}
}



int main() {
	ifstream in();//
	int n, m;
	in >> n >> m;

	int* LS = new int[n];
	int* LO = new int[m];
	char** A = new char* [n];
	for (int i = 0; i < n; i++)
		A[i] = new char[m];

	for (int i = 0; i < n; i++) {
		int a; 
		in >> a;
		LS[i] = a;
	}
	for (int i = 0; i < m; i++) {
		int a;
		in >> a;
		LO[i] = a;
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			char a;
			in >> a;
			A[i][j] = a;
		}
	in.close();
	
	if (IsSafe(n, m, reinterpret_cast<char*>(A), LS, LO))
		cout << "1";
	else
		cout << "0";

	delete[] LS;
	delete[] LO;
	for (int i = 0; i < n; i++)
		delete[] A[i];
	delete[] A;
}

bool IsSafe(int n, int m, char* A, int* LS, int* LO) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if ((A[i * m + j] == 'r' && LS[i] < LO[j]) ||
				(A[i * m + j] == 'w' && LS[i] >= LO[j]))
				return false;				

	return true;
}

bool NextComboRepeat(int* a, int n, int m) {
	for (int i = m - 1; i >= 0; --i)
		if (a[i] < n)
		{
			++a[i];
			for (int j = i + 1; j < m; ++j)
				a[j] = a[j - 1];
			return true;
		}
	return false;
}
