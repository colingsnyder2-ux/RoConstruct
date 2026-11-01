// from server: 100% by auto
// roc 2010-06 007c8170  unit: CXTPCommandBars  size: 60 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007c8170
//
// 007c8170  8b89a0000000         mov ecx, dword ptr [ecx + 0xa0]
// 007c8176  56                   push esi
// 007c8177  51                   push ecx
// 007c8178  e8874d1b00           call 0x97cf04
// 007c817d  50                   push eax
// 007c817e  e8fbfbfdff           call 0x7a7d7e
// 007c8183  8bf0                 mov esi, eax
// 007c8185  83c408               add esp, 8
// 007c8188  85f6                 test esi, esi
// 007c818a  741e                 je 0x7c81aa
// 007c818c  f686e400000008       test byte ptr [esi + 0xe4], 8
// 007c8193  7415                 je 0x7c81aa
// 007c8195  8b06                 mov eax, dword ptr [esi]
// 007c8197  8b9058010000         mov edx, dword ptr [eax + 0x158]
// 007c819d  6a00                 push 0
// 007c819f  8bce                 mov ecx, esi
// 007c81a1  ffd2                 call edx
// 007c81a3  83a6e4000000f7       and dword ptr [esi + 0xe4], 0xfffffff7
// 007c81aa  5e                   pop esi
// 007c81ab  c3                   ret 
// library xtp-13.2.1-shared-mfc/Source\CommandBars\XTPCommandBars.cpp (function ?IdleRecalcLayout@CXTPCommandBars@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/CommandBars/XTPCommandBars.cpp
