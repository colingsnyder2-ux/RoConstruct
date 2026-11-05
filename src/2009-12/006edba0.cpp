// from server: 17% by atomic.potato
struct Sub
{
    char pad0[0xf0];
    void* p0;      // 0xf0
    void* p1;      // 0xf4
};

struct Mat
{
    float m[9];
};

struct Vec
{
    float x, y, z;
};

struct S
{
    char pad0[0xc];
    float x;       // 0xc
    float y;       // 0x10
    float z;       // 0x14
    char pad1[0xc];
    float rx;      // 0x24
    float ry;      // 0x28
    float rz;      // 0x2c
    char pad2[0xc4];
    Sub* sub;      // 0xf0

    void f(Vec* out);
};

extern "C" void __stdcall sub_6ed4b0();
extern "C" void __stdcall sub_5f3900();

void S::f(Vec* out)
{
    sub_6ed4b0();
    Mat* m = (Mat*)sub->p0;
    Vec* v = (Vec*)sub->p1;
    float nx = -v->x * 0.0f;
    float ny = -v->y * 0.0f;
    float nz = -v->z * 0.0f;
    float tx = m->m[0]*nx + m->m[3]*ny + m->m[6]*nz + m->m[9];
    float ty = m->m[1]*nx + m->m[4]*ny + m->m[7]*nz + m->m[10];
    float tz = m->m[2]*nx + m->m[5]*ny + m->m[8]*nz + m->m[11];
    sub_5f3900();
    out->x = tx;
    out->y = ty;
    out->z = tz;
}
