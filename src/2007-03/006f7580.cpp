// from server: 100% by auto
// roc 2007-03 006f7580  unit: seg_006f0000  size: 45 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006f7580
//
// 006f7580  56                   push esi
// 006f7581  8bf1                 mov esi, ecx
// 006f7583  833e01               cmp dword ptr [esi], 1
// 006f7586  750c                 jne 0x6f7594
// 006f7588  8b4608               mov eax, dword ptr [esi + 8]
// 006f758b  50                   push eax
// 006f758c  e8236ef2ff           call 0x61e3b4
// 006f7591  83c404               add esp, 4
// 006f7594  833e06               cmp dword ptr [esi], 6
// 006f7597  750c                 jne 0x6f75a5
// 006f7599  8b4e08               mov ecx, dword ptr [esi + 8]
// 006f759c  51                   push ecx
// 006f759d  e84e6bf2ff           call 0x61e0f0
// 006f75a2  83c404               add esp, 4
// 006f75a5  c70600000000         mov dword ptr [esi], 0
// 006f75ab  5e                   pop esi
// 006f75ac  c3                   ret 
// library xtp-15.2.1/Source\SkinFramework\XTPSkinManagerSchema.cpp (function ?ClearProperty@CXTPSkinManagerSchemaProperty@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/SkinFramework/XTPSkinManagerSchema.cpp
