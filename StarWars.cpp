#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

using namespace std;

void defineChart();
void PrintChart();
void movement();
void updateGame();
void handleInput(char);

int ship_x, ship_y;
int table1[10][2];
int ship_position[2];

int main()
{
    int Heal = 3;
    srand(time(0));
    defineChart();
    PrintChart();
    movement();

    return 0;
}

void defineChart()
{
    int ES_count = 0;
    while (ES_count != 10)
    {
        table1[10][2];

        // Generates random coordinates for spaceship
        ship_x = (rand() % 10);
        ship_y = (rand() % 10);
        ship_position[ship_x, ship_y];
        // Set of stars to ensure you have exactly 10 stars
        int starsSet[10][2];

        // Generate random coordinates for enemies
        for (int i = 0; i < 10; i++)
        {
            int x = rand() % 10;
            int y = rand() % 10;

            // Ensure the generated coordinates are not the spaceship coordinates or duplicate star coordinates
            while ((x == ship_x && y == ship_y) || (i > 0 && (x == starsSet[i - 1][0] && y == starsSet[i - 1][1])))
            {
                x = rand() % 10;
                y = rand() % 10;
            }
            starsSet[i][0] = x;
            starsSet[i][1] = y;

            table1[i][0] = x;
            table1[i][1] = y;
            ES_count++;
        }
    }
}

void PrintChart()
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
                    else if (i == ship_x && k == ship_y)
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
    cout << "Enter w, a, s, d to move, L or R to shoot or enter q to quit: ";
    do
    {
        input = toupper(getch());
        switch (input)
        {
        case 'W':
            cout << "W was pressed" << endl;
            ship_x--;
            updateGame();
			break;
        case 'A':
            cout << "A was pressed" << endl;
            ship_y--;
            updateGame();
            break;
        case 'S':
            cout << "S was pressed" << endl;
            ship_x++;
            updateGame();
            break;
        case 'D':
            cout << "D was pressed" << endl;
            ship_y++;
            updateGame();
            break;
        case 'R': //todo : complete shoot to right 
            cout << "r was pressed" << endl;
            updateGame();
            break;
        case 'L': //to do : complete shoot to left
            cout << "L was pressed" << endl;
            updateGame();
            break;
        default: // Handling invalid input
            cout << "Invalid input. Please enter w, a, s, d,l or r or q" << endl;
        }
    } while (input != 'Q');
}

void updateGame()
{
    system("CLS"); 
    PrintChart();
}