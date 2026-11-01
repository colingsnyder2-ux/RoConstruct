// from server: 100% by auto
// roc 2009-06 00758de0  unit: CRobloxTreeCtrl  size: 56 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00758de0
//
// 00758de0  51                   push ecx
// 00758de1  8d442408             lea eax, [esp + 8]
// 00758de5  50                   push eax
// 00758de6  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00758dea  8d542404             lea edx, [esp + 4]
// 00758dee  52                   push edx
// 00758def  50                   push eax
// 00758df0  e80bf5ffff           call 0x758300
// 00758df5  85c0                 test eax, eax
// 00758df7  7504                 jne 0x758dfd
// 00758df9  59                   pop ecx
// 00758dfa  c20800               ret 8
// 00758dfd  56                   push esi
// 00758dfe  57                   push edi
// 00758dff  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 00758e03  8d7004               lea esi, [eax + 4]
// 00758e06  b911000000           mov ecx, 0x11
// 00758e0b  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 00758e0d  5f                   pop edi
// 00758e0e  b801000000           mov eax, 1
// 00758e13  5e                   pop esi
// 00758e14  59                   pop ecx
// 00758e15  c20800               ret 8
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ?Lookup@?$CMap@PAXPAXUCLRFONT@CXTPTreeBase@@AAU12@@@QBEHPAXAAUCLRFONT@CXTPTreeBase@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
