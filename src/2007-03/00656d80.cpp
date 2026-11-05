// from server: 100% by auto
// roc 2007-03 00656d80  unit: seg_00650000  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00656d80
//
// 00656d80  8b442404             mov eax, dword ptr [esp + 4]
// 00656d84  85c0                 test eax, eax
// 00656d86  7514                 jne 0x656d9c
// 00656d88  50                   push eax
// 00656d89  8b4120               mov eax, dword ptr [ecx + 0x20]
// 00656d8c  50                   push eax
// 00656d8d  ff1574ef7700         call dword ptr [0x77ef74]
// 00656d93  89442404             mov dword ptr [esp + 4], eax
// 00656d97  e9b278fcff           jmp 0x61e64e
// 00656d9c  8b4020               mov eax, dword ptr [eax + 0x20]
// 00656d9f  50                   push eax
// 00656da0  8b4120               mov eax, dword ptr [ecx + 0x20]
// 00656da3  50                   push eax
// 00656da4  ff1574ef7700         call dword ptr [0x77ef74]
// 00656daa  89442404             mov dword ptr [esp + 4], eax
// 00656dae  e99b78fcff           jmp 0x61e64e
// library mfc-8.0/atlmfc\src\mfc\bardock.cpp (function ?SetParent@CWnd@@QAEPAV1@PAV1@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/bardock.cpp
