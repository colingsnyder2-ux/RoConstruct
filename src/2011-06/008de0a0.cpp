// from server: 100% by auto
// roc 2011-06 008de0a0  unit: CXTPTabPaintManager::CAppearanceSetVisio  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008de0a0
//
// 008de0a0  56                   push esi
// 008de0a1  8bf1                 mov esi, ecx
// 008de0a3  8d4e54               lea ecx, [esi + 0x54]
// 008de0a6  c706647ead00         mov dword ptr [esi], 0xad7e64
// 008de0ac  ff15082ea400         call dword ptr [0xa42e08]
// 008de0b2  8d4e48               lea ecx, [esi + 0x48]
// 008de0b5  ff15082ea400         call dword ptr [0xa42e08]
// 008de0bb  8bce                 mov ecx, esi
// 008de0bd  5e                   pop esi
// 008de0be  e923cbf2ff           jmp 0x80abe6
// library xtp-15.2.1-shared-mfc/Source\PropertyGrid\XTPPropertyGridInplaceButton.cpp (function ??1CXTPPropertyGridInplaceButton@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/PropertyGrid/XTPPropertyGridInplaceButton.cpp
