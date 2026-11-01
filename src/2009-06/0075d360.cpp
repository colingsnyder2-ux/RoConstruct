// from server: 100% by auto
// roc 2009-06 0075d360  unit: CXTPControls  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0075d360
//
// 0075d360  56                   push esi
// 0075d361  6a2c                 push 0x2c
// 0075d363  8bf1                 mov esi, ecx
// 0075d365  6a00                 push 0
// 0075d367  56                   push esi
// 0075d368  e807c9fbff           call 0x719c74
// 0075d36d  83c40c               add esp, 0xc
// 0075d370  c7062c000000         mov dword ptr [esi], 0x2c
// 0075d376  c7460805000000       mov dword ptr [esi + 8], 5
// 0075d37d  8bc6                 mov eax, esi
// 0075d37f  5e                   pop esi
// 0075d380  c3                   ret 
// library xtp-15.2.1/Source\Controls\Util\XTPWindowPos.cpp (function ??0CXTPWindowPos@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Util/XTPWindowPos.cpp
