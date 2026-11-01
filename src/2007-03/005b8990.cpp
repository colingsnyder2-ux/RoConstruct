// from server: 100% by auto
// roc 2007-03 005b8990  unit: seg_005b0000  size: 79 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005b8990
//
// 005b8990  56                   push esi
// 005b8991  8b74240c             mov esi, dword ptr [esp + 0xc]
// 005b8995  57                   push edi
// 005b8996  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 005b899a  3bfe                 cmp edi, esi
// 005b899c  743e                 je 0x5b89dc
// 005b899e  53                   push ebx
// 005b899f  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 005b89a3  8bc3                 mov eax, ebx
// 005b89a5  f7d8                 neg eax
// 005b89a7  c1e004               shl eax, 4
// 005b89aa  014708               add dword ptr [edi + 8], eax
// 005b89ad  85db                 test ebx, ebx
// 005b89af  7e2a                 jle 0x5b89db
// 005b89b1  33d2                 xor edx, edx
// 005b89b3  55                   push ebp
// 005b89b4  8b4e08               mov ecx, dword ptr [esi + 8]
// 005b89b7  8b4708               mov eax, dword ptr [edi + 8]
// 005b89ba  03c2                 add eax, edx
// 005b89bc  8d6910               lea ebp, [ecx + 0x10]
// 005b89bf  896e08               mov dword ptr [esi + 8], ebp
// 005b89c2  8b28                 mov ebp, dword ptr [eax]
// 005b89c4  8929                 mov dword ptr [ecx], ebp
// 005b89c6  8b6804               mov ebp, dword ptr [eax + 4]
// 005b89c9  896904               mov dword ptr [ecx + 4], ebp
// 005b89cc  8b4008               mov eax, dword ptr [eax + 8]
// 005b89cf  83c210               add edx, 0x10
// 005b89d2  83eb01               sub ebx, 1
// 005b89d5  894108               mov dword ptr [ecx + 8], eax
// 005b89d8  75da                 jne 0x5b89b4
// 005b89da  5d                   pop ebp
// 005b89db  5b                   pop ebx
// 005b89dc  5f                   pop edi
// 005b89dd  5e                   pop esi
// 005b89de  c3                   ret 
// library lua-5.1.1/lapi.c (function _lua_xmove)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lapi.c
