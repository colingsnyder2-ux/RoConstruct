// from server: 46% by colin
struct LDraw2RobloxMapRoot {
    int field0;
    int field4;
    char field8[0x1c];
    char field24[0x1c];
    LDraw2RobloxMapRoot(const LDraw2RobloxMapRoot& other);
};

extern "C" void __stdcall copy_string(char* dst, const char* src);

LDraw2RobloxMapRoot::LDraw2RobloxMapRoot(const LDraw2RobloxMapRoot& other)
{
    field0 = other.field0;
    field4 = other.field4;
    copy_string(field8, other.field8);
    copy_string(field24, other.field24);
}
