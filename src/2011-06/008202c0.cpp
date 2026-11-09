// from server: 100% by auto
// roc 2011-06 008202c0  unit: CXTPImageManagerResource::CBitmapDC  size: 60 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008202c0
//
// 008202c0  8b442404             mov eax, dword ptr [esp + 4]
// 008202c4  85c0                 test eax, eax
// 008202c6  7403                 je 0x8202cb
// 008202c8  8b4004               mov eax, dword ptr [eax + 4]
// 008202cb  8b542420             mov edx, dword ptr [esp + 0x20]
// 008202cf  52                   push edx
// 008202d0  8b542420             mov edx, dword ptr [esp + 0x20]
// 008202d4  52                   push edx
// 008202d5  8b542420             mov edx, dword ptr [esp + 0x20]
// 008202d9  52                   push edx
// 008202da  8b542420             mov edx, dword ptr [esp + 0x20]
// 008202de  52                   push edx
// 008202df  8b542420             mov edx, dword ptr [esp + 0x20]
// 008202e3  52                   push edx
// 008202e4  8b542420             mov edx, dword ptr [esp + 0x20]
// 008202e8  52                   push edx
// 008202e9  8b542420             mov edx, dword ptr [esp + 0x20]
// 008202ed  52                   push edx
// 008202ee  50                   push eax
// 008202ef  8b4104               mov eax, dword ptr [ecx + 4]
// 008202f2  50                   push eax
// 008202f3  ff15d41aa400         call dword ptr [0xa41ad4]
// 008202f9  c22000               ret 0x20
// library mfc-9.0/atlmfc\src\mfc\ctlnownd.cpp (function ?GrayStringA@CDC@@UAEHPAVCBrush@@P6GHPAUHDC__@@JH@ZJHHHHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/ctlnownd.cpp
