// from server: 100% by atomic.potato
struct DxUserInput
{
    unsigned short field0;
    unsigned short field2;
    void *field4;
    int field8;
    int fieldC;
    int field10;

    void f();
};

extern "C" void __cdecl sub_7A7C46(void *);

void DxUserInput::f()
{
    void *p = field4;
    field10 = 0;
    if (p != 0)
    {
        sub_7A7C46(p);
        field4 = 0;
    }
    field8 = 0;
    fieldC = 0;
    field0 = 0;
    field2 = 0x4e4;
}
