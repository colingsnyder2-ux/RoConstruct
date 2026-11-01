// from server: 100% by colin
// from server: 93% by atomic.potato
struct S_func_00801400 {
    void m();
};

extern S_func_00801400 G1_func_00801400;

struct T_sub_00658200 { void m(); };
extern "C" void __cdecl sub_006a067a(void*);

void* g_ptr_0097d944;
void** g_pptr_0097d944 = &g_ptr_0097d944;

void func_00801400()
{
    void*& p = g_ptr_0097d944;
    void* edi = p;
    if (p)
    {
        void* q = *(void**)p;
        if (q)
        {
            ((T_sub_00658200*)q)->m();
            sub_006a067a(q);
        }
        sub_006a067a(edi);
    }
}
