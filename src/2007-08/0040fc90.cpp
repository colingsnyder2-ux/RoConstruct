// from server: 99% by EspClaude
// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 50727
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
