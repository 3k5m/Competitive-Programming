#include <bits/stdc++.h>
using namespace std;

//extremely convoluted way to find solution
//this works by first using guaranteed method once two numbers are in row/column
//and then eliminating special cases one by one in each function

#define INF 1000000001
#define debug 0

int matrice[3][3] = {{INF,INF,INF},{INF,INF,INF},{INF,INF,INF}};

void printsquare(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<matrice[i][j]<<" ";
        }
        cout<<"\n";
    }
}

int checkrow(int c, bool row){
    int n = 0;
    int numA, numB, locA, locB, locC, diff;
    for(int i=0;i<3;i++){
        int checkthis;
        if(row) checkthis = matrice[c][i];
        else checkthis = matrice[i][c];

        if(checkthis != INF){
            if(!n) {
                numA = checkthis;
                locA = i;
            }else{
                numB = checkthis;
                locB = i;
            }
            n++;
        }else{
            locC = i;
        }
    }
    if(n==3) return 1;
    if(n==1 || n==0) return -1;

    if(numA == INF || numB == INF) return -1;

    diff = (numA - numB) / (locA - locB);
    if(row) matrice[c][locC] = numA + diff * (locC - locA);
    else matrice[locC][c] = numA + diff * (locC - locA);
    return 0;
}

void checkguarantees(){
    bool allpass; int l=0;
    do{
        l++;
        allpass = true;
        for(int i=0;i<3;i++){
            if(checkrow(i,1)==-1) allpass = false;
        }
        
        for(int i=0;i<3;i++){
            if(checkrow(i,0)==-1) allpass = false;
        }
    }while(!allpass && l<=50);
}

void Lshape(){
    
    if(debug) cout<<"Lshape activated\n";
    int row = -1, column = -1, n=0;
    for(int i=0;i<3;i++){
        n=0;
        for(int j=0;j<3;j++){
            if(matrice[i][j] != INF){
                n++;
            }
        }
        if(n==3) {
            if(row==-1){
                row = i;
            }else{
                return;
            }
        }
    }
    for(int i=0;i<3;i++){
        n=0;
        for(int j=0;j<3;j++){
            if(matrice[j][i] != INF){
                n++;
            }
        }
        if(n==3) {
            if(column==-1){
                column = i;
            }else{
                return;
            }
        }
    }
    
    if(row==-1 && column == -1) return;
    if(row==-1 && column != -1){
        for(int i=0;i<3;i++){
            if(i==row) continue;
            for(int j=0;j<3;j++){
                if(j==column) continue;
                matrice[i][j] = matrice[i][column];
                checkguarantees();
                if(debug) cout<<"Lshape success (column only)\n";
            }
        }
    }else if(row!=-1 && column == -1){
        for(int i=0;i<3;i++){
            if(i==row) continue;
            for(int j=0;j<3;j++){
                if(j==column) continue;
                matrice[i][j] = matrice[row][j];
                checkguarantees();
                if(debug) cout<<"Lshape success (row only)\n";
            }
        }

    }else{
        for(int i=0;i<3;i++){
            if(i==row) continue;
            for(int j=0;j<3;j++){
                if(j==column) continue;
                matrice[i][j] = matrice[row][j] + matrice[i][column] - matrice[row][column];
                checkguarantees();
                if(debug) cout<<"Lshape success (both r+c)\n";
            }
        }
    }

}

//all starting values fit in 2x2 area
void minisquare(){
            if(debug) cout<<"minisquare activated\n";
    bool flag = true;
    //check top row
    if(matrice[0][0]==INF && matrice[0][1]==INF && matrice[0][2]==INF && matrice[1][0]==INF && matrice[2][0]==INF){
        //top left
        for(int i=1;i<=2;i++){
            for(int j=1;j<=2;j++){
                if(matrice[i][j] == INF){
                    matrice[i][j] = 0;
                }
            }
        }
    }else if(matrice[0][0]==INF && matrice[0][1]==INF && matrice[0][2]==INF && matrice[1][2]==INF && matrice[2][2]==INF){
        //top right
        for(int i=1;i<=2;i++){
            for(int j=0;j<=1;j++){
                if(matrice[i][j] == INF){
                    matrice[i][j] = 0;
                }
            }
        }
    }else if(matrice[2][1]==INF && matrice[2][2]==INF && matrice[0][0]==INF && matrice[1][0]==INF && matrice[2][0]==INF){
        //bottom left
        for(int i=0;i<=1;i++){
            for(int j=1;j<=2;j++){
                if(matrice[i][j] == INF){
                    matrice[i][j] = 0;
                }
            }
        }
    }else if(matrice[2][2]==INF && matrice[2][1]==INF && matrice[2][0]==INF && matrice[1][2]==INF && matrice[0][2]==INF){
        //bottom right
        for(int i=0;i<=1;i++){
            for(int j=0;j<=1;j++){
                if(matrice[i][j] == INF){
                    matrice[i][j] = 0;
                }
            }
        }
    }
            if(debug) cout<<"minisquare finished\n";
    checkguarantees();
    return;
}

void diagonal(){
            if(debug) cout<<"diagonal activated\n";
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if((i==0&&j==0)||(i==1&&j==1)||(i==2&&j==2)) {
                continue;
            }
            if((i==2&&j==0)||(i==1&&j==1)||(i==0&&j==2)) {
                continue;
            }
            if(matrice[i][j] != INF){
                return;
            }
        }
    }
    if(matrice[0][0]!=INF || matrice[2][2]!=INF){
        if(matrice[0][0]==INF) matrice[0][0] = 0;
        if(matrice[1][1]==INF) matrice[1][2] = 0;
        if(matrice[2][2]==INF) matrice[2][2] = 0;
        matrice[0][1] = matrice[1][1];
    }else if (matrice[2][0]!=INF || matrice[0][2]!=INF){
        if(matrice[0][2]==INF) matrice[0][2] = 0;
        if(matrice[1][1]==INF) matrice[1][2] = 0;
        if(matrice[2][0]==INF) matrice[2][0] = 0;
        matrice[0][1] = matrice[1][1];
    }
            if(debug) cout<<"diagonal success\n";
    checkguarantees();
    return;
}

void lastcase(){
            if(debug) cout<<"lastcase activated\n";
    bool flag = false;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(matrice[i][j] == INF){
                flag = true;
            }
        }
    }
    if(!flag) return;

    if(matrice[0][0]!=INF){
        matrice[1][1] = matrice[2][1];
        if(matrice[1][1]==INF) matrice[1][1] = matrice[1][2];
    }
    if(matrice[2][0]!=INF){
        matrice[1][1] = matrice[0][1];
        if(matrice[1][1]==INF) matrice[1][1] = matrice[1][2];
    }
    if(matrice[0][2]!=INF){
        matrice[1][1] = matrice[1][0];
        if(matrice[1][1]==INF) matrice[1][1] = matrice[2][1];
    }
    if(matrice[2][2]!=INF){
        matrice[1][1] = matrice[0][1];
        if(matrice[1][1]==INF) matrice[1][1] = matrice[1][0];
    }

            if(debug) cout<<"lastcase success\n";
    checkguarantees();
    Lshape();
    checkguarantees();
    return;
}

//do this last if every other case fails
//ended up not using this because it fails randomly (who would've guessed)
void randomtry(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(matrice[i][j] == INF){
                matrice[i][j] = rand()%10;
                checkguarantees();
            }
        }
    }
}

void solve(){

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            string inp; cin>>inp;
            if(inp == "X"){
                continue;
            }else{
                matrice[i][j] = stoi(inp);
            }
        }
    }
    
    minisquare();
    
    //do basic checks, fills in the third if there's two on row/column
    checkguarantees();

    //special case handling
    Lshape();
    minisquare();
    diagonal();
    lastcase();
    //randomtry();

    printsquare();
}



int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0)->sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}
