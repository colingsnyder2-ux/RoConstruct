// from server: 100% by auto
// roc 2007-03 00711a10  unit: seg_00710000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00711a10
//
// 00711a10  56                   push esi
// 00711a11  8bf1                 mov esi, ecx
// 00711a13  e83834faff           call 0x6b4e50
// 00711a18  c706f4ed7d00         mov dword ptr [esi], 0x7dedf4
// 00711a1e  c7462094ed7d00       mov dword ptr [esi + 0x20], 0x7ded94
// 00711a25  8bc6                 mov eax, esi
// 00711a27  5e                   pop esi
// 00711a28  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPControlExt.cpp (function ??0CXTPControlWindowList@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControlExt.cpp
