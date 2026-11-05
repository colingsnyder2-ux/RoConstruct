// from server: 20% by atomic.potato
struct S_func_005c98c0 {
    char pad0[12];
    float m_c;
    void f();
};

extern "C" void __stdcall sub_0098b6e4();
extern "C" void __stdcall sub_00432090();
extern "C" void* __stdcall sub_006b1390();
extern "C" void __stdcall sub_004c2140();

void S_func_005c98c0::f()
{
    float v0 = *(float*)0x009aea18;
    void* p;
    char buf[0x60];
    void* q;

    p = *(void**)0x009c0fac;
    if (p) {
        sub_00432090();
        q = *(void**)((char*)p + 0x170);
        sub_006b1390();
        sub_0098b6e4();
    }

    p = *(void**)0x009c0f80;
    if (p) {
        sub_00432090();
        q = *(void**)((char*)p + 0x170);
        sub_006b1390();
        sub_0098b6e4();
    }

    p = *(void**)0x009c0f54;
    if (p) {
        sub_00432090();
        sub_0098b6e4();
    }

    p = *(void**)0x009c0f28;
    if (p) {
        sub_00432090();
        sub_0098b6e4();
    }

    p = *(void**)0x009c0f00;
    if (p) {
        sub_00432090();
        sub_0098b6e4();
    }

    sub_004c2140();
}
