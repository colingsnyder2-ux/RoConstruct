// from server: 100% by Yeetserama
// from server: 100% by king_originala
struct StringData;

typedef const char* (__thiscall *StringAccessor)(const StringData*);
extern StringAccessor string_c_str;
extern const char default_text[];

struct StringData {};

struct FontData {
    char padding[0xc8];
    StringData text;
};

struct Result {
    void finish(const char*);
};

struct CFont {
    char padding[0x134];
    FontData* data;

    Result* get();
    void f();
};

void CFont::f()
{
    if (get()) {
        if (!data)
            get()->finish(default_text);
        else
            get()->finish(string_c_str(&data->text));
    }
}
