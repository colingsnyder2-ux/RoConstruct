// from server: 40% by atomic.potato
extern "C" void __cdecl sub_00983270(void *, unsigned int, unsigned int, unsigned int);

struct S
{
    void f();
};

void S::f()
{
    unsigned char local[268];
    sub_00983270(local, 0x20, 6, 0x7dd040);
}
