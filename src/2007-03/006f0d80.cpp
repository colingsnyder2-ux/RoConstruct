// from server: 100% by auto
// roc 2007-03 006f0d80  unit: seg_006f0000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006f0d80
//
// 006f0d80  8b442404             mov eax, dword ptr [esp + 4]
// 006f0d84  56                   push esi
// 006f0d85  50                   push eax
// 006f0d86  8bf1                 mov esi, ecx
// 006f0d88  e8ffdff2ff           call 0x61ed8c
// 006f0d8d  6a00                 push 0
// 006f0d8f  c70544278c0002000000 mov dword ptr [0x8c2744], 2
// 006f0d99  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 006f0d9c  6a00                 push 0
// 006f0d9e  51                   push ecx
// 006f0d9f  ff1554ee7700         call dword ptr [0x77ee54]
// 006f0da5  5e                   pop esi
// 006f0da6  c20400               ret 4
// library xtp-15.2.1/Source\Controls\Dialog\XTPColorPageCustom.cpp (function ?OnSetFocus@CXTPColorLum@@IAEXPAVCWnd@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Dialog/XTPColorPageCustom.cpp
