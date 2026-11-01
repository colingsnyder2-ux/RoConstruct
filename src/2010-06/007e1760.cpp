// from server: 100% by tester
extern "C" void (__cdecl *qsort)(void*, unsigned int, unsigned int, int (__cdecl*)(const void*, const void*));

struct VCXTPReportRows {
    char pad[0x24];
    void* field24;
    void* field28;
    void Sort(int (__cdecl* cmp)(const void*, const void*));
};

void VCXTPReportRows::Sort(int (__cdecl* cmp)(const void*, const void*)) {
    qsort(field24, (unsigned int)field28, 4, cmp);
}
