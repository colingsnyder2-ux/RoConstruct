// from server: 80% by atomic.potato
extern "C" void __cdecl boost_thread_destroy(void *);
extern "C" void __cdecl destroy_thread_object(void *);

struct CProgressDialog
{
    void *thread;
    void f();
};

void CProgressDialog::f()
{
    void *p = thread;
    if (p != 0)
    {
        boost_thread_destroy(p);
        destroy_thread_object(p);
    }
}
