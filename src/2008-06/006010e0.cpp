// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_textvariantmember_47dbf4d9ffd6ae44.cpp

// Candidate translation unit (score above; library headers required).
#include <string>
#include <intrin.h>
typedef std::string String;
struct Name;
extern const Name& __cdecl getLocalScope();
struct Scope
{
    String text;
    const Name* value;
    Scope();
    ~Scope();
};

inline Scope::Scope() : value(&getLocalScope())
{
}

struct Slot
{
    unsigned int value;
    Slot();
    ~Slot();
};

inline Slot::Slot() : value(0)
{
}

struct S
{
    Scope scope;
    Slot a;
    Slot b;
    Slot c;
    Slot d;
    float x;
    float y;

    S(const char*, unsigned int);
    void setString(const char*, unsigned int);
};

S::S(const char* data, unsigned int length)
    : x(0.0f), y(0.0f)
{
    setString(data, length);
}
