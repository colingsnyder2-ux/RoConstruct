// from server: 100% by auto
// roc 2007-03 00699de0  unit: seg_00690000  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00699de0
//
// 00699de0  8b442404             mov eax, dword ptr [esp + 4]
// 00699de4  56                   push esi
// 00699de5  50                   push eax
// 00699de6  8bf1                 mov esi, ecx
// 00699de8  e813f7f9ff           call 0x639500
// 00699ded  83f8ff               cmp eax, -1
// 00699df0  7506                 jne 0x699df8
// 00699df2  0bc0                 or eax, eax
// 00699df4  5e                   pop esi
// 00699df5  c20400               ret 4
// 00699df8  8bce                 mov ecx, esi
// 00699dfa  e8d1e6ffff           call 0x6984d0
// 00699dff  33c0                 xor eax, eax
// 00699e01  5e                   pop esi
// 00699e02  c20400               ret 4
// library xtp-15.2.1/Source\Ribbon\XTPRibbonBar.cpp (function ?OnCreate@CXTPRibbonBar@@IAEHPAUtagCREATESTRUCTA@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Ribbon/XTPRibbonBar.cpp
