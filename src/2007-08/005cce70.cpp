// from server: 59% by tester
struct S_func_005cce70 {
    char pad0[0x64];
    void* m_ptr64;
    char pad1[0x40];
    float m_fa8;
    float m_fac;
    float m_fb0;
    void __cdecl f(S_func_005cce70* other);
};

extern "C" void __stdcall sub_00530100(void* p);
extern "C" void* __stdcall sub_005b4c90(void* p);
extern "C" int __stdcall sub_005bc7b0(void* p, void* q);

void S_func_005cce70::f(S_func_005cce70* other)
{
    void* a = m_ptr64;
    sub_00530100(a);
    void* b = other->m_ptr64;
    sub_00530100(b);

    float dx = ((S_func_005cce70*)b)->m_fa8 - ((S_func_005cce70*)a)->m_fa8;
    float dy = ((S_func_005cce70*)b)->m_fac - ((S_func_005cce70*)a)->m_fac;
    float dz = ((S_func_005cce70*)b)->m_fb0 - ((S_func_005cce70*)a)->m_fb0;

    void** vtbl_other = *(void***)other;
    float w1 = ((float (__stdcall*)(void*))vtbl_other[3])(other);
    void** vtbl_this = *(void***)this;
    float w2 = ((float (__stdcall*)(void*))vtbl_this[3])(this);

    float ax = dz < 0.0f ? -dz : dz;
    float ay = dy < 0.0f ? -dy : dy;
    float az = dx < 0.0f ? -dx : dx;

    float* p;
    if (ax < ay) {
        p = &ay;
    } else {
        p = &ax;
    }
    if (*p < az) {
        p = &az;
    }
    if (w1 + w2 < *p) {
        return;
    }

    void* r1 = sub_005b4c90(this);
    void* r2 = sub_005b4c90(other);
    sub_005bc7b0(r2, r1);
}
