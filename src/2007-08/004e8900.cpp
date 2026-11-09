// from server: 39% by colin
// roc 2007-08 004e8900  unit: TorsoMesh  size: 853 bytes
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD

extern "C" {
    int __cdecl sub_5B99D0(void* dst, void* src);
    void* __cdecl sub_62FF32(int size);
    void __cdecl sub_62FF26(void* p);
    void __cdecl sub_4F54E0(void* p);
    int __cdecl sub_4F5360(void* a, void* b, void* c, int d);
    void __cdecl sub_4EEE30(void* self, int a, int b, int c, int d);
    float* __cdecl sub_501570();
}

extern double g_795B48;

struct TorsoBuilder {
    void build(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l);
};

void TorsoBuilder::build(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l)
{
    float v40[4];
    float v44[4];
    float v48[4];
    float v4c[4];
    float v50[4];
    float v54[4];
    float v58[4];
    float v5c[4];
    float v60[4];
    float v64[4];
    float v68[4];
    float v6c[4];
    float v70[4];
    float v74[4];
    float v78[4];
    float v7c[4];
    float v80[4];
    float v84[4];
    float v88[4];
    float v8c[4];

    sub_5B99D0(v40, (char*)this + 4);

    float f14 = (float)(int)(v40[1] < 0 ? -v40[1] : v40[1]);
    int eax = (int)(short)a;
    int ebx = (int)(short)b;
    float f84 = f14;
    float f18 = (float)(int)(v40[2] < 0 ? -v40[2] : v40[2]);
    float f88 = f18;
    float f1c = (float)(int)(v40[3] < 0 ? -v40[3] : v40[3]);
    float f8c = f1c;

    int esi = (ebx + 1) * (eax + 1);
    float f14b = (float)eax;
    float fdiv = (float)((double)e - (double)c) / f14b;
    float f58 = fdiv;
    float f18b = (float)ebx;
    float fdiv2 = (float)((double)f - (double)d) / f18b;
    float f5c = fdiv2;
    float f60 = (float)g / f14b;
    float f64 = (float)h / f18b;

    int* edi = (int*)sub_62FF32(esi * 4);

    float f30 = (float)c;
    float f28 = (float)e;
    int count = eax;
    int idx = 0;
    int* p10 = edi;

    if (count >= 0) {
        float fz = 0.0f;
        float f30b = (float)d;
        int esi2 = 0;
        float f2c = (float)f;

        if (ebx >= 0) {
            int ecx = i * 4;
            float* p5c = (float*)((char*)v40 + 0x20 - ecx);
            float* p48 = (float*)((char*)v40 + 0x1c + ecx);

            do {
                float f3c = v40[1];
                float f44 = f30b;
                float f48 = (float)e;
                float f20 = f44;
                float f24 = f44;
                *p5c = f2c;
                *p48 = f30b;

                float f70 = f48;
                float f78 = f48;
                float f80 = 1.0f;

                ((void (__stdcall*)(float*, float*, float*, float*, float*))a)(v40, v48, v44, v84, v88);

                float* pf = sub_501570();
                if (pf[0] == (float)g && pf[1] == (float)h) {
                    v44[0] = (float)e;
                    v44[1] = (float)f;
                }

                float t1 = v44[0] * (float)g_795B48;
                float t2 = v44[1] * (float)g_795B48;
                v7c[0] = t1;
                v80[0] = t2;

                sub_5B99D0(v68, v7c);
                sub_5B99D0(v44, v8c);

                int r = sub_4F5360(v8c, v84, v88, 1);
                *p10 = r;

                esi2++;
                f30b = f30b + f58;
                p10++;
                f2c = f2c + f5c;
                fz = 0.0f;
            } while (esi2 <= ebx);

            edi = p10 - (ebx + 1);
            eax = count;
        }

        f2c = f2c + v4c[0];
        idx++;
        f28 = f28 + v50[0];
        p10 = p10 + (ebx + 1);
    }

    if (eax > 0) {
        int* esi3 = edi;
        int* p10b = edi + ebx + 2;
        int cnt = eax;

        do {
            if (ebx > 0) {
                int* pdi = p10b;
                int n = ebx;
                do {
                    int edx = pdi[0];
                    int eax2 = pdi[-1];
                    int ecx = esi3[0];
                    int edx2 = esi3[1];
                    sub_4EEE30((void*)this, ecx, edx2, eax2, edx);
                    pdi++;
                    esi3++;
                } while (--n != 0);
                edi = p10b - (ebx + 1);
            }
            esi3 = esi3 + (ebx + 1);
            p10b = p10b + (ebx + 1);
            cnt--;
        } while (cnt != 0);
    }

    unsigned int total = (unsigned int)esi;
    unsigned int si = 0;
    if (total > 0) {
        do {
            sub_4F54E0((void*)edi[si]);
            si++;
        } while (si < total);
    }

    sub_62FF26(edi);
}
