// from server: 100% by auto
// roc 2010-06 00841860  unit: CXTPCommandBarAnimation::PAUCAnimateInfo::?$CArray  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00841860
//
// 00841860  56                   push esi
// 00841861  8bf1                 mov esi, ecx
// 00841863  57                   push edi
// 00841864  33ff                 xor edi, edi
// 00841866  8d4e1c               lea ecx, [esi + 0x1c]
// 00841869  897e08               mov dword ptr [esi + 8], edi
// 0084186c  c74604a02ea000       mov dword ptr [esi + 4], 0xa02ea0
// 00841873  e818ffffff           call 0x841790
// 00841878  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0084187c  897e0c               mov dword ptr [esi + 0xc], edi
// 0084187f  897e10               mov dword ptr [esi + 0x10], edi
// 00841882  897e14               mov dword ptr [esi + 0x14], edi
// 00841885  897e18               mov dword ptr [esi + 0x18], edi
// 00841888  8906                 mov dword ptr [esi], eax
// 0084188a  5f                   pop edi
// 0084188b  8bc6                 mov eax, esi
// 0084188d  5e                   pop esi
// 0084188e  c20400               ret 4
// library xtp-13.2.1/Source\CommandBars\XTPCommandBarAnimation.cpp (function ??0CXTPCommandBarAnimation@@QAE@PAVCXTPCommandBar@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPCommandBarAnimation.cpp
