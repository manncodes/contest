#include<iostream>

#include<cmath>

#include<iomanip>

#include<algorithm>

#include<string>

#include<fstream>

#include<vector>

#include<deque>

#include<list>

#include<map>

#include<set>

#include<unordered_set>

#include<unordered_map>

#include<stack>

#include<queue>

#define double long double

#define ll long long int

#define yes   cout<<"YES"<<endl

#define no    cout<<"NO"<<endl

#define all(a)        (a).begin(), (a).end()

#define rall(a)       (a).rbegin(), (a).rend()

using namespace std;

const double bye = 3.141592653;



void fast()

{

	ios::sync_with_stdio(false);

	cin.tie(nullptr);

	cout.tie(nullptr);

}

ll gcd(ll a, ll b)

{

	while (b != 0)

	{

		ll temp = a;

		a = b;

		b = temp % a;

	}

	return a;

}

int arr[55][55];



void solve()

{

	ll n = 0, m = 0, q = 0, ans = 0, ans2 = 0, res = 0, mn = INT_MAX, mx = INT_MIN, mn2 = INT_MAX, mx2 = INT_MIN;





	cin >> n;

	m = n * n;

	q = 1;

	if (n % 2 == 1)

	{

		for (int i = 0; i < n; i++)

		{

			for (int j = 0; j < n; j++)

			{

				if (j % 2 == 0)

				{

					arr[i][j] = m;

					m--;

				}

				else

				{

					arr[i][j] = q;

					q++;

				}

			}

		}

	}

	else {



		for (int i = 0; i < n; i++)

		{

			for (int j = 0; j < n; j++)

			{

				if (j % 2 == 1)

				{

					arr[i][j] = m;

					m--;

				}

				else

				{

					arr[i][j] = q;

					q++;

				}

			}

		}





	}



	for (int i = 0; i < n; i++)

	{

		for (int j = 0; j < n; j++)

		{

			cout << arr[i][j] << " ";

		}

		cout << endl;

	}





}

int main()

{



	fast();



	int t;

	cin >> t;

	while (t--)

		solve();





}