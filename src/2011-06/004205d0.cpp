// from server: 100% by auto
// roc 2011-06 004205d0  unit: RBX::DSVideoCaptureEngine  size: 143 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 004205d0
//
// 004205d0  64a100000000         mov eax, dword ptr fs:[0]
// 004205d6  6aff                 push -1
// 004205d8  6811409f00           push 0x9f4011
// 004205dd  50                   push eax
// 004205de  64892500000000       mov dword ptr fs:[0], esp
// 004205e5  83ec08               sub esp, 8
// 004205e8  56                   push esi
// 004205e9  8bf1                 mov esi, ecx
// 004205eb  8b461c               mov eax, dword ptr [esi + 0x1c]
// 004205ee  40                   inc eax
// 004205ef  394614               cmp dword ptr [esi + 0x14], eax
// 004205f2  7707                 ja 0x4205fb
// 004205f4  6a01                 push 1
// 004205f6  e865feffff           call 0x420460
// 004205fb  8b4614               mov eax, dword ptr [esi + 0x14]
// 004205fe  57                   push edi
// 004205ff  8b7e18               mov edi, dword ptr [esi + 0x18]
// 00420602  037e1c               add edi, dword ptr [esi + 0x1c]
// 00420605  3bc7                 cmp eax, edi
// 00420607  7702                 ja 0x42060b
// 00420609  2bf8                 sub edi, eax
// 0042060b  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 0042060e  833cb900             cmp dword ptr [ecx + edi*4], 0
// 00420612  7510                 jne 0x420624
// 00420614  6a1c                 push 0x1c
// 00420616  e8439a3e00           call 0x80a05e
// 0042061b  8b5610               mov edx, dword ptr [esi + 0x10]
// 0042061e  83c404               add esp, 4
// 00420621  8904ba               mov dword ptr [edx + edi*4], eax
// 00420624  8b4610               mov eax, dword ptr [esi + 0x10]
// 00420627  8b0cb8               mov ecx, dword ptr [eax + edi*4]
// 0042062a  894c2408             mov dword ptr [esp + 8], ecx
// 0042062e  894c240c             mov dword ptr [esp + 0xc], ecx
// 00420632  c744241800000000     mov dword ptr [esp + 0x18], 0
// 0042063a  5f                   pop edi
// 0042063b  85c9                 test ecx, ecx
// 0042063d  740b                 je 0x42064a
// 0042063f  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 00420643  52                   push edx
// 00420644  ff15c804a400         call dword ptr [0xa404c8]
// 0042064a  ff461c               inc dword ptr [esi + 0x1c]
// 0042064d  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00420651  5e                   pop esi
// 00420652  64890d00000000       mov dword ptr fs:[0], ecx
// 00420659  83c414               add esp, 0x14
// 0042065c  c20400               ret 4
// standard library deque<string> (function ?push_back@?$deque@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAEXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@@Z)

// stl: deque<string>
#include <string>
typedef std::string E;
#include <deque>
template class std::deque<E>;
