// from server: 100% by atomic.potato
extern "C" void __cdecl sub_637B00();

struct S
{
    int a;
    int b;
    int pad[4];
    int c;
    int d;

    void f();
};

void S::f()
{
    a = 0x9cdba4;
    b = 0x9cdb9c;
    c = 0x9cdb90;
    d = 0x9cdb88;
    sub_637B00();
}
