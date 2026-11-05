// from server: 100% by auto
// roc 2010-06 00545530  unit: RBX::RenderSceneBase  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00545530
//
// 00545530  56                   push esi
// 00545531  8bf1                 mov esi, ecx
// 00545533  8d4e04               lea ecx, [esi + 4]
// 00545536  c706fcf2a100         mov dword ptr [esi], 0xa1f2fc
// 0054553c  e83ffaffff           call 0x544f80
// 00545541  f644240801           test byte ptr [esp + 8], 1
// 00545546  7409                 je 0x545551
// 00545548  56                   push esi
// 00545549  e84c242600           call 0x7a799a
// 0054554e  83c404               add esp, 4
// 00545551  8bc6                 mov eax, esi
// 00545553  5e                   pop esi
// 00545554  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxvisualmanageroffice2007.cpp (function ??_GCMFCVisualManagerBitmapCacheItem@CMFCVisualManagerBitmapCache@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxvisualmanageroffice2007.cpp
