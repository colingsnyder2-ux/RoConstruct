// from server: 100% by auto
// roc 2007-03 0071b070  unit: seg_00710000  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0071b070
//
// 0071b070  56                   push esi
// 0071b071  8bf1                 mov esi, ecx
// 0071b073  e888440000           call 0x71f500
// 0071b078  8b4620               mov eax, dword ptr [esi + 0x20]
// 0071b07b  6a00                 push 0
// 0071b07d  6a00                 push 0
// 0071b07f  6a1a                 push 0x1a
// 0071b081  50                   push eax
// 0071b082  ff1548ee7700         call dword ptr [0x77ee48]
// 0071b088  5e                   pop esi
// 0071b089  c3                   ret 
// library xtp-15.2.1/Source\SkinFramework\XTPSkinObjectStatusBar.cpp (function ?RefreshMetrics@CXTPSkinObjectStatusBar@@MAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/SkinFramework/XTPSkinObjectStatusBar.cpp
