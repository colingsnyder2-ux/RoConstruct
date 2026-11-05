// from server: 100% by auto
// roc 2011-06 008b7870  unit: CXTPReportHeaderDropWnd  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008b7870
//
// 008b7870  8b442408             mov eax, dword ptr [esp + 8]
// 008b7874  85c0                 test eax, eax
// 008b7876  7504                 jne 0x8b787c
// 008b7878  33d2                 xor edx, edx
// 008b787a  eb03                 jmp 0x8b787f
// 008b787c  8b5004               mov edx, dword ptr [eax + 4]
// 008b787f  8b442404             mov eax, dword ptr [esp + 4]
// 008b7883  85c0                 test eax, eax
// 008b7885  7403                 je 0x8b788a
// 008b7887  8b4004               mov eax, dword ptr [eax + 4]
// 008b788a  56                   push esi
// 008b788b  8b742410             mov esi, dword ptr [esp + 0x10]
// 008b788f  56                   push esi
// 008b7890  52                   push edx
// 008b7891  50                   push eax
// 008b7892  8b4104               mov eax, dword ptr [ecx + 4]
// 008b7895  50                   push eax
// 008b7896  ff15ac00a400         call dword ptr [0xa400ac]
// 008b789c  5e                   pop esi
// 008b789d  c20c00               ret 0xc
// library mfc-9.0/atlmfc\src\mfc\afxsmartdockingguide.cpp (function ?CombineRgn@CRgn@@QAEHPBV1@0H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxsmartdockingguide.cpp
