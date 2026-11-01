// from server: 100% by auto
// roc 2009-06 0076d960  unit: CXTPControlToolbars  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0076d960
//
// 0076d960  56                   push esi
// 0076d961  8bf1                 mov esi, ecx
// 0076d963  e838100500           call 0x7be9a0
// 0076d968  c7060ca78f00         mov dword ptr [esi], 0x8fa70c
// 0076d96e  c74620aca68f00       mov dword ptr [esi + 0x20], 0x8fa6ac
// 0076d975  8bc6                 mov eax, esi
// 0076d977  5e                   pop esi
// 0076d978  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPControlExt.cpp (function ??0CXTPControlWindowList@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControlExt.cpp
