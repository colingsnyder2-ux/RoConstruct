// from server: 87% by atomic.potato
typedef void *BoostThread;

struct BoostThreadObject
{
    void destroy();
};

extern "C" void __cdecl function_007a799a(BoostThread);

struct CProgressDialog
{
    void *unused;
};

void __cdecl f(BoostThread thread)
{
    if (thread != 0)
    {
        ((BoostThreadObject *)thread)->destroy();
        function_007a799a(thread);
    }
}
