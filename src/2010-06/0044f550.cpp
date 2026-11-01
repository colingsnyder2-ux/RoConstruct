// from server: 100% by auto
// roc 2010-06 0044f550  unit: CRobloxModule  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0044f550
//
// 0044f550  8b442404             mov eax, dword ptr [esp + 4]
// 0044f554  8b08                 mov ecx, dword ptr [eax]
// 0044f556  8b510c               mov edx, dword ptr [ecx + 0xc]
// 0044f559  6844c2a000           push 0xa0c244
// 0044f55e  6848c2a000           push 0xa0c248
// 0044f563  50                   push eax
// 0044f564  ffd2                 call edx
// 0044f566  c20400               ret 4
// library atl-8.0/atl.cpp (function ?AddCommonRGSReplacements@?$CAtlModuleT@VCComModule@ATL@@@ATL@@UAEJPAUIRegistrarBase@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
