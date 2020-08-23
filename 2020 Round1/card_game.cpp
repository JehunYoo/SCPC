#include <iostream>
#include <algorithm>
#define MAXLEN 3001
using namespace std;

int Answer1, Answer2;
int X[MAXLEN], Y[MAXLEN], state[MAXLEN][MAXLEN];
int N, K;

int checkState(int x, int y);

int main(int argc, char** argv)
{
	int T, test_case;

	scanf("%d", &T);
	for(test_case = 0; test_case < T; test_case++)
	{
		Answer1 = 0;
		Answer2 = 0;

		scanf("%d %d", &N, &K);
		for(int i=1; i<=N; i++)
			scanf("%d", X + i);
		for(int i=1; i<=N; i++)
			scanf("%d", Y + i);
		fill(&state[0][0], &state[0][0] + sizeof(state) / sizeof(int), -1);

		/////////////////////////////////////////////////////////////////////////////////////////////
		for(int x=0; x<=N; x++)
			for(int y=0; y<=N; y++) {
				state[x][y] = checkState(x, y);
				switch (state[x][y])
				{
				case 1:
					Answer1++;
					break;
				
				case 2:
					Answer2++;
					break;
				}
			}
		/////////////////////////////////////////////////////////////////////////////////////////////

		cout << "Case #" << test_case+1 << endl;
		cout << Answer1 << " " << Answer2 << endl;
	}

	return 0;
}

int checkState(int x, int y)
{
	int sum, val, temp = x;
	bool isCase2 = true;

	if(x == 0 && y == 0)
		return 1;
	if(state[x][y] != -1)
		return state[x][y];

	sum = X[x];
	while(x>0 && sum <= K) {
		val = checkState(--x, y);
		if(val == 2)
			return 1;
		else if(val == 0)
			isCase2 = false;
		sum += X[x];
	}
	
	x = temp;
	sum = Y[y];
	while (y>0 && sum <= K) {
		val = checkState(x, --y);
		if(val == 2)
			return 1;
		else if(val == 0)
			isCase2 = false;
		sum += Y[y];
	}

	if(isCase2)
		return 2;
	else
		return 0;
}