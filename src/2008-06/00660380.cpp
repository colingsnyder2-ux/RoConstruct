// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_filterstairs_55d2f7ceceb920d7.cpp

// Candidate translation unit (score above; library headers required).

#include <boost/shared_ptr.hpp>
typedef boost::shared_ptr<void> Shared;

extern Shared __cdecl makeShared(void*);
extern void* __cdecl getCharacter(void*);
extern void* __cdecl getRelated(void*);

struct FilterStairs
{
    virtual ~FilterStairs();
    Shared character;
    Shared related;

    FilterStairs(void*);
};

FilterStairs::FilterStairs(void* player)
{
    character = makeShared(getCharacter(player));
    related = makeShared(getRelated(character.get()));
}