// from server: 100% by auto
// roc 2011-06 0087bfd0  unit: CXTPPropertyGridItemColor::?8??OnInplaceButtonDown::CPropertyGridItemColorColorPopup  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0087bfd0
//
// 0087bfd0  56                   push esi
// 0087bfd1  6a00                 push 0
// 0087bfd3  8bf1                 mov esi, ecx
// 0087bfd5  e8a632feff           call 0x85f280
// 0087bfda  83c404               add esp, 4
// 0087bfdd  83be6401000000       cmp dword ptr [esi + 0x164], 0
// 0087bfe4  740b                 je 0x87bff1
// 0087bfe6  8b06                 mov eax, dword ptr [esi]
// 0087bfe8  8b5004               mov edx, dword ptr [eax + 4]
// 0087bfeb  6a01                 push 1
// 0087bfed  8bce                 mov ecx, esi
// 0087bfef  ffd2                 call edx
// 0087bff1  5e                   pop esi
// 0087bff2  c3                   ret 
// library xtp-13.2.1/Source\Controls\XTColorPopup.cpp (function ?PostNcDestroy@CXTColorPopup@@MAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTColorPopup.cpp
