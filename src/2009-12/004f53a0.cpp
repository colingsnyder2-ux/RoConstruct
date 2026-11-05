// from server: 78% by atomic.potato
struct S
{
    int a;
    int b;
    int c;
    int d;
    int f();
};

extern "C" void __cdecl Target();

int S::f()
{
    a = 0x9ba054;
    b = 0x9ba04c;
    c = 0x9ba040;
    d = 0x9ba038;
    Target();
    return 0;
}
