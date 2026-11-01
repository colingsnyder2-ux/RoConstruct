// from server: 100% by auto
// roc 2009-06 007355d0  unit: KKPAVCXTPImageManagerResource::?$CMap  size: 93 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007355d0
//
// 007355d0  837c240400           cmp dword ptr [esp + 4], 0
// 007355d5  56                   push esi
// 007355d6  8bf1                 mov esi, ecx
// 007355d8  7408                 je 0x7355e2
// 007355da  8d4e30               lea ecx, [esi + 0x30]
// 007355dd  e82efbffff           call 0x735110
// 007355e2  8d4e54               lea ecx, [esi + 0x54]
// 007355e5  e826fbffff           call 0x735110
// 007355ea  8d4e78               lea ecx, [esi + 0x78]
// 007355ed  e81efbffff           call 0x735110
// 007355f2  8d8e9c000000         lea ecx, [esi + 0x9c]
// 007355f8  e813fbffff           call 0x735110
// 007355fd  8d8ec0000000         lea ecx, [esi + 0xc0]
// 00735603  e808fbffff           call 0x735110
// 00735608  8d8ee4000000         lea ecx, [esi + 0xe4]
// 0073560e  e8fdfaffff           call 0x735110
// 00735613  8d8e08010000         lea ecx, [esi + 0x108]
// 00735619  e8f2faffff           call 0x735110
// 0073561e  8d8e2c010000         lea ecx, [esi + 0x12c]
// 00735624  e8e7faffff           call 0x735110
// 00735629  5e                   pop esi
// 0073562a  c20400               ret 4
// library xtp-15.2.1/Source\Common\XTPImageManager.cpp (function ?Clear@CXTPImageManagerIcon@@AAEXH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPImageManager.cpp
