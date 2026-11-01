// from server: 100% by auto
// roc 2007-03 006fc060  unit: seg_006f0000  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006fc060
//
// 006fc060  8b44240c             mov eax, dword ptr [esp + 0xc]
// 006fc064  c1e006               shl eax, 6
// 006fc067  03442408             add eax, dword ptr [esp + 8]
// 006fc06b  c1e006               shl eax, 6
// 006fc06e  03442404             add eax, dword ptr [esp + 4]
// 006fc072  c1e00e               shl eax, 0xe
// 006fc075  03442410             add eax, dword ptr [esp + 0x10]
// 006fc079  c3                   ret 
// library xtp-15.2.1/Source\SkinFramework\XTPSkinManagerSchema.cpp (function ?CalculatePropertyCode@CXTPSkinManagerSchema@@SAIIHHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/SkinFramework/XTPSkinManagerSchema.cpp
