// from server: 38% by atomic.potato
struct Args
{
    unsigned short a;
    unsigned short b;
    unsigned int c;
};

extern "C" void __stdcall Call(unsigned int, unsigned int, unsigned int);

void __stdcall Function(unsigned short a, unsigned short b, unsigned int c, unsigned int d)
{
    Args x;
    x.a = a;
    x.b = b;
    Call(d, x.a, x.b);
}
