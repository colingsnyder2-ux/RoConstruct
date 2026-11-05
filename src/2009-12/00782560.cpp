// from server: 38% by atomic.potato
struct Vec3 { float x, y, z; };

extern "C" {
    void __cdecl sub_7858D0(void*, void*);
    int __cdecl sub_77CF20(void*, const char*, int, void*, void*);
    void* __cdecl sub_60BA40(void*, void*);
    char __cdecl sub_6F06E0(void*, void*, void*);
    void* __cdecl sub_7830A0(void*, void*);
}

extern float g_b7cc20;
extern float g_b7cc24;
extern float g_b7cc28;
extern int g_b7cc2c;
extern float g_b7cc38;
extern float g_b7cc3c;
extern float g_b7cc40;
extern int g_b7cc44;
extern float g_9aea18;

struct BlockBlockContact {
    char pad[0x30];
    bool func(void* a, void* b, void* c, Vec3* out);
};

bool BlockBlockContact::func(void* a, void* b, void* c, Vec3* out)
{
    char buf[0x18];
    sub_7858D0(buf, a);
    g_b7cc2c = 0;
    if (sub_77CF20(buf, (const char*)0xb987d5, 0, b, c) != 0)
        goto fallback;

    if (!(g_b7cc2c & 1)) {
        g_b7cc2c |= 1;
        g_b7cc20 = 0.0f;
        g_b7cc24 = 0.0f;
        g_b7cc28 = 0.0f;
    }
    if (!(g_b7cc44 & 1)) {
        g_b7cc44 |= 1;
        g_b7cc38 = 0.0f;
        g_b7cc3c = g_9aea18;
        g_b7cc40 = 0.0f;
    }
    {
        void* p = sub_60BA40(&g_b7cc38, &g_b7cc20);
        char r = sub_6F06E0(buf, p, b);
        if (!(r == 0))
            goto fallback;
    }
    if (!(g_b7cc2c & 1)) {
        g_b7cc2c |= 1;
        g_b7cc20 = 0.0f;
        g_b7cc24 = 0.0f;
        g_b7cc28 = 0.0f;
    }
    out->x = g_b7cc20;
    out->y = g_b7cc24;
    out->z = g_b7cc28;
    return false;

fallback:
    {
        void* p = sub_7830A0(buf, out);
        out->x = *(float*)p;
        out->y = *(float*)((char*)p + 4);
        out->z = *(float*)((char*)p + 8);
    }
    return true;
}
