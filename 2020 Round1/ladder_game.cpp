#include <iostream>
#include <algorithm>
#include <stack>
#define MAX_N 1501
#define MAX_K 2001
#define MIN(alpha, beta) alpha > beta ? beta : alpha
using namespace std;

typedef struct {
    int first;
    int second;
    int third;
    int fourth;
} MultiPairs;

int Answer, N, K, M;
int ladder[MAX_K][MAX_N];
int findPath(int from, int to);
MultiPairs makeMultiPairs(int first, int second, int third, int fourth);


int main(int argc, char** argv)
{
	int T, test_case, from, to;

	scanf("%d", &T);
	for(test_case = 0; test_case < T; test_case++)
	{
		Answer = 0;
        scanf("%d %d %d", &N, &K, &M);
        fill(&ladder[0][0], &ladder[0][0] + sizeof(ladder) / sizeof(int), -1);
        
        for(int k=1; k<=K; k++) {
            scanf("%d %d", &from, &to);
            ladder[k][from] = to;
            ladder[k][to] = from;
        }
        for(int m=1; m<=M; m++) {
            scanf("%d %d", &from, &to);
        /////////////////////////////////////////////////////////////////////////////////////////////
            Answer += findPath(from, to);
		/////////////////////////////////////////////////////////////////////////////////////////////
        }
		
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;
}

int findPath(int from, int to)
{
    int result = K + 1;
    MultiPairs mp = {0, from, 0, 0};
    stack<MultiPairs> st;
    st.push(mp);

    while(!st.empty()) {
        mp = st.top(); st.pop();
        
        if(mp.first == K + 1 && mp.second == to) {
            result = MIN(result, mp.third);
            continue;
        }

        if(ladder[mp.first][mp.second] != -1 && mp.fourth == 0) {
            st.push(makeMultiPairs(mp.first, ladder[mp.first][mp.second], mp.third, 1));
            if(mp.first <= K) {
                st.push(makeMultiPairs(mp.first + 1, mp.second, mp.third + 1, 0)); // ignore
            }
        }
        else if(mp.first <= K) {
            st.push(makeMultiPairs(mp.first + 1, mp.second, mp.third, 0));
        }
    }
    if(result == K + 1)
        return -1;
    else
        return result;
}

MultiPairs makeMultiPairs(int first, int second, int third, int fourth)
{
    MultiPairs mp = {first, second, third, fourth};
    return mp;
}