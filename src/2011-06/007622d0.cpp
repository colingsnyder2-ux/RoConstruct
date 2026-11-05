// from server: 100% by auto
// roc 2011-06 007622d0  unit: seg_00760000  size: 79 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 007622d0
//
// 007622d0  56                   push esi
// 007622d1  8b74240c             mov esi, dword ptr [esp + 0xc]
// 007622d5  57                   push edi
// 007622d6  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 007622da  3bfe                 cmp edi, esi
// 007622dc  743e                 je 0x76231c
// 007622de  53                   push ebx
// 007622df  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 007622e3  8bc3                 mov eax, ebx
// 007622e5  f7d8                 neg eax
// 007622e7  c1e004               shl eax, 4
// 007622ea  014708               add dword ptr [edi + 8], eax
// 007622ed  85db                 test ebx, ebx
// 007622ef  7e2a                 jle 0x76231b
// 007622f1  33d2                 xor edx, edx
// 007622f3  55                   push ebp
// 007622f4  8b4e08               mov ecx, dword ptr [esi + 8]
// 007622f7  8b4708               mov eax, dword ptr [edi + 8]
// 007622fa  03c2                 add eax, edx
// 007622fc  8d6910               lea ebp, [ecx + 0x10]
// 007622ff  896e08               mov dword ptr [esi + 8], ebp
// 00762302  8b28                 mov ebp, dword ptr [eax]
// 00762304  8929                 mov dword ptr [ecx], ebp
// 00762306  8b6804               mov ebp, dword ptr [eax + 4]
// 00762309  896904               mov dword ptr [ecx + 4], ebp
// 0076230c  8b4008               mov eax, dword ptr [eax + 8]
// 0076230f  83c210               add edx, 0x10
// 00762312  83eb01               sub ebx, 1
// 00762315  894108               mov dword ptr [ecx + 8], eax
// 00762318  75da                 jne 0x7622f4
// 0076231a  5d                   pop ebp
// 0076231b  5b                   pop ebx
// 0076231c  5f                   pop edi
// 0076231d  5e                   pop esi
// 0076231e  c3                   ret 
// library lua-5.1/lapi.c (function _lua_xmove)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
