// from server: 100% by king_originala
struct String;

extern void (__thiscall *string_construct)(String *, const char *);
extern void (__thiscall *string_destroy)(String *);

struct String {
    char storage[28];
    String(const char *);
    ~String();
};

__forceinline String::String(const char *text)
{
    string_construct(this, text);
}

__forceinline String::~String()
{
    string_destroy(this);
}

struct Base {
    unsigned long slots[77];

    Base(int);
    ~Base();
    void setName(const String &);
};

struct S : Base {
    S(int);
};

S::S(int arg) : Base(arg)
{
    slots[0] = 0x83f24c;
    slots[4] = 0x83f240;
    slots[5] = 0x83f238;
    slots[8] = 0x83f230;
    slots[9] = 0x83f220;
    slots[17] = 0x83f210;
    slots[25] = 0x83f200;
    slots[33] = 0x83f1f0;
    slots[41] = 0x83f1e0;
    slots[49] = 0x83f1d0;
    slots[76] = 0x83f1b8;

    String name(reinterpret_cast<const char *>(0x83f28c));
    setName(name);
}
