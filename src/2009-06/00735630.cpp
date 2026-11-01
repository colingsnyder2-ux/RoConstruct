// from server: 100% by auto
// roc 2009-06 00735630  unit: KKPAVCXTPImageManagerResource::?$CMap  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00735630
//
// 00735630  56                   push esi
// 00735631  8bf1                 mov esi, ecx
// 00735633  8d4e54               lea ecx, [esi + 0x54]
// 00735636  e8d5faffff           call 0x735110
// 0073563b  8d4e78               lea ecx, [esi + 0x78]
// 0073563e  e8cdfaffff           call 0x735110
// 00735643  8d8e2c010000         lea ecx, [esi + 0x12c]
// 00735649  5e                   pop esi
// 0073564a  e9c1faffff           jmp 0x735110
// library xtp-15.2.1/Source\Common\XTPImageManager.cpp (function ?Refresh@CXTPImageManagerIcon@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPImageManager.cpp
