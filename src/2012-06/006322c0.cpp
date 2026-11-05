// from server: 100% by auto
// roc 2012-06 006322c0  unit: std::D::DU?$char_traits::V?$basic_string::?$Set  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006322c0
//
// 006322c0  56                   push esi
// 006322c1  8bf1                 mov esi, ecx
// 006322c3  8d4e04               lea ecx, [esi + 4]
// 006322c6  c706583bb800         mov dword ptr [esi], 0xb83b58
// 006322cc  e8effbffff           call 0x631ec0
// 006322d1  f644240801           test byte ptr [esp + 8], 1
// 006322d6  7409                 je 0x6322e1
// 006322d8  56                   push esi
// 006322d9  e836fe3400           call 0x982114
// 006322de  83c404               add esp, 4
// 006322e1  8bc6                 mov eax, esi
// 006322e3  5e                   pop esi
// 006322e4  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxvisualmanageroffice2007.cpp (function ??_GCMFCVisualManagerBitmapCacheItem@CMFCVisualManagerBitmapCache@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxvisualmanageroffice2007.cpp
