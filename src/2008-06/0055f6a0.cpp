// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_timerintegertimee579961826f2dca7.cpp

// Candidate translation unit (score above; library headers required).
#include <memory>
#include <boost/function.hpp>
// Integer-register copy of first 32-bit member, then function at offset 8.
struct Item { unsigned int time; boost::function0<void> func; };
template void std::_Construct<Item,Item>(Item*, const Item&);
