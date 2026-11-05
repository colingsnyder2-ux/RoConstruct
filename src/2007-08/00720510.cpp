// from server: 100% by auto
// roc 2007-08 00720510  unit: CXTWndHook  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00720510
//
// 00720510  56                   push esi
// 00720511  6a0a                 push 0xa
// 00720513  8bf1                 mov esi, ecx
// 00720515  e830860100           call 0x738b4a
// 0072051a  c70694227e00         mov dword ptr [esi], 0x7e2294
// 00720520  8bc6                 mov eax, esi
// 00720522  5e                   pop esi
// 00720523  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\oletyplb.cpp (function ??0CTypeLibCacheMap@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/oletyplb.cpp
