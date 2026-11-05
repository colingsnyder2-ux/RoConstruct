// from server: 100% by auto
// roc 2010-06 00741a70  unit: RBX::VHttp::?$sp_counted_impl_p  size: 104 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00741a70
//
// 00741a70  56                   push esi
// 00741a71  8bf1                 mov esi, ecx
// 00741a73  8b461c               mov eax, dword ptr [esi + 0x1c]
// 00741a76  40                   inc eax
// 00741a77  394614               cmp dword ptr [esi + 0x14], eax
// 00741a7a  7707                 ja 0x741a83
// 00741a7c  6a01                 push 1
// 00741a7e  e8edfaffff           call 0x741570
// 00741a83  8b4614               mov eax, dword ptr [esi + 0x14]
// 00741a86  57                   push edi
// 00741a87  8b7e18               mov edi, dword ptr [esi + 0x18]
// 00741a8a  037e1c               add edi, dword ptr [esi + 0x1c]
// 00741a8d  3bc7                 cmp eax, edi
// 00741a8f  7702                 ja 0x741a93
// 00741a91  2bf8                 sub edi, eax
// 00741a93  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 00741a96  833cb900             cmp dword ptr [ecx + edi*4], 0
// 00741a9a  7510                 jne 0x741aac
// 00741a9c  6a10                 push 0x10
// 00741a9e  e8fd5e0600           call 0x7a79a0
// 00741aa3  8b5610               mov edx, dword ptr [esi + 0x10]
// 00741aa6  83c404               add esp, 4
// 00741aa9  8904ba               mov dword ptr [edx + edi*4], eax
// 00741aac  8b4610               mov eax, dword ptr [esi + 0x10]
// 00741aaf  8b04b8               mov eax, dword ptr [eax + edi*4]
// 00741ab2  5f                   pop edi
// 00741ab3  85c0                 test eax, eax
// 00741ab5  741a                 je 0x741ad1
// 00741ab7  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00741abb  8b11                 mov edx, dword ptr [ecx]
// 00741abd  8910                 mov dword ptr [eax], edx
// 00741abf  8b5104               mov edx, dword ptr [ecx + 4]
// 00741ac2  895004               mov dword ptr [eax + 4], edx
// 00741ac5  8b5108               mov edx, dword ptr [ecx + 8]
// 00741ac8  895008               mov dword ptr [eax + 8], edx
// 00741acb  8b490c               mov ecx, dword ptr [ecx + 0xc]
// 00741ace  89480c               mov dword ptr [eax + 0xc], ecx
// 00741ad1  ff461c               inc dword ptr [esi + 0x1c]
// 00741ad4  5e                   pop esi
// 00741ad5  c20400               ret 4
// standard library deque<pod16> (function ?push_back@?$deque@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: deque<pod16>
struct E { int v[4]; };
#include <deque>
template class std::deque<E>;
