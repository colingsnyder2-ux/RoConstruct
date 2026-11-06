// Compile-only equivalence observer against the unmodified VC9 string implementation.
// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /DNDEBUG
#include <string>

extern "C" const char* notifierCString(const std::string& value) {
    return value.c_str();
}

extern "C" const char* notifierConstIndex(const std::string& value) {
    return &value[0];
}
