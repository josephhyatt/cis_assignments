#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string str)
{
    if (str.length() < 2)
    {
        return true;
    }
        if (str[0] != str[str.length() - 1])
        {
            return false;
        }
        string substring = str.substr(1, str.length() - 2);
        return isPalindrome(substring);
}

int main()
{
    string str;
    cout << "Enter a word: ";
    cin >> str;
        if (isPalindrome(str))
        {
            cout << "It's a palindrome!" << endl;
        }
        else
        {
            cout << "It's not a palindrome." << endl;
        }
    cin.ignore();
    cin.get();
    return 0;
}
