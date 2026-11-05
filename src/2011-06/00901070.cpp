// from server: 100% by auto
// roc 2011-06 00901070  unit: CXTWndHook  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00901070
//
// 00901070  56                   push esi
// 00901071  6a0a                 push 0xa
// 00901073  8bf1                 mov esi, ecx
// 00901075  e860ba0c00           call 0x9ccada
// 0090107a  c70674e1ad00         mov dword ptr [esi], 0xade174
// 00901080  8bc6                 mov eax, esi
// 00901082  5e                   pop esi
// 00901083  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\oletyplb.cpp (function ??0CTypeLibCacheMap@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/oletyplb.cpp
