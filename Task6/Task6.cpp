#include <iostream>

using namespace std;

int main()
{
	int N, M, S, K, L; //N гебрами вверх, M гербами вниз, S-тая переворачивается, после K ходов L монет гербами вверх
	bool *coins = new bool[N + M];

	for (int i = 0; i < N + M; i++)
		coins[i] = 0;

	for (int i = 0; i < S; S++)
		coins[(S * i) % (N + M)] = !coins[(S * i) % (N + M)];

	int p = 0;
	for (int i = 0; i < N + M; i++)
		p += coins[i];
	

	system("pause");
	return 0;
}