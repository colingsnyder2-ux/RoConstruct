// from server: 100% by auto
// roc 2010-06 007bdf30  unit: CXTPImageManagerResource::CBitmapDC  size: 60 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007bdf30
//
// 007bdf30  8b442404             mov eax, dword ptr [esp + 4]
// 007bdf34  85c0                 test eax, eax
// 007bdf36  7403                 je 0x7bdf3b
// 007bdf38  8b4004               mov eax, dword ptr [eax + 4]
// 007bdf3b  8b542420             mov edx, dword ptr [esp + 0x20]
// 007bdf3f  52                   push edx
// 007bdf40  8b542420             mov edx, dword ptr [esp + 0x20]
// 007bdf44  52                   push edx
// 007bdf45  8b542420             mov edx, dword ptr [esp + 0x20]
// 007bdf49  52                   push edx
// 007bdf4a  8b542420             mov edx, dword ptr [esp + 0x20]
// 007bdf4e  52                   push edx
// 007bdf4f  8b542420             mov edx, dword ptr [esp + 0x20]
// 007bdf53  52                   push edx
// 007bdf54  8b542420             mov edx, dword ptr [esp + 0x20]
// 007bdf58  52                   push edx
// 007bdf59  8b542420             mov edx, dword ptr [esp + 0x20]
// 007bdf5d  52                   push edx
// 007bdf5e  50                   push eax
// 007bdf5f  8b4104               mov eax, dword ptr [ecx + 4]
// 007bdf62  50                   push eax
// 007bdf63  ff15bcb99e00         call dword ptr [0x9eb9bc]
// 007bdf69  c22000               ret 0x20
// library mfc-9.0/atlmfc\src\mfc\ctlnownd.cpp (function ?GrayStringA@CDC@@UAEHPAVCBrush@@P6GHPAUHDC__@@JH@ZJHHHHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/ctlnownd.cpp
