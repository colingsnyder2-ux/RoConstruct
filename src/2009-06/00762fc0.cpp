// from server: 100% by tester
struct CXTPCustomizeSheet {
    char pad[0xb8];
    void* m_pSomething;
    void Func();
};

void CXTPCustomizeSheet::Func()
{
    void* p = *(void**)((char*)m_pSomething + 0x58);
    if (p)
    {
        *(int*)((char*)p + 0x90) = 0;
        void* q = *(void**)((char*)p + 0x100);
        void** vt = *(void***)q;
        typedef void (__thiscall *Fn)(void*);
        Fn fn = (Fn)vt[0x184 / 4];
        fn(q);
    }
}
