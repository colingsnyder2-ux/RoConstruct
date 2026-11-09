// from server: 34% by atomic.potato
extern "C" void __stdcall helper_004b7580(void*, void*);
extern "C" void __stdcall helper_004bd040(void*);
extern "C" void __stdcall helper_004b4fc0(void*);

struct S {
    void f(int, int, int, int, int, int, int, int, int, int, int, int, int);
};

void S::f(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13)
{
    char buf[0x30];
    void* p = buf;
    helper_004b7580(&p, &a1);
    helper_004bd040(this);
    helper_004b4fc0(buf);
}
