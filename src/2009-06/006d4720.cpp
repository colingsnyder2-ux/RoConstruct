// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Vector3 {
    float x, y, z;
    Vector3(const Vector3& v) : x(v.x), y(v.y), z(v.z) {}
};
struct Cofm {
    char pad[8];
    Vector3 cofmInBody;
    void updateIfDirty();
    const Vector3& getCofmInBody() { updateIfDirty(); return cofmInBody; }
};
struct Frame {
    char data[0x24];
    Vector3 transform(const Vector3&) const;
};
struct S {
    char reserved0[0x30];
    Cofm* cofm;
    char reserved1[0x9c - 0x34];
    Frame frame;
    Vector3 fallback;
    const void* get();
    Vector3 f();
};
Vector3 S::f()
{
    const Vector3* c;
    return cofm
        ? (c = &cofm->getCofmInBody(), get(), frame.transform(*c))
        : (get(), fallback);
}
