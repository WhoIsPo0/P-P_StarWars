#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void Chart();
void s_chart();
void attack();
void movement();

int main() {
    int Heal = 3;
    srand(time(0));
    Chart();
    while (Heal != 0) {
        return 0;
    }
}

void Chart(){
    int ES_count = 0;
    while(ES_count != 10){
    int table1[10][2];

    // Generates random coordinates for spaceship
    int s = rand() % 10;
    int z = rand() % 10;

    // Set of stars to ensure you have exactly 10 stars
    int starsSet[10][2];

    // Generate random coordinates for enemies
    for (int i = 0; i < 10; i++) {
        int x = rand() % 10;
        int y = rand() % 10;

        // Ensure the generated coordinates are not the spaceship coordinates or duplicate star coordinates
        while ((x == s && y == z) || (i > 0 && (x == starsSet[i-1][0] && y == starsSet[i-1][1]))) {
            x = rand() % 10;
            y = rand() % 10;
        }
        starsSet[i][0] = x;
        starsSet[i][1] = y;

        table1[i][0] = x;
        table1[i][1] = y;

    }

    for (int i = 0; i <= 10; i++) {
        for (int j = 0; j <= 9; j++)
            cout << " ---";

        cout << endl;

        if (i <= 9) {
            for (int k = 0; k <= 10; k++) {
                bool isStar = false;
                bool isSpaceShip = false;
                // Check if the current position is a star
                for (int l = 0; l < 10; l++) {
                    if (i == table1[l][0] && k == table1[l][1]) {
                        isStar = true;
                        ES_count++;
                        break;
                    }
                    else if( i == s && k == z){
                        isSpaceShip = true;
                        break;
                    }

                }
                if (isStar) {
                    cout << "| * ";
                }
                else  if (isSpaceShip){
                    cout << "| @ ";
                }
                else {
                    cout << "|   ";
                }
            }

            cout << endl;
        }
    }
}
}
