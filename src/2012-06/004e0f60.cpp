// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD 
#include <string>
#include <map>
struct E { char data[0x40]; E(); E(const E&); ~E(); };
template class std::map<std::string, E>;
