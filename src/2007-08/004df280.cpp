// from server: 18% by colin
struct Level {
    char pad0[4];
    int field4;
    char pad8[0x30];
    int field38;

    void method(float f14, float f18, float f1c, float f20,
    float f24, float f28, float f2c, float f30,
    float f34, int n38, short s3c, short s3e);
};

extern "C" void __cdecl sub_5b99d0(void*, void*);
extern "C" void* __cdecl sub_62ff32(unsigned int);
extern "C" void* __cdecl sub_501570();
extern "C" void __cdecl sub_4f5360(void*, void*, void*, int);
extern "C" void __cdecl sub_4eee30(void*, int, int, int, int);
extern "C" void __cdecl sub_4f54e0(void*);
extern "C" void __cdecl sub_62ff26(void*);

extern float g_79f2b8;
extern double g_795b48;

void Level::method(
    float f14, float f18, float f1c, float f20,
    float f24, float f28, float f2c, float f30,
    float f34, int n38, short s3c, short s3e)
{
    float local38[3];
    sub_5b99d0(&field4, local38);

    float a0 = local38[0];
    float a1 = local38[1];
    float a2 = local38[2];

    float fa0 = a0 < 0 ? -a0 : a0;
    float fa1 = a1 < 0 ? -a1 : a1;
    float fa2 = a2 < 0 ? -a2 : a2;

    int si = s3c;
    int bx = s3e;

    int count = (si + 1) * (bx + 1);
    void* arr = sub_62ff32(count * 4);

    float stepX = (f1c - f14) / (float)si;
    float stepY = (f20 - f18) / (float)si;
    float stepZ = f30 / (float)si;
    float stepW = f34 / (float)si;

    float baseX = f14;
    float baseY = f18;
    float baseZ = f28;
    float baseW = f2c;

    int idx = 0;
    int rowBase = 0;

    if (si >= 0) {
        int outerCount = si + 1;
        float curZ = baseZ;
        float curW = baseW;
        float curY = baseY;
        float curX = baseX;

        for (int i = 0; i < outerCount; i++) {
            float zz = curZ;
            float ww = curW;
            float yy = curY;
            float xx = curX;

            if (bx >= 0) {
                int innerCount = bx + 1;
                int colBase = rowBase;
                float innerX = xx;
                float innerY = yy;

                for (int j = 0; j < innerCount; j++) {
                    float v0 = innerX;
                    float v1 = innerY;
                    float v2 = zz;
                    float v3 = ww;

                    float t = v0 * g_79f2b8;
                    float u = v1 * g_79f2b8;

                    float p0 = v2 + t;
                    float p1 = v3 + u;

                    float q0 = v2 - t;
                    float q1 = v3 - u;

                    float r0 = v2 + t;
                    float r1 = v3 - u;

                    float s0 = v2 - t;
                    float s1 = v3 + u;

                    float out0 = p0;
                    float out1 = p1;
                    float out2 = q0;
                    float out3 = q1;

                    float tmp0 = r0;
                    float tmp1 = r1;
                    float tmp2 = s0;
                    float tmp3 = s1;

                    float farr[4];
                    farr[0] = out0;
                    farr[1] = out1;
                    farr[2] = out2;
                    farr[3] = out3;

                    float farr2[4];
                    farr2[0] = tmp0;
                    farr2[1] = tmp1;
                    farr2[2] = tmp2;
                    farr2[3] = tmp3;

                    float farr3[4];
                    farr3[0] = out0;
                    farr3[1] = out1;
                    farr3[2] = out2;
                    farr3[3] = out3;

                    float farr4[4];
                    farr4[0] = tmp0;
                    farr4[1] = tmp1;
                    farr4[2] = tmp2;
                    farr4[3] = tmp3;

                    void* res = 0;
                    sub_4f5360(&res, farr3, farr4, 1);

                    ((void**)arr)[colBase] = res;

                    colBase++;
                    innerX += stepX;
                    innerY += stepY;
                }
            }

            rowBase += (bx + 1);
            curZ += stepZ;
            curW += stepW;
            curY += stepY;
            curX += stepX;
        }
    }

    if (si > 0) {
        int outerCount = si;
        int rBase = 0;
        int cBase = bx + 2;

        for (int i = 0; i < outerCount; i++) {
            if (bx > 0) {
                int innerCount = bx;
                int r = rBase;
                int c = cBase;

                for (int j = 0; j < innerCount; j++) {
                    int v00 = ((int*)arr)[r];
                    int v01 = ((int*)arr)[r + 1];
                    int v10 = ((int*)arr)[c];
                    int v11 = ((int*)arr)[c + 1];

                    sub_4eee30((void*)field38, v00, v01, v10, v11);

                    r++;
                    c++;
                }
            }
            rBase += (bx + 1);
            cBase += (bx + 1);
        }
    }

    unsigned int n = (unsigned int)count;
    for (unsigned int k = 0; k < n; k++) {
        sub_4f54e0(((void**)arr)[k]);
    }

    sub_62ff26(arr);
}
