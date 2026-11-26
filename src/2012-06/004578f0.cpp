// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /D_SECURE_SCL=0
#include <map>
typedef std::map<unsigned, int> Map;
struct D : Map { std::pair<Map::iterator, bool> ins(const Map::value_type& v); };
std::pair<Map::iterator, bool> D::ins(const Map::value_type& v) { return insert(v); }
