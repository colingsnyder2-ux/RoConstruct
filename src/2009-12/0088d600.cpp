// from server: 100% by auto
// roc 2009-12 0088d600  unit: CXTPCommandBarAnimation::PAUCAnimateInfo::?$CArray  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0088d600
//
// 0088d600  56                   push esi
// 0088d601  8bf1                 mov esi, ecx
// 0088d603  57                   push edi
// 0088d604  33ff                 xor edi, edi
// 0088d606  8d4e1c               lea ecx, [esi + 0x1c]
// 0088d609  897e08               mov dword ptr [esi + 8], edi
// 0088d60c  c7460418229a00       mov dword ptr [esi + 4], 0x9a2218
// 0088d613  e818ffffff           call 0x88d530
// 0088d618  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0088d61c  897e0c               mov dword ptr [esi + 0xc], edi
// 0088d61f  897e10               mov dword ptr [esi + 0x10], edi
// 0088d622  897e14               mov dword ptr [esi + 0x14], edi
// 0088d625  897e18               mov dword ptr [esi + 0x18], edi
// 0088d628  8906                 mov dword ptr [esi], eax
// 0088d62a  5f                   pop edi
// 0088d62b  8bc6                 mov eax, esi
// 0088d62d  5e                   pop esi
// 0088d62e  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPCommandBarAnimation.cpp (function ??0CXTPCommandBarAnimation@@QAE@PAVCXTPCommandBar@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPCommandBarAnimation.cpp
