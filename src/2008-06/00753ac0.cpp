// from server: 100% by auto
// roc 2008-06 00753ac0  unit: CXTPReportHeaderDropWnd  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00753ac0
//
// 00753ac0  8b442408             mov eax, dword ptr [esp + 8]
// 00753ac4  85c0                 test eax, eax
// 00753ac6  7504                 jne 0x753acc
// 00753ac8  33d2                 xor edx, edx
// 00753aca  eb03                 jmp 0x753acf
// 00753acc  8b5004               mov edx, dword ptr [eax + 4]
// 00753acf  8b442404             mov eax, dword ptr [esp + 4]
// 00753ad3  85c0                 test eax, eax
// 00753ad5  7403                 je 0x753ada
// 00753ad7  8b4004               mov eax, dword ptr [eax + 4]
// 00753ada  56                   push esi
// 00753adb  8b742410             mov esi, dword ptr [esp + 0x10]
// 00753adf  56                   push esi
// 00753ae0  52                   push edx
// 00753ae1  50                   push eax
// 00753ae2  8b4104               mov eax, dword ptr [ecx + 4]
// 00753ae5  50                   push eax
// 00753ae6  ff15f4208000         call dword ptr [0x8020f4]
// 00753aec  5e                   pop esi
// 00753aed  c20c00               ret 0xc
// library mfc-9.0/atlmfc\src\mfc\afxsmartdockingguide.cpp (function ?CombineRgn@CRgn@@QAEHPBV1@0H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxsmartdockingguide.cpp
