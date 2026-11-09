// from server: 100% by auto
// roc 2009-12 0044d940  unit: CRobloxModule  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0044d940
//
// 0044d940  8b442404             mov eax, dword ptr [esp + 4]
// 0044d944  8b08                 mov ecx, dword ptr [eax]
// 0044d946  8b510c               mov edx, dword ptr [ecx + 0xc]
// 0044d949  687cb49a00           push 0x9ab47c
// 0044d94e  6880b49a00           push 0x9ab480
// 0044d953  50                   push eax
// 0044d954  ffd2                 call edx
// 0044d956  c20400               ret 4
// library atl-8.0/atl.cpp (function ?AddCommonRGSReplacements@?$CAtlModuleT@VCComModule@ATL@@@ATL@@UAEJPAUIRegistrarBase@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
