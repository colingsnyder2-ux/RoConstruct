// from server: 26% by atomic.potato
struct Sub1 {
    void f();
};

struct Sub2 {
    void g();
};

struct BodyPosition {
    char pad[0x158];
    float f158;
    float f15c;
    float f160;
    float f164;
    float f168;
    float f16c;
    float f170;
    float f174;
    float f178;
    float f17c;
    float f180;
    void func(float* out, void* a, void* b, void* c, void* d);
};

extern float g_9b1610;

void BodyPosition::func(float* out, void* a, void* b, void* c, void* d)
{
    Sub1* p1 = (Sub1*)a;
    p1->f();

    float x = f16c - *(float*)((char*)a + 0xc0);
    float y = f170 - *(float*)((char*)a + 0xc4);
    float z = f174 - *(float*)((char*)a + 0xc8);
    x *= f158;
    y *= f158;
    z *= f158;

    p1->f();

    float neg = -f15c;
    float nx = neg * *(float*)((char*)a + 0xcc) + x;
    float ny = *(float*)((char*)a + 0xd0) * neg + y;
    float nz = *(float*)((char*)a + 0xd4) * neg + z;

    void* q = *(void**)((char*)a + 0x2c);
    void* r = *(void**)((char*)q + 0x30);
    float scale;
    if (r) {
        ((Sub2*)r)->g();
        scale = *(float*)((char*)r + 0x14);
    } else {
        scale = *(float*)((char*)q + 0x94);
    }

    nx *= scale;
    ny *= scale;
    nz *= scale;
    f178 = nx;
    f17c = ny;
    f180 = nz;

    float mx = -f168;
    float my = -f164;
    float mz = -f160;

    if (mx < nz) {
        if (nz < f168) {
            mx = f168;
        } else {
            mx = nz;
        }
    }

    if (my < f17c) {
        if (f17c < f164) {
            my = f164;
        } else {
            my = f17c;
        }
    }

    if (mz < f178) {
        if (f178 < f160) {
            mz = f160;
        } else {
            mz = f178;
        }
    }

    f178 = mz;
    f17c = my;
    f180 = mx;

    out[0] = f178;
    out[1] = f17c;
    out[2] = f180;
}
