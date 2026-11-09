// from server: 100% by auto
// roc 2009-06 00732d20  unit: CXTPImageManagerResource::CBitmapDC  size: 60 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00732d20
//
// 00732d20  8b442404             mov eax, dword ptr [esp + 4]
// 00732d24  85c0                 test eax, eax
// 00732d26  7403                 je 0x732d2b
// 00732d28  8b4004               mov eax, dword ptr [eax + 4]
// 00732d2b  8b542420             mov edx, dword ptr [esp + 0x20]
// 00732d2f  52                   push edx
// 00732d30  8b542420             mov edx, dword ptr [esp + 0x20]
// 00732d34  52                   push edx
// 00732d35  8b542420             mov edx, dword ptr [esp + 0x20]
// 00732d39  52                   push edx
// 00732d3a  8b542420             mov edx, dword ptr [esp + 0x20]
// 00732d3e  52                   push edx
// 00732d3f  8b542420             mov edx, dword ptr [esp + 0x20]
// 00732d43  52                   push edx
// 00732d44  8b542420             mov edx, dword ptr [esp + 0x20]
// 00732d48  52                   push edx
// 00732d49  8b542420             mov edx, dword ptr [esp + 0x20]
// 00732d4d  52                   push edx
// 00732d4e  50                   push eax
// 00732d4f  8b4104               mov eax, dword ptr [ecx + 4]
// 00732d52  50                   push eax
// 00732d53  ff1518ef8900         call dword ptr [0x89ef18]
// 00732d59  c22000               ret 0x20
// library mfc-9.0/atlmfc\src\mfc\ctlnownd.cpp (function ?GrayStringA@CDC@@UAEHPAVCBrush@@P6GHPAUHDC__@@JH@ZJHHHHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/ctlnownd.cpp
