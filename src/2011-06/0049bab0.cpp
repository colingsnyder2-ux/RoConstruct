// from server: 100% by atomic.potato
struct Inner {
    void method();
};

struct CWebToolbox {
    char pad0[0xf8];
    Inner* field_f8;
    int f(int, int, int);
};

int CWebToolbox::f(int, int, int)
{
    if (field_f8)
        field_f8->method();
    return 3;
}
