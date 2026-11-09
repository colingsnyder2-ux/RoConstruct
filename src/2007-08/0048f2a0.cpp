// from server: 100% by colin
struct S_func_0048f2a0
{
    char pad[0x124];
    char field_0x124;
    void setValue(char value);
};

extern "C" void __stdcall sub_00444710(void*);

void S_func_0048f2a0::setValue(char value)
{
    if (value != field_0x124)
    {
        field_0x124 = value;
        sub_00444710((void*)0x8bdf3c);
    }
}
