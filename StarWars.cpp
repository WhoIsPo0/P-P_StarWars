#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

using namespace std;

void Chart();
void s_chart();
void attack();
void movement();

int s, z;
int table1[10][2];

int main()
{
    int Heal = 0;
    srand(time(0));
    Chart();
    for (int i = 0; i < 3; i++)
    {
        s_chart();
        cout << "Do you want to ATTACK ?(Press Y/N)";
        cout << "Do you want to MOVE ?(Press L/R)";
        Heal++;
    }
    return 0;
}

void Chart()
{
    int ES_count = 0;
    while (ES_count != 10)
    {
        table1[10][2];

        // Generates random coordinates for spaceship
        s = (rand() % 10);
        z = (rand() % 10);

        // Set of stars to ensure you have exactly 10 stars
        int starsSet[10][2];

        // Generate random coordinates for enemies
        for (int i = 0; i < 10; i++)
        {
            int x = rand() % 10;
            int y = rand() % 10;

            // Ensure the generated coordinates are not the spaceship coordinates or duplicate star coordinates
            while ((x == s && y == z) || (i > 0 && (x == starsSet[i - 1][0] && y == starsSet[i - 1][1])))
            {
                x = rand() % 10;
                y = rand() % 10;
            }
            starsSet[i][0] = x;
            starsSet[i][1] = y;

            table1[i][0] = x;
            table1[i][1] = y;
        }

        for (int i = 0; i <= 10; i++)
        {
            for (int j = 0; j <= 9; j++)
                cout << " ---";

            cout << endl;

            if (i <= 9)
            {
                for (int k = 0; k <= 10; k++)
                {
                    bool isStar = false;
                    bool isSpaceShip = false;
                    // Check if the current position is a star or a spaceship
                    for (int l = 0; l < 10; l++)
                    {
                        if (i == table1[l][0] && k == table1[l][1])
                        {
                            isStar = true;
                            ES_count++;
                            break;
                        }
                        else if (i == s && k == z)
                        {
                            isSpaceShip = true;
                            break;
                        }
                    }
                    if (isStar)
                    {
                        cout << "| * ";
                    }
                    else if (isSpaceShip)
                    {
                        cout << "| @ ";
                    }
                    else
                    {
                        cout << "|   ";
                    }
                }

                cout << endl;
            }
        }
    }
}

void s_chart()
{
    for (int i = 0; i <= 10; i++)
    {
        for (int j = 0; j <= 9; j++)
            cout << " ---";

        cout << endl;

        if (i <= 9)
        {
            for (int k = 0; k <= 10; k++)
            {
                bool isStar = false;
                bool isSpaceShip = false;
                // Check if the current position is a star or a spaceship
                for (int l = 0; l < 10; l++)
                {
                    if (i == table1[l][0] && k == table1[l][1])
                    {
                        isStar = true;
                        break;
                    }
                    else if (i == s && k == z)
                    {
                        isSpaceShip = true;
                        break;
                    }
                }
                if (isStar)
                {
                    cout << "| * ";
                }
                else if (isSpaceShip)
                {
                    cout << "| @ ";
                }
                else
                {
                    cout << "|   ";
                }
            }

            cout << endl;
        }
    }
}

void movement()
{
    char input;
    cout << "Enter w, a, s, d to move, or enter q to quit: ";
    do
    {
        input = toupper(getch());
        switch (input)
        {
        case 'W':
            cout << "W was pressed" << endl;
            break;
        case 'A':
            cout << "A was pressed" << endl;
            break;
        case 'S':
            cout << "S was pressed" << endl;
            break;
        case 'D':
            cout << "D was pressed" << endl;
            break;
        default: // Handling invalid input
            cout << "Invalid input. Please enter w, a, s, d, or q" << endl;
        }
    } while (input != 'Q');
}
