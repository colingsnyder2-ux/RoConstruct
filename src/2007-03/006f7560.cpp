// from server: 100% by auto
// roc 2007-03 006f7560  unit: seg_006f0000  size: 24 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006f7560
//
// 006f7560  8b442404             mov eax, dword ptr [esp + 4]
// 006f7564  8b4c2408             mov ecx, dword ptr [esp + 8]
// 006f7568  0108                 add dword ptr [eax], ecx
// 006f756a  014808               add dword ptr [eax + 8], ecx
// 006f756d  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 006f7571  014804               add dword ptr [eax + 4], ecx
// 006f7574  01480c               add dword ptr [eax + 0xc], ecx
// 006f7577  c3                   ret 
// library xtp-15.2.1/Source\SkinFramework\XTPSkinManagerSchema.cpp (function ?InflateBorders@@YAXAAVCRect@@HH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/SkinFramework/XTPSkinManagerSchema.cpp
