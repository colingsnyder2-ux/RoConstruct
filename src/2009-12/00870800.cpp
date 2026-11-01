// from server: 100% by auto
// roc 2009-12 00870800  unit: PAVCXTPHookManagerHookAble::?$CArray  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00870800
//
// 00870800  56                   push esi
// 00870801  6a0a                 push 0xa
// 00870803  8bf1                 mov esi, ecx
// 00870805  e826feffff           call 0x870630
// 0087080a  8bc6                 mov eax, esi
// 0087080c  5e                   pop esi
// 0087080d  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxpanecontainer.cpp (function ??0CPaneContainerGC@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxpanecontainer.cpp
