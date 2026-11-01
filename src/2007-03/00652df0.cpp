// from server: 100% by auto
// roc 2007-03 00652df0  unit: seg_00650000  size: 56 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00652df0
//
// 00652df0  53                   push ebx
// 00652df1  56                   push esi
// 00652df2  8bf1                 mov esi, ecx
// 00652df4  33db                 xor ebx, ebx
// 00652df6  6a0a                 push 0xa
// 00652df8  8d4e18               lea ecx, [esi + 0x18]
// 00652dfb  c7065c767c00         mov dword ptr [esi], 0x7c765c
// 00652e01  895e04               mov dword ptr [esi + 4], ebx
// 00652e04  c7460801000000       mov dword ptr [esi + 8], 1
// 00652e0b  895e0c               mov dword ptr [esi + 0xc], ebx
// 00652e0e  895e10               mov dword ptr [esi + 0x10], ebx
// 00652e11  895e14               mov dword ptr [esi + 0x14], ebx
// 00652e14  e8e7fdffff           call 0x652c00
// 00652e19  885e38               mov byte ptr [esi + 0x38], bl
// 00652e1c  895e34               mov dword ptr [esi + 0x34], ebx
// 00652e1f  c6463901             mov byte ptr [esi + 0x39], 1
// 00652e23  8bc6                 mov eax, esi
// 00652e25  5e                   pop esi
// 00652e26  5b                   pop ebx
// 00652e27  c3                   ret 
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ??0CXTPTreeBase@@IAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
