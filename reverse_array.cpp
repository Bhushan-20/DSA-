#include<iostream>
#include<vector>
using namespace std;

vector<int> reverse(vector<int> v){
    int e=v.size()-1;
    int s=0;
    while (s<=e){
        swap(v[s],v[e]);
        s++;
        e--;

    }
    return v;
    
}
void print(vector<int> v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}
int main(){
    vector<int> v{5,3,8,1};
    vector<int> ans = reverse(v);
    cout<<"Reversed Array = ";
    print(ans);

    return 0;
}