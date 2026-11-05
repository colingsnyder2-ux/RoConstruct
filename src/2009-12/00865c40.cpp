// from server: 89% by atomic.potato
extern "C" void __cdecl qsort(void *, unsigned int, unsigned int, int (__cdecl *)(const void *, const void *));

struct CPropertyGridItemBrickColor
{
    void f();
    char padding[36];
    void *member24;
    unsigned int member28;
};

void CPropertyGridItemBrickColor::f()
{
    qsort(member24, 4, member28, (int (__cdecl *)(const void *, const void *))0x864ce0);
}
