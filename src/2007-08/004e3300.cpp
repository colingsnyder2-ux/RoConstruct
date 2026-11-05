// from server: 19% by colin
// roc 2007-08 004e3300  unit: PBBBuilder  size: 794 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004e3300

extern "C" double __stdcall ceil(double);

struct Vec2 {
    float x;
    float y;
};

struct PBBBuilder {
    char pad[0x10];
    unsigned int flags;
    void build(int a, int b, int c);
};

extern "C" void __stdcall sub_5b9a10(void*, void*);
extern "C" void* __stdcall sub_50b010(void*, void*);
extern "C" float __stdcall sub_4de980(int);
extern "C" void __stdcall sub_4e0180(void*, void*, void*, int, int, int);
extern "C" void __stdcall sub_4e2640(void*, int);

extern float g_787050;
extern float g_797e9c;
extern double g_795b48;
extern double g_79f340;
extern double g_79f348;

void PBBBuilder::build(int a, int b, int c)
{
    unsigned int v = this->flags;
    v = (v >> 15) & 7;

    float f1;
    float f2;
    sub_5b9a10(&f1, &this->pad[4]);

    float fa = (float)ceil((double)(f1 < 0 ? -f1 : f1));
    float fb = (float)ceil((double)(f2 < 0 ? -f2 : f2));

    float fc = f1 < 0 ? -f1 : f1;
    float fd = f2 < 0 ? -f2 : f2;

    int n;
    if (c == 0) {
        if (v != 0) {
            float t = (float)((double)fc * g_795b48);
            t = (float)ceil((double)t);
            n = (int)t;
        } else {
            n = 1;
        }
    } else {
        n = 1;
    }

    int idx = (c == 0) ? 1 : 0;

    short s1 = 0;
    short s2 = 0;
    short* p = &s1;
    short val = p[idx];
    int q = (int)val / n;
    int one = 1;
    unsigned short qq = (unsigned short)q;
    if ((short)qq > 1) {
        s2 = (short)qq;
    } else {
        s2 = 1;
    }

    float f3 = fd;
    float f4 = fc;

    Vec2 v1;
    Vec2 v2;
    sub_50b010(&v1, &f3);
    sub_50b010(&v2, &f4);

    float x1 = -v1.x;
    float y1 = -v1.y;
    float x2 = -v2.x;
    float y2 = -v2.y;

    float ax = 0.0f;
    float ay = 0.0f;
    float az = 0.0f;
    float aw = 0.0f;

    if (c == 0) {
        if (v == 0) {
            ax = g_787050;
            ay = g_797e9c;
            az = ay;
            aw = ay;
        } else {
            float t = sub_4de980(v);
            ay = t;
            ax = t + t;
            az = g_797e9c;
            if (idx == 1) {
                az = -az;
            }
        }
    } else if (c == 1) {
        ax = 0.0f;
        ay = this->pad[0x1c];
        az = this->pad[0x18];
        aw = -this->pad[0x1c];
    } else if (c == 2) {
        ax = 0.0f;
        ay = 0.0f;
        az = 0.0f;
        aw = 0.0f;
    }

    int i = 0;
    while (i < n) {
        float cur;
        if (i == n - 1) {
            cur = fc;
            if (c == 0 && az != 0.0f) {
                cur = (cur - aw) * (float)g_79f348 * az;
            }
        } else {
            cur = aw + (float)g_79f340;
        }

        float tmp = az;
        sub_4e0180(&v1, &v2, &tmp, a, b, c);
        sub_4e2640(&v1, b);
        aw = cur;
        i++;
    }
}
