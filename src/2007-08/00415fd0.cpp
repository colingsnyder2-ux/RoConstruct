// from server: 100% by tester
// roc 2007-03 004136b0  unit: seg_00410000  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 004136b0
//
// 004136b0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 004136b4  834104ff             add dword ptr [ecx + 4], -1
// 004136b8  56                   push esi
// 004136b9  8b7104               mov esi, dword ptr [ecx + 4]
// 004136bc  750d                 jne 0x4136cb
// 004136be  85c9                 test ecx, ecx
// 004136c0  7409                 je 0x4136cb
// 004136c2  8b01                 mov eax, dword ptr [ecx]
// 004136c4  8b500c               mov edx, dword ptr [eax + 0xc]
// 004136c7  6a01                 push 1
// 004136c9  ffd2                 call edx
// 004136cb  8bc6                 mov eax, esi
// 004136cd  5e                   pop esi
// 004136ce  c20400               ret 4
// library atl-8.0/atl.cpp (function ?Release@?$CComPolyObject@VCAxHostWindow@ATL@@@ATL@@UAGKXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
