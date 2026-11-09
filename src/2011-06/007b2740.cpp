// from server: 100% by auto
// roc 2011-06 007b2740  unit: RBX::SleepStage  size: 116 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 007b2740
//
// 007b2740  56                   push esi
// 007b2741  8bf1                 mov esi, ecx
// 007b2743  8b461c               mov eax, dword ptr [esi + 0x1c]
// 007b2746  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 007b2749  03c8                 add ecx, eax
// 007b274b  f6c103               test cl, 3
// 007b274e  7514                 jne 0x7b2764
// 007b2750  83c004               add eax, 4
// 007b2753  c1e802               shr eax, 2
// 007b2756  394614               cmp dword ptr [esi + 0x14], eax
// 007b2759  7709                 ja 0x7b2764
// 007b275b  6a01                 push 1
// 007b275d  8bce                 mov ecx, esi
// 007b275f  e80cf8ffff           call 0x7b1f70
// 007b2764  8b4614               mov eax, dword ptr [esi + 0x14]
// 007b2767  53                   push ebx
// 007b2768  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 007b276b  035e1c               add ebx, dword ptr [esi + 0x1c]
// 007b276e  57                   push edi
// 007b276f  8bfb                 mov edi, ebx
// 007b2771  c1ef02               shr edi, 2
// 007b2774  3bc7                 cmp eax, edi
// 007b2776  7702                 ja 0x7b277a
// 007b2778  2bf8                 sub edi, eax
// 007b277a  8b5610               mov edx, dword ptr [esi + 0x10]
// 007b277d  833cba00             cmp dword ptr [edx + edi*4], 0
// 007b2781  7510                 jne 0x7b2793
// 007b2783  6a10                 push 0x10
// 007b2785  e8d4780500           call 0x80a05e
// 007b278a  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 007b278d  83c404               add esp, 4
// 007b2790  8904b9               mov dword ptr [ecx + edi*4], eax
// 007b2793  8b5610               mov edx, dword ptr [esi + 0x10]
// 007b2796  8b04ba               mov eax, dword ptr [edx + edi*4]
// 007b2799  83e303               and ebx, 3
// 007b279c  8d0498               lea eax, [eax + ebx*4]
// 007b279f  5f                   pop edi
// 007b27a0  5b                   pop ebx
// 007b27a1  85c0                 test eax, eax
// 007b27a3  7408                 je 0x7b27ad
// 007b27a5  8b4c2408             mov ecx, dword ptr [esp + 8]
// 007b27a9  8b11                 mov edx, dword ptr [ecx]
// 007b27ab  8910                 mov dword ptr [eax], edx
// 007b27ad  ff461c               inc dword ptr [esi + 0x1c]
// 007b27b0  5e                   pop esi
// 007b27b1  c20400               ret 4
// standard library deque<ptr> (function ?push_back@?$deque@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXABQAUT@@@Z)

// stl: deque<ptr>
struct T; typedef T* E;
#include <deque>
template class std::deque<E>;
