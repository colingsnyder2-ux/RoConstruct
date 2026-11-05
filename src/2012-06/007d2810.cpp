// from server: 66% by atomic.potato
struct Shirt
{
    char padding[0xa4];
    char value[0x20];

    Shirt *f(Shirt *source);
};

struct StringData
{
    char data[0x20];
};

extern "C" StringData *copy_string(StringData *, StringData *);

Shirt *Shirt::f(Shirt *source)
{
    StringData *destination = (StringData *)((char *)this + 0xa4);
    copy_string((StringData *)source, destination);
    source->value[0] = destination->data[0];
    return source;
}
