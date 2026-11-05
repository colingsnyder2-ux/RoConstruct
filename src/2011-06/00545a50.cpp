// from server: 100% by auto
// roc 2011-06 00545a50  unit: std::D::DU?$char_traits::V?$basic_string::?$Set  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00545a50
//
// 00545a50  56                   push esi
// 00545a51  8bf1                 mov esi, ecx
// 00545a53  8d4e04               lea ecx, [esi + 4]
// 00545a56  c7064cfea700         mov dword ptr [esi], 0xa7fe4c
// 00545a5c  e8effeffff           call 0x545950
// 00545a61  f644240801           test byte ptr [esp + 8], 1
// 00545a66  7409                 je 0x545a71
// 00545a68  56                   push esi
// 00545a69  e8ea452c00           call 0x80a058
// 00545a6e  83c404               add esp, 4
// 00545a71  8bc6                 mov eax, esi
// 00545a73  5e                   pop esi
// 00545a74  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxvisualmanageroffice2007.cpp (function ??_GCMFCVisualManagerBitmapCacheItem@CMFCVisualManagerBitmapCache@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxvisualmanageroffice2007.cpp
