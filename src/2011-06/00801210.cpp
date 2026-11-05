// from server: 100% by auto
// roc 2011-06 00801210  unit: RBX::Tasks::SequenceBase  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00801210
//
// 00801210  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00801214  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00801218  8b542404             mov edx, dword ptr [esp + 4]
// 0080121c  50                   push eax
// 0080121d  51                   push ecx
// 0080121e  52                   push edx
// 0080121f  ff155c03a400         call dword ptr [0xa4035c]
// 00801225  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\ctlcore.cpp (function ?SetWindowLongPtrA@@YAJPAUHWND__@@HJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/ctlcore.cpp
