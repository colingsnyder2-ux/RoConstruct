// from server: 100% by auto
// roc 2008-06 006ba660  unit: CXTPPropertyGridItemConstraint  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006ba660
//
// 006ba660  8b44240c             mov eax, dword ptr [esp + 0xc]
// 006ba664  8b542404             mov edx, dword ptr [esp + 4]
// 006ba668  56                   push esi
// 006ba669  50                   push eax
// 006ba66a  8b4204               mov eax, dword ptr [edx + 4]
// 006ba66d  8bf1                 mov esi, ecx
// 006ba66f  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 006ba673  51                   push ecx
// 006ba674  50                   push eax
// 006ba675  ff159c208000         call dword ptr [0x80209c]
// 006ba67b  50                   push eax
// 006ba67c  8bce                 mov ecx, esi
// 006ba67e  e8df65feff           call 0x6a0c62
// 006ba683  5e                   pop esi
// 006ba684  c20c00               ret 0xc
// library mfc-9.0/atlmfc\src\mfc\afxcolorpickerctrl.cpp (function ?CreateCompatibleBitmap@CBitmap@@QAEHPAVCDC@@HH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxcolorpickerctrl.cpp
