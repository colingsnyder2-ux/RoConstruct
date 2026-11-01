// from server: 100% by auto
// roc 2009-12 00894d80  unit: CXTPRibbonBar  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00894d80
//
// 00894d80  8b442404             mov eax, dword ptr [esp + 4]
// 00894d84  56                   push esi
// 00894d85  50                   push eax
// 00894d86  8bf1                 mov esi, ecx
// 00894d88  e833fff6ff           call 0x804cc0
// 00894d8d  83f8ff               cmp eax, -1
// 00894d90  7506                 jne 0x894d98
// 00894d92  0bc0                 or eax, eax
// 00894d94  5e                   pop esi
// 00894d95  c20400               ret 4
// 00894d98  8bce                 mov ecx, esi
// 00894d9a  e841e5ffff           call 0x8932e0
// 00894d9f  33c0                 xor eax, eax
// 00894da1  5e                   pop esi
// 00894da2  c20400               ret 4
// library xtp-15.2.1/Source\Ribbon\XTPRibbonBar.cpp (function ?OnCreate@CXTPRibbonBar@@IAEHPAUtagCREATESTRUCTA@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Ribbon/XTPRibbonBar.cpp
