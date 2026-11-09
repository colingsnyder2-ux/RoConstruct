// from server: 31% by colin
struct V2 { float x, y; };
struct V3 { float x, y, z; };
struct V4 { float x, y, z, w; };

struct A {
    void xy(V2* out);
};

struct B {
    V3 p0, p1;
};

struct C {
    V4 v;
};

struct D {
    V3 a, b;
};

extern "C" void __cdecl sub_682ff0(V3* out, V3* a, int b, V2* c);
extern "C" void __cdecl sub_5787f0(V3* out, V2* a, V2* b);

struct S {
    V4 f(B* a, B* b, int c, int d, int e, int f2, int g, int h, int i, int j, int k, int l, int m, int n, int o, int p, int q, int r);
};

V4 S::f(B* a, B* b, int c, int d, int e, int f2, int g, int h, int i, int j, int k, int l, int m, int n, int o, int p, int q, int r)
{
    V2 t1, t2;
    V3 u1, u2;
    V2 d1, d2;
    V3 dir;
    V4 result;

    ((A*)&a->p0)->xy(&t1);
    sub_682ff0(&u1, &a->p1, 0, &t1);
    ((A*)&u1)->xy(&t1);

    ((A*)&b->p0)->xy(&t2);
    sub_682ff0(&u2, &b->p1, 0, &t2);
    ((A*)&u2)->xy(&t2);

    d1.x = t1.x + t2.x;
    d1.y = t1.y + t2.y;

    d2.x = t2.x - t1.x;
    d2.y = t2.y - t1.y;

    sub_5787f0(&dir, &d1, &d2);

    result.x = dir.x;
    result.y = dir.y;
    result.z = dir.z;
    result.w = dir.z;

    return result;
}
