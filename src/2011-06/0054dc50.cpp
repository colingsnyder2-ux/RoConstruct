// from server: 100% by auto
// roc 2011-06 0054dc50  unit: G3D::_internal::DialogTemplate  size: 215 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0054dc50
//
// 0054dc50  56                   push esi
// 0054dc51  8bf1                 mov esi, ecx
// 0054dc53  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0054dc57  57                   push edi
// 0054dc58  8b7e04               mov edi, dword ptr [esi + 4]
// 0054dc5b  3bf9                 cmp edi, ecx
// 0054dc5d  0f84bf000000         je 0x54dd22
// 0054dc63  8b5608               mov edx, dword ptr [esi + 8]
// 0054dc66  53                   push ebx
// 0054dc67  33db                 xor ebx, ebx
// 0054dc69  3bca                 cmp ecx, edx
// 0054dc6b  894e04               mov dword ptr [esi + 4], ecx
// 0054dc6e  7e65                 jle 0x54dcd5
// 0054dc70  3bd3                 cmp edx, ebx
// 0054dc72  7506                 jne 0x54dc7a
// 0054dc74  894e08               mov dword ptr [esi + 8], ecx
// 0054dc77  57                   push edi
// 0054dc78  eb7f                 jmp 0x54dcf9
// 0054dc7a  ba0a000000           mov edx, 0xa
// 0054dc7f  3bca                 cmp ecx, edx
// 0054dc81  7c4c                 jl 0x54dccf
// 0054dc83  8b4608               mov eax, dword ptr [esi + 8]
// 0054dc86  f30f1005746ea700     movss xmm0, dword ptr [0xa76e74]
// 0054dc8e  03c0                 add eax, eax
// 0054dc90  03c0                 add eax, eax
// 0054dc92  3d801a0600           cmp eax, 0x61a80
// 0054dc97  7e0a                 jle 0x54dca3
// 0054dc99  f30f1005948aa700     movss xmm0, dword ptr [0xa78a94]
// 0054dca1  eb0f                 jmp 0x54dcb2
// 0054dca3  3d00fa0000           cmp eax, 0xfa00
// 0054dca8  7e08                 jle 0x54dcb2
// 0054dcaa  f30f1005ec5ca700     movss xmm0, dword ptr [0xa75cec]
// 0054dcb2  8b4608               mov eax, dword ptr [esi + 8]
// 0054dcb5  55                   push ebp
// 0054dcb6  f30f2ac8             cvtsi2ss xmm1, eax
// 0054dcba  f30f59c8             mulss xmm1, xmm0
// 0054dcbe  f30f2ce9             cvttss2si ebp, xmm1
// 0054dcc2  2be8                 sub ebp, eax
// 0054dcc4  8d0429               lea eax, [ecx + ebp]
// 0054dcc7  3bc2                 cmp eax, edx
// 0054dcc9  894608               mov dword ptr [esi + 8], eax
// 0054dccc  5d                   pop ebp
// 0054dccd  7d03                 jge 0x54dcd2
// 0054dccf  895608               mov dword ptr [esi + 8], edx
// 0054dcd2  57                   push edi
// 0054dcd3  eb24                 jmp 0x54dcf9
// 0054dcd5  b856555555           mov eax, 0x55555556
// 0054dcda  f7ea                 imul edx
// 0054dcdc  8bc2                 mov eax, edx
// 0054dcde  c1e81f               shr eax, 0x1f
// 0054dce1  03c2                 add eax, edx
// 0054dce3  3bc8                 cmp ecx, eax
// 0054dce5  7f19                 jg 0x54dd00
// 0054dce7  385c2414             cmp byte ptr [esp + 0x14], bl
// 0054dceb  7413                 je 0x54dd00
// 0054dced  83f90a               cmp ecx, 0xa
// 0054dcf0  7e0e                 jle 0x54dd00
// 0054dcf2  3bcf                 cmp ecx, edi
// 0054dcf4  7c02                 jl 0x54dcf8
// 0054dcf6  8bcf                 mov ecx, edi
// 0054dcf8  51                   push ecx
// 0054dcf9  8bce                 mov ecx, esi
// 0054dcfb  e830feffff           call 0x54db30
// 0054dd00  3b7e04               cmp edi, dword ptr [esi + 4]
// 0054dd03  8bcf                 mov ecx, edi
// 0054dd05  7d1a                 jge 0x54dd21
// 0054dd07  8b16                 mov edx, dword ptr [esi]
// 0054dd09  8d048a               lea eax, [edx + ecx*4]
// 0054dd0c  3bc3                 cmp eax, ebx
// 0054dd0e  740b                 je 0x54dd1b
// 0054dd10  8818                 mov byte ptr [eax], bl
// 0054dd12  885801               mov byte ptr [eax + 1], bl
// 0054dd15  885802               mov byte ptr [eax + 2], bl
// 0054dd18  885803               mov byte ptr [eax + 3], bl
// 0054dd1b  41                   inc ecx
// 0054dd1c  3b4e04               cmp ecx, dword ptr [esi + 4]
// 0054dd1f  7ce6                 jl 0x54dd07
// 0054dd21  5b                   pop ebx
// 0054dd22  5f                   pop edi
// 0054dd23  5e                   pop esi
// 0054dd24  c20800               ret 8
// library rbx2016-g3d/GImage_bmp.cpp (function ?resize@?$Array@VColor4uint8@G3D@@$09$0CA@@G3D@@QAEXH_N@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d GImage_bmp.cpp
