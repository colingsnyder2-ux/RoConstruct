// from server: 100% by auto
// roc 2009-12 007a56d0  unit: seg_007a0000  size: 9 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007a56d0
//
// 007a56d0  8bc1                 mov eax, ecx
// 007a56d2  c700acd39e00         mov dword ptr [eax], 0x9ed3ac
// 007a56d8  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\afxabort.cpp (function ??0Thank_you@Define_the_symbol__ATL_MIXED@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/afxabort.cpp
