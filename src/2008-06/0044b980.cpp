// from server: 100% by auto
// roc 2008-06 0044b980  unit: CRobloxModule  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0044b980
//
// 0044b980  8b442404             mov eax, dword ptr [esp + 4]
// 0044b984  8b08                 mov ecx, dword ptr [eax]
// 0044b986  8b510c               mov edx, dword ptr [ecx + 0xc]
// 0044b989  680c6b8200           push 0x826b0c
// 0044b98e  68e8698100           push 0x8169e8
// 0044b993  50                   push eax
// 0044b994  ffd2                 call edx
// 0044b996  c20400               ret 4
// library atl-8.0/atl.cpp (function ?AddCommonRGSReplacements@?$CAtlModuleT@VCComModule@ATL@@@ATL@@UAEJPAUIRegistrarBase@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
