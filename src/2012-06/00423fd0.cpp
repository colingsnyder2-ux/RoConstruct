// from server: 100% by auto
// roc 2012-06 00423fd0  unit: RBX::DSVideoCaptureEngine  size: 143 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00423fd0
//
// 00423fd0  64a100000000         mov eax, dword ptr fs:[0]
// 00423fd6  6aff                 push -1
// 00423fd8  6871e0ab00           push 0xabe071
// 00423fdd  50                   push eax
// 00423fde  64892500000000       mov dword ptr fs:[0], esp
// 00423fe5  83ec08               sub esp, 8
// 00423fe8  56                   push esi
// 00423fe9  8bf1                 mov esi, ecx
// 00423feb  8b461c               mov eax, dword ptr [esi + 0x1c]
// 00423fee  40                   inc eax
// 00423fef  394614               cmp dword ptr [esi + 0x14], eax
// 00423ff2  7707                 ja 0x423ffb
// 00423ff4  6a01                 push 1
// 00423ff6  e875feffff           call 0x423e70
// 00423ffb  8b4614               mov eax, dword ptr [esi + 0x14]
// 00423ffe  57                   push edi
// 00423fff  8b7e18               mov edi, dword ptr [esi + 0x18]
// 00424002  037e1c               add edi, dword ptr [esi + 0x1c]
// 00424005  3bc7                 cmp eax, edi
// 00424007  7702                 ja 0x42400b
// 00424009  2bf8                 sub edi, eax
// 0042400b  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 0042400e  833cb900             cmp dword ptr [ecx + edi*4], 0
// 00424012  7510                 jne 0x424024
// 00424014  6a1c                 push 0x1c
// 00424016  e8ffe05500           call 0x98211a
// 0042401b  8b5610               mov edx, dword ptr [esi + 0x10]
// 0042401e  83c404               add esp, 4
// 00424021  8904ba               mov dword ptr [edx + edi*4], eax
// 00424024  8b4610               mov eax, dword ptr [esi + 0x10]
// 00424027  8b0cb8               mov ecx, dword ptr [eax + edi*4]
// 0042402a  894c2408             mov dword ptr [esp + 8], ecx
// 0042402e  894c240c             mov dword ptr [esp + 0xc], ecx
// 00424032  c744241800000000     mov dword ptr [esp + 0x18], 0
// 0042403a  5f                   pop edi
// 0042403b  85c9                 test ecx, ecx
// 0042403d  740b                 je 0x42404a
// 0042403f  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 00424043  52                   push edx
// 00424044  ff154426b200         call dword ptr [0xb22644]
// 0042404a  ff461c               inc dword ptr [esi + 0x1c]
// 0042404d  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00424051  5e                   pop esi
// 00424052  64890d00000000       mov dword ptr fs:[0], ecx
// 00424059  83c414               add esp, 0x14
// 0042405c  c20400               ret 4
// standard library deque<string> (function ?push_back@?$deque@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAEXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@@Z)

// stl: deque<string>
#include <string>
typedef std::string E;
#include <deque>
template class std::deque<E>;
