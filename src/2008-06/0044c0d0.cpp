// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espclaude_5d70bf43e9d60d33.cpp

// Candidate translation unit (score above; library headers required).
#include <string>
#include <algorithm>
#include <boost/bind.hpp>

class CRobloxModule {
public:
    int matches(std::string name);
};

typedef boost::_bi::bind_t<int, boost::_mfi::mf1<int, CRobloxModule, std::string>,
    boost::_bi::list2<boost::_bi::value<CRobloxModule*>, boost::arg<1> > > Bound;

template std::string* std::_Find_if<std::string*, Bound>(std::string*, std::string*, Bound);
