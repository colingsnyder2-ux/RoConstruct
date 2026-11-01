// from server: 100% by auto
// roc 2009-12 00608db0  unit: seg_00600000  size: 356 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00608db0
//
// 00608db0  51                   push ecx
// 00608db1  8b542408             mov edx, dword ptr [esp + 8]
// 00608db5  8a4208               mov al, byte ptr [edx + 8]
// 00608db8  53                   push ebx
// 00608db9  8b1a                 mov ebx, dword ptr [edx]
// 00608dbb  55                   push ebp
// 00608dbc  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 00608dc0  56                   push esi
// 00608dc1  57                   push edi
// 00608dc2  895c2410             mov dword ptr [esp + 0x10], ebx
// 00608dc6  3c02                 cmp al, 2
// 00608dc8  757b                 jne 0x608e45
// 00608dca  85ed                 test ebp, ebp
// 00608dcc  7477                 je 0x608e45
// 00608dce  807a0908             cmp byte ptr [edx + 9], 8
// 00608dd2  7571                 jne 0x608e45
// 00608dd4  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00608dd8  8bf9                 mov edi, ecx
// 00608dda  85db                 test ebx, ebx
// 00608ddc  763f                 jbe 0x608e1d
// 00608dde  8bff                 mov edi, edi
// 00608de0  0fb601               movzx eax, byte ptr [ecx]
// 00608de3  0fb67101             movzx esi, byte ptr [ecx + 1]
// 00608de7  41                   inc ecx
// 00608de8  0fb65101             movzx edx, byte ptr [ecx + 1]
// 00608dec  25f8000000           and eax, 0xf8
// 00608df1  c1e005               shl eax, 5
// 00608df4  41                   inc ecx
// 00608df5  81e6f8000000         and esi, 0xf8
// 00608dfb  0bc6                 or eax, esi
// 00608dfd  03c0                 add eax, eax
// 00608dff  c1fa03               sar edx, 3
// 00608e02  03c0                 add eax, eax
// 00608e04  83e21f               and edx, 0x1f
// 00608e07  0bc2                 or eax, edx
// 00608e09  8a0428               mov al, byte ptr [eax + ebp]
// 00608e0c  8807                 mov byte ptr [edi], al
// 00608e0e  41                   inc ecx
// 00608e0f  47                   inc edi
// 00608e10  83eb01               sub ebx, 1
// 00608e13  75cb                 jne 0x608de0
// 00608e15  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 00608e19  8b542418             mov edx, dword ptr [esp + 0x18]
// 00608e1d  8a4209               mov al, byte ptr [edx + 9]
// 00608e20  88420b               mov byte ptr [edx + 0xb], al
// 00608e23  3c08                 cmp al, 8
// 00608e25  c6420803             mov byte ptr [edx + 8], 3
// 00608e29  c6420a01             mov byte ptr [edx + 0xa], 1
// 00608e2d  0fb6c0               movzx eax, al
// 00608e30  0f829d000000         jb 0x608ed3
// 00608e36  c1e803               shr eax, 3
// 00608e39  0fafc3               imul eax, ebx
// 00608e3c  5f                   pop edi
// 00608e3d  5e                   pop esi
// 00608e3e  5d                   pop ebp
// 00608e3f  894204               mov dword ptr [edx + 4], eax
// 00608e42  5b                   pop ebx
// 00608e43  59                   pop ecx
// 00608e44  c3                   ret 
// 00608e45  3c06                 cmp al, 6
// 00608e47  0f8598000000         jne 0x608ee5
// 00608e4d  85ed                 test ebp, ebp
// 00608e4f  0f8490000000         je 0x608ee5
// 00608e55  807a0908             cmp byte ptr [edx + 9], 8
// 00608e59  0f8586000000         jne 0x608ee5
// 00608e5f  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00608e63  8bf9                 mov edi, ecx
// 00608e65  85db                 test ebx, ebx
// 00608e67  7646                 jbe 0x608eaf
// 00608e69  8da42400000000       lea esp, [esp]
// 00608e70  0fb601               movzx eax, byte ptr [ecx]
// 00608e73  0fb67101             movzx esi, byte ptr [ecx + 1]
// 00608e77  41                   inc ecx
// 00608e78  0fb65101             movzx edx, byte ptr [ecx + 1]
// 00608e7c  25f8000000           and eax, 0xf8
// 00608e81  41                   inc ecx
// 00608e82  c1e005               shl eax, 5
// 00608e85  81e6f8000000         and esi, 0xf8
// 00608e8b  0bc6                 or eax, esi
// 00608e8d  03c0                 add eax, eax
// 00608e8f  c1fa03               sar edx, 3
// 00608e92  83e21f               and edx, 0x1f
// 00608e95  03c0                 add eax, eax
// 00608e97  0bc2                 or eax, edx
// 00608e99  8a1428               mov dl, byte ptr [eax + ebp]
// 00608e9c  8817                 mov byte ptr [edi], dl
// 00608e9e  83c102               add ecx, 2
// 00608ea1  47                   inc edi
// 00608ea2  83eb01               sub ebx, 1
// 00608ea5  75c9                 jne 0x608e70
// 00608ea7  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 00608eab  8b542418             mov edx, dword ptr [esp + 0x18]
// 00608eaf  8a4209               mov al, byte ptr [edx + 9]
// 00608eb2  88420b               mov byte ptr [edx + 0xb], al
// 00608eb5  3c08                 cmp al, 8
// 00608eb7  c6420803             mov byte ptr [edx + 8], 3
// 00608ebb  c6420a01             mov byte ptr [edx + 0xa], 1
// 00608ebf  0fb6c0               movzx eax, al
// 00608ec2  720f                 jb 0x608ed3
// 00608ec4  c1e803               shr eax, 3
// 00608ec7  0fafc3               imul eax, ebx
// 00608eca  5f                   pop edi
// 00608ecb  5e                   pop esi
// 00608ecc  5d                   pop ebp
// 00608ecd  894204               mov dword ptr [edx + 4], eax
// 00608ed0  5b                   pop ebx
// 00608ed1  59                   pop ecx
// 00608ed2  c3                   ret 
// 00608ed3  0fafc3               imul eax, ebx
// 00608ed6  5f                   pop edi
// 00608ed7  5e                   pop esi
// 00608ed8  83c007               add eax, 7
// 00608edb  c1e803               shr eax, 3
// 00608ede  5d                   pop ebp
// 00608edf  894204               mov dword ptr [edx + 4], eax
// 00608ee2  5b                   pop ebx
// 00608ee3  59                   pop ecx
// 00608ee4  c3                   ret 
// 00608ee5  3c03                 cmp al, 3
// 00608ee7  7525                 jne 0x608f0e
// 00608ee9  8b742424             mov esi, dword ptr [esp + 0x24]
// 00608eed  85f6                 test esi, esi
// 00608eef  741d                 je 0x608f0e
// 00608ef1  807a0908             cmp byte ptr [edx + 9], 8
// 00608ef5  7517                 jne 0x608f0e
// 00608ef7  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00608efb  85db                 test ebx, ebx
// 00608efd  760f                 jbe 0x608f0e
// 00608eff  90                   nop 
// 00608f00  0fb608               movzx ecx, byte ptr [eax]
// 00608f03  8a1431               mov dl, byte ptr [ecx + esi]
// 00608f06  8810                 mov byte ptr [eax], dl
// 00608f08  40                   inc eax
// 00608f09  83eb01               sub ebx, 1
// 00608f0c  75f2                 jne 0x608f00
// 00608f0e  5f                   pop edi
// 00608f0f  5e                   pop esi
// 00608f10  5d                   pop ebp
// 00608f11  5b                   pop ebx
// 00608f12  59                   pop ecx
// 00608f13  c3                   ret 
// library libpng-1.2.6/pngrtran.c (function _png_do_dither)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.6 pngrtran.c
