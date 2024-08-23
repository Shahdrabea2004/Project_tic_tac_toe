#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>
using namespace std;

string Board[3][3]= {{"1","2","3"},{"4","5","6"},{"7","8","9"}};
string Prizes[5]= {"chips", "chocolate", "Gold Pen", "shoes", "cookies"};

void Display_Board()
{
    cout<<"|----|----|----|"<<endl;
    for(int r=0; r<3; r++)
    {
        cout<<"|";
        for(int c=0; c<3; c++)
        {
            cout<<" "<<Board[r][c]<<"  |";
        }
        cout<<endl;
        cout<<"|----|----|----|"<<endl;

    }
}

bool Check_Win()
{
    for(int i=0; i<3; i++)
    {
        if((Board[i][0]==Board[i][1]&&Board[i][1]==Board[i][2])
                ||(Board[0][i]==Board[1][i]&&Board[1][i]==Board[2][i]))
            return true;
    }
    if((Board[0][0]==Board[1][1]&&Board[1][1]==Board[2][2])||
            (Board[0][2]==Board[1][1]&&Board[1][1]==Board[2][0]))
        return true;

    return false;
}

bool Check_Full_or_Tie()
{

    for(int r=0; r<3; r++)
    {
        for(int c=0; c<3; c++)
        {
            if(Board[r][c]!="X"&&Board[r][c]!="O"&&Check_Win()==true)
            {
                return false;
            }
            else
            {
                return true;
            }

        }
    }

}

void Prize()
{
    srand(time(0));
    if(Check_Win)
    {

        int Random_Prize=rand()%5+1;
        cout<<"                                      Congratulations you got it! "<<"* "<<Prizes[Random_Prize]<<" *"<<endl;

    }
}

void Players_Input(string Player_sample)
{
    while(true)
    {
        string Input_Player;
        cout << "Player * "<<Player_sample<<" * please enter the number from the board (1-9): ";
        cin>>Input_Player;
        bool ExitError=false;
        for(int r=0; r<3; r++)
        {
            for(int c=0; c<3; c++)
            {
                if(Board[r][c]==Input_Player)
                {
                    Board[r][c]=Player_sample;
                    ExitError=true;
                    Display_Board();
                    break;
                }

            }
            if(ExitError)
                break;

        }

        if(!ExitError)
        {
            cout << "Invalid move. Number not found or already taken." << endl;

        }
        else
        {
            break;
        }
    }

}

void Player_Computer(string Computer_sample )
{
    srand(time(0));
    while(true)
    {
        int Move=rand()%9+1;
        string Move_str=to_string(Move);
        bool ExitError=false;
        for(int r=0; r<3; r++)
        {
            for(int c=0; c<3; c++)
            {
                if(Board[r][c]==Move_str)
                {
                    Board[r][c]=Computer_sample;
                    ExitError=true;
                    Display_Board();
                    break;
                }
            }
            if(ExitError)
                break;
        }

        if(ExitError)
            break;
    }
}

void Game_X_or_O()
{
    system("COLOR 75");
    string Player1_Symbol,Player2_Symbol;
    cout<<"\n\n\n\n";
    cout<<"                                      Please Enter the Symbol you want (X or O) \n\n";
    cout<<"                                                         ";
    cin>>Player1_Symbol;
    cout<<"\n";
    while(Player1_Symbol!="X"&&Player1_Symbol!="O")
    {

        cout << "                                      Invalid choice. Please choose (X or O) \n\n ";
        cout<<"                                                         ";
        cin>>Player1_Symbol;
        cout<<"\n";

    }
    if(Player1_Symbol=="X")
    {
        Player2_Symbol="O";
    }
    else if(Player1_Symbol=="O")
    {
        Player2_Symbol="X";
    }
    string Against_Who;
    cout << "                             Do you want to play against another player (P) or computer (C)? \n\n";
    cout << "                                                         ";
    cin>>Against_Who;
    cout<<"\n";
    while(Against_Who!="P"&&Against_Who!="C"&&Against_Who!="p"&&Against_Who!="c")
    {
        cout << "                             Do you want to play against another player (P) or computer (C)? \n\n";
        cout << "                                                         ";
        cin>>Against_Who;
        cout<<"\n";

    }
    for(int i=0; i<9; i++)
    {
        system("cls");

        Display_Board();
        if(i%2==0)
        {
            system("COLOR 71");
            Players_Input(Player1_Symbol);

            if(Check_Win())
            {
                system("cls");
                system("COLOR 40");
                Display_Board();
                cout<<"\n";
                cout << "                                                 Player 1 ("<<Player1_Symbol<<") wins!\n\n";
                Prize();
                exit(0);
            }


        }
        else
        {
            if(Against_Who=="C"||Against_Who=="c")
            {
                system("COLOR 70");
                Player_Computer(Player2_Symbol);
                if(Check_Win())
                {
                    system("cls");
                    system("COLOR 40");
                    Display_Board();
                    cout<<"\n";
                    cout << "Computer ("<<Player2_Symbol<<") wins!" << endl;
                    exit(0);
                }
            }
            else if(Against_Who=="P"||Against_Who=="p")
            {
                system("COLOR 70");
                Players_Input(Player2_Symbol);
                if(Check_Win())
                {
                    system("cls");
                    system("COLOR 40");
                    Display_Board();
                    cout<<"\n";
                    cout << "                                                 Player 2 ("<<Player2_Symbol<<") wins!\n\n";
                    Prize();
                    exit(0);
                }
            }

        }


    }
    if(Check_Full_or_Tie())
    {

        system("cls");
        system("COLOR 40");
        Display_Board();
        cout<<"\n";
        cout << "  It's a tie!" << endl;
        exit(0);
    }

}



int main()
{
    cout<<"\n";
    cout<<"                                   * Welcome to our game, the game of x and o *\n";
    cout<<"                 * Please be polite and do not cheat. We hope you and your friends have a good time *\n";
    Game_X_or_O();


}
