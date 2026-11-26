// from server: 100% by Xemicl
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <map>
#include <string>
// std::map<std::string, V>::_Erase where V is a 0x40-byte value with an out-of-line destructor.
struct V { char data[0x40]; ~V(); };
template class std::map<std::string, V>;