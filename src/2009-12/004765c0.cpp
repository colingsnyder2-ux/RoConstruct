// from server: 100% by atomic.potato
struct CWebToolboxHelper
{
    void method();
};

struct CWebToolbox
{
    char unused[0xf8];
    CWebToolboxHelper* fieldF8;
    void f(int, int, int);
    void method(int, int, int);
};

void CWebToolbox::f(int a, int b, int c)
{
    method(a, b, c);
    if (fieldF8)
        fieldF8->method();
}
