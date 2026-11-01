// from server: 100% by auto
// roc 2009-06 004080a0  unit: VCApp::?$CComAggObject  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004080a0
//
// 004080a0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 004080a4  834104ff             add dword ptr [ecx + 4], -1
// 004080a8  56                   push esi
// 004080a9  8b7104               mov esi, dword ptr [ecx + 4]
// 004080ac  750d                 jne 0x4080bb
// 004080ae  85c9                 test ecx, ecx
// 004080b0  7409                 je 0x4080bb
// 004080b2  8b01                 mov eax, dword ptr [ecx]
// 004080b4  8b500c               mov edx, dword ptr [eax + 0xc]
// 004080b7  6a01                 push 1
// 004080b9  ffd2                 call edx
// 004080bb  8bc6                 mov eax, esi
// 004080bd  5e                   pop esi
// 004080be  c20400               ret 4
// library atl-8.0/atl.cpp (function ?Release@?$CComPolyObject@VCAxHostWindow@ATL@@@ATL@@UAGKXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
