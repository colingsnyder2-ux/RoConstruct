// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_entrylocal_7feebf1d3fc40bcb.cpp

// Candidate translation unit (score above; library headers required).


#include <boost/shared_ptr.hpp>
typedef boost::shared_ptr<void> Entry;

typedef void (__cdecl *Callback)(Entry);

struct Iterator { unsigned int owner; Entry* position; };
Callback __cdecl process(Iterator first, Iterator last, Callback callback) {
    Entry* current = first.position;
    Entry* finish = last.position;
    for (; current != finish; ++current)
        callback(*current);
    return callback;
}
