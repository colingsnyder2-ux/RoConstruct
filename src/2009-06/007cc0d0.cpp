// from server: 100% by auto
// roc 2009-06 007cc0d0  unit: CXTPReportHeaderDropWnd  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007cc0d0
//
// 007cc0d0  8b442408             mov eax, dword ptr [esp + 8]
// 007cc0d4  85c0                 test eax, eax
// 007cc0d6  7504                 jne 0x7cc0dc
// 007cc0d8  33d2                 xor edx, edx
// 007cc0da  eb03                 jmp 0x7cc0df
// 007cc0dc  8b5004               mov edx, dword ptr [eax + 4]
// 007cc0df  8b442404             mov eax, dword ptr [esp + 4]
// 007cc0e3  85c0                 test eax, eax
// 007cc0e5  7403                 je 0x7cc0ea
// 007cc0e7  8b4004               mov eax, dword ptr [eax + 4]
// 007cc0ea  56                   push esi
// 007cc0eb  8b742410             mov esi, dword ptr [esp + 0x10]
// 007cc0ef  56                   push esi
// 007cc0f0  52                   push edx
// 007cc0f1  50                   push eax
// 007cc0f2  8b4104               mov eax, dword ptr [ecx + 4]
// 007cc0f5  50                   push eax
// 007cc0f6  ff150ce18900         call dword ptr [0x89e10c]
// 007cc0fc  5e                   pop esi
// 007cc0fd  c20c00               ret 0xc
// library mfc-9.0/atlmfc\src\mfc\afxsmartdockingguide.cpp (function ?CombineRgn@CRgn@@QAEHPBV1@0H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxsmartdockingguide.cpp
