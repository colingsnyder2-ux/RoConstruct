// from server: 100% by king_originala
struct String;

extern void (__thiscall *string_construct)(String *);
extern String &(__thiscall *string_assign)(String *, const String &);

struct Base {
    unsigned char storage[0x144];
    Base();
    ~Base();
};

struct String {
    unsigned char storage[28];
    String(void *);
    ~String();
    String &operator=(const String &);
};

struct S : Base {
    String text;
    S(int, const String &);
    void initialize();
    void setValue(int);
};

__forceinline String::String(void *object)
{
    unsigned char *p = (unsigned char *)object;
    *(unsigned long *)(p + 0x000) = 0x0082fce4;
    *(unsigned long *)(p + 0x010) = 0x0082fcd4;
    *(unsigned long *)(p + 0x014) = 0x0082fccc;
    *(unsigned long *)(p + 0x020) = 0x0082fcc4;
    *(unsigned long *)(p + 0x024) = 0x0082fcb4;
    *(unsigned long *)(p + 0x044) = 0x0082fca4;
    *(unsigned long *)(p + 0x064) = 0x0082fc94;
    *(unsigned long *)(p + 0x084) = 0x0082fc84;
    *(unsigned long *)(p + 0x0a4) = 0x0082fc74;
    *(unsigned long *)(p + 0x0c4) = 0x0082fc64;
    *(unsigned long *)(p + 0x130) = 0x0082fc5c;
    string_construct(this);
}

inline String &String::operator=(const String &other)
{
    return string_assign(this, other);
}

S::S(int value, const String &name)
    : Base(), text(this)
{
    initialize();
    setValue(value);
    text = name;
}
