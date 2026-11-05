// from server: 31% by atomic.potato
struct Vec4 {
    float x, y, z, w;
};

struct Entry {
    float a, b, c, d, e, f, g;
};

struct Container {
    unsigned int count;
    char pad0[0x10];
    Entry* begin;
    Entry* end;
};

extern "C" void __stdcall _invalid_parameter_noinfo();

extern float g_9aea18;
extern float g_9ae6a0;
extern float g_b7cc28;
extern void (__stdcall *g_98b760)();

void __stdcall func(Container* c, Vec4* out)
{
    float s0 = 0.0f;
    float s1 = 0.0f;
    float s2 = 0.0f;
    float s3 = 0.0f;
    float s4 = 0.0f;
    float s5 = 0.0f;
    float s6 = 0.0f;
    float s7 = 0.0f;

    s0 = 0.0f;
    s1 = 0.0f;
    s2 = 0.0f;
    s3 = g_9aea18;
    s4 = 0.0f;
    s5 = 0.0f;
    s6 = 0.0f;
    s7 = 0.0f;

    unsigned int i = 0;
    if (c->count > 0) {
        unsigned int n = (unsigned int)((c->end - c->begin) / 7);
        while (i < c->count) {
            if (i >= n) {
                g_98b760();
            }
            Entry* e = c->begin + i;
            s0 += e->a;
            s1 += e->b;
            s2 += e->c;
            s3 += e->d;
            s4 += e->e;
            s5 += e->f;
            s6 += e->g;
            i++;
        }
    }

    float inv = 1.0f / (float)c->count;
    out->x = s0 * inv;
    out->y = s1 * inv;
    out->z = s2 * inv;
    out->w = s3 * inv;
}
