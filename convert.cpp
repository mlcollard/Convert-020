/*
    convert.cpp

    Convert the text

    Note: The "@concern" are for pedagogical purposes only.

    * @concern are assume to be [in], meaning they are predefined and used in the code
    * @concern marked [out] meaning they are produced in that section
*/

#include <iostream>
#include <string>
#include <cctype>

// output a character
// @concern output format, std::cout, output[out]
void output(char& c) {
    std::cout << c;
}

// is the option for lowercase
// @concern "--lower", std::string, isOptionLower[out]
bool isOptionLower(const std::string& s) {

    return s == "--lower";
}

// is the option for uppercase
// @concern "--upper", std::string, isOptionUpper[out]
bool isOptionUpper(const std::string& s) {

    return s == "--upper";
}

typedef void (*Conversion)(char& c);

// @concern iteration, apply, myforeach()
void myforeach(std::string::iterator begin, std::string::iterator end, Conversion apply) {

    for (auto pc = begin; pc != end; ++pc)
        apply(*pc);
}

int main(int argc, char* argv[]) {

    // requires conversion option and string
    // @concern input format, argc, argv, error handling, std::cerr
    if (argc != 3) {
        std::cerr << "usage: " << argv[0] << " <option> <string>\n";
        return 1;
    }

    // conversion option
    // @concern input format, argv, std::string, option[out]
    std::string option(argv[1]);

    // input text
    // @concern input format, argv, std::string, text[out]
    std::string text(argv[2]);

    // convert the string according to the option
    // @concern option, text, isOptionUpper(), isOptionLower()
    // @concern std::string, std::toupper(), std::tolower(), iteration
    // @concern error handling, std::cerr
    if (isOptionUpper(option)) {

        for (auto pc = text.begin(); pc != text.end(); ++pc)
            *pc = std::toupper(*pc);

    } else if (isOptionLower(option)) {

        for (auto pc = text.begin(); pc != text.end(); ++pc)
            *pc = std::tolower(*pc);

    } else {

        std::cerr << "Invalid conversion option: " << option << '\n';
        return 1;
    }

    // output converted text
    // @concern text, output()
    myforeach(text.begin(), text.end(), output);
    std::cout << '\n';

    return 0;
}
