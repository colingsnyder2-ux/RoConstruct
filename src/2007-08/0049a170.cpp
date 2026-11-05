// from server: 100% by auto
// roc 2007-08 0049a170  unit: RBX::Network::Client  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0049a170
//
// 0049a170  56                   push esi
// 0049a171  8bf1                 mov esi, ecx
// 0049a173  8b4610               mov eax, dword ptr [esi + 0x10]
// 0049a176  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 0049a179  03c8                 add ecx, eax
// 0049a17b  f6c103               test cl, 3
// 0049a17e  7514                 jne 0x49a194
// 0049a180  83c004               add eax, 4
// 0049a183  c1e802               shr eax, 2
// 0049a186  394608               cmp dword ptr [esi + 8], eax
// 0049a189  7709                 ja 0x49a194
// 0049a18b  6a01                 push 1
// 0049a18d  8bce                 mov ecx, esi
// 0049a18f  e8ccfdffff           call 0x499f60
// 0049a194  8b4608               mov eax, dword ptr [esi + 8]
// 0049a197  53                   push ebx
// 0049a198  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 0049a19b  035e10               add ebx, dword ptr [esi + 0x10]
// 0049a19e  57                   push edi
// 0049a19f  8bfb                 mov edi, ebx
// 0049a1a1  c1ef02               shr edi, 2
// 0049a1a4  3bc7                 cmp eax, edi
// 0049a1a6  7702                 ja 0x49a1aa
// 0049a1a8  2bf8                 sub edi, eax
// 0049a1aa  8b5604               mov edx, dword ptr [esi + 4]
// 0049a1ad  833cba00             cmp dword ptr [edx + edi*4], 0
// 0049a1b1  7510                 jne 0x49a1c3
// 0049a1b3  6a10                 push 0x10
// 0049a1b5  e83c5d1900           call 0x62fef6
// 0049a1ba  8b4e04               mov ecx, dword ptr [esi + 4]
// 0049a1bd  83c404               add esp, 4
// 0049a1c0  8904b9               mov dword ptr [ecx + edi*4], eax
// 0049a1c3  8b5604               mov edx, dword ptr [esi + 4]
// 0049a1c6  8b04ba               mov eax, dword ptr [edx + edi*4]
// 0049a1c9  83e303               and ebx, 3
// 0049a1cc  8d0498               lea eax, [eax + ebx*4]
// 0049a1cf  85c0                 test eax, eax
// 0049a1d1  5f                   pop edi
// 0049a1d2  5b                   pop ebx
// 0049a1d3  7408                 je 0x49a1dd
// 0049a1d5  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0049a1d9  8b11                 mov edx, dword ptr [ecx]
// 0049a1db  8910                 mov dword ptr [eax], edx
// 0049a1dd  83461001             add dword ptr [esi + 0x10], 1
// 0049a1e1  5e                   pop esi
// 0049a1e2  c20400               ret 4
// standard library deque<ptr> (function ?push_back@?$deque@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXABQAUT@@@Z)

// stl: deque<ptr>
struct T; typedef T* E;
#include <deque>
template class std::deque<E>;
