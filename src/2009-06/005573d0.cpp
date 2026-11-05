// from server: 25% by atomic.potato
extern "C" __declspec(dllimport) double __stdcall ceil(double);

struct Vec2 { float x; float y; };

struct PBBBuilder {
    char pad0[8];
    int field8;
    char padC[8];
    int field14;
    char pad18[0x0c];
    float field24;
    float field28;
    float field2c;
    char pad30[0x10];
    void method(float, float, float, int, int, int);
};

extern "C" void __stdcall sub_52C1A0(int);
extern "C" void __stdcall sub_52DB40(void*, void*, void*);
extern "C" void __stdcall sub_556240(void*, int);
extern "C" void __stdcall sub_682E10(void*, void*);
extern "C" void __stdcall sub_575590(Vec2* out, float* in);

extern float g_8BAD4C;
extern float g_8BD044;
extern float g_8BE5AC;
extern float g_8C01C4;
extern float g_8CA3E4;
extern void* g_89E8B8;

void PBBBuilder::method(float a, float b, float c, int d, int e, int f)
{
    int idx = (field14 >> 15) & 7;
    int local_2c = (int)this;
    int local_28 = idx;

    float fa = a < 0 ? -a : a;
    float fb = b < 0 ? -b : b;
    float fc = c < 0 ? -c : c;

    float arr[3];
    arr[0] = fa;
    arr[1] = fb;
    arr[2] = fc;

    int flag;
    if (f == 0) {
        flag = (fa == fb) ? 1 : 0;
    } else {
        flag = 0;
    }
    int esi = flag ? 0 : 1;

    int ebp;
    if (f == 0 && idx != 0) {
        double v = (double)arr[esi] * (double)g_8BAD4C;
        double r = ceil(v);
        float rf = (float)r;
        int iv = (int)rf;
        if (iv < 1) {
            ebp = 1;
        } else {
            ebp = iv;
        }
    } else {
        ebp = 1;
    }

    short w10 = 0;
    short w12 = 0;
    (void)w10; (void)w12;

    int ecx2 = esi + esi;
    short s = *(short*)((char*)&d + ecx2);
    int q = (int)s / ebp;
    short qs = (short)q;
    int one = 1;
    short cmpv = (short)one;
    short chosen;
    if (cmpv < qs) {
        chosen = qs;
    } else {
        chosen = (short)one;
    }
    *(short*)((char*)&w10 + ecx2) = chosen;

    float f2c = field2c + fc;
    float local_1c = f2c;

    short other = *(short*)((char*)&e + ecx2);
    *(short*)((char*)&w12 + ecx2) = other;

    Vec2 v1;
    sub_575590(&v1, &local_1c);
    float n1x = -v1.x;
    float n1y = -v1.y;

    Vec2 v2;
    sub_575590(&v2, &n1x);

    float z = 0.0f;
    float l28 = z, l2c = z, l14 = z, l18 = z;

    int mode = f;
    if (mode == 0) {
        if (idx == 0) {
            l28 = g_8C01C4;
            l2c = g_8BAD4C;
            float* p = &l18;
            p[esi] = g_8BAD4C;
        } else {
            l2c = z;
            sub_52C1A0(idx);
            float t = g_8BD044 * l2c;
            l2c = t;
            l14 = g_8CA3E4;
            if (esi == 1) {
                l14 = -l14;
            }
        }
    } else if (mode == 1) {
        l28 = z;
        l2c = field28;
        l14 = field24;
        l18 = -field28;
    } else if (mode == 2) {
        l28 = z;
        l2c = z;
        l14 = z;
        l18 = z;
    }

    int i = 0;
    while (i < ebp) {
        float tmp;
        if (i == ebp - 1) {
            tmp = arr[esi];
            float* p30 = &l28;
            p30[esi] = tmp;
            if (f == 0 && local_28 != 0) {
                float diff = tmp - l18;
                float prod = diff * l14;
                l14 = prod * g_8C01C4;
            }
        } else {
            float* p30 = &l28;
            p30[esi] = l18 + g_8BE5AC;
        }

        float args[2];
        args[0] = l14;
        args[1] = l28;
        float args2[2];
        args2[0] = l2c;
        args2[1] = l18;
        float args3[5];
        args3[0] = l28;
        args3[1] = l2c;
        args3[2] = l14;
        args3[3] = l18;
        args3[4] = l28;

        sub_52DB40(args3, args2, args);
        sub_556240((void*)&local_2c, d);

        l18 = (&l28)[esi];
        i++;
    }
}
