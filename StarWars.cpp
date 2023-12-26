#include <iostream>
using namespace std;

void initializeGame ();
void Chart();

int main(){
    
    initializeGame();
    
    return 0;
}

// define chart function
void Chart(){

    for(int i = 0 ; i <= 10 ; i++){
        for(int j = 0 ; j <= 9 ; j++)
            cout << " ---";

        cout << endl;

        if( i <= 9) {
            for (int k = 0; k <= 10; k++)
                cout << "|   ";

            cout << endl;
        }

    }
}

// define initializeGame function

void initializeGame(){

    Chart () ;
}