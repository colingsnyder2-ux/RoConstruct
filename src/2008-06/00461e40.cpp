// from server: 100% by king_originala
extern "C" void* __stdcall sub_6a0926();

struct S {
    char pad_0[0x7c];
    void* field_7c;
    unsigned int field_80;
    char pad_84[0x14];
    int field_98;

    int sub_6a1412(int, int, int, int, int);
    int f(int, int, int, int, int);
};

int S::f(int a, int b, int c, int d, int e)
{
    void* h = *(void**)((char*)sub_6a0926() + 0x0c);
    field_80 |= 0x200;
    field_7c = h;
    field_98 = a ? 0x65 : 0x66;
    return sub_6a1412(a, b, c, d, e);
}
