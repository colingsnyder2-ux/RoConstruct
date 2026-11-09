// from server: 100% by tester
struct CXTPCustomizeSheet {
    char pad[0xb8];
    void* m_p;
    void SetActivePage1();
};

void CXTPCustomizeSheet::SetActivePage1()
{
    void* p = *(void**)((char*)m_p + 0x58);
    if (p)
    {
        *(int*)((char*)p + 0x148) = 1;
        void* q = *(void**)((char*)p + 0xfc);
        void** vt = *(void***)q;
        typedef void (__thiscall *Fn)(void*);
        Fn fn = (Fn)vt[0x17c / 4];
        fn(q);
    }
}
