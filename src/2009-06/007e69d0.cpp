// from server: 100% by auto
// roc 2009-06 007e69d0  unit: CXTPImageEditorPicker  size: 66 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007e69d0
//
// 007e69d0  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 007e69d4  85c0                 test eax, eax
// 007e69d6  7504                 jne 0x7e69dc
// 007e69d8  33d2                 xor edx, edx
// 007e69da  eb03                 jmp 0x7e69df
// 007e69dc  8b5004               mov edx, dword ptr [eax + 4]
// 007e69df  8b4104               mov eax, dword ptr [ecx + 4]
// 007e69e2  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 007e69e6  83c903               or ecx, 3
// 007e69e9  51                   push ecx
// 007e69ea  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 007e69ee  51                   push ecx
// 007e69ef  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 007e69f3  51                   push ecx
// 007e69f4  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 007e69f8  51                   push ecx
// 007e69f9  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 007e69fd  51                   push ecx
// 007e69fe  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 007e6a02  6a00                 push 0
// 007e6a04  51                   push ecx
// 007e6a05  6a00                 push 0
// 007e6a07  52                   push edx
// 007e6a08  50                   push eax
// 007e6a09  ff150cef8900         call dword ptr [0x89ef0c]
// 007e6a0f  c21c00               ret 0x1c
// library mfc-9.0/atlmfc\src\mfc\afxtoolbarimages.cpp (function ?DrawState@CDC@@QAEHVCPoint@@VCSize@@PAUHICON__@@IPAVCBrush@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxtoolbarimages.cpp
