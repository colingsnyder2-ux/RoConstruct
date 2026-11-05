// from server: 100% by auto
// roc 2012-06 00507410  unit: Ogre::RbxSceneUpdater  size: 116 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00507410
//
// 00507410  56                   push esi
// 00507411  8bf1                 mov esi, ecx
// 00507413  8b461c               mov eax, dword ptr [esi + 0x1c]
// 00507416  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00507419  03c8                 add ecx, eax
// 0050741b  f6c103               test cl, 3
// 0050741e  7514                 jne 0x507434
// 00507420  83c004               add eax, 4
// 00507423  c1e802               shr eax, 2
// 00507426  394614               cmp dword ptr [esi + 0x14], eax
// 00507429  7709                 ja 0x507434
// 0050742b  6a01                 push 1
// 0050742d  8bce                 mov ecx, esi
// 0050742f  e8ccfdffff           call 0x507200
// 00507434  8b4614               mov eax, dword ptr [esi + 0x14]
// 00507437  53                   push ebx
// 00507438  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 0050743b  035e1c               add ebx, dword ptr [esi + 0x1c]
// 0050743e  57                   push edi
// 0050743f  8bfb                 mov edi, ebx
// 00507441  c1ef02               shr edi, 2
// 00507444  3bc7                 cmp eax, edi
// 00507446  7702                 ja 0x50744a
// 00507448  2bf8                 sub edi, eax
// 0050744a  8b5610               mov edx, dword ptr [esi + 0x10]
// 0050744d  833cba00             cmp dword ptr [edx + edi*4], 0
// 00507451  7510                 jne 0x507463
// 00507453  6a10                 push 0x10
// 00507455  e8c0ac4700           call 0x98211a
// 0050745a  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 0050745d  83c404               add esp, 4
// 00507460  8904b9               mov dword ptr [ecx + edi*4], eax
// 00507463  8b5610               mov edx, dword ptr [esi + 0x10]
// 00507466  8b04ba               mov eax, dword ptr [edx + edi*4]
// 00507469  83e303               and ebx, 3
// 0050746c  8d0498               lea eax, [eax + ebx*4]
// 0050746f  5f                   pop edi
// 00507470  5b                   pop ebx
// 00507471  85c0                 test eax, eax
// 00507473  7408                 je 0x50747d
// 00507475  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00507479  8b11                 mov edx, dword ptr [ecx]
// 0050747b  8910                 mov dword ptr [eax], edx
// 0050747d  ff461c               inc dword ptr [esi + 0x1c]
// 00507480  5e                   pop esi
// 00507481  c20400               ret 4
// standard library deque<ptr> (function ?push_back@?$deque@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXABQAUT@@@Z)

// stl: deque<ptr>
struct T; typedef T* E;
#include <deque>
template class std::deque<E>;
