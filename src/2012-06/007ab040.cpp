// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <string>
struct TD { long long t; TD(const TD& o) : t(o.t) {} };
std::string to_simple_string(TD td);
struct Lighting { char pad[0x1c0]; TD timeOfDay; std::string getTimeStr() const; };
std::string Lighting::getTimeStr() const { return to_simple_string(timeOfDay); }
