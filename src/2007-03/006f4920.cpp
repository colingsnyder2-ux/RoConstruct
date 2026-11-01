// from server: 100% by auto
// roc 2007-03 006f4920  unit: seg_006f0000  size: 67 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006f4920
//
// 006f4920  56                   push esi
// 006f4921  8bf1                 mov esi, ecx
// 006f4923  8b4608               mov eax, dword ptr [esi + 8]
// 006f4926  6a00                 push 0
// 006f4928  50                   push eax
// 006f4929  e852fdffff           call 0x6f4680
// 006f492e  8b4c2408             mov ecx, dword ptr [esp + 8]
// 006f4932  8b11                 mov edx, dword ptr [ecx]
// 006f4934  895008               mov dword ptr [eax + 8], edx
// 006f4937  8b5104               mov edx, dword ptr [ecx + 4]
// 006f493a  89500c               mov dword ptr [eax + 0xc], edx
// 006f493d  8b5108               mov edx, dword ptr [ecx + 8]
// 006f4940  895010               mov dword ptr [eax + 0x10], edx
// 006f4943  8b490c               mov ecx, dword ptr [ecx + 0xc]
// 006f4946  894814               mov dword ptr [eax + 0x14], ecx
// 006f4949  8b4e08               mov ecx, dword ptr [esi + 8]
// 006f494c  85c9                 test ecx, ecx
// 006f494e  7409                 je 0x6f4959
// 006f4950  8901                 mov dword ptr [ecx], eax
// 006f4952  894608               mov dword ptr [esi + 8], eax
// 006f4955  5e                   pop esi
// 006f4956  c20400               ret 4
// 006f4959  894604               mov dword ptr [esi + 4], eax
// 006f495c  894608               mov dword ptr [esi + 8], eax
// 006f495f  5e                   pop esi
// 006f4960  c20400               ret 4
// library xtp-15.2.1/Source\Controls\List\XTPListBase.cpp (function ?AddTail@?$CList@UROWCOLOR@CXTPListBase@@AAU12@@@QAEPAU__POSITION@@AAUROWCOLOR@CXTPListBase@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/List/XTPListBase.cpp
