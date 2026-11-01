// from server: 89% by atomic.potato
extern "C" void __cdecl qsort(void *, unsigned int, unsigned int, int (__cdecl *)(const void *, const void *));

struct CXTPPropertyGridItemConstraints
{
    void Sort();
};

void CXTPPropertyGridItemConstraints::Sort()
{
    qsort(*(void **)((char *)this + 0x24), 4, *(unsigned int *)((char *)this + 0x28), (int (__cdecl *)(const void *, const void *))0x864de0);
}
