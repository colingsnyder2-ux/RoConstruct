// from server: 31% by atomic.potato
struct S {
    void f(int, int, int);
};

extern "C" void __stdcall sub_610BE0(void*, int);
extern "C" void __stdcall sub_610B80(void*, int);
extern "C" void __stdcall sub_617990(void*, int, int, int);

void S::f(int a, int b, int c)
{
    char buf1[32];
    *(int*)buf1 = 0;
    sub_610BE0(buf1, 0x4545b0);
    char buf2[32];
    *(int*)buf2 = 0;
    sub_610B80(buf2, 0x428830);
    sub_617990(this, a, b, c);
}
