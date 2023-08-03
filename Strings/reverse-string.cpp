#include <iostream>
#include <string>

// Function to reverse the input string
std::string reverseString(std::string str)
{
    int start = 0;
    int end = str.size() - 1;

    while (start < end) {
        std::swap(str[start++], str[end--]);
    }

    return str;
}

int main()
{
    std::string input;
    std::cout << "Enter a string: ";
    std::getline(std::cin, input);

    std::string reversed = reverseString(input);
    std::cout << "Reversed string: " << reversed << std::endl;

    return 0;
}
