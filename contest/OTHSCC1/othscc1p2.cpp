#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, v, max=-1, sum=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>v;
        if(v>max) max = v;
        sum+=v;
    }
    sum-=max;
    cout<<floor(sum/(n-1));
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0)->sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}
