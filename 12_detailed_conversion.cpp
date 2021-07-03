/*  
    In this program I use some very basic functions and no <string> (concatinate strings or chars) 
    for this problem. This base conversion problem is a question in a "C++ tutorial" book. I found
    this algorithm to solve this and implemet it with almost nothing in C++.
*/

#include <iostream>
using namespace std;

int main()
{
    cout << "__change integer base(2-16)__\n\n"
         << "NOTE: valid chars are \"0123456789ABCDEF\".\n\n";

    int inp_len, inp_base, out_base;
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
    bool z = true;
    while (inp_len > 0) // convert input number to a base_10 number
    {
        chr = cin.get();
        if (chr > char(inp_base + ((inp_base < 10) ? ASCII_DIGIT_START : (ASCII_ALPHABET_START - 10))))
        {
            cout << "\ninvalid digit for base " << inp_base << ".\n";
            return 0;
        }
        if (z)
        {
            cout << "\n\t|  STEP 1:"
                 << "\n\t|  convert each base_" << inp_base << " input chars to base_10"
                 << "\n\t|  values and plus theme together";
            z = false;
        }
        cout << "\n\t|  " << chr << " -> ";
        chr2val = int(chr) - (chr < 'A' ? ASCII_DIGIT_START : (ASCII_ALPHABET_START - 10));

        for (i = inp_len - 1; i > 0; i--, chr2val *= inp_base) // EXAMPLE: 123 = 1*10^(3-1) + 2*10^(3-2) + 3*10^(3-3)
            ;
        base_10_val += chr2val; // input number total value (123 = 100 + 20 + 3)
        cout << chr2val;
        inp_len--;
    } // end of conversion to base_10

    cout << "\n\t|  number in base_10 : " << base_10_val << "\n";

    cout << "\n\t|  STEP 2:"
         << "\n\t|  find the first output digit in base_" << out_base << " by"
         << "\n\t|  dividing the value that found in STEP 1 to"
         << "\n\t|  destination base (" << out_base << "):";

    // find the smallest multiple of "out_base" before "base_10_val"
    int power, tmp;
    for (power = 0, tmp = base_10_val; tmp >= out_base; tmp /= out_base, power++)
        cout << "\n\t|  " << tmp << " // " << out_base << " = " << (tmp / out_base);

    for (power = 0, tmp = base_10_val; tmp >= out_base; tmp /= out_base, power++)
        ;

    string out = "";

    cout << " < " << out_base;
    cout << "\n\t|  in base_10 : " << tmp
         << "\n\t|  in base_" << out_base << " : " << char(tmp + ((tmp < 10) ? ASCII_DIGIT_START : ASCII_ALPHABET_START - 10)) << endl;

    out += char(tmp + ((tmp < 10) ? ASCII_DIGIT_START : ASCII_ALPHABET_START - 10));

    cout
        << "\n\t|  STEP 3:"
        << "\n\t|  finding other output digits"
        << "\n\t|  we did above calculation (STEP 2) " << power << " times, so we do"
        << "\n\t|  following calculation " << power << " times too:";

    int x = power, modulo;
    while (x > 0)
    {
        cout << "\n\t|  " << x << ":";
        for (i = x, tmp = base_10_val; i > 0; i--)
        {
            cout << "\n\t|    " << tmp << " // " << out_base << " = " << tmp / out_base << " , " << tmp << " % " << out_base << " = " << tmp % out_base;
            modulo = tmp % out_base;
            tmp /= out_base;
        }
        cout << " (base_" << out_base << ") " << char(modulo + ((modulo < 10) ? ASCII_DIGIT_START : (ASCII_ALPHABET_START - 10)));
        out += char(modulo + ((modulo < 10) ? ASCII_DIGIT_START : (ASCII_ALPHABET_START - 10)));
        x--;
    }

    cout << "\n\n\t|  output : " << out << "  |\n\n";
}