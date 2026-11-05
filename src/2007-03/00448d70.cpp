// from server: 100% by auto
// roc 2007-03 00448d70  unit: seg_00440000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00448d70
//
// 00448d70  8b442404             mov eax, dword ptr [esp + 4]
// 00448d74  8b08                 mov ecx, dword ptr [eax]
// 00448d76  8b510c               mov edx, dword ptr [ecx + 0xc]
// 00448d79  684ce57900           push 0x79e54c
// 00448d7e  68d0f67800           push 0x78f6d0
// 00448d83  50                   push eax
// 00448d84  ffd2                 call edx
// 00448d86  c20400               ret 4
// library atl-8.0/atl.cpp (function ?AddCommonRGSReplacements@?$CAtlModuleT@VCComModule@ATL@@@ATL@@UAEJPAUIRegistrarBase@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
