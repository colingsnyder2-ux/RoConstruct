// from server: 45% by atomic.potato
struct S {
    char pad[8];
    int (__stdcall *fn)(int);
    int (__stdcall *fn2)(int);
    void method(int a, int b);
};

void S::method(int a, int b)
{
    if (a != 0) {
        int v = *(int*)b;
        int c = *(int*)((char*)this + 0xc);
        int (__stdcall *f)(int) = *(int (__stdcall **)(int))((char*)this + 8);
        c += a - 0x1c;
        f(v);
    } else {
        int v = *(int*)b;
        int c = *(int*)((char*)this + 0xc);
        int (__stdcall *f)(int) = *(int (__stdcall **)(int))((char*)this + 8);
        c += 0;
        f(v);
    }
}
