#include <iostream>
using namespace std;

//Prototypes
bool isAcceptedByDFA(string);
void printAcceptedSubstrings(string, int);


//Main Function
int main() {
    //Initialize variables
    string sequence;

    //Prompt and store DNA sequence from user
    cout << "Input a DNA Sequence : ";
    cin >> sequence;

    //Check if original input is accepted by the DFA
    cout << "Input String Is Accepted By the DFA : " << boolalpha << isAcceptedByDFA(sequence) << endl;

    //Find all substrings and print accepted substrings
    cout << "Matching Patterns : " << endl;
    printAcceptedSubstrings(sequence, sequence.length());

}

//To check if argument string is accepted by DFA
bool isAcceptedByDFA(string sequence)
{
    bool isAccepted = false;    //isAccepted set to false before entering for loop
    string state = "S";         //State will start at start

    for(char s : sequence)      //For each loop to check all characters in sequence
    {

        if(state == "1")
        {
            if(s == 'A')
            {
                state = "F";
            }
        }
        if(state == "S")
        {
            if(s == 'A')
            {
                state = "1";
            }
        }

    }

    if(state == "F")
    {
        isAccepted = true;
    }

    return isAccepted;
}

void printAcceptedSubstrings(string sequence, int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 1; j <=n - i; j++)
        {
            string stringToCheck = sequence.substr(i,j);
            if(isAcceptedByDFA(stringToCheck))
            {
                cout << stringToCheck << endl;
            }
        }
    }
}

