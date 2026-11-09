// from server: 100% by auto
// roc 2011-06 0080cc40  unit: CPatchedControlComboBox  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0080cc40
//
// 0080cc40  8b442404             mov eax, dword ptr [esp + 4]
// 0080cc44  8b5004               mov edx, dword ptr [eax + 4]
// 0080cc47  8b4120               mov eax, dword ptr [ecx + 0x20]
// 0080cc4a  52                   push edx
// 0080cc4b  50                   push eax
// 0080cc4c  ff15dc19a400         call dword ptr [0xa419dc]
// 0080cc52  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\ctlnownd.cpp (function ?ReleaseDC@CWnd@@QAEHPAVCDC@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/ctlnownd.cpp
