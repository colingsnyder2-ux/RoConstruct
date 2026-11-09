// from server: 100% by auto
// roc 2010-06 004187b0  unit: RBX::VTool::?$FactoryProduct::Creator  size: 143 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004187b0
//
// 004187b0  64a100000000         mov eax, dword ptr fs:[0]
// 004187b6  6aff                 push -1
// 004187b8  6891299a00           push 0x9a2991
// 004187bd  50                   push eax
// 004187be  64892500000000       mov dword ptr fs:[0], esp
// 004187c5  83ec08               sub esp, 8
// 004187c8  56                   push esi
// 004187c9  8bf1                 mov esi, ecx
// 004187cb  8b461c               mov eax, dword ptr [esi + 0x1c]
// 004187ce  40                   inc eax
// 004187cf  394614               cmp dword ptr [esi + 0x14], eax
// 004187d2  7707                 ja 0x4187db
// 004187d4  6a01                 push 1
// 004187d6  e825feffff           call 0x418600
// 004187db  8b4614               mov eax, dword ptr [esi + 0x14]
// 004187de  57                   push edi
// 004187df  8b7e18               mov edi, dword ptr [esi + 0x18]
// 004187e2  037e1c               add edi, dword ptr [esi + 0x1c]
// 004187e5  3bc7                 cmp eax, edi
// 004187e7  7702                 ja 0x4187eb
// 004187e9  2bf8                 sub edi, eax
// 004187eb  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 004187ee  833cb900             cmp dword ptr [ecx + edi*4], 0
// 004187f2  7510                 jne 0x418804
// 004187f4  6a1c                 push 0x1c
// 004187f6  e8a5f13800           call 0x7a79a0
// 004187fb  8b5610               mov edx, dword ptr [esi + 0x10]
// 004187fe  83c404               add esp, 4
// 00418801  8904ba               mov dword ptr [edx + edi*4], eax
// 00418804  8b4610               mov eax, dword ptr [esi + 0x10]
// 00418807  8b0cb8               mov ecx, dword ptr [eax + edi*4]
// 0041880a  894c2408             mov dword ptr [esp + 8], ecx
// 0041880e  894c240c             mov dword ptr [esp + 0xc], ecx
// 00418812  c744241800000000     mov dword ptr [esp + 0x18], 0
// 0041881a  5f                   pop edi
// 0041881b  85c9                 test ecx, ecx
// 0041881d  740b                 je 0x41882a
// 0041881f  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 00418823  52                   push edx
// 00418824  ff150ca49e00         call dword ptr [0x9ea40c]
// 0041882a  ff461c               inc dword ptr [esi + 0x1c]
// 0041882d  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00418831  5e                   pop esi
// 00418832  64890d00000000       mov dword ptr fs:[0], ecx
// 00418839  83c414               add esp, 0x14
// 0041883c  c20400               ret 4
// standard library deque<string> (function ?push_back@?$deque@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAEXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@@Z)

// stl: deque<string>
#include <string>
typedef std::string E;
#include <deque>
template class std::deque<E>;
