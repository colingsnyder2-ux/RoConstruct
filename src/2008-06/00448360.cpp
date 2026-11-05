// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_settingsreturn_3f2a8f1adda8f010.cpp

// Candidate translation unit (score above; library headers required).
#include <string>
typedef std::string String;
extern const char authoring[];
struct StringVector {
    char reserved[12];
    String* begin;
    String* end;
    String* capacity;

    String& at(unsigned int index);
};

struct Settings {
    char reserved[136];
    StringVector strings;

    String get(const int& index);
};

String Settings::get(const int& index)
{
    int value = index;


    if (value < 0)
        return String(authoring);

    StringVector* vector = &strings;
    if (static_cast<unsigned int>(value) >=
        static_cast<int>(vector->end - vector->begin))
        return String(authoring);

    return String(vector->at(static_cast<unsigned int>(value)));
}
