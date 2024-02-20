#include <bits/stdc++.h>
using namespace std;

    string x;
    int sum=0,loops=0, i=0;
    int num;
    bool neg = false;

int parsenum(){
    neg = false;
    if(x[i]=='-'){
        neg = true;
        i++;
    }
    num = x[i]-'0';
    i++;
    while(x[i]>='0' && x[i]<='9'){
        num*=10;
        num+=x[i]-'0';
        i++;
    }
    if(neg) num*=-1;
    return num;
}

void solve(){
    getline(cin, x);
    for(i=0;i<x.length();i++){
        if((x[i]>='0' && x[i]<='9') || x[i]=='-'){
            sum+=parsenum();
        }
    }
    cout<<sum;
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0)->sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}
