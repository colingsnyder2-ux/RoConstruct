// roc 2012-06 009f2b10  unit: CXTPPropertyGridItemConstraints  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009f2b10
//
// 009f2b10  8b4128               mov eax, dword ptr [ecx + 0x28]
// 009f2b13  8b4924               mov ecx, dword ptr [ecx + 0x24]
// 009f2b16  68301b9f00           push 0x9f1b30
// 009f2b1b  6a04                 push 4
// 009f2b1d  50                   push eax
// 009f2b1e  51                   push ecx
// 009f2b1f  ff15d428b200         call dword ptr [0xb228d4]
// 009f2b25  83c410               add esp, 0x10
// 009f2b28  c3                   ret 
// copied from an identical function in another client (function ?fn_ROCX00001c@CPropertyGridItemBrickColor@ns_ROCX00001c@@QAEXXZ)

namespace ns_ROCX00001c {
typedef unsigned int size_t;
extern "C" __declspec(dllimport) void qsort(void* base, size_t nmemb, size_t size, int (*compar)(const void*, const void*));

struct CPropertyGridItemBrickColor {
    char pad[0x24];
    void* member_24;
    void* member_28;

    void fn_ROCX00001c();
};

extern "C" int compar_function(const void* a, const void* b);

void CPropertyGridItemBrickColor::fn_ROCX00001c() {
    qsort(member_24, (size_t)member_28, 4, compar_function);
}
}
