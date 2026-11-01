// from server: 100% by king_originala
unsigned __cdecl descriptor();

struct Base {
    unsigned data[118];
    Base(int);
    ~Base();
};

struct S : Base {
    static __forceinline int prepare(S*, int);
    S(int complete);
};

__forceinline int S::prepare(S* p, int complete)
{
    volatile int constructionFlags = 0;
    if (complete) {
        p->data[0x150 / 4] = 0x834eb4;
        p->data[0x1d4 / 4] = 0x846144;
    }
    return 0;
}

S::S(int complete) : Base(prepare(this, complete))
{
    data[0x1c / 4] = descriptor();

    int* table = reinterpret_cast<int*>(data[0x150 / 4]);
    data[0x00 / 4] = 0x834f8c;
    data[0x10 / 4] = 0x834f7c;
    data[0x14 / 4] = 0x834f74;
    data[0x20 / 4] = 0x834f6c;
    data[0x24 / 4] = 0x834f5c;
    data[0x44 / 4] = 0x834f4c;
    data[0x64 / 4] = 0x834f3c;
    data[0x84 / 4] = 0x834f2c;
    data[0xa4 / 4] = 0x834f1c;
    data[0xc4 / 4] = 0x834f0c;
    data[0x130 / 4] = 0x834f04;
    data[0x140 / 4] = 0x834eec;

    *reinterpret_cast<unsigned*>(
        reinterpret_cast<char*>(this) + 0x150 + table[1]) = 0x834ee4;

    table = reinterpret_cast<int*>(data[0x150 / 4]);
    *reinterpret_cast<unsigned*>(
        reinterpret_cast<char*>(this) + 0x150 + table[2]) = 0x834ec8;

    table = reinterpret_cast<int*>(data[0x150 / 4]);
    int offset = table[1];
    *reinterpret_cast<int*>(
        reinterpret_cast<char*>(this) + 0x14c + offset) = offset - 0x78;

    table = reinterpret_cast<int*>(data[0x150 / 4]);
    offset = table[2];
    *reinterpret_cast<int*>(
        reinterpret_cast<char*>(this) + 0x14c + offset) = offset - 0x80;
}
