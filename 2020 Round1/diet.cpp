#include <iostream>
#include <algorithm>
#define MAXLEN 200000
#define MAX(alpha, beta) alpha > beta ? alpha : beta
#define MIN(alpha, beta) alpha > beta ? beta : alpha
using namespace std;

int N, K;
unsigned long Answer;

int main(int argc, char** argv)
{
	int T, test_case;
	unsigned long calA[MAXLEN], calB[MAXLEN];
    
	scanf("%d", &T);
	for(test_case = 0; test_case < T; test_case++)
	{
		Answer = 0;
        scanf("%d %d", &N, &K);

        for(int i=0; i<N; i++)
            scanf("%ld", calA + i);
        for(int i=0; i<N; i++)
            scanf("%ld", calB + i);
			

		/////////////////////////////////////////////////////////////////////////////////////////////
        sort(calA, calA + N);
		sort(calB, calB + N);
		
		unsigned long local1 = 0, local2 = 0;
		for(int i=0; i<K; i++) {
			local1 = MAX(local1, calA[i] + calB[i]);
			local2 = MAX(local2, calA[i] + calB[K-1-i]);
		}
		Answer = MIN(local1, local2);
		/////////////////////////////////////////////////////////////////////////////////////////////

		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;
}