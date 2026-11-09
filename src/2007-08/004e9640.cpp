// from server: 29% by colin
// roc 2007-08 004e9640  unit: TorsoMesh.cpp  size: 794 bytes
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD

extern "C" double __cdecl ceil(double);

struct TorsoBuilder {
    char pad0[0x10];
    unsigned int flags;
    void build(int a, int b, int c);
};

extern "C" void __cdecl sub_5b9990(void*, void*);
extern "C" void* __cdecl sub_50b010(void*, void*);
extern "C" float __cdecl sub_4de980(int);
extern "C" void __cdecl sub_4e0180(void*, void*, void*, void*, void*, void*);
extern "C" void __cdecl sub_4e8240(void*, int);

void TorsoBuilder::build(int a, int b, int c)
{
    float v44, v48, v4c;
    float v18, v1c;
    float v28, v2c, v20;
    float v30[2];
    float v38[2];
    float v1c_arr[2];
    unsigned short v10[2];
    unsigned short v58;
    int v1c_int;
    int ebp;
    int esi;
    int ebx;
    int edi;
    float f;
    float tmp[3];
    float tmp2[3];

    ebx = (this->flags >> 3) & 7;

    sub_5b9990(tmp, &this->pad0[0]);

    f = *(float*)((char*)&a + 0);
    if (f < 0) f = -f;
    v18 = f;
    v1c = f;

    ebp = c;
    edi = 0;

    f = tmp[0];
    if (f < 0) f = -f;
    v44 = f;
    f = tmp[1];
    if (f < 0) f = -f;
    v48 = f;
    f = tmp[2];
    if (f < 0) f = -f;
    v4c = f;

    if (ebp == 0) {
        if (v44 == v48) {
            esi = 1;
        } else {
            esi = 0;
        }
    } else {
        esi = 0;
    }

    if (ebp == 0 && ebx != 0) {
        f = v44 * 0.5f;
        f = (float)ceil((double)f);
        ebp = (int)f;
    } else {
        ebp = 1;
    }

    v10[0] = 0;
    v10[1] = 0;

    {
        short s = *(short*)((char*)v10 + (esi * 2));
        int q = s / ebp;
        unsigned short uq = (unsigned short)q;
        v58 = uq;
        if ((short)uq > 1) {
            v1c_int = v58;
        } else {
            v1c_int = 1;
        }
        v10[esi] = (unsigned short)v1c_int;
    }

    v18 = v4c;

    sub_50b010(tmp2, &v48);
    v58 = (unsigned short)(-tmp2[0]);
    v20 = -tmp2[1];
    v28 = v58;
    v2c = v20;

    sub_50b010(tmp2, &v48);

    v28 = 0.0f;
    v2c = 0.0f;
    v1c_arr[0] = 0.0f;
    v1c_arr[1] = 0.0f;

    switch (c) {
    case 0:
        if (ebx == 0) {
            v28 = *(float*)0x787050;
            v2c = *(float*)0x797e9c;
            v1c_arr[esi] = v28;
        } else {
            v2c = sub_4de980(ebx);
            v1c_arr[esi] = v2c * 2.0f;
            v1c_arr[0] = *(float*)0x797e9c;
            if (esi == 1) {
                v1c_arr[0] = -v1c_arr[0];
            }
        }
        break;
    case 1:
        v28 = 0.0f;
        v2c = *(float*)((char*)this + 0x1c);
        v1c_arr[0] = *(float*)((char*)this + 0x18);
        v1c_arr[1] = -*(float*)((char*)this + 0x1c);
        break;
    case 2:
        break;
    default:
        break;
    }

    edi = 0;
    if (ebp > 0) {
        do {
            if (edi == ebp - 1) {
                v58 = v44;
                v30[esi] = v58;
                if (c != 0 || v1c_arr[0] == 0.0f) {
                    v30[esi] = v38[esi] + 1.0f;
                } else {
                    v1c_arr[esi] = (v58 - v38[esi]) * 0.5f * v1c_arr[esi];
                }
            } else {
                v30[esi] = v38[esi] + 1.0f;
            }

            sub_4e0180(tmp, &v1c_arr[0], &v30[0], &v38[0], &v10[0], &v1c_int);
            sub_4e8240(tmp, a);
            v38[esi] = v30[esi];
            edi++;
        } while (edi < ebp);
    }
}
