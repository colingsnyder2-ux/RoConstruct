// from server: 70% by colin
struct S {
    void f();
};

extern "C" void* __cdecl __iob_func();
extern "C" int __cdecl fprintf(void*, const char*, ...);
extern "C" void __cdecl __security_check_cookie(unsigned int);

void S::f()
{
    __security_check_cookie(0);
    fprintf((void*)((char*)__iob_func() + 0x40), "libpng warning: %s", "t$Wh");
    __security_check_cookie(0);
}
