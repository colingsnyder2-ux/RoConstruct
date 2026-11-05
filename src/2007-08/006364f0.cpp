// from server: 100% by auto
// roc 2007-08 006364f0  unit: CEdit  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006364f0
//
// 006364f0  8b442408             mov eax, dword ptr [esp + 8]
// 006364f4  8b542404             mov edx, dword ptr [esp + 4]
// 006364f8  50                   push eax
// 006364f9  8b4120               mov eax, dword ptr [ecx + 0x20]
// 006364fc  52                   push edx
// 006364fd  68b0000000           push 0xb0
// 00636502  50                   push eax
// 00636503  ff15d8ec7700         call dword ptr [0x77ecd8]
// 00636509  c20800               ret 8
// library mfc-8.0/atlmfc\src\mfc\viewedit.cpp (function ?GetSel@CEdit@@QBEXAAH0@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/viewedit.cpp
