// from server: 100% by auto
// roc 2010-06 007b48a0  unit: CEdit  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007b48a0
//
// 007b48a0  8b442408             mov eax, dword ptr [esp + 8]
// 007b48a4  8b542404             mov edx, dword ptr [esp + 4]
// 007b48a8  50                   push eax
// 007b48a9  8b4120               mov eax, dword ptr [ecx + 0x20]
// 007b48ac  52                   push edx
// 007b48ad  68b0000000           push 0xb0
// 007b48b2  50                   push eax
// 007b48b3  ff1554ba9e00         call dword ptr [0x9eba54]
// 007b48b9  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxmaskededit.cpp (function ?GetSel@CEdit@@QBEXAAH0@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxmaskededit.cpp
