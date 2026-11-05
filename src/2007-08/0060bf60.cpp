// from server: 100% by auto
// roc 2007-08 0060bf60  unit: CXTCaptionButtonTheme  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0060bf60
//
// 0060bf60  56                   push esi
// 0060bf61  8bf1                 mov esi, ecx
// 0060bf63  8b4610               mov eax, dword ptr [esi + 0x10]
// 0060bf66  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 0060bf69  03c8                 add ecx, eax
// 0060bf6b  f6c103               test cl, 3
// 0060bf6e  7514                 jne 0x60bf84
// 0060bf70  83c004               add eax, 4
// 0060bf73  c1e802               shr eax, 2
// 0060bf76  394608               cmp dword ptr [esi + 8], eax
// 0060bf79  7709                 ja 0x60bf84
// 0060bf7b  6a01                 push 1
// 0060bf7d  8bce                 mov ecx, esi
// 0060bf7f  e87cfdffff           call 0x60bd00
// 0060bf84  8b4608               mov eax, dword ptr [esi + 8]
// 0060bf87  53                   push ebx
// 0060bf88  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 0060bf8b  035e10               add ebx, dword ptr [esi + 0x10]
// 0060bf8e  57                   push edi
// 0060bf8f  8bfb                 mov edi, ebx
// 0060bf91  c1ef02               shr edi, 2
// 0060bf94  3bc7                 cmp eax, edi
// 0060bf96  7702                 ja 0x60bf9a
// 0060bf98  2bf8                 sub edi, eax
// 0060bf9a  8b5604               mov edx, dword ptr [esi + 4]
// 0060bf9d  833cba00             cmp dword ptr [edx + edi*4], 0
// 0060bfa1  7510                 jne 0x60bfb3
// 0060bfa3  6a10                 push 0x10
// 0060bfa5  e84c3f0200           call 0x62fef6
// 0060bfaa  8b4e04               mov ecx, dword ptr [esi + 4]
// 0060bfad  83c404               add esp, 4
// 0060bfb0  8904b9               mov dword ptr [ecx + edi*4], eax
// 0060bfb3  8b5604               mov edx, dword ptr [esi + 4]
// 0060bfb6  8b04ba               mov eax, dword ptr [edx + edi*4]
// 0060bfb9  83e303               and ebx, 3
// 0060bfbc  8d0498               lea eax, [eax + ebx*4]
// 0060bfbf  85c0                 test eax, eax
// 0060bfc1  5f                   pop edi
// 0060bfc2  5b                   pop ebx
// 0060bfc3  7408                 je 0x60bfcd
// 0060bfc5  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0060bfc9  8b11                 mov edx, dword ptr [ecx]
// 0060bfcb  8910                 mov dword ptr [eax], edx
// 0060bfcd  83461001             add dword ptr [esi + 0x10], 1
// 0060bfd1  5e                   pop esi
// 0060bfd2  c20400               ret 4
// standard library deque<ptr> (function ?push_back@?$deque@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXABQAUT@@@Z)

// stl: deque<ptr>
struct T; typedef T* E;
#include <deque>
template class std::deque<E>;
