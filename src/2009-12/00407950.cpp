// from server: 100% by auto
// roc 2009-12 00407950  unit: VCApp::?$CComAggObject  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00407950
//
// 00407950  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00407954  834104ff             add dword ptr [ecx + 4], -1
// 00407958  56                   push esi
// 00407959  8b7104               mov esi, dword ptr [ecx + 4]
// 0040795c  750d                 jne 0x40796b
// 0040795e  85c9                 test ecx, ecx
// 00407960  7409                 je 0x40796b
// 00407962  8b01                 mov eax, dword ptr [ecx]
// 00407964  8b500c               mov edx, dword ptr [eax + 0xc]
// 00407967  6a01                 push 1
// 00407969  ffd2                 call edx
// 0040796b  8bc6                 mov eax, esi
// 0040796d  5e                   pop esi
// 0040796e  c20400               ret 4
// library atl-8.0/atl.cpp (function ?Release@?$CComPolyObject@VCAxHostWindow@ATL@@@ATL@@UAGKXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
