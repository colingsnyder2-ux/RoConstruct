// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD /D_SECURE_SCL=0
#include <map>
#include <string>
struct V { int x; };
typedef std::map<std::string, V> Map;
struct Desc : Map { Map::iterator find2(const std::string& k); };
Map::iterator Desc::find2(const std::string& k) { return find(k); }
