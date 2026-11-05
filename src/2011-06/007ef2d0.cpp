// from server: 100% by auto
// roc 2011-06 007ef2d0  unit: RBX::SpatialFilter  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 007ef2d0
//
// 007ef2d0  c701b8f0ab00         mov dword ptr [ecx], 0xabf0b8
// 007ef2d6  83c104               add ecx, 4
// 007ef2d9  e9f2e8f1ff           jmp 0x70dbd0
// library mfc-9.0/atlmfc\src\mfc\afxvisualmanageroffice2007.cpp (function ??1CMFCVisualManagerBitmapCacheItem@CMFCVisualManagerBitmapCache@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxvisualmanageroffice2007.cpp
