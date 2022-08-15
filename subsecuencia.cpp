#include <iostream>
#include <string>

using namespace std;

bool subsecuencia(string s, string t){
    int i=0;
    int k=0;
    int l=0;
    while(i<s.size()){
        int j=k;
        while(j<t.size()){
            if(s[i]==t[j]) {
                k=j;
                j=t.size();
                l++;
            }
            j++;
        }
        i++;
    }
    return(l==s.size());
}


int main()
{
    /* No hace falta modificar el main */
    // Leo la entrada
    string s, t;
    cin >> s >> t;
    
    bool res = subsecuencia(s, t);
    cout << (res ? "true" : "false");
    return 0;
}

