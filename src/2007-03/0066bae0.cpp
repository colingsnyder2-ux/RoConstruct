// from server: 100% by auto
// roc 2007-03 0066bae0  unit: seg_00660000  size: 60 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0066bae0
//
// 0066bae0  8b442404             mov eax, dword ptr [esp + 4]
// 0066bae4  85c0                 test eax, eax
// 0066bae6  7403                 je 0x66baeb
// 0066bae8  8b4004               mov eax, dword ptr [eax + 4]
// 0066baeb  8b542420             mov edx, dword ptr [esp + 0x20]
// 0066baef  52                   push edx
// 0066baf0  8b542420             mov edx, dword ptr [esp + 0x20]
// 0066baf4  52                   push edx
// 0066baf5  8b542420             mov edx, dword ptr [esp + 0x20]
// 0066baf9  52                   push edx
// 0066bafa  8b542420             mov edx, dword ptr [esp + 0x20]
// 0066bafe  52                   push edx
// 0066baff  8b542420             mov edx, dword ptr [esp + 0x20]
// 0066bb03  52                   push edx
// 0066bb04  8b542420             mov edx, dword ptr [esp + 0x20]
// 0066bb08  52                   push edx
// 0066bb09  8b542420             mov edx, dword ptr [esp + 0x20]
// 0066bb0d  52                   push edx
// 0066bb0e  50                   push eax
// 0066bb0f  8b4104               mov eax, dword ptr [ecx + 4]
// 0066bb12  50                   push eax
// 0066bb13  ff1590ef7700         call dword ptr [0x77ef90]
// 0066bb19  c22000               ret 0x20
// library mfc-8.0/atlmfc\src\mfc\ctlnownd.cpp (function ?GrayStringA@CDC@@UAEHPAVCBrush@@P6GHPAUHDC__@@JH@ZJHHHHH@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/ctlnownd.cpp
