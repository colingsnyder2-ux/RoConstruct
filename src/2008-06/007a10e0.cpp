// from server: 100% by auto
// roc 2008-06 007a10e0  unit: CXTWndHook  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 007a10e0
//
// 007a10e0  56                   push esi
// 007a10e1  6a0a                 push 0xa
// 007a10e3  8bf1                 mov esi, ecx
// 007a10e5  e824b70100           call 0x7bc80e
// 007a10ea  c70674f08600         mov dword ptr [esi], 0x86f074
// 007a10f0  8bc6                 mov eax, esi
// 007a10f2  5e                   pop esi
// 007a10f3  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\oletyplb.cpp (function ??0CTypeLibCacheMap@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/oletyplb.cpp
