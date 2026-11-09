// from server: 100% by king_originala
extern "C" void __cdecl release_value(void *, int, int);
extern "C" void __cdecl set_value(void *, int, int);
extern "C" int __cdecl get_value(void *, int);

struct S {
    unsigned char padding[24];
    void *context;
    int reserved;
    int value;

    S &assign(const S &other);
    S &copy(const S &other);
};

S &S::assign(const S &other)
{
    if (context)
        release_value(context, -10000, value);

    copy(other);

    if (!context) {
        value = 0;
        return *this;
    }

    set_value(context, -10000, other.value);
    value = get_value(context, -10000);
    return *this;
}
