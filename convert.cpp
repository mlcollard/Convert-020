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
#include <unordered_map>

// output a character
// @concern output format, std::cout, output[out]
void output(char& c) {
    std::cout << c;
}

typedef void (*Conversion)(char& c);

// @concern "--upper", "--lower", toUpper(), toLower()
// @concern conversionOption, std::unordered_map<>
const std::unordered_map<std::string, Conversion> conversionOption{
    { "--upper", [](char& c) { c = std::toupper(c); } },
    { "--lower", [](char& c) { c = std::tolower(c); } },
};

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

    // map the conversion from the option
    // @concern option
    // @concern error handling, std::cerr, convert()[out]
    auto conversionEntry = conversionOption.find(option);
    if (conversionEntry == conversionOption.end()) {
        std::cerr << "Invalid conversion option: " << option << '\n';
        return 1;
    }
    auto convert = conversionEntry->second;

    // convert the string according to the option
    // @concern text, convert
    myforeach(text.begin(), text.end(), convert);

    // output converted text
    // @concern text, output()
    myforeach(text.begin(), text.end(), output);
    std::cout << '\n';

    return 0;
}
