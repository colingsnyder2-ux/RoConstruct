// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD

#include <set>

struct String {
    unsigned char storage[28];
};

extern void (__thiscall *construct_string)(String *);

struct S : std::set<int> {
    int value;
    String text;
    S(int);
};

S::S(int argument)
    : value(argument)
{
    construct_string(&text);
}
