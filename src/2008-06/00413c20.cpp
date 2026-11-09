// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_copyverbvector_bcd63a4facb35748.cpp

// Candidate translation unit (score above; library headers required).
#include <vector>
#include <boost/shared_ptr.hpp>
typedef boost::shared_ptr<void> Shared;
typedef std::vector<Shared> Vector;

struct CopyVerb {
    unsigned char padding[0x154];
    Vector* selection;

    Shared first();
};

Shared CopyVerb::first()
{
    return selection->size() > 0 ? *selection->begin() : Shared();
}
