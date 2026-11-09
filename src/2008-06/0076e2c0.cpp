// from server: 100% by auto
// roc 2008-06 0076e2c0  unit: CXTPImageEditorPicker  size: 66 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0076e2c0
//
// 0076e2c0  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0076e2c4  85c0                 test eax, eax
// 0076e2c6  7504                 jne 0x76e2cc
// 0076e2c8  33d2                 xor edx, edx
// 0076e2ca  eb03                 jmp 0x76e2cf
// 0076e2cc  8b5004               mov edx, dword ptr [eax + 4]
// 0076e2cf  8b4104               mov eax, dword ptr [ecx + 4]
// 0076e2d2  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0076e2d6  83c903               or ecx, 3
// 0076e2d9  51                   push ecx
// 0076e2da  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0076e2de  51                   push ecx
// 0076e2df  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0076e2e3  51                   push ecx
// 0076e2e4  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0076e2e8  51                   push ecx
// 0076e2e9  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0076e2ed  51                   push ecx
// 0076e2ee  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0076e2f2  6a00                 push 0
// 0076e2f4  51                   push ecx
// 0076e2f5  6a00                 push 0
// 0076e2f7  52                   push edx
// 0076e2f8  50                   push eax
// 0076e2f9  ff15782b8000         call dword ptr [0x802b78]
// 0076e2ff  c21c00               ret 0x1c
// library mfc-9.0/atlmfc\src\mfc\afxtoolbarimages.cpp (function ?DrawState@CDC@@QAEHVCPoint@@VCSize@@PAUHICON__@@IPAVCBrush@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxtoolbarimages.cpp
