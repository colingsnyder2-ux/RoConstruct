// from server: 100% by auto
// roc 2007-03 00721960  unit: seg_00720000  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00721960
//
// 00721960  56                   push esi
// 00721961  6a0a                 push 0xa
// 00721963  8bf1                 mov esi, ecx
// 00721965  e81a990100           call 0x73b284
// 0072196a  c706b43e7e00         mov dword ptr [esi], 0x7e3eb4
// 00721970  8bc6                 mov eax, esi
// 00721972  5e                   pop esi
// 00721973  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\oletyplb.cpp (function ??0CTypeLibCacheMap@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/oletyplb.cpp
