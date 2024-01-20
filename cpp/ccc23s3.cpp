#include <bits/stdc++.h>
using namespace std;

char poster[2005][2005];

int n, m, r, c, i, j;
bool impossible = false, swapped = false;

void defaultposter(){
    for(i=0;i<r;i++){
        for(j=0;j<m;j++){
            poster[i][j] = 'a';
        }
    }
    for(;i<n;i++){
        for(j=0;j<c;j++){
            poster[i][j] = 'a';
        }
        for(;j<m;j++){
            poster[i][j] = 'b';
        }
    }
}

void fullexposter(){
    if(c%2==m%2){
        //eliminate 2 columns at a time, until c=m
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                poster[i][j] = 'a';
            }
        }
        for(i=0;i<(m-c)/2;i++){
            poster[0][i] = 'b';
            poster[0][m-1-i] = 'b';
        }
    }else if(m%2==1){
        //use middle column after eliminating 2 at a time
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                poster[i][j] = 'a';
            }
        }
        for(i=0;i<((m-c)/2);i++){
            poster[0][i] = 'b';
            poster[0][m-1-i] = 'b';
        }
        poster[0][(0+m)/2] = 'b';
    }else{
        impossible = true;
    }
}

void nosymposter(){
    for(i=0;i<n;i++){
        for(j=0;j<m-1;j++){
            poster[i][j] = 'a';
        }
        poster[i][m-1] = 'b';
    }
    
    for(i=m-1;i>c-1;i--){
        poster[n-1][i] ++;
    }
}

void solve(){
    cin>>n>>m>>r>>c;
    if(r<n && c<m && r>0 && c>0){
        defaultposter();
    }else if(r == 0){
        nosymposter();
    }else if(c == 0){
        swapped = true;
        swap(n, m);
        swap(r, c);
        nosymposter();
    }else if(r == n){
        fullexposter();
    }else if(c == m){
        swapped = true;
        swap(n, m);
        swap(r, c);
        fullexposter();
    }

    if(!impossible){
        if(swapped){
            for(j=0;j<m;j++){
                for(i=0;i<n;i++){
                    cout<<poster[i][j];
                }
                cout<<"\n";
            }
        }
        else{
            for(i=0;i<n;i++){
                for(j=0;j<m;j++){
                    cout<<poster[i][j];
                }
                cout<<"\n";
            }
        }
    }else{
        cout<<"IMPOSSIBLE";
    }
}



int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0)->sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}
