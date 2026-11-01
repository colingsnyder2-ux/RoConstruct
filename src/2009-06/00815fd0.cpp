// from server: 100% by auto
// roc 2009-06 00815fd0  unit: CXTPRibbonControlSystemRecentFileList  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00815fd0
//
// 00815fd0  56                   push esi
// 00815fd1  8bf1                 mov esi, ecx
// 00815fd3  e858ffffff           call 0x815f30
// 00815fd8  c70624e49000         mov dword ptr [esi], 0x90e424
// 00815fde  c74620c4e39000       mov dword ptr [esi + 0x20], 0x90e3c4
// 00815fe5  8bc6                 mov eax, esi
// 00815fe7  5e                   pop esi
// 00815fe8  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPControlExt.cpp (function ??0CXTPControlWindowList@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControlExt.cpp
