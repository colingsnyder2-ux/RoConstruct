// from server: 100% by auto
// roc 2007-03 00700080  unit: seg_00700000  size: 73 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00700080
//
// 00700080  8b442410             mov eax, dword ptr [esp + 0x10]
// 00700084  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00700088  50                   push eax
// 00700089  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0070008d  52                   push edx
// 0070008e  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00700092  50                   push eax
// 00700093  52                   push edx
// 00700094  e847feffff           call 0x6ffee0
// 00700099  85c0                 test eax, eax
// 0070009b  7508                 jne 0x7000a5
// 0070009d  b805400080           mov eax, 0x80004005
// 007000a2  c21400               ret 0x14
// 007000a5  833806               cmp dword ptr [eax], 6
// 007000a8  7408                 je 0x7000b2
// 007000aa  b857000780           mov eax, 0x80070057
// 007000af  c21400               ret 0x14
// 007000b2  56                   push esi
// 007000b3  8b7008               mov esi, dword ptr [eax + 8]
// 007000b6  57                   push edi
// 007000b7  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 007000bb  b90f000000           mov ecx, 0xf
// 007000c0  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 007000c2  5f                   pop edi
// 007000c3  33c0                 xor eax, eax
// 007000c5  5e                   pop esi
// 007000c6  c21400               ret 0x14
// library xtp-15.2.1/Source\SkinFramework\XTPSkinManagerSchema.cpp (function ?GetFontProperty@CXTPSkinManagerSchema@@QAEJIHHHAAUtagLOGFONTA@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/SkinFramework/XTPSkinManagerSchema.cpp
