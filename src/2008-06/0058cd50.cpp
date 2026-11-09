// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_xmlentitydecode0fe6f6fa0df33ef6.cpp

// Candidate translation unit (score above; library headers required).
#include <string>
#include <stdexcept>
#include <cstdlib>
std::string decode(std::string input)
{
    std::string result;
    unsigned index = 0;
    char character;
    bool (__cdecl *equal)(const std::string &, const char *) = std::operator==;

    while (index < input.size()) {
        character = input[index++];
        if (character == '&') {
            std::string entity;
            while (index < input.size()) {
                character = input[index++];
                if (character == ';')
                    break;
                entity += character;
            }

            if (equal(entity, "lt"))
                result += '<';
            else if (equal(entity, "gt"))
                result += '>';
            else if (equal(entity, "amp"))
                result += '&';
            else if (equal(entity, "quot"))
                result += '"';
            else if (equal(entity, "apos"))
                result += '\'';
            else if (equal(entity, "nbsp"))
                result += ' ';
            else if (entity.c_str()[0] == '#') {
                if (entity.size() < 2) {
                    std::string message("bad XML. No character code following #");
                    throw std::runtime_error(message);
                }
                if (entity[1] == 'x') {
                    std::string message("Unable to parse hexidecimal character code");
                    throw std::runtime_error(message);
                }
                result += (char)atoi(entity.substr(1, std::string::npos).c_str());
            } else {
                result += "&" + entity + ";";
            }
        } else {
            result += character;
        }
    }
    return result;
}
