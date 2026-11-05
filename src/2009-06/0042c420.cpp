// from server: 100% by auto
// roc 2009-06 0042c420  unit: CMultiPlayerPane  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0042c420
//
// 0042c420  56                   push esi
// 0042c421  8bf1                 mov esi, ecx
// 0042c423  e8f8ce2e00           call 0x719320
// 0042c428  c70684228b00         mov dword ptr [esi], 0x8b2284
// 0042c42e  c7465400000000       mov dword ptr [esi + 0x54], 0
// 0042c435  8bc6                 mov eax, esi
// 0042c437  5e                   pop esi
// 0042c438  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\ctlcore.cpp (function ??0CReflectorWnd@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/ctlcore.cpp
