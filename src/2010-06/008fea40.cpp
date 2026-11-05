// from server: 100% by auto
// roc 2010-06 008fea40  unit: Ogre::RbxSceneUpdater  size: 116 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008fea40
//
// 008fea40  56                   push esi
// 008fea41  8bf1                 mov esi, ecx
// 008fea43  8b461c               mov eax, dword ptr [esi + 0x1c]
// 008fea46  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 008fea49  03c8                 add ecx, eax
// 008fea4b  f6c103               test cl, 3
// 008fea4e  7514                 jne 0x8fea64
// 008fea50  83c004               add eax, 4
// 008fea53  c1e802               shr eax, 2
// 008fea56  394614               cmp dword ptr [esi + 0x14], eax
// 008fea59  7709                 ja 0x8fea64
// 008fea5b  6a01                 push 1
// 008fea5d  8bce                 mov ecx, esi
// 008fea5f  e88c29b3ff           call 0x4313f0
// 008fea64  8b4614               mov eax, dword ptr [esi + 0x14]
// 008fea67  53                   push ebx
// 008fea68  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 008fea6b  035e1c               add ebx, dword ptr [esi + 0x1c]
// 008fea6e  57                   push edi
// 008fea6f  8bfb                 mov edi, ebx
// 008fea71  c1ef02               shr edi, 2
// 008fea74  3bc7                 cmp eax, edi
// 008fea76  7702                 ja 0x8fea7a
// 008fea78  2bf8                 sub edi, eax
// 008fea7a  8b5610               mov edx, dword ptr [esi + 0x10]
// 008fea7d  833cba00             cmp dword ptr [edx + edi*4], 0
// 008fea81  7510                 jne 0x8fea93
// 008fea83  6a10                 push 0x10
// 008fea85  e8168feaff           call 0x7a79a0
// 008fea8a  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 008fea8d  83c404               add esp, 4
// 008fea90  8904b9               mov dword ptr [ecx + edi*4], eax
// 008fea93  8b5610               mov edx, dword ptr [esi + 0x10]
// 008fea96  8b04ba               mov eax, dword ptr [edx + edi*4]
// 008fea99  83e303               and ebx, 3
// 008fea9c  8d0498               lea eax, [eax + ebx*4]
// 008fea9f  5f                   pop edi
// 008feaa0  5b                   pop ebx
// 008feaa1  85c0                 test eax, eax
// 008feaa3  7408                 je 0x8feaad
// 008feaa5  8b4c2408             mov ecx, dword ptr [esp + 8]
// 008feaa9  8b11                 mov edx, dword ptr [ecx]
// 008feaab  8910                 mov dword ptr [eax], edx
// 008feaad  ff461c               inc dword ptr [esi + 0x1c]
// 008feab0  5e                   pop esi
// 008feab1  c20400               ret 4
// standard library deque<ptr> (function ?push_back@?$deque@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXABQAUT@@@Z)

// stl: deque<ptr>
struct T; typedef T* E;
#include <deque>
template class std::deque<E>;
