// from server: 100% by auto
// roc 2009-06 008032b0  unit: CXTColorWnd  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 008032b0
//
// 008032b0  8b442404             mov eax, dword ptr [esp + 4]
// 008032b4  56                   push esi
// 008032b5  50                   push eax
// 008032b6  8bf1                 mov esi, ecx
// 008032b8  e89d65f1ff           call 0x71985a
// 008032bd  6a00                 push 0
// 008032bf  c705cc2aa50001000000 mov dword ptr [0xa52acc], 1
// 008032c9  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 008032cc  6a00                 push 0
// 008032ce  51                   push ecx
// 008032cf  ff157cee8900         call dword ptr [0x89ee7c]
// 008032d5  5e                   pop esi
// 008032d6  c20400               ret 4
// library xtp-15.2.1/Source\Controls\Dialog\XTPColorPageCustom.cpp (function ?OnSetFocus@CXTPColorWnd@@IAEXPAVCWnd@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Dialog/XTPColorPageCustom.cpp
