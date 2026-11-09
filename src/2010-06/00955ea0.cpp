// from server: 100% by auto
// roc 2010-06 00955ea0  unit: seg_00950000  size: 157 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00955ea0
//
// 00955ea0  83ec08               sub esp, 8
// 00955ea3  53                   push ebx
// 00955ea4  56                   push esi
// 00955ea5  8bf1                 mov esi, ecx
// 00955ea7  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 00955eaa  57                   push edi
// 00955eab  85db                 test ebx, ebx
// 00955ead  7504                 jne 0x955eb3
// 00955eaf  33c9                 xor ecx, ecx
// 00955eb1  eb15                 jmp 0x955ec8
// 00955eb3  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 00955eb6  2bcb                 sub ecx, ebx
// 00955eb8  b8abaaaa2a           mov eax, 0x2aaaaaab
// 00955ebd  f7e9                 imul ecx
// 00955ebf  d1fa                 sar edx, 1
// 00955ec1  8bca                 mov ecx, edx
// 00955ec3  c1e91f               shr ecx, 0x1f
// 00955ec6  03ca                 add ecx, edx
// 00955ec8  8b7e10               mov edi, dword ptr [esi + 0x10]
// 00955ecb  8bd7                 mov edx, edi
// 00955ecd  2bd3                 sub edx, ebx
// 00955ecf  b8abaaaa2a           mov eax, 0x2aaaaaab
// 00955ed4  f7ea                 imul edx
// 00955ed6  d1fa                 sar edx, 1
// 00955ed8  8bc2                 mov eax, edx
// 00955eda  c1e81f               shr eax, 0x1f
// 00955edd  03c2                 add eax, edx
// 00955edf  3bc1                 cmp eax, ecx
// 00955ee1  7332                 jae 0x955f15
// 00955ee3  8b542418             mov edx, dword ptr [esp + 0x18]
// 00955ee7  c644240c00           mov byte ptr [esp + 0xc], 0
// 00955eec  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00955ef0  51                   push ecx
// 00955ef1  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00955ef5  52                   push edx
// 00955ef6  8d4608               lea eax, [esi + 8]
// 00955ef9  50                   push eax
// 00955efa  51                   push ecx
// 00955efb  6a01                 push 1
// 00955efd  57                   push edi
// 00955efe  e80df8ffff           call 0x955710
// 00955f03  83c418               add esp, 0x18
// 00955f06  83c70c               add edi, 0xc
// 00955f09  897e10               mov dword ptr [esi + 0x10], edi
// 00955f0c  5f                   pop edi
// 00955f0d  5e                   pop esi
// 00955f0e  5b                   pop ebx
// 00955f0f  83c408               add esp, 8
// 00955f12  c20400               ret 4
// 00955f15  3bdf                 cmp ebx, edi
// 00955f17  7606                 jbe 0x955f1f
// 00955f19  ff150ca99e00         call dword ptr [0x9ea90c]
// 00955f1f  8b542418             mov edx, dword ptr [esp + 0x18]
// 00955f23  8b06                 mov eax, dword ptr [esi]
// 00955f25  52                   push edx
// 00955f26  57                   push edi
// 00955f27  50                   push eax
// 00955f28  8d442418             lea eax, [esp + 0x18]
// 00955f2c  50                   push eax
// 00955f2d  8bce                 mov ecx, esi
// 00955f2f  e80cfeffff           call 0x955d40
// 00955f34  5f                   pop edi
// 00955f35  5e                   pop esi
// 00955f36  5b                   pop ebx
// 00955f37  83c408               add esp, 8
// 00955f3a  c20400               ret 4
// standard library vector<pod12> (function ?push_back@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
