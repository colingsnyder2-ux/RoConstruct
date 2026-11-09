// from server: 30% by colin
// roc 2007-08 004e8c60  unit: TorsoBuilder  size: 853 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004e8c60

extern "C" void __cdecl sub_5B99F0(void*, void*);
extern "C" void* __cdecl sub_62FF32(unsigned int);
extern "C" void __cdecl sub_62FF26(void*);
extern "C" void* __cdecl sub_501570();
extern "C" void __cdecl sub_4F54E0(void*);
extern "C" void* __cdecl sub_4F5360(void*, void*, void*, int);
extern "C" void __cdecl sub_4EEE30(void*, int, int, int, int);

struct TorsoBuilder {
    void build(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l);
};

void TorsoBuilder::build(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l)
{
    float v[3];
    sub_5B99F0((char*)this + 4, v);

    float ax = v[0] < 0 ? -v[0] : v[0];
    float ay = v[1] < 0 ? -v[1] : v[1];
    float az = v[2] < 0 ? -v[2] : v[2];

    int n0 = *(short*)((char*)&a + 0x28);
    int n1 = *(short*)((char*)&a + 0x2a);

    int count = (n0 + 1) * (n1 + 1);
    void** arr = (void**)sub_62FF32(count * 4);

    float f0 = (float)n0;
    float f1 = *(float*)((char*)&a + 0x08) - *(float*)((char*)&a + 0x00);
    float f2 = *(float*)((char*)&a + 0x0c) - *(float*)((char*)&a + 0x04);
    float f3 = *(float*)((char*)&a + 0x1c);
    float f4 = *(float*)((char*)&a + 0x20);

    float d0 = f1 / f0;
    float d1 = f2 / (float)n1;
    float d2 = f3 / ax;
    float d3 = f4 / ay;

    float base0 = *(float*)((char*)&a + 0x00);
    float base1 = *(float*)((char*)&a + 0x14);
    float base2 = *(float*)((char*)&a + 0x18);

    int idx = 0;
    float cur0 = base0;
    for (int i0 = 0; i0 <= n0; i0++) {
        float cur1 = base1;
        for (int i1 = 0; i1 <= n1; i1++) {
            float p[3];
            p[0] = cur0;
            p[1] = cur1;
            p[2] = base2;

            float q[3];
            q[0] = cur0;
            q[1] = cur1;
            q[2] = base2;

            float r[3];
            r[0] = cur0;
            r[1] = cur1;
            r[2] = base2;

            float s[3];
            s[0] = cur0;
            s[1] = cur1;
            s[2] = base2;

            void* res = sub_4F5360(s, r, q, 1);
            arr[idx] = res;
            idx++;

            float* chk = (float*)sub_501570();
            if (chk[0] == f3 && chk[1] == f4) {
                p[0] = *(float*)((char*)&a + 0x14);
                p[1] = *(float*)((char*)&a + 0x18);
            }

            float t0 = p[0] * 0.5f;
            float t1 = p[1] * 0.5f;
            float t2 = p[2] * 0.5f;

            float u[3];
            sub_5B99F0(&t0, u);
            float w[3];
            sub_5B99F0(&t1, w);

            cur1 += d1;
        }
        cur0 += d0;
    }

    for (unsigned int m = 0; m < (unsigned int)count; m++) {
        sub_4F54E0(arr[m]);
    }
    sub_62FF26(arr);
}
