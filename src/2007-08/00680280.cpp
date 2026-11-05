// from server: 100% by auto
// roc 2007-08 00680280  unit: CXTPBufferDC  size: 60 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00680280
//
// 00680280  8b442404             mov eax, dword ptr [esp + 4]
// 00680284  85c0                 test eax, eax
// 00680286  7403                 je 0x68028b
// 00680288  8b4004               mov eax, dword ptr [eax + 4]
// 0068028b  8b542420             mov edx, dword ptr [esp + 0x20]
// 0068028f  52                   push edx
// 00680290  8b542420             mov edx, dword ptr [esp + 0x20]
// 00680294  52                   push edx
// 00680295  8b542420             mov edx, dword ptr [esp + 0x20]
// 00680299  52                   push edx
// 0068029a  8b542420             mov edx, dword ptr [esp + 0x20]
// 0068029e  52                   push edx
// 0068029f  8b542420             mov edx, dword ptr [esp + 0x20]
// 006802a3  52                   push edx
// 006802a4  8b542420             mov edx, dword ptr [esp + 0x20]
// 006802a8  52                   push edx
// 006802a9  8b542420             mov edx, dword ptr [esp + 0x20]
// 006802ad  52                   push edx
// 006802ae  50                   push eax
// 006802af  8b4104               mov eax, dword ptr [ecx + 4]
// 006802b2  50                   push eax
// 006802b3  ff15c0ec7700         call dword ptr [0x77ecc0]
// 006802b9  c22000               ret 0x20
// library mfc-8.0/atlmfc\src\mfc\ctlnownd.cpp (function ?GrayStringA@CDC@@UAEHPAVCBrush@@P6GHPAUHDC__@@JH@ZJHHHHH@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/ctlnownd.cpp
