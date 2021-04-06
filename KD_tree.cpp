#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5;
const int mod = 1e9 + 7;
int n;
struct node {
    vector<int>val;
    node *izq, *der;
    node(vector<int> num){val = num;}
};
node* insert(node* root, vector<int> a,int pos){
    if(!root){
         return root = new node(a);
    }
    // solo es cuestion de avanzar la posicion y modular respecto a n
    if(root->val[pos%n] > a[pos%n]) 
        root->izq = insert(root->izq,a, pos + 1);
    else 
        root->der = insert(root->der,a, pos + 1);
    return root;
}
// para imprimir bonitos los vectores
template<typename T>
std::ostream &operator <<(std::ostream &os, const std::vector<T> &v) {
   using namespace std;
   os<<"{";
   for(int y = 0 ; y < (int)v.size() - 1;y++)
       os << v[y] <<",";
    os<< v[v.size() -1]<<"}";
   return os;
}
void print(node* root){
    if(!root)return;
    print(root->izq);
    cout<<root->val<<" ";
    print(root->der);
}
int main() {
    node *root = NULL;
    //pruebas para disintas dimensiones
    //vector<vector<int>> arr  = {{ 4} , {6} , {7} ,{1} , {3} };
    //vector<vector<int>> arr  = { {21,42}, {10,100}, {15,200},{20,50}, {20,300}};
    vector<vector<int>> arr  = { {10,0,100}, {5,10,15}, {7,7,7},{9,0,0}, {11,10,9},{11,0,0}};
    n = arr[0].size();
    for(auto x : arr)
        root = insert(root , x,0);
    //imprime en inorder
    print(root);
}
