// from server: 100% by auto
// roc 2009-12 0083d9a0  unit: CXTPCustomizeSheet::CCustomizeEdit  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0083d9a0
//
// 0083d9a0  56                   push esi
// 0083d9a1  8bf1                 mov esi, ecx
// 0083d9a3  e8b8270500           call 0x890160
// 0083d9a8  c7062c8e9f00         mov dword ptr [esi], 0x9f8e2c
// 0083d9ae  c74620cc8d9f00       mov dword ptr [esi + 0x20], 0x9f8dcc
// 0083d9b5  8bc6                 mov eax, esi
// 0083d9b7  5e                   pop esi
// 0083d9b8  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPControlExt.cpp (function ??0CXTPControlWindowList@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControlExt.cpp
