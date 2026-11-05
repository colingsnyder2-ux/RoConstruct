// from server: 100% by auto
// roc 2008-06 004445c0  unit: RBX::MergeBinder  size: 182 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004445c0
//
// 004445c0  83ec08               sub esp, 8
// 004445c3  53                   push ebx
// 004445c4  55                   push ebp
// 004445c5  56                   push esi
// 004445c6  8bf1                 mov esi, ecx
// 004445c8  8b4610               mov eax, dword ptr [esi + 0x10]
// 004445cb  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 004445ce  8bc8                 mov ecx, eax
// 004445d0  2bcb                 sub ecx, ebx
// 004445d2  57                   push edi
// 004445d3  f7c1f0ffffff         test ecx, 0xfffffff0
// 004445d9  7504                 jne 0x4445df
// 004445db  33ff                 xor edi, edi
// 004445dd  eb27                 jmp 0x444606
// 004445df  3bd8                 cmp ebx, eax
// 004445e1  7606                 jbe 0x4445e9
// 004445e3  ff1590288000         call dword ptr [0x802890]
// 004445e9  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 004445ed  8b06                 mov eax, dword ptr [esi]
// 004445ef  85c9                 test ecx, ecx
// 004445f1  7404                 je 0x4445f7
// 004445f3  3bc8                 cmp ecx, eax
// 004445f5  7406                 je 0x4445fd
// 004445f7  ff1590288000         call dword ptr [0x802890]
// 004445fd  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00444601  2bfb                 sub edi, ebx
// 00444603  c1ff04               sar edi, 4
// 00444606  8b542428             mov edx, dword ptr [esp + 0x28]
// 0044460a  8b442424             mov eax, dword ptr [esp + 0x24]
// 0044460e  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00444612  52                   push edx
// 00444613  6a01                 push 1
// 00444615  50                   push eax
// 00444616  51                   push ecx
// 00444617  8bce                 mov ecx, esi
// 00444619  e8a2fcffff           call 0x4442c0
// 0044461e  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 00444621  3b5e10               cmp ebx, dword ptr [esi + 0x10]
// 00444624  7606                 jbe 0x44462c
// 00444626  ff1590288000         call dword ptr [0x802890]
// 0044462c  8b36                 mov esi, dword ptr [esi]
// 0044462e  8bee                 mov ebp, esi
// 00444630  895c2414             mov dword ptr [esp + 0x14], ebx
// 00444634  85f6                 test esi, esi
// 00444636  751a                 jne 0x444652
// 00444638  ff1590288000         call dword ptr [0x802890]
// 0044463e  33c0                 xor eax, eax
// 00444640  c1e704               shl edi, 4
// 00444643  03fb                 add edi, ebx
// 00444645  3b7810               cmp edi, dword ptr [eax + 0x10]
// 00444648  7713                 ja 0x44465d
// 0044464a  85f6                 test esi, esi
// 0044464c  7408                 je 0x444656
// 0044464e  8b36                 mov esi, dword ptr [esi]
// 00444650  eb06                 jmp 0x444658
// 00444652  8b06                 mov eax, dword ptr [esi]
// 00444654  ebea                 jmp 0x444640
// 00444656  33f6                 xor esi, esi
// 00444658  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 0044465b  7306                 jae 0x444663
// 0044465d  ff1590288000         call dword ptr [0x802890]
// 00444663  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00444667  897804               mov dword ptr [eax + 4], edi
// 0044466a  5f                   pop edi
// 0044466b  5e                   pop esi
// 0044466c  8928                 mov dword ptr [eax], ebp
// 0044466e  5d                   pop ebp
// 0044466f  5b                   pop ebx
// 00444670  83c408               add esp, 8
// 00444673  c21000               ret 0x10
// standard library vector<pod16> (function ?insert@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE?AV?$_Vector_iterator@UE@@V?$allocator@UE@@@std@@@2@V?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@ABUE@@@Z)

// stl: vector<pod16>
struct E { int v[4]; };
#include <vector>
template class std::vector<E>;
