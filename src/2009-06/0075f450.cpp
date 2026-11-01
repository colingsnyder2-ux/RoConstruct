// from server: 100% by auto
// roc 2009-06 0075f450  unit: CXTPDockingPaneManager  size: 67 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0075f450
//
// 0075f450  56                   push esi
// 0075f451  8bf1                 mov esi, ecx
// 0075f453  8b4608               mov eax, dword ptr [esi + 8]
// 0075f456  6a00                 push 0
// 0075f458  50                   push eax
// 0075f459  e802f5ffff           call 0x75e960
// 0075f45e  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0075f462  8b11                 mov edx, dword ptr [ecx]
// 0075f464  895008               mov dword ptr [eax + 8], edx
// 0075f467  8b5104               mov edx, dword ptr [ecx + 4]
// 0075f46a  89500c               mov dword ptr [eax + 0xc], edx
// 0075f46d  8b5108               mov edx, dword ptr [ecx + 8]
// 0075f470  895010               mov dword ptr [eax + 0x10], edx
// 0075f473  8b490c               mov ecx, dword ptr [ecx + 0xc]
// 0075f476  894814               mov dword ptr [eax + 0x14], ecx
// 0075f479  8b4e08               mov ecx, dword ptr [esi + 8]
// 0075f47c  85c9                 test ecx, ecx
// 0075f47e  7409                 je 0x75f489
// 0075f480  8901                 mov dword ptr [ecx], eax
// 0075f482  894608               mov dword ptr [esi + 8], eax
// 0075f485  5e                   pop esi
// 0075f486  c20400               ret 4
// 0075f489  894604               mov dword ptr [esi + 4], eax
// 0075f48c  894608               mov dword ptr [esi + 8], eax
// 0075f48f  5e                   pop esi
// 0075f490  c20400               ret 4
// library xtp-15.2.1/Source\Controls\List\XTPListBase.cpp (function ?AddTail@?$CList@UROWCOLOR@CXTPListBase@@AAU12@@@QAEPAU__POSITION@@AAUROWCOLOR@CXTPListBase@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/List/XTPListBase.cpp
