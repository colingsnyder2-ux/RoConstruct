// from server: 73% by colin
struct VCWorkspace_ActiveDocView
{
    void* m_ptr;
};

extern "C" void __stdcall sub_4055F0(void*);

extern void* g_880DF0;
extern char  g_880DE4;

long __stdcall sub_406430(void* p1, void* p2, void* p3, void** ppOut)
{
    if (ppOut == 0)
        return (long)0x80004003;

    if (g_880DF0 == 0)
        sub_4055F0(&g_880DE4);

    *ppOut = g_880DF0;

    if (g_880DF0 != 0)
    {
        void** vtbl = *(void***)g_880DF0;
        void (__stdcall *fn)(void*) = (void (__stdcall *)(void*))vtbl[1];
        fn(g_880DF0);
    }

    return 0;
}
