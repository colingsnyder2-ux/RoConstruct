// from server: 100% by colin
#include <intrin.h>
struct S_func_00609a30 {
    char pad0[320];
    int m_x;
    int f();
};

extern char table_823474[];
extern char table_823464[];
extern char table_82345c[];
extern char table_823454[];
extern char table_823444[];
extern char table_823434[];
extern char table_823424[];
extern char table_823414[];
extern char table_823404[];
extern char table_8233f4[];
extern char table_8233c4[];

struct S {
    unsigned int data[0x2d74 / 4];
    void initialize(int a, int b, int c);
    S* construct(int a, int b, S_func_00609a30* p);
};

S* S::construct(int a, int b, S_func_00609a30* p)
{
    int v = p->f();
    initialize(a, b, v);

    data[0x00 / 4] = reinterpret_cast<unsigned int>(table_823474);
    data[0x10 / 4] = reinterpret_cast<unsigned int>(table_823464);
    data[0x14 / 4] = reinterpret_cast<unsigned int>(table_82345c);
    data[0x20 / 4] = reinterpret_cast<unsigned int>(table_823454);
    data[0x24 / 4] = reinterpret_cast<unsigned int>(table_823444);
    data[0x44 / 4] = reinterpret_cast<unsigned int>(table_823434);
    data[0x64 / 4] = reinterpret_cast<unsigned int>(table_823424);
    data[0x84 / 4] = reinterpret_cast<unsigned int>(table_823414);
    data[0xa4 / 4] = reinterpret_cast<unsigned int>(table_823404);
    data[0xc4 / 4] = reinterpret_cast<unsigned int>(table_8233f4);
    data[0x2b74 / 4] = reinterpret_cast<unsigned int>(table_8233c4);
    *reinterpret_cast<volatile unsigned int*>(&data[0x2d68 / 4]) = 0;
    *reinterpret_cast<volatile unsigned int*>(&data[0x2d6c / 4]) = 0;
    _ReadWriteBarrier();
    data[0x2d70 / 4] = reinterpret_cast<unsigned int>(p);
    return this;
}
