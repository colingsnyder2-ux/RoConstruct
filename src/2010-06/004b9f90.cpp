// from server: 47% by atomic.potato
struct Shirt
{
    char pad[0xb8];
    struct String
    {
        char data[0x20];
    } value;
    String *copy(String *);
};

extern "C" void string_copy(Shirt::String *, const Shirt::String *);

Shirt::String *Shirt::copy(Shirt::String *source)
{
    string_copy(&value, source);
    return source;
}
