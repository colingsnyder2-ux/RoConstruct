// from server: 100% by atomic.potato
struct T4_0052a1d0 {
    char pad[0x1ac];
    void* m_1ac;
};

extern "C" void* __fastcall f_00417d10(void*);
extern "C" int __cdecl f_004a01f0(void*);
extern "C" void __fastcall f_0051b240(void*);

void f_0052a1d0(void* a)
{
    T4_0052a1d0* p = (T4_0052a1d0*)f_00417d10(a);
    if (p)
    {
        void* q = p->m_1ac;
        if (q)
        {
            if (f_004a01f0(q))
            {
                f_0051b240(q);
            }
        }
    }
}
