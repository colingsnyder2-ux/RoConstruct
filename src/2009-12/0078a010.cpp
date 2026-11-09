// from server: 100% by auto
// roc 2009-12 0078a010  unit: RBX::UniversalTool  size: 87 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0078a010
//
// 0078a010  53                   push ebx
// 0078a011  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 0078a015  85db                 test ebx, ebx
// 0078a017  744c                 je 0x78a065
// 0078a019  55                   push ebp
// 0078a01a  8b6c2410             mov ebp, dword ptr [esp + 0x10]
// 0078a01e  56                   push esi
// 0078a01f  8b742410             mov esi, dword ptr [esp + 0x10]
// 0078a023  57                   push edi
// 0078a024  8b06                 mov eax, dword ptr [esi]
// 0078a026  8d8e0c020000         lea ecx, [esi + 0x20c]
// 0078a02c  4b                   dec ebx
// 0078a02d  3bc1                 cmp eax, ecx
// 0078a02f  7223                 jb 0x78a054
// 0078a031  2bc6                 sub eax, esi
// 0078a033  83e80c               sub eax, 0xc
// 0078a036  741c                 je 0x78a054
// 0078a038  50                   push eax
// 0078a039  8b4608               mov eax, dword ptr [esi + 8]
// 0078a03c  8d7e0c               lea edi, [esi + 0xc]
// 0078a03f  57                   push edi
// 0078a040  50                   push eax
// 0078a041  e85aedffff           call 0x788da0
// 0078a046  ff4604               inc dword ptr [esi + 4]
// 0078a049  56                   push esi
// 0078a04a  893e                 mov dword ptr [esi], edi
// 0078a04c  e80fffffff           call 0x789f60
// 0078a051  83c410               add esp, 0x10
// 0078a054  8a5500               mov dl, byte ptr [ebp]
// 0078a057  8b0e                 mov ecx, dword ptr [esi]
// 0078a059  8811                 mov byte ptr [ecx], dl
// 0078a05b  ff06                 inc dword ptr [esi]
// 0078a05d  45                   inc ebp
// 0078a05e  85db                 test ebx, ebx
// 0078a060  75c2                 jne 0x78a024
// 0078a062  5f                   pop edi
// 0078a063  5e                   pop esi
// 0078a064  5d                   pop ebp
// 0078a065  5b                   pop ebx
// 0078a066  c3                   ret 
// library lua-5.1/lauxlib.c (function _luaL_addlstring)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lauxlib.c
