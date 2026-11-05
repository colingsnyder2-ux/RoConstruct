// from server: 37% by colin
// roc 2007-08 0069ef96  unit: CXTPPropertyGridItemEnum  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0069ef96
//
// 0069ef96  33c0                 xor eax, eax
// 0069ef98  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0069ef9b  64890d00000000       mov dword ptr fs:[0], ecx
// 0069efa2  59                   pop ecx
// 0069efa3  5f                   pop edi
// 0069efa4  5e                   pop esi
// 0069efa5  5b                   pop ebx
// 0069efa6  8be5                 mov esp, ebp
// 0069efa8  5d                   pop ebp
// 0069efa9  c21400               ret 0x14

struct CXTPPropertyGridItemEnum
{
    int func_0069ef96(int, int, int, int, int);
};

int CXTPPropertyGridItemEnum::func_0069ef96(int, int, int, int, int)
{
    return 0;
}
