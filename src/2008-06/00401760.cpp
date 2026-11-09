// from server: 100% by auto
// roc 2008-06 00401760  unit: CAboutRobloxDialog  size: 59 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00401760
//
// 00401760  56                   push esi
// 00401761  8b742408             mov esi, dword ptr [esp + 8]
// 00401765  85f6                 test esi, esi
// 00401767  742c                 je 0x401795
// 00401769  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0040176d  85c0                 test eax, eax
// 0040176f  7424                 je 0x401795
// 00401771  8b542410             mov edx, dword ptr [esp + 0x10]
// 00401775  52                   push edx
// 00401776  56                   push esi
// 00401777  6aff                 push -1
// 00401779  50                   push eax
// 0040177a  8b442424             mov eax, dword ptr [esp + 0x24]
// 0040177e  33c9                 xor ecx, ecx
// 00401780  51                   push ecx
// 00401781  50                   push eax
// 00401782  66890e               mov word ptr [esi], cx
// 00401785  ff151c238000         call dword ptr [0x80231c]
// 0040178b  f7d8                 neg eax
// 0040178d  1bc0                 sbb eax, eax
// 0040178f  23c6                 and eax, esi
// 00401791  5e                   pop esi
// 00401792  c21000               ret 0x10
// 00401795  33c0                 xor eax, eax
// 00401797  5e                   pop esi
// 00401798  c21000               ret 0x10
// library mfc-9.0/atlmfc\src\mfc\afxglobalutils.cpp (function ?AtlA2WHelper@@YGPA_WPA_WPBDHI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxglobalutils.cpp
