// from server: 100% by auto
// roc 2009-06 006fe220  unit: RBX::AdornRbxGfx  size: 141 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006fe220
//
// 006fe220  53                   push ebx
// 006fe221  8b5c2408             mov ebx, dword ptr [esp + 8]
// 006fe225  55                   push ebp
// 006fe226  8b2dace98900         mov ebp, dword ptr [0x89e9ac]
// 006fe22c  56                   push esi
// 006fe22d  8bf1                 mov esi, ecx
// 006fe22f  57                   push edi
// 006fe230  c70300000000         mov dword ptr [ebx], 0
// 006fe236  85f6                 test esi, esi
// 006fe238  740e                 je 0x6fe248
// 006fe23a  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006fe23e  39460c               cmp dword ptr [esi + 0xc], eax
// 006fe241  7705                 ja 0x6fe248
// 006fe243  3b4610               cmp eax, dword ptr [esi + 0x10]
// 006fe246  7606                 jbe 0x6fe24e
// 006fe248  ffd5                 call ebp
// 006fe24a  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006fe24e  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 006fe252  8b0e                 mov ecx, dword ptr [esi]
// 006fe254  890b                 mov dword ptr [ebx], ecx
// 006fe256  894304               mov dword ptr [ebx + 4], eax
// 006fe259  397e0c               cmp dword ptr [esi + 0xc], edi
// 006fe25c  7705                 ja 0x6fe263
// 006fe25e  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 006fe261  7606                 jbe 0x6fe269
// 006fe263  ffd5                 call ebp
// 006fe265  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 006fe269  8b03                 mov eax, dword ptr [ebx]
// 006fe26b  8b0e                 mov ecx, dword ptr [esi]
// 006fe26d  85c0                 test eax, eax
// 006fe26f  7404                 je 0x6fe275
// 006fe271  3bc1                 cmp eax, ecx
// 006fe273  7402                 je 0x6fe277
// 006fe275  ffd5                 call ebp
// 006fe277  8b5304               mov edx, dword ptr [ebx + 4]
// 006fe27a  3bd7                 cmp edx, edi
// 006fe27c  7426                 je 0x6fe2a4
// 006fe27e  8b4610               mov eax, dword ptr [esi + 0x10]
// 006fe281  2bc7                 sub eax, edi
// 006fe283  c1f802               sar eax, 2
// 006fe286  8d0c8500000000       lea ecx, [eax*4]
// 006fe28d  8d2c11               lea ebp, [ecx + edx]
// 006fe290  85c0                 test eax, eax
// 006fe292  7e0d                 jle 0x6fe2a1
// 006fe294  51                   push ecx
// 006fe295  57                   push edi
// 006fe296  51                   push ecx
// 006fe297  52                   push edx
// 006fe298  ff155ce98900         call dword ptr [0x89e95c]
// 006fe29e  83c410               add esp, 0x10
// 006fe2a1  896e10               mov dword ptr [esi + 0x10], ebp
// 006fe2a4  5f                   pop edi
// 006fe2a5  5e                   pop esi
// 006fe2a6  5d                   pop ebp
// 006fe2a7  8bc3                 mov eax, ebx
// 006fe2a9  5b                   pop ebx
// 006fe2aa  c21400               ret 0x14
// standard library vector<ptr> (function ?erase@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE?AV?$_Vector_iterator@PAUT@@V?$allocator@PAUT@@@std@@@2@V?$_Vector_const_iterator@PAUT@@V?$allocator@PAUT@@@std@@@2@0@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
