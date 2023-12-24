#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;

class Validator {
private:
    string alphabet;
    int current_state;

public:
    Validator() 
    {
        alphabet = "0123456789+-.E/#";
        alphabet[13] = 69;
    }

    void checkString(string input) 
    {
        int transition_table[10][16] = {
            { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }, 
            { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }, 
            { 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 3, 3, 1, 1, 1, 1 },  
            { 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 1, 1, 1, 1, 1 }, 
            { 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 1, 5, 1, 2, 1 }, 
            { 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 1, 1, 1, 1, 1, 1 }, 
            { 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 1, 1, 1, 7, 2, 1 },  
            { 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 8, 8, 1, 1, 1, 1 },
            { 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 1, 1, 1, 1, 1, 1 },  
            { 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 1, 1, 1, 1, 2, 0 }  
        };

        char symbol;
        current_state = 2;

        for (size_t i = 0; i < input.length(); i++) 
        {
            bool is_found = false;
            symbol = input[i];
            if (symbol == -59 || symbol == -123)
                symbol = 69;

            for (int j = 0; j < alphabet.length(); j++) 
            {
                if (symbol == alphabet[j])
                {
                    current_state = transition_table[current_state][j];
                    is_found = true;
                    break;
                }
            }

            if (!is_found)
                current_state = 1;

            if (current_state == 0)
                break;
        }

        if (current_state == 0)
            cout <<  "STRING is RIGHT"  << endl << endl;
        else
            cout << "STRING is WRONG" << endl << endl;
    }
};

void main() 
{
    Validator validator;
    string input_string;

    getline(cin, input_string);
    validator.checkString(input_string);

}
