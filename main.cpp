// #include <bits/stdc++.h>

// using namespace std;


//     int main(int argc, char const *argv[])
//     {

//     	#ifndef ONLINE_JUDGE
// 	    // for getting input from input.txt
// 	    freopen("input.txt", "r", stdin);
// 	    // for writing output to output.txt
// 	    freopen("output.txt", "w", stdout);
// 		#endif
//     	int a, b, c;
//     	cin>>a >>b >>c ;

//     	int ans = a+b+c;
//     	cout<< ans;
//     	return 0;
//     }




// //3

// #include <bits/stdc++.h>
// #include <unordered_map>

// using namespace std;

// typedef long long ll;
// typedef pair<int, int> pi;
// typedef vector<bool> vb;
// typedef vector<int> vi;
// typedef vector<ll> vll;
// typedef vector<pi> vpi;
// typedef vector<vi> vvi;

// #define rep2(i, a, b) for (auto i = (a); i < (b); i++)
// #define rep(i, a) rep2(i, 0, a)

// vpi dxy = { pi(-1, 0), pi(1, 0), pi(0, -1), pi(0, 1) };
// void print(vi a) { rep(i, a.size()) cout << " " << a[i]; cout << endl; }
// void print2(vvi a) { rep(i, a.size()) { rep(j, a[i].size()) cout << " " << a[i][j]; cout << endl; } }

// int solve() {
//     int n;
//     cin >> n;
//     vi p(n), h(n);
//     rep(i, n) cin >> p[i] >> h[i];
//     vi rk(n);
//     rep(i, n) rk[i] = i;
//     sort(rk.begin(), rk.end(), [p](int x, int y) { return p[x] < p[y]; });
    
//     unordered_map<int, int> l; // left most position when cut down to the right >>>>>
//     unordered_map<int, int> r; // right most position when cut down to the left <<<<<
//     int ret = 0;
//     for (int i = n - 1; i >= 0; i--) {
//         int j = rk[i], pos = p[j] - h[j];
//         auto iter = r.find(p[j]);
//         r[pos] = max(h[j] + (iter == r.end() ? 0 : iter->second), r[pos]);
//         ret = max(ret, r[pos]);
//     }
//     rep(i, n) {
//         int j = rk[i], pos = p[j] + h[j];
//         auto iter = l.find(p[j]);
//         l[pos] = max(h[j] + (iter == l.end() ? 0 : iter->second), l[pos]);
//         iter = r.find(pos);
//         ret = max(ret, (iter == r.end() ? 0 : iter->second) + l[pos]);
//     }
//     return ret;
// }

// int main() {
//     ios::sync_with_stdio(0); cin.tie(0);
//     freopen("timber_input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
//     int t = 1;
//     cin >> t;
//     rep(i, t) {
//         cout << "Case #" << i + 1 << ": ";
//         cout << solve() << endl;
//         // solve();
//     }
// }


// //4
// #include <bits/stdc++.h>
// #include <unordered_set>
// using namespace std;

// typedef long long ll;
// typedef pair<int, int> pi;
// typedef vector<bool> vb;
// typedef vector<int> vi;
// typedef vector<ll> vll;
// typedef vector<pi> vpi;
// typedef vector<vi> vvi;

// #define rep2(i, a, b) for (auto i = (a); i < (b); i++)
// #define rep(i, a) rep2(i, 0, a)

// vpi dxy = { pi(-1, 0), pi(1, 0), pi(0, -1), pi(0, 1) };
// void print(vi a) { rep(i, a.size()) cout << " " << a[i]; cout << endl; }
// void print2(vvi a) { rep(i, a.size()) { rep(j, a[i].size()) cout << " " << a[i][j]; cout << endl; } }

// ll solve() {
//     int n, m;
//     cin >> n >> m;
//     vll c(n);
//     rep(i, n) cin >> c[i];
//     vector<pair<ll, int>> heap{ pair<ll, int>(0, n - 1) };
//     auto cmp = [](pair<ll, int> a, pair<ll, int> b) { return a.first > b.first; };

//     for (int i = n - 2; i > 0; i--) {
//         if (c[i] == 0) continue;
//         while (heap.size() > 0 && heap[0].second > i + m) {
//             pop_heap(heap.begin(), heap.end(), cmp);
//             heap.pop_back();
//         }
//         if (heap.size() == 0) break;
//         heap.push_back(pair<ll, int>(heap[0].first + c[i], i));
//         push_heap(heap.begin(), heap.end(), cmp);
//     }
//     while (heap.size() > 0 && heap[0].second > m) {
//         pop_heap(heap.begin(), heap.end(), cmp);
//         heap.pop_back();
//     }
//     if (heap.size() == 0) return -1;
//     return heap[0].first;
// }

// int main() {
//     ios::sync_with_stdio(0); cin.tie(0);
//     freopen("running_on_fumes_chapter_1_input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
//     int t = 1;
//     cin >> t;
//     rep(i, t) {
//         cout << "Case #" << i + 1 << ": ";
//         cout << solve() << endl;
//         // solve();
//     }
// }

// #include<bits/stdc++.h>
// #define ll long long
// using namespace std;
// ll even=1485675896686442139,odd=1551864689390002130;
// ll a[105];
// void dfs(vector<vector<int> >&v,int i,int par,int dist){
//     if(dist%2)
//         a[i]=odd;
//     else a[i]=even;
//     for(auto it:v[i]){
//         if(it!=par)
//             dfs(v,it,i,dist+1);
//     }
// }
// int main(){
// int t;
// cin>>t;
// while(t--){
//     ll n,i,j,x,y;
//     cin>>n;
//     vector<vector<int> > v(n+1);
//     for(i=0;i<n-1;i++){
//         cin>>x>>y;
//         v[x].push_back(y);
//         v[y].push_back(x);
//     }
//     dfs(v,1,-1,1);
//     for(i=1;i<=n;i++)
//         cout<<a[i]<<" ";
//     cout<<endl;
// }
// }



// #include<bits/stdc++.h>
// #define ll long long int
// using namespace std;

// void dikhawo(vector<vector<int>> v, int n){
// 	for (int i = 0; i < n+1; ++i)
// 	{
// 		/* code */
// 		for (auto j = v[i].begin(); j != v[i].end(); ++j) {
// 			cout << *j<< " ";
// 		}
//         cout<<endl;
// 	}
// }

// int main()
// {
// 	/* code */
// 		#ifndef ONLINE_JUDGE
// 	    // for getting input from input.txt
// 	    freopen("input.txt", "r", stdin);
// 	    // for writing output to output.txt
// 	    freopen("output.txt", "w", stdout);
// 		#endif
// 	int t;
// 	ll n;
// 	cin>> t;
	// while(t--){
	// 	cin>>n;
	// 	int sum=0;
	// 	ll arr[n]={0};
	// 	for (int i = 0; i < n; i++)
	// 	{
	// 		/* code */
	// 		cin>>arr[i];
	// 	}

	// 	sort(arr, arr+n);
	// 	for (int i = 1; i < n; i++)
	// 	{
	// 		/* code */
	// 		int fac = arr[0];
	// 		int temp = 0;
	// 		temp =  (fac *arr[i] );
	// 		//cout<<arr[i]<<" ";
	// 		sum = sum + temp;

	// 	}
	// 	cout<<sum<<endl;
	
	// }

	// while (t--) {
	// 	int n;
	// 	cin>>n;
 
	// 	int i;
	// 	int min;
	// 	unsigned long long sum;
	// 	for (i=1, min=getInt(), sum=min; i<n; i++) {
	// 		int p = getInt();
	// 		if (p < min)
	// 			min = p;
	// 		sum += p;
	// 	}
	// 	sum = (sum-min)*min;
	// 	printf("%llu\n", sum);
	// }




// 	return 0;
// }

// CPP program to count frequencies of array items 
// #include <bits/stdc++.h> 
// #define ll long long int
// using namespace std; 

// void findFreq(int arr[], int n) 
// { 
// 	unordered_map<int, int> mp; 

	
// 	for (int i = 0; i < n; i++) 
// 		mp[arr[i]]++; 

	
// 	for (auto x : mp) 
// 		cout << x.first << " " << x.second << endl; 
// } 

// int main() 
// { 
	//#ifndef ONLINE_JUDGE
// 	    // for getting input from input.txt
// 	    freopen("input.txt", "r", stdin);
// 	    // for writing output to output.txt
// 	    freopen("output.txt", "w", stdout);
// 		#endif
// 	ll n;
// 	cin>>n;
// 	int arr[n];
// 	for (int i = 0; i < n; ++i)
// 	{
// 		 code 
// 		cin>>arr[i];
// 	}
	
// 	findFreq(arr, n); 
// 	return 0; 
// } 


//  facebook 2019 hackercup 

// Graphs as a Service
// Solution by Jacob Plachta

#include <bits/stdc++.h> 
#define ll long long int
using namespace std; 
#define boost ios::sync_with_stdio(0); cin.tie(0)
#define mp(x, y) make_pair(x, y)

typedef pair<int, int> pii;

int main()
{
		#ifndef ONLINE_JUDGE
	    // for getting input from input.txt
	    freopen("input.txt", "r", stdin);
	    // for writing output to output.txt
	    freopen("output.txt", "w", stdout);
		#endif
	boost;

	int T;
	cin>>T;
	for(int test=1; test<=T; test++){
		ll n, m;
		cin>>n>>m;
		ll arr[n+1][n+1];
		for (int i = 0; i < n; ++i)
		{
			/* code */
			for (int j = 0; j < n; ++j)
			{
				/* code */
				arr[i][j] = 1e9;
			}
			arr[i][i]=0;
		}

		vector<pair<pii, int>> edges;
		for (int i = 0; i < m; ++i)
		{
			int x, y, z;
			cin>>x>>y>>z;
			arr[x][y] = arr[y][x]= z;
			edges.push_back(make_pair(make_pair(x, y), z));
		}

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				for (int k = 0; k < n; ++k)
				{
					arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
				}
			}
		}

		bool fail = 1;
		for(auto e:edges){
			if(arr[e.first.first][e.first.second] < e.second)
			
				fail = 0;
				break;
			
		}

		cout<<"Case #"<<test<<": ";

		if (fail)
		{
			cout<<m<<"\n";
			for(auto e : edges) {
				cout<<e.first.first<<" "<<e.first.second<<" "<<e.second<<"\n";
			}
		}
		else{
			cout<<"Impossible"<<endl;
		}


	}
	return 0;
}