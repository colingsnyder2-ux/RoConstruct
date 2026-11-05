// from server: 30% by atomic.potato
struct Vec3 { float x, y, z; };

struct Mat3 {
    float m[9];
    void setRow(int i, const Vec3& v);
    void getRow(int i, Vec3* out) const;
};

struct S {
    char pad0[0x13c];
    int m_flag;
    void f(int a, int b);
};

extern "C" {
    void __stdcall sub_5400e0(const Mat3* m, int i, Vec3* out);
    void __stdcall sub_540050(Mat3* dst, const Mat3* src);
    void __stdcall sub_5412b0(Vec3* out, float x, float y, float z);
    void __stdcall sub_540310(Mat3* m, const Vec3* v);
    void __stdcall sub_541890(Mat3* m);
    void __stdcall sub_542730(Mat3* m, const Vec3* v);
    void __stdcall sub_542880(Mat3* m);
    void __stdcall sub_541450(Mat3* m);
    void __stdcall sub_411f60(void* p, const char* s);
    void* __stdcall sub_663f30(S* self);
    void __stdcall sub_665400(S* self, void* p);
    void __stdcall sub_666510(S* self, const Vec3* v);
    void __stdcall sub_6665a0(S* self, const Vec3* v);
}

extern float g_a75cdc;
extern float g_a690b4;
extern float g_a726ac;
extern float g_a9bff8;
extern float g_a9bdd4;
extern double g_a9c000;

void S::f(int a, int b)
{
    Mat3 m1;
    Vec3 v;
    sub_5400e0(&m1, 2, &v);
    float t = g_a75cdc;
    Vec3 d;
    d.x = t - v.x;
    d.y = t - v.y;
    d.z = t - v.z;
    float len = d.x * d.x + d.z * d.z;
    if ((double)len > g_a9c000) {
        sub_542880(&m1);
        sub_5400e0(&m1, 0, &v);
        d.x = t - v.x;
        d.y = t - v.y;
        d.z = t - v.z;
    } else {
        float inv = 1.0f / (float)len;
        d.x = inv * d.x;
        d.y = inv * g_a690b4;
        d.z = inv * d.z;
    }
    sub_541890(&m1);
    sub_542730(&m1, &d);
    sub_5412b0(&v, g_a9bdd4, g_a9bff8, 0.0f);
    sub_540310(&m1, &v);
    sub_5400e0(&m1, 2, &v);
    float t2 = g_a75cdc;
    float s = g_a726ac;
    Vec3 d2;
    d2.x = (t2 - v.x) * s;
    d2.y = (t2 - v.y) * s;
    d2.z = (t2 - v.z) * s;
    Vec3* p = (Vec3*)((char*)this + 0x24);
    p->x += d2.x;
    p->y += d2.y;
    p->z += d2.z;
    sub_542730(&m1, p);
    if (m_flag != 0) {
        m_flag = 0;
        sub_411f60(this, (const char*)0xccdcc8);
    }
    Mat3 m2;
    sub_541450(&m2);
    sub_540050(&m2, &m1);
    Vec3 v2;
    v2.x = p->x;
    v2.y = p->y;
    v2.z = p->z;
    sub_666510(this, &v2);
    sub_6665a0(this, &v2);
    void* r = sub_663f30(this);
    if (r != 0) {
        void** vt = *(void***)r;
        void* (*fn)(void*, int, int) = (void* (*)(void*, int, int))vt[4];
        void* res = fn(r, a, 0);
        sub_665400(this, res);
    }
}
