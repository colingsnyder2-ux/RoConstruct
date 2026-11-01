// from server: 100% by auto
// roc 2009-12 005f58e0  unit: G3D::BinaryInput  size: 141 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005f58e0
//
// 005f58e0  53                   push ebx
// 005f58e1  8b5c2408             mov ebx, dword ptr [esp + 8]
// 005f58e5  55                   push ebp
// 005f58e6  8b2d60b79800         mov ebp, dword ptr [0x98b760]
// 005f58ec  56                   push esi
// 005f58ed  8bf1                 mov esi, ecx
// 005f58ef  57                   push edi
// 005f58f0  c70300000000         mov dword ptr [ebx], 0
// 005f58f6  85f6                 test esi, esi
// 005f58f8  740e                 je 0x5f5908
// 005f58fa  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 005f58fe  39460c               cmp dword ptr [esi + 0xc], eax
// 005f5901  7705                 ja 0x5f5908
// 005f5903  3b4610               cmp eax, dword ptr [esi + 0x10]
// 005f5906  7606                 jbe 0x5f590e
// 005f5908  ffd5                 call ebp
// 005f590a  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 005f590e  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 005f5912  8b0e                 mov ecx, dword ptr [esi]
// 005f5914  890b                 mov dword ptr [ebx], ecx
// 005f5916  894304               mov dword ptr [ebx + 4], eax
// 005f5919  397e0c               cmp dword ptr [esi + 0xc], edi
// 005f591c  7705                 ja 0x5f5923
// 005f591e  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 005f5921  7606                 jbe 0x5f5929
// 005f5923  ffd5                 call ebp
// 005f5925  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 005f5929  8b03                 mov eax, dword ptr [ebx]
// 005f592b  8b0e                 mov ecx, dword ptr [esi]
// 005f592d  85c0                 test eax, eax
// 005f592f  7404                 je 0x5f5935
// 005f5931  3bc1                 cmp eax, ecx
// 005f5933  7402                 je 0x5f5937
// 005f5935  ffd5                 call ebp
// 005f5937  8b5304               mov edx, dword ptr [ebx + 4]
// 005f593a  3bd7                 cmp edx, edi
// 005f593c  7426                 je 0x5f5964
// 005f593e  8b4610               mov eax, dword ptr [esi + 0x10]
// 005f5941  2bc7                 sub eax, edi
// 005f5943  c1f803               sar eax, 3
// 005f5946  8d0cc500000000       lea ecx, [eax*8]
// 005f594d  8d2c11               lea ebp, [ecx + edx]
// 005f5950  85c0                 test eax, eax
// 005f5952  7e0d                 jle 0x5f5961
// 005f5954  51                   push ecx
// 005f5955  57                   push edi
// 005f5956  51                   push ecx
// 005f5957  52                   push edx
// 005f5958  ff15c0b79800         call dword ptr [0x98b7c0]
// 005f595e  83c410               add esp, 0x10
// 005f5961  896e10               mov dword ptr [esi + 0x10], ebp
// 005f5964  5f                   pop edi
// 005f5965  5e                   pop esi
// 005f5966  5d                   pop ebp
// 005f5967  8bc3                 mov eax, ebx
// 005f5969  5b                   pop ebx
// 005f596a  c21400               ret 0x14
// standard library vector<double> (function ?erase@?$vector@NV?$allocator@N@std@@@std@@QAE?AV?$_Vector_iterator@NV?$allocator@N@std@@@2@V?$_Vector_const_iterator@NV?$allocator@N@std@@@2@0@Z)

// stl: vector<double>
typedef double E;
#include <vector>
template class std::vector<E>;
