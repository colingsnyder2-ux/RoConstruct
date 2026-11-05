// from server: 100% by auto
// roc 2007-03 006f60c0  unit: seg_006f0000  size: 45 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006f60c0
//
// 006f60c0  56                   push esi
// 006f60c1  8bf1                 mov esi, ecx
// 006f60c3  837e0800             cmp dword ptr [esi + 8], 0
// 006f60c7  741a                 je 0x6f60e3
// 006f60c9  8b4640               mov eax, dword ptr [esi + 0x40]
// 006f60cc  8b4e44               mov ecx, dword ptr [esi + 0x44]
// 006f60cf  50                   push eax
// 006f60d0  51                   push ecx
// 006f60d1  8d560c               lea edx, [esi + 0xc]
// 006f60d4  52                   push edx
// 006f60d5  8bce                 mov ecx, esi
// 006f60d7  e894fcffff           call 0x6f5d70
// 006f60dc  c7460800000000       mov dword ptr [esi + 8], 0
// 006f60e3  33c0                 xor eax, eax
// 006f60e5  394608               cmp dword ptr [esi + 8], eax
// 006f60e8  5e                   pop esi
// 006f60e9  0f94c0               sete al
// 006f60ec  c3                   ret 
// library xtp-13.2.1/Source\SkinFramework\XTPSkinManagerApiHook.cpp (function ?UnhookImport@CXTPSkinManagerApiFunction@@QAEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/SkinFramework/XTPSkinManagerApiHook.cpp
