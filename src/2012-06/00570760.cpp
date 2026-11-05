// from server: 100% by tajop
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// Target: cdecl (source, destination); null-checked placement copy of three floats.
#include <new>
struct Vector3 {
    float x, y, z;
    Vector3(const Vector3& o) : x(o.x), y(o.y), z(o.z) {}
};
void __cdecl constructVector3(const Vector3& value, void* where)
{
    if (where) new (where) Vector3(value);
}
