// from server: 21% by atomic.potato
struct V2 { float x, y; };
struct V3 { float x, y, z; };

struct S {
    char pad0[4];
    void* ptr4;
    char pad8[0x10];
    float f18;
    float f1c;
    float f20;
    void method(V3* a, V3* b, V3* c, V3* d, float e, float f, char g, V3* h, V3* i);
};

extern "C" void __fastcall sub_559bd0(V2* out, void* self);
extern "C" void __fastcall sub_559b70(V3* out, V3* a, V3* b);
extern "C" void __fastcall sub_738f20(V3* out, V3* a, V3* b);

extern float g_a126e0;
extern float g_a1f624;

void S::method(V3* a, V3* b, V3* c, V3* d, float e, float f, char g, V3* h, V3* i)
{
    V2 t1, t2, t3, t4;
    V3 v1, v2, v3, v4;
    V3 r1, r2, r3;
    float dx, dy;

    sub_559bd0(&t1, a);
    sub_559bd0(&t2, b);
    dx = t2.x - t1.x;
    dy = t2.y - t1.y;

    sub_559bd0(&t3, c);
    sub_559bd0(&t4, d);
    v1.x = t3.x + t4.x;
    v1.y = t3.y + t4.y;

    sub_559b70(&v2, &v1, (V3*)&dx);

    v3.x = v2.x;
    v3.y = v2.y;
    v3.z = v2.z;

    v4.x = h->x;
    v4.y = h->y;
    v4.z = h->z;

    r1.x = a->x;
    r1.y = a->y;
    r1.z = a->z;

    sub_559bd0(&t1, &v3);

    float zero = 0.0f;
    float f1 = g_a1f624;
    float f2 = g_a1f624;

    r2.x = t1.x;
    r2.y = zero;
    r2.z = zero;
    r3.x = zero;
    r3.y = zero;
    r3.z = v4.z;
    r3.x = v4.x;
    r3.y = v4.y;
    r3.z = v4.z;

    if (r1.x > zero) r1.x -= e;
    else r1.x += e;

    if (r1.y > zero) r1.y -= e;
    else r1.y += e;

    if (r1.x > zero) {
        r1.x -= f;
        v4.z -= f;
    } else {
        r1.x += f;
        v4.z += f;
    }

    if (g) {
        r3.x = h->x;
        r3.y = h->y;
    }

    sub_738f20(&r2, &r1, &r3);

    r1.x = f18 + r2.x;
    r1.y = f1c + r2.y;
    r1.z = f20 + r2.z;

    sub_738f20(&r3, &r1, &r2);

    r2.x = r3.x;
    r2.y = r3.y;
    r2.z = r3.z;

    sub_738f20(&r3, &r2, &r1);

    r3.x = r2.x;
    r3.y = r2.y;
    r3.z = r2.z;

    r3.z *= g_a126e0;
    r3.y *= g_a126e0;

    void** vt = *(void***)ptr4;
    void (*fn)(void*, V3*) = (void (*)(void*, V3*))vt[4];
    fn(ptr4, &r3);
}
