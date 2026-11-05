// from server: 100% by auto
// roc 2009-12 008c1490  unit: CXTPImageEditorPicker  size: 66 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008c1490
//
// 008c1490  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 008c1494  85c0                 test eax, eax
// 008c1496  7504                 jne 0x8c149c
// 008c1498  33d2                 xor edx, edx
// 008c149a  eb03                 jmp 0x8c149f
// 008c149c  8b5004               mov edx, dword ptr [eax + 4]
// 008c149f  8b4104               mov eax, dword ptr [ecx + 4]
// 008c14a2  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 008c14a6  83c903               or ecx, 3
// 008c14a9  51                   push ecx
// 008c14aa  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 008c14ae  51                   push ecx
// 008c14af  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 008c14b3  51                   push ecx
// 008c14b4  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 008c14b8  51                   push ecx
// 008c14b9  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 008c14bd  51                   push ecx
// 008c14be  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 008c14c2  6a00                 push 0
// 008c14c4  51                   push ecx
// 008c14c5  6a00                 push 0
// 008c14c7  52                   push edx
// 008c14c8  50                   push eax
// 008c14c9  ff15f8ca9800         call dword ptr [0x98caf8]
// 008c14cf  c21c00               ret 0x1c
// library mfc-9.0/atlmfc\src\mfc\afxtoolbarimages.cpp (function ?DrawState@CDC@@QAEHVCPoint@@VCSize@@PAUHICON__@@IPAVCBrush@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxtoolbarimages.cpp
