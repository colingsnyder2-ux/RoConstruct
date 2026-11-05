// from server: 50% by atomic.potato
extern "C" void __cdecl Function621430(unsigned short, unsigned short, unsigned short, unsigned short, unsigned long);

struct TorsoBuilder
{
    void __stdcall Function(unsigned short, unsigned short, unsigned short, unsigned long);
};

void __stdcall TorsoBuilder::Function(unsigned short a, unsigned short b, unsigned short c, unsigned long d)
{
    Function621430(a, b, c, c, d);
}
