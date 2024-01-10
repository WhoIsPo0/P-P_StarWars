#include <iostream>
#include <time.h>
#include <conio.h>

using namespace std;

struct GameData
{
    int ship_x, ship_y;
    int table1[10][2];
};

int defineChart(GameData &gameData);
int SaveChart(const GameData &gameData);
void movement(GameData &gameData);
bool updateGame(const GameData &gameData);
void guide(char);

int main()
{
    int Heal = 3;
    GameData gameData;
    srand(time(0));
    defineChart(gameData);

    while (Heal > 0)
    {
        SaveChart(gameData);
        movement(gameData);
        Heal--;
    }

    return 0;
}

int defineChart(GameData &gameData)
{
    int ES_count = 0;

    while (ES_count != 10)
    {
        // Generates random coordinates for spaceship
        gameData.ship_x = rand() % 10;
        gameData.ship_y = rand() % 10;

        // Set of stars to ensure you have exactly 10 stars
        int starsSet[10][2];

        // Generate random coordinates for enemies
        for (int i = 0; i < 10; i++)
        {
            int x = rand() % 10;
            int y = rand() % 10;

            // Ensure the generated coordinates are not the spaceship coordinates or duplicate star coordinates
            while ((x == gameData.ship_x && y == gameData.ship_y) ||
                   (i > 0 && (x == starsSet[i - 1][0] && y == starsSet[i - 1][1])))
            {
                x = rand() % 10;
                y = rand() % 10;
            }
            starsSet[i][0] = x;
            starsSet[i][1] = y;

            gameData.table1[i][0] = x;
            gameData.table1[i][1] = y;
        }

        for (int i = 0; i < 10; i++)
        {
            for (int k = 0; k < 10; k++)
            {
                // Check if the current position is a star or a spaceship
                for (int l = 0; l < 10; l++)
                {
                    if (i == gameData.table1[l][0] && k == gameData.table1[l][1])
                    {
                        ES_count++;
                        break;
                    }
                }
            }
        }
    }

    return 0;
}

int SaveChart(const GameData &gameData)
{
    for (int i = 0; i <= 10; i++)
    {
        for (int j = 0; j < 10; j++)
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
                    if (i == gameData.table1[l][0] && k == gameData.table1[l][1])
                    {
                        isStar = true;
                        break;
                    }
                    else if (i == gameData.ship_x && k == gameData.ship_y)
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
        }

        cout << endl;
    }
}

void movement(GameData &gameData)
{
    char input;
    cout << "Enter w, a, s, d to move, L or R to shoot or enter q to quit: ";
    do
    {
        input = toupper(getch());
        switch (input)
        {
        case 'W':
            if (gameData.ship_x > 0)
            {

                gameData.ship_x--;
                updateGame(gameData);
            }
            else
            {
                guide('w');
            }
            break;
        case 'A':

            if (gameData.ship_y > 0)
            {
                gameData.ship_y--;
                updateGame(gameData);
            }
            else
            {
                guide('a');
            }
            break;
        case 'S':
            if (gameData.ship_x < 9)
            {

                gameData.ship_x++;
                updateGame(gameData);
            }
            else
            {
                guide('s');
            }
            break;
        case 'D':
            if (gameData.ship_y < 9)
            {
                gameData.ship_y++;
                updateGame(gameData);
            }
            else
            {
                guide('d');
            }
            break;
        case 'R': // to do: implement shoot to right
            cout << "R was pressed" << endl;
            updateGame(gameData);
            break;
        case 'L': // to do: implement shoot to left
            cout << "L was pressed" << endl;
            updateGame(gameData);
            break;
        case 'Q':
            cout << "Quitting the game." << endl;
            break;
        default: // Handling invalid input
            cout << "Invalid input. Please enter w, a, s, d, l, r, or q" << endl;
        }
    } while (input != 'Q');
}

bool updateGame(const GameData &gameData)
{
    system("CLS");
    SaveChart(gameData);

    return true;
}
char guideinput;
void guide(char guideinput)
{
    switch (guideinput)
    {
    case 'g': // general guide
        cout << "Enter w, a, s, d to move, L or R to shoot or enter q to quit: " << endl;
        break;
    case 'w': // up guide
        cout << " you cant go up anymore Enter a, s, d to move, L or R to shoot or enter q to quit: " << endl;
        break;
    case 'a': // left guide
        cout << "you cant go left anymore Enter w, s, d to move, L or R to shoot or enter q to quit:  " << endl;
        break;
    case 's': // down guide
        cout << "you cant go down anymore Enter w, a, d to move, L or R to shoot or enter q to quit: " << endl;
        break;
    case 'd': // down guide
        cout << "you cant go right anymore Enter w, a, s to move, L or R to shoot or enter q to quit: " << endl;
        break;
    case 'k': // shoot guide
        cout << "enter l to shoot left enter r to shoot right enter q to quit" << endl;
        break;
    }
}
