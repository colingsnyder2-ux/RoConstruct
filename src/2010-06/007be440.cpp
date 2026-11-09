// from server: 100% by auto
// roc 2010-06 007be440  unit: CXTPImageManagerResource::CBitmapDC  size: 74 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007be440
//
// 007be440  83ec0c               sub esp, 0xc
// 007be443  56                   push esi
// 007be444  8bf1                 mov esi, ecx
// 007be446  8b461c               mov eax, dword ptr [esi + 0x1c]
// 007be449  f7d8                 neg eax
// 007be44b  1bc0                 sbb eax, eax
// 007be44d  89442404             mov dword ptr [esp + 4], eax
// 007be451  742b                 je 0x7be47e
// 007be453  57                   push edi
// 007be454  8d7e10               lea edi, [esi + 0x10]
// 007be457  8d44240c             lea eax, [esp + 0xc]
// 007be45b  50                   push eax
// 007be45c  8d4c2414             lea ecx, [esp + 0x14]
// 007be460  51                   push ecx
// 007be461  8d542410             lea edx, [esp + 0x10]
// 007be465  52                   push edx
// 007be466  8bcf                 mov ecx, edi
// 007be468  e8231e0b00           call 0x870290
// 007be46d  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 007be471  e8a69afeff           call 0x7a7f1c
// 007be476  837c240800           cmp dword ptr [esp + 8], 0
// 007be47b  75da                 jne 0x7be457
// 007be47d  5f                   pop edi
// 007be47e  8d4e10               lea ecx, [esi + 0x10]
// 007be481  5e                   pop esi
// 007be482  83c40c               add esp, 0xc
// 007be485  e936f5ffff           jmp 0x7bd9c0
// library xtp-13.2.1/Source\Common\XTPImageManager.cpp (function ?RemoveAll@CXTPImageManagerImageList@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPImageManager.cpp
