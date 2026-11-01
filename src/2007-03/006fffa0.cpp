// from server: 100% by auto
// roc 2007-03 006fffa0  unit: seg_006f0000  size: 64 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006fffa0
//
// 006fffa0  8b442410             mov eax, dword ptr [esp + 0x10]
// 006fffa4  8b54240c             mov edx, dword ptr [esp + 0xc]
// 006fffa8  50                   push eax
// 006fffa9  8b44240c             mov eax, dword ptr [esp + 0xc]
// 006fffad  52                   push edx
// 006fffae  8b54240c             mov edx, dword ptr [esp + 0xc]
// 006fffb2  50                   push eax
// 006fffb3  52                   push edx
// 006fffb4  e827ffffff           call 0x6ffee0
// 006fffb9  85c0                 test eax, eax
// 006fffbb  7508                 jne 0x6fffc5
// 006fffbd  b805400080           mov eax, 0x80004005
// 006fffc2  c21400               ret 0x14
// 006fffc5  833802               cmp dword ptr [eax], 2
// 006fffc8  7408                 je 0x6fffd2
// 006fffca  b857000780           mov eax, 0x80070057
// 006fffcf  c21400               ret 0x14
// 006fffd2  8b4008               mov eax, dword ptr [eax + 8]
// 006fffd5  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 006fffd9  8901                 mov dword ptr [ecx], eax
// 006fffdb  33c0                 xor eax, eax
// 006fffdd  c21400               ret 0x14
// library xtp-15.2.1/Source\SkinFramework\XTPSkinManagerSchema.cpp (function ?GetIntProperty@CXTPSkinManagerSchema@@QAEJIHHHAAH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/SkinFramework/XTPSkinManagerSchema.cpp
