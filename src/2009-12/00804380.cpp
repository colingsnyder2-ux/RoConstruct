// from server: 100% by atomic.potato
struct CXTPCommandBar
{
    void f(int);
};

void CXTPCommandBar::f(int value)
{
    if (value)
        *(unsigned long *)((char *)this + 0xf0) |= 0x400000;
    else
        *(unsigned long *)((char *)this + 0xf0) &= 0xffbfffff;
}
