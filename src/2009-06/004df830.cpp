// from server: 100% by auto
// roc 2009-06 004df830  unit: RBX::Network::IdSerializer  size: 157 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004df830
//
// 004df830  83ec08               sub esp, 8
// 004df833  53                   push ebx
// 004df834  56                   push esi
// 004df835  8bf1                 mov esi, ecx
// 004df837  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 004df83a  57                   push edi
// 004df83b  85db                 test ebx, ebx
// 004df83d  7504                 jne 0x4df843
// 004df83f  33c9                 xor ecx, ecx
// 004df841  eb15                 jmp 0x4df858
// 004df843  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 004df846  2bcb                 sub ecx, ebx
// 004df848  b8abaaaa2a           mov eax, 0x2aaaaaab
// 004df84d  f7e9                 imul ecx
// 004df84f  d1fa                 sar edx, 1
// 004df851  8bca                 mov ecx, edx
// 004df853  c1e91f               shr ecx, 0x1f
// 004df856  03ca                 add ecx, edx
// 004df858  8b7e10               mov edi, dword ptr [esi + 0x10]
// 004df85b  8bd7                 mov edx, edi
// 004df85d  2bd3                 sub edx, ebx
// 004df85f  b8abaaaa2a           mov eax, 0x2aaaaaab
// 004df864  f7ea                 imul edx
// 004df866  d1fa                 sar edx, 1
// 004df868  8bc2                 mov eax, edx
// 004df86a  c1e81f               shr eax, 0x1f
// 004df86d  03c2                 add eax, edx
// 004df86f  3bc1                 cmp eax, ecx
// 004df871  7332                 jae 0x4df8a5
// 004df873  8b542418             mov edx, dword ptr [esp + 0x18]
// 004df877  c644240c00           mov byte ptr [esp + 0xc], 0
// 004df87c  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004df880  51                   push ecx
// 004df881  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 004df885  52                   push edx
// 004df886  8d4608               lea eax, [esi + 8]
// 004df889  50                   push eax
// 004df88a  51                   push ecx
// 004df88b  6a01                 push 1
// 004df88d  57                   push edi
// 004df88e  e8edf0ffff           call 0x4de980
// 004df893  83c418               add esp, 0x18
// 004df896  83c70c               add edi, 0xc
// 004df899  897e10               mov dword ptr [esi + 0x10], edi
// 004df89c  5f                   pop edi
// 004df89d  5e                   pop esi
// 004df89e  5b                   pop ebx
// 004df89f  83c408               add esp, 8
// 004df8a2  c20400               ret 4
// 004df8a5  3bdf                 cmp ebx, edi
// 004df8a7  7606                 jbe 0x4df8af
// 004df8a9  ff15ace98900         call dword ptr [0x89e9ac]
// 004df8af  8b542418             mov edx, dword ptr [esp + 0x18]
// 004df8b3  8b06                 mov eax, dword ptr [esi]
// 004df8b5  52                   push edx
// 004df8b6  57                   push edi
// 004df8b7  50                   push eax
// 004df8b8  8d442418             lea eax, [esp + 0x18]
// 004df8bc  50                   push eax
// 004df8bd  8bce                 mov ecx, esi
// 004df8bf  e89cfeffff           call 0x4df760
// 004df8c4  5f                   pop edi
// 004df8c5  5e                   pop esi
// 004df8c6  5b                   pop ebx
// 004df8c7  83c408               add esp, 8
// 004df8ca  c20400               ret 4
// standard library vector<pod12> (function ?push_back@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
