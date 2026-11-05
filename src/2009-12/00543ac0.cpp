// from server: 33% by atomic.potato
extern "C" {
    void __stdcall sub_98B6F0(void*, void*);
    void __stdcall sub_98B6E4(void*);
}

struct S {
    void f(int, int, int, int, int, int, int, int, int);
};

void S::f(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9)
{
    char buf[0x1c];
    int local = 0;
    sub_98B6F0(buf, &a1);
    int v = *(int*)&a1;
    int (*fn)(int) = *(int (**)(int))this;
    int off = *(int*)((char*)this + 4);
    fn(off + v);
    sub_98B6E4(buf);
}
