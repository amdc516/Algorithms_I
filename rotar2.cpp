#include <iostream>
#include <string>

using namespace std;

string rotar(string s, int j) {
    int i=0;
    while(i<j){
        s.push_back(s[i]);
        i++;
    }
    string w;
    for(i=j;i<=(s.size()-1);i++){
        w.push_back(s[i]);
    }
    return w;
}

int main()
{
    /* No hace falta modificar el main */
    // Leo la entrada
    string s;
    int j;
    cin >> s >> j;
    
    string res = rotar(s, j);
    cout << res;
    return 0;
}
