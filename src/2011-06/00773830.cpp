// from server: 100% by colin
// roc-cl: 50727
// roc-flags: /O2 /GS /EHsc /MD
// stl: map_str<pod12>
struct E { int v[3]; };
#include <map>
#include <string>
template class std::map<std::string, E>;