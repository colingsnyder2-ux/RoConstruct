// from server: 100% by auto
// roc 2011-06 00829bf0  unit: CXTPCommandBars  size: 60 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00829bf0
//
// 00829bf0  8b89a0000000         mov ecx, dword ptr [ecx + 0xa0]
// 00829bf6  56                   push esi
// 00829bf7  51                   push ecx
// 00829bf8  e8292b1a00           call 0x9cc726
// 00829bfd  50                   push eax
// 00829bfe  e83908feff           call 0x80a43c
// 00829c03  8bf0                 mov esi, eax
// 00829c05  83c408               add esp, 8
// 00829c08  85f6                 test esi, esi
// 00829c0a  741e                 je 0x829c2a
// 00829c0c  f686e400000008       test byte ptr [esi + 0xe4], 8
// 00829c13  7415                 je 0x829c2a
// 00829c15  8b06                 mov eax, dword ptr [esi]
// 00829c17  8b9058010000         mov edx, dword ptr [eax + 0x158]
// 00829c1d  6a00                 push 0
// 00829c1f  8bce                 mov ecx, esi
// 00829c21  ffd2                 call edx
// 00829c23  83a6e4000000f7       and dword ptr [esi + 0xe4], 0xfffffff7
// 00829c2a  5e                   pop esi
// 00829c2b  c3                   ret 
// library xtp-15.2.1-shared-mfc/Source\CommandBars\XTPCommandBars.cpp (function ?IdleRecalcLayout@CXTPCommandBars@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/CommandBars/XTPCommandBars.cpp
