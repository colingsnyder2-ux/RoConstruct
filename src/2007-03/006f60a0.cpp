// from server: 100% by auto
// roc 2007-03 006f60a0  unit: seg_006f0000  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006f60a0
//
// 006f60a0  56                   push esi
// 006f60a1  8bf1                 mov esi, ecx
// 006f60a3  8b4644               mov eax, dword ptr [esi + 0x44]
// 006f60a6  8b4e40               mov ecx, dword ptr [esi + 0x40]
// 006f60a9  50                   push eax
// 006f60aa  51                   push ecx
// 006f60ab  8d560c               lea edx, [esi + 0xc]
// 006f60ae  52                   push edx
// 006f60af  8bce                 mov ecx, esi
// 006f60b1  e8bafcffff           call 0x6f5d70
// 006f60b6  894608               mov dword ptr [esi + 8], eax
// 006f60b9  5e                   pop esi
// 006f60ba  c3                   ret 
// library xtp-13.2.1/Source\SkinFramework\XTPSkinManagerApiHook.cpp (function ?HookImport@CXTPSkinManagerApiFunction@@QAEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/SkinFramework/XTPSkinManagerApiHook.cpp
