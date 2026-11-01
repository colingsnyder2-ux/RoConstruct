// from server: 100% by auto
// roc 2007-03 0066b9b0  unit: seg_00660000  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0066b9b0
//
// 0066b9b0  8b442404             mov eax, dword ptr [esp + 4]
// 0066b9b4  8b4904               mov ecx, dword ptr [ecx + 4]
// 0066b9b7  50                   push eax
// 0066b9b8  51                   push ecx
// 0066b9b9  ff154cd17700         call dword ptr [0x77d14c]
// 0066b9bf  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\ctlcore.cpp (function ?GetMenuItemID@CMenu@@QBEIH@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/ctlcore.cpp
