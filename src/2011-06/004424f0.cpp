// from server: 80% by atomic.potato
extern "C" void boost_thread_destructor(void *);
extern "C" void __cdecl helper(void *);

struct CProgressDialog
{
    void f();
};

void CProgressDialog::f()
{
    void *p = *(void **)this;
    if (p != 0)
    {
        boost_thread_destructor(p);
        helper(p);
    }
}
