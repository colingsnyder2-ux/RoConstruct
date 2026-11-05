// from server: 100% by auto
// roc 2008-06 004a8790  unit: RBX::VHint::?$FactoryProduct::Creator  size: 157 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004a8790
//
// 004a8790  83ec08               sub esp, 8
// 004a8793  53                   push ebx
// 004a8794  56                   push esi
// 004a8795  8bf1                 mov esi, ecx
// 004a8797  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 004a879a  57                   push edi
// 004a879b  85db                 test ebx, ebx
// 004a879d  7504                 jne 0x4a87a3
// 004a879f  33c9                 xor ecx, ecx
// 004a87a1  eb15                 jmp 0x4a87b8
// 004a87a3  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 004a87a6  2bcb                 sub ecx, ebx
// 004a87a8  b8abaaaa2a           mov eax, 0x2aaaaaab
// 004a87ad  f7e9                 imul ecx
// 004a87af  d1fa                 sar edx, 1
// 004a87b1  8bca                 mov ecx, edx
// 004a87b3  c1e91f               shr ecx, 0x1f
// 004a87b6  03ca                 add ecx, edx
// 004a87b8  8b7e10               mov edi, dword ptr [esi + 0x10]
// 004a87bb  8bd7                 mov edx, edi
// 004a87bd  2bd3                 sub edx, ebx
// 004a87bf  b8abaaaa2a           mov eax, 0x2aaaaaab
// 004a87c4  f7ea                 imul edx
// 004a87c6  d1fa                 sar edx, 1
// 004a87c8  8bc2                 mov eax, edx
// 004a87ca  c1e81f               shr eax, 0x1f
// 004a87cd  03c2                 add eax, edx
// 004a87cf  3bc1                 cmp eax, ecx
// 004a87d1  7332                 jae 0x4a8805
// 004a87d3  8b542418             mov edx, dword ptr [esp + 0x18]
// 004a87d7  c644240c00           mov byte ptr [esp + 0xc], 0
// 004a87dc  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004a87e0  51                   push ecx
// 004a87e1  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 004a87e5  52                   push edx
// 004a87e6  8d4608               lea eax, [esi + 8]
// 004a87e9  50                   push eax
// 004a87ea  51                   push ecx
// 004a87eb  6a01                 push 1
// 004a87ed  57                   push edi
// 004a87ee  e89df1ffff           call 0x4a7990
// 004a87f3  83c418               add esp, 0x18
// 004a87f6  83c70c               add edi, 0xc
// 004a87f9  897e10               mov dword ptr [esi + 0x10], edi
// 004a87fc  5f                   pop edi
// 004a87fd  5e                   pop esi
// 004a87fe  5b                   pop ebx
// 004a87ff  83c408               add esp, 8
// 004a8802  c20400               ret 4
// 004a8805  3bdf                 cmp ebx, edi
// 004a8807  7606                 jbe 0x4a880f
// 004a8809  ff1590288000         call dword ptr [0x802890]
// 004a880f  8b542418             mov edx, dword ptr [esp + 0x18]
// 004a8813  8b06                 mov eax, dword ptr [esi]
// 004a8815  52                   push edx
// 004a8816  57                   push edi
// 004a8817  50                   push eax
// 004a8818  8d442418             lea eax, [esp + 0x18]
// 004a881c  50                   push eax
// 004a881d  8bce                 mov ecx, esi
// 004a881f  e89cfeffff           call 0x4a86c0
// 004a8824  5f                   pop edi
// 004a8825  5e                   pop esi
// 004a8826  5b                   pop ebx
// 004a8827  83c408               add esp, 8
// 004a882a  c20400               ret 4
// standard library vector<pod12> (function ?push_back@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
