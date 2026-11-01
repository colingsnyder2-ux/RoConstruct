// from server: 100% by auto
// roc 2009-12 0048cbf0  unit: G3D::Shader  size: 122 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0048cbf0
//
// 0048cbf0  53                   push ebx
// 0048cbf1  55                   push ebp
// 0048cbf2  8b2d60b79800         mov ebp, dword ptr [0x98b760]
// 0048cbf8  56                   push esi
// 0048cbf9  57                   push edi
// 0048cbfa  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 0048cbfe  8bf1                 mov esi, ecx
// 0048cc00  c70700000000         mov dword ptr [edi], 0
// 0048cc06  85f6                 test esi, esi
// 0048cc08  740e                 je 0x48cc18
// 0048cc0a  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0048cc0e  39460c               cmp dword ptr [esi + 0xc], eax
// 0048cc11  7705                 ja 0x48cc18
// 0048cc13  3b4610               cmp eax, dword ptr [esi + 0x10]
// 0048cc16  7606                 jbe 0x48cc1e
// 0048cc18  ffd5                 call ebp
// 0048cc1a  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0048cc1e  8b0e                 mov ecx, dword ptr [esi]
// 0048cc20  894704               mov dword ptr [edi + 4], eax
// 0048cc23  8b442424             mov eax, dword ptr [esp + 0x24]
// 0048cc27  890f                 mov dword ptr [edi], ecx
// 0048cc29  39460c               cmp dword ptr [esi + 0xc], eax
// 0048cc2c  7705                 ja 0x48cc33
// 0048cc2e  3b4610               cmp eax, dword ptr [esi + 0x10]
// 0048cc31  7606                 jbe 0x48cc39
// 0048cc33  ffd5                 call ebp
// 0048cc35  8b442424             mov eax, dword ptr [esp + 0x24]
// 0048cc39  8b0e                 mov ecx, dword ptr [esi]
// 0048cc3b  8bd8                 mov ebx, eax
// 0048cc3d  8b07                 mov eax, dword ptr [edi]
// 0048cc3f  85c0                 test eax, eax
// 0048cc41  7404                 je 0x48cc47
// 0048cc43  3bc1                 cmp eax, ecx
// 0048cc45  7402                 je 0x48cc49
// 0048cc47  ffd5                 call ebp
// 0048cc49  8b4704               mov eax, dword ptr [edi + 4]
// 0048cc4c  3bc3                 cmp eax, ebx
// 0048cc4e  7411                 je 0x48cc61
// 0048cc50  8b5610               mov edx, dword ptr [esi + 0x10]
// 0048cc53  50                   push eax
// 0048cc54  52                   push edx
// 0048cc55  53                   push ebx
// 0048cc56  e8b5fdffff           call 0x48ca10
// 0048cc5b  83c40c               add esp, 0xc
// 0048cc5e  894610               mov dword ptr [esi + 0x10], eax
// 0048cc61  8bc7                 mov eax, edi
// 0048cc63  5f                   pop edi
// 0048cc64  5e                   pop esi
// 0048cc65  5d                   pop ebp
// 0048cc66  5b                   pop ebx
// 0048cc67  c21400               ret 0x14
// standard library vector<pod20> (function ?erase@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE?AV?$_Vector_iterator@UE@@V?$allocator@UE@@@std@@@2@V?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@0@Z)

// stl: vector<pod20>
struct E { int v[5]; };
#include <vector>
template class std::vector<E>;
