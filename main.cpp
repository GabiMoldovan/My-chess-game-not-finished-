///##########################################################################################*
///        #####    #     #     ##   ###    ###     ###        ###
///        #        ##   ##    # #      #      #   ## #        ###
///        # ###    # # # #   #  #   ####   ####      #        ###
///        #   #    #  #  #      #      #      #     ###       ###
///        #####    #     #      #   ###    ###       #        ###
///##########################################################################################*

#include <bits/stdc++.h>
#define _WIN32_WINNT 0x0500
#include <windows.h>
#define Size 60

using namespace std;

unsigned long long int Moves;

void Instructions();
void PrintTable();
void StartTheGame();
void InitializeTable();
void doTheMove();
void ThePieceInThisPosition(char piesa[5]);

bool IsAbleToMove(char CurrPos[], char ToPos[]);
bool goodMove(char theMove[15]);
bool checkTeam(char piece);

int Translate(char piece[5], int pos);

struct Pieces
{
    char Piece[5];
    unsigned int Elims;
} fakeTable[9][9];

int main()
{
    RECT r;
    HWND console = GetConsoleWindow();
    GetWindowRect(console, &r); //stores the console's current dimensions
    MoveWindow(console, r.left, r.top, 600, 800, TRUE);
    StartTheGame();
}

void StartTheGame()
{
    char NeedHelp;
    InitializeTable();
    PrintTable();
    _sleep(2500);
    cout<<"\n\nBefore we start the game, do you have any questions?";
    _sleep(1500);
    cout<<"\n\n";
    cout<<"Type Y if so, else type N: ";
    cin>>NeedHelp;
    if(NeedHelp=='Y' || NeedHelp=='y') Instructions();
    PrintTable();

    bool GameOver=false;
    while(!GameOver)
    {
        ++Moves;
        cout<<"\nPlayer's "<<(Moves%2==0 ? "2":"1")<<" turn\n";
        doTheMove();
    }
    exit(0);
}

void doTheMove()
{
    char piece[55];
    char to[55];
    cout<<"Select the position of the piece you want to move: ";
    cin>>piece;
    while(goodMove(piece)==false)
    {
        cin>>piece;
    }
    cout<<"Select where you want to move it: ";
    cin>>to;
    while(goodMove(to)==false)
    {
        cin>>to;
    }
    swap(fakeTable[Translate(piece,1)][Translate(piece,0)], fakeTable[Translate(to,1)][Translate(to,0)]);
    PrintTable();
    //exit(0);
}

bool goodMove(char theMove[55])  /// broken
{
    if(strlen(theMove)!=2)
    {
        cout<<"\nYour move lenght is incorrect, please enter the move again: ";
        return false;
    }
    if( !strchr("ABCDEFGH",theMove[0])  &&  !strchr("abcdefgh",theMove[0]) )
    {
        cout<<"\nYou selected a wrong raw, please enter the raw again: ";
        return false;
    }
    if(!strchr("12345678",theMove[1]))
    {
        cout<<"\nYou selected a wrong line, please enter the line again: ";
        return false;
    }
    return true;
}

int Translate(char piece[5], int pos)
{
    if(pos==0)
    {
        if(piece[0]=='A' || piece[0]=='a') return 1;
        if(piece[0]=='B' || piece[0]=='b') return 2;
        if(piece[0]=='C' || piece[0]=='c') return 3;
        if(piece[0]=='D' || piece[0]=='d') return 4;
        if(piece[0]=='E' || piece[0]=='e') return 5;
        if(piece[0]=='F' || piece[0]=='f') return 6;
        if(piece[0]=='G' || piece[0]=='g') return 7;
        if(piece[0]=='H' || piece[0]=='h') return 8;
    }
    else return (9-(piece[1]-'0'));
}

void Instructions()
{
    cout<<"\n\n\n";
    // QUESTIONS:
    cout<<"Select a question by typing it's number.\n";
    _sleep(2000); // 3 sec
    cout<<"0. I changed my mind, I don't have any question.\n";
    _sleep(500);
    cout<<"1. How do I move a piece?\n";
    _sleep(500);
    cout<<"2. I don't know how a piece work.\n";
    _sleep(500);
    cout<<"3. I don't know what a piece is.\n";
    unsigned short question;
    char piece;
    cout<<"\nPlease type the question number: ";
    cin>>question;
    cout<<"\n";
    if(question==0) return;
    else if(question==1)
    {
        cout<<"To move a piece simply type it's position(letter,number), ' to ' and the position you want to place it.\n";
        _sleep(2000);
        cout<<"An exemple: 'b0 to a2'\n";
        _sleep(500);
        cout<<"You don't have to use uppercase letters.\n";
    }
    else if(question==3)
    {
        cout<<"Please type the letter of the piece: ";
        cin>>piece;
        cout<<"\n";
        if(piece=='R') //Tura - Rook
        {
            cout<<"R stands for the Rook\n";
            _sleep(500);
        }
        else if(piece=='N') //Cal
        {
            cout<<"N stands for the Horse\n";
            _sleep(500);
        }
        else if(piece=='B') //Nebun
        {
            cout<<"B stands for the Bishop\n";
            _sleep(500);
        }
        else if(piece=='Q') //Regina
        {
            cout<<"Q stands for the Queen\n";
            _sleep(500);
        }
        else if(piece=='K') //Rege
        {
            cout<<"K stands for the King\n";
            _sleep(500);
        }
        else if(piece=='P') //Pion
        {
            cout<<"P stands for the Pawn\n";
            _sleep(500);
        }
    }
    _sleep(4500);
    char StillNeedHelp;
    cout<<"If you have another question please type Y/N: ";
    cin>>StillNeedHelp;
    if(StillNeedHelp=='Y') Instructions();
}

void InitializeTable()
{

    /// TEAM 1 (The upper team)

    // Tura 1
    strcpy(fakeTable[1][1].Piece,"R1");
    fakeTable[1][1].Elims=0;

    //Cal 1
    strcpy(fakeTable[1][2].Piece,"N1");
    fakeTable[1][2].Elims=0;

    //Nebun 1
    strcpy(fakeTable[1][3].Piece,"B1");
    fakeTable[1][3].Elims=0;

    //Regina
    fakeTable[1][4].Piece[0]='Q';
    fakeTable[1][4].Piece[1]='\0';
    fakeTable[1][4].Elims=0;

    //Rege
    fakeTable[1][5].Piece[0]='K';
    fakeTable[1][5].Piece[1]='\0';
    fakeTable[1][5].Elims=0;

    //Nebun 2
    strcpy(fakeTable[1][6].Piece,"B2");
    fakeTable[1][6].Elims=0;

    //Cql 2
    strcpy(fakeTable[1][7].Piece,"N2");
    fakeTable[1][7].Elims=0;

    //Tura 2
    strcpy(fakeTable[1][8].Piece,"R2");
    fakeTable[1][8].Elims=0;

    //Pioni Team 1
    strcpy(fakeTable[2][1].Piece,"P1");
    fakeTable[2][1].Elims=0;
    strcpy(fakeTable[2][2].Piece,"P2");
    fakeTable[2][2].Elims=0;
    strcpy(fakeTable[2][3].Piece,"P3");
    fakeTable[2][3].Elims=0;
    strcpy(fakeTable[2][4].Piece,"P4");
    fakeTable[2][4].Elims=0;
    strcpy(fakeTable[2][5].Piece,"P5");
    fakeTable[2][5].Elims=0;
    strcpy(fakeTable[2][6].Piece,"P6");
    fakeTable[2][6].Elims=0;
    strcpy(fakeTable[2][7].Piece,"P7");
    fakeTable[2][7].Elims=0;
    strcpy(fakeTable[2][8].Piece,"P8");
    fakeTable[2][8].Elims=0;

    /// TEAM 0 (The lower team)

    //Pioni Team 0
    strcpy(fakeTable[7][1].Piece,"p1");
    fakeTable[7][1].Elims=0;
    strcpy(fakeTable[7][2].Piece,"p2");
    fakeTable[7][2].Elims=0;
    strcpy(fakeTable[7][3].Piece,"p3");
    fakeTable[7][3].Elims=0;
    strcpy(fakeTable[7][4].Piece,"p4");
    fakeTable[7][4].Elims=0;
    strcpy(fakeTable[7][5].Piece,"p5");
    fakeTable[7][5].Elims=0;
    strcpy(fakeTable[7][6].Piece,"p6");
    fakeTable[7][6].Elims=0;
    strcpy(fakeTable[7][7].Piece,"p7");
    fakeTable[7][7].Elims=0;
    strcpy(fakeTable[7][8].Piece,"p8");
    fakeTable[7][8].Elims=0;

    // Tura 1
    strcpy(fakeTable[8][1].Piece,"r1");
    fakeTable[8][1].Elims=0;

    //Cal 1
    strcpy(fakeTable[8][2].Piece,"n1");
    fakeTable[8][2].Elims=0;

    //Nebun 1
    strcpy(fakeTable[8][3].Piece,"b1");
    fakeTable[8][3].Elims=0;

    //Regina
    fakeTable[8][4].Piece[0]='q';
    fakeTable[8][4].Piece[1]='\0';
    fakeTable[8][4].Elims=0;

    //Rege
    fakeTable[8][5].Piece[0]='k';
    fakeTable[8][5].Piece[1]='\0';
    fakeTable[8][5].Elims=0;

    //Nebun 2
    strcpy(fakeTable[8][6].Piece,"b2");
    fakeTable[8][6].Elims=0;

    //Cql 2
    strcpy(fakeTable[8][7].Piece,"n2");
    fakeTable[8][7].Elims=0;

    //Tura 2
    strcpy(fakeTable[8][8].Piece,"r2");
    fakeTable[8][8].Elims=0;

    // Spatii goale
    strcpy(fakeTable[3][1].Piece," ");
    strcpy(fakeTable[3][2].Piece," ");
    strcpy(fakeTable[3][3].Piece," ");
    strcpy(fakeTable[3][4].Piece," ");
    strcpy(fakeTable[3][5].Piece," ");
    strcpy(fakeTable[3][6].Piece," ");
    strcpy(fakeTable[3][7].Piece," ");
    strcpy(fakeTable[3][8].Piece," ");
    strcpy(fakeTable[4][1].Piece," ");
    strcpy(fakeTable[4][2].Piece," ");
    strcpy(fakeTable[4][3].Piece," ");
    strcpy(fakeTable[4][4].Piece," ");
    strcpy(fakeTable[4][5].Piece," ");
    strcpy(fakeTable[4][6].Piece," ");
    strcpy(fakeTable[4][7].Piece," ");
    strcpy(fakeTable[4][8].Piece," ");
    strcpy(fakeTable[5][1].Piece," ");
    strcpy(fakeTable[5][2].Piece," ");
    strcpy(fakeTable[5][3].Piece," ");
    strcpy(fakeTable[5][4].Piece," ");
    strcpy(fakeTable[5][5].Piece," ");
    strcpy(fakeTable[5][6].Piece," ");
    strcpy(fakeTable[5][7].Piece," ");
    strcpy(fakeTable[5][8].Piece," ");
    strcpy(fakeTable[6][1].Piece," ");
    strcpy(fakeTable[6][2].Piece," ");
    strcpy(fakeTable[6][3].Piece," ");
    strcpy(fakeTable[6][4].Piece," ");
    strcpy(fakeTable[6][5].Piece," ");
    strcpy(fakeTable[6][6].Piece," ");
    strcpy(fakeTable[6][7].Piece," ");
    strcpy(fakeTable[6][8].Piece," ");
}


void PrintTable()
{
    cout<<"This is the Chess Table:\n\n";

    _sleep(1000);

    cout<<"      A     B     C     D     E     F     G     H\n";
    cout<<"   #################################################\n";
    cout<<"   #     #     #     #     #     #     #     #     #\n";
    cout<<" 8 #  "; ThePieceInThisPosition(fakeTable[1][1].Piece); cout<<"  #  "; ThePieceInThisPosition(fakeTable[1][2].Piece); cout<<"  #  "; ThePieceInThisPosition(fakeTable[1][3].Piece); cout<<"  #  "; ThePieceInThisPosition(fakeTable[1][4].Piece); cout<<"  #  "; ThePieceInThisPosition(fakeTable[1][5].Piece); cout<<"  #  "; ThePieceInThisPosition(fakeTable[1][6].Piece); cout<<"  #  "; ThePieceInThisPosition(fakeTable[1][7].Piece); cout<<"  #  "; ThePieceInThisPosition(fakeTable[1][8].Piece); cout<<"  #\n";
    cout<<"   #     #     #     #     #     #     #     #     #\n";
    cout<<"   #################################################\n";
    cout<<"   #     #     #     #     #     #     #     #     #\n";
    cout<<" 7 #  "; ThePieceInThisPosition(fakeTable[2][1].Piece); cout<<"  #  "; ThePieceInThisPosition(fakeTable[2][2].Piece); cout<<"  #  "; ThePieceInThisPosition(fakeTable[2][3].Piece); cout<<"  #  "; ThePieceInThisPosition(fakeTable[2][4].Piece); cout<<"  #  "; ThePieceInThisPosition(fakeTable[2][5].Piece); cout<<"  #  "; ThePieceInThisPosition(fakeTable[2][6].Piece); cout<<"  #  "; ThePieceInThisPosition(fakeTable[2][7].Piece); cout<<"  #  "; ThePieceInThisPosition(fakeTable[2][8].Piece); cout<<"  #\n";
    cout<<"   #     #     #     #     #     #     #     #     #\n";
    cout<<"   #################################################\n";
    cout<<"   #     #     #     #     #     #     #     #     #\n";
    cout<<" 6 #  "; ThePieceInThisPosition(fakeTable[3][1].Piece); cout<<"  #  "; ThePieceInThisPosition(fakeTable[3][2].Piece); cout<<"  #  "; ThePieceInThisPosition(fakeTable[3][3].Piece); cout<<"  #  "; ThePieceInThisPosition(fakeTable[3][4].Piece); cout<<"  #  "; ThePieceInThisPosition(fakeTable[3][5].Piece); cout<<"  #  "; ThePieceInThisPosition(fakeTable[3][6].Piece); cout<<"  #  "; ThePieceInThisPosition(fakeTable[3][7].Piece); cout<<"  #  "; ThePieceInThisPosition(fakeTable[3][8].Piece); cout<<"  #\n";
    cout<<"   #     #     #     #     #     #     #     #     #\n";
    cout<<"   #################################################\n";
    cout<<"   #     #     #     #     #     #     #     #     #\n";
    cout<<" 5 #  "; ThePieceInThisPosition(fakeTable[4][1].Piece); cout<<"  #  "; ThePieceInThisPosition(fakeTable[4][2].Piece); cout<<"  #  "; ThePieceInThisPosition(fakeTable[4][3].Piece); cout<<"  #  "; ThePieceInThisPosition(fakeTable[4][4].Piece); cout<<"  #  "; ThePieceInThisPosition(fakeTable[4][5].Piece); cout<<"  #  "; ThePieceInThisPosition(fakeTable[4][6].Piece); cout<<"  #  "; ThePieceInThisPosition(fakeTable[4][7].Piece); cout<<"  #  "; ThePieceInThisPosition(fakeTable[4][8].Piece); cout<<"  #\n";
    cout<<"   #     #     #     #     #     #     #     #     #\n";
    cout<<"   #################################################\n";
    cout<<"   #     #     #     #     #     #     #     #     #\n";
    cout<<" 4 #  "; ThePieceInThisPosition(fakeTable[5][1].Piece); cout<<"  #  "; ThePieceInThisPosition(fakeTable[5][2].Piece); cout<<"  #  "; ThePieceInThisPosition(fakeTable[5][3].Piece); cout<<"  #  "; ThePieceInThisPosition(fakeTable[5][4].Piece); cout<<"  #  "; ThePieceInThisPosition(fakeTable[5][5].Piece); cout<<"  #  "; ThePieceInThisPosition(fakeTable[5][6].Piece); cout<<"  #  "; ThePieceInThisPosition(fakeTable[5][7].Piece); cout<<"  #  "; ThePieceInThisPosition(fakeTable[5][8].Piece); cout<<"  #\n";
    cout<<"   #     #     #     #     #     #     #     #     #\n";
    cout<<"   #################################################\n";
    cout<<"   #     #     #     #     #     #     #     #     #\n";
    cout<<" 3 #  "; ThePieceInThisPosition(fakeTable[6][1].Piece); cout<<"  #  "; ThePieceInThisPosition(fakeTable[6][2].Piece); cout<<"  #  "; ThePieceInThisPosition(fakeTable[6][3].Piece); cout<<"  #  "; ThePieceInThisPosition(fakeTable[6][4].Piece); cout<<"  #  "; ThePieceInThisPosition(fakeTable[6][5].Piece); cout<<"  #  "; ThePieceInThisPosition(fakeTable[6][6].Piece); cout<<"  #  "; ThePieceInThisPosition(fakeTable[6][7].Piece); cout<<"  #  "; ThePieceInThisPosition(fakeTable[6][8].Piece); cout<<"  #\n";
    cout<<"   #     #     #     #     #     #     #     #     #\n";
    cout<<"   #################################################\n";
    cout<<"   #     #     #     #     #     #     #     #     #\n";
    cout<<" 2 #  "; ThePieceInThisPosition(fakeTable[7][1].Piece); cout<<"  #  "; ThePieceInThisPosition(fakeTable[7][2].Piece); cout<<"  #  "; ThePieceInThisPosition(fakeTable[7][3].Piece); cout<<"  #  "; ThePieceInThisPosition(fakeTable[7][4].Piece); cout<<"  #  "; ThePieceInThisPosition(fakeTable[7][5].Piece); cout<<"  #  "; ThePieceInThisPosition(fakeTable[7][6].Piece); cout<<"  #  "; ThePieceInThisPosition(fakeTable[7][7].Piece); cout<<"  #  "; ThePieceInThisPosition(fakeTable[7][8].Piece); cout<<"  #\n";
    cout<<"   #     #     #     #     #     #     #     #     #\n";
    cout<<"   #################################################\n";
    cout<<"   #     #     #     #     #     #     #     #     #\n";
    cout<<" 1 #  "; ThePieceInThisPosition(fakeTable[8][1].Piece); cout<<"  #  "; ThePieceInThisPosition(fakeTable[8][2].Piece); cout<<"  #  "; ThePieceInThisPosition(fakeTable[8][3].Piece); cout<<"  #  "; ThePieceInThisPosition(fakeTable[8][4].Piece); cout<<"  #  "; ThePieceInThisPosition(fakeTable[8][5].Piece); cout<<"  #  "; ThePieceInThisPosition(fakeTable[8][6].Piece); cout<<"  #  "; ThePieceInThisPosition(fakeTable[8][7].Piece); cout<<"  #  "; ThePieceInThisPosition(fakeTable[8][8].Piece); cout<<"  #\n";
    cout<<"   #     #     #     #     #     #     #     #     #\n";
    cout<<"   #################################################\n";
}

void ThePieceInThisPosition(char piesa[5])
{
    if(strcmp(piesa,"R1")==0) cout<<"R";
    else if(strcmp(piesa,"N1")==0) cout<<"N";
    else if(strcmp(piesa,"B1")==0) cout<<"B";
    else if(strcmp(piesa,"K")==0) cout<<"K";
    else if(strcmp(piesa,"Q")==0) cout<<"Q";
    else if(strcmp(piesa,"R2")==0) cout<<"R";
    else if(strcmp(piesa,"N2")==0) cout<<"N";
    else if(strcmp(piesa,"B2")==0) cout<<"B";
    else if(strcmp(piesa,"P1")==0) cout<<"P";
    else if(strcmp(piesa,"P2")==0) cout<<"P";
    else if(strcmp(piesa,"P3")==0) cout<<"P";
    else if(strcmp(piesa,"P4")==0) cout<<"P";
    else if(strcmp(piesa,"P5")==0) cout<<"P";
    else if(strcmp(piesa,"P6")==0) cout<<"P";
    else if(strcmp(piesa,"P7")==0) cout<<"P";
    else if(strcmp(piesa,"P8")==0) cout<<"P";
    else if(strcmp(piesa,"r1")==0) cout<<"r";
    else if(strcmp(piesa,"n1")==0) cout<<"n";
    else if(strcmp(piesa,"b1")==0) cout<<"b";
    else if(strcmp(piesa,"k")==0) cout<<"k";
    else if(strcmp(piesa,"q")==0) cout<<"q";
    else if(strcmp(piesa,"r2")==0) cout<<"r";
    else if(strcmp(piesa,"n2")==0) cout<<"n";
    else if(strcmp(piesa,"b2")==0) cout<<"b";
    else if(strcmp(piesa,"p1")==0) cout<<"p";
    else if(strcmp(piesa,"p2")==0) cout<<"p";
    else if(strcmp(piesa,"p3")==0) cout<<"p";
    else if(strcmp(piesa,"p4")==0) cout<<"p";
    else if(strcmp(piesa,"p5")==0) cout<<"p";
    else if(strcmp(piesa,"p6")==0) cout<<"p";
    else if(strcmp(piesa,"p7")==0) cout<<"p";
    else if(strcmp(piesa,"p8")==0) cout<<"p";
    else if(strcmp(piesa," ")==0) cout<<" ";
    else cout<<"ERROR";
}


/*
This is the Chess Table:

      A     B     C     D     E     F     G     H
   #################################################
   #     #     #     #     #     #     #     #     #
 8 #  R  #  N  #  B  #  Q  #  K  #  B  #  N  #  R  #
   #     #     #     #     #     #     #     #     #
   #################################################
   #     #     #     #     #     #     #     #     #
 7 #  P  #  P  #  P  #  P  #  P  #  P  #  P  #  P  #
   #     #     #     #     #     #     #     #     #
   #################################################
   #     #     #     #     #     #     #     #     #
 6 #     #     #     #     #     #     #     #     #
   #     #     #     #     #     #     #     #     #
   #################################################
   #     #     #     #     #     #     #     #     #
 5 #     #     #     #     #     #     #     #     #
   #     #     #     #     #     #     #     #     #
   #################################################
   #     #     #     #     #     #     #     #     #
 4 #     #     #     #     #     #     #     #     #
   #     #     #     #     #     #     #     #     #
   #################################################
   #     #     #     #     #     #     #     #     #
 3 #     #     #     #     #     #     #     #     #
   #     #     #     #     #     #     #     #     #
   #################################################
   #     #     #     #     #     #     #     #     #
 2 #  p  #  p  #  p  #  p  #  p  #  p  #  p  #  p  #
   #     #     #     #     #     #     #     #     #
   #################################################
   #     #     #     #     #     #     #     #     #
 1 #  r  #  n  #  b  #  q  #  k  #  b  #  n  #  r  #
   #     #     #     #     #     #     #     #     #
   #################################################


Before we start the game, do you have any questions?
*/

