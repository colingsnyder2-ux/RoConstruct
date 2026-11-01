// from server: 100% by auto
// roc 2009-12 00833c60  unit: CRobloxTreeCtrl  size: 56 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00833c60
//
// 00833c60  51                   push ecx
// 00833c61  8d442408             lea eax, [esp + 8]
// 00833c65  50                   push eax
// 00833c66  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00833c6a  8d542404             lea edx, [esp + 4]
// 00833c6e  52                   push edx
// 00833c6f  50                   push eax
// 00833c70  e80bf5ffff           call 0x833180
// 00833c75  85c0                 test eax, eax
// 00833c77  7504                 jne 0x833c7d
// 00833c79  59                   pop ecx
// 00833c7a  c20800               ret 8
// 00833c7d  56                   push esi
// 00833c7e  57                   push edi
// 00833c7f  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 00833c83  8d7004               lea esi, [eax + 4]
// 00833c86  b911000000           mov ecx, 0x11
// 00833c8b  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 00833c8d  5f                   pop edi
// 00833c8e  b801000000           mov eax, 1
// 00833c93  5e                   pop esi
// 00833c94  59                   pop ecx
// 00833c95  c20800               ret 8
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ?Lookup@?$CMap@PAXPAXUCLRFONT@CXTPTreeBase@@AAU12@@@QBEHPAXAAUCLRFONT@CXTPTreeBase@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
