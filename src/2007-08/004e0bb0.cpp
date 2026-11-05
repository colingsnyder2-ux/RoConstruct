// from server: 26% by colin
// roc 2007-08 004e0bb0  unit: RBX::Render::Mesh::Level  size: 813 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004e0bb0

extern "C" double __stdcall ceil(double);

struct Vec3 { float x, y, z; };

struct MeshLevel {
    char pad0[4];
    Vec3 field4;
    char pad10[0x10];
    int field20;
    void method(float, float, float, float, int, int);
};

extern "C" void __stdcall sub_5b9970(void*, void*);
extern "C" void __stdcall sub_50b010(void*, void*);
extern "C" void __stdcall sub_4de980(float, int);
extern "C" void __stdcall sub_4df640(void*, void*, int, float, float, short);
extern "C" void __stdcall sub_4e0180(void*, void*, void*, void*, int, int, float, float, float, float);

extern float g_787050;
extern float g_797e9c;
extern double g_795b48;
extern double g_79f340;
extern double g_79f348;

void MeshLevel::method(float a, float b, float c, float d, int e, int f)
{
    float v40[4];
    float v44[4];
    float v30[4];
    float v1c[4];
    float v20[4];
    float v28[4];
    float v2c[4];
    short v10[4];
    int v60;
    int v64;
    int v1c_i;
    float fv18, fv1c, fv10, fv44, fv48, fv4c;
    int ebx, ebp, esi, edi;
    float ftmp;
    int i;

    ebx = this->field20 & 7;

    sub_5b9970(&this->field4, v40);

    fv48 = (float)ceil((double)(a < 0 ? -a : a));
    fv4c = (float)ceil((double)(b < 0 ? -b : b));
    fv10 = (float)ceil((double)(c < 0 ? -c : c));
    fv18 = fv10;
    fv44 = (float)ceil((double)(d < 0 ? -d : d));

    if (f == 0) {
        if (fv44 == fv18) {
            esi = 0;
        } else {
            esi = 1;
        }
    } else {
        esi = 0;
    }

    if (f == 0 && ebx != 0) {
        ftmp = v44[esi] * (float)g_795b48;
        ftmp = (float)ceil((double)ftmp);
        ebp = (int)ftmp;
    } else {
        ebp = 1;
    }

    v10[0] = 0;
    v10[1] = 0;
    {
        short s = *(short*)((char*)v10 + 0x52 - esi * 2);
        int val = (int)s / ebp;
        v60 = (unsigned short)val;
        if ((short)val > 1) {
            v1c_i = v60;
        } else {
            v1c_i = 1;
        }
        v10[esi] = (short)v1c_i;
    }

    fv18 = fv4c;
    sub_50b010(v40, v44);
    v60 = (int)(-v44[0]);
    v20[0] = -v44[1];
    v2c[0] = (float)v60;
    v28[0] = v20[0];

    v64 = (int)v44[2];
    v28[0] = 0.0f;
    v2c[0] = 0.0f;
    v1c[0] = 0.0f;
    v20[0] = 0.0f;

    if (v64 == 0) {
        if (ebx == 0) {
            v28[0] = g_787050;
            v2c[0] = g_797e9c;
            v20[0] = v28[0];
            v1c[0] = v2c[0];
        } else {
            v2c[0] = 0.0f;
            sub_4de980(v2c[0], ebx);
            v2c[0] = v2c[0] * 2.0f;
            v20[0] = v2c[0];
            v1c[0] = g_797e9c;
            if (esi == 1) {
                v1c[0] = -v1c[0];
            }
        }
    } else if (v64 == 1) {
        v28[0] = 0.0f;
        v2c[0] = this->field4.y;
        v1c[0] = this->field4.x;
        v20[0] = -this->field4.y;
    } else if (v64 == 2) {
        v28[0] = 0.0f;
        v2c[0] = 0.0f;
        v1c[0] = 0.0f;
        v20[0] = 0.0f;
    }

    for (i = 0; i < ebp; i++) {
        if (i == ebp - 1) {
            v60 = (int)v44[esi];
            v30[esi] = (float)v60;
            if (v64 == 0 && v20[0] != 0.0f) {
                v1c[esi] = (v30[esi] - v1c[esi]) * (float)g_79f348 * v1c[esi];
            }
        } else {
            v30[esi] = v1c[esi] + (float)g_79f340;
        }

        sub_4e0180(&v40, &v44, &v30, &v1c, e, esi, v1c[0], v20[0], v28[0], v2c[0]);
        sub_4df640(&v40, &v44, v64, v1c[0], v20[0], v10[0]);
        v1c[esi] = v30[esi];
    }
}
