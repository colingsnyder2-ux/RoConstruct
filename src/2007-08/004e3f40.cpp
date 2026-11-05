// from server: 20% by colin
// Reconstructed from the target machine code.
// 32-bit x86, MSVC 2005 (/O2 /GS /EHsc /MD).

extern "C" {
    __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
    __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
    __declspec(dllimport) double __cdecl ceil(double);
    double __cdecl fabs(double);
}

// Minimal declarations for the called helpers.
struct Vec3 {
    float x, y, z;
};

// Helper functions used by the target.
extern "C" void __cdecl sub_5B99B0(void*, void*);
extern "C" void __cdecl sub_50B010(void*, void*);
extern "C" float __cdecl sub_4DE980(int);
extern "C" void __cdecl sub_4E0180(void*, void*, void*, void*, void*);
extern "C" void __cdecl sub_4E3620(void*);
extern "C" void __cdecl sub_62FC62(void*);

// Globals referenced by the target.
extern float dword_787050;
extern float dword_797E9C;
extern double qword_795B48;
extern double qword_79F340;
extern double qword_79F348;

struct WedgeBuilder {
    // Offset 0x10 holds a packed value; bits 6..8 select a mode.
    unsigned int flags;
    int field_14;
    float field_18;
    float field_1C;

    void build(int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12);
};

void WedgeBuilder::build(int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12)
{
    int mode = (flags >> 6) & 7;

    float v44;
    float v48;
    float v4C;
    float v50;
    float v54;
    float v58;

    sub_5B99B0(&v44, &a2);

    float fabs_v54 = (float)fabs(v54);
    float fabs_v44 = (float)fabs(v44);
    float fabs_v48 = (float)fabs(v48);

    float v10 = fabs_v44;
    float v14 = fabs_v48;
    float v1C = fabs_v54;

    int edi;
    if (a12 == 0) {
        if (v14 == v1C) {
            edi = 1;
        } else {
            edi = 0;
        }
    } else {
        edi = 0;
    }

    int ebx;
    if (a12 == 0 && mode != 0) {
        float t = (&v10)[edi] * (float)qword_795B48;
        t = (float)ceil((double)t);
        ebx = (int)t;
    } else {
        ebx = 1;
    }

    unsigned short v10w = 0;
    unsigned short v12w = 0;

    short raw = *(short*)((char*)&a12 + 2 - edi * 2);
    int q = (int)raw / ebx;
    int one = 1;
    unsigned short qw = (unsigned short)q;
    unsigned int qv = (unsigned int)qw;
    if ((short)qw > 1) {
        // keep qv
    } else {
        qv = (unsigned int)one;
    }
    unsigned short chosen = (unsigned short)qv;

    float v58s = v58;
    *(unsigned short*)((char*)&v10w + edi * 2) = chosen;
    *(unsigned short*)((char*)&v12w - edi * 2) = (unsigned short)raw;

    float v28 = v58s;

    Vec3 tmp1;
    sub_50B010(&tmp1, &v44);
    float nx = -tmp1.x;
    float ny = -tmp1.y;
    float nz = -tmp1.z;

    Vec3 tmp2;
    sub_50B010(&tmp2, &v44);

    float f0 = 0.0f;
    float v2C = f0;
    float v30 = f0;
    float v1C2 = f0;
    float v20 = f0;

    int sel = (int)qv;
    if (sel == 0) {
        if (mode == 0) {
            v2C = dword_787050;
            v30 = dword_797E9C;
            v1C2 = (&v2C)[edi];
            v20 = 0.0f;
        } else {
            v2C = 0.0f;
            v30 = sub_4DE980(mode);
            v1C2 = v30 * 2.0f;
            v20 = dword_797E9C;
            if (edi == 1) {
                v1C2 = -v1C2;
            }
        }
    } else if (sel == 1) {
        v2C = 0.0f;
        v30 = field_1C;
        v1C2 = field_18;
        v20 = -field_1C;
    } else if (sel == 2) {
        v2C = 0.0f;
        v30 = 0.0f;
        v1C2 = 0.0f;
        v20 = 0.0f;
    }

    int i = 0;
    int count = ebx;
    if (count > 0) {
        do {
            if (i == count - 1) {
                float t = (&v10)[edi];
                float v34 = t;
                if (sel == 0 && v20 != 0.0f) {
                    v1C2 = (v1C2 - v20) * (float)qword_79F348 * (&v10)[edi];
                }
            } else {
                float v34 = (&v10)[edi] + (float)qword_79F340;
            }

            float args[4];
            args[0] = v1C2;
            args[1] = v30;
            args[2] = v2C;
            args[3] = v20;

            sub_4E0180(&args[0], &args[1], &args[2], &args[3], &a2);

            sub_4E3620(&a2);

            (&v10)[edi] = (&v10)[edi];
            i++;
        } while (i < count);
    }

    if (a2 != 0) {
        if (InterlockedDecrement((long*)(a2 + 4)) == 0) {
            void* p = *(void**)(a2 + 8);
            while (p != 0) {
                void* next = *(void**)((char*)p + 4);
                (*(void (__stdcall**)(void*))p)(p);
                sub_62FC62(p);
                p = next;
            }
            (*(void (__stdcall**)(void*, int))a2)((void*)a2, 1);
        }
    }
}
