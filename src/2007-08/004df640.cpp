// from server: 25% by colin
struct Level {
    void build(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n);
};

extern "C" void __cdecl sub_5B9970(float* dst, float* src);
extern "C" void* __cdecl sub_62FF32(int size);
extern "C" void __cdecl sub_62FF26(void* p);
extern "C" void* __cdecl sub_501570();
extern "C" void* __cdecl sub_4F5360(void* a, void* b, void* c, int d);
extern "C" void __cdecl sub_4F54E0(void* p);
extern "C" void __cdecl sub_4EEE30(void* self, int a, int b, int c, int d);

extern float flt_79F2B8;
extern double dbl_795B48;

void Level::build(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n)
{
    float tmp[3];
    sub_5B9970(tmp, (float*)((char*)this + 4));

    float f0 = tmp[0];
    if (f0 < 0) f0 = -f0;
    float f1 = tmp[1];
    if (f1 < 0) f1 = -f1;
    float f2 = tmp[2];
    if (f2 < 0) f2 = -f2;

    int esi = *(short*)((char*)&n + 4);
    int ebx = *(short*)((char*)&n + 6);

    int edi = (ebx + 1) * (esi + 1);

    float fa = (float)esi;
    float fb = (float)ebx;

    float fc = (float)(*(int*)((char*)&n + 0x1c) - *(int*)((char*)&n + 0x14));
    float fd = (float)(*(int*)((char*)&n + 0x20) - *(int*)((char*)&n + 0x18));

    float fe = fc / fa;
    float ff = fd / fb;

    float fg = *(float*)((char*)&n + 0x30);
    float fh = *(float*)((char*)&n + 0x34);

    float fi = fg / fa;
    float fj = fh / fb;

    void* mem = sub_62FF32(edi * 4);

    float fk = *(float*)((char*)&n + 0x14);
    float fl = *(float*)((char*)&n + 0x28);

    void* base = mem;

    if (esi >= 0) {
        float fm = *(float*)((char*)&n + 0x18);
        float fn = *(float*)((char*)&n + 0x2c);

        int outer = esi + 1;
        void* rowptr = mem;

        if (ebx >= 0) {
            int inner = ebx + 1;
            float fpos = fk;
            float fpos2 = fm;
            float fstep = fe;
            float fstep2 = ff;
            float fstep3 = fi;
            float fstep4 = fj;
            float fz = 0.0f;

            do {
                float fcur = fpos;
                float fcur2 = fpos2;
                float fcur3 = fz;
                float fcur4 = fz;

                int cnt = inner;
                void* p = rowptr;
                do {
                    float fv0 = fcur;
                    float fv1 = fcur2;
                    float fv2 = fcur3;
                    float fv3 = fcur4;

                    float fw = 1.0f;
                    if (fw < fcur3) {
                        fv2 = fcur3 - flt_79F2B8;
                    } else {
                        fv2 = fcur3 + flt_79F2B8;
                    }

                    float fv4 = fv2 - fl;

                    float farr[3];
                    farr[0] = fv0;
                    farr[1] = fv1;
                    farr[2] = fv4;

                    int idx = 0;
                    do {
                        if (*(char*)((char*)&n + idx + 0x10) != 0) {
                            float t = farr[idx];
                            t = t * *(float*)((char*)&n + idx * 4 + 8);
                            t = t / *(float*)((char*)&n + idx * 4 + 0x7c);
                            farr[idx] = t;
                        } else {
                            farr[idx] = *(float*)((char*)&n + idx * 4 + 8);
                        }
                        idx++;
                    } while (idx < 2);

                    void* q = sub_501570();
                    float* qf = (float*)q;
                    if (qf[0] == *(float*)((char*)&n + 0x24) && qf[1] == *(float*)((char*)&n + 0x28)) {
                        fv0 = fl;
                        fv1 = fn;
                    }

                    float fw2 = fv0 * (float)dbl_795B48;
                    float fw3 = fv1 * (float)dbl_795B48;

                    float farr2[3];
                    farr2[0] = fw2;
                    farr2[1] = fw3;
                    farr2[2] = fv4;

                    float farr3[3];
                    sub_5B9970(farr3, farr2);

                    void* r = sub_4F5360(farr3, farr, farr2, 1);
                    *(void**)p = r;

                    fcur += fstep;
                    fcur2 += fstep2;
                    fcur3 += fstep3;
                    fcur4 += fstep4;

                    p = (char*)p + 4;
                    cnt--;
                } while (cnt != 0);

                fpos += fstep;
                fpos2 += fstep2;
                rowptr = (char*)rowptr + (ebx + 1) * 4;
                outer--;
            } while (outer != 0);
        }

        if (n > 0) {
            void* p1 = base;
            void* p2 = (char*)base + ebx * 4 + 8;
            int cnt2 = n;
            do {
                if (ebx > 0) {
                    void* s1 = p1;
                    void* s2 = p2;
                    int cnt3 = ebx;
                    do {
                        int v0 = *(int*)s2;
                        int v1 = *(int*)((char*)s2 - 4);
                        int v2 = *(int*)s1;
                        int v3 = *(int*)((char*)s1 + 4);
                        sub_4EEE30(this, v2, v3, v1, v0);
                        s2 = (char*)s2 + 4;
                        s1 = (char*)s1 + 4;
                        cnt3--;
                    } while (cnt3 != 0);
                }
                p1 = (char*)p1 + (ebx + 1) * 4;
                p2 = (char*)p2 + (ebx + 1) * 4;
                cnt2--;
            } while (cnt2 != 0);
        }
    }

    unsigned int total = (unsigned int)edi;
    unsigned int idx = 0;
    if (total > 0) {
        do {
            void* p = *(void**)((char*)base + idx * 4);
            sub_4F54E0(p);
            idx++;
        } while (idx < total);
    }

    sub_62FF26(base);
}
