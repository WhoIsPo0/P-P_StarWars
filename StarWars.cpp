#include <iostream>
using namespace std;

void Chart();

int main(){
    Chart();
    return 0;
}

void Chart(){

    for(int i = 0 ; i <= 10 ; i++){
        for(int j = 0 ; j <= 10 ; j++)
            cout << " ---";

        cout << endl;

        if( i <= 9) {
            for (int k = 0; k <= 11; k++)
                cout << "|   ";

            cout << endl;
        }

    }
}