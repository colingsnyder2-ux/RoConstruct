// from server: 100% by auto
// roc 2010-06 00840cf0  unit: PAVCXTPHookManagerHookAble::?$CArray  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00840cf0
//
// 00840cf0  56                   push esi
// 00840cf1  6a0a                 push 0xa
// 00840cf3  8bf1                 mov esi, ecx
// 00840cf5  e8e6fdffff           call 0x840ae0
// 00840cfa  8bc6                 mov eax, esi
// 00840cfc  5e                   pop esi
// 00840cfd  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxpanecontainer.cpp (function ??0CPaneContainerGC@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxpanecontainer.cpp
