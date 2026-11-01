// from server: 100% by auto
// roc 2009-12 007897f0  unit: RBX::UniversalTool  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007897f0
//
// 007897f0  56                   push esi
// 007897f1  8b742408             mov esi, dword ptr [esp + 8]
// 007897f5  8b4610               mov eax, dword ptr [esi + 0x10]
// 007897f8  8b4844               mov ecx, dword ptr [eax + 0x44]
// 007897fb  3b4840               cmp ecx, dword ptr [eax + 0x40]
// 007897fe  7209                 jb 0x789809
// 00789800  56                   push esi
// 00789801  e80a440400           call 0x7cdc10
// 00789806  83c404               add esp, 4
// 00789809  8b4614               mov eax, dword ptr [esi + 0x14]
// 0078980c  3b4628               cmp eax, dword ptr [esi + 0x28]
// 0078980f  7505                 jne 0x789816
// 00789811  8b4648               mov eax, dword ptr [esi + 0x48]
// 00789814  eb08                 jmp 0x78981e
// 00789816  8b5004               mov edx, dword ptr [eax + 4]
// 00789819  8b02                 mov eax, dword ptr [edx]
// 0078981b  8b400c               mov eax, dword ptr [eax + 0xc]
// 0078981e  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00789822  50                   push eax
// 00789823  51                   push ecx
// 00789824  56                   push esi
// 00789825  e856740400           call 0x7d0c80
// 0078982a  8b4e08               mov ecx, dword ptr [esi + 8]
// 0078982d  8901                 mov dword ptr [ecx], eax
// 0078982f  83c40c               add esp, 0xc
// 00789832  c7410807000000       mov dword ptr [ecx + 8], 7
// 00789839  83460810             add dword ptr [esi + 8], 0x10
// 0078983d  83c018               add eax, 0x18
// 00789840  5e                   pop esi
// 00789841  c3                   ret 
// library lua-5.1/lapi.c (function _lua_newuserdata)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
