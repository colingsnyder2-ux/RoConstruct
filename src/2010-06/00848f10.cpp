// from server: 100% by auto
// roc 2010-06 00848f10  unit: CXTPRibbonBar  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00848f10
//
// 00848f10  8b442404             mov eax, dword ptr [esp + 4]
// 00848f14  56                   push esi
// 00848f15  50                   push eax
// 00848f16  8bf1                 mov esi, ecx
// 00848f18  e813fff6ff           call 0x7b8e30
// 00848f1d  83f8ff               cmp eax, -1
// 00848f20  7506                 jne 0x848f28
// 00848f22  0bc0                 or eax, eax
// 00848f24  5e                   pop esi
// 00848f25  c20400               ret 4
// 00848f28  8bce                 mov ecx, esi
// 00848f2a  e861e5ffff           call 0x847490
// 00848f2f  33c0                 xor eax, eax
// 00848f31  5e                   pop esi
// 00848f32  c20400               ret 4
// library xtp-13.2.1/Source\Ribbon\XTPRibbonBar.cpp (function ?OnCreate@CXTPRibbonBar@@IAEHPAUtagCREATESTRUCTA@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Ribbon/XTPRibbonBar.cpp
