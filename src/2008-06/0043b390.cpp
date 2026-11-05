// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_colorfunctorcopy_026488baf660e72e.cpp

// Candidate translation unit (score above; library headers required).
#include <G3D/Color3.h>
// from server: 85% by king_originala
typedef int (__thiscall *Getter)(void*);
typedef void (__thiscall *Consumer)(void*, int, const G3D::Color3*);

struct Iterator {
    int unused;
    char* current;
};

struct Functor {
    Consumer consume;
    char* object;
    int adjustment;
    Getter get;
    int unused;
    G3D::Color3 color;
};

Functor __cdecl apply(Iterator first, Iterator last, Functor action)
{
    char* current = first.current;
    char* end = last.current;
    for (; current != end; current += 8) {
        int value = action.get(current);
        action.consume(action.object + action.adjustment, value, &action.color);
    }

    return action;
}
