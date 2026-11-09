// from server: 100% by auto
// roc 2012-06 00687c70  unit: RBX::HeartbeatInstance  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00687c70
//
// 00687c70  56                   push esi
// 00687c71  8bf1                 mov esi, ecx
// 00687c73  8d4e04               lea ecx, [esi + 4]
// 00687c76  c7067cf9b800         mov dword ptr [esi], 0xb8f97c
// 00687c7c  e8df0ddaff           call 0x428a60
// 00687c81  f644240801           test byte ptr [esp + 8], 1
// 00687c86  7409                 je 0x687c91
// 00687c88  56                   push esi
// 00687c89  e886a42f00           call 0x982114
// 00687c8e  83c404               add esp, 4
// 00687c91  8bc6                 mov eax, esi
// 00687c93  5e                   pop esi
// 00687c94  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxvisualmanageroffice2007.cpp (function ??_GCMFCVisualManagerBitmapCacheItem@CMFCVisualManagerBitmapCache@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxvisualmanageroffice2007.cpp
