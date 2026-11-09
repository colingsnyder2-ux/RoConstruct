// from server: 100% by auto
// roc 2009-12 0086a850  unit: CXTPPropertyGridItemColor::?8??OnInplaceButtonDown::CPropertyGridItemColorColorPopup  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0086a850
//
// 0086a850  56                   push esi
// 0086a851  6a00                 push 0
// 0086a853  8bf1                 mov esi, ecx
// 0086a855  e8462ffeff           call 0x84d7a0
// 0086a85a  83c404               add esp, 4
// 0086a85d  83be6401000000       cmp dword ptr [esi + 0x164], 0
// 0086a864  740b                 je 0x86a871
// 0086a866  8b06                 mov eax, dword ptr [esi]
// 0086a868  8b5004               mov edx, dword ptr [eax + 4]
// 0086a86b  6a01                 push 1
// 0086a86d  8bce                 mov ecx, esi
// 0086a86f  ffd2                 call edx
// 0086a871  5e                   pop esi
// 0086a872  c3                   ret 
// library xtp-13.2.1/Source\Controls\XTColorPopup.cpp (function ?PostNcDestroy@CXTColorPopup@@MAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTColorPopup.cpp
