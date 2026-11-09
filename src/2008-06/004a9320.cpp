// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espclaude_e8a7fd12331aa159.cpp

// Candidate translation unit (score above; library headers required).
#include "util/Guid.h"
#include <map>
#include <vector>
struct Elem { int x; };
struct GuidList : std::vector<Elem> {
    GuidList() {}
    GuidList(const GuidList&);
    ~GuidList();
};
typedef std::map<RBX::Guid::Data, GuidList> GuidMap;
GuidList& lookupGuid(GuidMap& m, const RBX::Guid::Data& d) { return m[d]; }
