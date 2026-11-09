// from server: 100% by auto
// roc 2010-06 008756a0  unit: CXTPImageEditorPicker  size: 66 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008756a0
//
// 008756a0  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 008756a4  85c0                 test eax, eax
// 008756a6  7504                 jne 0x8756ac
// 008756a8  33d2                 xor edx, edx
// 008756aa  eb03                 jmp 0x8756af
// 008756ac  8b5004               mov edx, dword ptr [eax + 4]
// 008756af  8b4104               mov eax, dword ptr [ecx + 4]
// 008756b2  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 008756b6  83c903               or ecx, 3
// 008756b9  51                   push ecx
// 008756ba  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 008756be  51                   push ecx
// 008756bf  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 008756c3  51                   push ecx
// 008756c4  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 008756c8  51                   push ecx
// 008756c9  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 008756cd  51                   push ecx
// 008756ce  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 008756d2  6a00                 push 0
// 008756d4  51                   push ecx
// 008756d5  6a00                 push 0
// 008756d7  52                   push edx
// 008756d8  50                   push eax
// 008756d9  ff15a8ba9e00         call dword ptr [0x9ebaa8]
// 008756df  c21c00               ret 0x1c
// library mfc-9.0/atlmfc\src\mfc\afxtoolbarimages.cpp (function ?DrawState@CDC@@QAEHVCPoint@@VCSize@@PAUHICON__@@IPAVCBrush@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxtoolbarimages.cpp
