// from server: 100% by auto
// roc 2010-06 00559120  unit: G3D::BinaryInput  size: 131 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00559120
//
// 00559120  53                   push ebx
// 00559121  8b5c2408             mov ebx, dword ptr [esp + 8]
// 00559125  55                   push ebp
// 00559126  8b2d0ca99e00         mov ebp, dword ptr [0x9ea90c]
// 0055912c  56                   push esi
// 0055912d  8bf1                 mov esi, ecx
// 0055912f  57                   push edi
// 00559130  c70300000000         mov dword ptr [ebx], 0
// 00559136  85f6                 test esi, esi
// 00559138  740e                 je 0x559148
// 0055913a  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0055913e  39460c               cmp dword ptr [esi + 0xc], eax
// 00559141  7705                 ja 0x559148
// 00559143  3b4610               cmp eax, dword ptr [esi + 0x10]
// 00559146  7606                 jbe 0x55914e
// 00559148  ffd5                 call ebp
// 0055914a  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0055914e  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00559152  8b0e                 mov ecx, dword ptr [esi]
// 00559154  890b                 mov dword ptr [ebx], ecx
// 00559156  894304               mov dword ptr [ebx + 4], eax
// 00559159  397e0c               cmp dword ptr [esi + 0xc], edi
// 0055915c  7705                 ja 0x559163
// 0055915e  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 00559161  7606                 jbe 0x559169
// 00559163  ffd5                 call ebp
// 00559165  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00559169  8b03                 mov eax, dword ptr [ebx]
// 0055916b  8b0e                 mov ecx, dword ptr [esi]
// 0055916d  85c0                 test eax, eax
// 0055916f  7404                 je 0x559175
// 00559171  3bc1                 cmp eax, ecx
// 00559173  7402                 je 0x559177
// 00559175  ffd5                 call ebp
// 00559177  8b4b04               mov ecx, dword ptr [ebx + 4]
// 0055917a  3bcf                 cmp ecx, edi
// 0055917c  741c                 je 0x55919a
// 0055917e  8b4610               mov eax, dword ptr [esi + 0x10]
// 00559181  2bc7                 sub eax, edi
// 00559183  8d2c08               lea ebp, [eax + ecx]
// 00559186  85c0                 test eax, eax
// 00559188  7e0d                 jle 0x559197
// 0055918a  50                   push eax
// 0055918b  57                   push edi
// 0055918c  50                   push eax
// 0055918d  51                   push ecx
// 0055918e  ff1580a89e00         call dword ptr [0x9ea880]
// 00559194  83c410               add esp, 0x10
// 00559197  896e10               mov dword ptr [esi + 0x10], ebp
// 0055919a  5f                   pop edi
// 0055919b  5e                   pop esi
// 0055919c  5d                   pop ebp
// 0055919d  8bc3                 mov eax, ebx
// 0055919f  5b                   pop ebx
// 005591a0  c21400               ret 0x14
// standard library vector<char> (function ?erase@?$vector@DV?$allocator@D@std@@@std@@QAE?AV?$_Vector_iterator@DV?$allocator@D@std@@@2@V?$_Vector_const_iterator@DV?$allocator@D@std@@@2@0@Z)

// stl: vector<char>
typedef char E;
#include <vector>
template class std::vector<E>;
