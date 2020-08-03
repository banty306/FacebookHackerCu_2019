#include <bits/stdc++.h> 
#define ll long long int
using namespace std; 
#define boost ios::sync_with_stdio(0); cin.tie(0)
#define mp(x, y) make_pair(x, y)

typedef pair<int, int> pii;
const int MOD = 1000000007;
const int N = 1e6 + 5;
ll pw2[N];


int main()
{
		// #ifndef ONLINE_JUDGE
	 //    // for getting input from input.txt
	 //    freopen("input.txt", "r", stdin);
	 //    // for writing output to output.txt
	 //    freopen("output.txt", "w", stdout);
		// #endif
	boost;
	pw2[0] = 1;
	for(int i=1; i<N; i++) {
		pw2[i] = (pw2[i-1] * 2) % MOD;
	}

	int T;
	cin>>T;
	for(int test=1; test<=T; test++){
		int n, k;
		cin>>n>>k;
		string str;
		cin>>str;
		reverse(str.begin(), str.end());
		ll ans=0;
		int d=0;
		
		for (int i = 0; i < n; i++)
		{
			if (str[i]=='B')
			{
				d++;
			}
			else{
				d--
;			}
			if (d > k)
			{
				ans = ans + pw2[n - i] % MOD ;
				d = d-2;
			}
			if (d < 0)
			{
				d =0;
			}
		}

		cout<<"Case #" <<test <<": ";
		cout<<ans<<endl;
	}
	return 0;
}