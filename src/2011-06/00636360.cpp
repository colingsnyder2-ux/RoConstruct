// from server: 29% by atomic.potato
struct S {
    int f0;
    int f4;
    char pad8[0x10];
    void* f18;
    void* f1c;
    void* ctor();
};

extern "C" void __stdcall sub_636230();
extern "C" void __stdcall sub_598250();
extern "C" void __stdcall sub_a404c4();
extern "C" void __stdcall sub_a404d0();

void* S::ctor()
{
    sub_636230();
    f0 = 0xa96e2c;
    f4 = 0xa96e24;
    f18 = (void*)0xa96e18;
    f1c = (void*)0xa96e0c;
    sub_a404c4();
    sub_598250();
    sub_a404d0();

    return this;
}
