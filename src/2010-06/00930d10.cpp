// from server: 39% by atomic.potato
struct Seg930000
{
    void f(unsigned short a, unsigned short b, unsigned short c, unsigned int d);
};

extern "C" void __cdecl sub_92f880(unsigned int, unsigned int, unsigned int, unsigned int);

void Seg930000::f(unsigned short a, unsigned short b, unsigned short c, unsigned int d)
{
    sub_92f880(a, b, c, d);
}
