// from server: 100% by auto
// roc 2009-12 008332a0  unit: CXTTreeBase::PAXPAXUCLRFONT::?$CMap  size: 56 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008332a0
//
// 008332a0  53                   push ebx
// 008332a1  56                   push esi
// 008332a2  8bf1                 mov esi, ecx
// 008332a4  33db                 xor ebx, ebx
// 008332a6  6a0a                 push 0xa
// 008332a8  8d4e18               lea ecx, [esi + 0x18]
// 008332ab  c706ac659f00         mov dword ptr [esi], 0x9f65ac
// 008332b1  895e04               mov dword ptr [esi + 4], ebx
// 008332b4  c7460801000000       mov dword ptr [esi + 8], 1
// 008332bb  895e0c               mov dword ptr [esi + 0xc], ebx
// 008332be  895e10               mov dword ptr [esi + 0x10], ebx
// 008332c1  895e14               mov dword ptr [esi + 0x14], ebx
// 008332c4  e8e7fdffff           call 0x8330b0
// 008332c9  885e38               mov byte ptr [esi + 0x38], bl
// 008332cc  895e34               mov dword ptr [esi + 0x34], ebx
// 008332cf  c6463901             mov byte ptr [esi + 0x39], 1
// 008332d3  8bc6                 mov eax, esi
// 008332d5  5e                   pop esi
// 008332d6  5b                   pop ebx
// 008332d7  c3                   ret 
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ??0CXTPTreeBase@@IAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
