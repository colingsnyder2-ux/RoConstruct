// from server: 81% by atomic.potato
extern "C" void boost_thread_destructor(void *);
extern "C" void __cdecl helper(void *);

struct CProgressDialog
{
};

void __cdecl f(void *p)
{
    if (p)
    {
        boost_thread_destructor(p);
        helper(p);
    }
}
