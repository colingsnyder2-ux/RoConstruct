// from server: 53% by atomic.potato
struct CWebToolbox
{
    int fieldF8;
    void f();
};

extern "C" void call_007a7f70(CWebToolbox*);
extern "C" void call_007a7d42(int);

void CWebToolbox::f()
{
    call_007a7f70(this);
    if (fieldF8)
        call_007a7d42(fieldF8);
}
