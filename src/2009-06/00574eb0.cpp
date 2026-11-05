// from server: 100% by auto
// roc 2009-06 00574eb0  unit: G3D::BinaryInput  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00574eb0
//
// 00574eb0  53                   push ebx
// 00574eb1  8b5c2408             mov ebx, dword ptr [esp + 8]
// 00574eb5  56                   push esi
// 00574eb6  57                   push edi
// 00574eb7  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 00574ebb  8bf1                 mov esi, ecx
// 00574ebd  c70600000000         mov dword ptr [esi], 0
// 00574ec3  85ff                 test edi, edi
// 00574ec5  740a                 je 0x574ed1
// 00574ec7  395f0c               cmp dword ptr [edi + 0xc], ebx
// 00574eca  7705                 ja 0x574ed1
// 00574ecc  3b5f10               cmp ebx, dword ptr [edi + 0x10]
// 00574ecf  7606                 jbe 0x574ed7
// 00574ed1  ff15ace98900         call dword ptr [0x89e9ac]
// 00574ed7  8b07                 mov eax, dword ptr [edi]
// 00574ed9  8906                 mov dword ptr [esi], eax
// 00574edb  5f                   pop edi
// 00574edc  895e04               mov dword ptr [esi + 4], ebx
// 00574edf  8bc6                 mov eax, esi
// 00574ee1  5e                   pop esi
// 00574ee2  5b                   pop ebx
// 00574ee3  c20800               ret 8
// standard library vector<ptr> (function ??0?$_Vector_const_iterator@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE@PAPAUT@@PBV_Container_base_aux@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
