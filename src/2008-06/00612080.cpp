// from server: 100% by auto
// roc 2008-06 00612080  unit: seg_00610000  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00612080
//
// 00612080  8b442408             mov eax, dword ptr [esp + 8]
// 00612084  56                   push esi
// 00612085  57                   push edi
// 00612086  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0061208a  8bcf                 mov ecx, edi
// 0061208c  e8fff9ffff           call 0x611a90
// 00612091  8bf0                 mov esi, eax
// 00612093  8b4608               mov eax, dword ptr [esi + 8]
// 00612096  83c0fd               add eax, -3
// 00612099  83f804               cmp eax, 4
// 0061209c  7733                 ja 0x6120d1
// 0061209e  ff2485d8206100       jmp dword ptr [eax*4 + 0x6120d8]
// 006120a5  8b06                 mov eax, dword ptr [esi]
// 006120a7  8b400c               mov eax, dword ptr [eax + 0xc]
// 006120aa  5f                   pop edi
// 006120ab  5e                   pop esi
// 006120ac  c3                   ret 
// 006120ad  8b0e                 mov ecx, dword ptr [esi]
// 006120af  8b4110               mov eax, dword ptr [ecx + 0x10]
// 006120b2  5f                   pop edi
// 006120b3  5e                   pop esi
// 006120b4  c3                   ret 
// 006120b5  8b16                 mov edx, dword ptr [esi]
// 006120b7  52                   push edx
// 006120b8  e8f3cb0400           call 0x65ecb0
// 006120bd  83c404               add esp, 4
// 006120c0  5f                   pop edi
// 006120c1  5e                   pop esi
// 006120c2  c3                   ret 
// 006120c3  56                   push esi
// 006120c4  57                   push edi
// 006120c5  e8e6a50400           call 0x65c6b0
// 006120ca  83c408               add esp, 8
// 006120cd  85c0                 test eax, eax
// 006120cf  75d4                 jne 0x6120a5
// 006120d1  5f                   pop edi
// 006120d2  33c0                 xor eax, eax
// 006120d4  5e                   pop esi
// 006120d5  c3                   ret 
// 006120d6  8bff                 mov edi, edi
// 006120d8  c3                   ret 
// 006120d9  206100               and byte ptr [ecx], ah
// 006120dc  a5                   movsd dword ptr es:[edi], dword ptr [esi]
// 006120dd  206100               and byte ptr [ecx], ah
// 006120e0  b520                 mov ch, 0x20
// 006120e2  61                   popal 
// 006120e3  00d1                 add cl, dl
// 006120e5  206100               and byte ptr [ecx], ah
// 006120e8  ad                   lodsd eax, dword ptr [esi]
// 006120e9  206100               and byte ptr [ecx], ah
// library lua-5.1/lapi.c (function _lua_objlen)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
