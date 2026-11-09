// from server: 100% by auto
// from server: 100% by colin
// from server: 87% by coldek
// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lang: cpp
// roc-lib: rbxgs roc_unit_793d094842d6b0aa.cpp

// Candidate translation unit (score above; library headers required).
#include <vector>
#include <utility>
#include <boost/shared_ptr.hpp>
namespace RBX { class Instance; }
typedef std::pair<unsigned int, boost::shared_ptr<RBX::Instance> > NativeEntry;
template class std::vector<NativeEntry>;
