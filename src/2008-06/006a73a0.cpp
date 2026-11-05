// from server: 100% by auto
// roc 2008-06 006a73a0  unit: CEdit  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006a73a0
//
// 006a73a0  8b442408             mov eax, dword ptr [esp + 8]
// 006a73a4  8b542404             mov edx, dword ptr [esp + 4]
// 006a73a8  50                   push eax
// 006a73a9  8b4120               mov eax, dword ptr [ecx + 0x20]
// 006a73ac  52                   push edx
// 006a73ad  68b0000000           push 0xb0
// 006a73b2  50                   push eax
// 006a73b3  ff15142e8000         call dword ptr [0x802e14]
// 006a73b9  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxmaskededit.cpp (function ?GetSel@CEdit@@QBEXAAH0@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxmaskededit.cpp
