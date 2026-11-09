// from server: 100% by auto
// roc 2010-06 005256f0  unit: RBX::Mesh::Level  size: 141 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005256f0
//
// 005256f0  53                   push ebx
// 005256f1  8b5c2408             mov ebx, dword ptr [esp + 8]
// 005256f5  55                   push ebp
// 005256f6  8b2d0ca99e00         mov ebp, dword ptr [0x9ea90c]
// 005256fc  56                   push esi
// 005256fd  8bf1                 mov esi, ecx
// 005256ff  57                   push edi
// 00525700  c70300000000         mov dword ptr [ebx], 0
// 00525706  85f6                 test esi, esi
// 00525708  740e                 je 0x525718
// 0052570a  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0052570e  39460c               cmp dword ptr [esi + 0xc], eax
// 00525711  7705                 ja 0x525718
// 00525713  3b4610               cmp eax, dword ptr [esi + 0x10]
// 00525716  7606                 jbe 0x52571e
// 00525718  ffd5                 call ebp
// 0052571a  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0052571e  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00525722  8b0e                 mov ecx, dword ptr [esi]
// 00525724  890b                 mov dword ptr [ebx], ecx
// 00525726  894304               mov dword ptr [ebx + 4], eax
// 00525729  397e0c               cmp dword ptr [esi + 0xc], edi
// 0052572c  7705                 ja 0x525733
// 0052572e  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 00525731  7606                 jbe 0x525739
// 00525733  ffd5                 call ebp
// 00525735  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00525739  8b03                 mov eax, dword ptr [ebx]
// 0052573b  8b0e                 mov ecx, dword ptr [esi]
// 0052573d  85c0                 test eax, eax
// 0052573f  7404                 je 0x525745
// 00525741  3bc1                 cmp eax, ecx
// 00525743  7402                 je 0x525747
// 00525745  ffd5                 call ebp
// 00525747  8b5304               mov edx, dword ptr [ebx + 4]
// 0052574a  3bd7                 cmp edx, edi
// 0052574c  7426                 je 0x525774
// 0052574e  8b4610               mov eax, dword ptr [esi + 0x10]
// 00525751  2bc7                 sub eax, edi
// 00525753  c1f802               sar eax, 2
// 00525756  8d0c8500000000       lea ecx, [eax*4]
// 0052575d  8d2c11               lea ebp, [ecx + edx]
// 00525760  85c0                 test eax, eax
// 00525762  7e0d                 jle 0x525771
// 00525764  51                   push ecx
// 00525765  57                   push edi
// 00525766  51                   push ecx
// 00525767  52                   push edx
// 00525768  ff1580a89e00         call dword ptr [0x9ea880]
// 0052576e  83c410               add esp, 0x10
// 00525771  896e10               mov dword ptr [esi + 0x10], ebp
// 00525774  5f                   pop edi
// 00525775  5e                   pop esi
// 00525776  5d                   pop ebp
// 00525777  8bc3                 mov eax, ebx
// 00525779  5b                   pop ebx
// 0052577a  c21400               ret 0x14
// standard library vector<ptr> (function ?erase@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE?AV?$_Vector_iterator@PAUT@@V?$allocator@PAUT@@@std@@@2@V?$_Vector_const_iterator@PAUT@@V?$allocator@PAUT@@@std@@@2@0@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
