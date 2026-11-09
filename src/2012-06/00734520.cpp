// from server: 100% by atomic.potato
struct S_func_00734520 {
    void* m_p;
    void assign(void* p);
};

extern "C" void __stdcall sub_00983270(void* p, int a, void* b, void* c);
extern "C" void __cdecl sub_009823BA(void* p);

void S_func_00734520::assign(void* p)
{
    void* old = m_p;
    m_p = p;
    if (old) {
        int n = *(int*)((char*)old - 4);
        void* base = (char*)old - 4;
        sub_00983270(old, 0x84, (void*)n, (void*)0x70c7c0);
        sub_009823BA(base);
    }
}
