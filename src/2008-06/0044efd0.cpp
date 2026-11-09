// from server: 100% by king_originala
struct S;
typedef const char* (__thiscall *StringAccessor)(const void*);
extern StringAccessor stringAccessor;

struct S
{
    char padding[0x114];
    char text[0x14];
    unsigned int length;

    void prepare();
    void apply(const char*, int, int, int, int, int);
    int f();
};

int S::f()
{
    prepare();
    if (length != 0)
    {
        apply(stringAccessor(text), 0, 0, 0, 0, 0);
        return 0;
    }
    return 1;
}
