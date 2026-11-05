// from server: 30% by colin
// roc 2007-08 004e8240  unit: TorsoMesh  size: 853 bytes
// Compile with VS2005 /O2 /GS- /EHsc /MD

extern "C" void __cdecl sub_5B9990(float* dst, float* src);
extern "C" void* __cdecl sub_62FF32(unsigned int size);
extern "C" void __cdecl sub_62FF26(void* p);
extern "C" void __cdecl sub_4F54E0(void* p);
extern "C" void* __cdecl sub_4F5360(void* a, void* b, void* c, void* d, int e);
extern "C" void __cdecl sub_4EEE30(void* self, int a, int b, int c, int d);
extern "C" float* __cdecl sub_501570();

struct TorsoBuilder {
    char pad0[4];
    float field4;
    void build(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12);
};

void TorsoBuilder::build(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12)
{
    float local_40[3];
    float local_34;
    float local_30;
    float local_2c;
    float local_28;
    float local_24;
    float local_20;
    float local_1c;
    float local_18;
    float local_14;
    float local_10;
    float local_c;
    float local_8;
    float local_4;

    sub_5B9990(local_40, &field4);

    float fabs0 = local_40[0] < 0 ? -local_40[0] : local_40[0];
    float fabs1 = local_40[1] < 0 ? -local_40[1] : local_40[1];
    float fabs2 = local_40[2] < 0 ? -local_40[2] : local_40[2];

    int n0 = (short)a1;
    int n1 = (short)a2;
    int count = (n1 + 1) * (n0 + 1);

    float f0 = (float)n0;
    float f1 = (float)n1;

    float d0 = *(float*)((char*)this + 0x14) - *(float*)((char*)this + 0xc);
    float d1 = *(float*)((char*)this + 0x18) - *(float*)((char*)this + 0x10);

    float r0 = d0 / f0;
    float r1 = d1 / f1;

    float r2 = *(float*)((char*)this + 0x28) / fabs0;
    float r3 = *(float*)((char*)this + 0x2c) / fabs1;
    float r4 = *(float*)((char*)this + 0x28) / fabs2;

    void* mem = sub_62FF32(count * 4);

    float base0 = *(float*)((char*)this + 0xc);
    float base1 = *(float*)((char*)this + 0x10);
    float base2 = *(float*)((char*)this + 0x20);
    float base3 = *(float*)((char*)this + 0x24);

    void** arr = (void**)mem;
    int i = 0;
    if (n0 >= 0) {
        float acc0 = 0.0f;
        float acc1 = base1;
        float acc2 = base3;
        int row = 0;
        while (true) {
            if (n1 >= 0) {
                int j = 0;
                float col0 = acc0;
                float col1 = acc1;
                float col2 = acc2;
                do {
                    float v0 = col0;
                    float v1 = col1;
                    float v2 = col2;
                    float v3 = *(float*)((char*)this + 0x1c);
                    float v4 = 1.0f;

                    float out0, out1, out2, out3;
                    void* res = sub_4F5360(&out0, &v0, &v1, &v2, 1);

                    float* p = sub_501570();
                    if (p[0] == *(float*)((char*)this + 0x28) && p[1] == *(float*)((char*)this + 0x2c)) {
                        v0 = *(float*)((char*)this + 0x20);
                        v1 = *(float*)((char*)this + 0x24);
                    }

                    float t0 = v0 * 0.5f;
                    float t1 = v1 * 0.5f;

                    float uv0[2], uv1[2];
                    sub_5B9990(uv0, &t0);
                    sub_5B9990(uv1, &t1);

                    void* res2 = sub_4F5360(uv0, uv1, &out0, &out1, 1);

                    arr[row * (n1 + 1) + j] = res2;

                    col0 += r0;
                    col1 += r1;
                    col2 += r2;
                    j++;
                } while (j <= n1);
            }
            acc0 += r3;
            acc1 += r4;
            row++;
            if (row > n0) break;
        }
    }

    if (n0 > 0) {
        int r = 0;
        int idx = 0;
        do {
            if (n1 > 0) {
                int c = 0;
                do {
                    sub_4EEE30(this, (int)arr[idx], (int)arr[idx + 1], (int)arr[idx + n1 + 1], (int)arr[idx + n1 + 2]);
                    idx++;
                    c++;
                } while (c < n1);
            }
            idx += n1 + 1;
            r++;
        } while (r < n0);
    }

    unsigned int k = 0;
    if (count > 0) {
        do {
            sub_4F54E0(arr[k]);
            k++;
        } while (k < (unsigned int)count);
    }

    sub_62FF26(mem);
}
