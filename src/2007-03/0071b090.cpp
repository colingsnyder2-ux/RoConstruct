// from server: 100% by auto
// roc 2007-03 0071b090  unit: seg_00710000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0071b090
//
// 0071b090  56                   push esi
// 0071b091  8bf1                 mov esi, ecx
// 0071b093  e83a36f0ff           call 0x61e6d2
// 0071b098  83f8ff               cmp eax, -1
// 0071b09b  7506                 jne 0x71b0a3
// 0071b09d  0bc0                 or eax, eax
// 0071b09f  5e                   pop esi
// 0071b0a0  c20400               ret 4
// 0071b0a3  8b4620               mov eax, dword ptr [esi + 0x20]
// 0071b0a6  6a00                 push 0
// 0071b0a8  6a00                 push 0
// 0071b0aa  6a1a                 push 0x1a
// 0071b0ac  50                   push eax
// 0071b0ad  ff1550ee7700         call dword ptr [0x77ee50]
// 0071b0b3  33c0                 xor eax, eax
// 0071b0b5  5e                   pop esi
// 0071b0b6  c20400               ret 4
// library xtp-15.2.1/Source\SkinFramework\XTPSkinObjectStatusBar.cpp (function ?OnCreate@CXTPSkinObjectStatusBar@@IAEHPAUtagCREATESTRUCTA@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/SkinFramework/XTPSkinObjectStatusBar.cpp
