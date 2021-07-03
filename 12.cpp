/*  
    In this program I use some very basic functions and no <string> (concatinate strings or chars) 
    for this problem. This base conversion problem is a question in a "C++ tutorial" book. I found
    this algorithm to solve this and implemet it with almost nothing in C++.
*/
#include <iostream>
using namespace std;

int main()
{
    cout << "\t+ -------------------------------------------------- +\n"
         << "\t| For more information  take a  look  at source code |\n"
         << "\t| and compile \"detailed_conversion.cpp\" file         |\n"
         << "\t+ -------------------------------------------------- +\n\n"
         << "__change integer base(2-16)__\n\n"
         << " NOTE : valid chars are \"0123456789ABCDEF\".\n\n";

    int inp_len,
        inp_base, out_base;
    const int ASCII_DIGIT_START = 48;
    const int ASCII_ALPHABET_START = 65;

    cout << "input base : ";
    cin >> inp_base;
    cout << "input length : ";
    cin >> inp_len;
    cout << "output base : ";
    cin >> out_base;
    cout << "number : ";
    cin.ignore();

    char chr;
    int i, chr2val, base_10_val = 0;
    while (inp_len > 0) // convert input number to a base_10 number
    {
        chr = cin.get();
        chr2val = int(chr) - (chr < 'A' ? ASCII_DIGIT_START : (ASCII_ALPHABET_START - 10));

        if (chr2val < inp_base) // check for invalid digit (according to input base)
        {
            for (i = inp_len - 1; i > 0; i--, chr2val *= inp_base) //EXAMPLE: 123 = 1*10^(3-1) + 2*10^(3-2) + 3*10^(3-3)
                ;
            base_10_val += chr2val; // input number total value (123 = 100 + 20 + 3)
            inp_len--;
        }
        else // handle invalid digit
        {
            cout << "\ninvalid digit for base " << inp_base << ".\n";
            inp_len = 0;
            continue;
        }
    } // end of conversion to base_10

    int power, tmp;
    for (power = 0, tmp = base_10_val; tmp >= out_base; tmp /= out_base, power++)
        ;
    cout << "\noutput : " << char(tmp + ((tmp < 10) ? ASCII_DIGIT_START : ASCII_ALPHABET_START - 10));

    while (power > 0) // make other digits of output
    {
        // power starts from "power - 1" because last claculation is "tmp %= out_base;"
        for (i = power - 1, tmp = base_10_val; i > 0; i--, tmp /= out_base)
            ;
        tmp %= out_base;
        cout << char(tmp + ((tmp < 10) ? ASCII_DIGIT_START : ASCII_ALPHABET_START - 10));
        power--;
    }

    cout << endl;
}