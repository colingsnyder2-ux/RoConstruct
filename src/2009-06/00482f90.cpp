// from server: 100% by auto
// roc 2009-06 00482f90  unit: Ogre::RbxSpatialHashedSceneNode::?1??_findVisibleObjects::NodeVisiter  size: 146 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00482f90
//
// 00482f90  53                   push ebx
// 00482f91  8b5c2408             mov ebx, dword ptr [esp + 8]
// 00482f95  55                   push ebp
// 00482f96  8b2dace98900         mov ebp, dword ptr [0x89e9ac]
// 00482f9c  56                   push esi
// 00482f9d  57                   push edi
// 00482f9e  8bf9                 mov edi, ecx
// 00482fa0  c70300000000         mov dword ptr [ebx], 0
// 00482fa6  85ff                 test edi, edi
// 00482fa8  740e                 je 0x482fb8
// 00482faa  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00482fae  39470c               cmp dword ptr [edi + 0xc], eax
// 00482fb1  7705                 ja 0x482fb8
// 00482fb3  3b4710               cmp eax, dword ptr [edi + 0x10]
// 00482fb6  7606                 jbe 0x482fbe
// 00482fb8  ffd5                 call ebp
// 00482fba  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00482fbe  8b742424             mov esi, dword ptr [esp + 0x24]
// 00482fc2  8b0f                 mov ecx, dword ptr [edi]
// 00482fc4  890b                 mov dword ptr [ebx], ecx
// 00482fc6  894304               mov dword ptr [ebx + 4], eax
// 00482fc9  39770c               cmp dword ptr [edi + 0xc], esi
// 00482fcc  7705                 ja 0x482fd3
// 00482fce  3b7710               cmp esi, dword ptr [edi + 0x10]
// 00482fd1  7606                 jbe 0x482fd9
// 00482fd3  ffd5                 call ebp
// 00482fd5  8b742424             mov esi, dword ptr [esp + 0x24]
// 00482fd9  8b03                 mov eax, dword ptr [ebx]
// 00482fdb  8b0f                 mov ecx, dword ptr [edi]
// 00482fdd  85c0                 test eax, eax
// 00482fdf  7404                 je 0x482fe5
// 00482fe1  3bc1                 cmp eax, ecx
// 00482fe3  7402                 je 0x482fe7
// 00482fe5  ffd5                 call ebp
// 00482fe7  8b5304               mov edx, dword ptr [ebx + 4]
// 00482fea  3bd6                 cmp edx, esi
// 00482fec  742b                 je 0x483019
// 00482fee  8b4f10               mov ecx, dword ptr [edi + 0x10]
// 00482ff1  8bc1                 mov eax, ecx
// 00482ff3  2bc6                 sub eax, esi
// 00482ff5  c1f803               sar eax, 3
// 00482ff8  8d2cc2               lea ebp, [edx + eax*8]
// 00482ffb  8bc6                 mov eax, esi
// 00482ffd  3bf1                 cmp esi, ecx
// 00482fff  7415                 je 0x483016
// 00483001  2bd6                 sub edx, esi
// 00483003  8b30                 mov esi, dword ptr [eax]
// 00483005  893402               mov dword ptr [edx + eax], esi
// 00483008  8b7004               mov esi, dword ptr [eax + 4]
// 0048300b  89740204             mov dword ptr [edx + eax + 4], esi
// 0048300f  83c008               add eax, 8
// 00483012  3bc1                 cmp eax, ecx
// 00483014  75ed                 jne 0x483003
// 00483016  896f10               mov dword ptr [edi + 0x10], ebp
// 00483019  5f                   pop edi
// 0048301a  5e                   pop esi
// 0048301b  5d                   pop ebp
// 0048301c  8bc3                 mov eax, ebx
// 0048301e  5b                   pop ebx
// 0048301f  c21400               ret 0x14
// standard library vector<pod8> (function ?erase@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE?AV?$_Vector_iterator@UE@@V?$allocator@UE@@@std@@@2@V?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@0@Z)

// stl: vector<pod8>
struct E { int v[2]; };
#include <vector>
template class std::vector<E>;
