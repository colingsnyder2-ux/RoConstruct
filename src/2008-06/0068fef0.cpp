// from server: 100% by auto
// roc 2008-06 0068fef0  unit: Ogre::RbxSceneManagerFactory  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0068fef0
//
// 0068fef0  53                   push ebx
// 0068fef1  56                   push esi
// 0068fef2  8bf1                 mov esi, ecx
// 0068fef4  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 0068fef7  57                   push edi
// 0068fef8  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0068fefc  c70700000000         mov dword ptr [edi], 0
// 0068ff02  3b5e10               cmp ebx, dword ptr [esi + 0x10]
// 0068ff05  7606                 jbe 0x68ff0d
// 0068ff07  ff1590288000         call dword ptr [0x802890]
// 0068ff0d  8b06                 mov eax, dword ptr [esi]
// 0068ff0f  8907                 mov dword ptr [edi], eax
// 0068ff11  895f04               mov dword ptr [edi + 4], ebx
// 0068ff14  8bc7                 mov eax, edi
// 0068ff16  5f                   pop edi
// 0068ff17  5e                   pop esi
// 0068ff18  5b                   pop ebx
// 0068ff19  c20400               ret 4
// standard library vector<ptr> (function ?begin@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE?AV?$_Vector_iterator@PAUT@@V?$allocator@PAUT@@@std@@@2@XZ)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
