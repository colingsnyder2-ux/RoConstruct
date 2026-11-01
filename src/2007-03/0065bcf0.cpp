// from server: 100% by auto
// roc 2007-03 0065bcf0  unit: seg_00650000  size: 67 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0065bcf0
//
// 0065bcf0  56                   push esi
// 0065bcf1  8bf1                 mov esi, ecx
// 0065bcf3  8b4608               mov eax, dword ptr [esi + 8]
// 0065bcf6  6a00                 push 0
// 0065bcf8  50                   push eax
// 0065bcf9  e862f4ffff           call 0x65b160
// 0065bcfe  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0065bd02  8b11                 mov edx, dword ptr [ecx]
// 0065bd04  895008               mov dword ptr [eax + 8], edx
// 0065bd07  8b5104               mov edx, dword ptr [ecx + 4]
// 0065bd0a  89500c               mov dword ptr [eax + 0xc], edx
// 0065bd0d  8b5108               mov edx, dword ptr [ecx + 8]
// 0065bd10  895010               mov dword ptr [eax + 0x10], edx
// 0065bd13  8b490c               mov ecx, dword ptr [ecx + 0xc]
// 0065bd16  894814               mov dword ptr [eax + 0x14], ecx
// 0065bd19  8b4e08               mov ecx, dword ptr [esi + 8]
// 0065bd1c  85c9                 test ecx, ecx
// 0065bd1e  7409                 je 0x65bd29
// 0065bd20  8901                 mov dword ptr [ecx], eax
// 0065bd22  894608               mov dword ptr [esi + 8], eax
// 0065bd25  5e                   pop esi
// 0065bd26  c20400               ret 4
// 0065bd29  894604               mov dword ptr [esi + 4], eax
// 0065bd2c  894608               mov dword ptr [esi + 8], eax
// 0065bd2f  5e                   pop esi
// 0065bd30  c20400               ret 4
// library xtp-15.2.1/Source\Controls\List\XTPListBase.cpp (function ?AddTail@?$CList@UROWCOLOR@CXTPListBase@@AAU12@@@QAEPAU__POSITION@@AAUROWCOLOR@CXTPListBase@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/List/XTPListBase.cpp
