// from server: 100% by auto
// roc 2010-06 005591b0  unit: G3D::BinaryInput  size: 141 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005591b0
//
// 005591b0  53                   push ebx
// 005591b1  8b5c2408             mov ebx, dword ptr [esp + 8]
// 005591b5  55                   push ebp
// 005591b6  8b2d0ca99e00         mov ebp, dword ptr [0x9ea90c]
// 005591bc  56                   push esi
// 005591bd  8bf1                 mov esi, ecx
// 005591bf  57                   push edi
// 005591c0  c70300000000         mov dword ptr [ebx], 0
// 005591c6  85f6                 test esi, esi
// 005591c8  740e                 je 0x5591d8
// 005591ca  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 005591ce  39460c               cmp dword ptr [esi + 0xc], eax
// 005591d1  7705                 ja 0x5591d8
// 005591d3  3b4610               cmp eax, dword ptr [esi + 0x10]
// 005591d6  7606                 jbe 0x5591de
// 005591d8  ffd5                 call ebp
// 005591da  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 005591de  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 005591e2  8b0e                 mov ecx, dword ptr [esi]
// 005591e4  890b                 mov dword ptr [ebx], ecx
// 005591e6  894304               mov dword ptr [ebx + 4], eax
// 005591e9  397e0c               cmp dword ptr [esi + 0xc], edi
// 005591ec  7705                 ja 0x5591f3
// 005591ee  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 005591f1  7606                 jbe 0x5591f9
// 005591f3  ffd5                 call ebp
// 005591f5  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 005591f9  8b03                 mov eax, dword ptr [ebx]
// 005591fb  8b0e                 mov ecx, dword ptr [esi]
// 005591fd  85c0                 test eax, eax
// 005591ff  7404                 je 0x559205
// 00559201  3bc1                 cmp eax, ecx
// 00559203  7402                 je 0x559207
// 00559205  ffd5                 call ebp
// 00559207  8b5304               mov edx, dword ptr [ebx + 4]
// 0055920a  3bd7                 cmp edx, edi
// 0055920c  7426                 je 0x559234
// 0055920e  8b4610               mov eax, dword ptr [esi + 0x10]
// 00559211  2bc7                 sub eax, edi
// 00559213  c1f803               sar eax, 3
// 00559216  8d0cc500000000       lea ecx, [eax*8]
// 0055921d  8d2c11               lea ebp, [ecx + edx]
// 00559220  85c0                 test eax, eax
// 00559222  7e0d                 jle 0x559231
// 00559224  51                   push ecx
// 00559225  57                   push edi
// 00559226  51                   push ecx
// 00559227  52                   push edx
// 00559228  ff1580a89e00         call dword ptr [0x9ea880]
// 0055922e  83c410               add esp, 0x10
// 00559231  896e10               mov dword ptr [esi + 0x10], ebp
// 00559234  5f                   pop edi
// 00559235  5e                   pop esi
// 00559236  5d                   pop ebp
// 00559237  8bc3                 mov eax, ebx
// 00559239  5b                   pop ebx
// 0055923a  c21400               ret 0x14
// standard library vector<double> (function ?erase@?$vector@NV?$allocator@N@std@@@std@@QAE?AV?$_Vector_iterator@NV?$allocator@N@std@@@2@V?$_Vector_const_iterator@NV?$allocator@N@std@@@2@0@Z)

// stl: vector<double>
typedef double E;
#include <vector>
template class std::vector<E>;
