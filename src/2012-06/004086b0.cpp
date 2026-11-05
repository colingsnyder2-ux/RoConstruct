// from server: 100% by auto
// roc 2012-06 004086b0  unit: VCApp::?$CComAggObject  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004086b0
//
// 004086b0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 004086b4  834104ff             add dword ptr [ecx + 4], -1
// 004086b8  56                   push esi
// 004086b9  8b7104               mov esi, dword ptr [ecx + 4]
// 004086bc  750d                 jne 0x4086cb
// 004086be  85c9                 test ecx, ecx
// 004086c0  7409                 je 0x4086cb
// 004086c2  8b01                 mov eax, dword ptr [ecx]
// 004086c4  8b500c               mov edx, dword ptr [eax + 0xc]
// 004086c7  6a01                 push 1
// 004086c9  ffd2                 call edx
// 004086cb  8bc6                 mov eax, esi
// 004086cd  5e                   pop esi
// 004086ce  c20400               ret 4
// library atl-8.0/atl.cpp (function ?Release@?$CComPolyObject@VCAxHostWindow@ATL@@@ATL@@UAGKXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
