// from server: 38% by atomic.potato
struct Vec3 { float x, y, z; };

extern "C" void __cdecl sub_682df0(Vec3* dst, const Vec3* src);
extern "C" float* __cdecl sub_56cb90();
extern "C" void* __cdecl sub_718d1a(int);
extern "C" void __cdecl sub_718cde(void*);
extern "C" void __cdecl sub_5596b0(void*, void*, void*, void*, void*, void*);

struct SphereBuilder {
    char pad0[4];
    void* field4;
    char pad8[0x8c];
    void build(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8,
               int a9, int a10, int a11, int a12, int a13, int a14, int a15,
               int a16, int a17, int a18, int a19, int a20, int a21, int a22,
               int a23, int a24, int a25, int a26, int a27, int a28, int a29,
               int a30, int a31, int a32, int a33, int a34, int a35);
};

void SphereBuilder::build(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8,
                          int a9, int a10, int a11, int a12, int a13, int a14, int a15,
                          int a16, int a17, int a18, int a19, int a20, int a21, int a22,
                          int a23, int a24, int a25, int a26, int a27, int a28, int a29,
                          int a30, int a31, int a32, int a33, int a34, int a35)
{
    Vec3 tmp;
    sub_682df0(&tmp, (const Vec3*)((char*)this + 8));

    float f0 = tmp.x; if (f0 < 0) f0 = -f0;
    float f1 = tmp.y; if (f1 < 0) f1 = -f1;
    float f2 = tmp.z; if (f2 < 0) f2 = -f2;

    int n1 = *(short*)((char*)&a1 + 0x100 - 0x8c);
    int n2 = *(short*)((char*)&a1 + 0x102 - 0x8c);
    (void)n1; (void)n2;

    float d1 = *(float*)((char*)&a1 + 0xe0 - 0x8c) - *(float*)((char*)&a1 + 0xd8 - 0x8c);
    float d2 = *(float*)((char*)&a1 + 0xe4 - 0x8c) - *(float*)((char*)&a1 + 0xdc - 0x8c);

    int cnt1 = *(short*)((char*)&a1 + 0x100 - 0x8c) + 1;
    int cnt2 = *(short*)((char*)&a1 + 0x102 - 0x8c) + 1;

    float step1 = d1 / (float)cnt1;
    float step2 = d2 / (float)cnt2;

    float r1 = *(float*)((char*)&a1 + 0xf8 - 0x8c) / *(float*)((char*)&a1 + 0xfc - 0x8c);
    float r2 = *(float*)((char*)&a1 + 0xfc - 0x8c) / *(float*)((char*)&a1 + 0xf8 - 0x8c);

    int total = cnt1 * cnt2;
    void* arr = sub_718d1a(total * 4);

    float base1 = *(float*)((char*)&a1 + 0xdc - 0x8c);
    float base2 = *(float*)((char*)&a1 + 0xf0 - 0x8c);

    int i = 0;
    float acc1 = 0.0f;
    float acc2 = base1;
    float acc3 = 0.0f;
    float acc4 = base2;

    while (i <= *(short*)((char*)&a1 + 0x100 - 0x8c)) {
        int j = 0;
        float v1 = 0.0f;
        float v2 = acc2;
        while (j <= *(short*)((char*)&a1 + 0x102 - 0x8c)) {
            Vec3 p;
            p.x = v1;
            p.y = v2;
            p.z = acc3;
            float* q = sub_56cb90();
            int eq = (q[0] == *(float*)((char*)&a1 + 0xec - 0x8c) &&
                      q[1] == *(float*)((char*)&a1 + 0xf0 - 0x8c)) ? 1 : 0;
            Vec3 p2;
            p2.x = *(float*)((char*)&a1 + 0x60 - 0x8c);
            p2.y = f0;
            p2.z = f2;
            sub_5596b0(this, &p, &p2, &p, (void*)eq, 0);
            int idx = (*(short*)((char*)&a1 + 0xfa - 0x8c) + 1) * i + j;
            ((int*)arr)[idx] = 0;
            v1 += step1;
            v2 += f1;
            j++;
        }
        acc2 += step2;
        acc3 += f2;
        i++;
    }

    int k = 0;
    while (k < *(short*)((char*)&a1 + 0xf8 - 0x8c)) {
        int m = 0;
        while (m < *(short*)((char*)&a1 + 0xfa - 0x8c)) {
            int base = (*(short*)((char*)&a1 + 0xfa - 0x8c) + 1) * k + m;
            int* p = (int*)arr;
            void* v0 = (void*)p[base];
            void* v1 = (void*)p[base + 1];
            void* v2 = (void*)p[base + *(short*)((char*)&a1 + 0xfa - 0x8c) + 1];
            void* v3 = (void*)p[base + *(short*)((char*)&a1 + 0xfa - 0x8c) + 2];
            void** vt = (void**)(*(void**)this->field4);
            void (*fn)(void*, void*, void*, void*) = (void (*)(void*, void*, void*, void*))vt[6];
            fn(v0, v1, v2, v3);
            m++;
        }
        k++;
    }

    sub_718cde(arr);
}
