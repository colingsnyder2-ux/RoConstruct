// from server: 45% by atomic.potato
struct Base
{
    virtual void f(int);
};

extern "C" Base *__cdecl sub_8e1870(void *);

struct CXTCaptionButton
{
    void f(int);
};

void CXTCaptionButton::f(int value)
{
    Base *p = sub_8e1870(this);
    p->f(value);
}
