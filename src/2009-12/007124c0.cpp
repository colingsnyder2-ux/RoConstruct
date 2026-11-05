// from server: 23% by atomic.potato
struct Vec3 { float x, y, z; };
struct Vec4 { float x, y, z, w; };

struct Mat4 {
    float m[16];
};

struct Mechanism {
    char pad0[0xa4];
    Mat4 m_mat;
    void f(Vec3* out);
};

extern "C" float* __cdecl G3D_getZero3();
extern "C" float* __cdecl G3D_getOne3();
extern "C" float* __cdecl G3D_getZero4();

void Mechanism::f(Vec3* out)
{
    Vec4 v;
    Vec3 a, b;
    Vec4 c, d;
    Vec3 e, g;
    Vec4 h;
    Vec3 i, j;

    ((void (__thiscall*)(void*, Vec4*))*(void**)(*(void**)out))((void*)out, &v);

    float half = *(float*)0x9af2dc;
    float vx = v.x, vy = v.y, vz = v.z, vw = v.w;

    float cx = (vz + vx) * half;
    float cy = (vw + vy) * half;

    a.x = vx; a.y = vy; a.z = vz;
    b.x = vw; b.y = 0.0f; b.z = 0.0f;

    float* p;
    if (vw > vz) p = &b.x; else p = &a.x;
    float m0 = *p;

    if (vz > vx) p = &a.x; else p = &b.x;
    float m1 = *p;

    if (vy > vw) p = &b.x; else p = &a.x;
    float m2 = *p;

    if (vx > vz) p = &a.x; else p = &b.x;
    float m3 = *p;

    c.x = m1; c.y = m0; c.z = m3; c.w = m2;

    d.x = half; d.y = half; d.z = half; d.w = half;

    ((void (__thiscall*)(void*, Vec4*, Vec4*))*(void**)(*(char**)out + 0x28))((void*)out, &d, &c);

    float* q = G3D_getZero3();
    e.x = q[0]; e.y = q[1]; e.z = q[2];

    float* r = G3D_getOne3();
    g.x = r[0]; g.y = r[1]; g.z = r[2];

    float* s = G3D_getZero4();
    h.x = s[0]; h.y = s[1]; h.z = s[2]; h.w = s[3];

    i.x = e.x; i.y = e.y; i.z = e.z;
    j.x = g.x; j.y = g.y; j.z = g.z;

    ((void (__thiscall*)(void*, Vec3*, Vec3*, Vec4*, Vec4*, float, int, int, float*))*(void**)(*(char**)out + 0x34))(
        (void*)out, &i, &j, &h, &d, *(float*)0x9de390, 2, 1, (float*)&m_mat);
}
