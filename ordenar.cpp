#include <vector>
#include <iostream>

using namespace std;

int indiceMinSubsec(vector<int> v, int l, int r){
  int i = l;
  int pos = l;
  int min = v[l];
  int n = v.size();
  while(l<=i && i<r){
      if(min <= v[i+1]){
          i++;
      }else{
          min=v[i+1];
          pos=i+1;
          i++;
      }
  }
return pos;  
}

void ordenar1(vector<int>& v){
  vector<int> w = v; 
  int i = 0;
  int pos;
  int minimo;
  int n = v.size();
  while(i<n){
      pos=indiceMinSubsec(w,0,w.size()-1);
      minimo=w[pos];
      v[i]=minimo;
      w.erase(w.begin()+pos);
      i++;
  } 

}

int main() {
    /* No hace falta modificar el main */
    
    // Leo las entradas
    int n; //Longitud del vector
    cin >> n;
    int i = 0;
    int x;
    vector<int> v;// En v leo el vector
    while (i<n){
        cin >> x;
        v.push_back(x);
        i++;
    }

    // Hago el ordenamiento
    ordenar1(v);
    
    // Imprimo el vector resultado
    i = 0;
    while (i < v.size()){
        cout << v[i] << " ";
        i++;
    }
    
    return 0;
}
