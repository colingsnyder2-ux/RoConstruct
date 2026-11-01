// from server: 100% by auto
// roc 2009-06 007b7b30  unit: CXTPRibbonBar  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007b7b30
//
// 007b7b30  8b442404             mov eax, dword ptr [esp + 4]
// 007b7b34  56                   push esi
// 007b7b35  50                   push eax
// 007b7b36  8bf1                 mov esi, ecx
// 007b7b38  e84360f7ff           call 0x72db80
// 007b7b3d  83f8ff               cmp eax, -1
// 007b7b40  7506                 jne 0x7b7b48
// 007b7b42  0bc0                 or eax, eax
// 007b7b44  5e                   pop esi
// 007b7b45  c20400               ret 4
// 007b7b48  8bce                 mov ecx, esi
// 007b7b4a  e8b1e5ffff           call 0x7b6100
// 007b7b4f  33c0                 xor eax, eax
// 007b7b51  5e                   pop esi
// 007b7b52  c20400               ret 4
// library xtp-15.2.1/Source\Ribbon\XTPRibbonBar.cpp (function ?OnCreate@CXTPRibbonBar@@IAEHPAUtagCREATESTRUCTA@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Ribbon/XTPRibbonBar.cpp
