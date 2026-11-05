// from server: 25% by atomic.potato
struct S {
    void f(int, int, int, int, int);
};

extern "C" void __stdcall sub_9ea40c(void*, const void*);

void S::f(int a1, int a2, int a3, int a4, int a5)
{
    char buf1[0x1c];
    char buf2[0x1c];
    sub_9ea40c(buf1, &a1);
    sub_9ea40c(buf2, &a2);
    int v = *(int*)buf2;
    int w = *(int*)buf1;
    int x = *(int*)((char*)this + 4);
    void (__stdcall *fn)(int) = *(void (__stdcall**)(int))this;
    fn(x + v);
}
