// from server: 100% by auto
// roc 2010-06 00822740  unit: CXTPResourceManager  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00822740
//
// 00822740  0fb7442404           movzx eax, word ptr [esp + 4]
// 00822745  56                   push esi
// 00822746  50                   push eax
// 00822747  8bf1                 mov esi, ecx
// 00822749  e862fcffff           call 0x8223b0
// 0082274e  83c404               add esp, 4
// 00822751  89460c               mov dword ptr [esi + 0xc], eax
// 00822754  85c0                 test eax, eax
// 00822756  7510                 jne 0x822768
// 00822758  6809040000           push 0x409
// 0082275d  e84efcffff           call 0x8223b0
// 00822762  83c404               add esp, 4
// 00822765  89460c               mov dword ptr [esi + 0xc], eax
// 00822768  5e                   pop esi
// 00822769  c20400               ret 4
// library xtp-13.2.1/Source\Common\XTPResourceManager.cpp (function ?SetResourceLanguage@CXTPResourceManager@@QAEXG@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPResourceManager.cpp
