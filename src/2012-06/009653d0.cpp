// from server: 34% by tester
struct Sub {
    float f0;
    float f4;
    float f8;
    float fC;
    float f10;
    float f14;
};

struct PolyContact {
    char pad0[0xC];
    Sub* m_p0C;
    Sub* m_p10;
    char pad14[0xCC - 0x14];
    unsigned int m_cc;
    bool f(float arg);
};

extern "C" Sub* __stdcall sub_7bb0f0(Sub* s);
extern "C" void __stdcall sub_9652f0(PolyContact* self);
extern "C" float __stdcall sub_964e20(PolyContact* self);

bool PolyContact::f(float arg)
{
    Sub* a = sub_7bb0f0(m_p10);
    Sub* b = sub_7bb0f0(m_p0C);

    if (b->f0 > a->fC) return false;
    if (b->f4 > a->f10) return false;
    if (b->f8 > a->f14) return false;
    if (a->f4 > b->f10) return false;
    if (a->f0 > b->fC) return false;
    if (a->f8 > b->f14) return false;

    sub_9652f0(this);
    if (m_cc == 0) return false;
    float r = sub_964e20(this);
    return r > arg;
}
