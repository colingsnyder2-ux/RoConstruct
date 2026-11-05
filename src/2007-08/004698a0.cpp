// from server: 52% by colin
// roc 2007-08 004698a0  unit: RBX::LDraw2Lua::LDraw2RobloxColorMap  size: 244 bytes

struct std_string {
    char data[0x1c];
    std_string();
    std_string(const std_string&);
    ~std_string();
};

struct string_iterator {
    char data[4];
};

struct LDraw2RobloxColorMap {
    int convert(const std_string& name);
};

extern "C" {
    int __stdcall tolower(int c);
}

extern "C" void* __cdecl __std_begin(void* out, std_string* self);
extern "C" void* __cdecl __std_end(void* out, std_string* self);

int LDraw2RobloxColorMap::convert(const std_string& name)
{
    std_string local(name);

    string_iterator it1;
    string_iterator it2;
    string_iterator it3;
    string_iterator it4;

    __std_begin(&it1, &local);
    __std_end(&it2, &local);
    __std_begin(&it3, &local);
    __std_end(&it4, &local);

    int result = 0;
    result = 0;

    int r = 0;
    r = 0;

    local.~std_string();
    return r;
}
