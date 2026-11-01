// from server: 100% by auto
// roc 2009-12 0079a890  unit: lua_exception  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0079a890
//
// 0079a890  8b442408             mov eax, dword ptr [esp + 8]
// 0079a894  8b4060               mov eax, dword ptr [eax + 0x60]
// 0079a897  53                   push ebx
// 0079a898  8b5c2408             mov ebx, dword ptr [esp + 8]
// 0079a89c  8b5328               mov edx, dword ptr [ebx + 0x28]
// 0079a89f  55                   push ebp
// 0079a8a0  56                   push esi
// 0079a8a1  8d0c40               lea ecx, [eax + eax*2]
// 0079a8a4  57                   push edi
// 0079a8a5  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 0079a8a9  8d34ca               lea esi, [edx + ecx*8]
// 0079a8ac  e86fffffff           call 0x79a820
// 0079a8b1  8be8                 mov ebp, eax
// 0079a8b3  85ed                 test ebp, ebp
// 0079a8b5  7415                 je 0x79a8cc
// 0079a8b7  8b06                 mov eax, dword ptr [esi]
// 0079a8b9  c1e704               shl edi, 4
// 0079a8bc  8d4c07f0             lea ecx, [edi + eax - 0x10]
// 0079a8c0  51                   push ecx
// 0079a8c1  53                   push ebx
// 0079a8c2  e8a9ddfeff           call 0x788670
// 0079a8c7  83c408               add esp, 8
// 0079a8ca  8bc5                 mov eax, ebp
// 0079a8cc  5f                   pop edi
// 0079a8cd  5e                   pop esi
// 0079a8ce  5d                   pop ebp
// 0079a8cf  5b                   pop ebx
// 0079a8d0  c3                   ret 
// library lua-5.1/ldebug.c (function _lua_getlocal)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 ldebug.c
