// from server: 100% by auto
// roc 2007-03 006537b0  unit: seg_00650000  size: 56 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006537b0
//
// 006537b0  51                   push ecx
// 006537b1  8d442408             lea eax, [esp + 8]
// 006537b5  50                   push eax
// 006537b6  8b44240c             mov eax, dword ptr [esp + 0xc]
// 006537ba  8d542404             lea edx, [esp + 4]
// 006537be  52                   push edx
// 006537bf  50                   push eax
// 006537c0  e80bf5ffff           call 0x652cd0
// 006537c5  85c0                 test eax, eax
// 006537c7  7504                 jne 0x6537cd
// 006537c9  59                   pop ecx
// 006537ca  c20800               ret 8
// 006537cd  56                   push esi
// 006537ce  57                   push edi
// 006537cf  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 006537d3  8d7004               lea esi, [eax + 4]
// 006537d6  b911000000           mov ecx, 0x11
// 006537db  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 006537dd  5f                   pop edi
// 006537de  b801000000           mov eax, 1
// 006537e3  5e                   pop esi
// 006537e4  59                   pop ecx
// 006537e5  c20800               ret 8
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ?Lookup@?$CMap@PAXPAXUCLRFONT@CXTPTreeBase@@AAU12@@@QBEHPAXAAUCLRFONT@CXTPTreeBase@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
