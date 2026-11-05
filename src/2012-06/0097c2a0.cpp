// from server: 100% by auto
// roc 2012-06 0097c2a0  unit: RBX::Tasks::SequenceBase  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0097c2a0
//
// 0097c2a0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0097c2a4  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0097c2a8  8b542404             mov edx, dword ptr [esp + 4]
// 0097c2ac  50                   push eax
// 0097c2ad  51                   push ecx
// 0097c2ae  52                   push edx
// 0097c2af  ff15f821b200         call dword ptr [0xb221f8]
// 0097c2b5  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\ctlcore.cpp (function ?SetWindowLongPtrA@@YAJPAUHWND__@@HJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/ctlcore.cpp
