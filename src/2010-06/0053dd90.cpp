// from server: 100% by atomic.potato
extern "C" void __stdcall sub_7A8ADE(void *, unsigned int, unsigned int, void *);

struct S {
    void f();
};

void S::f()
{
    sub_7A8ADE((char *)this + 0x18, 4, 0x10, (void *)0x52CAF0);
}
