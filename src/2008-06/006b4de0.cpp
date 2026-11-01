// from server: 100% by tester
struct CXTPCommandBar {
    void* GetNext();
};

void* CXTPCommandBar::GetNext()
{
    void* p = this;
    void* r = ((void* (__thiscall *)(void*))((*(void***)p)[0x194 / 4]))(p);
    if (r != 0) {
        do {
            p = r;
            r = ((void* (__thiscall *)(void*))((*(void***)p)[0x194 / 4]))(p);
        } while (r != 0);
    }
    return p;
}
