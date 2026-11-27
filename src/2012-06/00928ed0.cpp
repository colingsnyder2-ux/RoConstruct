// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2

struct V3 { int x, y, z; V3(const V3& o) : x(o.x), y(o.y), z(o.z) {} };
struct Base { virtual void v0(); char pad[0x5c]; Base(int, int, int); };
struct Mid : Base {
    int m60; int m64;
    virtual void v0();
    Mid(int a1, int a2, int a3, int a6) : Base(a1, a2, a3), m60(0), m64(a6) {}
};
struct D : Mid {
    float m68; V3 m6c;
    virtual void v0();
    D(int a1, int a2, int a3, float a4, const V3& a5, int a6);
};
D::D(int a1, int a2, int a3, float a4, const V3& a5, int a6)
    : Mid(a1, a2, a3, a6), m68(a4), m6c(a5) {}
