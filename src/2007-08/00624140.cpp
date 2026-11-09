// from server: 50% by colin
struct S {
    void f();
};

extern "C" void* __stdcall sub_408740(void*, void*);
extern "C" void __stdcall sub_5491a0(void*);

extern "C" void* __stdcall sub_77e698(void*, const char*);
extern "C" void __stdcall sub_77e6ac(void*);

void S::f()
{
    char buf[8];
    char buf2[24];
    void* p;

    sub_77e698(buf, "Fonts\\safechat.xml");
    p = sub_408740(buf2, *(void**)((char*)this + 0x34));
    sub_5491a0(p);
    sub_77e6ac(buf);
}
