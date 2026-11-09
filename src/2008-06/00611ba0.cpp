// from server: 100% by auto
// roc 2008-06 00611ba0  unit: seg_00610000  size: 79 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00611ba0
//
// 00611ba0  56                   push esi
// 00611ba1  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00611ba5  57                   push edi
// 00611ba6  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00611baa  3bfe                 cmp edi, esi
// 00611bac  743e                 je 0x611bec
// 00611bae  53                   push ebx
// 00611baf  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 00611bb3  8bc3                 mov eax, ebx
// 00611bb5  f7d8                 neg eax
// 00611bb7  c1e004               shl eax, 4
// 00611bba  014708               add dword ptr [edi + 8], eax
// 00611bbd  85db                 test ebx, ebx
// 00611bbf  7e2a                 jle 0x611beb
// 00611bc1  33d2                 xor edx, edx
// 00611bc3  55                   push ebp
// 00611bc4  8b4e08               mov ecx, dword ptr [esi + 8]
// 00611bc7  8b4708               mov eax, dword ptr [edi + 8]
// 00611bca  03c2                 add eax, edx
// 00611bcc  8d6910               lea ebp, [ecx + 0x10]
// 00611bcf  896e08               mov dword ptr [esi + 8], ebp
// 00611bd2  8b28                 mov ebp, dword ptr [eax]
// 00611bd4  8929                 mov dword ptr [ecx], ebp
// 00611bd6  8b6804               mov ebp, dword ptr [eax + 4]
// 00611bd9  896904               mov dword ptr [ecx + 4], ebp
// 00611bdc  8b4008               mov eax, dword ptr [eax + 8]
// 00611bdf  83c210               add edx, 0x10
// 00611be2  83eb01               sub ebx, 1
// 00611be5  894108               mov dword ptr [ecx + 8], eax
// 00611be8  75da                 jne 0x611bc4
// 00611bea  5d                   pop ebp
// 00611beb  5b                   pop ebx
// 00611bec  5f                   pop edi
// 00611bed  5e                   pop esi
// 00611bee  c3                   ret 
// library lua-5.1/lapi.c (function _lua_xmove)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
