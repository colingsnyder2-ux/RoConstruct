// from server: 100% by auto
// roc 2009-12 008380d0  unit: CXTPControls  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008380d0
//
// 008380d0  56                   push esi
// 008380d1  6a2c                 push 0x2c
// 008380d3  8bf1                 mov esi, ecx
// 008380d5  6a00                 push 0
// 008380d7  56                   push esi
// 008380d8  e8c7c9fbff           call 0x7f4aa4
// 008380dd  83c40c               add esp, 0xc
// 008380e0  c7062c000000         mov dword ptr [esi], 0x2c
// 008380e6  c7460805000000       mov dword ptr [esi + 8], 5
// 008380ed  8bc6                 mov eax, esi
// 008380ef  5e                   pop esi
// 008380f0  c3                   ret 
// library xtp-15.2.1/Source\Controls\Util\XTPWindowPos.cpp (function ??0CXTPWindowPos@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Util/XTPWindowPos.cpp
