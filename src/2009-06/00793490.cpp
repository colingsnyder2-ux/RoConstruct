// from server: 100% by auto
// roc 2009-06 00793490  unit: PAVCXTPHookManagerHookAble::?$CArray  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00793490
//
// 00793490  56                   push esi
// 00793491  6a0a                 push 0xa
// 00793493  8bf1                 mov esi, ecx
// 00793495  e8e6fdffff           call 0x793280
// 0079349a  8bc6                 mov eax, esi
// 0079349c  5e                   pop esi
// 0079349d  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxpanecontainer.cpp (function ??0CPaneContainerGC@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxpanecontainer.cpp
