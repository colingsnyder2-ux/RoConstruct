// from server: 40% by colin
// roc 2007-08 0069ed32  unit: CXTPPropertyGridItemEnum  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0069ed32
//
// 0069ed32  33c0                 xor eax, eax
// 0069ed34  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0069ed37  64890d00000000       mov dword ptr fs:[0], ecx
// 0069ed3e  59                   pop ecx
// 0069ed3f  5f                   pop edi
// 0069ed40  5e                   pop esi
// 0069ed41  5b                   pop ebx
// 0069ed42  8be5                 mov esp, ebp
// 0069ed44  5d                   pop ebp
// 0069ed45  c3                   ret 

struct CXTPPropertyGridItemEnum
{
    void f();
};

void CXTPPropertyGridItemEnum::f()
{
    int* p = (int*)0;
    *p = 0;
}
