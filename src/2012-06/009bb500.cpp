// roc 2012-06 009bb500  unit: VCXTPReportRows::?$CXTPHeapObjectT  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009bb500
//
// 009bb500  8b442404             mov eax, dword ptr [esp + 4]
// 009bb504  8b5128               mov edx, dword ptr [ecx + 0x28]
// 009bb507  50                   push eax
// 009bb508  8b4124               mov eax, dword ptr [ecx + 0x24]
// 009bb50b  6a04                 push 4
// 009bb50d  52                   push edx
// 009bb50e  50                   push eax
// 009bb50f  ff15d428b200         call dword ptr [0xb228d4]
// 009bb515  83c410               add esp, 0x10
// 009bb518  c20400               ret 4
// copied from an identical function in another client (function ?Sort@VCXTPReportRows@ns_ROCX00002e@@QAEXP6AHPBX0@Z@Z)

namespace ns_ROCX00002e {
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
}
