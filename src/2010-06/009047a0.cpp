// from server: 100% by auto
// roc 2010-06 009047a0  unit: Ogre::RbxSpatialHashedSceneNode::?3??_findVisibleObjects::NodeVisiter  size: 94 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 009047a0
//
// 009047a0  56                   push esi
// 009047a1  8bf1                 mov esi, ecx
// 009047a3  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 009047a7  8b4610               mov eax, dword ptr [esi + 0x10]
// 009047aa  8d5104               lea edx, [ecx + 4]
// 009047ad  2bc2                 sub eax, edx
// 009047af  c1f802               sar eax, 2
// 009047b2  57                   push edi
// 009047b3  85c0                 test eax, eax
// 009047b5  7e15                 jle 0x9047cc
// 009047b7  03c0                 add eax, eax
// 009047b9  03c0                 add eax, eax
// 009047bb  50                   push eax
// 009047bc  52                   push edx
// 009047bd  50                   push eax
// 009047be  51                   push ecx
// 009047bf  ff1580a89e00         call dword ptr [0x9ea880]
// 009047c5  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 009047c9  83c410               add esp, 0x10
// 009047cc  834610fc             add dword ptr [esi + 0x10], -4
// 009047d0  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 009047d4  8b4610               mov eax, dword ptr [esi + 0x10]
// 009047d7  c70700000000         mov dword ptr [edi], 0
// 009047dd  394e0c               cmp dword ptr [esi + 0xc], ecx
// 009047e0  7704                 ja 0x9047e6
// 009047e2  3bc8                 cmp ecx, eax
// 009047e4  760a                 jbe 0x9047f0
// 009047e6  ff150ca99e00         call dword ptr [0x9ea90c]
// 009047ec  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 009047f0  8b06                 mov eax, dword ptr [esi]
// 009047f2  8907                 mov dword ptr [edi], eax
// 009047f4  894f04               mov dword ptr [edi + 4], ecx
// 009047f7  8bc7                 mov eax, edi
// 009047f9  5f                   pop edi
// 009047fa  5e                   pop esi
// 009047fb  c20c00               ret 0xc
// standard library vector<ptr> (function ?erase@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE?AV?$_Vector_iterator@PAUT@@V?$allocator@PAUT@@@std@@@2@V?$_Vector_const_iterator@PAUT@@V?$allocator@PAUT@@@std@@@2@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
