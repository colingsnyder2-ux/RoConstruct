// from server: 100% by auto
// roc 2009-12 0083a210  unit: CXTPDockingPaneManager  size: 67 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0083a210
//
// 0083a210  56                   push esi
// 0083a211  8bf1                 mov esi, ecx
// 0083a213  8b4608               mov eax, dword ptr [esi + 8]
// 0083a216  6a00                 push 0
// 0083a218  50                   push eax
// 0083a219  e802f5ffff           call 0x839720
// 0083a21e  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0083a222  8b11                 mov edx, dword ptr [ecx]
// 0083a224  895008               mov dword ptr [eax + 8], edx
// 0083a227  8b5104               mov edx, dword ptr [ecx + 4]
// 0083a22a  89500c               mov dword ptr [eax + 0xc], edx
// 0083a22d  8b5108               mov edx, dword ptr [ecx + 8]
// 0083a230  895010               mov dword ptr [eax + 0x10], edx
// 0083a233  8b490c               mov ecx, dword ptr [ecx + 0xc]
// 0083a236  894814               mov dword ptr [eax + 0x14], ecx
// 0083a239  8b4e08               mov ecx, dword ptr [esi + 8]
// 0083a23c  85c9                 test ecx, ecx
// 0083a23e  7409                 je 0x83a249
// 0083a240  8901                 mov dword ptr [ecx], eax
// 0083a242  894608               mov dword ptr [esi + 8], eax
// 0083a245  5e                   pop esi
// 0083a246  c20400               ret 4
// 0083a249  894604               mov dword ptr [esi + 4], eax
// 0083a24c  894608               mov dword ptr [esi + 8], eax
// 0083a24f  5e                   pop esi
// 0083a250  c20400               ret 4
// library xtp-15.2.1/Source\Controls\List\XTPListBase.cpp (function ?AddTail@?$CList@UROWCOLOR@CXTPListBase@@AAU12@@@QAEPAU__POSITION@@AAUROWCOLOR@CXTPListBase@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/List/XTPListBase.cpp
