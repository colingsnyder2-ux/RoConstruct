// from server: 100% by auto
// roc 2007-03 006f48d0  unit: seg_006f0000  size: 68 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006f48d0
//
// 006f48d0  56                   push esi
// 006f48d1  8bf1                 mov esi, ecx
// 006f48d3  8b4604               mov eax, dword ptr [esi + 4]
// 006f48d6  50                   push eax
// 006f48d7  6a00                 push 0
// 006f48d9  e8a2fdffff           call 0x6f4680
// 006f48de  8b4c2408             mov ecx, dword ptr [esp + 8]
// 006f48e2  8b11                 mov edx, dword ptr [ecx]
// 006f48e4  895008               mov dword ptr [eax + 8], edx
// 006f48e7  8b5104               mov edx, dword ptr [ecx + 4]
// 006f48ea  89500c               mov dword ptr [eax + 0xc], edx
// 006f48ed  8b5108               mov edx, dword ptr [ecx + 8]
// 006f48f0  895010               mov dword ptr [eax + 0x10], edx
// 006f48f3  8b490c               mov ecx, dword ptr [ecx + 0xc]
// 006f48f6  894814               mov dword ptr [eax + 0x14], ecx
// 006f48f9  8b4e04               mov ecx, dword ptr [esi + 4]
// 006f48fc  85c9                 test ecx, ecx
// 006f48fe  740a                 je 0x6f490a
// 006f4900  894104               mov dword ptr [ecx + 4], eax
// 006f4903  894604               mov dword ptr [esi + 4], eax
// 006f4906  5e                   pop esi
// 006f4907  c20400               ret 4
// 006f490a  894608               mov dword ptr [esi + 8], eax
// 006f490d  894604               mov dword ptr [esi + 4], eax
// 006f4910  5e                   pop esi
// 006f4911  c20400               ret 4
// library xtp-15.2.1/Source\Controls\List\XTPListBase.cpp (function ?AddHead@?$CList@UROWCOLOR@CXTPListBase@@AAU12@@@QAEPAU__POSITION@@AAUROWCOLOR@CXTPListBase@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/List/XTPListBase.cpp
