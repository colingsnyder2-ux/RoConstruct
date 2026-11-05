// from server: 100% by auto
// roc 2010-06 005454d0  unit: G3D::Lighting  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005454d0
//
// 005454d0  c701fcf2a100         mov dword ptr [ecx], 0xa1f2fc
// 005454d6  83c104               add ecx, 4
// 005454d9  e9a2faffff           jmp 0x544f80
// library mfc-9.0/atlmfc\src\mfc\afxvisualmanageroffice2007.cpp (function ??1CMFCVisualManagerBitmapCacheItem@CMFCVisualManagerBitmapCache@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxvisualmanageroffice2007.cpp
