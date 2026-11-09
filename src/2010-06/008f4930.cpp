// from server: 31% by atomic.potato




struct C1 { void f(float* out); };
struct C2 { void f(float* a, float* b, float* c); };

struct S {
    char pad0[0x38];
    float f38;
    float f3c;
    char pad40[0x4c];
    char f8c;
    char pad8d[0x3];
    char pad90[0x30];
};

struct T {
    float x, y, z;
    float nx, ny, nz;
    float u, v;
    float tx, ty;
    float px, py;
};

extern float g_c03cc4;
extern float g_c03cc8;
extern float g_c03ccc;
extern unsigned int g_c03cd0;

T* S_do(S* self, T* out, float* a, float* b, int c)
{
    out->x = a[0];
    out->y = a[1];
    out->z = a[2];

    if (!(g_c03cd0 & 1)) {
        g_c03cd0 |= 1;
        g_c03cc4 = 0.0f;
        g_c03cc8 = 0.0f;
        g_c03ccc = 0.0f;
    }

    float tmp[3];
    tmp[0] = g_c03cc4;
    tmp[1] = g_c03cc8;
    tmp[2] = g_c03ccc;

    float tmp2[3];
    tmp2[0] = b[0];
    tmp2[1] = b[1];
    tmp2[2] = b[2];

    ((C2*)out)->f(tmp, tmp2, 0);

    if (self->f8c) {
        float m[9];
        ((C1*)((char*)self + 0x5c))->f(m);
        float rx = a[3];
        float ry = a[4];
        float rz = a[5];
        float r0 = m[1] * ry + m[2] * rz + rz * m[0];
        float r1 = m[3] * rz + m[4] * ry + m[5] * rz;
        float r2 = m[6] * rz + m[7] * ry + m[8] * rz;
        out->nx = r0;
        out->ny = r1;
        out->nz = r2;
    } else {
        out->nx = a[3];
        out->ny = a[4];
        out->nz = a[5];
    }

    out->u = a[7];
    out->v = a[8];
    out->tx = a[0x34 / 4];
    out->ty = a[0x38 / 4];
    out->px = a[0x34 / 4] - self->f38;
    out->py = a[0x38 / 4] - self->f3c;
    return out;
}
