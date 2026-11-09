// from server: 38% by atomic.potato
struct S {
    char pad[0x1f4];
    int m_state;
    void* m_ptr;
    void func(int);
};

extern "C" void __cdecl sub_00414DA0(void*);
extern "C" void* __cdecl sub_009823F0(unsigned int);
extern "C" void __cdecl sub_0098337A(void*, int, void*, void*);
extern "C" void __cdecl sub_00983270(void*, int, void*, void*);
extern "C" void __cdecl sub_009823BA(void*);
extern "C" void __cdecl sub_007EBA70();

struct S_assign {
    void* m_p;
    void assign(void* p);
};

void S::func(int a)
{
    if (m_state == a)
        return;
    sub_00414DA0((void*)0xe34160);
    m_state = a;
    if (m_state == 0) {
        void* old = m_ptr;
        m_ptr = 0;
        if (old) {
            int n = *(int*)((char*)old - 4);
            sub_00983270(old, n, (void*)0x70c7c0, (void*)0x84);
            sub_009823BA((char*)old - 4);
        }
    } else {
        unsigned int v = (unsigned int)(m_state - 1);
        if (v > 4)
            return;
        if (m_ptr == 0) {
            void* p = sub_009823F0(0x4a8);
            if (p) {
                *(int*)p = 9;
                sub_0098337A((char*)p + 4, 0x84, (void*)0x70c670, (void*)0x70c7c0);
            }
            ((S_assign*)&m_ptr)->assign(p);
        }
    }
    sub_007EBA70();
}
