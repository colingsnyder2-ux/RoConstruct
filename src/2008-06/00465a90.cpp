// from server: 100% by king_originala
struct Variant
{
    unsigned short type;
    unsigned short reserved[3];
    unsigned long value;
    unsigned long extra;
};

struct S
{
    unsigned char padding[0xF4];
    unsigned char enabled;

    int fallback(void* site, long id, Variant* result);
    int f(void* site, long id, Variant* result);
};

int S::f(void* site, long id, Variant* result)
{
    if (id != -5512)
        return fallback(site, id, result);

    if (enabled)
    {
        result->type = 3;
        result->value = 0x1730;
        return 1;
    }

    return fallback(site, -5512, result);
}
