// from server: 100% by atomic.potato
struct StandardOut
{
    void f();
};

void StandardOut::f()
{
    *(unsigned char *)((char *)this + 0x24) = 1;
    extern void __declspec(nothrow) __fastcall f(void *);
    f((char *)this + 0x20);
}
