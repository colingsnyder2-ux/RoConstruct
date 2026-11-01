// from server: 100% by auto
// roc 2007-03 006e00c0  unit: seg_006e0000  size: 66 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006e00c0
//
// 006e00c0  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006e00c4  85c0                 test eax, eax
// 006e00c6  7504                 jne 0x6e00cc
// 006e00c8  33d2                 xor edx, edx
// 006e00ca  eb03                 jmp 0x6e00cf
// 006e00cc  8b5004               mov edx, dword ptr [eax + 4]
// 006e00cf  8b4104               mov eax, dword ptr [ecx + 4]
// 006e00d2  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 006e00d6  83c903               or ecx, 3
// 006e00d9  51                   push ecx
// 006e00da  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 006e00de  51                   push ecx
// 006e00df  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 006e00e3  51                   push ecx
// 006e00e4  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 006e00e8  51                   push ecx
// 006e00e9  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 006e00ed  51                   push ecx
// 006e00ee  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 006e00f2  6a00                 push 0
// 006e00f4  51                   push ecx
// 006e00f5  6a00                 push 0
// 006e00f7  52                   push edx
// 006e00f8  50                   push eax
// 006e00f9  ff15f4ee7700         call dword ptr [0x77eef4]
// 006e00ff  c21c00               ret 0x1c
// library mfc-9.0/atlmfc\src\mfc\afxtoolbarimages.cpp (function ?DrawState@CDC@@QAEHVCPoint@@VCSize@@PAUHICON__@@IPAVCBrush@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxtoolbarimages.cpp
