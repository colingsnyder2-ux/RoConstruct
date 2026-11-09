// from server: 100% by auto
// roc 2008-06 004028c0  unit: VCWorkspace::?$CComAggObject  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004028c0
//
// 004028c0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 004028c4  834104ff             add dword ptr [ecx + 4], -1
// 004028c8  56                   push esi
// 004028c9  8b7104               mov esi, dword ptr [ecx + 4]
// 004028cc  750d                 jne 0x4028db
// 004028ce  85c9                 test ecx, ecx
// 004028d0  7409                 je 0x4028db
// 004028d2  8b01                 mov eax, dword ptr [ecx]
// 004028d4  8b500c               mov edx, dword ptr [eax + 0xc]
// 004028d7  6a01                 push 1
// 004028d9  ffd2                 call edx
// 004028db  8bc6                 mov eax, esi
// 004028dd  5e                   pop esi
// 004028de  c20400               ret 4
// library atl-8.0/atl.cpp (function ?Release@?$CComPolyObject@VCAxHostWindow@ATL@@@ATL@@UAGKXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
