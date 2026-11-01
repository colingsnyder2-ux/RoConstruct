// from server: 100% by auto
// roc 2007-03 006f76b0  unit: seg_006f0000  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006f76b0
//
// 006f76b0  56                   push esi
// 006f76b1  8bf1                 mov esi, ecx
// 006f76b3  e8c8feffff           call 0x6f7580
// 006f76b8  8b442408             mov eax, dword ptr [esp + 8]
// 006f76bc  894608               mov dword ptr [esi + 8], eax
// 006f76bf  5e                   pop esi
// 006f76c0  c20400               ret 4
// library xtp-15.2.1/Source\SkinFramework\XTPSkinManagerSchema.cpp (function ?SetPropertyEnum@CXTPSkinManagerSchemaProperty@@QAEXH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-15.2.1 Source/SkinFramework/XTPSkinManagerSchema.cpp
