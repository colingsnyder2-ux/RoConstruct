// from server: 100% by auto
// roc 2008-06 0071c660  unit: PAVCXTPHookManagerHookAble::?$CArray  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0071c660
//
// 0071c660  56                   push esi
// 0071c661  6a0a                 push 0xa
// 0071c663  8bf1                 mov esi, ecx
// 0071c665  e826feffff           call 0x71c490
// 0071c66a  8bc6                 mov eax, esi
// 0071c66c  5e                   pop esi
// 0071c66d  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxpanecontainer.cpp (function ??0CPaneContainerGC@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxpanecontainer.cpp
