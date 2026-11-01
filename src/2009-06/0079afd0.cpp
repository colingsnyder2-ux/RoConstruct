// from server: 100% by auto
// roc 2009-06 0079afd0  unit: CXTPResourceManager  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0079afd0
//
// 0079afd0  0fb7442404           movzx eax, word ptr [esp + 4]
// 0079afd5  56                   push esi
// 0079afd6  50                   push eax
// 0079afd7  8bf1                 mov esi, ecx
// 0079afd9  e862fcffff           call 0x79ac40
// 0079afde  83c404               add esp, 4
// 0079afe1  89460c               mov dword ptr [esi + 0xc], eax
// 0079afe4  85c0                 test eax, eax
// 0079afe6  7510                 jne 0x79aff8
// 0079afe8  6809040000           push 0x409
// 0079afed  e84efcffff           call 0x79ac40
// 0079aff2  83c404               add esp, 4
// 0079aff5  89460c               mov dword ptr [esi + 0xc], eax
// 0079aff8  5e                   pop esi
// 0079aff9  c20400               ret 4
// library xtp-15.2.1/Source\Common\XTPResourceManager.cpp (function ?SetResourceLanguage@CXTPResourceManager@@QAEXG@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPResourceManager.cpp
