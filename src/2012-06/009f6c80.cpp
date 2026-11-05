// roc 2012-06 009f6c80  unit: CXTCaption  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009f6c80
//
// 009f6c80  56                   push esi
// 009f6c81  8bf1                 mov esi, ecx
// 009f6c83  e818fe0600           call 0xa66aa0
// 009f6c88  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 009f6c8c  8b10                 mov edx, dword ptr [eax]
// 009f6c8e  8b5218               mov edx, dword ptr [edx + 0x18]
// 009f6c91  51                   push ecx
// 009f6c92  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 009f6c96  56                   push esi
// 009f6c97  51                   push ecx
// 009f6c98  8bc8                 mov ecx, eax
// 009f6c9a  ffd2                 call edx
// 009f6c9c  5e                   pop esi
// 009f6c9d  c20800               ret 8
// copied from an identical function in another client (function ?method@CSelectionCaption@ns_ROCX000002@@QAEXHH@Z)

namespace ns_ROCX000002 {
struct CSelectionCaption {
    void method(int a, int b);
};

extern "C" void* __cdecl sub_710f90();

void CSelectionCaption::method(int a, int b) {
    void* p = sub_710f90();
    void** vtbl = *(void***)p;
    void (__thiscall *fn)(void*, int, void*, int) =
        (void (__thiscall *)(void*, int, void*, int))vtbl[6];
    fn(p, a, this, b);
}
}
