// from server: 27% by colin
// roc 2007-08 004e2030  unit: PBBBuilder  size: 757 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004e2030

extern "C" {
    void __cdecl sub_5b9990(void* dst, const void* src);
    void* __cdecl sub_62ff32(unsigned int size);
    void __cdecl sub_62ff26(void* p);
    void __cdecl sub_4f54e0(void* p);
    void* __cdecl sub_4f5360(void* a, void* b, void* c, int d);
    void __cdecl sub_4eee30(void* self, int a, int b, int c, int d);
    void* __cdecl sub_501570();
}

struct PBBBuilder {
    char pad0[4];
    int field4;
    void build(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l);
};

void PBBBuilder::build(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l)
{
    char buf[0x58];
    sub_5b9990(buf, &field4);

    int esi = *(short*)((char*)&a + 0x28);
    int ebx = *(short*)((char*)&a + 0x2a);

    float f1 = (float)esi;
    float f2 = *(float*)((char*)&a + 8) - *(float*)((char*)&a + 0);
    float f3 = f2 / f1;

    int edi = (ebx + 1) * (esi + 1);
    int* arr = (int*)sub_62ff32(edi * 4);

    float f4 = (float)ebx;
    float f5 = *(float*)((char*)&a + 0xc) - *(float*)((char*)&a + 4);
    float f6 = f5 / f4;

    float f7 = *(float*)((char*)&a + 0x1c) / f1;
    float f8 = *(float*)((char*)&a + 0x20) / f4;

    float f9 = *(float*)((char*)&a + 0);
    float f10 = *(float*)((char*)&a + 4);
    float f11 = *(float*)((char*)&a + 0x14);
    float f12 = *(float*)((char*)&a + 0x18);

    int* p = arr;
    if (esi >= 0) {
        float f13 = *(float*)((char*)&a + 0x10);
        float f14 = *(float*)((char*)&a + 0x1c);
        int cnt1 = esi + 1;
        if (ebx >= 0) {
            int cnt2 = ebx + 1;
            do {
                float f15 = f9;
                float f16 = f10;
                float f17 = f11;
                float f18 = f12;
                do {
                    float v1 = f15;
                    float v2 = f16;
                    float v3 = f17;
                    float v4 = f18;
                    float v5 = f13;
                    float v6 = f14;
                    float v7 = 1.0f;
                    if (v1 < v6) {
                        v5 = v5 + v5 - v6;
                    } else {
                        v5 = v5 + v6;
                    }
                    float v8;
                    if (v2 > v5) {
                        v8 = v2 - v5;
                    } else {
                        v8 = -v5 - v2;
                    }
                    void* r = sub_501570();
                    if (*(float*)r == *(float*)((char*)&a + 0x1c) &&
                        *(float*)((float*)r + 1) == *(float*)((char*)&a + 0x20)) {
                        v1 = *(float*)((char*)&a + 0x14);
                        v2 = *(float*)((char*)&a + 0x18);
                    }
                    float v9 = v1 * *(double*)0x795b48;
                    float v10 = v2 * *(float*)((char*)&a + 0x10);
                    float tmp1[3];
                    tmp1[0] = v9;
                    tmp1[1] = v10;
                    tmp1[2] = 1.0f;
                    float tmp2[3];
                    sub_5b9990(tmp2, tmp1);
                    float tmp3[3];
                    sub_5b9990(tmp3, &v5);
                    void* res = sub_4f5360(tmp3, tmp2, tmp1, 1);
                    *p = (int)res;
                    p++;
                    f13 = f13 + f7;
                    f14 = f14 + f8;
                    cnt2--;
                } while (cnt2 != 0);
            } while (--cnt1 != 0);
        }
    }

    if (edi > 0) {
        int cnt = edi;
        int* q = arr;
        do {
            sub_4f54e0((void*)*q);
            q++;
            cnt--;
        } while (cnt != 0);
    }
    sub_62ff26(arr);
}
