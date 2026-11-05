// from server: 18% by Intel
struct S_func_007bb710 {
    char pad[264];
    struct P_func_007bb710 { void g(); }* m_p;
    void f();
};

extern "C" float __stdcall fsqrt(float);
extern "C" float __stdcall fmul(float, float);
extern "C" float __stdcall fadd(float, float);

struct SpatialFilter {
    int __thiscall func();
};

int __thiscall SpatialFilter::func() {
    S_func_007bb710* this_ptr = (S_func_007bb710*)this;
    this_ptr->f();

    float xmm4 = *(float*)((char*)this + 0x34);
    float xmm3 = *(float*)((char*)this + 0x38);
    float xmm5 = *(float*)((char*)this + 0x30);

    float* eax_ptr = (float*)this_ptr->m_p;

    float xmm0 = eax_ptr[1];
    float xmm1 = eax_ptr[2];
    float xmm2 = eax_ptr[4];

    xmm1 = xmm1 * xmm3;
    xmm0 = xmm0 * xmm4;
    xmm0 = xmm0 + xmm1;

    xmm1 = eax_ptr[0];
    xmm1 = xmm1 * xmm5;
    xmm2 = xmm2 * xmm4;
    xmm0 = xmm0 + xmm1;

    xmm1 = eax_ptr[3];
    xmm0 = xmm0 + eax_ptr[9];
    xmm0 = xmm0 - *(float*)((char*)this + 0x6c);

    xmm1 = xmm1 * xmm5;
    xmm1 = xmm1 + xmm2;

    xmm2 = eax_ptr[5];
    xmm2 = xmm2 * xmm3;
    xmm1 = xmm1 + eax_ptr[10];
    xmm1 = xmm1 - *(float*)((char*)this + 0x70);

    xmm2 = xmm2 * xmm5;
    xmm5 = eax_ptr[7];
    xmm5 = xmm5 * xmm4;
    xmm4 = eax_ptr[8];
    xmm2 = xmm2 + xmm5;
    xmm4 = xmm4 * xmm3;
    xmm2 = xmm2 + xmm4;
    xmm2 = xmm2 + eax_ptr[11];
    xmm2 = xmm2 - *(float*)((char*)this + 0x74);

    float st0 = xmm2 * xmm2;
    float st1 = xmm1 * xmm1;
    float st2 = xmm0 * xmm0;

    float sum = st0 + st1 + st2;
    float result = fsqrt(sum);

    float threshold = *(float*)0xB82680;
    if (result <= threshold) {
        return 1;
    }
    return 0;
}
