#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<int>>&mat , int i ,int j){
    mat[i][j]=1;
    mat[j][i]=1;
}

void display(vector<vector<int>>&mat){
    int v = mat.size();
    for(int i=0 ; i<v ; i++){
        for(int j=0 ; j<v ; j++){
            cout<<mat[i][j]<<" ";

        }
        cout<<endl;
    }
}


int main(){
    int v = 3;
    vector<vector<int>>mat(v, vector<int>(v,0));

    addEdge(mat  , 0 , 1);
    addEdge(mat  , 1 , 2);
    addEdge(mat  , 2 , 0);

    display(mat);


    
}