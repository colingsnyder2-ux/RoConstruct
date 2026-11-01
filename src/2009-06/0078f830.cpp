// from server: 100% by auto
// roc 2009-06 0078f830  unit: CXTPPropertyGridItemColor::?8??OnInplaceButtonDown::CPropertyGridItemColorColorPopup  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0078f830
//
// 0078f830  56                   push esi
// 0078f831  6a00                 push 0
// 0078f833  8bf1                 mov esi, ecx
// 0078f835  e83632feff           call 0x772a70
// 0078f83a  83c404               add esp, 4
// 0078f83d  83be6401000000       cmp dword ptr [esi + 0x164], 0
// 0078f844  740b                 je 0x78f851
// 0078f846  8b06                 mov eax, dword ptr [esi]
// 0078f848  8b5004               mov edx, dword ptr [eax + 4]
// 0078f84b  6a01                 push 1
// 0078f84d  8bce                 mov ecx, esi
// 0078f84f  ffd2                 call edx
// 0078f851  5e                   pop esi
// 0078f852  c3                   ret 
// library xtp-13.2.1/Source\Controls\XTColorPopup.cpp (function ?PostNcDestroy@CXTColorPopup@@MAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTColorPopup.cpp
