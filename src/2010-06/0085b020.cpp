// from server: 100% by auto
// roc 2010-06 0085b020  unit: CXTPReportHeaderDropWnd  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0085b020
//
// 0085b020  8b442408             mov eax, dword ptr [esp + 8]
// 0085b024  85c0                 test eax, eax
// 0085b026  7504                 jne 0x85b02c
// 0085b028  33d2                 xor edx, edx
// 0085b02a  eb03                 jmp 0x85b02f
// 0085b02c  8b5004               mov edx, dword ptr [eax + 4]
// 0085b02f  8b442404             mov eax, dword ptr [esp + 4]
// 0085b033  85c0                 test eax, eax
// 0085b035  7403                 je 0x85b03a
// 0085b037  8b4004               mov eax, dword ptr [eax + 4]
// 0085b03a  56                   push esi
// 0085b03b  8b742410             mov esi, dword ptr [esp + 0x10]
// 0085b03f  56                   push esi
// 0085b040  52                   push edx
// 0085b041  50                   push eax
// 0085b042  8b4104               mov eax, dword ptr [ecx + 4]
// 0085b045  50                   push eax
// 0085b046  ff15f4a09e00         call dword ptr [0x9ea0f4]
// 0085b04c  5e                   pop esi
// 0085b04d  c20c00               ret 0xc
// library mfc-9.0/atlmfc\src\mfc\afxsmartdockingguide.cpp (function ?CombineRgn@CRgn@@QAEHPBV1@0H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxsmartdockingguide.cpp
