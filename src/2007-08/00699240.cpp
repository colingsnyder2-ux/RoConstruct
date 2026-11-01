// from server: 100% by colin
struct CXTPPropertyGridItemConstraints {
    char pad[0x24];
    void* m_base;
    unsigned int m_count;
    void SortMembers();
};

extern "C" __declspec(dllimport) void qsort(void* base, unsigned int num, unsigned int width, int (__cdecl* comp)(const void*, const void*));

int __cdecl CompareFunction(const void* a, const void* b);

void CXTPPropertyGridItemConstraints::SortMembers() {
    qsort(m_base, m_count, 4, CompareFunction);
}
