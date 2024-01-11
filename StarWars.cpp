#include <iostream>
#include <time.h>
#include <conio.h>

using namespace std;

struct GameData
{
    int ship_x, ship_y;
    int startX, startY;
    int table1[10][2];
    int Heal = 3;
    int enemy = 10;
};

int defineChart(GameData &gameData);
int SaveChart(const GameData &gameData);
void movement(GameData &gameData);
void attack(GameData &gameData);

int main()
{
    GameData gameData;
    srand(time(0));
    defineChart(gameData);

    gameData.startX = gameData.ship_x;
    gameData.startY = gameData.ship_y;

    while (true)
    {
        system("CLS");
        cout << "HEAL : " << gameData.Heal << endl;

        SaveChart(gameData);

        cout << "Do you want to Attack or Move? A or M." << endl;
        char attack_move = toupper(getch());

        if (attack_move == 'A')
        {
            attack(gameData);
        }
        else if (attack_move == 'M')
        {
            movement(gameData);
        }
        else
        {
            cout << "invalid input!!!" << endl;
        }
        if (gameData.Heal == 0)
        {
            cout << "YOU ARE A BIG LOOSER;)";
            break;
        }
        else if (gameData.enemy == 0)
        {
            cout << "YOU WON!!!";
            break;
        }
    }

    return 0;
}

int defineChart(GameData &gameData)
{
    int enemy_count = 0;

    while (enemy_count != 10)
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
                        enemy_count++;
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
    return 0;
}

void movement(GameData &gameData)
{

    cout << " Please enter w, a, s, d or q" << endl;
    char input;

    input = toupper(getch());
    switch (input)
    {
    case 'W':
        if (gameData.ship_x > 0)
        {

            gameData.ship_x--;
        }

        break;
    case 'A':

        if (gameData.ship_y > 0)
        {
            gameData.ship_y--;
        }

        break;
    case 'S':
        if (gameData.ship_x < 9)
        {

            gameData.ship_x++;
        }
        break;
    case 'D':
        if (gameData.ship_y < 9)
        {
            gameData.ship_y++;
        }
        break;
    case 'Q':
        cout << "Quitting the game." << endl;
        break;
    default:
        cout << "Invalid input!!!";
        break;
    }
    for (int i = 0; i < 10; i++)
    {

        if (gameData.ship_x == gameData.table1[i][0] && gameData.ship_y == gameData.table1[i][1])
        {
            gameData.Heal--;
            gameData.enemy--;
            gameData.table1[i][0] = -10;
            gameData.table1[i][1] = -10;
            gameData.ship_x = gameData.startX;
            gameData.ship_y = gameData.startY;
        }
    }
}

void attack(GameData &gameData)
{
    int at_count = 0;

    cout << "where do you want to attack?(you can attack Left with (L) and Right with (R)." << endl;

    char attack_direction = toupper(getch());
    switch (attack_direction)
    {
    case 'L':
        for (int i = 0; i < 10; i++)
        {
            if (at_count == 1)
                break;
            for (int j = gameData.ship_y; j >= 0; j--)
            {
                if (gameData.table1[i][0] == gameData.ship_x && gameData.table1[i][1] == j)
                {
                    gameData.table1[i][0] = -10;
                    gameData.table1[i][1] = -10;
                    gameData.enemy--;
                    at_count = 1;
                    break;
                }
            }
        }
        break;

    case 'R':
        for (int i = 0; i < 10; i++)
        {
            if (at_count == 1)
                break;
            for (int j = gameData.ship_y; j < 10; j++)
            {
                if (gameData.table1[i][0] == gameData.ship_x && gameData.table1[i][1] == j)
                {
                    gameData.table1[i][0] = -10;
                    gameData.table1[i][1] = -10;
                    gameData.enemy--;
                    at_count = 1;
                    break;
                }
            }
        }
        break;

    default:
        cout << "Invalid attack direction!" << endl;
    }
}
