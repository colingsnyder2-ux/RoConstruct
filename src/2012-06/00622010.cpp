// from server: 42% by atomic.potato
extern "C" void __stdcall sub_620ba0(unsigned short, unsigned short,
                                      unsigned int);

void __stdcall sub_622010(unsigned short a, unsigned short b,
                           unsigned short d, unsigned int e)
{
    sub_620ba0(a, b, e);
}
