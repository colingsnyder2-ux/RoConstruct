// from server: 48% by atomic.potato
extern "C" void __cdecl Function_00933840(unsigned short, unsigned short,
                                           unsigned long, unsigned long);

struct S {
    void f(unsigned long, unsigned long, unsigned short, unsigned short,
           unsigned long);
};

void S::f(unsigned long a, unsigned long b, unsigned short c,
          unsigned short d, unsigned long e)
{
    Function_00933840(c, d, a, b);
}
