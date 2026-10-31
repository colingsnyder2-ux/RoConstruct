// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Vector3 { float x, y, z;
  Vector3() {}
  Vector3(const Vector3& o) : x(o.x), y(o.y), z(o.z) {} };
struct S { char pad[0x170]; Vector3 v; Vector3 get() const; };
Vector3 S::get() const { return v; }
