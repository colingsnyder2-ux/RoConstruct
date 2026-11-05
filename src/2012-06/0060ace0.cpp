// from server: 21% by atomic.potato
struct V2 { float x; float y; };
struct V3 { float x; float y; float z; };

struct Inner {
    char pad0[0x10];
    virtual void vf(V3*, V3*, V3*);
};

struct Outer {
    char pad0[4];
    Inner* p4;
    char pad8[0x10];
    float f18;
    float f1c;
    float f20;

    void method(V2* a, V2* b, V3* c, V3* d, V3* e, V3* f, V3* g, char h);
};

extern "C" void __fastcall sub_634240(V2* ret, void* self);
extern "C" void __fastcall sub_634210(V3* ret, V2* a, V2* b);
extern "C" void __fastcall sub_827640(V3* ret, V3* a, V3* b);

extern float g_b4c440;
extern float g_b62770;

void Outer::method(V2* a, V2* b, V3* c, V3* d, V3* e, V3* f, V3* g, char h)
{
    V2 t1, t2, t3, t4;
    V3 v1, v2, v3, v4, v5, v6, v7, v8;

    sub_634240(&t1, a);
    sub_634240(&t2, b);
    t3.x = t2.x - t1.x;
    t3.y = t2.y - t1.y;
    sub_634240(&t4, c);
    sub_634240(&t1, b);
    t2.x = t4.x + t1.x;
    t2.y = t4.y + t1.y;
    sub_634210(&v1, &t3, &t2);

    v2.x = 0.0f; v2.y = 0.0f;
    v3.x = 0.0f; v3.y = 0.0f;
    v4.x = v1.x; v4.y = v1.y; v4.z = v1.z;
    v5.x = g_b4c440; v5.y = g_b4c440;
    v6.x = d->x; v6.y = d->y;
    v7.x = g_b4c440; v7.y = g_b4c440;
    sub_634240(&t1, e);

    v8.x = e->x; v8.y = e->y; v8.z = e->z;
    v2.x = t1.x; v2.y = t1.y;
    v3.x = t2.x; v3.y = t2.y;

    v4.x = v1.x; v4.y = v1.y; v4.z = v1.z;
    v5.x = v1.x; v5.y = v1.y; v5.z = v1.z;
    v6.x = v1.x; v6.y = v1.y; v6.z = v1.z;
    v7.x = v1.x; v7.y = v1.y; v7.z = v1.z;

    p4->vf(&v4, &v5, &v6);

    if (h) {
        v6.x = d->x;
        v6.y = d->y;
    }

    sub_827640(&v7, &v6, &v8);

    v7.x = f18 + v7.x;
    v7.y = f1c + v7.y;
    v7.z = f20 + v7.z;

    sub_827640(&v8, &v7, &v5);

    sub_827640(&v5, &v8, &v4);

    v5.x *= g_b62770;
    v5.y *= g_b62770;

    Inner* p = p4;
    void (__thiscall* fn)(Inner*, V3*) = *(void (__thiscall**)(Inner*, V3*))(*(void***)p + 4);
    fn(p, &v5);
}
