#include <iostream>
#include <vector>

using namespace std;

vector<int> rotar(vector<int> v, int k){
    int i=0;
    while(i<k){
        v.push_back(v[i]);
        i++;
    }
    vector<int> w;
    for(i=k;i<=(v.size()-1);i++){
        w.push_back(v[i]);
    }
    return w;
}

int main() {
    /* No hace falta modificar el main */
    // Leo las entradas
    int n; //Longitud del vector a rotar
    cin >> n;
    int i = 0;
    int x;
    vector<int> v;// En v leo el vector
    while (i<n){
        cin >> x;
        v.push_back(x);
        i++;
    }
    
    int k; // La cantidad que tengo que rotar la guardo en k
    cin >> k;
    
    // Hago la rotacion
    vector<int> res = rotar(v,k);
    i = 0;
    
    // Imprimo el vector resultado
    while (i < res.size()){
        cout << res[i] << " ";
        i++;
    }

    return 0;
}
