// from server: 53% by Intel
struct LDrawParser {
    void* vftable;
    char gap4[32];
    int field24;
    int field28;
    int field2C;
    LDrawParser(const char* name);
};

extern "C" void __stdcall std_string_ctor(void* thisptr, const char* str);

LDrawParser::LDrawParser(const char* name) {
    vftable = (void*)0x796370;
    std_string_ctor(this + 4, name);
    field24 = 0;
    field28 = 0;
    field2C = 0;
}
