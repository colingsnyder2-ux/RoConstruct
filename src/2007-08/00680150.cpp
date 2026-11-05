// from server: 100% by auto
// roc 2007-08 00680150  unit: CXTPBufferDC  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00680150
//
// 00680150  8b442404             mov eax, dword ptr [esp + 4]
// 00680154  8b4904               mov ecx, dword ptr [ecx + 4]
// 00680157  50                   push eax
// 00680158  51                   push ecx
// 00680159  ff1570d07700         call dword ptr [0x77d070]
// 0068015f  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\ctlcore.cpp (function ?GetMenuItemID@CMenu@@QBEIH@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/ctlcore.cpp
