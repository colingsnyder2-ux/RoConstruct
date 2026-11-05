// from server: 100% by auto
// roc 2010-06 007c0770  unit: KKPAVCXTPImageManagerResource::?$CMap  size: 93 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007c0770
//
// 007c0770  837c240400           cmp dword ptr [esp + 4], 0
// 007c0775  56                   push esi
// 007c0776  8bf1                 mov esi, ecx
// 007c0778  7408                 je 0x7c0782
// 007c077a  8d4e30               lea ecx, [esi + 0x30]
// 007c077d  e82efbffff           call 0x7c02b0
// 007c0782  8d4e54               lea ecx, [esi + 0x54]
// 007c0785  e826fbffff           call 0x7c02b0
// 007c078a  8d4e78               lea ecx, [esi + 0x78]
// 007c078d  e81efbffff           call 0x7c02b0
// 007c0792  8d8e9c000000         lea ecx, [esi + 0x9c]
// 007c0798  e813fbffff           call 0x7c02b0
// 007c079d  8d8ec0000000         lea ecx, [esi + 0xc0]
// 007c07a3  e808fbffff           call 0x7c02b0
// 007c07a8  8d8ee4000000         lea ecx, [esi + 0xe4]
// 007c07ae  e8fdfaffff           call 0x7c02b0
// 007c07b3  8d8e08010000         lea ecx, [esi + 0x108]
// 007c07b9  e8f2faffff           call 0x7c02b0
// 007c07be  8d8e2c010000         lea ecx, [esi + 0x12c]
// 007c07c4  e8e7faffff           call 0x7c02b0
// 007c07c9  5e                   pop esi
// 007c07ca  c20400               ret 4
// library xtp-13.2.1/Source\Common\XTPImageManager.cpp (function ?Clear@CXTPImageManagerIcon@@AAEXH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPImageManager.cpp
