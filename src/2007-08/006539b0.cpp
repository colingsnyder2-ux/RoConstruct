// from server: 100% by colin
struct CInstanceRecord_CNameItem {
    char pad0[0x48];
    void* m_ptr;
    void f(int);
};

void CInstanceRecord_CNameItem::f(int arg)
{
    if (m_ptr != 0) {
        void** vtbl = *(void***)m_ptr;
        void (__thiscall *fn)(void*, int) = (void (__thiscall *)(void*, int))vtbl[0x2c];
        fn(m_ptr, arg);
    }
}
