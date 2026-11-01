// from server: 100% by auto
// roc 2009-12 00846c60  unit: CXTPControls  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00846c60
//
// 00846c60  56                   push esi
// 00846c61  8bf1                 mov esi, ecx
// 00846c63  e808ffffff           call 0x846b70
// 00846c68  c7067ca69f00         mov dword ptr [esi], 0x9fa67c
// 00846c6e  c7464001000000       mov dword ptr [esi + 0x40], 1
// 00846c75  8bc6                 mov eax, esi
// 00846c77  5e                   pop esi
// 00846c78  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPControls.cpp (function ??0CXTPOriginalControls@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControls.cpp
