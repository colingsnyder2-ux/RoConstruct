// from server: 59% by atomic.potato
struct S_func_006864c0 {
    char pad0[0x38];
    S_func_006864c0* m_next;
    int f();
};

extern "C" int __cdecl sub_00983448(int, int, int, int, S_func_006864c0*);

int S_func_006864c0::f()
{
    S_func_006864c0* p = m_next;
    if (p) {
        do {
            if (sub_00983448(0, 0xd9a3c4, 0xd601e8, 0, p) != 0)
                return 1;
            p = p->m_next;
        } while (p);
    }
    return 0;
}
