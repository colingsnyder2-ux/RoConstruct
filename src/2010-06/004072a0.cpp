// from server: 100% by auto
// roc 2010-06 004072a0  unit: VCApp::?$CComAggObject  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004072a0
//
// 004072a0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 004072a4  834104ff             add dword ptr [ecx + 4], -1
// 004072a8  56                   push esi
// 004072a9  8b7104               mov esi, dword ptr [ecx + 4]
// 004072ac  750d                 jne 0x4072bb
// 004072ae  85c9                 test ecx, ecx
// 004072b0  7409                 je 0x4072bb
// 004072b2  8b01                 mov eax, dword ptr [ecx]
// 004072b4  8b500c               mov edx, dword ptr [eax + 0xc]
// 004072b7  6a01                 push 1
// 004072b9  ffd2                 call edx
// 004072bb  8bc6                 mov eax, esi
// 004072bd  5e                   pop esi
// 004072be  c20400               ret 4
// library atl-8.0/atl.cpp (function ?Release@?$CComPolyObject@VCAxHostWindow@ATL@@@ATL@@UAGKXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
