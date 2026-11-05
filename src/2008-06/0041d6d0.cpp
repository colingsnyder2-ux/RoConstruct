// from server: 100% by auto
// roc 2008-06 0041d6d0  unit: VDHTMLWindow::?$SignalDesc  size: 143 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0041d6d0
//
// 0041d6d0  64a100000000         mov eax, dword ptr fs:[0]
// 0041d6d6  6aff                 push -1
// 0041d6d8  6881757d00           push 0x7d7581
// 0041d6dd  50                   push eax
// 0041d6de  64892500000000       mov dword ptr fs:[0], esp
// 0041d6e5  83ec08               sub esp, 8
// 0041d6e8  56                   push esi
// 0041d6e9  8bf1                 mov esi, ecx
// 0041d6eb  8b461c               mov eax, dword ptr [esi + 0x1c]
// 0041d6ee  40                   inc eax
// 0041d6ef  394614               cmp dword ptr [esi + 0x14], eax
// 0041d6f2  7707                 ja 0x41d6fb
// 0041d6f4  6a01                 push 1
// 0041d6f6  e875feffff           call 0x41d570
// 0041d6fb  8b4614               mov eax, dword ptr [esi + 0x14]
// 0041d6fe  57                   push edi
// 0041d6ff  8b7e18               mov edi, dword ptr [esi + 0x18]
// 0041d702  037e1c               add edi, dword ptr [esi + 0x1c]
// 0041d705  3bc7                 cmp eax, edi
// 0041d707  7702                 ja 0x41d70b
// 0041d709  2bf8                 sub edi, eax
// 0041d70b  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 0041d70e  833cb900             cmp dword ptr [ecx + edi*4], 0
// 0041d712  7510                 jne 0x41d724
// 0041d714  6a1c                 push 0x1c
// 0041d716  e805322800           call 0x6a0920
// 0041d71b  8b5610               mov edx, dword ptr [esi + 0x10]
// 0041d71e  83c404               add esp, 4
// 0041d721  8904ba               mov dword ptr [edx + edi*4], eax
// 0041d724  8b4610               mov eax, dword ptr [esi + 0x10]
// 0041d727  8b0cb8               mov ecx, dword ptr [eax + edi*4]
// 0041d72a  894c2408             mov dword ptr [esp + 8], ecx
// 0041d72e  894c240c             mov dword ptr [esp + 0xc], ecx
// 0041d732  c744241800000000     mov dword ptr [esp + 0x18], 0
// 0041d73a  5f                   pop edi
// 0041d73b  85c9                 test ecx, ecx
// 0041d73d  740b                 je 0x41d74a
// 0041d73f  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0041d743  52                   push edx
// 0041d744  ff155c248000         call dword ptr [0x80245c]
// 0041d74a  ff461c               inc dword ptr [esi + 0x1c]
// 0041d74d  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0041d751  5e                   pop esi
// 0041d752  64890d00000000       mov dword ptr fs:[0], ecx
// 0041d759  83c414               add esp, 0x14
// 0041d75c  c20400               ret 4
// standard library deque<string> (function ?push_back@?$deque@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAEXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@@Z)

// stl: deque<string>
#include <string>
typedef std::string E;
#include <deque>
template class std::deque<E>;
