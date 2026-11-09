// from server: 37% by atomic.potato
struct S {
    void f(int, int, int);
};

extern "C" void __stdcall sub_61C800(void*, void*);
extern "C" void __stdcall sub_6288F0(void*, void*, void*, void*, void*, void*);

void S::f(int a, int b, int c)
{
    char buf1[8];
    char buf2[8];
    char buf3[32];
    char buf4[32];
    *(int*)buf1 = 0;
    *(int*)(buf1 + 4) = 0;
    *(int*)buf2 = 0;
    *(int*)(buf2 + 4) = 0;
    *(int*)buf3 = 0;
    *(int*)buf4 = 0;
    sub_61C800((void*)0x91d210, (void*)c);
    sub_6288F0(buf1, buf2, buf3, buf4, (void*)0, (void*)0);
}
