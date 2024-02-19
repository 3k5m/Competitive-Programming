#include <bits/stdc++.h>
using namespace std;

int pfx[1000005];

void solve(){
    int n, s, t, p, max = -1, de;
    bool candestroyall = false;
    cin>>n>>s>>t;
    cin>>p;
    pfx[0]=p;
    for(int i=1;i<n;i++){
        cin>>p;
        pfx[i]=pfx[i-1]+p;
    }
    //for(auto x:pfx) {if(x!=0)cout<<x<<" ";}
    //cout<<"\n";
    for(int i=0, j=t;i<=t;i++,j--){
        candestroyall = false;
        de = 0;
        int leftd = i*s-1;
        int rightd = (n-1)-j*s;
        if(leftd>=0 && leftd<=n-1) {de += pfx[leftd];}
        if(rightd<=n-1 && rightd>=0) {de += (pfx[n-1] - pfx[rightd]);}

        if(leftd>=n-1 || rightd<=0){
            candestroyall = true;
            max = pfx[n-1];
            break;
        }
        //cout<<"two pfx index are  "<<leftd<<" || "<<rightd<<"\n";
        //cout<<"two pfx values are  "<<pfx[leftd]<<" || "<<pfx[rightd]<<"\n";
        //cout<<"de is "<<de<<"\n";
        if(de > max) max = de;
    }
    cout<<max;
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0)->sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}
