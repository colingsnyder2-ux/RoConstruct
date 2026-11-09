// from server: 34% by atomic.potato
extern "C" void* __cdecl sub_7f3860(unsigned int);
extern "C" void __stdcall sub_98b6f0();
extern "C" void __stdcall sub_98b6e4();

struct S {
    void f();
};

void S::f()
{
    void* p = sub_7f3860(0x24);
    if (p) {
        *(unsigned int*)p = *(unsigned int*)((char*)&p + 0x18);
        sub_98b6f0();
        *(unsigned int*)((char*)p + 0x20) = *(unsigned int*)((char*)&p + 0x3c);
    }
    else {
        p = 0;
    }
    *(void**)((char*)&p + 0x3c) = p;
    sub_98b6e4();
}
