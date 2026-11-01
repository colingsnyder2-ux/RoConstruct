// from server: 100% by auto
// roc 2009-06 00893260  unit: seg_00890000  size: 381 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00893260
//
// 00893260  56                   push esi
// 00893261  8b35a4ed8900         mov esi, dword ptr [0x89eda4]
// 00893267  6a1e                 push 0x1e
// 00893269  33c9                 xor ecx, ecx
// 0089326b  6a2b                 push 0x2b
// 0089326d  51                   push ecx
// 0089326e  51                   push ecx
// 0089326f  b819000000           mov eax, 0x19
// 00893274  68d826a500           push 0xa526d8
// 00893279  a3d026a500           mov dword ptr [0xa526d0], eax
// 0089327e  890dd426a500         mov dword ptr [0xa526d4], ecx
// 00893284  ffd6                 call esi
// 00893286  6a4c                 push 0x4c
// 00893288  6a3c                 push 0x3c
// 0089328a  6a21                 push 0x21
// 0089328c  6a1e                 push 0x1e
// 0089328e  33c0                 xor eax, eax
// 00893290  b919000000           mov ecx, 0x19
// 00893295  68f026a500           push 0xa526f0
// 0089329a  a3e826a500           mov dword ptr [0xa526e8], eax
// 0089329f  890dec26a500         mov dword ptr [0xa526ec], ecx
// 008932a5  ffd6                 call esi
// 008932a7  6a1e                 push 0x1e
// 008932a9  6a56                 push 0x56
// 008932ab  6a00                 push 0
// 008932ad  6a2b                 push 0x2b
// 008932af  b819000000           mov eax, 0x19
// 008932b4  b93f000000           mov ecx, 0x3f
// 008932b9  680827a500           push 0xa52708
// 008932be  a30027a500           mov dword ptr [0xa52700], eax
// 008932c3  890d0427a500         mov dword ptr [0xa52704], ecx
// 008932c9  ffd6                 call esi
// 008932cb  6a4c                 push 0x4c
// 008932cd  6a1e                 push 0x1e
// 008932cf  6a21                 push 0x21
// 008932d1  6a00                 push 0
// 008932d3  b83f000000           mov eax, 0x3f
// 008932d8  b919000000           mov ecx, 0x19
// 008932dd  682027a500           push 0xa52720
// 008932e2  a31827a500           mov dword ptr [0xa52718], eax
// 008932e7  890d1c27a500         mov dword ptr [0xa5271c], ecx
// 008932ed  ffd6                 call esi
// 008932ef  6a6a                 push 0x6a
// 008932f1  6a2b                 push 0x2b
// 008932f3  33c9                 xor ecx, ecx
// 008932f5  6a4c                 push 0x4c
// 008932f7  51                   push ecx
// 008932f8  b819000000           mov eax, 0x19
// 008932fd  683827a500           push 0xa52738
// 00893302  a33027a500           mov dword ptr [0xa52730], eax
// 00893307  890d3427a500         mov dword ptr [0xa52734], ecx
// 0089330d  ffd6                 call esi
// 0089330f  6a4c                 push 0x4c
// 00893311  6a78                 push 0x78
// 00893313  6a21                 push 0x21
// 00893315  6a5a                 push 0x5a
// 00893317  33c0                 xor eax, eax
// 00893319  b919000000           mov ecx, 0x19
// 0089331e  685027a500           push 0xa52750
// 00893323  a34827a500           mov dword ptr [0xa52748], eax
// 00893328  890d4c27a500         mov dword ptr [0xa5274c], ecx
// 0089332e  ffd6                 call esi
// 00893330  6a6a                 push 0x6a
// 00893332  6a56                 push 0x56
// 00893334  6a4c                 push 0x4c
// 00893336  6a2b                 push 0x2b
// 00893338  b819000000           mov eax, 0x19
// 0089333d  b93f000000           mov ecx, 0x3f
// 00893342  686827a500           push 0xa52768
// 00893347  a36027a500           mov dword ptr [0xa52760], eax
// 0089334c  890d6427a500         mov dword ptr [0xa52764], ecx
// 00893352  ffd6                 call esi
// 00893354  6a4c                 push 0x4c
// 00893356  6a5a                 push 0x5a
// 00893358  6a21                 push 0x21
// 0089335a  b83f000000           mov eax, 0x3f
// 0089335f  b919000000           mov ecx, 0x19
// 00893364  6a3c                 push 0x3c
// 00893366  a37827a500           mov dword ptr [0xa52778], eax
// 0089336b  890d7c27a500         mov dword ptr [0xa5277c], ecx
// 00893371  688027a500           push 0xa52780
// 00893376  ffd6                 call esi
// 00893378  6a21                 push 0x21
// 0089337a  6a77                 push 0x77
// 0089337c  6a00                 push 0
// 0089337e  b81e000000           mov eax, 0x1e
// 00893383  6a56                 push 0x56
// 00893385  8bc8                 mov ecx, eax
// 00893387  689827a500           push 0xa52798
// 0089338c  a39027a500           mov dword ptr [0xa52790], eax
// 00893391  890d9427a500         mov dword ptr [0xa52794], ecx
// 00893397  ffd6                 call esi
// 00893399  6a6d                 push 0x6d
// 0089339b  6a77                 push 0x77
// 0089339d  6a4c                 push 0x4c
// 0089339f  b81e000000           mov eax, 0x1e
// 008933a4  6a56                 push 0x56
// 008933a6  8bc8                 mov ecx, eax
// 008933a8  68b027a500           push 0xa527b0
// 008933ad  a3a827a500           mov dword ptr [0xa527a8], eax
// 008933b2  890dac27a500         mov dword ptr [0xa527ac], ecx
// 008933b8  ffd6                 call esi
// 008933ba  6a2b                 push 0x2b
// 008933bc  6a2b                 push 0x2b
// 008933be  6a00                 push 0
// 008933c0  b819000000           mov eax, 0x19
// 008933c5  6a00                 push 0
// 008933c7  8bc8                 mov ecx, eax
// 008933c9  68c827a500           push 0xa527c8
// 008933ce  a3c027a500           mov dword ptr [0xa527c0], eax
// 008933d3  890dc427a500         mov dword ptr [0xa527c4], ecx
// 008933d9  ffd6                 call esi
// 008933db  5e                   pop esi
// 008933dc  c3                   ret 
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneContext.cpp (function ??__EarrSpritesStyckerWidbey@@YAXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneContext.cpp
