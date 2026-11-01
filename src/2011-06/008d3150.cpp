// from server: 100% by auto
// roc 2011-06 008d3150  unit: CXTPTabManagerItem  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008d3150
//
// 008d3150  8b410c               mov eax, dword ptr [ecx + 0xc]
// 008d3153  c701e878ad00         mov dword ptr [ecx], 0xad78e8
// 008d3159  394810               cmp dword ptr [eax + 0x10], ecx
// 008d315c  7507                 jne 0x8d3165
// 008d315e  c7401000000000       mov dword ptr [eax + 0x10], 0
// 008d3165  83c128               add ecx, 0x28
// 008d3168  ff25082ea400         jmp dword ptr [0xa42e08]
// library xtp-15.2.1-shared-mfc/Source\TabManager\XTPTabManager.cpp (function ??1CXTPTabManagerNavigateButton@@MAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/TabManager/XTPTabManager.cpp
