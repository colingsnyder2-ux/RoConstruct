// from server: 100% by auto
// roc 2011-06 00795fe0  unit: RBX::VHttp::?$sp_counted_impl_p  size: 104 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00795fe0
//
// 00795fe0  56                   push esi
// 00795fe1  8bf1                 mov esi, ecx
// 00795fe3  8b461c               mov eax, dword ptr [esi + 0x1c]
// 00795fe6  40                   inc eax
// 00795fe7  394614               cmp dword ptr [esi + 0x14], eax
// 00795fea  7707                 ja 0x795ff3
// 00795fec  6a01                 push 1
// 00795fee  e84dfaffff           call 0x795a40
// 00795ff3  8b4614               mov eax, dword ptr [esi + 0x14]
// 00795ff6  57                   push edi
// 00795ff7  8b7e18               mov edi, dword ptr [esi + 0x18]
// 00795ffa  037e1c               add edi, dword ptr [esi + 0x1c]
// 00795ffd  3bc7                 cmp eax, edi
// 00795fff  7702                 ja 0x796003
// 00796001  2bf8                 sub edi, eax
// 00796003  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 00796006  833cb900             cmp dword ptr [ecx + edi*4], 0
// 0079600a  7510                 jne 0x79601c
// 0079600c  6a10                 push 0x10
// 0079600e  e84b400700           call 0x80a05e
// 00796013  8b5610               mov edx, dword ptr [esi + 0x10]
// 00796016  83c404               add esp, 4
// 00796019  8904ba               mov dword ptr [edx + edi*4], eax
// 0079601c  8b4610               mov eax, dword ptr [esi + 0x10]
// 0079601f  8b04b8               mov eax, dword ptr [eax + edi*4]
// 00796022  5f                   pop edi
// 00796023  85c0                 test eax, eax
// 00796025  741a                 je 0x796041
// 00796027  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0079602b  8b11                 mov edx, dword ptr [ecx]
// 0079602d  8910                 mov dword ptr [eax], edx
// 0079602f  8b5104               mov edx, dword ptr [ecx + 4]
// 00796032  895004               mov dword ptr [eax + 4], edx
// 00796035  8b5108               mov edx, dword ptr [ecx + 8]
// 00796038  895008               mov dword ptr [eax + 8], edx
// 0079603b  8b490c               mov ecx, dword ptr [ecx + 0xc]
// 0079603e  89480c               mov dword ptr [eax + 0xc], ecx
// 00796041  ff461c               inc dword ptr [esi + 0x1c]
// 00796044  5e                   pop esi
// 00796045  c20400               ret 4
// standard library deque<pod16> (function ?push_back@?$deque@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: deque<pod16>
struct E { int v[4]; };
#include <deque>
template class std::deque<E>;
