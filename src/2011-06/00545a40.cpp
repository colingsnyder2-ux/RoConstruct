// from server: 100% by auto
// roc 2011-06 00545a40  unit: std::D::DU?$char_traits::V?$basic_string::?$Table  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00545a40
//
// 00545a40  c7014cfea700         mov dword ptr [ecx], 0xa7fe4c
// 00545a46  83c104               add ecx, 4
// 00545a49  e902ffffff           jmp 0x545950
// library mfc-9.0/atlmfc\src\mfc\afxvisualmanageroffice2007.cpp (function ??1CMFCVisualManagerBitmapCacheItem@CMFCVisualManagerBitmapCache@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxvisualmanageroffice2007.cpp
