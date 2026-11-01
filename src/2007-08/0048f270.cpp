// from server: 100% by colin
struct VPlayerBoundFuncDesc
{
    int field0;
    char pad[0x11c];
    int field120;
    void set(int value);
};

void __stdcall func_444710(int);

void VPlayerBoundFuncDesc::set(int value)
{
    if (value != this->field120)
    {
        this->field120 = value;
        func_444710(0x8bde78);
    }
}
