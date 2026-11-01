// from server: 100% by auto
// roc 2007-03 006fffe0  unit: seg_006f0000  size: 64 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006fffe0
//
// 006fffe0  8b442410             mov eax, dword ptr [esp + 0x10]
// 006fffe4  8b54240c             mov edx, dword ptr [esp + 0xc]
// 006fffe8  50                   push eax
// 006fffe9  8b44240c             mov eax, dword ptr [esp + 0xc]
// 006fffed  52                   push edx
// 006fffee  8b54240c             mov edx, dword ptr [esp + 0xc]
// 006ffff2  50                   push eax
// 006ffff3  52                   push edx
// 006ffff4  e8e7feffff           call 0x6ffee0
// 006ffff9  85c0                 test eax, eax
// 006ffffb  7508                 jne 0x700005
// 006ffffd  b805400080           mov eax, 0x80004005
// 00700002  c21400               ret 0x14
// 00700005  833803               cmp dword ptr [eax], 3
// 00700008  7408                 je 0x700012
// 0070000a  b857000780           mov eax, 0x80070057
// 0070000f  c21400               ret 0x14
// 00700012  8b4008               mov eax, dword ptr [eax + 8]
// 00700015  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00700019  8901                 mov dword ptr [ecx], eax
// 0070001b  33c0                 xor eax, eax
// 0070001d  c21400               ret 0x14
// library xtp-15.2.1/Source\SkinFramework\XTPSkinManagerSchema.cpp (function ?GetBoolProperty@CXTPSkinManagerSchema@@QAEJIHHHAAH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/SkinFramework/XTPSkinManagerSchema.cpp
