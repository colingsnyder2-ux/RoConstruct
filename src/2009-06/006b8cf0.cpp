// from server: 100% by auto
// roc 2009-06 006b8cf0  unit: RBX::UniversalTool  size: 79 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006b8cf0
//
// 006b8cf0  56                   push esi
// 006b8cf1  8b74240c             mov esi, dword ptr [esp + 0xc]
// 006b8cf5  57                   push edi
// 006b8cf6  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 006b8cfa  3bfe                 cmp edi, esi
// 006b8cfc  743e                 je 0x6b8d3c
// 006b8cfe  53                   push ebx
// 006b8cff  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 006b8d03  8bc3                 mov eax, ebx
// 006b8d05  f7d8                 neg eax
// 006b8d07  c1e004               shl eax, 4
// 006b8d0a  014708               add dword ptr [edi + 8], eax
// 006b8d0d  85db                 test ebx, ebx
// 006b8d0f  7e2a                 jle 0x6b8d3b
// 006b8d11  33d2                 xor edx, edx
// 006b8d13  55                   push ebp
// 006b8d14  8b4e08               mov ecx, dword ptr [esi + 8]
// 006b8d17  8b4708               mov eax, dword ptr [edi + 8]
// 006b8d1a  03c2                 add eax, edx
// 006b8d1c  8d6910               lea ebp, [ecx + 0x10]
// 006b8d1f  896e08               mov dword ptr [esi + 8], ebp
// 006b8d22  8b28                 mov ebp, dword ptr [eax]
// 006b8d24  8929                 mov dword ptr [ecx], ebp
// 006b8d26  8b6804               mov ebp, dword ptr [eax + 4]
// 006b8d29  896904               mov dword ptr [ecx + 4], ebp
// 006b8d2c  8b4008               mov eax, dword ptr [eax + 8]
// 006b8d2f  83c210               add edx, 0x10
// 006b8d32  83eb01               sub ebx, 1
// 006b8d35  894108               mov dword ptr [ecx + 8], eax
// 006b8d38  75da                 jne 0x6b8d14
// 006b8d3a  5d                   pop ebp
// 006b8d3b  5b                   pop ebx
// 006b8d3c  5f                   pop edi
// 006b8d3d  5e                   pop esi
// 006b8d3e  c3                   ret 
// library lua-5.1/lapi.c (function _lua_xmove)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
