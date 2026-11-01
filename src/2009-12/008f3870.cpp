// from server: 100% by auto
// roc 2009-12 008f3870  unit: CXTWndHook  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008f3870
//
// 008f3870  56                   push esi
// 008f3871  6a0a                 push 0xa
// 008f3873  8bf1                 mov esi, ecx
// 008f3875  e87c320300           call 0x926af6
// 008f387a  c70624faa000         mov dword ptr [esi], 0xa0fa24
// 008f3880  8bc6                 mov eax, esi
// 008f3882  5e                   pop esi
// 008f3883  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\oletyplb.cpp (function ??0CTypeLibCacheMap@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/oletyplb.cpp
