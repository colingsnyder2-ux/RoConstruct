// from server: 100% by auto
// roc 2010-06 00966c70  unit: Ogre::RbxSceneUpdater  size: 105 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00966c70
//
// 00966c70  56                   push esi
// 00966c71  8b742410             mov esi, dword ptr [esp + 0x10]
// 00966c75  3bce                 cmp ecx, esi
// 00966c77  740f                 je 0x966c88
// 00966c79  57                   push edi
// 00966c7a  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 00966c7e  57                   push edi
// 00966c7f  e8cca4ffff           call 0x961150
// 00966c84  297e18               sub dword ptr [esi + 0x18], edi
// 00966c87  5f                   pop edi
// 00966c88  8b442418             mov eax, dword ptr [esp + 0x18]
// 00966c8c  8b4804               mov ecx, dword ptr [eax + 4]
// 00966c8f  8b542420             mov edx, dword ptr [esp + 0x20]
// 00966c93  8911                 mov dword ptr [ecx], edx
// 00966c95  8b442420             mov eax, dword ptr [esp + 0x20]
// 00966c99  8b4804               mov ecx, dword ptr [eax + 4]
// 00966c9c  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00966ca0  8911                 mov dword ptr [ecx], edx
// 00966ca2  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00966ca6  8b4804               mov ecx, dword ptr [eax + 4]
// 00966ca9  8b542418             mov edx, dword ptr [esp + 0x18]
// 00966cad  8911                 mov dword ptr [ecx], edx
// 00966caf  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00966cb3  8b542420             mov edx, dword ptr [esp + 0x20]
// 00966cb7  8b5204               mov edx, dword ptr [edx + 4]
// 00966cba  8b4804               mov ecx, dword ptr [eax + 4]
// 00966cbd  895004               mov dword ptr [eax + 4], edx
// 00966cc0  8b442418             mov eax, dword ptr [esp + 0x18]
// 00966cc4  8b5004               mov edx, dword ptr [eax + 4]
// 00966cc7  8b442420             mov eax, dword ptr [esp + 0x20]
// 00966ccb  895004               mov dword ptr [eax + 4], edx
// 00966cce  8b542418             mov edx, dword ptr [esp + 0x18]
// 00966cd2  894a04               mov dword ptr [edx + 4], ecx
// 00966cd5  5e                   pop esi
// 00966cd6  c22400               ret 0x24
// standard library list<ptr> (function ?_Splice@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXV?$_Const_iterator@$00@12@AAV12@00I_N@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
