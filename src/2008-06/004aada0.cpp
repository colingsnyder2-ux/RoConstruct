// from server: 100% by king_originala
extern char property;

struct S
{
    char padding[0x138];
    int value;
    void notify(const void *);
    void set(const int *);
};

void S::set(const int *v)
{
    if (*v != value)
    {
        value = *v;
        notify(&property);
    }
}
