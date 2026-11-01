// from server: 100% by auto
// roc 2007-03 00711b50  unit: seg_00710000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00711b50
//
// 00711b50  56                   push esi
// 00711b51  8bf1                 mov esi, ecx
// 00711b53  e858ffffff           call 0x711ab0
// 00711b58  c706ecf27d00         mov dword ptr [esi], 0x7df2ec
// 00711b5e  c746208cf27d00       mov dword ptr [esi + 0x20], 0x7df28c
// 00711b65  8bc6                 mov eax, esi
// 00711b67  5e                   pop esi
// 00711b68  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPControlExt.cpp (function ??0CXTPControlWindowList@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControlExt.cpp
