#include <iostream>
#include <stack>
#include <cctype>
#include <cstring>
using namespace std;

int main (void)
{
    int CasoTeste;
    cin >> CasoTeste;
    char entrada [410];
    stack <char> l;

    while ( CasoTeste-- ) {
        cin>>entrada;
        int t = strlen (entrada);

        for ( int i = 0; i < t; i++ ) {

            if ( isalpha (entrada [i]) )
                cout << entrada [i];

            else if ( entrada [i] == ')' ) {
                cout << l.top ();
                l.pop ();
            }

            else if ( entrada [i] != '(' )
                l.push (entrada [i]);
        }

        cout << endl;
    }

    return 0;
}
