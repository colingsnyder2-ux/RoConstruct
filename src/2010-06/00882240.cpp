// from server: 100% by auto
// roc 2010-06 00882240  unit: CXTPTabManagerItem  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00882240
//
// 00882240  8b410c               mov eax, dword ptr [ecx + 0xc]
// 00882243  c70194e9a600         mov dword ptr [ecx], 0xa6e994
// 00882249  394810               cmp dword ptr [eax + 0x10], ecx
// 0088224c  7507                 jne 0x882255
// 0088224e  c7401000000000       mov dword ptr [eax + 0x10], 0
// 00882255  83c128               add ecx, 0x28
// 00882258  ff25f0ce9e00         jmp dword ptr [0x9ecef0]
// library xtp-13.2.1-shared-mfc/Source\TabManager\XTPTabManager.cpp (function ??1CXTPTabManagerNavigateButton@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/TabManager/XTPTabManager.cpp
