// from server: 100% by auto
// roc 2010-06 008220b0  unit: CXTPResourceManager  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008220b0
//
// 008220b0  56                   push esi
// 008220b1  8bf1                 mov esi, ecx
// 008220b3  8b4608               mov eax, dword ptr [esi + 8]
// 008220b6  85c0                 test eax, eax
// 008220b8  740e                 je 0x8220c8
// 008220ba  50                   push eax
// 008220bb  ff1568a39e00         call dword ptr [0x9ea368]
// 008220c1  c7460800000000       mov dword ptr [esi + 8], 0
// 008220c8  5e                   pop esi
// 008220c9  c3                   ret 
// library xtp-13.2.1/Source\Common\XTPResourceManager.cpp (function ?Close@CXTPResourceManager@@UAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPResourceManager.cpp
