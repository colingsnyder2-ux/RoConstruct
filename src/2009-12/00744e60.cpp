// from server: 100% by atomic.potato
struct Flag
{
    int a;
    int b;
    int c;
    int d;
    int e;
    int f_value;
    int g;
    int h;

    void f();
};

extern "C" void __cdecl Flag_tail();

void Flag::f()
{
    a = 0x9e357c;
    b = 0x9e3574;
    g = 0x9e3568;
    h = 0x9e3560;
    Flag_tail();
}
