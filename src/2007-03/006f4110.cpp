// from server: 100% by auto
// roc 2007-03 006f4110  unit: seg_006f0000  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006f4110
//
// 006f4110  56                   push esi
// 006f4111  8bf1                 mov esi, ecx
// 006f4113  e8b6690400           call 0x73aace
// 006f4118  8b442408             mov eax, dword ptr [esp + 8]
// 006f411c  894620               mov dword ptr [esi + 0x20], eax
// 006f411f  c70674b17d00         mov dword ptr [esi], 0x7db174
// 006f4125  c7462400000000       mov dword ptr [esi + 0x24], 0
// 006f412c  8bc6                 mov eax, esi
// 006f412e  5e                   pop esi
// 006f412f  c20400               ret 4
// library xtp-15.2.1/Source\SkinFramework\XTPSkinObject.cpp (function ??0CXTPSkinObjectClassInfo@@QAE@PAUCRuntimeClass@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/SkinFramework/XTPSkinObject.cpp
