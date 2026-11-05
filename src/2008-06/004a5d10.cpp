// from server: 100% by king_originala
struct String;
extern void (__thiscall *copy_string)(String *, const String *);

struct String
{
    unsigned char data[28];
    String(const String &);
};

inline String::String(const String &other)
{
    copy_string(this, &other);
}

struct Value
{
    unsigned int reserved;
    String text;
};

struct Argument
{
    unsigned int reserved;
    Value *value;
};

struct Creator
{
    String create(const Argument *);
};

String Creator::create(const Argument *arg)
{
    volatile unsigned int temporary = 0;
    return String(arg->value->text);
}
