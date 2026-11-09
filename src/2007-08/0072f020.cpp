// from server: 40% by tester
extern "C" float __cdecl func_00630e0c(float);

struct S {
    void __cdecl f(float a, float b, float c, float d, float e, float f2, float g);
};

void S::f(float a, float b, float c, float d, float e, float f2, float g)
{
    float v24 = e * b - a * f2;
    float v28 = a * g - d * b;
    float v08 = c * v28 - d * v24;
    float v0c = e * v24 - c * v28;
    float v10 = d * d - e * e;

    float len = v0c * v0c + v08 * v08 + v10 * v10;
    len = func_00630e0c(len);
    float inv = 1.0f / len;

    float out0 = v08 * inv;
    float out1 = v10 * inv;
    float out2 = v0c * inv;

    ((void (__thiscall*)(void*, int))0x4739d0)(this, 3);
    ((void (__thiscall*)(void*, int, int, int))0x474170)(this, 0, 2, 0);
    ((void (__thiscall*)(void*, int))0x477e40)(this, 0);
    ((void (__thiscall*)(void*, float*))0x474ae0)(this, &out0);
    ((void (__thiscall*)(void*, float*))0x474bf0)(this, &v24);
    ((void (__thiscall*)(void*, float*))0x474bf0)(this, &v28);
    ((void (__thiscall*)(void*))0x4757f0)(this);
    ((void (__thiscall*)(void*))0x4796d0)(this);
}
