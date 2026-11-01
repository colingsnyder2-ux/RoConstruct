// from server: 100% by auto
// roc 2007-03 0071daf0  unit: seg_00710000  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0071daf0
//
// 0071daf0  56                   push esi
// 0071daf1  8bf1                 mov esi, ecx
// 0071daf3  e8da0bf0ff           call 0x61e6d2
// 0071daf8  83f8ff               cmp eax, -1
// 0071dafb  7506                 jne 0x71db03
// 0071dafd  0bc0                 or eax, eax
// 0071daff  5e                   pop esi
// 0071db00  c20400               ret 4
// 0071db03  8b4620               mov eax, dword ptr [esi + 0x20]
// 0071db06  6a00                 push 0
// 0071db08  6a00                 push 0
// 0071db0a  50                   push eax
// 0071db0b  ff1554ee7700         call dword ptr [0x77ee54]
// 0071db11  33c0                 xor eax, eax
// 0071db13  5e                   pop esi
// 0071db14  c20400               ret 4
// library xtp-15.2.1/Source\SkinFramework\XTPSkinObjectComboBox.cpp (function ?OnCreate@CXTPSkinObjectDateTime@@IAEHPAUtagCREATESTRUCTA@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/SkinFramework/XTPSkinObjectComboBox.cpp
