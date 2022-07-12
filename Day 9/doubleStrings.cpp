#include <bits/stdc++.h>
using namespace std;

void solve() {

   int n;
   cin>>n;

   vector<string> a;
   unordered_map<string, int> mp;

   for(int i = 0; i < n; i++) {

        string temp;
        cin>>temp;

        a.push_back(temp);
        mp[temp] = 1;

   }

    vector<int> binaryString(n, 0);

   for(int i = 0; i < n; i++) {

        for(int j = 1; j < a[i].size(); j++) {

            string t = a[i].substr(0, j);
            string s = a[i]. substr(j);

            if(mp.find(t) != mp.end() && mp.find(s) != mp.end()) {

                binaryString[i] = 1;
                break;

            }
        }
   }

   for(int i = 0; i < binaryString.size(); i++)
    cout<<binaryString[i];

   cout<<"\n";

}


int main()
{

    int t;
    cin>>t;

    while(t--) {

        solve();
    }

    return 0;

}
