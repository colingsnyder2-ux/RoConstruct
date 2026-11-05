// from server: 100% by auto
// roc 2011-06 00496800  unit: DxUserInput  size: 98 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00496800
//
// 00496800  56                   push esi
// 00496801  8bf1                 mov esi, ecx
// 00496803  8b461c               mov eax, dword ptr [esi + 0x1c]
// 00496806  40                   inc eax
// 00496807  57                   push edi
// 00496808  394614               cmp dword ptr [esi + 0x14], eax
// 0049680b  7707                 ja 0x496814
// 0049680d  6a01                 push 1
// 0049680f  e81c9dfeff           call 0x480530
// 00496814  8b7e18               mov edi, dword ptr [esi + 0x18]
// 00496817  037e1c               add edi, dword ptr [esi + 0x1c]
// 0049681a  8b4614               mov eax, dword ptr [esi + 0x14]
// 0049681d  3bc7                 cmp eax, edi
// 0049681f  7702                 ja 0x496823
// 00496821  2bf8                 sub edi, eax
// 00496823  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 00496826  833cb900             cmp dword ptr [ecx + edi*4], 0
// 0049682a  7510                 jne 0x49683c
// 0049682c  6a0c                 push 0xc
// 0049682e  e82b383700           call 0x80a05e
// 00496833  8b5610               mov edx, dword ptr [esi + 0x10]
// 00496836  83c404               add esp, 4
// 00496839  8904ba               mov dword ptr [edx + edi*4], eax
// 0049683c  8b4610               mov eax, dword ptr [esi + 0x10]
// 0049683f  8b3cb8               mov edi, dword ptr [eax + edi*4]
// 00496842  85ff                 test edi, edi
// 00496844  7414                 je 0x49685a
// 00496846  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0049684a  8b08                 mov ecx, dword ptr [eax]
// 0049684c  890f                 mov dword ptr [edi], ecx
// 0049684e  8b5004               mov edx, dword ptr [eax + 4]
// 00496851  895704               mov dword ptr [edi + 4], edx
// 00496854  8b4008               mov eax, dword ptr [eax + 8]
// 00496857  894708               mov dword ptr [edi + 8], eax
// 0049685a  ff461c               inc dword ptr [esi + 0x1c]
// 0049685d  5f                   pop edi
// 0049685e  5e                   pop esi
// 0049685f  c20400               ret 4
// standard library deque<pod12> (function ?push_back@?$deque@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: deque<pod12>
struct E { int v[3]; };
#include <deque>
template class std::deque<E>;
