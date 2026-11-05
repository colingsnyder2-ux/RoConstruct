// from server: 100% by auto
// roc 2009-12 004ab510  unit: Ogre::RbxSceneUpdater  size: 105 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004ab510
//
// 004ab510  56                   push esi
// 004ab511  8b742410             mov esi, dword ptr [esp + 0x10]
// 004ab515  3bce                 cmp ecx, esi
// 004ab517  740f                 je 0x4ab528
// 004ab519  57                   push edi
// 004ab51a  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 004ab51e  57                   push edi
// 004ab51f  e84c6e2700           call 0x722370
// 004ab524  297e18               sub dword ptr [esi + 0x18], edi
// 004ab527  5f                   pop edi
// 004ab528  8b442418             mov eax, dword ptr [esp + 0x18]
// 004ab52c  8b4804               mov ecx, dword ptr [eax + 4]
// 004ab52f  8b542420             mov edx, dword ptr [esp + 0x20]
// 004ab533  8911                 mov dword ptr [ecx], edx
// 004ab535  8b442420             mov eax, dword ptr [esp + 0x20]
// 004ab539  8b4804               mov ecx, dword ptr [eax + 4]
// 004ab53c  8b54240c             mov edx, dword ptr [esp + 0xc]
// 004ab540  8911                 mov dword ptr [ecx], edx
// 004ab542  8b44240c             mov eax, dword ptr [esp + 0xc]
// 004ab546  8b4804               mov ecx, dword ptr [eax + 4]
// 004ab549  8b542418             mov edx, dword ptr [esp + 0x18]
// 004ab54d  8911                 mov dword ptr [ecx], edx
// 004ab54f  8b44240c             mov eax, dword ptr [esp + 0xc]
// 004ab553  8b542420             mov edx, dword ptr [esp + 0x20]
// 004ab557  8b5204               mov edx, dword ptr [edx + 4]
// 004ab55a  8b4804               mov ecx, dword ptr [eax + 4]
// 004ab55d  895004               mov dword ptr [eax + 4], edx
// 004ab560  8b442418             mov eax, dword ptr [esp + 0x18]
// 004ab564  8b5004               mov edx, dword ptr [eax + 4]
// 004ab567  8b442420             mov eax, dword ptr [esp + 0x20]
// 004ab56b  895004               mov dword ptr [eax + 4], edx
// 004ab56e  8b542418             mov edx, dword ptr [esp + 0x18]
// 004ab572  894a04               mov dword ptr [edx + 4], ecx
// 004ab575  5e                   pop esi
// 004ab576  c22400               ret 0x24
// standard library list<ptr> (function ?_Splice@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXV?$_Const_iterator@$00@12@AAV12@00I_N@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
