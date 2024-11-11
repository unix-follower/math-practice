#include <iostream>
#include <string>
#include <exception>
#include <math.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

string to_symbolic(unsigned int number)
{
    string output;
    if (number == 1)
    {
        output = "one";
    }
    else if (number == 2)
    {
        output = "two";
    }
    else if (number == 3)
    {
        output = "three";
    }
    else if (number == 4)
    {
        output = "four";
    }
    else if (number == 5)
    {
        output = "five";
    }
    else if (number == 6)
    {
        output = "six";
    }
    else if (number == 7)
    {
        output = "seven";
    }
    else if (number == 8)
    {
        output = "eight";
    }
    else if (number == 9)
    {
        output = "nine";
    }
    else
    {
        output = "Greater than 9";
    }

    return output;
}

int main()
{
    string n_temp;
    getline(std::cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    if (n < 1 || n > pow(10, 9))
    {
        throw std::runtime_error("1<=n<=10^9");
    }

    string output = to_symbolic(n);

    std::cout << output;

    return 0;
}

string ltrim(const string &str)
{
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str)
{
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end());

    return s;
}
