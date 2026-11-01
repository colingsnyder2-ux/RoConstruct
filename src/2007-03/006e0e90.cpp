// from server: 100% by auto
// roc 2007-03 006e0e90  unit: seg_006e0000  size: 75 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006e0e90
//
// 006e0e90  83ec0c               sub esp, 0xc
// 006e0e93  56                   push esi
// 006e0e94  8bf1                 mov esi, ecx
// 006e0e96  8b4620               mov eax, dword ptr [esi + 0x20]
// 006e0e99  89442404             mov dword ptr [esp + 4], eax
// 006e0e9d  c744240cfeffffff     mov dword ptr [esp + 0xc], 0xfffffffe
// 006e0ea5  e8589e0500           call 0x73ad02
// 006e0eaa  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 006e0ead  51                   push ecx
// 006e0eae  8944240c             mov dword ptr [esp + 0xc], eax
// 006e0eb2  ff15c8ec7700         call dword ptr [0x77ecc8]
// 006e0eb8  50                   push eax
// 006e0eb9  e890d7f3ff           call 0x61e64e
// 006e0ebe  8b4c2408             mov ecx, dword ptr [esp + 8]
// 006e0ec2  8d542404             lea edx, [esp + 4]
// 006e0ec6  52                   push edx
// 006e0ec7  8b5020               mov edx, dword ptr [eax + 0x20]
// 006e0eca  51                   push ecx
// 006e0ecb  6a4e                 push 0x4e
// 006e0ecd  52                   push edx
// 006e0ece  ff1550ee7700         call dword ptr [0x77ee50]
// 006e0ed4  5e                   pop esi
// 006e0ed5  83c40c               add esp, 0xc
// 006e0ed8  c20c00               ret 0xc
// library xtp-15.2.1/Source\CommandBars\XTPImageEditor.cpp (function ?OnLButtonDown@CXTPImageEditorPicker@@IAEXIVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPImageEditor.cpp
