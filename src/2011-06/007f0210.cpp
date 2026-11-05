// from server: 75% by atomic.potato
struct PolyContact {
    char pad0[0xa0];
    unsigned int m_count;
    void* m_items[1];
    void clear();
};

extern "C" void __cdecl sub_7efff0();

void PolyContact::clear()
{
    sub_7efff0();
    unsigned int i = 0;
    if (m_count > i) {
        do {
            void* p = m_items[i];
            if (p) {
                void** vt = *(void***)p;
                ((void (__thiscall*)(void*, int))vt[0])(p, 1);
            }
            ++i;
        } while (i < m_count);
        m_count = 0;
    } else {
        m_count = i;
    }
}
