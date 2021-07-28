#include <iostream>
#include <iomanip>
#include <string.h>
#include <string>
#include "windows.h"

using namespace std;

// Определение констант
#define ALPHABET "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define smallShips 3
#define middleShips 2
#define bigShips 1

// Класс отвечающий за игровое поле и манипуляции с ним
class Field
{
private: 
    // Поля класса Field
    int SIZE;
    int N;
    bool isOver;
    int** GAME_FIELD;

    // Метод создания игрового поля и заполнения если нужно (bool)
    void Create_GAME_FIELD(bool opponent = false)
    {
        this->GAME_FIELD = new int* [SIZE];

        for (int i = 0; i < SIZE; i++)
        {
            this->GAME_FIELD[i] = new int[SIZE];
            for (int j = 0; j < SIZE; j++)
            {
                this->GAME_FIELD[i][j] = 0;
            }
        }
        if (opponent == true)
        {
            
        }
        else
        {
            cout << "<-------------------UNFILLED GAME FIELD------------------------>" << endl;
            Output_GAME_FIELD();
            cout << endl;
            Fill_GAME_FIELD();
            system("cls");
            cout << "<---------------SUCCESSFULLY FILLED GAME FIELD----------------->" << endl;
            Output_GAME_FIELD();
            Sleep(5000);
            system("cls");
        }
        


    }

    // Метод заполнения поля с клавиатуры (растановка кораблей на поле)
    void Fill_GAME_FIELD()
    {
        // Маленькие корабли
        int counter = 0;
        cout << "<----- SMALL SHIPS----->" << endl;
        while (counter != smallShips)
        {
            while (true)
            {
                string pos;
                bool flag = false;
                cout << "Ship position: ";
                cin >> pos;
                for (int i = 0; i < SIZE; i++)
                {
                    if (int(pos[1]) - 48 <= SIZE + 1)
                    {
                        if (pos[0] == ALPHABET[i])
                        {
                            this->GAME_FIELD[int(pos[1]) - 48 - 1][i] = 1;
                            cout << "[SUCCESS] Small ship on position " << pos << " DONE" << endl;
                            flag = true;
                            break;
                        }
                    }
                    
                    else
                    {
                        cout << "[ERROR] Retry your position!" << endl;
                        
                    }
                }
                if (flag == true)
                {
                    break;
                }
                else
                {
                    continue;
                }
               
            }
            counter++;
        }
        cout << endl;
        
        // Средние корабли
        counter = 0;
        cout << "<----- MIDDLE SHIPS----->" << endl;
        while (counter != middleShips)
        {
            bool flagFirstShip = false;
            bool flagSecondShip = false;
            string FirstShipPosition;
            while (true)
            {
                string pos;
                bool flag = false;


                cout << "Ship position: ";
                cin >> pos;
                for (int i = 0; i < SIZE; i++)
                {
                    if (int(pos[1]) - 48 <= SIZE + 1)
                    {
                        if (pos[0] == ALPHABET[i])
                        {
                            if (flagFirstShip == false)
                            {
                                flagFirstShip = true;
                                FirstShipPosition = pos;
                                this->GAME_FIELD[int(pos[1]) - 48 - 1][i] = 1;
                                cout << "[SUCCESS] Middle ship dot on position " << pos << " DONE" << endl;
                                
                                break;
                            }
                            else
                            {
                                flagSecondShip = true;
                                this->GAME_FIELD[int(pos[1]) - 48 - 1][i] = 1;
                                cout << "[SUCCESS] Middle ship on position " << pos << " DONE" << endl;
                                flag = true;
                                
                                
                                if (GAME_FIELD[int(pos[1]) - 48 - 1][i] == GAME_FIELD[int(FirstShipPosition[1]) - 48 - 1 + 1][i] ||
                                    GAME_FIELD[int(pos[1]) - 48 - 1][i] == GAME_FIELD[int(FirstShipPosition[1]) - 48 - 1 - 1][i] ||
                                    GAME_FIELD[int(pos[1]) - 48 - 1][i] == GAME_FIELD[int(FirstShipPosition[1]) - 48 - 1][i + 1] ||
                                    GAME_FIELD[int(pos[1]) - 48 - 1][i] == GAME_FIELD[int(FirstShipPosition[1]) - 48 - 1 + 1][i - 1])
                                {
                                    break;
                                }
                                
                            }
                            
                        }
                    }

                    else
                    {
                        cout << "[ERROR] Retry your position!" << endl;

                    }
                }
                if (flag == true)
                {
                    break;
                }
                else
                {
                    continue;
                }

            }
            counter++;
        }
        cout << endl;

        // Большой корабль
        counter = 0;
        cout << "<----- BIG SHIP----->" << endl;
        while (counter != bigShips)
        {
            bool flagFirstShip = false;
            bool flagSecondShip = false;
            bool flagThirdShip = false;
            string FirstShipPosition;
            string SecondShipPosition;
            while (true)
            {
                string pos;
                bool flag = false;


                cout << "Ship position: ";
                cin >> pos;
                for (int i = 0; i < SIZE; i++)
                {
                    if (int(pos[1]) - 48 <= SIZE + 1)
                    {
                        if (pos[0] == ALPHABET[i])
                        {
                            if (flagFirstShip == false)
                            {
                                flagFirstShip = true;
                                FirstShipPosition = pos;
                                this->GAME_FIELD[int(pos[1]) - 48 - 1][i] = 1;
                                cout << "[SUCCESS] BIG ship dot on position " << pos << " DONE" << endl;

                                break;
                            }
                            else
                            {
                                if (flagSecondShip == false)
                                {
                                    flagSecondShip = true;
                                    SecondShipPosition = pos;
                                    this->GAME_FIELD[int(pos[1]) - 48 - 1][i] = 1;
                                    cout << "[SUCCESS] BIG ship dot on position " << pos << " DONE" << endl;



                                    if (GAME_FIELD[int(pos[1]) - 48 - 1][i] == GAME_FIELD[int(FirstShipPosition[1]) - 48 - 1 + 1][i] ||
                                        GAME_FIELD[int(pos[1]) - 48 - 1][i] == GAME_FIELD[int(FirstShipPosition[1]) - 48 - 1 - 1][i] ||
                                        GAME_FIELD[int(pos[1]) - 48 - 1][i] == GAME_FIELD[int(FirstShipPosition[1]) - 48 - 1][i + 1] ||
                                        GAME_FIELD[int(pos[1]) - 48 - 1][i] == GAME_FIELD[int(FirstShipPosition[1]) - 48 - 1 + 1][i - 1])
                                    {
                                        break;
                                    }
                                }
                                if (flagSecondShip == true)
                                {
                                    flagThirdShip = true;

                                    this->GAME_FIELD[int(pos[1]) - 48 - 1][i] = 1;
                                    cout << "[SUCCESS] BIG ship on position " << pos << " DONE" << endl;
                                    flag = true;


                                    if (GAME_FIELD[int(pos[1]) - 48 - 1][i] == GAME_FIELD[int(FirstShipPosition[1]) - 48 - 1 + 1][i] ||
                                        GAME_FIELD[int(pos[1]) - 48 - 1][i] == GAME_FIELD[int(FirstShipPosition[1]) - 48 - 1 - 1][i] ||
                                        GAME_FIELD[int(pos[1]) - 48 - 1][i] == GAME_FIELD[int(FirstShipPosition[1]) - 48 - 1][i + 1] ||
                                        GAME_FIELD[int(pos[1]) - 48 - 1][i] == GAME_FIELD[int(FirstShipPosition[1]) - 48 - 1 + 1][i - 1] ||
                                        GAME_FIELD[int(pos[1]) - 48 - 1][i] == GAME_FIELD[int(SecondShipPosition[1]) - 48 - 1 + 1][i - 1] ||
                                        GAME_FIELD[int(pos[1]) - 48 - 1][i] == GAME_FIELD[int(SecondShipPosition[1]) - 48 - 1 + 1][i + 1] ||
                                        GAME_FIELD[int(pos[1]) - 48 - 1][i] == GAME_FIELD[int(SecondShipPosition[1]) - 48 - 1 + 1 + 1][i] ||
                                        GAME_FIELD[int(pos[1]) - 48 - 1][i] == GAME_FIELD[int(SecondShipPosition[1]) - 48 - 1 + 1 - 1][i])
                                    {
                                        break;
                                    }
                                }
                            }


                        }
                    }
                    else
                    {
                        cout << "[ERROR] Retry your position!" << endl;

                    }
                    
                

                    

            }
                    if (flag == true)
                    {
                        break;
                    }
                    else
                    {
                        continue;
                    }

            }
            counter++;
        }
        
    }
    
public:
    
    // Конструкторы для своего поля
    Field()
    {
        this->isOver = false;
        this->SIZE = 10;
        this->N = 3;
        Create_GAME_FIELD();
    }
    Field(int SIZE, int N)
    {
        this->isOver = false;
        this->SIZE = SIZE;
        this->N = N;
        Create_GAME_FIELD();
    }
    // Конструкторы для чужого поля
    Field(bool opponent)
    {
        this->isOver = false;
        this->SIZE = 10;
        this->N = 3;
        Create_GAME_FIELD(true);
    }
    Field(int SIZE, int N, bool opponent)
    {
        this->isOver = false;
        this->SIZE = SIZE;
        this->N = N;
        Create_GAME_FIELD(true);
    }
 
    // Метод вывода поля в консоль
    void Output_GAME_FIELD()
    {
        // Рисуем разметку символьную сверху
        cout << setw(8) << "";
        for (int i = 0; i < SIZE; i++)
        {
            cout << setw(4) << ALPHABET[i];
        }
        cout << endl;
        cout << setw(8) << "";
        for (int i = 0; i < SIZE; i++)
        {
            cout << setw(4) << "-";
        }
        cout << endl;

        // Рисуем само поле + числовую разметку слева
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                // Рисуем по цифре в каждой строке вначале
                if (j == 0)
                {
                    cout << setw(4) << i + 1;
                    cout << setw(4) << "|";
                }
                if (GAME_FIELD[i][j] == 0)
                {
                    cout << setw(4) << "*";
                }
                else
                {
                    if (GAME_FIELD[i][j] == 1)
                    {
                        cout << setw(4) << "+";
                    }
                    else
                    {
                        if (GAME_FIELD[i][j] == -1)
                        {
                            cout << setw(4) << "X";
                        }
                    }
                }
            }
            cout << endl;
        }
    }
    // Метод проверки наличия кораблей на поле
    void CheckShips()
    {
        bool flag = true;
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                if (this->GAME_FIELD[i][j] == 1)
                {
                    flag = false;
                    this->isOver = false;
                    break;
                }
            }
            if (flag == false)
            {
                break;
            }
            
        }
        
    }
    // Метод, который передает булевое значение если кто-либо победил
    bool NoShips()
    {
        CheckShips();
        return isOver;
    }
    // Метод для выстрелов в корабли на поле
    bool KillShip(string pos, bool flag = false)
    {

        for (int i = 0; i < SIZE; i++)
        {
            if (int(pos[1]) - 48 <= SIZE + 1)
            {
                if (pos[0] == ALPHABET[i])
                {
                    if (this->GAME_FIELD[int(pos[1]) - 48 - 1][i] == 1 || flag == true)
                    {
                        Beep(523, 500);
                        this->GAME_FIELD[int(pos[1]) - 48 - 1][i] = -1;
                        return true;
                    }

                }
            }

            else
            {
                cout << "[ERROR] Retry your position!" << endl;

            }
        }
        return false;
    }
    
};


// Класс Игра - это класс, который имеет режимы игры и моделирует игровой процесс
class Game
{
private:
    int SIZE;
    int N;


public:
    // Конструктор класса без параметров (поумолчанию)
    Game()
    {
        this->SIZE = 10;
        this->N = 3;
        
    }
    // Конструктор класс с параметрами
    Game(int N, int SIZE)
    {

        this->SIZE = SIZE;
        this->N = N;
    }
    // Метод игры в режиме 1 на 1 против противника по очереди
    void GameStart1V1()
    {
        system("color F2");  // Установка белого фона и зеленого текста
        // Поле игрока 1
        cout << "<--------------------------------PLAYER 1 FIELD---------------------------------->\n\n";

        Field* player1 = new Field();
        Field* player1_opponent = new Field(true);



        // Поле игрока 2
        cout << "<--------------------------------PLAYER 2 FIELD---------------------------------->\n\n";
        Field* player2 = new Field();
        Field* player2_opponent = new Field(true);



        // Начало игры
        system("color F5");  // Установка белого фона и зеленого текста
        cout << "<--------------------------------GAME START---------------------------------->\n\n";
        
        bool turn1Player = true;
        bool turn2Player = false;
        string pos;
 
        // Проверка наличия кораблей на полях
        while (!player1->NoShips() && !player2->NoShips())
        {
            if (turn1Player == true)
            {
                turn1Player = false;
                turn2Player = true;

                system("cls");
                cout << " <--------------------------------PLAYER 1 FIELD---------------------------------- >\n\n" << endl;
                player1->Output_GAME_FIELD();
                cout << " <----------------------------PLAYER 2 FIELD (OPPONENT)---------------------------- >\n\n" << endl;
                player1_opponent->Output_GAME_FIELD();
                

                

                cout << "[PLAYER 1] Choose: ";
                cin >> pos;
                if (player2->KillShip(pos))
                {
                    cout << "[PLAYER 1] You succesfully hit opponent ship in pos " << pos << endl;
                    player1_opponent->KillShip(pos, true);
                }
                else
                {
                    cout << "[PLAYER 1] Missed :( " << endl;
                }

                Sleep(7500);


                
            }
            else
            {
                turn1Player = true;
                turn2Player = false;

                system("cls");
                cout << " <--------------------------------PLAYER 2 FIELD---------------------------------- >\n\n" << endl;
                player2->Output_GAME_FIELD();
                cout << " <----------------------------PLAYER 1 FIELD (OPPONENT)---------------------------- >\n\n" << endl;
                player2_opponent->Output_GAME_FIELD();


                cout << "[PLAYER 2] Choose: ";
                cin >> pos;
                if (player1->KillShip(pos))
                {
                    cout << "[PLAYER 2] You succesfully hit opponent ship in pos " << pos << endl;
                    player2_opponent->KillShip(pos, true);
                }
                else
                {
                    cout << "[PLAYER 2] Missed :( " << endl;
                }

                Sleep(7500);
            }
        }

        // Вывод в консоль победителя
        if (!player2->NoShips())
        {
            system("cls");
            cout << "PLAYER 1 HAS WON!!!!! CONGRATULATION!!!" << endl;
        }
        else
        {
            system("cls");
            cout << "PLAYER 2 HAS WON!!!!! CONGRATULATION!!!" << endl;

        }

        

    }
};

int main()
{
    // Создание объекта игры
    Game* obj = new Game();
    // Запуск игры в режиме 1 на 1
    obj->GameStart1V1();      
    
}

