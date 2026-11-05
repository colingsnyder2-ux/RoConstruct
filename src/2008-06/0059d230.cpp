// from server: 100% by king_originala
unsigned __cdecl getDescriptor();

struct Base
{
    unsigned words[77];
    int* vbtable;

    Base(void* argument, int mode);
    ~Base();
};

struct S : Base
{
    S(void* argument, int initializeVirtualBases);
};

S::S(void* argument, int initializeVirtualBases)
    : Base(initializeVirtualBases
               ? (vbtable = reinterpret_cast<int*>(0x830fac), argument)
               : argument,
           0)
{
    words[7] = getDescriptor();

    int* table = vbtable;
    words[0] = 0x83305c;
    words[4] = 0x833050;
    words[5] = 0x833048;
    words[8] = 0x833040;
    words[9] = 0x833030;
    words[17] = 0x833020;
    words[25] = 0x833010;
    words[33] = 0x833000;
    words[41] = 0x832ff0;
    words[49] = 0x832fe0;
    words[76] = 0x832fd4;

    *reinterpret_cast<unsigned*>(
        reinterpret_cast<char*>(this) + 0x134 + table[1]) = 0x832fc8;
    *reinterpret_cast<unsigned*>(
        reinterpret_cast<char*>(this) + 0x134 + vbtable[2]) = 0x832fc0;
}
