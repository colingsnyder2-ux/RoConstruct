// from server: 100% by auto
// roc 2009-12 0080c6e0  unit: KKPAVCXTPImageManagerResource::?$CMap  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0080c6e0
//
// 0080c6e0  56                   push esi
// 0080c6e1  8bf1                 mov esi, ecx
// 0080c6e3  8d4e54               lea ecx, [esi + 0x54]
// 0080c6e6  e8d5faffff           call 0x80c1c0
// 0080c6eb  8d4e78               lea ecx, [esi + 0x78]
// 0080c6ee  e8cdfaffff           call 0x80c1c0
// 0080c6f3  8d8e2c010000         lea ecx, [esi + 0x12c]
// 0080c6f9  5e                   pop esi
// 0080c6fa  e9c1faffff           jmp 0x80c1c0
// library xtp-15.2.1/Source\Common\XTPImageManager.cpp (function ?Refresh@CXTPImageManagerIcon@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPImageManager.cpp
