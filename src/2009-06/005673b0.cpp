// from server: 100% by auto
// roc 2009-06 005673b0  unit: RBX::RenderSceneBase  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005673b0
//
// 005673b0  56                   push esi
// 005673b1  8bf1                 mov esi, ecx
// 005673b3  8d4e04               lea ecx, [esi + 4]
// 005673b6  c706e4a98c00         mov dword ptr [esi], 0x8ca9e4
// 005673bc  e8df62f3ff           call 0x49d6a0
// 005673c1  f644240801           test byte ptr [esp + 8], 1
// 005673c6  7409                 je 0x5673d1
// 005673c8  56                   push esi
// 005673c9  e864161b00           call 0x718a32
// 005673ce  83c404               add esp, 4
// 005673d1  8bc6                 mov eax, esi
// 005673d3  5e                   pop esi
// 005673d4  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxvisualmanageroffice2007.cpp (function ??_GCMFCVisualManagerBitmapCacheItem@CMFCVisualManagerBitmapCache@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxvisualmanageroffice2007.cpp
