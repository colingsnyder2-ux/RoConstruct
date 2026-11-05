// from server: 100% by auto
// roc 2010-06 007ec2f0  unit: CXTPControls  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007ec2f0
//
// 007ec2f0  56                   push esi
// 007ec2f1  6a2c                 push 0x2c
// 007ec2f3  8bf1                 mov esi, ecx
// 007ec2f5  6a00                 push 0
// 007ec2f7  56                   push esi
// 007ec2f8  e8e7c8fbff           call 0x7a8be4
// 007ec2fd  83c40c               add esp, 0xc
// 007ec300  c7062c000000         mov dword ptr [esi], 0x2c
// 007ec306  c7460805000000       mov dword ptr [esi + 8], 5
// 007ec30d  8bc6                 mov eax, esi
// 007ec30f  5e                   pop esi
// 007ec310  c3                   ret 
// library xtp-13.2.1/Source\Controls\XTWindowPos.cpp (function ??0CXTWindowPos@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTWindowPos.cpp
