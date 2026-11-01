// from server: 100% by colin
struct Inner {
    void method1(int);
    void method2(void*);
};

struct S {
    char pad[0xc];
    Inner* inner;
    void func(void* arg);
};

void S::func(void* arg)
{
    int v = *(int*)((char*)arg + 0x264);
    inner->method1(v);
    ((Inner*)this)->method2(arg);
}
