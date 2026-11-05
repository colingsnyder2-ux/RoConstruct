// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Vec3 { float x,y,z; };
struct Less { bool operator()(const Vec3& a,const Vec3& b) const {
if (a.x < b.x) return true;
if (a.x > b.x) return false;
if (a.y < b.y) return true;
if (a.y > b.y) return false;
if (a.z < b.z) return true;
return false;
} };
struct Mapped { int words[7]; };
#include <map>
template class std::map<Vec3,Mapped,Less>;
