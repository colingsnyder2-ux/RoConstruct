// from server: 100% by auto
// roc 2011-06 004625d0  unit: CRobloxApp  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 004625d0
//
// 004625d0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 004625d4  8b542404             mov edx, dword ptr [esp + 4]
// 004625d8  56                   push esi
// 004625d9  50                   push eax
// 004625da  8b4204               mov eax, dword ptr [edx + 4]
// 004625dd  8bf1                 mov esi, ecx
// 004625df  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004625e3  51                   push ecx
// 004625e4  50                   push eax
// 004625e5  ff158801a400         call dword ptr [0xa40188]
// 004625eb  50                   push eax
// 004625ec  8bce                 mov ecx, esi
// 004625ee  e835803a00           call 0x80a628
// 004625f3  5e                   pop esi
// 004625f4  c20c00               ret 0xc
// library mfc-9.0/atlmfc\src\mfc\afxcolorpickerctrl.cpp (function ?CreateCompatibleBitmap@CBitmap@@QAEHPAVCDC@@HH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxcolorpickerctrl.cpp
