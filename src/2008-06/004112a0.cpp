// from server: 100% by auto
// roc 2008-06 004112a0  unit: boost::bad_weak_ptr  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004112a0
//
// 004112a0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 004112a4  8b542408             mov edx, dword ptr [esp + 8]
// 004112a8  8b4920               mov ecx, dword ptr [ecx + 0x20]
// 004112ab  50                   push eax
// 004112ac  8b442408             mov eax, dword ptr [esp + 8]
// 004112b0  52                   push edx
// 004112b1  50                   push eax
// 004112b2  51                   push ecx
// 004112b3  ff150c2e8000         call dword ptr [0x802e0c]
// 004112b9  c20c00               ret 0xc
// library mfc-9.0/atlmfc\src\mfc\afxautohidebar.cpp (function ?SetTimer@CWnd@@QAEIIIP6GXPAUHWND__@@IIK@Z@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxautohidebar.cpp
