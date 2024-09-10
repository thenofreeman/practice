#pragma once

class NumberToWords
{
    public:
        const static string lessThan20[];
        const static string tens[];

        Number(long long x)
            : number{x}, str{other(number)}
        { }

        std::string other(long long n)
        {
            if (n == 0)
                return lessThan20[n];
            else
                return calculate(n);
        }

        std::string calculate(long long n)
        {
            if (n >= 1000000000000)
                return calculate(n/1000000000000) + "trillion " + calculate(n%1000000000000);
            else if (n >= 1000000000)
                return calculate(n/1000000000) + "billion " + calculate(n%1000000000);
            else if (n >= 1000000)
                return calculate(n/1000000) + "million " + calculate(n%1000000);
            else if (n >= 1000)
                return calculate(n/1000) + "thousand " + calculate(n%1000);
            else if (n >= 100)
                return lessThan20[n/100] + " hundred " + calculate(n%100);
            else if (n >= 20)
                return tens[n/10] + " " + calculate(n%10);
            else if (n > 0)
                return lessThan20[n] + " ";

            return "";
        }

        void print()
        {
            std::cout << str << '\n';
        }

        friend std::ostream& operator<<(std::ostream& os, const Number& n)
        {
            os << n.str << '\n';
            return os;
        }

    private:
        long long number;
        string str;

};

const string Number::lessThan20 [] =
{
    "zero", "one", "two", "three", "four", "five",
    "six", "seven", "eight", "nine", "ten",
    "eleven", "twelve", "thirteen", "fourteen",
    "fifteen", "sixteen", "seventeen", "eighteen",
    "nineteen",
};

const string Number::tens [] =
{
    "zero", "ten", "twenty", "thirty", "forty",
    "fifty", "sixty", "seventy", "eighty", "ninety",
};