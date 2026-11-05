// from server: 100% by auto
// roc 2011-06 0045c790  unit: CRobloxModule  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0045c790
//
// 0045c790  8b442404             mov eax, dword ptr [esp + 4]
// 0045c794  8b08                 mov ecx, dword ptr [eax]
// 0045c796  8b510c               mov edx, dword ptr [ecx + 0xc]
// 0045c799  68fcf3a700           push 0xa7f3fc
// 0045c79e  6848e7a600           push 0xa6e748
// 0045c7a3  50                   push eax
// 0045c7a4  ffd2                 call edx
// 0045c7a6  c20400               ret 4
// library atl-8.0/atl.cpp (function ?AddCommonRGSReplacements@?$CAtlModuleT@VCComModule@ATL@@@ATL@@UAEJPAUIRegistrarBase@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
