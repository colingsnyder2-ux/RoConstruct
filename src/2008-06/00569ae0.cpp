// from server: 100% by coldek
// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /GS- /EHsc /MD /O2 /Ob0 /Oy-
#include <sstream>
extern int assertionHook;
struct S {
    char prefix[32];
    union {
        char text[16];
        char* heap;
    } name;
    unsigned length;
    unsigned capacity;
    void report0(int, std::istringstream*, int, const char*, const char*);
    void report1(int, std::istringstream*, int, const char*, const char*);
    void f(const char*);
};
void S::f(const char* message)
{
    const char* text = 0;
    if (length != 0) {
        if (capacity >= 16)
            text = name.heap;
        else
            text = name.text;
    }
    std::istringstream stream(std::ios_base::in);
    try {
        if (assertionHook == 0)
            report0(0, &stream, 0, text, message);
        else if (assertionHook == 1)
            report1(0, &stream, 0, text, message);
    }
    catch (...) {
        if (assertionHook == 0)
            report0(0, &stream, 0, text, message);
        else if (assertionHook == 1)
            report1(0, &stream, 0, text, message);
    }
}
