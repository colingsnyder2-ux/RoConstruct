// from server: 100% by auto
// roc 2009-12 007997b0  unit: lua_exception  size: 159 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007997b0
//
// 007997b0  83ec08               sub esp, 8
// 007997b3  53                   push ebx
// 007997b4  56                   push esi
// 007997b5  8bf1                 mov esi, ecx
// 007997b7  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 007997ba  57                   push edi
// 007997bb  85db                 test ebx, ebx
// 007997bd  7504                 jne 0x7997c3
// 007997bf  33c9                 xor ecx, ecx
// 007997c1  eb16                 jmp 0x7997d9
// 007997c3  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 007997c6  2bcb                 sub ecx, ebx
// 007997c8  b8abaaaa2a           mov eax, 0x2aaaaaab
// 007997cd  f7e9                 imul ecx
// 007997cf  c1fa02               sar edx, 2
// 007997d2  8bca                 mov ecx, edx
// 007997d4  c1e91f               shr ecx, 0x1f
// 007997d7  03ca                 add ecx, edx
// 007997d9  8b7e10               mov edi, dword ptr [esi + 0x10]
// 007997dc  8bd7                 mov edx, edi
// 007997de  2bd3                 sub edx, ebx
// 007997e0  b8abaaaa2a           mov eax, 0x2aaaaaab
// 007997e5  f7ea                 imul edx
// 007997e7  c1fa02               sar edx, 2
// 007997ea  8bc2                 mov eax, edx
// 007997ec  c1e81f               shr eax, 0x1f
// 007997ef  03c2                 add eax, edx
// 007997f1  3bc1                 cmp eax, ecx
// 007997f3  7332                 jae 0x799827
// 007997f5  8b542418             mov edx, dword ptr [esp + 0x18]
// 007997f9  c644240c00           mov byte ptr [esp + 0xc], 0
// 007997fe  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00799802  51                   push ecx
// 00799803  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00799807  52                   push edx
// 00799808  8d4608               lea eax, [esi + 8]
// 0079980b  50                   push eax
// 0079980c  51                   push ecx
// 0079980d  6a01                 push 1
// 0079980f  57                   push edi
// 00799810  e83bf1ffff           call 0x798950
// 00799815  83c418               add esp, 0x18
// 00799818  83c718               add edi, 0x18
// 0079981b  897e10               mov dword ptr [esi + 0x10], edi
// 0079981e  5f                   pop edi
// 0079981f  5e                   pop esi
// 00799820  5b                   pop ebx
// 00799821  83c408               add esp, 8
// 00799824  c20400               ret 4
// 00799827  3bdf                 cmp ebx, edi
// 00799829  7606                 jbe 0x799831
// 0079982b  ff1560b79800         call dword ptr [0x98b760]
// 00799831  8b542418             mov edx, dword ptr [esp + 0x18]
// 00799835  8b06                 mov eax, dword ptr [esi]
// 00799837  52                   push edx
// 00799838  57                   push edi
// 00799839  50                   push eax
// 0079983a  8d442418             lea eax, [esp + 0x18]
// 0079983e  50                   push eax
// 0079983f  8bce                 mov ecx, esi
// 00799841  e81afeffff           call 0x799660
// 00799846  5f                   pop edi
// 00799847  5e                   pop esi
// 00799848  5b                   pop ebx
// 00799849  83c408               add esp, 8
// 0079984c  c20400               ret 4
// standard library vector<pod24> (function ?push_back@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;
