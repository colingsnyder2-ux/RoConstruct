// from server: 100% by auto
// roc 2012-06 00579990  unit: RBX::Network::Replicator  size: 104 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00579990
//
// 00579990  56                   push esi
// 00579991  8bf1                 mov esi, ecx
// 00579993  8b461c               mov eax, dword ptr [esi + 0x1c]
// 00579996  40                   inc eax
// 00579997  394614               cmp dword ptr [esi + 0x14], eax
// 0057999a  7707                 ja 0x5799a3
// 0057999c  6a01                 push 1
// 0057999e  e8fdebffff           call 0x5785a0
// 005799a3  8b4614               mov eax, dword ptr [esi + 0x14]
// 005799a6  57                   push edi
// 005799a7  8b7e18               mov edi, dword ptr [esi + 0x18]
// 005799aa  037e1c               add edi, dword ptr [esi + 0x1c]
// 005799ad  3bc7                 cmp eax, edi
// 005799af  7702                 ja 0x5799b3
// 005799b1  2bf8                 sub edi, eax
// 005799b3  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 005799b6  833cb900             cmp dword ptr [ecx + edi*4], 0
// 005799ba  7510                 jne 0x5799cc
// 005799bc  6a10                 push 0x10
// 005799be  e857874000           call 0x98211a
// 005799c3  8b5610               mov edx, dword ptr [esi + 0x10]
// 005799c6  83c404               add esp, 4
// 005799c9  8904ba               mov dword ptr [edx + edi*4], eax
// 005799cc  8b4610               mov eax, dword ptr [esi + 0x10]
// 005799cf  8b04b8               mov eax, dword ptr [eax + edi*4]
// 005799d2  5f                   pop edi
// 005799d3  85c0                 test eax, eax
// 005799d5  741a                 je 0x5799f1
// 005799d7  8b4c2408             mov ecx, dword ptr [esp + 8]
// 005799db  8b11                 mov edx, dword ptr [ecx]
// 005799dd  8910                 mov dword ptr [eax], edx
// 005799df  8b5104               mov edx, dword ptr [ecx + 4]
// 005799e2  895004               mov dword ptr [eax + 4], edx
// 005799e5  8b5108               mov edx, dword ptr [ecx + 8]
// 005799e8  895008               mov dword ptr [eax + 8], edx
// 005799eb  8b490c               mov ecx, dword ptr [ecx + 0xc]
// 005799ee  89480c               mov dword ptr [eax + 0xc], ecx
// 005799f1  ff461c               inc dword ptr [esi + 0x1c]
// 005799f4  5e                   pop esi
// 005799f5  c20400               ret 4
// standard library deque<pod16> (function ?push_back@?$deque@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: deque<pod16>
struct E { int v[4]; };
#include <deque>
template class std::deque<E>;
