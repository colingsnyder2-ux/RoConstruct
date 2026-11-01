// from server: 100% by colin
typedef unsigned long DWORD;

struct CXTPControls
{
    unsigned char pad[0xd0];
    DWORD field_d0;

    DWORD GetSomeValue();
};

DWORD CXTPControls::GetSomeValue()
{
    DWORD value = this->field_d0;
    if (value)
        return *(DWORD*)(value + 0x24);
    return 0;
}
