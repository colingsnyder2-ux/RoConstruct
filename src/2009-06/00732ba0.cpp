// from server: 100% by auto
// roc 2009-06 00732ba0  unit: CXTPCommandBar  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00732ba0
//
// 00732ba0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00732ba4  8b542404             mov edx, dword ptr [esp + 4]
// 00732ba8  56                   push esi
// 00732ba9  50                   push eax
// 00732baa  8b4204               mov eax, dword ptr [edx + 4]
// 00732bad  8bf1                 mov esi, ecx
// 00732baf  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00732bb3  51                   push ecx
// 00732bb4  50                   push eax
// 00732bb5  ff15c0e08900         call dword ptr [0x89e0c0]
// 00732bbb  50                   push eax
// 00732bbc  8bce                 mov ecx, esi
// 00732bbe  e83f64feff           call 0x719002
// 00732bc3  5e                   pop esi
// 00732bc4  c20c00               ret 0xc
// library mfc-9.0/atlmfc\src\mfc\afxcolorpickerctrl.cpp (function ?CreateCompatibleBitmap@CBitmap@@QAEHPAVCDC@@HH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxcolorpickerctrl.cpp
