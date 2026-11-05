// from server: 64% by atomic.potato
extern "C" void __cdecl sub_007f49a4(void *, int, int, void *);

struct S
{
    void f();
};

void S::f()
{
    void *p = *(void **)0x0098bd10;
    char buffer[0x10];
    sub_007f49a4(buffer, 0x10, 6, p);
}
