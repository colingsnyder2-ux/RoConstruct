// from server: 32% by colin
struct S {
    void f();
};

extern "C" void __stdcall sub_418690();
extern "C" void __stdcall sub_570c00();
extern "C" void __stdcall sub_630d23();

void S::f()
{
    if (!(*(unsigned char*)0x8be388 & 1)) {
        *(unsigned int*)0x8be388 |= 1;
        sub_418690();
        sub_570c00();
        sub_630d23();
    }
}
