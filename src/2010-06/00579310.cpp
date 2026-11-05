// from server: 100% by auto
// roc 2010-06 00579310  unit: seg_00570000  size: 502 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00579310
//
// 00579310  56                   push esi
// 00579311  8b742408             mov esi, dword ptr [esp + 8]
// 00579315  8b4668               mov eax, dword ptr [esi + 0x68]
// 00579318  a801                 test al, 1
// 0057931a  750d                 jne 0x579329
// 0057931c  68d072a200           push 0xa272d0
// 00579321  56                   push esi
// 00579322  e88987ffff           call 0x571ab0
// 00579327  eb2e                 jmp 0x579357
// 00579329  a804                 test al, 4
// 0057932b  741b                 je 0x579348
// 0057932d  68b872a200           push 0xa272b8
// 00579332  56                   push esi
// 00579333  e82888ffff           call 0x571b60
// 00579338  8b442418             mov eax, dword ptr [esp + 0x18]
// 0057933c  50                   push eax
// 0057933d  56                   push esi
// 0057933e  e8cdf1ffff           call 0x578510
// 00579343  83c410               add esp, 0x10
// 00579346  5e                   pop esi
// 00579347  c3                   ret 
// 00579348  a802                 test al, 2
// 0057934a  740e                 je 0x57935a
// 0057934c  68a072a200           push 0xa272a0
// 00579351  56                   push esi
// 00579352  e80988ffff           call 0x571b60
// 00579357  83c408               add esp, 8
// 0057935a  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0057935e  53                   push ebx
// 0057935f  33db                 xor ebx, ebx
// 00579361  3bc3                 cmp eax, ebx
// 00579363  7425                 je 0x57938a
// 00579365  f7400800100000       test dword ptr [eax + 8], 0x1000
// 0057936c  741c                 je 0x57938a
// 0057936e  688872a200           push 0xa27288
// 00579373  56                   push esi
// 00579374  e8e787ffff           call 0x571b60
// 00579379  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0057937d  51                   push ecx
// 0057937e  56                   push esi
// 0057937f  e88cf1ffff           call 0x578510
// 00579384  83c410               add esp, 0x10
// 00579387  5b                   pop ebx
// 00579388  5e                   pop esi
// 00579389  c3                   ret 
// 0057938a  8b9688020000         mov edx, dword ptr [esi + 0x288]
// 00579390  55                   push ebp
// 00579391  57                   push edi
// 00579392  52                   push edx
// 00579393  56                   push esi
// 00579394  e86792ffff           call 0x572600
// 00579399  8b6c2424             mov ebp, dword ptr [esp + 0x24]
// 0057939d  8d4501               lea eax, [ebp + 1]
// 005793a0  50                   push eax
// 005793a1  56                   push esi
// 005793a2  e8f991ffff           call 0x5725a0
// 005793a7  8bf8                 mov edi, eax
// 005793a9  55                   push ebp
// 005793aa  57                   push edi
// 005793ab  56                   push esi
// 005793ac  89be88020000         mov dword ptr [esi + 0x288], edi
// 005793b2  e85930ffff           call 0x56c410
// 005793b7  55                   push ebp
// 005793b8  57                   push edi
// 005793b9  56                   push esi
// 005793ba  e821bcfeff           call 0x564fe0
// 005793bf  53                   push ebx
// 005793c0  56                   push esi
// 005793c1  e84af1ffff           call 0x578510
// 005793c6  83c430               add esp, 0x30
// 005793c9  85c0                 test eax, eax
// 005793cb  741b                 je 0x5793e8
// 005793cd  8b8e88020000         mov ecx, dword ptr [esi + 0x288]
// 005793d3  51                   push ecx
// 005793d4  56                   push esi
// 005793d5  e82692ffff           call 0x572600
// 005793da  83c408               add esp, 8
// 005793dd  5f                   pop edi
// 005793de  5d                   pop ebp
// 005793df  899e88020000         mov dword ptr [esi + 0x288], ebx
// 005793e5  5b                   pop ebx
// 005793e6  5e                   pop esi
// 005793e7  c3                   ret 
// 005793e8  8b9688020000         mov edx, dword ptr [esi + 0x288]
// 005793ee  881c2a               mov byte ptr [edx + ebp], bl
// 005793f1  8b8688020000         mov eax, dword ptr [esi + 0x288]
// 005793f7  8bf8                 mov edi, eax
// 005793f9  381f                 cmp byte ptr [edi], bl
// 005793fb  7408                 je 0x579405
// 005793fd  8d4900               lea ecx, [ecx]
// 00579400  47                   inc edi
// 00579401  381f                 cmp byte ptr [edi], bl
// 00579403  75fb                 jne 0x579400
// 00579405  47                   inc edi
// 00579406  8d4c28ff             lea ecx, [eax + ebp - 1]
// 0057940a  3bf9                 cmp edi, ecx
// 0057940c  7220                 jb 0x57942e
// 0057940e  50                   push eax
// 0057940f  56                   push esi
// 00579410  e8eb91ffff           call 0x572600
// 00579415  687072a200           push 0xa27270
// 0057941a  56                   push esi
// 0057941b  899e88020000         mov dword ptr [esi + 0x288], ebx
// 00579421  e83a87ffff           call 0x571b60
// 00579426  83c410               add esp, 0x10
// 00579429  5f                   pop edi
// 0057942a  5d                   pop ebp
// 0057942b  5b                   pop ebx
// 0057942c  5e                   pop esi
// 0057942d  c3                   ret 
// 0057942e  8a07                 mov al, byte ptr [edi]
// 00579430  47                   inc edi
// 00579431  84c0                 test al, al
// 00579433  7410                 je 0x579445
// 00579435  684072a200           push 0xa27240
// 0057943a  56                   push esi
// 0057943b  e82087ffff           call 0x571b60
// 00579440  83c408               add esp, 8
// 00579443  32c0                 xor al, al
// 00579445  2bbe88020000         sub edi, dword ptr [esi + 0x288]
// 0057944b  8d542414             lea edx, [esp + 0x14]
// 0057944f  52                   push edx
// 00579450  57                   push edi
// 00579451  0fb6d8               movzx ebx, al
// 00579454  55                   push ebp
// 00579455  53                   push ebx
// 00579456  56                   push esi
// 00579457  e804e0ffff           call 0x577460
// 0057945c  8b442428             mov eax, dword ptr [esp + 0x28]
// 00579460  8bc8                 mov ecx, eax
// 00579462  83c414               add esp, 0x14
// 00579465  2bcf                 sub ecx, edi
// 00579467  3bf8                 cmp edi, eax
// 00579469  7771                 ja 0x5794dc
// 0057946b  83f904               cmp ecx, 4
// 0057946e  726c                 jb 0x5794dc
// 00579470  8bae88020000         mov ebp, dword ptr [esi + 0x288]
// 00579476  0fb6042f             movzx eax, byte ptr [edi + ebp]
// 0057947a  8d142f               lea edx, [edi + ebp]
// 0057947d  0fb67a01             movzx edi, byte ptr [edx + 1]
// 00579481  c1e008               shl eax, 8
// 00579484  0bc7                 or eax, edi
// 00579486  0fb67a02             movzx edi, byte ptr [edx + 2]
// 0057948a  c1e008               shl eax, 8
// 0057948d  0bc7                 or eax, edi
// 0057948f  0fb67a03             movzx edi, byte ptr [edx + 3]
// 00579493  c1e008               shl eax, 8
// 00579496  0bc7                 or eax, edi
// 00579498  3bc1                 cmp eax, ecx
// 0057949a  7330                 jae 0x5794cc
// 0057949c  8bc8                 mov ecx, eax
// 0057949e  8b442418             mov eax, dword ptr [esp + 0x18]
// 005794a2  51                   push ecx
// 005794a3  52                   push edx
// 005794a4  53                   push ebx
// 005794a5  55                   push ebp
// 005794a6  50                   push eax
// 005794a7  56                   push esi
// 005794a8  e893b1feff           call 0x564640
// 005794ad  8b8e88020000         mov ecx, dword ptr [esi + 0x288]
// 005794b3  51                   push ecx
// 005794b4  56                   push esi
// 005794b5  e84691ffff           call 0x572600
// 005794ba  83c420               add esp, 0x20
// 005794bd  5f                   pop edi
// 005794be  5d                   pop ebp
// 005794bf  5b                   pop ebx
// 005794c0  c7868802000000000000 mov dword ptr [esi + 0x288], 0
// 005794ca  5e                   pop esi
// 005794cb  c3                   ret 
// 005794cc  76d0                 jbe 0x57949e
// 005794ce  55                   push ebp
// 005794cf  56                   push esi
// 005794d0  e82b91ffff           call 0x572600
// 005794d5  681c72a200           push 0xa2721c
// 005794da  eb12                 jmp 0x5794ee
// 005794dc  8b9688020000         mov edx, dword ptr [esi + 0x288]
// 005794e2  52                   push edx
// 005794e3  56                   push esi
// 005794e4  e81791ffff           call 0x572600
// 005794e9  68f071a200           push 0xa271f0
// 005794ee  56                   push esi
// 005794ef  c7868802000000000000 mov dword ptr [esi + 0x288], 0
// 005794f9  e86286ffff           call 0x571b60
// 005794fe  83c410               add esp, 0x10
// 00579501  5f                   pop edi
// 00579502  5d                   pop ebp
// 00579503  5b                   pop ebx
// 00579504  5e                   pop esi
// 00579505  c3                   ret 
// library libpng-1.2.32/pngrutil.c (function _png_handle_iCCP)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.32 pngrutil.c
