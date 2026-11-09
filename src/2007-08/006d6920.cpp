// from server: 100% by auto
// roc 2007-08 006d6920  unit: CXTPReportHeaderDropWnd  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006d6920
//
// 006d6920  8b442408             mov eax, dword ptr [esp + 8]
// 006d6924  85c0                 test eax, eax
// 006d6926  7504                 jne 0x6d692c
// 006d6928  33d2                 xor edx, edx
// 006d692a  eb03                 jmp 0x6d692f
// 006d692c  8b5004               mov edx, dword ptr [eax + 4]
// 006d692f  8b442404             mov eax, dword ptr [esp + 4]
// 006d6933  85c0                 test eax, eax
// 006d6935  7403                 je 0x6d693a
// 006d6937  8b4004               mov eax, dword ptr [eax + 4]
// 006d693a  56                   push esi
// 006d693b  8b742410             mov esi, dword ptr [esp + 0x10]
// 006d693f  56                   push esi
// 006d6940  52                   push edx
// 006d6941  50                   push eax
// 006d6942  8b4104               mov eax, dword ptr [ecx + 4]
// 006d6945  50                   push eax
// 006d6946  ff1590d07700         call dword ptr [0x77d090]
// 006d694c  5e                   pop esi
// 006d694d  c20c00               ret 0xc
// library mfc-8.0/atlmfc\src\mfc\wingdix.cpp (function ?CombineRgn@CRgn@@QAEHPBV1@0H@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/wingdix.cpp
