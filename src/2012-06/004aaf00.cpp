// from server: 100% by auto
// roc 2012-06 004aaf00  unit: DxUserInput  size: 98 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004aaf00
//
// 004aaf00  56                   push esi
// 004aaf01  8bf1                 mov esi, ecx
// 004aaf03  8b461c               mov eax, dword ptr [esi + 0x1c]
// 004aaf06  40                   inc eax
// 004aaf07  57                   push edi
// 004aaf08  394614               cmp dword ptr [esi + 0x14], eax
// 004aaf0b  7707                 ja 0x4aaf14
// 004aaf0d  6a01                 push 1
// 004aaf0f  e8cc56feff           call 0x4905e0
// 004aaf14  8b7e18               mov edi, dword ptr [esi + 0x18]
// 004aaf17  037e1c               add edi, dword ptr [esi + 0x1c]
// 004aaf1a  8b4614               mov eax, dword ptr [esi + 0x14]
// 004aaf1d  3bc7                 cmp eax, edi
// 004aaf1f  7702                 ja 0x4aaf23
// 004aaf21  2bf8                 sub edi, eax
// 004aaf23  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 004aaf26  833cb900             cmp dword ptr [ecx + edi*4], 0
// 004aaf2a  7510                 jne 0x4aaf3c
// 004aaf2c  6a0c                 push 0xc
// 004aaf2e  e8e7714d00           call 0x98211a
// 004aaf33  8b5610               mov edx, dword ptr [esi + 0x10]
// 004aaf36  83c404               add esp, 4
// 004aaf39  8904ba               mov dword ptr [edx + edi*4], eax
// 004aaf3c  8b4610               mov eax, dword ptr [esi + 0x10]
// 004aaf3f  8b3cb8               mov edi, dword ptr [eax + edi*4]
// 004aaf42  85ff                 test edi, edi
// 004aaf44  7414                 je 0x4aaf5a
// 004aaf46  8b44240c             mov eax, dword ptr [esp + 0xc]
// 004aaf4a  8b08                 mov ecx, dword ptr [eax]
// 004aaf4c  890f                 mov dword ptr [edi], ecx
// 004aaf4e  8b5004               mov edx, dword ptr [eax + 4]
// 004aaf51  895704               mov dword ptr [edi + 4], edx
// 004aaf54  8b4008               mov eax, dword ptr [eax + 8]
// 004aaf57  894708               mov dword ptr [edi + 8], eax
// 004aaf5a  ff461c               inc dword ptr [esi + 0x1c]
// 004aaf5d  5f                   pop edi
// 004aaf5e  5e                   pop esi
// 004aaf5f  c20400               ret 4
// standard library deque<pod12> (function ?push_back@?$deque@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: deque<pod12>
struct E { int v[3]; };
#include <deque>
template class std::deque<E>;
