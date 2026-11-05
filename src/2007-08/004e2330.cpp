// from server: 36% by colin
// roc 2007-08 004e2330  unit: PBBBuilder  size: 773 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004e2330

extern "C" void __cdecl sub_5B99D0(void*, void*);
extern "C" void* __cdecl sub_62FF32(unsigned int);
extern "C" void __cdecl sub_62FF26(void*);
extern "C" void* __cdecl sub_501570();
extern "C" void* __cdecl sub_4F5360(void*, void*, void*, int);
extern "C" void __cdecl sub_4F54E0(void*);
extern "C" void __cdecl sub_4EEE30(void*, void*, void*, void*);

struct PBBBuilder {
    void sub_4E2330(
        float a1, float a2, float a3, float a4,
        float a5, float a6, float a7, float a8,
        float a9, float a10, float a11, float a12,
        int a13, int a14, int a15, int a16, int a17);
};

void PBBBuilder::sub_4E2330(
    float a1, float a2, float a3, float a4,
    float a5, float a6, float a7, float a8,
    float a9, float a10, float a11, float a12,
    int a13, int a14, int a15, int a16, int a17)
{
    char buf[0x60];
    sub_5B99D0(buf, (char*)this + 4);

    short s14 = (short)a14;
    short s15 = (short)a15;
    int n14 = s14;
    int n15 = s15;

    float f20 = a4 - a1;
    float f21 = a8 - a5;
    float f22 = a12 - a9;

    float d20 = f20 / (float)n14;
    float d21 = f21 / (float)n15;
    float d22 = f22 / (float)n15;

    float r20 = a3 / f20;
    float r21 = a7 / f21;
    float r22 = a11 / f22;

    int count = (n14 + 1) * (n15 + 1);
    void** arr = (void**)sub_62FF32((unsigned int)count * 4);

    float cur1 = a1;
    float cur2 = a5;
    float cur3 = a9;

    if (n14 >= 0) {
        float step1 = a2;
        float step2 = a6;
        float step3 = a10;
        int i = n14 + 1;
        if (n15 >= 0) {
            int j = n15 + 1;
            void** p = arr;
            do {
                float v1 = cur1;
                float v2 = cur2;
                float v3 = cur3;
                float t1 = v1;
                float t2 = v2;
                float t3 = 1.0f;
                float w = step1;
                if (w < t1) {
                    float diff = t1 - w;
                    float ad = diff < 0 ? -diff : diff;
                    float r = 1.0f - ad;
                    r = r * a3;
                    t1 = r;
                } else {
                    float sum = w + t3;
                    if (sum > t1) {
                        t1 = sum - t1;
                    } else {
                        t1 = t1 + t3;
                    }
                }
                void* q = sub_501570();
                float* qf = (float*)q;
                if (qf[0] == a11 && qf[1] == a12) {
                    t1 = cur1;
                    t2 = cur2;
                }
                float u1 = t1 * 0.5f;
                float u2 = t2 * 0.5f;
                float u3 = t3 * 0.5f;
                char tmp1[0x10];
                char tmp2[0x10];
                sub_5B99D0(tmp1, &u1);
                sub_5B99D0(tmp2, &u3);
                void* res = sub_4F5360(tmp2, tmp1, &u1, 1);
                *p = res;
                p++;
                cur1 = u1 + d20;
                cur2 = u2 + d21;
                cur3 = u3 + d22;
                j--;
            } while (j != 0);
        }
        cur1 = cur1 + step1;
        cur2 = cur2 + step2;
        cur3 = cur3 + step3;
        i--;
    }

    if (n15 > 0) {
        void** p = arr;
        int j = n15;
        do {
            if (n14 > 0) {
                int k = n14;
                void** q = p;
                do {
                    void* v1 = q[0];
                    void* v2 = q[1];
                    void* v3 = q[n15 + 1];
                    void* v4 = q[n15 + 2];
                    sub_4EEE30(v4, v3, v2, v1);
                    q++;
                    k--;
                } while (k != 0);
            }
            p += n14 + 1;
            j--;
        } while (j != 0);
    }

    unsigned int total = (unsigned int)count;
    unsigned int idx = 0;
    if (total > 0) {
        do {
            sub_4F54E0(arr[idx]);
            idx++;
        } while (idx < total);
    }
    sub_62FF26(arr);
}
