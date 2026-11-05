// from server: 100% by auto
// roc 2011-06 004089c0  unit: VCApp::?$CComAggObject  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 004089c0
//
// 004089c0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 004089c4  834104ff             add dword ptr [ecx + 4], -1
// 004089c8  56                   push esi
// 004089c9  8b7104               mov esi, dword ptr [ecx + 4]
// 004089cc  750d                 jne 0x4089db
// 004089ce  85c9                 test ecx, ecx
// 004089d0  7409                 je 0x4089db
// 004089d2  8b01                 mov eax, dword ptr [ecx]
// 004089d4  8b500c               mov edx, dword ptr [eax + 0xc]
// 004089d7  6a01                 push 1
// 004089d9  ffd2                 call edx
// 004089db  8bc6                 mov eax, esi
// 004089dd  5e                   pop esi
// 004089de  c20400               ret 4
// library atl-8.0/atl.cpp (function ?Release@?$CComPolyObject@VCAxHostWindow@ATL@@@ATL@@UAGKXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
