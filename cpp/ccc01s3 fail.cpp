#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

const int MAX = 26;
const int endgoal = 1;

bool roadgraph[MAX][MAX];
stack<int> st;
bool visited[MAX][MAX] = {{0}};
bool bomb[MAX][MAX] = {{0}};

void clearvisits(){
    memset(visited, 0, sizeof(visited));
    while(!st.empty())st.pop();
}

void checkdisc(){
    for(int i=0;i<MAX;i++){
        for(int j=0;j<MAX;j++){
            bomb[i][j]&=visited[i][j];
        }
    }
}


void giveresult(){
    int r = 0;
    for(int i=0;i<MAX;i++){
        for(int j=0;j<MAX;j++){
            if(bomb[i][j]){
                char i2=char(i+'A'), j2=char(j+'A');
                cout<<i2<<j2<<"\n";
                r++;
            }
        }
    }
    cout<<"There are "<<r<<" disconnecting roads.\n";
}

void dfs() {
    int cur;
    while(!st.empty()){
        cur = st.top(); st.pop();

        cout<<"current spot: "<<cur<<"\n";

        //check if we reached end
        if(cur==endgoal){
            cout<<"reached end successfully \n";
            checkdisc();
            return;
            //problem w visited is it stores data for entire dfs session, not just one path... check later
        }

        //check for paths
        for(int i=0;i<MAX;i++){
            if(roadgraph[cur][i]){
                if(!visited[cur][i]){
                     cout<<"visiting new node: --> "<<i<<"\n";
                    st.push(i);
                    visited[cur][i]=1;
                }
            }
        }
    }
}

void solve(){

    while(true){
        char c, d; cin>>c;
        if(c=='*') break;
        cin>>d;
        roadgraph[c-'A'][d-'A'] = 1;
        bomb[c-'A'][d-'A'] = 1;
    }


        for(int i=0;i<MAX;i++){
            if(roadgraph[0][i]){
                cout<<"visiting new node: --> "<<i<<"\n";
                st.push(i);
                visited[0][i]=1;
                dfs();
                clearvisits();
            }
        }

    giveresult();
}



int main() {

    //ios_base::sync_with_stdio(0);
    //cin.tie(0)->sync_with_stdio(0);
    //cin.tie(0); cout.tie(0);

    solve();

    return 0;
}
