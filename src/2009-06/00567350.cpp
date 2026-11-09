// from server: 100% by auto
// roc 2009-06 00567350  unit: G3D::Lighting  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00567350
//
// 00567350  c701e4a98c00         mov dword ptr [ecx], 0x8ca9e4
// 00567356  83c104               add ecx, 4
// 00567359  e94263f3ff           jmp 0x49d6a0
// library mfc-9.0/atlmfc\src\mfc\afxvisualmanageroffice2007.cpp (function ??1CMFCVisualManagerBitmapCacheItem@CMFCVisualManagerBitmapCache@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxvisualmanageroffice2007.cpp
