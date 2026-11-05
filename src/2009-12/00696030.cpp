// from server: 62% by atomic.potato
struct S
{
    void f(void *);
};

void S::f(void *p)
{
    *(unsigned char *)((char *)this + 0x208) = 0;
    void **q = *(void ***)p;
    *(void **)((char *)p + 4) = 0;
    ((void (__thiscall *)(void *))q[2])(p);
}
