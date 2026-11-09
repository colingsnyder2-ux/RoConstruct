// from server: 64% by atomic.potato
struct S_func_0074b1a0 {
    char pad0[28];
    int m_x;
    int* f();
};

struct S_func_0074cc30 {
    char pad0[4];
    int m_a;
    int m_b;
    void g(int, int);
};

struct S_func_0074b6b0 {
    void h(void*);
};

struct S {
    char pad0[24];
    S_func_0074b1a0* m_p;
    void func(void*);
};

void S::func(void* a)
{
    S_func_0074b1a0* esi = m_p;
    S_func_0074b1a0* edi = (S_func_0074b1a0*)a;
    int* p = edi->f();
    int ebx = *p;
    int* eax = esi->f();
    int ecx = esi->m_x;
    ecx = eax[ecx - 1];
    eax[ebx] = ecx;
    eax = edi->f();
    *eax = ebx;
    int edx = esi->m_x;
    ((S_func_0074cc30*)esi)->g(edx - 1, 0);
    eax = edi->f();
    *eax = -1;
    ((S_func_0074b6b0*)esi)->h(edi);
    int* edi2 = *(int**)((char*)edi + 0x38);
    if (edi2 != 0) {
        *(float*)((char*)edi2 + 4) = 0.0f;
    }
}
