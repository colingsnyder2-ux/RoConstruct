// from server: 100% by auto
// roc 2008-06 0068ff20  unit: Ogre::RbxSceneManagerFactory  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0068ff20
//
// 0068ff20  53                   push ebx
// 0068ff21  56                   push esi
// 0068ff22  8bf1                 mov esi, ecx
// 0068ff24  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 0068ff27  57                   push edi
// 0068ff28  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0068ff2c  c70700000000         mov dword ptr [edi], 0
// 0068ff32  395e0c               cmp dword ptr [esi + 0xc], ebx
// 0068ff35  7606                 jbe 0x68ff3d
// 0068ff37  ff1590288000         call dword ptr [0x802890]
// 0068ff3d  8b06                 mov eax, dword ptr [esi]
// 0068ff3f  8907                 mov dword ptr [edi], eax
// 0068ff41  895f04               mov dword ptr [edi + 4], ebx
// 0068ff44  8bc7                 mov eax, edi
// 0068ff46  5f                   pop edi
// 0068ff47  5e                   pop esi
// 0068ff48  5b                   pop ebx
// 0068ff49  c20400               ret 4
// standard library vector<ptr> (function ?end@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE?AV?$_Vector_iterator@PAUT@@V?$allocator@PAUT@@@std@@@2@XZ)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
