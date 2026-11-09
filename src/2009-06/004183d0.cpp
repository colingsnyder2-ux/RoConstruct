// from server: 100% by auto
// roc 2009-06 004183d0  unit: RBX::VTool::?$FactoryProduct::Creator  size: 143 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004183d0
//
// 004183d0  64a100000000         mov eax, dword ptr fs:[0]
// 004183d6  6aff                 push -1
// 004183d8  68f17d8600           push 0x867df1
// 004183dd  50                   push eax
// 004183de  64892500000000       mov dword ptr fs:[0], esp
// 004183e5  83ec08               sub esp, 8
// 004183e8  56                   push esi
// 004183e9  8bf1                 mov esi, ecx
// 004183eb  8b461c               mov eax, dword ptr [esi + 0x1c]
// 004183ee  40                   inc eax
// 004183ef  394614               cmp dword ptr [esi + 0x14], eax
// 004183f2  7707                 ja 0x4183fb
// 004183f4  6a01                 push 1
// 004183f6  e825feffff           call 0x418220
// 004183fb  8b4614               mov eax, dword ptr [esi + 0x14]
// 004183fe  57                   push edi
// 004183ff  8b7e18               mov edi, dword ptr [esi + 0x18]
// 00418402  037e1c               add edi, dword ptr [esi + 0x1c]
// 00418405  3bc7                 cmp eax, edi
// 00418407  7702                 ja 0x41840b
// 00418409  2bf8                 sub edi, eax
// 0041840b  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 0041840e  833cb900             cmp dword ptr [ecx + edi*4], 0
// 00418412  7510                 jne 0x418424
// 00418414  6a1c                 push 0x1c
// 00418416  e81d063000           call 0x718a38
// 0041841b  8b5610               mov edx, dword ptr [esi + 0x10]
// 0041841e  83c404               add esp, 4
// 00418421  8904ba               mov dword ptr [edx + edi*4], eax
// 00418424  8b4610               mov eax, dword ptr [esi + 0x10]
// 00418427  8b0cb8               mov ecx, dword ptr [eax + edi*4]
// 0041842a  894c2408             mov dword ptr [esp + 8], ecx
// 0041842e  894c240c             mov dword ptr [esp + 0xc], ecx
// 00418432  c744241800000000     mov dword ptr [esp + 0x18], 0
// 0041843a  5f                   pop edi
// 0041843b  85c9                 test ecx, ecx
// 0041843d  740b                 je 0x41844a
// 0041843f  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 00418443  52                   push edx
// 00418444  ff15b8e48900         call dword ptr [0x89e4b8]
// 0041844a  ff461c               inc dword ptr [esi + 0x1c]
// 0041844d  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00418451  5e                   pop esi
// 00418452  64890d00000000       mov dword ptr fs:[0], ecx
// 00418459  83c414               add esp, 0x14
// 0041845c  c20400               ret 4
// standard library deque<string> (function ?push_back@?$deque@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAEXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@@Z)

// stl: deque<string>
#include <string>
typedef std::string E;
#include <deque>
template class std::deque<E>;
