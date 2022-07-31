#include <bits/stdc++.h>
using namespace std;

void solve() {

   int n;
   cin>>n;

   vector<int> a(3);
   a[0] = 3, a[1] = 2, a[2] = 1;

   int rem = n - 6;

   for(int i = 0; i < 3; i = (i + 1) % 3) {

        if(rem > 0) {
            a[i] += 1;
            rem -= 1;

        } else {
            break;
        }
   }

   cout<<a[1]<<" "<<a[0]<<" "<<a[2]<<endl;

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