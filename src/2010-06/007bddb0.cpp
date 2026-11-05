// from server: 100% by auto
// roc 2010-06 007bddb0  unit: CXTPCommandBar  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007bddb0
//
// 007bddb0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007bddb4  8b542404             mov edx, dword ptr [esp + 4]
// 007bddb8  56                   push esi
// 007bddb9  50                   push eax
// 007bddba  8b4204               mov eax, dword ptr [edx + 4]
// 007bddbd  8bf1                 mov esi, ecx
// 007bddbf  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007bddc3  51                   push ecx
// 007bddc4  50                   push eax
// 007bddc5  ff15c4a09e00         call dword ptr [0x9ea0c4]
// 007bddcb  50                   push eax
// 007bddcc  8bce                 mov ecx, esi
// 007bddce  e897a1feff           call 0x7a7f6a
// 007bddd3  5e                   pop esi
// 007bddd4  c20c00               ret 0xc
// library mfc-9.0/atlmfc\src\mfc\afxcolorpickerctrl.cpp (function ?CreateCompatibleBitmap@CBitmap@@QAEHPAVCDC@@HH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxcolorpickerctrl.cpp
