// from server: 27% by colin
struct LDraw2RobloxPartMap
{
    int field0;
    int field4;
    char field8[0x1c];
    char field24[0x1c];
    LDraw2RobloxPartMap(int a, int b, const void* c, const void* d);
};

extern "C" void __stdcall copy_string(void* dest, const void* src);
extern "C" void __stdcall destroy_string(void* s);

LDraw2RobloxPartMap::LDraw2RobloxPartMap(int a, int b, const void* c, const void* d)
{
    field0 = a;
    field4 = b;
    copy_string(field8, c);
    copy_string(field24, d);
    destroy_string(field24);
    destroy_string(field8);
}
