// from server: 100% by tester
struct CXTPCustomizeSheet {
    char pad[0xb8];
    void* m_pSomething;
    void ClearActivePage();
};

void CXTPCustomizeSheet::ClearActivePage()
{
    void* p = *(void**)((char*)m_pSomething + 0x58);
    if (p)
    {
        *(int*)((char*)p + 0x90) = 0;
        void* q = *(void**)((char*)p + 0x100);
        void** vtbl = *(void***)q;
        typedef void (__thiscall *Fn)(void*);
        Fn fn = (Fn)vtbl[0x184 / 4];
        fn(q);
    }
}
