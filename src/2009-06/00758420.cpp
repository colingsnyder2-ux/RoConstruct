// from server: 100% by auto
// roc 2009-06 00758420  unit: CXTTreeBase::PAXPAXUCLRFONT::?$CMap  size: 56 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00758420
//
// 00758420  53                   push ebx
// 00758421  56                   push esi
// 00758422  8bf1                 mov esi, ecx
// 00758424  33db                 xor ebx, ebx
// 00758426  6a0a                 push 0xa
// 00758428  8d4e18               lea ecx, [esi + 0x18]
// 0075842b  c70604618f00         mov dword ptr [esi], 0x8f6104
// 00758431  895e04               mov dword ptr [esi + 4], ebx
// 00758434  c7460801000000       mov dword ptr [esi + 8], 1
// 0075843b  895e0c               mov dword ptr [esi + 0xc], ebx
// 0075843e  895e10               mov dword ptr [esi + 0x10], ebx
// 00758441  895e14               mov dword ptr [esi + 0x14], ebx
// 00758444  e8e7fdffff           call 0x758230
// 00758449  885e38               mov byte ptr [esi + 0x38], bl
// 0075844c  895e34               mov dword ptr [esi + 0x34], ebx
// 0075844f  c6463901             mov byte ptr [esi + 0x39], 1
// 00758453  8bc6                 mov eax, esi
// 00758455  5e                   pop esi
// 00758456  5b                   pop ebx
// 00758457  c3                   ret 
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ??0CXTPTreeBase@@IAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
