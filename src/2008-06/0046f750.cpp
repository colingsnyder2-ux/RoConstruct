// from server: 52% by king_originala
struct String;

extern void (__thiscall *construct_string)(String*, const char*);
extern const char* (__thiscall *string_c_str)(const String*);

struct String {
    char storage[28];
    String(const char*);
    String(const String&);
    const char* c_str() const;
};

inline String::String(const char* text)
{
    String* volatile destination = this;
    construct_string(this, text);
}

inline const char* String::c_str() const
{
    return string_c_str(this);
}

struct Output;
extern Output* __cdecl write(Output*, const char*);

struct Item {
    virtual void unused() = 0;
    virtual void emit(Output*, String) = 0;
};

struct Parser {
    char storage[12];
    Item** first;
    Item** last;

    Item** get(unsigned int);
    void emit(Output*);
};

void Parser::emit(Output* output)
{
    write(write(output, reinterpret_cast<const char*>(0x81cbf8)),
          reinterpret_cast<const char*>(0x81cbcc));

    write(
        write(
            write(
                write(output, reinterpret_cast<const char*>(0x81cbec)),
                reinterpret_cast<const String*>(
                    reinterpret_cast<const char*>(this) + 4)->c_str()),
            reinterpret_cast<const char*>(0x81ca88)),
        reinterpret_cast<const char*>(0x81cbcc));

    write(write(output, reinterpret_cast<const char*>(0x81cbdc)),
          reinterpret_cast<const char*>(0x81cbcc));
    write(output, reinterpret_cast<const char*>(0x81cbcc));

    unsigned int count = static_cast<unsigned int>(last - first);
    for (unsigned int i = 0; i < count; ++i) {
        Item* item = *get(i);
        item->emit(output, String(reinterpret_cast<const char*>(0x81cbd8)));
    }
}
