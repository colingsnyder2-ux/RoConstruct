// from server: 48% by atomic.potato
struct S
{
    void f(int, int, int, int);
};

void S::f(int a, int b, int c, int d)
{
    char buf[0x30];
    void* (*fn)(void*, void*);
    void* src;
    void* dst;

    fn = *(void*(**)(void*, void*))((char*)*(void**)this + 8);
    src = fn(this, buf);
    dst = (void*)d;
    for (int i = 0; i < 9; i++)
    {
        ((int*)dst)[i] = ((int*)src)[i];
    }
    *(float*)((char*)dst + 0x24) = *(float*)((char*)src + 0x24);
    *(float*)((char*)dst + 0x28) = *(float*)((char*)src + 0x28);
    *(float*)((char*)dst + 0x2c) = *(float*)((char*)src + 0x2c);
}
