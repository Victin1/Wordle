//The header files iostream, string, and random are included.
#include <iostream>
#include <string>
#include <random>
//Under the namespace std, the following lines of code are built.
using namespace std;

//A list of 5-letter words is declared as an array of strings. This list acts as the dictionary of possible words as answers.
string words[] = {"APPLE", "CARES", "DROWN", "ROUNDS", "PERKS", "STAGE", "BRAKE", "POKER", "POWER", "KINGS"};

//A function randword() is declared with return type string, and returns a random string word from the array mentioned.
string randword(){
    random_device gen;
    int randnumb = gen();
    randnumb = abs(randnumb);
    randnumb = randnumb%10;
    return words[randnumb];
}

//2 functions, menu() (return type void) and playagain() (return type void) are declared using forward declaration for use in upcoming functions.
void menu();
void playagain();

//A function playgame() is declared with return type void.
//This function performs the role of displaying each of the 6 rounds of the wordle game.
//This includes the guess made, its relevance with the actual answer and (if required) whether or not the game is over with a loss/win.
//It also includes a user-input feature that allows the user to play again or exit to menu, using the forward-declared playagain() function.
void playgame(){
    string ans = randword();
    for(int x=0; x<6; x++){
        string guess;
        cout<<"---ATTEMPT "<<x+1<<"---\nEnter a 5-letter word: ";
        cin>>guess;
        string anno = "_____";
        int flag1=1; for(int i=0; i<guess.length(); i++){if(isupper(guess[i])==0){flag1=0;}}
        int flag2=0;
        
        if(flag1==0){cout<<"Please enter only UPPERCASE English alphabets.\n\n"; x=x-1; continue;}
        else{
            if(guess.length()!=5){"Please enter only a 5-digit word.\n\n"; x=x-1; continue;}
            else{
                for(int i=0; i<5; i++){
                    if(guess[i]==ans[i]){anno[i]='^';}
                    else{
                        for(int j=0; j<5; j++){
                            if(guess[i]==ans[j]){anno[i]='*'; flag2=1;}
                            else{if(anno[i]!='*'){anno[i]='-';}}
                        }
                    }
                }
            }
        }
        cout<<guess<<endl<<anno<<endl<<endl;
        
        if(x==5 && anno!="^^^^^"){cout<<"Awww, you're out of attempts.\nThe word was "<<ans<<"\nBetter luck next time!\n"; break;}
        if(anno=="^^^^^"){
            if(x==0){cout<<"Wow! You found the word "<<ans<<" on your first attempt! Congratulations\n";}
            else{cout<<"Congratulations! You found the word "<<ans<<" within "<<x+1<<" attempts!\n";}
            break;
        }
    }
    playagain();
}

//The forward-declared playagain() function is defined to perfoem the function of displaying the options to either:
//play again or return to the main menu and taking in the user input to do so.
void playagain(){
    cout<<"\nWould you like to play again? Enter y for Yes and n for no: ";
    char yn; cin>>yn;
    if(yn=='y'||yn=='Y'){cout<<"\nOkay, let's go again!\n\n";playgame();}
    else{if(yn=='n'||yn=='N'){cout<<"\nAlright then, you have been redirected to the menu!\n"; menu();}
        else{cout<<"\nSorry! Unfortunately you have not selected a mentioned option. Please try again.\n"; playagain();}
    }
}

//A function howtoplay() is declared with return type void, and defined to perform the function of displaying the rules and simple explanataion of the game.
//This is done in a readable format, and allows the user to return to menu by calling the forwad-declared menu() function using user input.
void howtoplay(){
    cout<<"Here is a simple explanation as to how to play Wordle:"<<endl<<"There is a secret 5-letter word which will not be revealed until the end of the game. The objective of the game is for you to guess that word within 6 tries.\n";
    cout<<"In each of the 6 attempts, you are allowed to guess a valid 5-letter word. Your guess will then be displayed back to you with the following annotations under each letter:\n";
    cout<<"- means that the letter does not appear in the secret word at all.\n";
    cout<<"* means that the letter appears in the secret word but not in the guessed position.\n";
    cout<<"^ means that the letter appears in that position in the secret word.\n";
    cout<<"The game ends either when you guess the word correctly or if you are unable to within 6 tries.\n\n";
    cout<<"Please enter the ESC key to return to the menu: "; char esc; cin>>esc;
    if(esc=='\e'){cout<<"\nAlright then, you have been redirected to the menu!\n"; menu();} else{cout<<"Sorry! Unfortunately you have not selected a mentioned option. Please try again.\n"; howtoplay();}
}

//A function quit() is declared witj return type void, and defined to perform the function of asking the user if leaving the game is intentional,
//and offers the user 2 options (Yes or No) and either:
//exits the game (terminating the program) or returns to the main menu by calling the forward-declared menu function respective to the user input.
void quit(){
    cout<<"Are you sure you want to exit? Enter y for Yes and n for No: ";
    char yn; cin>>yn;
    if(yn=='y'||yn=='Y'){cout<<"Thank you for playing!"; exit(0);}
    else{if(yn=='n'||yn=='N'){cout<<"\nAlright then, you have been redirected to the menu!\n"; menu();}
        else{cout<<"\nSorry! Unfortunately you have not selected a mentioned option. Please try again.\n"; quit();}
    }
}

//The forward-declared menu() function is defined to perform the function of displaying 3 options (PLAY, HOW TO PLAY, EXIT),
//each of which can be selected by the user by inputting their allotted number.
//Based on the input, using a switch-case algorithm, the respective function (playgame(), howtoplay(), quit()) is called,
//with the default case returning to the menu again by calling the menu() function (similar to recursive syntax).
void menu(){
        cout<<"Please select one of the following options, by entering the respective number:\n";
        cout<<"1. PLAY"<<endl<<"2. HOW TO PLAY"<<endl<<"3. EXIT\n";
        char c; string cstring;
        cin>>cstring; if(cstring.length()==1){c = cstring[0];} else{c=4;}
        switch(c){
            case '1': playgame(); break;
            case '2': howtoplay(); break;
            case '3': quit(); break;
            default: cout<<"\nSorry! Unfortunately you have not selected a mentioned option. Please try again.\n"; menu(); break;
        }
}

//The main() function is declared with return type int, and defined to display a greeting message and then calling the menu() function.
int main(){
    cout<<"Welcome to Wordle!\n";
    menu();
    //Finally, the main() function is closed by returning the integer 0.
    return 0;
}
