// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <map>
struct BucketVal { double d; char pad[0x148 - 8]; };
template class std::map<int, BucketVal>;
