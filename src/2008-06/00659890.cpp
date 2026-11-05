// from server: 100% by king_originala
extern "C" void (__stdcall *_invalid_parameter_noinfo)();

struct BallBallContact {
    int find(int a, int b);
};

int BallBallContact::find(int a, int b)
{
    int* key = (int*)b;
    unsigned int h = (unsigned int)key[2] * 0x4f9ffb7u;
    h ^= (unsigned int)key[1] * 0x127409fu;
    h ^= (unsigned int)key[0] * 0x466f45du;

    int shift = *(unsigned short*)(*(int*)(a + 0x64) + 0x20);
    unsigned int mask = (unsigned int)(0xffff >> shift);
    h &= mask;

    int* table = (int*)((char*)this + shift * 24 + 0xc);
    int count = (table[4] - table[3]) >> 3;
    if (h >= (unsigned int)count)
        _invalid_parameter_noinfo();

    int* node = (int*)(table[3] + h * 8);
    int* entry = (int*)*node;
    for (;;)
    {
        if (entry[0] == a && entry[5] == key[0] && entry[6] == key[1] && entry[7] == key[2])
            break;
        entry = (int*)entry[1];
        if (!entry)
            break;
    }
    return (int)entry;
}
