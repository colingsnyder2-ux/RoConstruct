// from server: 78% by atomic.potato
struct S_func_008f1870 {
    char pad[260];
    int m_104;
    int m_108[7];
    int __cdecl f(int* p);
};

int S_func_008f1870::f(int* p)
{
    int edx = *p;
    int ecx = m_104;
    int eax = *(int*)ecx;
    int (*fn)(int) = *(int (**)(int))((char*)eax + 0x40);
    eax = fn(edx);
    return ((int*)((char*)this + 0x124))[eax];
}
