// from server: 100% by auto
// roc 2009-12 00809ca0  unit: CXTPImageManagerResource::CBitmapDC  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00809ca0
//
// 00809ca0  8b442404             mov eax, dword ptr [esp + 4]
// 00809ca4  8b4904               mov ecx, dword ptr [ecx + 4]
// 00809ca7  50                   push eax
// 00809ca8  51                   push ecx
// 00809ca9  ff15f0b09800         call dword ptr [0x98b0f0]
// 00809caf  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\ctlcore.cpp (function ?GetMenuItemID@CMenu@@QBEIH@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/ctlcore.cpp
