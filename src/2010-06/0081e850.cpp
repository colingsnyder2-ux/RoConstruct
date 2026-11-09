// from server: 100% by auto
// roc 2010-06 0081e850  unit: CXTPPropertyGridItemColor::?8??OnInplaceButtonDown::CPropertyGridItemColorColorPopup  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0081e850
//
// 0081e850  56                   push esi
// 0081e851  6a00                 push 0
// 0081e853  8bf1                 mov esi, ecx
// 0081e855  e8a62ffeff           call 0x801800
// 0081e85a  83c404               add esp, 4
// 0081e85d  83be6401000000       cmp dword ptr [esi + 0x164], 0
// 0081e864  740b                 je 0x81e871
// 0081e866  8b06                 mov eax, dword ptr [esi]
// 0081e868  8b5004               mov edx, dword ptr [eax + 4]
// 0081e86b  6a01                 push 1
// 0081e86d  8bce                 mov ecx, esi
// 0081e86f  ffd2                 call edx
// 0081e871  5e                   pop esi
// 0081e872  c3                   ret 
// library xtp-13.2.1/Source\Controls\XTColorPopup.cpp (function ?PostNcDestroy@CXTColorPopup@@MAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTColorPopup.cpp
