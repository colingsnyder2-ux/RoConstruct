// from server: 100% by atomic.potato
struct CXTPCommandBar
{
    void f(void *);
};

void CXTPCommandBar::f(void *value)
{
    *(int *)((char *)*(int *)((char *)this + 0x178) + 0x18) = (int)value;
}
