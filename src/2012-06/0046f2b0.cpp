// from server: 100% by auto
// roc 2012-06 0046f2b0  unit: CRobloxModule  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0046f2b0
//
// 0046f2b0  8b442404             mov eax, dword ptr [esp + 4]
// 0046f2b4  8b08                 mov ecx, dword ptr [eax]
// 0046f2b6  8b510c               mov edx, dword ptr [ecx + 0xc]
// 0046f2b9  6824c9b400           push 0xb4c924
// 0046f2be  68089fb500           push 0xb59f08
// 0046f2c3  50                   push eax
// 0046f2c4  ffd2                 call edx
// 0046f2c6  c20400               ret 4
// library atl-8.0/atl.cpp (function ?AddCommonRGSReplacements@?$CAtlModuleT@VCComModule@ATL@@@ATL@@UAEJPAUIRegistrarBase@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
