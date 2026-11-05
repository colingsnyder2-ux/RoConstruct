// from server: 100% by auto
// roc 2009-06 00574f80  unit: G3D::BinaryInput  size: 141 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00574f80
//
// 00574f80  53                   push ebx
// 00574f81  8b5c2408             mov ebx, dword ptr [esp + 8]
// 00574f85  55                   push ebp
// 00574f86  8b2dace98900         mov ebp, dword ptr [0x89e9ac]
// 00574f8c  56                   push esi
// 00574f8d  8bf1                 mov esi, ecx
// 00574f8f  57                   push edi
// 00574f90  c70300000000         mov dword ptr [ebx], 0
// 00574f96  85f6                 test esi, esi
// 00574f98  740e                 je 0x574fa8
// 00574f9a  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00574f9e  39460c               cmp dword ptr [esi + 0xc], eax
// 00574fa1  7705                 ja 0x574fa8
// 00574fa3  3b4610               cmp eax, dword ptr [esi + 0x10]
// 00574fa6  7606                 jbe 0x574fae
// 00574fa8  ffd5                 call ebp
// 00574faa  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00574fae  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00574fb2  8b0e                 mov ecx, dword ptr [esi]
// 00574fb4  890b                 mov dword ptr [ebx], ecx
// 00574fb6  894304               mov dword ptr [ebx + 4], eax
// 00574fb9  397e0c               cmp dword ptr [esi + 0xc], edi
// 00574fbc  7705                 ja 0x574fc3
// 00574fbe  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 00574fc1  7606                 jbe 0x574fc9
// 00574fc3  ffd5                 call ebp
// 00574fc5  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00574fc9  8b03                 mov eax, dword ptr [ebx]
// 00574fcb  8b0e                 mov ecx, dword ptr [esi]
// 00574fcd  85c0                 test eax, eax
// 00574fcf  7404                 je 0x574fd5
// 00574fd1  3bc1                 cmp eax, ecx
// 00574fd3  7402                 je 0x574fd7
// 00574fd5  ffd5                 call ebp
// 00574fd7  8b5304               mov edx, dword ptr [ebx + 4]
// 00574fda  3bd7                 cmp edx, edi
// 00574fdc  7426                 je 0x575004
// 00574fde  8b4610               mov eax, dword ptr [esi + 0x10]
// 00574fe1  2bc7                 sub eax, edi
// 00574fe3  c1f803               sar eax, 3
// 00574fe6  8d0cc500000000       lea ecx, [eax*8]
// 00574fed  8d2c11               lea ebp, [ecx + edx]
// 00574ff0  85c0                 test eax, eax
// 00574ff2  7e0d                 jle 0x575001
// 00574ff4  51                   push ecx
// 00574ff5  57                   push edi
// 00574ff6  51                   push ecx
// 00574ff7  52                   push edx
// 00574ff8  ff155ce98900         call dword ptr [0x89e95c]
// 00574ffe  83c410               add esp, 0x10
// 00575001  896e10               mov dword ptr [esi + 0x10], ebp
// 00575004  5f                   pop edi
// 00575005  5e                   pop esi
// 00575006  5d                   pop ebp
// 00575007  8bc3                 mov eax, ebx
// 00575009  5b                   pop ebx
// 0057500a  c21400               ret 0x14
// standard library vector<double> (function ?erase@?$vector@NV?$allocator@N@std@@@std@@QAE?AV?$_Vector_iterator@NV?$allocator@N@std@@@2@V?$_Vector_const_iterator@NV?$allocator@N@std@@@2@0@Z)

// stl: vector<double>
typedef double E;
#include <vector>
template class std::vector<E>;
