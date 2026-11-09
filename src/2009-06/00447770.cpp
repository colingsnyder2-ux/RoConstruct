// from server: 100% by auto
// roc 2009-06 00447770  unit: CRobloxModule  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00447770
//
// 00447770  8b442404             mov eax, dword ptr [esp + 4]
// 00447774  8b08                 mov ecx, dword ptr [eax]
// 00447776  8b510c               mov edx, dword ptr [ecx + 0xc]
// 00447779  680c728b00           push 0x8b720c
// 0044777e  6810728b00           push 0x8b7210
// 00447783  50                   push eax
// 00447784  ffd2                 call edx
// 00447786  c20400               ret 4
// library atl-8.0/atl.cpp (function ?AddCommonRGSReplacements@?$CAtlModuleT@VCComModule@ATL@@@ATL@@UAEJPAUIRegistrarBase@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
