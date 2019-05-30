#include <iostream>

int array_size(char s[])
{
    int j = 0;
    while (s[j] != '\0')
    {
        j++;
    }
    return j;
}

char* find_last(char s[], char c)
{
    for (int i = array_size(s); i >= 0; i--)
    {
        if (s[i] == c)
        {
            return &s[i];
        }
    }
    return nullptr;
}

void display_array(char s[])
{
    for (int i = 0; i < array_size(s); i++)
    {
        std::cout << s[i] << "," << " ";
    }
    std::cout << "\n";
}

int main()
{
    char arr[] = "abcdefghij";
    char empty_char;

    std::cout << "\nHere's an array of characters: " << std::endl;
    display_array(arr);

    std::cout << "\nType a single character:";
    std::cin >> empty_char;


    char* c_pointer = find_last(arr, empty_char);

    if (c_pointer != nullptr)
    {
        std::cout << "The last occurrence of the character '" << empty_char << "' in string '" << arr << "' is --<(" << c_pointer << ")>--" << std::endl;
    }
    else
    {
        std::cout << "\n'" << empty_char << "' is not a matching character in the given array. " << std::endl;
    }
}
