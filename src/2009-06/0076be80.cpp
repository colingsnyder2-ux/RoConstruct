// from server: 100% by auto
// roc 2009-06 0076be80  unit: CXTPControls  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0076be80
//
// 0076be80  56                   push esi
// 0076be81  8bf1                 mov esi, ecx
// 0076be83  e808ffffff           call 0x76bd90
// 0076be88  c706d4a18f00         mov dword ptr [esi], 0x8fa1d4
// 0076be8e  c7464001000000       mov dword ptr [esi + 0x40], 1
// 0076be95  8bc6                 mov eax, esi
// 0076be97  5e                   pop esi
// 0076be98  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPControls.cpp (function ??0CXTPOriginalControls@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControls.cpp
