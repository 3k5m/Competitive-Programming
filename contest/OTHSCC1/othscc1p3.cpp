#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, d, chainmax = 1, det = 1, h, prevh, c=1;
    cin>>n>>d;
    cin>>h;
    for(int i=1;i<n;i++){
        if(c>chainmax) chainmax = c;
        prevh=h;
        cin>>h;
        if(abs(h-prevh)<=d){
            c++;
        }else{
            det++;
            c = 1;
        }
    }
    if(c>chainmax) chainmax = c;
    cout<<det<<"\n"<<chainmax;
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0)->sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}
