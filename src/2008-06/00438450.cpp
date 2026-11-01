// from server: 100% by colin
struct Str {
    int words[8];
};

struct X {
    char pad[0xa4];
    Str value;
    Str* copy(Str* out);
    Str* convert(Str* out);
};

extern const char* (__thiscall* text_data)(Str*);
extern void (__thiscall* text_destroy)(void*);
extern void (__thiscall* string_construct)(Str*, const char*);

struct Temporary {
    int value;
    Temporary(X* owner, Str*& text);
    __declspec(dllimport) ~Temporary() throw();
};

inline Temporary::Temporary(X* owner, Str*& text)
{
    value = 0;
    text = owner->copy(reinterpret_cast<Str*>(this));
}


Str* X::convert(Str* out)
{
    Str* text;
    Temporary temporary(this, text);
    string_construct(out, text_data(text));
    return out;
}
