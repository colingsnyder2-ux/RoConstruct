// from server: 100% by auto
// roc 2010-06 0087a3e0  unit: CXTPControlCustom  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0087a3e0
//
// 0087a3e0  56                   push esi
// 0087a3e1  8bf1                 mov esi, ecx
// 0087a3e3  8d4e54               lea ecx, [esi + 0x54]
// 0087a3e6  c70694dda600         mov dword ptr [esi], 0xa6dd94
// 0087a3ec  ff15f0ce9e00         call dword ptr [0x9ecef0]
// 0087a3f2  8d4e48               lea ecx, [esi + 0x48]
// 0087a3f5  ff15f0ce9e00         call dword ptr [0x9ecef0]
// 0087a3fb  8bce                 mov ecx, esi
// 0087a3fd  5e                   pop esi
// 0087a3fe  e91fe1f2ff           jmp 0x7a8522
// library xtp-13.2.1-shared-mfc/Source\PropertyGrid\XTPPropertyGridInplaceButton.cpp (function ??1CXTPPropertyGridInplaceButton@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/PropertyGrid/XTPPropertyGridInplaceButton.cpp
