// from server: 100% by auto
// roc 2008-06 00445dc0  unit: RBX::Reflection::M::?$TypedPropertyDescriptor  size: 141 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00445dc0
//
// 00445dc0  53                   push ebx
// 00445dc1  8b5c2408             mov ebx, dword ptr [esp + 8]
// 00445dc5  55                   push ebp
// 00445dc6  8b2d90288000         mov ebp, dword ptr [0x802890]
// 00445dcc  56                   push esi
// 00445dcd  8bf1                 mov esi, ecx
// 00445dcf  57                   push edi
// 00445dd0  c70300000000         mov dword ptr [ebx], 0
// 00445dd6  85f6                 test esi, esi
// 00445dd8  740e                 je 0x445de8
// 00445dda  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00445dde  39460c               cmp dword ptr [esi + 0xc], eax
// 00445de1  7705                 ja 0x445de8
// 00445de3  3b4610               cmp eax, dword ptr [esi + 0x10]
// 00445de6  7606                 jbe 0x445dee
// 00445de8  ffd5                 call ebp
// 00445dea  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00445dee  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00445df2  8b0e                 mov ecx, dword ptr [esi]
// 00445df4  890b                 mov dword ptr [ebx], ecx
// 00445df6  894304               mov dword ptr [ebx + 4], eax
// 00445df9  397e0c               cmp dword ptr [esi + 0xc], edi
// 00445dfc  7705                 ja 0x445e03
// 00445dfe  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 00445e01  7606                 jbe 0x445e09
// 00445e03  ffd5                 call ebp
// 00445e05  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00445e09  8b03                 mov eax, dword ptr [ebx]
// 00445e0b  8b0e                 mov ecx, dword ptr [esi]
// 00445e0d  85c0                 test eax, eax
// 00445e0f  7404                 je 0x445e15
// 00445e11  3bc1                 cmp eax, ecx
// 00445e13  7402                 je 0x445e17
// 00445e15  ffd5                 call ebp
// 00445e17  8b5304               mov edx, dword ptr [ebx + 4]
// 00445e1a  3bd7                 cmp edx, edi
// 00445e1c  7426                 je 0x445e44
// 00445e1e  8b4610               mov eax, dword ptr [esi + 0x10]
// 00445e21  2bc7                 sub eax, edi
// 00445e23  c1f802               sar eax, 2
// 00445e26  8d0c8500000000       lea ecx, [eax*4]
// 00445e2d  8d2c11               lea ebp, [ecx + edx]
// 00445e30  85c0                 test eax, eax
// 00445e32  7e0d                 jle 0x445e41
// 00445e34  51                   push ecx
// 00445e35  57                   push edi
// 00445e36  51                   push ecx
// 00445e37  52                   push edx
// 00445e38  ff1550288000         call dword ptr [0x802850]
// 00445e3e  83c410               add esp, 0x10
// 00445e41  896e10               mov dword ptr [esi + 0x10], ebp
// 00445e44  5f                   pop edi
// 00445e45  5e                   pop esi
// 00445e46  5d                   pop ebp
// 00445e47  8bc3                 mov eax, ebx
// 00445e49  5b                   pop ebx
// 00445e4a  c21400               ret 0x14
// standard library vector<ptr> (function ?erase@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE?AV?$_Vector_iterator@PAUT@@V?$allocator@PAUT@@@std@@@2@V?$_Vector_const_iterator@PAUT@@V?$allocator@PAUT@@@std@@@2@0@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
