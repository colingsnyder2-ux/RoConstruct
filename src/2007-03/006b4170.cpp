// from server: 100% by auto
// roc 2007-03 006b4170  unit: seg_006b0000  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006b4170
//
// 006b4170  56                   push esi
// 006b4171  8bf1                 mov esi, ecx
// 006b4173  57                   push edi
// 006b4174  8d4e24               lea ecx, [esi + 0x24]
// 006b4177  e894feffff           call 0x6b4010
// 006b417c  33ff                 xor edi, edi
// 006b417e  8d4610               lea eax, [esi + 0x10]
// 006b4181  50                   push eax
// 006b4182  893e                 mov dword ptr [esi], edi
// 006b4184  897e04               mov dword ptr [esi + 4], edi
// 006b4187  897e08               mov dword ptr [esi + 8], edi
// 006b418a  897e0c               mov dword ptr [esi + 0xc], edi
// 006b418d  ff1514ef7700         call dword ptr [0x77ef14]
// 006b4193  897e20               mov dword ptr [esi + 0x20], edi
// 006b4196  5f                   pop edi
// 006b4197  8bc6                 mov eax, esi
// 006b4199  5e                   pop esi
// 006b419a  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPCommandBarAnimation.cpp (function ??0CAnimateInfo@CXTPCommandBarAnimation@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPCommandBarAnimation.cpp
