// from server: 50% by atomic.potato
struct S
{
    int vtable;
    int pad1;
    int pad2;
    int pad3;
    void *p;
    void f();
};

extern "C" void destroy_exception(void *);

void S::f()
{
    vtable = 0x00b7e5b0;
    *((int *)((char *)this + 0x0c)) = 0x00b7e5a8;
    *((int *)((char *)this + 0x0c)) = 0x00b43e60;
    if (p != 0)
        destroy_exception(p);
    vtable = 0x00b42e94;
}
