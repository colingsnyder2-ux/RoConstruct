// from server: 37% by atomic.potato
struct Sub1 { char pad[0x14]; float f14; };
struct Sub2 { char pad[0x98]; float f98; };
struct Sub3 { char pad[0x30]; void* p30; };
struct Sub4 { char pad[0x34]; void* p34; };
struct Sub5 { char pad[0x38]; void* p38; };
struct Sub6 { char pad[0x108]; Sub3* p108; };

extern "C" int __cdecl f_8df0c0();
extern "C" int __cdecl f_6813e0(int);
extern "C" int __cdecl f_79bd90();
extern "C" void __cdecl f_7b8e60();
extern "C" int __cdecl f_7eb4d0(void*, void*);
extern "C" void __cdecl f_65e690(void*, void*);

extern float g_a75b68;
extern float g_abc460;
extern float g_cd5674;
extern float g_cd5678;
extern float g_cd567c;
extern int g_cd5680;

struct S {
    char pad[0x38];
    int f38;
    void func(int);
};

void S::func(int)
{
    int v = f_8df0c0();
    int esi = f_6813e0(v);
    if (esi == 0)
        return;
    int ebx = f_79bd90();
    if (ebx == 0)
        return;
    Sub4* edi = (Sub4*)((Sub4*)esi)->p34;
    float xmm0;
    if (edi != 0) {
        f_7b8e60();
        xmm0 = ((Sub1*)edi)->f14;
    } else {
        xmm0 = ((Sub2*)esi)->f98;
    }
    Sub6* eax6 = ((Sub6*)ebx);
    Sub4* esi2 = (Sub4*)eax6->p108->p30;
    float s10 = xmm0;
    if (esi2 != 0) {
        f_7b8e60();
        xmm0 = ((Sub1*)esi2)->f14;
    } else {
        xmm0 = ((Sub2*)eax6->p108)->f98;
    }
    float s0c;
    if (s0c > xmm0) {
        s10 = xmm0;
    } else {
        s10 = s0c;
    }
    float xmm0b = s10;
    float zero = 0.0f;
    if ((g_cd5680 & 1) == 0) {
        float xmm1 = g_abc460;
        g_cd5680 |= 1;
        g_cd5674 = zero;
        g_cd5678 = xmm1;
        g_cd567c = zero;
    }
    float tmp;
    f_7eb4d0(&tmp, &g_cd5674);
    Sub3* ecx3 = ((Sub6*)ebx)->p108;
    float xmm0c = ((float*)&tmp)[1];
    xmm0c *= s10;
    xmm0c *= ((float*)&tmp)[2];
    xmm0c *= g_a75b68;
    void* ecx4 = ((Sub5*)ecx3)->p38;
    float s18 = xmm0c;
    float s1c = 0.0f;
    if (ecx4 != 0) {
        f_65e690(&s18, &this->f38);
    }
}
