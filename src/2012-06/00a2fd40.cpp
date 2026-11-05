// from server: 100% by auto
// roc 2012-06 00a2fd40  unit: CXTPReportHeaderDropWnd  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a2fd40
//
// 00a2fd40  8b442408             mov eax, dword ptr [esp + 8]
// 00a2fd44  85c0                 test eax, eax
// 00a2fd46  7504                 jne 0xa2fd4c
// 00a2fd48  33d2                 xor edx, edx
// 00a2fd4a  eb03                 jmp 0xa2fd4f
// 00a2fd4c  8b5004               mov edx, dword ptr [eax + 4]
// 00a2fd4f  8b442404             mov eax, dword ptr [esp + 4]
// 00a2fd53  85c0                 test eax, eax
// 00a2fd55  7403                 je 0xa2fd5a
// 00a2fd57  8b4004               mov eax, dword ptr [eax + 4]
// 00a2fd5a  56                   push esi
// 00a2fd5b  8b742410             mov esi, dword ptr [esp + 0x10]
// 00a2fd5f  56                   push esi
// 00a2fd60  52                   push edx
// 00a2fd61  50                   push eax
// 00a2fd62  8b4104               mov eax, dword ptr [ecx + 4]
// 00a2fd65  50                   push eax
// 00a2fd66  ff151421b200         call dword ptr [0xb22114]
// 00a2fd6c  5e                   pop esi
// 00a2fd6d  c20c00               ret 0xc
// library mfc-9.0/atlmfc\src\mfc\afxsmartdockingguide.cpp (function ?CombineRgn@CRgn@@QAEHPBV1@0H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxsmartdockingguide.cpp
