// from server: 47% by atomic.potato
struct S_func_005d75b0 {
    void f(int a1, int a2, int a3, int a4);
};

void S_func_005d75b0::f(int a1, int a2, int a3, int a4)
{
    int buf[9];
    void *vtable = *(void **)this;
    int *(*fn)(void *, int *) = *(int *(**)(void *, int *))((char *)vtable + 0xc);
    int *ret = fn(this, buf);
    int *dst = (int *)a4;
    for (int i = 0; i < 9; ++i)
        dst[i] = ret[i];
    *(float *)((char *)dst + 0x24) = *(float *)((char *)ret + 0x24);
    *(float *)((char *)dst + 0x28) = *(float *)((char *)ret + 0x28);
    *(float *)((char *)dst + 0x2c) = *(float *)((char *)ret + 0x2c);
}
