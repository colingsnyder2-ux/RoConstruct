// from server: 100% by auto
// roc 2009-12 00789430  unit: RBX::UniversalTool  size: 135 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00789430
//
// 00789430  8b442408             mov eax, dword ptr [esp + 8]
// 00789434  56                   push esi
// 00789435  8b742408             mov esi, dword ptr [esp + 8]
// 00789439  57                   push edi
// 0078943a  8bce                 mov ecx, esi
// 0078943c  bf01000000           mov edi, 1
// 00789441  e8aaf1ffff           call 0x7885f0
// 00789446  8b4808               mov ecx, dword ptr [eax + 8]
// 00789449  83e906               sub ecx, 6
// 0078944c  7436                 je 0x789484
// 0078944e  2bcf                 sub ecx, edi
// 00789450  7425                 je 0x789477
// 00789452  2bcf                 sub ecx, edi
// 00789454  740b                 je 0x789461
// 00789456  33ff                 xor edi, edi
// 00789458  834608f0             add dword ptr [esi + 8], -0x10
// 0078945c  8bc7                 mov eax, edi
// 0078945e  5f                   pop edi
// 0078945f  5e                   pop esi
// 00789460  c3                   ret 
// 00789461  8b08                 mov ecx, dword ptr [eax]
// 00789463  8b5608               mov edx, dword ptr [esi + 8]
// 00789466  8b52f0               mov edx, dword ptr [edx - 0x10]
// 00789469  83c148               add ecx, 0x48
// 0078946c  8911                 mov dword ptr [ecx], edx
// 0078946e  c7410805000000       mov dword ptr [ecx + 8], 5
// 00789475  eb18                 jmp 0x78948f
// 00789477  8b4e08               mov ecx, dword ptr [esi + 8]
// 0078947a  8b10                 mov edx, dword ptr [eax]
// 0078947c  8b49f0               mov ecx, dword ptr [ecx - 0x10]
// 0078947f  894a0c               mov dword ptr [edx + 0xc], ecx
// 00789482  eb0b                 jmp 0x78948f
// 00789484  8b5608               mov edx, dword ptr [esi + 8]
// 00789487  8b08                 mov ecx, dword ptr [eax]
// 00789489  8b52f0               mov edx, dword ptr [edx - 0x10]
// 0078948c  89510c               mov dword ptr [ecx + 0xc], edx
// 0078948f  8b4e08               mov ecx, dword ptr [esi + 8]
// 00789492  8b49f0               mov ecx, dword ptr [ecx - 0x10]
// 00789495  f6410503             test byte ptr [ecx + 5], 3
// 00789499  7413                 je 0x7894ae
// 0078949b  8b00                 mov eax, dword ptr [eax]
// 0078949d  f6400504             test byte ptr [eax + 5], 4
// 007894a1  740b                 je 0x7894ae
// 007894a3  51                   push ecx
// 007894a4  50                   push eax
// 007894a5  56                   push esi
// 007894a6  e855480400           call 0x7cdd00
// 007894ab  83c40c               add esp, 0xc
// 007894ae  834608f0             add dword ptr [esi + 8], -0x10
// 007894b2  8bc7                 mov eax, edi
// 007894b4  5f                   pop edi
// 007894b5  5e                   pop esi
// 007894b6  c3                   ret 
// library lua-5.1.3/lapi.c (function _lua_setfenv)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.3 lapi.c
