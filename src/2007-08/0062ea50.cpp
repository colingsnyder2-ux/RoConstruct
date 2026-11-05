// from server: 17% by colin
struct V3 { float x, y, z; };
struct CF { float m[12]; };

struct AdornG3D {
    char pad0[0x24];
    float px, py, pz;
    char pad1[0x24];
    void* vt;
    void render3dAdornImpl(int, void*, void*);
    void render3dAdorn(int, void*, void*);
};

extern "C" {
    void __cdecl sub_506D40(void*);
    void __cdecl sub_5095D0(void*, void*);
    void* __cdecl sub_50A500();
    void* __cdecl sub_50B050();
    void* __cdecl sub_50B150();
    void __cdecl sub_62E7A0(void*, void*, int, float, float, void*);
    float __cdecl sub_62F100(void*, void*);
    void* __cdecl sub_736ED0();
}

extern float dword_79646C;
extern double qword_795B48;
extern double qword_79F340;
extern double qword_792AF8;
extern double qword_7A0BE8;
extern float dword_797E9C;
extern float dword_797EB0;
extern float dword_7A8340;
extern float dword_8C7FA8;
extern float dword_8C7FAC;
extern float dword_8C7FB0;
extern float dword_8BD12C;
extern float dword_8BD130;
extern float dword_8BD134;
extern int dword_8C7FB4;
extern int dword_8BD138;
extern int dword_79F77C;

void AdornG3D::render3dAdorn(int a1, void* a2, void* a3)
{
    float f0, f1, f2;
    float v54, v58, v5C;
    float v30, v34, v38;
    float v48, v4C, v50;
    int i;
    float* src = (float*)a1;
    float scale = (float)qword_795B48;
    v54 = src[0] * scale;
    v58 = src[1] * scale;
    v5C = src[2] * scale;
    float v14;
    for (i = 0; i < 2; i = i + 1) {
        if ((float)i > 1.0f) {
            v14 = dword_79646C;
        } else {
            v14 = 1.0f;
        }
        int mode = (int)a3;
        if (mode == 0 || mode == 2) {
            float t = v14;
            v30 = v54 * t;
            v34 = v58 * t;
            v38 = v5C * t;
            float* p = (float*)a2;
            v48 = p[9] + v30;
            v4C = p[10] + v34;
            v50 = p[11] + v38;
            void* tmp = sub_50A500();
            sub_5095D0((char*)&v30 - 0x40, tmp);
            void** vt = (void**)a3;
            void (*fn)(void*, void*) = (void (*)(void*, void*))vt[0x34/4];
            fn(a3, (char*)&v30 - 0x44);
            void* r = sub_50B050();
            float f = dword_797E9C;
            sub_62E7A0(a3, a2, 0, 1.0f, f, r);
        } else if (mode == 1) {
            float t = v14;
            v30 = v54 * t;
            v34 = v58 * t;
            v38 = v5C * t;
            float* p = (float*)a2;
            v48 = p[9] + v30;
            v4C = p[10] + v34;
            v50 = p[11] + v38;
            void* tmp = sub_50A500();
            sub_5095D0((char*)&v30 - 0x40, tmp);
            void** vt = (void**)a3;
            void (*fn)(void*, void*) = (void (*)(void*, void*))vt[0x34/4];
            fn(a3, (char*)&v30 - 0x44);
            void* r = sub_50B050();
            float f = dword_797E9C;
            sub_62E7A0(a3, a2, 0, 1.0f, f, r);
        }
    }
}
