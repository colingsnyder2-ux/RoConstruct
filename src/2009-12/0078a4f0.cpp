// from server: 100% by auto
// roc 2009-12 0078a4f0  unit: RBX::UniversalTool  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0078a4f0
//
// 0078a4f0  8b442408             mov eax, dword ptr [esp + 8]
// 0078a4f4  8b4804               mov ecx, dword ptr [eax + 4]
// 0078a4f7  85c9                 test ecx, ecx
// 0078a4f9  7503                 jne 0x78a4fe
// 0078a4fb  33c0                 xor eax, eax
// 0078a4fd  c3                   ret 
// 0078a4fe  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0078a502  890a                 mov dword ptr [edx], ecx
// 0078a504  c7400400000000       mov dword ptr [eax + 4], 0
// 0078a50b  8b00                 mov eax, dword ptr [eax]
// 0078a50d  c3                   ret 
// library lua-5.1/lauxlib.c (function _getS)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lauxlib.c
