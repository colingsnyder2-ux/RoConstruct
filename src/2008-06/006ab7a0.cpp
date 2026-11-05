// from server: 100% by auto
// roc 2008-06 006ab7a0  unit: CPatchedControlComboBox  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006ab7a0
//
// 006ab7a0  8b442404             mov eax, dword ptr [esp + 4]
// 006ab7a4  8b5004               mov edx, dword ptr [eax + 4]
// 006ab7a7  8b4120               mov eax, dword ptr [ecx + 0x20]
// 006ab7aa  52                   push edx
// 006ab7ab  50                   push eax
// 006ab7ac  ff15c02c8000         call dword ptr [0x802cc0]
// 006ab7b2  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\ctlnownd.cpp (function ?ReleaseDC@CWnd@@QAEHPAVCDC@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/ctlnownd.cpp
