// from server: 100% by auto
// roc 2007-03 00620d30  unit: seg_00620000  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00620d30
//
// 00620d30  8b442408             mov eax, dword ptr [esp + 8]
// 00620d34  8b542404             mov edx, dword ptr [esp + 4]
// 00620d38  50                   push eax
// 00620d39  8b4120               mov eax, dword ptr [ecx + 0x20]
// 00620d3c  52                   push edx
// 00620d3d  68b0000000           push 0xb0
// 00620d42  50                   push eax
// 00620d43  ff1550ee7700         call dword ptr [0x77ee50]
// 00620d49  c20800               ret 8
// library mfc-8.0/atlmfc\src\mfc\viewedit.cpp (function ?GetSel@CEdit@@QBEXAAH0@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/viewedit.cpp
