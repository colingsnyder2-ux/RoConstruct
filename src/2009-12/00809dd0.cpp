// from server: 100% by auto
// roc 2009-12 00809dd0  unit: CXTPImageManagerResource::CBitmapDC  size: 60 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00809dd0
//
// 00809dd0  8b442404             mov eax, dword ptr [esp + 4]
// 00809dd4  85c0                 test eax, eax
// 00809dd6  7403                 je 0x809ddb
// 00809dd8  8b4004               mov eax, dword ptr [eax + 4]
// 00809ddb  8b542420             mov edx, dword ptr [esp + 0x20]
// 00809ddf  52                   push edx
// 00809de0  8b542420             mov edx, dword ptr [esp + 0x20]
// 00809de4  52                   push edx
// 00809de5  8b542420             mov edx, dword ptr [esp + 0x20]
// 00809de9  52                   push edx
// 00809dea  8b542420             mov edx, dword ptr [esp + 0x20]
// 00809dee  52                   push edx
// 00809def  8b542420             mov edx, dword ptr [esp + 0x20]
// 00809df3  52                   push edx
// 00809df4  8b542420             mov edx, dword ptr [esp + 0x20]
// 00809df8  52                   push edx
// 00809df9  8b542420             mov edx, dword ptr [esp + 0x20]
// 00809dfd  52                   push edx
// 00809dfe  50                   push eax
// 00809dff  8b4104               mov eax, dword ptr [ecx + 4]
// 00809e02  50                   push eax
// 00809e03  ff1504cb9800         call dword ptr [0x98cb04]
// 00809e09  c22000               ret 0x20
// library mfc-8.0/atlmfc\src\mfc\ctlnownd.cpp (function ?GrayStringA@CDC@@UAEHPAVCBrush@@P6GHPAUHDC__@@JH@ZJHHHHH@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/ctlnownd.cpp
