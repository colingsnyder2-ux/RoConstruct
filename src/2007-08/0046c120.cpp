// from server: 46% by colin
struct RBX_LDrawParser {
    int field0;
    char pad[0x20];
    int field24;
    int field28;
    int field2c;
    RBX_LDrawParser(const char*);
};

extern "C" __declspec(dllimport) void* __stdcall MSVCP80_basic_string_ctor(void*, const char*);

RBX_LDrawParser::RBX_LDrawParser(const char* s)
{
    field0 = 0x796370;
    MSVCP80_basic_string_ctor((char*)this + 4, s);
    field24 = 0;
    field28 = 0;
    field2c = 0;
}
