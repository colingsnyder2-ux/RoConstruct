// from server: 65% by atomic.potato
extern "C" void __cdecl sub_719B76(void*, int, int, const char*);

struct S
{
    char pad[0x1B8];
    void f();
};

void S::f()
{
    sub_719B76(pad + 0x1B8, 12, 2, "QSUVW");
}
