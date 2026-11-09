// from server: 100% by atomic.potato
struct S
{
    int a;
    int b;
    int padding[4];
    int c;
    int d;
    int e;
    void init();
};

extern "C" void __cdecl f();

void S::init()
{
    a = 0x9cddc4;
    b = 0x9cddbc;
    c = 0x9cddb0;
    d = 0x9cdda8;
    f();
}
