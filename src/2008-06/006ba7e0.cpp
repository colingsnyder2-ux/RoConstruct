// from server: 100% by auto
// roc 2008-06 006ba7e0  unit: CXTPImageManagerResource::CBitmapDC  size: 60 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006ba7e0
//
// 006ba7e0  8b442404             mov eax, dword ptr [esp + 4]
// 006ba7e4  85c0                 test eax, eax
// 006ba7e6  7403                 je 0x6ba7eb
// 006ba7e8  8b4004               mov eax, dword ptr [eax + 4]
// 006ba7eb  8b542420             mov edx, dword ptr [esp + 0x20]
// 006ba7ef  52                   push edx
// 006ba7f0  8b542420             mov edx, dword ptr [esp + 0x20]
// 006ba7f4  52                   push edx
// 006ba7f5  8b542420             mov edx, dword ptr [esp + 0x20]
// 006ba7f9  52                   push edx
// 006ba7fa  8b542420             mov edx, dword ptr [esp + 0x20]
// 006ba7fe  52                   push edx
// 006ba7ff  8b542420             mov edx, dword ptr [esp + 0x20]
// 006ba803  52                   push edx
// 006ba804  8b542420             mov edx, dword ptr [esp + 0x20]
// 006ba808  52                   push edx
// 006ba809  8b542420             mov edx, dword ptr [esp + 0x20]
// 006ba80d  52                   push edx
// 006ba80e  50                   push eax
// 006ba80f  8b4104               mov eax, dword ptr [ecx + 4]
// 006ba812  50                   push eax
// 006ba813  ff15842b8000         call dword ptr [0x802b84]
// 006ba819  c22000               ret 0x20
// library mfc-9.0/atlmfc\src\mfc\ctlnownd.cpp (function ?GrayStringA@CDC@@UAEHPAVCBrush@@P6GHPAUHDC__@@JH@ZJHHHHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/ctlnownd.cpp
