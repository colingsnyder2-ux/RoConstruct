// from server: 100% by auto
// roc 2009-12 0088d5b0  unit: CXTPCommandBarAnimation::PAUCAnimateInfo::?$CArray  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0088d5b0
//
// 0088d5b0  56                   push esi
// 0088d5b1  8bf1                 mov esi, ecx
// 0088d5b3  57                   push edi
// 0088d5b4  8d4e24               lea ecx, [esi + 0x24]
// 0088d5b7  e834ffffff           call 0x88d4f0
// 0088d5bc  33ff                 xor edi, edi
// 0088d5be  8d4610               lea eax, [esi + 0x10]
// 0088d5c1  50                   push eax
// 0088d5c2  893e                 mov dword ptr [esi], edi
// 0088d5c4  897e04               mov dword ptr [esi + 4], edi
// 0088d5c7  897e08               mov dword ptr [esi + 8], edi
// 0088d5ca  897e0c               mov dword ptr [esi + 0xc], edi
// 0088d5cd  ff159cca9800         call dword ptr [0x98ca9c]
// 0088d5d3  897e20               mov dword ptr [esi + 0x20], edi
// 0088d5d6  5f                   pop edi
// 0088d5d7  8bc6                 mov eax, esi
// 0088d5d9  5e                   pop esi
// 0088d5da  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPCommandBarAnimation.cpp (function ??0CAnimateInfo@CXTPCommandBarAnimation@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPCommandBarAnimation.cpp
