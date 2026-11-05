// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_joincommand_9ccfcedff9b8352a.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/shared_ptr.hpp>
typedef boost::shared_ptr<void> Shared;
struct Children
{
    char padding[12];
    char* begin;
    char* end;
};

struct Object
{
    char padding[0x154];
    Children* children;
    Shared first();
    Shared second();
};

struct Holder
{
    Object* get();
};

int __cdecl matches(void*, void*);

struct JoinCommand
{
    char padding[12];
    Holder* holder;
    bool execute();
};

bool JoinCommand::execute()
{
    Object* p = holder ? holder->get() : 0;
    if (((p->children->end - p->children->begin) & ~7) == 16)
    {
        Shared a = p->first();
        Shared b = p->second();
        if ((unsigned char)matches(a.get(), b.get()))
            return true;
    }
    return false;
}
