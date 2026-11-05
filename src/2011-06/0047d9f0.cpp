// from server: 100% by atomic.potato
struct CRobloxPlayerDlg
{
    char pad[0xc];
    void* field_c;
    void Release();
};

void CRobloxPlayerDlg::Release()
{
    void* p = field_c;
    if (p)
    {
        void** vtbl = *(void***)p;
        void (__stdcall *fn)(void*) = (void (__stdcall *)(void*))vtbl[2];
        fn(p);
    }
}
