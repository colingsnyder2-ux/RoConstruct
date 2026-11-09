// from server: 21% by colin
// roc 2007-08 007369e0  unit: G3D::Sky  size: 927 bytes

struct Sky {
    int field0;
    char pad[0x4a8 - 4];
    float field4a8;
    float field4ac;
    float field4b0;
    float field4b4;
    char pad2[0x890 - 0x4b8];
    double field890;

    void render(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, float* out);
};

extern "C" {
    void __stdcall sub_474f70(int);
    void __stdcall sub_476250(int);
    void __stdcall sub_474680(int, int);
    void __stdcall sub_474170(int, int, int);
    void __stdcall sub_473cd0(int, int, double);
    void __stdcall sub_4796d0(int);
    void __stdcall sub_475470(int);
    void __stdcall sub_4779e0(int);
    void __stdcall sub_4ff7f0(void*);
    void* __stdcall sub_500010(unsigned int);
    void __stdcall sub_736100(int, int, int, double, double, double, double, int, int);
    void __stdcall sub_8bd8f0(int);
    void __stdcall sub_77e6d8();
    void __stdcall glColor4fv(const float*);
    void __stdcall glDisableClientState(unsigned int);
    void __stdcall glDrawArrays(unsigned int, int, int);
    void __stdcall glEnableClientState(unsigned int);
    void __stdcall glMatrixMode(unsigned int);
    void __stdcall glTexCoordPointer(int, unsigned int, int, const void*);
    void __stdcall glTranslatef(float, float, float);
    void __stdcall glVertexPointer(int, unsigned int, int, const void*);
}

extern double g_7e8da0;
extern double g_79f2e0;
extern char g_8bcf62;
extern void* g_8bd8f0;
extern void* g_77e6d8;
extern void* g_77ea38;
extern void* g_77ea44;
extern void* g_77ea4c;
extern void* g_77ea50;
extern void* g_77ea88;
extern void* g_77eb0c;
extern void* g_77eb64;
extern void* g_77ebac;

void Sky::render(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, float* out)
{
    field0 = 0;
    sub_474f70(j);
    sub_476250(0);
    sub_474680(0, 4);
    sub_474170(0, 1, 2);
    sub_473cd0(2, 0, g_7e8da0);
    float f890 = (float)field890;
    if (g_8bcf62) {
        sub_8bd8f0(0x84c0);
    }
    int count = 0;
    unsigned int len = *(unsigned int*)(c + 0x14);
    unsigned int idx = 0;
    while (idx < len) {
        if (idx > len) {
            sub_77e6d8();
        }
        const char* str;
        if (*(unsigned int*)(c + 0x18) >= 0x10) {
            str = *(const char**)(c + 4);
        } else {
            str = (const char*)(c + 4);
        }
        signed char ch = str[idx];
        int v = ch & 0x8000007f;
        if (v < 0) {
            v = (v - 1) | 0xffffff80;
            v = v + 1;
        }
        if (v != 0x20) count++;
        idx++;
        len = *(unsigned int*)(c + 0x14);
    }
    if (count == 0) {
        sub_4796d0(0);
        *out = 0.0f;
        out[1] = f890;
        return;
    }
    void* buf = sub_500010(count * 64);
    sub_736100((int)buf, c, d, (double)f890, (double)e, (double)f, (double)g, h, i);
    sub_4779e0(0);
    void* p1 = g_77ea4c;
    ((void(__stdcall*)(int))p1)(0x8078);
    ((void(__stdcall*)(int))p1)(0x8074);
    glEnableClientState(2);
    glVertexPointer(0x1406, 0x10, 2, buf);
    glTexCoordPointer(0x1406, 0x10, 2, (char*)buf + 8);
    float scale = *(float*)(d + 0xc);
    if (scale == (float)g_79f2e0) {
        // skip
    } else {
        float sx = *(float*)d * f890;
        float sy = *(float*)(d + 4) * f890;
        float sz = *(float*)(d + 8) * f890;
        float sw = *(float*)(d + 0xc);
        float* dst = (float*)((char*)this + 0x4a8);
        dst[0] = sx;
        dst[1] = sy;
        dst[2] = sz;
        dst[3] = sw;
        glMatrixMode(0x1700);
        int x0 = -1;
        int y0 = -1;
        float fx = 0.0f;
        float fy = 0.0f;
        while (1) {
            if (y0 == 0 && x0 == 0) break;
            float fyf = (float)y0;
            float fxf = (float)x0;
            glTranslatef(fxf - fx, fyf - fy, 0.0f);
            glDrawArrays(7, 0, count);
            fx = fxf;
            fy = fyf;
            y0 += 2;
            if (y0 <= 1) continue;
            x0 += 2;
            if (x0 <= 1) continue;
            glTranslatef(-fx, -fy, 0.0f);
            break;
        }
    }
    float sx = *(float*)d * f890;
    float sy = *(float*)(d + 4) * f890;
    float sz = *(float*)(d + 8) * f890;
    float sw = *(float*)(d + 0xc);
    float* dst = (float*)((char*)this + 0x4a8);
    dst[0] = sx;
    dst[1] = sy;
    dst[2] = sz;
    dst[3] = sw;
    glMatrixMode(0x1700);
    glDrawArrays(7, 0, count);
    void* p2 = g_77ebac;
    ((void(__stdcall*)(int))p2)(0x8078);
    ((void(__stdcall*)(int))p2)(0x8074);
    sub_475470(0);
    sub_4796d0(0);
    sub_4ff7f0(buf);
    *out = f890;
    out[1] = f890;
}
