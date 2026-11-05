// from server: 47% by atomic.potato
struct S {
    char pad[0x144];
    int f(float);
    int g(float*, float*, float*);
    int h();
    int k();
    int m(float, float, float);
};

extern float g_a;
extern float g_b;
extern float g_c;
extern float g_d;
extern float g_e;
extern unsigned char g_init;
extern float g_cached;

extern "C" int __cdecl sub_4382f0();

int S::f(float value)
{
    if (!(value == value))
        return 0;

    float a;
    float b;
    float c;
    g(&a, &b, &c);

    if (!g_init) {
        g_cached = g_a;
        g_init = 1;
    }

    float lo = g_b - g_cached;
    float hi = value + c;
    float clamped;
    if (lo < hi)
        clamped = hi;
    else if (hi < g_cached)
        clamped = g_cached;
    else
        clamped = hi;

    if (!(clamped == value))
        return 0;

    c = clamped;

    if (sub_4382f0() != 0) {
        int* p = (int*)sub_4382f0();
        if (p[0x94 / 4] == 2) {
            if (!h()) {
                if (k()) {
                    if (g_d <= c) {
                        if (c < g_e)
                            c = g_e;
                    } else {
                        c = g_d;
                    }
                }
            }
        }
    }

    m(a, b, c);
    return 1;
}
