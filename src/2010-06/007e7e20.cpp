// from server: 100% by auto
// roc 2010-06 007e7e20  unit: CRobloxTreeCtrl  size: 56 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007e7e20
//
// 007e7e20  51                   push ecx
// 007e7e21  8d442408             lea eax, [esp + 8]
// 007e7e25  50                   push eax
// 007e7e26  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007e7e2a  8d542404             lea edx, [esp + 4]
// 007e7e2e  52                   push edx
// 007e7e2f  50                   push eax
// 007e7e30  e80bf5ffff           call 0x7e7340
// 007e7e35  85c0                 test eax, eax
// 007e7e37  7504                 jne 0x7e7e3d
// 007e7e39  59                   pop ecx
// 007e7e3a  c20800               ret 8
// 007e7e3d  56                   push esi
// 007e7e3e  57                   push edi
// 007e7e3f  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 007e7e43  8d7004               lea esi, [eax + 4]
// 007e7e46  b911000000           mov ecx, 0x11
// 007e7e4b  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 007e7e4d  5f                   pop edi
// 007e7e4e  b801000000           mov eax, 1
// 007e7e53  5e                   pop esi
// 007e7e54  59                   pop ecx
// 007e7e55  c20800               ret 8
// library xtp-13.2.1/Source\Controls\XTTreeBase.cpp (function ?Lookup@?$CMap@PAXPAXUCLRFONT@CXTTreeBase@@AAU12@@@QBEHPAXAAUCLRFONT@CXTTreeBase@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTTreeBase.cpp
