// from server: 80% by atomic.potato
struct CBrowserDocManager
{
    void f(void *);
};

extern CBrowserDocManager *g_manager;
extern void __stdcall Call_0045b070(CBrowserDocManager *, void *);

void CBrowserDocManager::f(void *arg)
{
    if (arg == g_manager)
        Call_0045b070(this, arg);
}
