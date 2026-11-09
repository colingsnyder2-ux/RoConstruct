// from server: 100% by atomic.potato
extern "C" void __stdcall Function_00411F60(int);

struct BoundFuncDesc
{
    int value;
    int pad[45];
    int field_b8;
    void set(int);
};

void BoundFuncDesc::set(int value)
{
    if (field_b8 == value)
        return;
    field_b8 = value;
    Function_00411F60(0xcd221c);
}
