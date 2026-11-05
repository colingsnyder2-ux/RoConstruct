// from server: 100% by auto
// roc 2010-06 007c07d0  unit: KKPAVCXTPImageManagerResource::?$CMap  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007c07d0
//
// 007c07d0  56                   push esi
// 007c07d1  8bf1                 mov esi, ecx
// 007c07d3  8d4e54               lea ecx, [esi + 0x54]
// 007c07d6  e8d5faffff           call 0x7c02b0
// 007c07db  8d4e78               lea ecx, [esi + 0x78]
// 007c07de  e8cdfaffff           call 0x7c02b0
// 007c07e3  8d8e2c010000         lea ecx, [esi + 0x12c]
// 007c07e9  5e                   pop esi
// 007c07ea  e9c1faffff           jmp 0x7c02b0
// library xtp-13.2.1/Source\Common\XTPImageManager.cpp (function ?Refresh@CXTPImageManagerIcon@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPImageManager.cpp
