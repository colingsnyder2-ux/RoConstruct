// from server: 100% by auto
// roc 2007-08 006f0f80  unit: CXTPImageEditorPicker  size: 66 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006f0f80
//
// 006f0f80  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006f0f84  85c0                 test eax, eax
// 006f0f86  7504                 jne 0x6f0f8c
// 006f0f88  33d2                 xor edx, edx
// 006f0f8a  eb03                 jmp 0x6f0f8f
// 006f0f8c  8b5004               mov edx, dword ptr [eax + 4]
// 006f0f8f  8b4104               mov eax, dword ptr [ecx + 4]
// 006f0f92  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 006f0f96  83c903               or ecx, 3
// 006f0f99  51                   push ecx
// 006f0f9a  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 006f0f9e  51                   push ecx
// 006f0f9f  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 006f0fa3  51                   push ecx
// 006f0fa4  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 006f0fa8  51                   push ecx
// 006f0fa9  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 006f0fad  51                   push ecx
// 006f0fae  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 006f0fb2  6a00                 push 0
// 006f0fb4  51                   push ecx
// 006f0fb5  6a00                 push 0
// 006f0fb7  52                   push edx
// 006f0fb8  50                   push eax
// 006f0fb9  ff1578ee7700         call dword ptr [0x77ee78]
// 006f0fbf  c21c00               ret 0x1c
// library mfc-9.0/atlmfc\src\mfc\afxtoolbarimages.cpp (function ?DrawState@CDC@@QAEHVCPoint@@VCSize@@PAUHICON__@@IPAVCBrush@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxtoolbarimages.cpp
