// from server: 100% by auto
// roc 2009-06 0044cc50  unit: CRobloxControlColorSelector  size: 157 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0044cc50
//
// 0044cc50  83ec08               sub esp, 8
// 0044cc53  53                   push ebx
// 0044cc54  56                   push esi
// 0044cc55  8bf1                 mov esi, ecx
// 0044cc57  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 0044cc5a  57                   push edi
// 0044cc5b  85db                 test ebx, ebx
// 0044cc5d  7504                 jne 0x44cc63
// 0044cc5f  33c9                 xor ecx, ecx
// 0044cc61  eb15                 jmp 0x44cc78
// 0044cc63  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 0044cc66  2bcb                 sub ecx, ebx
// 0044cc68  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0044cc6d  f7e9                 imul ecx
// 0044cc6f  d1fa                 sar edx, 1
// 0044cc71  8bca                 mov ecx, edx
// 0044cc73  c1e91f               shr ecx, 0x1f
// 0044cc76  03ca                 add ecx, edx
// 0044cc78  8b7e10               mov edi, dword ptr [esi + 0x10]
// 0044cc7b  8bd7                 mov edx, edi
// 0044cc7d  2bd3                 sub edx, ebx
// 0044cc7f  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0044cc84  f7ea                 imul edx
// 0044cc86  d1fa                 sar edx, 1
// 0044cc88  8bc2                 mov eax, edx
// 0044cc8a  c1e81f               shr eax, 0x1f
// 0044cc8d  03c2                 add eax, edx
// 0044cc8f  3bc1                 cmp eax, ecx
// 0044cc91  7332                 jae 0x44ccc5
// 0044cc93  8b542418             mov edx, dword ptr [esp + 0x18]
// 0044cc97  c644240c00           mov byte ptr [esp + 0xc], 0
// 0044cc9c  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0044cca0  51                   push ecx
// 0044cca1  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0044cca5  52                   push edx
// 0044cca6  8d4608               lea eax, [esi + 8]
// 0044cca9  50                   push eax
// 0044ccaa  51                   push ecx
// 0044ccab  6a01                 push 1
// 0044ccad  57                   push edi
// 0044ccae  e8fdf9ffff           call 0x44c6b0
// 0044ccb3  83c418               add esp, 0x18
// 0044ccb6  83c70c               add edi, 0xc
// 0044ccb9  897e10               mov dword ptr [esi + 0x10], edi
// 0044ccbc  5f                   pop edi
// 0044ccbd  5e                   pop esi
// 0044ccbe  5b                   pop ebx
// 0044ccbf  83c408               add esp, 8
// 0044ccc2  c20400               ret 4
// 0044ccc5  3bdf                 cmp ebx, edi
// 0044ccc7  7606                 jbe 0x44cccf
// 0044ccc9  ff15ace98900         call dword ptr [0x89e9ac]
// 0044cccf  8b542418             mov edx, dword ptr [esp + 0x18]
// 0044ccd3  8b06                 mov eax, dword ptr [esi]
// 0044ccd5  52                   push edx
// 0044ccd6  57                   push edi
// 0044ccd7  50                   push eax
// 0044ccd8  8d442418             lea eax, [esp + 0x18]
// 0044ccdc  50                   push eax
// 0044ccdd  8bce                 mov ecx, esi
// 0044ccdf  e89cfeffff           call 0x44cb80
// 0044cce4  5f                   pop edi
// 0044cce5  5e                   pop esi
// 0044cce6  5b                   pop ebx
// 0044cce7  83c408               add esp, 8
// 0044ccea  c20400               ret 4
// standard library vector<pod12> (function ?push_back@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
