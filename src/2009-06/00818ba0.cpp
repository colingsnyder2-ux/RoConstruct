// from server: 100% by auto
// roc 2009-06 00818ba0  unit: CXTWndHook  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00818ba0
//
// 00818ba0  56                   push esi
// 00818ba1  6a0a                 push 0xa
// 00818ba3  8bf1                 mov esi, ecx
// 00818ba5  e8e0390300           call 0x84c58a
// 00818baa  c706b4f59000         mov dword ptr [esi], 0x90f5b4
// 00818bb0  8bc6                 mov eax, esi
// 00818bb2  5e                   pop esi
// 00818bb3  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\oletyplb.cpp (function ??0CTypeLibCacheMap@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/oletyplb.cpp
