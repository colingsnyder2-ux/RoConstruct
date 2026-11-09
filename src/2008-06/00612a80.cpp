// from server: 100% by auto
// roc 2008-06 00612a80  unit: seg_00610000  size: 240 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00612a80
//
// 00612a80  8b442408             mov eax, dword ptr [esp + 8]
// 00612a84  53                   push ebx
// 00612a85  8b5c2408             mov ebx, dword ptr [esp + 8]
// 00612a89  56                   push esi
// 00612a8a  8b7310               mov esi, dword ptr [ebx + 0x10]
// 00612a8d  57                   push edi
// 00612a8e  33ff                 xor edi, edi
// 00612a90  83f807               cmp eax, 7
// 00612a93  0f87ab000000         ja 0x612b44
// 00612a99  ff2485502b6100       jmp dword ptr [eax*4 + 0x612b50]
// 00612aa0  8bc7                 mov eax, edi
// 00612aa2  5f                   pop edi
// 00612aa3  c74640fdffffff       mov dword ptr [esi + 0x40], 0xfffffffd
// 00612aaa  5e                   pop esi
// 00612aab  5b                   pop ebx
// 00612aac  c3                   ret 
// 00612aad  8b4644               mov eax, dword ptr [esi + 0x44]
// 00612ab0  894640               mov dword ptr [esi + 0x40], eax
// 00612ab3  8bc7                 mov eax, edi
// 00612ab5  5f                   pop edi
// 00612ab6  5e                   pop esi
// 00612ab7  5b                   pop ebx
// 00612ab8  c3                   ret 
// 00612ab9  53                   push ebx
// 00612aba  e851990400           call 0x65c410
// 00612abf  83c404               add esp, 4
// 00612ac2  8bc7                 mov eax, edi
// 00612ac4  5f                   pop edi
// 00612ac5  5e                   pop esi
// 00612ac6  5b                   pop ebx
// 00612ac7  c3                   ret 
// 00612ac8  8b7e44               mov edi, dword ptr [esi + 0x44]
// 00612acb  c1ef0a               shr edi, 0xa
// 00612ace  8bc7                 mov eax, edi
// 00612ad0  5f                   pop edi
// 00612ad1  5e                   pop esi
// 00612ad2  5b                   pop ebx
// 00612ad3  c3                   ret 
// 00612ad4  8b7e44               mov edi, dword ptr [esi + 0x44]
// 00612ad7  81e7ff030000         and edi, 0x3ff
// 00612add  8bc7                 mov eax, edi
// 00612adf  5f                   pop edi
// 00612ae0  5e                   pop esi
// 00612ae1  5b                   pop ebx
// 00612ae2  c3                   ret 
// 00612ae3  8b442418             mov eax, dword ptr [esp + 0x18]
// 00612ae7  8b4e44               mov ecx, dword ptr [esi + 0x44]
// 00612aea  c1e00a               shl eax, 0xa
// 00612aed  3bc1                 cmp eax, ecx
// 00612aef  7709                 ja 0x612afa
// 00612af1  8bd1                 mov edx, ecx
// 00612af3  2bd0                 sub edx, eax
// 00612af5  895640               mov dword ptr [esi + 0x40], edx
// 00612af8  eb03                 jmp 0x612afd
// 00612afa  897e40               mov dword ptr [esi + 0x40], edi
// 00612afd  394e40               cmp dword ptr [esi + 0x40], ecx
// 00612b00  7711                 ja 0x612b13
// 00612b02  53                   push ebx
// 00612b03  e888980400           call 0x65c390
// 00612b08  8b4640               mov eax, dword ptr [esi + 0x40]
// 00612b0b  83c404               add esp, 4
// 00612b0e  3b4644               cmp eax, dword ptr [esi + 0x44]
// 00612b11  76ef                 jbe 0x612b02
// 00612b13  807e1500             cmp byte ptr [esi + 0x15], 0
// 00612b17  752e                 jne 0x612b47
// 00612b19  bf01000000           mov edi, 1
// 00612b1e  8bc7                 mov eax, edi
// 00612b20  5f                   pop edi
// 00612b21  5e                   pop esi
// 00612b22  5b                   pop ebx
// 00612b23  c3                   ret 
// 00612b24  8b7e50               mov edi, dword ptr [esi + 0x50]
// 00612b27  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00612b2b  8bc7                 mov eax, edi
// 00612b2d  5f                   pop edi
// 00612b2e  894e50               mov dword ptr [esi + 0x50], ecx
// 00612b31  5e                   pop esi
// 00612b32  5b                   pop ebx
// 00612b33  c3                   ret 
// 00612b34  8b7e54               mov edi, dword ptr [esi + 0x54]
// 00612b37  8b542418             mov edx, dword ptr [esp + 0x18]
// 00612b3b  8bc7                 mov eax, edi
// 00612b3d  5f                   pop edi
// 00612b3e  895654               mov dword ptr [esi + 0x54], edx
// 00612b41  5e                   pop esi
// 00612b42  5b                   pop ebx
// 00612b43  c3                   ret 
// 00612b44  83cfff               or edi, 0xffffffff
// 00612b47  8bc7                 mov eax, edi
// 00612b49  5f                   pop edi
// 00612b4a  5e                   pop esi
// 00612b4b  5b                   pop ebx
// 00612b4c  c3                   ret 
// 00612b4d  8d4900               lea ecx, [ecx]
// 00612b50  a02a6100ad           mov al, byte ptr [0xad00612a]
// 00612b55  2a6100               sub ah, byte ptr [ecx]
// 00612b58  b92a6100c8           mov ecx, 0xc800612a
// 00612b5d  2a6100               sub ah, byte ptr [ecx]
// 00612b60  d42a                 aam 0x2a
// 00612b62  61                   popal 
// 00612b63  00e3                 add bl, ah
// 00612b65  2a6100               sub ah, byte ptr [ecx]
// 00612b68  242b                 and al, 0x2b
// 00612b6a  61                   popal 
// 00612b6b  00342b               add byte ptr [ebx + ebp], dh
// 00612b6e  61                   popal 
// library lua-5.1/lapi.c (function _lua_gc)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
