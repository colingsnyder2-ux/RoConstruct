// from server: 100% by auto
// roc 2010-06 007fad00  unit: CXTPControls  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007fad00
//
// 007fad00  56                   push esi
// 007fad01  8bf1                 mov esi, ecx
// 007fad03  e808ffffff           call 0x7fac10
// 007fad08  c7063ce9a500         mov dword ptr [esi], 0xa5e93c
// 007fad0e  c7464001000000       mov dword ptr [esi + 0x40], 1
// 007fad15  8bc6                 mov eax, esi
// 007fad17  5e                   pop esi
// 007fad18  c3                   ret 
// library xtp-13.2.1/Source\CommandBars\XTPControls.cpp (function ??0CXTPOriginalControls@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPControls.cpp
