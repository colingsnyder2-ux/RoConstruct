// from server: 100% by auto
// roc 2009-12 0086e730  unit: CXTPResourceManager  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0086e730
//
// 0086e730  0fb7442404           movzx eax, word ptr [esp + 4]
// 0086e735  56                   push esi
// 0086e736  50                   push eax
// 0086e737  8bf1                 mov esi, ecx
// 0086e739  e862fcffff           call 0x86e3a0
// 0086e73e  83c404               add esp, 4
// 0086e741  89460c               mov dword ptr [esi + 0xc], eax
// 0086e744  85c0                 test eax, eax
// 0086e746  7510                 jne 0x86e758
// 0086e748  6809040000           push 0x409
// 0086e74d  e84efcffff           call 0x86e3a0
// 0086e752  83c404               add esp, 4
// 0086e755  89460c               mov dword ptr [esi + 0xc], eax
// 0086e758  5e                   pop esi
// 0086e759  c20400               ret 4
// library xtp-15.2.1/Source\Common\XTPResourceManager.cpp (function ?SetResourceLanguage@CXTPResourceManager@@QAEXG@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPResourceManager.cpp
