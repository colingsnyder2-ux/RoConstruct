// from server: 77% by atomic.potato
struct S
{
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
    int g;
    void init();
};

extern "C" void __cdecl finish(S *);

void S::init()
{
    a = 0x00bb0964;
    b = 0x00bb0958;
    e = 0x00bb094c;
    f = 0x00bb0940;
    finish(this);
}
