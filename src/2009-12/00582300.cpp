// from server: 100% by auto
// roc 2009-12 00582300  unit: Ogre::RbxSceneUpdater  size: 105 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00582300
//
// 00582300  56                   push esi
// 00582301  8b742410             mov esi, dword ptr [esp + 0x10]
// 00582305  3bce                 cmp ecx, esi
// 00582307  740f                 je 0x582318
// 00582309  57                   push edi
// 0058230a  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 0058230e  57                   push edi
// 0058230f  e88c9cffff           call 0x57bfa0
// 00582314  297e18               sub dword ptr [esi + 0x18], edi
// 00582317  5f                   pop edi
// 00582318  8b442418             mov eax, dword ptr [esp + 0x18]
// 0058231c  8b4804               mov ecx, dword ptr [eax + 4]
// 0058231f  8b542420             mov edx, dword ptr [esp + 0x20]
// 00582323  8911                 mov dword ptr [ecx], edx
// 00582325  8b442420             mov eax, dword ptr [esp + 0x20]
// 00582329  8b4804               mov ecx, dword ptr [eax + 4]
// 0058232c  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00582330  8911                 mov dword ptr [ecx], edx
// 00582332  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00582336  8b4804               mov ecx, dword ptr [eax + 4]
// 00582339  8b542418             mov edx, dword ptr [esp + 0x18]
// 0058233d  8911                 mov dword ptr [ecx], edx
// 0058233f  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00582343  8b542420             mov edx, dword ptr [esp + 0x20]
// 00582347  8b5204               mov edx, dword ptr [edx + 4]
// 0058234a  8b4804               mov ecx, dword ptr [eax + 4]
// 0058234d  895004               mov dword ptr [eax + 4], edx
// 00582350  8b442418             mov eax, dword ptr [esp + 0x18]
// 00582354  8b5004               mov edx, dword ptr [eax + 4]
// 00582357  8b442420             mov eax, dword ptr [esp + 0x20]
// 0058235b  895004               mov dword ptr [eax + 4], edx
// 0058235e  8b542418             mov edx, dword ptr [esp + 0x18]
// 00582362  894a04               mov dword ptr [edx + 4], ecx
// 00582365  5e                   pop esi
// 00582366  c22400               ret 0x24
// standard library list<ptr> (function ?_Splice@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXV?$_Const_iterator@$00@12@AAV12@00I_N@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
