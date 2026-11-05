// from server: 100% by auto
// roc 2010-06 008a5d00  unit: CXTPRibbonControlSystemRecentFileList  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008a5d00
//
// 008a5d00  56                   push esi
// 008a5d01  8bf1                 mov esi, ecx
// 008a5d03  e858ffffff           call 0x8a5c60
// 008a5d08  c7068434a700         mov dword ptr [esi], 0xa73484
// 008a5d0e  c746202434a700       mov dword ptr [esi + 0x20], 0xa73424
// 008a5d15  8bc6                 mov eax, esi
// 008a5d17  5e                   pop esi
// 008a5d18  c3                   ret 
// library xtp-13.2.1/Source\CommandBars\XTPControlExt.cpp (function ??0CXTPControlWindowList@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPControlExt.cpp
