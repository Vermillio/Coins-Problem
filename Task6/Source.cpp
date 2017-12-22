//In a circle, N coins are placed with coats of arms and M coins with coats of arms down. 
//Going round in a clockwise direction, each S-th coin is inverted. For the first time the account begins with the coat of arms. 
//In what order should the coins be placed, so that after the K moves there are L coins, which are to be put upwards.


#include <iostream>
#include <cmath>

using namespace std;

struct coin
{
	bool swap;
	bool is_emb;
	coin() : swap(0), is_emb(0) {};
};

int main()
{
	int N, M, S, K, L;

	cout << "Enter N" << endl;
	cin >> N;
	cout << "Enter M" << endl;
	cin >> M;
	cout << "Enter S" << endl;
	cin >> S;
	cout << "Enter K" << endl;
	cin >> K;
	cout << "Enter L" << endl;
	cin >> L;
	cout << endl;

	coin *coins = new coin[N + M];

	for (int i = 0; i < K; i++)
	{
		coins[i*S % (N + M)].swap = 1 - coins[i*S % (N + M)].swap;
	}
	int p = 0;

	for (int i = 0; i < N + M; i++)
		p += coins[i].swap;

	if (p < abs(L - N) || (p - abs(L - N)) % 2 == 1 || (p - abs(L - N))/2 > N || ((p - abs(L - N)) / 2 + L - N > M && (p - abs(L-N)/2 - L + N < M)))
	{
		cout << "Impossible." << endl;
		system("pause");
		return 0;
	}
	


	int diff, rest_e, rest_ne;

	diff = abs(L - N);
	rest_e = rest_ne = (p - diff) / 2;
	int N1 = N - rest_e, M1 = M - rest_ne;

	coins[0].is_emb = 1;
	if (N > L)
		diff--;
	else rest_e--;

	int i = 1;
	while (i < N + M)
	{
		if (coins[i].swap)
		{
			if (diff)
			{
				diff--;
				coins[i].is_emb = N > L;
			}
			else if (rest_e)
			{
				rest_e--;
				coins[i].is_emb = 1;
			}
			else if (rest_ne)
			{
				rest_ne--;
				coins[i].is_emb = 0;
			}
		}
		else
		{
			if (N1)
			{
				N1--;
				coins[i].is_emb = 1;
			}
			else if (M1)
			{
				M1--;
				coins[i].is_emb = 0;
			}
			else {
				cout << "error" << endl;
				system("pause");
				return 0;
			}
		}
		++i;
	}
	for (int i = 0; i < N + M; i++)
	{
		cout << coins[i].is_emb << endl;
	}

	system("pause");
	return 0;
}