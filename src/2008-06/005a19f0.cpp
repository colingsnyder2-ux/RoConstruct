// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_arrowctor_acce1397a3eb454e.cpp

// Candidate translation unit (score above; library headers required).

#include <boost/shared_ptr.hpp>
typedef boost::shared_ptr<void> Pair;

extern Pair __cdecl makePair(void*);

struct Primary {
    virtual ~Primary();
};

struct Secondary {
    virtual ~Secondary();
};

struct Base : Primary, Secondary {
    char storage[64];
    Base(void*);
    virtual ~Base();
    void activate();
};

struct ArrowTool : Base {
    Pair value;
    ArrowTool(void*, void*);
    virtual ~ArrowTool();
};

ArrowTool::ArrowTool(void* first, void* second)
    : Base(first), value()
{
    value = makePair(second);
    activate();
}