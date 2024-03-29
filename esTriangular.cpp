#include <iostream>
#include <vector>

using namespace std;

bool esTriangular(vector<vector<int> > m){
    bool res1 = true;
    for (int i = 0; i < m.size(); i++){
        for (int j = 0; j < m[0].size(); j++) {
            if (i < j){
                res1 = res1 && m[i][j] == 0;
            }
        }
    }
    bool res2 = true;
    for (int i = 0; i < m.size(); i++){
        for (int j = 0; j < m[0].size(); j++) {
            if (i > j){
                res2 = res2 && m[i][j] == 0;
            }
        }
    }
	return res1 || res2;
}

int main()
{
    /* No hace falta modificar el main */
    // Leo la entrada
    int n; // Cantidad de filas y columnas de la matriz
    cin >> n;
    int x;
    int filas = n, columnas = n;
    vector<vector<int> > m(filas, vector<int>(columnas, 0)); // En m leo la matriz
    
    for (int f = 0; f < filas; ++f) {
        for (int c = 0; c < columnas; ++c) {
            cin >> x;
            m[f][c] = x;
        }
    }

    bool res = esTriangular(m);
    cout << (res ? "true" : "false");    
    return 0;
}
