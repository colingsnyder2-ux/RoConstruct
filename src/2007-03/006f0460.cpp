// from server: 100% by auto
// roc 2007-03 006f0460  unit: seg_006f0000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006f0460
//
// 006f0460  8b442404             mov eax, dword ptr [esp + 4]
// 006f0464  56                   push esi
// 006f0465  50                   push eax
// 006f0466  8bf1                 mov esi, ecx
// 006f0468  e81fe9f2ff           call 0x61ed8c
// 006f046d  6a00                 push 0
// 006f046f  c70544278c0001000000 mov dword ptr [0x8c2744], 1
// 006f0479  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 006f047c  6a00                 push 0
// 006f047e  51                   push ecx
// 006f047f  ff1554ee7700         call dword ptr [0x77ee54]
// 006f0485  5e                   pop esi
// 006f0486  c20400               ret 4
// library xtp-15.2.1/Source\Controls\Dialog\XTPColorPageCustom.cpp (function ?OnSetFocus@CXTPColorWnd@@IAEXPAVCWnd@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Dialog/XTPColorPageCustom.cpp
