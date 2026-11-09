// from server: 100% by auto
// roc 2009-12 008a6ed0  unit: CXTPReportHeaderDropWnd  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008a6ed0
//
// 008a6ed0  8b442408             mov eax, dword ptr [esp + 8]
// 008a6ed4  85c0                 test eax, eax
// 008a6ed6  7504                 jne 0x8a6edc
// 008a6ed8  33d2                 xor edx, edx
// 008a6eda  eb03                 jmp 0x8a6edf
// 008a6edc  8b5004               mov edx, dword ptr [eax + 4]
// 008a6edf  8b442404             mov eax, dword ptr [esp + 4]
// 008a6ee3  85c0                 test eax, eax
// 008a6ee5  7403                 je 0x8a6eea
// 008a6ee7  8b4004               mov eax, dword ptr [eax + 4]
// 008a6eea  56                   push esi
// 008a6eeb  8b742410             mov esi, dword ptr [esp + 0x10]
// 008a6eef  56                   push esi
// 008a6ef0  52                   push edx
// 008a6ef1  50                   push eax
// 008a6ef2  8b4104               mov eax, dword ptr [ecx + 4]
// 008a6ef5  50                   push eax
// 008a6ef6  ff15acb09800         call dword ptr [0x98b0ac]
// 008a6efc  5e                   pop esi
// 008a6efd  c20c00               ret 0xc
// library mfc-8.0/atlmfc\src\mfc\wingdix.cpp (function ?CombineRgn@CRgn@@QAEHPBV1@0H@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/wingdix.cpp
