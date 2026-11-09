// from server: 100% by auto
// roc 2007-08 006a2f60  unit: PAVCXTPHookManagerHookAble::?$CArray  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006a2f60
//
// 006a2f60  56                   push esi
// 006a2f61  6a0a                 push 0xa
// 006a2f63  8bf1                 mov esi, ecx
// 006a2f65  e846fdffff           call 0x6a2cb0
// 006a2f6a  8bc6                 mov eax, esi
// 006a2f6c  5e                   pop esi
// 006a2f6d  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxpanecontainer.cpp (function ??0CPaneContainerGC@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxpanecontainer.cpp
