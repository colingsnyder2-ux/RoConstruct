// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
struct Vector3 {
    float x, y, z;
    Vector3& operator=(const Vector3& o) { x = o.x; y = o.y; z = o.z; return *this; }
};
struct Vector4 { float x,y,z,w; Vector4& operator=(const Vector4& o){x=o.x;y=o.y;z=o.z;w=o.w;return *this;} };
struct Elem {
    std::string name;
    bool flag;
    float p; Vector4 a; Vector4 b;
};
void fill_elems(Elem* first, Elem* last, const Elem& val)
{
    for (; first != last; ++first)
        *first = val;
}
