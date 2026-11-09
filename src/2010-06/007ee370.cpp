// from server: 100% by auto
// roc 2010-06 007ee370  unit: CXTPDockingPaneManager  size: 67 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007ee370
//
// 007ee370  56                   push esi
// 007ee371  8bf1                 mov esi, ecx
// 007ee373  8b4608               mov eax, dword ptr [esi + 8]
// 007ee376  6a00                 push 0
// 007ee378  50                   push eax
// 007ee379  e802f5ffff           call 0x7ed880
// 007ee37e  8b4c2408             mov ecx, dword ptr [esp + 8]
// 007ee382  8b11                 mov edx, dword ptr [ecx]
// 007ee384  895008               mov dword ptr [eax + 8], edx
// 007ee387  8b5104               mov edx, dword ptr [ecx + 4]
// 007ee38a  89500c               mov dword ptr [eax + 0xc], edx
// 007ee38d  8b5108               mov edx, dword ptr [ecx + 8]
// 007ee390  895010               mov dword ptr [eax + 0x10], edx
// 007ee393  8b490c               mov ecx, dword ptr [ecx + 0xc]
// 007ee396  894814               mov dword ptr [eax + 0x14], ecx
// 007ee399  8b4e08               mov ecx, dword ptr [esi + 8]
// 007ee39c  85c9                 test ecx, ecx
// 007ee39e  7409                 je 0x7ee3a9
// 007ee3a0  8901                 mov dword ptr [ecx], eax
// 007ee3a2  894608               mov dword ptr [esi + 8], eax
// 007ee3a5  5e                   pop esi
// 007ee3a6  c20400               ret 4
// 007ee3a9  894604               mov dword ptr [esi + 4], eax
// 007ee3ac  894608               mov dword ptr [esi + 8], eax
// 007ee3af  5e                   pop esi
// 007ee3b0  c20400               ret 4
// library xtp-13.2.1/Source\Controls\XTListBase.cpp (function ?AddTail@?$CList@UROWCOLOR@CXTListBase@@AAU12@@@QAEPAU__POSITION@@AAUROWCOLOR@CXTListBase@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTListBase.cpp
