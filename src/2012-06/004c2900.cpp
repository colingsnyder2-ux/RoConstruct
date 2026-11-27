// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct Matrix3 { float m[3][3]; };
struct Vector3 { float x, y, z; Vector3& operator=(const Vector3& o) { x = o.x; y = o.y; z = o.z; return *this; } };
struct CF { Matrix3 r; Vector3 t; };
struct S { char pad[0xa0]; CF cf; void set(const CF& c); };
void S::set(const CF& c) { cf = c; }
