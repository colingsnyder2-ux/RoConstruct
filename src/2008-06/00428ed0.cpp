// from server: 100% by king_originala
extern char* __cdecl allocate(unsigned int);

struct Block
{
    unsigned int data[80];
};

char* __stdcall func_00428ed0(unsigned int a, unsigned int b, const Block* source)
{
    char* p = allocate(0x148);
    if (p)
        *reinterpret_cast<unsigned int*>(p) = a;

    unsigned int* q = reinterpret_cast<unsigned int*>(p + 4);
    if (q)
        *q = b;

    Block* r = reinterpret_cast<Block*>(p + 8);
    if (r)
        *r = *source;

    return p;
}
