// from server: 100% by auto
// roc 2009-12 004540c0  unit: CRobloxControlMaterialSelector  size: 157 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004540c0
//
// 004540c0  83ec08               sub esp, 8
// 004540c3  53                   push ebx
// 004540c4  56                   push esi
// 004540c5  8bf1                 mov esi, ecx
// 004540c7  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 004540ca  57                   push edi
// 004540cb  85db                 test ebx, ebx
// 004540cd  7504                 jne 0x4540d3
// 004540cf  33c9                 xor ecx, ecx
// 004540d1  eb15                 jmp 0x4540e8
// 004540d3  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 004540d6  2bcb                 sub ecx, ebx
// 004540d8  b8abaaaa2a           mov eax, 0x2aaaaaab
// 004540dd  f7e9                 imul ecx
// 004540df  d1fa                 sar edx, 1
// 004540e1  8bca                 mov ecx, edx
// 004540e3  c1e91f               shr ecx, 0x1f
// 004540e6  03ca                 add ecx, edx
// 004540e8  8b7e10               mov edi, dword ptr [esi + 0x10]
// 004540eb  8bd7                 mov edx, edi
// 004540ed  2bd3                 sub edx, ebx
// 004540ef  b8abaaaa2a           mov eax, 0x2aaaaaab
// 004540f4  f7ea                 imul edx
// 004540f6  d1fa                 sar edx, 1
// 004540f8  8bc2                 mov eax, edx
// 004540fa  c1e81f               shr eax, 0x1f
// 004540fd  03c2                 add eax, edx
// 004540ff  3bc1                 cmp eax, ecx
// 00454101  7332                 jae 0x454135
// 00454103  8b542418             mov edx, dword ptr [esp + 0x18]
// 00454107  c644240c00           mov byte ptr [esp + 0xc], 0
// 0045410c  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00454110  51                   push ecx
// 00454111  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00454115  52                   push edx
// 00454116  8d4608               lea eax, [esi + 8]
// 00454119  50                   push eax
// 0045411a  51                   push ecx
// 0045411b  6a01                 push 1
// 0045411d  57                   push edi
// 0045411e  e8adfaffff           call 0x453bd0
// 00454123  83c418               add esp, 0x18
// 00454126  83c70c               add edi, 0xc
// 00454129  897e10               mov dword ptr [esi + 0x10], edi
// 0045412c  5f                   pop edi
// 0045412d  5e                   pop esi
// 0045412e  5b                   pop ebx
// 0045412f  83c408               add esp, 8
// 00454132  c20400               ret 4
// 00454135  3bdf                 cmp ebx, edi
// 00454137  7606                 jbe 0x45413f
// 00454139  ff1560b79800         call dword ptr [0x98b760]
// 0045413f  8b542418             mov edx, dword ptr [esp + 0x18]
// 00454143  8b06                 mov eax, dword ptr [esi]
// 00454145  52                   push edx
// 00454146  57                   push edi
// 00454147  50                   push eax
// 00454148  8d442418             lea eax, [esp + 0x18]
// 0045414c  50                   push eax
// 0045414d  8bce                 mov ecx, esi
// 0045414f  e89cfeffff           call 0x453ff0
// 00454154  5f                   pop edi
// 00454155  5e                   pop esi
// 00454156  5b                   pop ebx
// 00454157  83c408               add esp, 8
// 0045415a  c20400               ret 4
// standard library vector<pod12> (function ?push_back@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
