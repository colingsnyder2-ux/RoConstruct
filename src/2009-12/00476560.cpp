// from server: 100% by atomic.potato
struct CWebToolboxBase {
    char padding[0xf8];
};

struct Sub1 {
    void method();
};

struct CWebToolbox : CWebToolboxBase {
    void other(int);
    Sub1 *field_f8;
    void f(int);
};

void CWebToolbox::f(int)
{
    if (field_f8)
        field_f8->method();
    other(0);
}
