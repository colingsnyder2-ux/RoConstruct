// from server: 100% by auto
// roc 2007-03 00659b70  unit: seg_00650000  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00659b70
//
// 00659b70  56                   push esi
// 00659b71  6a2c                 push 0x2c
// 00659b73  8bf1                 mov esi, ecx
// 00659b75  6a00                 push 0
// 00659b77  56                   push esi
// 00659b78  e89f54fcff           call 0x61f01c
// 00659b7d  83c40c               add esp, 0xc
// 00659b80  c7062c000000         mov dword ptr [esi], 0x2c
// 00659b86  c7460805000000       mov dword ptr [esi + 8], 5
// 00659b8d  8bc6                 mov eax, esi
// 00659b8f  5e                   pop esi
// 00659b90  c3                   ret 
// library xtp-15.2.1/Source\Controls\Util\XTPWindowPos.cpp (function ??0CXTPWindowPos@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Util/XTPWindowPos.cpp
