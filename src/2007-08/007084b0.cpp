// from server: 100% by colin
struct CXTColorHex
{
    char pad[0x64];
    char field_64;
    int Set(const char* str);
};

extern "C" int __stdcall sub_0062FCF2(const char* str);

int CXTColorHex::Set(const char* str)
{
    if (sub_0062FCF2(str) == 0)
        return 0;
    field_64 = 0;
    return 1;
}
