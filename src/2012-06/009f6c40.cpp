// roc 2012-06 009f6c40  unit: CXTCaption  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009f6c40
//
// 009f6c40  56                   push esi
// 009f6c41  8bf1                 mov esi, ecx
// 009f6c43  e858fe0600           call 0xa66aa0
// 009f6c48  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 009f6c4c  8b10                 mov edx, dword ptr [eax]
// 009f6c4e  8b5210               mov edx, dword ptr [edx + 0x10]
// 009f6c51  51                   push ecx
// 009f6c52  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 009f6c56  56                   push esi
// 009f6c57  51                   push ecx
// 009f6c58  8bc8                 mov ecx, eax
// 009f6c5a  ffd2                 call edx
// 009f6c5c  5e                   pop esi
// 009f6c5d  c20800               ret 8
// copied from an identical function in another client (function ?method@CSelectionCaption@ns_ROCX000000@@QAEXHH@Z)

namespace ns_ROCX000000 {
struct CSelectionCaption {
    void method(int, int);
};

extern "C" void* __cdecl sub_710f90();

void CSelectionCaption::method(int a, int b) {
    void* p = sub_710f90();
    void** vtbl = *(void***)p;
    void (__thiscall *fn)(void*, int, void*, int) = (void (__thiscall *)(void*, int, void*, int))vtbl[4];
    fn(p, a, this, b);
}
}
