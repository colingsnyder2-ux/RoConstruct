// from server: 42% by atomic.potato
extern "C" void __stdcall Call0060dc30(unsigned short, unsigned short, unsigned int);

void __stdcall Function0060fb10(unsigned short a, unsigned short b, unsigned int c, unsigned int d)
{
    Call0060dc30(a, b, d);
}
