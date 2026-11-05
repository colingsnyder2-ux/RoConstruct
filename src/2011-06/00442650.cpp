// from server: 80% by atomic.potato
struct CProgressDialog
{
    void f();
};

void CProgressDialog::f()
{
    struct V
    {
        void (__thiscall *release)(void *, void *, int);
    };

    V *p = *(V **)((char *)this + 8);
    if (p != 0 && p->release != 0)
        p->release((char *)this + 16, (char *)this + 16, 2);
    *(V **)((char *)this + 8) = 0;
}
