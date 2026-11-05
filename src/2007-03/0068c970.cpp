// from server: 100% by auto
// roc 2007-03 0068c970  unit: seg_00680000  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0068c970
//
// 0068c970  56                   push esi
// 0068c971  6a0a                 push 0xa
// 0068c973  8bf1                 mov esi, ecx
// 0068c975  e826fdffff           call 0x68c6a0
// 0068c97a  8bc6                 mov eax, esi
// 0068c97c  5e                   pop esi
// 0068c97d  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxpanecontainer.cpp (function ??0CPaneContainerGC@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxpanecontainer.cpp
