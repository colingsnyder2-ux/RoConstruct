// from server: 100% by auto
// roc 2012-06 00831a60  unit: RBX::PAVPrimitive::$$A6AXU?$pair::?$signal::Vslot::?$callable  size: 79 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00831a60
//
// 00831a60  56                   push esi
// 00831a61  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00831a65  57                   push edi
// 00831a66  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00831a6a  3bfe                 cmp edi, esi
// 00831a6c  743e                 je 0x831aac
// 00831a6e  53                   push ebx
// 00831a6f  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 00831a73  8bc3                 mov eax, ebx
// 00831a75  f7d8                 neg eax
// 00831a77  c1e004               shl eax, 4
// 00831a7a  014708               add dword ptr [edi + 8], eax
// 00831a7d  85db                 test ebx, ebx
// 00831a7f  7e2a                 jle 0x831aab
// 00831a81  33d2                 xor edx, edx
// 00831a83  55                   push ebp
// 00831a84  8b4e08               mov ecx, dword ptr [esi + 8]
// 00831a87  8b4708               mov eax, dword ptr [edi + 8]
// 00831a8a  03c2                 add eax, edx
// 00831a8c  8d6910               lea ebp, [ecx + 0x10]
// 00831a8f  896e08               mov dword ptr [esi + 8], ebp
// 00831a92  8b28                 mov ebp, dword ptr [eax]
// 00831a94  8929                 mov dword ptr [ecx], ebp
// 00831a96  8b6804               mov ebp, dword ptr [eax + 4]
// 00831a99  896904               mov dword ptr [ecx + 4], ebp
// 00831a9c  8b4008               mov eax, dword ptr [eax + 8]
// 00831a9f  83c210               add edx, 0x10
// 00831aa2  83eb01               sub ebx, 1
// 00831aa5  894108               mov dword ptr [ecx + 8], eax
// 00831aa8  75da                 jne 0x831a84
// 00831aaa  5d                   pop ebp
// 00831aab  5b                   pop ebx
// 00831aac  5f                   pop edi
// 00831aad  5e                   pop esi
// 00831aae  c3                   ret 
// library lua-5.1/lapi.c (function _lua_xmove)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
