// from server: 37% by colin
// roc 2007-08 0069ebf3  unit: CXTPPropertyGridItemEnum  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0069ebf3
//
// 0069ebf3  33c0                 xor eax, eax
// 0069ebf5  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0069ebf8  64890d00000000       mov dword ptr fs:[0], ecx
// 0069ebff  59                   pop ecx
// 0069ec00  5f                   pop edi
// 0069ec01  5e                   pop esi
// 0069ec02  5b                   pop ebx
// 0069ec03  8be5                 mov esp, ebp
// 0069ec05  5d                   pop ebp
// 0069ec06  c20400               ret 4

struct CXTPPropertyGridItemEnum
{
    int f(int);
};

int CXTPPropertyGridItemEnum::f(int)
{
    return 0;
}
