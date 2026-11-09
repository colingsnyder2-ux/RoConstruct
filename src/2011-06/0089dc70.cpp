// from server: 100% by auto
// roc 2011-06 0089dc70  unit: PAVCXTPHookManagerHookAble::?$CArray  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0089dc70
//
// 0089dc70  56                   push esi
// 0089dc71  6a0a                 push 0xa
// 0089dc73  8bf1                 mov esi, ecx
// 0089dc75  e826feffff           call 0x89daa0
// 0089dc7a  8bc6                 mov eax, esi
// 0089dc7c  5e                   pop esi
// 0089dc7d  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxpanecontainer.cpp (function ??0CPaneContainerGC@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxpanecontainer.cpp
