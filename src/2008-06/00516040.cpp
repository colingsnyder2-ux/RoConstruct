// from server: 100% by auto
// roc 2008-06 00516040  unit: G3D::BinaryInput  size: 136 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00516040
//
// 00516040  53                   push ebx
// 00516041  8b5c2408             mov ebx, dword ptr [esp + 8]
// 00516045  55                   push ebp
// 00516046  8b2d90288000         mov ebp, dword ptr [0x802890]
// 0051604c  56                   push esi
// 0051604d  8bf1                 mov esi, ecx
// 0051604f  57                   push edi
// 00516050  c70300000000         mov dword ptr [ebx], 0
// 00516056  85f6                 test esi, esi
// 00516058  740e                 je 0x516068
// 0051605a  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0051605e  39460c               cmp dword ptr [esi + 0xc], eax
// 00516061  7705                 ja 0x516068
// 00516063  3b4610               cmp eax, dword ptr [esi + 0x10]
// 00516066  7606                 jbe 0x51606e
// 00516068  ffd5                 call ebp
// 0051606a  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0051606e  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00516072  8b0e                 mov ecx, dword ptr [esi]
// 00516074  890b                 mov dword ptr [ebx], ecx
// 00516076  894304               mov dword ptr [ebx + 4], eax
// 00516079  397e0c               cmp dword ptr [esi + 0xc], edi
// 0051607c  7705                 ja 0x516083
// 0051607e  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 00516081  7606                 jbe 0x516089
// 00516083  ffd5                 call ebp
// 00516085  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00516089  8b03                 mov eax, dword ptr [ebx]
// 0051608b  8b0e                 mov ecx, dword ptr [esi]
// 0051608d  85c0                 test eax, eax
// 0051608f  7404                 je 0x516095
// 00516091  3bc1                 cmp eax, ecx
// 00516093  7402                 je 0x516097
// 00516095  ffd5                 call ebp
// 00516097  8b5304               mov edx, dword ptr [ebx + 4]
// 0051609a  3bd7                 cmp edx, edi
// 0051609c  7421                 je 0x5160bf
// 0051609e  8b4610               mov eax, dword ptr [esi + 0x10]
// 005160a1  2bc7                 sub eax, edi
// 005160a3  d1f8                 sar eax, 1
// 005160a5  8d0c00               lea ecx, [eax + eax]
// 005160a8  8d2c11               lea ebp, [ecx + edx]
// 005160ab  85c0                 test eax, eax
// 005160ad  7e0d                 jle 0x5160bc
// 005160af  51                   push ecx
// 005160b0  57                   push edi
// 005160b1  51                   push ecx
// 005160b2  52                   push edx
// 005160b3  ff1550288000         call dword ptr [0x802850]
// 005160b9  83c410               add esp, 0x10
// 005160bc  896e10               mov dword ptr [esi + 0x10], ebp
// 005160bf  5f                   pop edi
// 005160c0  5e                   pop esi
// 005160c1  5d                   pop ebp
// 005160c2  8bc3                 mov eax, ebx
// 005160c4  5b                   pop ebx
// 005160c5  c21400               ret 0x14
// standard library vector<short> (function ?erase@?$vector@FV?$allocator@F@std@@@std@@QAE?AV?$_Vector_iterator@FV?$allocator@F@std@@@2@V?$_Vector_const_iterator@FV?$allocator@F@std@@@2@0@Z)

// stl: vector<short>
typedef short E;
#include <vector>
template class std::vector<E>;
