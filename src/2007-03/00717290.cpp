// from server: 100% by auto
// roc 2007-03 00717290  unit: seg_00710000  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00717290
//
// 00717290  56                   push esi
// 00717291  57                   push edi
// 00717292  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00717296  8b37                 mov esi, dword ptr [edi]
// 00717298  e827390200           call 0x73abc4
// 0071729d  a900100000           test eax, 0x1000
// 007172a2  7412                 je 0x7172b6
// 007172a4  83fefe               cmp esi, -2
// 007172a7  750d                 jne 0x7172b6
// 007172a9  f6470910             test byte ptr [edi + 9], 0x10
// 007172ad  7407                 je 0x7172b6
// 007172af  5f                   pop edi
// 007172b0  33c0                 xor eax, eax
// 007172b2  5e                   pop esi
// 007172b3  c20400               ret 4
// 007172b6  5f                   pop edi
// 007172b7  b801000000           mov eax, 1
// 007172bc  5e                   pop esi
// 007172bd  c20400               ret 4
// library xtp-15.2.1/Source\SkinFramework\XTPSkinObjectToolBar.cpp (function ?HasButtonImage@CXTPSkinObjectToolBar@@IAEHPAU_TBBUTTON@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/SkinFramework/XTPSkinObjectToolBar.cpp
