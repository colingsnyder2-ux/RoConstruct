// from server: 100% by auto
// roc 2009-12 0080c680  unit: KKPAVCXTPImageManagerResource::?$CMap  size: 93 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0080c680
//
// 0080c680  837c240400           cmp dword ptr [esp + 4], 0
// 0080c685  56                   push esi
// 0080c686  8bf1                 mov esi, ecx
// 0080c688  7408                 je 0x80c692
// 0080c68a  8d4e30               lea ecx, [esi + 0x30]
// 0080c68d  e82efbffff           call 0x80c1c0
// 0080c692  8d4e54               lea ecx, [esi + 0x54]
// 0080c695  e826fbffff           call 0x80c1c0
// 0080c69a  8d4e78               lea ecx, [esi + 0x78]
// 0080c69d  e81efbffff           call 0x80c1c0
// 0080c6a2  8d8e9c000000         lea ecx, [esi + 0x9c]
// 0080c6a8  e813fbffff           call 0x80c1c0
// 0080c6ad  8d8ec0000000         lea ecx, [esi + 0xc0]
// 0080c6b3  e808fbffff           call 0x80c1c0
// 0080c6b8  8d8ee4000000         lea ecx, [esi + 0xe4]
// 0080c6be  e8fdfaffff           call 0x80c1c0
// 0080c6c3  8d8e08010000         lea ecx, [esi + 0x108]
// 0080c6c9  e8f2faffff           call 0x80c1c0
// 0080c6ce  8d8e2c010000         lea ecx, [esi + 0x12c]
// 0080c6d4  e8e7faffff           call 0x80c1c0
// 0080c6d9  5e                   pop esi
// 0080c6da  c20400               ret 4
// library xtp-15.2.1/Source\Common\XTPImageManager.cpp (function ?Clear@CXTPImageManagerIcon@@AAEXH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPImageManager.cpp
