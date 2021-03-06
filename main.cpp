#include <iostream>

using namespace std;

char board[3][3]= {{'1','2','3'}, {'4','5','6'}, {'7','8','9'}};
char current_marker;
int  current_player;
char marker_p1;
char marker_p2;

void drawBoard()
{
    cout << "\n\n\n\n\n";
    cout << "\t\t-------------\n";
    cout << "\t\t| " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << " |\n" << "\t\t-------------" << endl;
    cout << "\t\t| " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << " |\n" << "\t\t-------------" << endl;
    cout << "\t\t| " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << " |\n" << "\t\t-------------" << endl;
    cout << "\n\n\n\n\n";
}

bool placeMarker(int slot, char current_marker)
{
    int row, col;
    if (slot%3==0)
    {
        row= (slot/3)-1;
        col= 2;
    }
    else
    {
        row= slot/3;
        col= (slot%3)-1;
    }
    int index= board[row][col];
    if(index!=marker_p1 && index!=marker_p2)
    {
        board[row][col]= current_marker;
        return true;
    }
    return false;
}

void swap_player_and_marker()
{
    if (current_marker==marker_p1)
    {
        current_marker=marker_p2;
        current_player=2;
    }
    else
    {
        current_marker=marker_p1;
        current_player=1;
    }
}

char winner()
{
    for (int i=0; i<3; ++i)
    {
        if (board[i][0]==board[i][1] && board[i][1]==board[i][2]) return current_player;
        if (board[0][i]==board[1][i] && board[1][i]==board[2][i]) return current_player;
    }
    if (board[0][0]==board[1][1] && board[1][1]==board[2][2]) return current_player;
    if (board[0][2]==board[1][1] && board[1][1]==board[2][0]) return current_player;
    return 0;
}

void game()
{
    cout << "Player 1, choose your marker : ";
    cin >> marker_p1;
    cout << "Player 2, choose your marker : ";
    cin >> marker_p2;
    current_player=1;
    current_marker=marker_p1;
    int tied=1;

    for (int i=0; i<9; ++i)
    {
        cout << "It's player " << current_player << "'s turn. Enter your slot : ";
        int slot;
        cin >> slot;
        bool yn= placeMarker(slot, current_marker);
        while(!yn)
        {
            cout << "That space already occupied please enter another position : ";
            cin >> slot;
            yn= placeMarker(slot, current_marker);
        }
        drawBoard();
        if (winner())
        {
            tied=0;
            cout << "The winner is Player " << current_player << ". Congratulation!\n\n";
            break;
        }
        swap_player_and_marker();
    }
    if (tied) cout << "\t\tGame tied\n\n";
}

int main()
{
    game();

    return 0;
}
