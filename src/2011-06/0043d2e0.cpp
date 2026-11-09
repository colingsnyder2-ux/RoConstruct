// from server: 100% by auto
// roc 2011-06 0043d2e0  unit: RBX::Reflection::VValue::PAV?$vector::?$sp_counted_impl_pd  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0043d2e0
//
// 0043d2e0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0043d2e4  8b542408             mov edx, dword ptr [esp + 8]
// 0043d2e8  8b4920               mov ecx, dword ptr [ecx + 0x20]
// 0043d2eb  50                   push eax
// 0043d2ec  8b442408             mov eax, dword ptr [esp + 8]
// 0043d2f0  52                   push edx
// 0043d2f1  50                   push eax
// 0043d2f2  51                   push ecx
// 0043d2f3  ff15c019a400         call dword ptr [0xa419c0]
// 0043d2f9  c20c00               ret 0xc
// library mfc-9.0/atlmfc\src\mfc\afxautohidebar.cpp (function ?SetTimer@CWnd@@QAEIIIP6GXPAUHWND__@@IIK@Z@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxautohidebar.cpp
