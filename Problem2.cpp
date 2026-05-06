#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{

    int N;
    cin >> N;

    vector<long long> A(N);

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    long long K;
    cin >> K;

    for (int i = 1; i < N; i++)
    {

        if ((A[i] - A[0]) % K != 0)
        {
            cout << -1 << endl;
            return 0;
        }
    }

    vector<long long> normalized;

    for (int i = 0; i < N; i++)
    {
        normalized.push_back(A[i] / K);
    }

    sort(normalized.begin(), normalized.end());

    long long median = normalized[N / 2];

    long long operations = 0;

    for (int i = 0; i < N; i++)
    {
        operations += abs(normalized[i] - median);
    }

    cout << operations << endl;

    return 0;
}