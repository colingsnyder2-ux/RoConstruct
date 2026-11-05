// from server: 100% by king_originala
struct String
{
    char data[28];
};

extern bool (__cdecl *strings_differ)(const String&, const String&);
extern String& (__thiscall *string_assign)(String*, const String&);
extern int __cdecl sub_495e80(int, int);
extern char descriptor;

struct S
{
    char padding[0x194];
    String value;

    void set(const String&);
    void update(int);
    void notify(const void*);
};

void S::set(const String& input)
{
    if (strings_differ(input, value))
    {
        string_assign(&value, input);
        if ((unsigned char)sub_495e80((int)this, 0))
            update(0);
        notify(&descriptor);
    }
}
