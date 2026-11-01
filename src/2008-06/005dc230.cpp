// from server: 100% by king_originala
extern char property;

struct S
{
    char padding[0x1e8];
    unsigned char unused : 4;
    unsigned char selected : 1;
    unsigned char remaining : 3;

    void f(bool value);
    void notify(const void* descriptor);
};

void S::f(bool value)
{
    if (selected != value)
    {
        selected = value;
        notify(&property);
    }
}
