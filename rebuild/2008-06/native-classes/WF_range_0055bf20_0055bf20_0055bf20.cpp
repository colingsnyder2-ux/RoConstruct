// native-flags: /O2 /EHsc /MD /GS-
#include <string>

std::string __cdecl transform(std::string input) {
    std::string result;
    for (int i = 0; i < 32; i += 2) {
        if (input[i] != '0')
            result += input[i];
        result += input[i + 1];
    }
    return result;
}
