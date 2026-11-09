// from server: 100% by auto
// roc 2012-06 00591440  unit: RBX::Network::VServerReplicator::?$Setter  size: 116 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00591440
//
// 00591440  56                   push esi
// 00591441  8bf1                 mov esi, ecx
// 00591443  8b461c               mov eax, dword ptr [esi + 0x1c]
// 00591446  40                   inc eax
// 00591447  394614               cmp dword ptr [esi + 0x14], eax
// 0059144a  7707                 ja 0x591453
// 0059144c  6a01                 push 1
// 0059144e  e83dfbffff           call 0x590f90
// 00591453  8b4614               mov eax, dword ptr [esi + 0x14]
// 00591456  57                   push edi
// 00591457  8b7e18               mov edi, dword ptr [esi + 0x18]
// 0059145a  037e1c               add edi, dword ptr [esi + 0x1c]
// 0059145d  3bc7                 cmp eax, edi
// 0059145f  7702                 ja 0x591463
// 00591461  2bf8                 sub edi, eax
// 00591463  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 00591466  833cb900             cmp dword ptr [ecx + edi*4], 0
// 0059146a  7510                 jne 0x59147c
// 0059146c  6a18                 push 0x18
// 0059146e  e8a70c3f00           call 0x98211a
// 00591473  8b5610               mov edx, dword ptr [esi + 0x10]
// 00591476  83c404               add esp, 4
// 00591479  8904ba               mov dword ptr [edx + edi*4], eax
// 0059147c  8b4610               mov eax, dword ptr [esi + 0x10]
// 0059147f  8b04b8               mov eax, dword ptr [eax + edi*4]
// 00591482  5f                   pop edi
// 00591483  85c0                 test eax, eax
// 00591485  7426                 je 0x5914ad
// 00591487  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0059148b  8b11                 mov edx, dword ptr [ecx]
// 0059148d  8910                 mov dword ptr [eax], edx
// 0059148f  8b5104               mov edx, dword ptr [ecx + 4]
// 00591492  895004               mov dword ptr [eax + 4], edx
// 00591495  8b5108               mov edx, dword ptr [ecx + 8]
// 00591498  895008               mov dword ptr [eax + 8], edx
// 0059149b  8b510c               mov edx, dword ptr [ecx + 0xc]
// 0059149e  89500c               mov dword ptr [eax + 0xc], edx
// 005914a1  8b5110               mov edx, dword ptr [ecx + 0x10]
// 005914a4  895010               mov dword ptr [eax + 0x10], edx
// 005914a7  8b4914               mov ecx, dword ptr [ecx + 0x14]
// 005914aa  894814               mov dword ptr [eax + 0x14], ecx
// 005914ad  ff461c               inc dword ptr [esi + 0x1c]
// 005914b0  5e                   pop esi
// 005914b1  c20400               ret 4
// standard library deque<pod24> (function ?push_back@?$deque@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: deque<pod24>
struct E { int v[6]; };
#include <deque>
template class std::deque<E>;
