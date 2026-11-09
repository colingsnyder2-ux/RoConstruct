// from server: 100% by colin
// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: zlib-1.2.3-winapi inflate.c
// roc 2008-06 007a8380  unit: boost::iostreams::DUoutput::V?$basic_null_device::?$stream_buffer  size: 5600 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 007a8380
//
// 007a8380  8b542404             mov edx, dword ptr [esp + 4]
// 007a8384  83ec2c               sub esp, 0x2c
// 007a8387  85d2                 test edx, edx
// 007a8389  57                   push edi
// 007a838a  0f8440150000         je 0x7a98d0
// 007a8390  8b7a1c               mov edi, dword ptr [edx + 0x1c]
// 007a8393  85ff                 test edi, edi
// 007a8395  0f8435150000         je 0x7a98d0
// 007a839b  837a0c00             cmp dword ptr [edx + 0xc], 0
// 007a839f  0f842b150000         je 0x7a98d0
// 007a83a5  833a00               cmp dword ptr [edx], 0
// 007a83a8  750a                 jne 0x7a83b4
// 007a83aa  837a0400             cmp dword ptr [edx + 4], 0
// 007a83ae  0f851c150000         jne 0x7a98d0
// 007a83b4  833f0b               cmp dword ptr [edi], 0xb
// 007a83b7  7506                 jne 0x7a83bf
// 007a83b9  c7070c000000         mov dword ptr [edi], 0xc
// 007a83bf  8b4a10               mov ecx, dword ptr [edx + 0x10]
// 007a83c2  8b420c               mov eax, dword ptr [edx + 0xc]
// 007a83c5  53                   push ebx
// 007a83c6  8b5f38               mov ebx, dword ptr [edi + 0x38]
// 007a83c9  55                   push ebp
// 007a83ca  8b2a                 mov ebp, dword ptr [edx]
// 007a83cc  894c2418             mov dword ptr [esp + 0x18], ecx
// 007a83d0  894c2428             mov dword ptr [esp + 0x28], ecx
// 007a83d4  8b0f                 mov ecx, dword ptr [edi]
// 007a83d6  83f91c               cmp ecx, 0x1c
// 007a83d9  89442424             mov dword ptr [esp + 0x24], eax
// 007a83dd  8b4204               mov eax, dword ptr [edx + 4]
// 007a83e0  56                   push esi
// 007a83e1  8b773c               mov esi, dword ptr [edi + 0x3c]
// 007a83e4  89442410             mov dword ptr [esp + 0x10], eax
// 007a83e8  895c2418             mov dword ptr [esp + 0x18], ebx
// 007a83ec  89442438             mov dword ptr [esp + 0x38], eax
// 007a83f0  c744243000000000     mov dword ptr [esp + 0x30], 0
// 007a83f8  761a                 jbe 0x7a8414
// 007a83fa  b8feffffff           mov eax, 0xfffffffe
// 007a83ff  5e                   pop esi
// 007a8400  5d                   pop ebp
// 007a8401  5b                   pop ebx
// 007a8402  5f                   pop edi
// 007a8403  83c42c               add esp, 0x2c
// 007a8406  c20800               ret 8
// 007a8409  8da42400000000       lea esp, [esp]
// 007a8410  8b542440             mov edx, dword ptr [esp + 0x40]
// 007a8414  ff248ddc987a00       jmp dword ptr [ecx*4 + 0x7a98dc]
// 007a841b  837f0800             cmp dword ptr [edi + 8], 0
// 007a841f  750b                 jne 0x7a842c
// 007a8421  c7070c000000         mov dword ptr [edi], 0xc
// 007a8427  e942130000           jmp 0x7a976e
// 007a842c  83fe10               cmp esi, 0x10
// 007a842f  7328                 jae 0x7a8459
// 007a8431  85c0                 test eax, eax
// 007a8433  0f8493130000         je 0x7a97cc
// 007a8439  0fb65500             movzx edx, byte ptr [ebp]
// 007a843d  8bce                 mov ecx, esi
// 007a843f  d3e2                 shl edx, cl
// 007a8441  83e801               sub eax, 1
// 007a8444  83c608               add esi, 8
// 007a8447  83c501               add ebp, 1
// 007a844a  03da                 add ebx, edx
// 007a844c  83fe10               cmp esi, 0x10
// 007a844f  89442410             mov dword ptr [esp + 0x10], eax
// 007a8453  895c2418             mov dword ptr [esp + 0x18], ebx
// 007a8457  72d8                 jb 0x7a8431
// 007a8459  f6470802             test byte ptr [edi + 8], 2
// 007a845d  744a                 je 0x7a84a9
// 007a845f  81fb1f8b0000         cmp ebx, 0x8b1f
// 007a8465  7542                 jne 0x7a84a9
// 007a8467  6a00                 push 0
// 007a8469  6a00                 push 0
// 007a846b  6a00                 push 0
// 007a846d  e89efcffff           call 0x7a8110
// 007a8472  894718               mov dword ptr [edi + 0x18], eax
// 007a8475  6a02                 push 2
// 007a8477  8d442424             lea eax, [esp + 0x24]
// 007a847b  c64424241f           mov byte ptr [esp + 0x24], 0x1f
// 007a8480  c64424258b           mov byte ptr [esp + 0x25], 0x8b
// 007a8485  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 007a8488  50                   push eax
// 007a8489  51                   push ecx
// 007a848a  e881fcffff           call 0x7a8110
// 007a848f  33db                 xor ebx, ebx
// 007a8491  894718               mov dword ptr [edi + 0x18], eax
// 007a8494  8b442410             mov eax, dword ptr [esp + 0x10]
// 007a8498  895c2418             mov dword ptr [esp + 0x18], ebx
// 007a849c  33f6                 xor esi, esi
// 007a849e  c70701000000         mov dword ptr [edi], 1
// 007a84a4  e9c5120000           jmp 0x7a976e
// 007a84a9  8b4720               mov eax, dword ptr [edi + 0x20]
// 007a84ac  85c0                 test eax, eax
// 007a84ae  c7471000000000       mov dword ptr [edi + 0x10], 0
// 007a84b5  7407                 je 0x7a84be
// 007a84b7  c74030ffffffff       mov dword ptr [eax + 0x30], 0xffffffff
// 007a84be  f6470801             test byte ptr [edi + 8], 1
// 007a84c2  0f84a4000000         je 0x7a856c
// 007a84c8  0fb6c3               movzx eax, bl
// 007a84cb  c1e008               shl eax, 8
// 007a84ce  8bd3                 mov edx, ebx
// 007a84d0  c1ea08               shr edx, 8
// 007a84d3  03c2                 add eax, edx
// 007a84d5  33d2                 xor edx, edx
// 007a84d7  b91f000000           mov ecx, 0x1f
// 007a84dc  f7f1                 div ecx
// 007a84de  85d2                 test edx, edx
// 007a84e0  0f8586000000         jne 0x7a856c
// 007a84e6  8bd3                 mov edx, ebx
// 007a84e8  80e20f               and dl, 0xf
// 007a84eb  80fa08               cmp dl, 8
// 007a84ee  7414                 je 0x7a8504
// 007a84f0  8b442440             mov eax, dword ptr [esp + 0x40]
// 007a84f4  c740185cee8600       mov dword ptr [eax + 0x18], 0x86ee5c
// 007a84fb  8b442410             mov eax, dword ptr [esp + 0x10]
// 007a84ff  e964120000           jmp 0x7a9768
// 007a8504  c1eb04               shr ebx, 4
// 007a8507  8bcb                 mov ecx, ebx
// 007a8509  83e10f               and ecx, 0xf
// 007a850c  83c108               add ecx, 8
// 007a850f  83ee04               sub esi, 4
// 007a8512  3b4f24               cmp ecx, dword ptr [edi + 0x24]
// 007a8515  895c2418             mov dword ptr [esp + 0x18], ebx
// 007a8519  7614                 jbe 0x7a852f
// 007a851b  8b4c2440             mov ecx, dword ptr [esp + 0x40]
// 007a851f  8b442410             mov eax, dword ptr [esp + 0x10]
// 007a8523  c7411848ee8600       mov dword ptr [ecx + 0x18], 0x86ee48
// 007a852a  e939120000           jmp 0x7a9768
// 007a852f  ba01000000           mov edx, 1
// 007a8534  6a00                 push 0
// 007a8536  d3e2                 shl edx, cl
// 007a8538  6a00                 push 0
// 007a853a  6a00                 push 0
// 007a853c  895714               mov dword ptr [edi + 0x14], edx
// 007a853f  e86c140000           call 0x7a99b0
// 007a8544  8b4c2440             mov ecx, dword ptr [esp + 0x40]
// 007a8548  c1eb08               shr ebx, 8
// 007a854b  f7d3                 not ebx
// 007a854d  83e302               and ebx, 2
// 007a8550  83cb09               or ebx, 9
// 007a8553  894718               mov dword ptr [edi + 0x18], eax
// 007a8556  894130               mov dword ptr [ecx + 0x30], eax
// 007a8559  8b442410             mov eax, dword ptr [esp + 0x10]
// 007a855d  891f                 mov dword ptr [edi], ebx
// 007a855f  33db                 xor ebx, ebx
// 007a8561  895c2418             mov dword ptr [esp + 0x18], ebx
// 007a8565  33f6                 xor esi, esi
// 007a8567  e902120000           jmp 0x7a976e
// 007a856c  8b542440             mov edx, dword ptr [esp + 0x40]
// 007a8570  8b442410             mov eax, dword ptr [esp + 0x10]
// 007a8574  c7421830ee8600       mov dword ptr [edx + 0x18], 0x86ee30
// 007a857b  e9e8110000           jmp 0x7a9768
// 007a8580  83fe10               cmp esi, 0x10
// 007a8583  7328                 jae 0x7a85ad
// 007a8585  85c0                 test eax, eax
// 007a8587  0f843f120000         je 0x7a97cc
// 007a858d  0fb65500             movzx edx, byte ptr [ebp]
// 007a8591  8bce                 mov ecx, esi
// 007a8593  d3e2                 shl edx, cl
// 007a8595  83e801               sub eax, 1
// 007a8598  83c608               add esi, 8
// 007a859b  83c501               add ebp, 1
// 007a859e  03da                 add ebx, edx
// 007a85a0  83fe10               cmp esi, 0x10
// 007a85a3  89442410             mov dword ptr [esp + 0x10], eax
// 007a85a7  895c2418             mov dword ptr [esp + 0x18], ebx
// 007a85ab  72d8                 jb 0x7a8585
// 007a85ad  80fb08               cmp bl, 8
// 007a85b0  895f10               mov dword ptr [edi + 0x10], ebx
// 007a85b3  7410                 je 0x7a85c5
// 007a85b5  8b4c2440             mov ecx, dword ptr [esp + 0x40]
// 007a85b9  c741185cee8600       mov dword ptr [ecx + 0x18], 0x86ee5c
// 007a85c0  e9a3110000           jmp 0x7a9768
// 007a85c5  f7c300e00000         test ebx, 0xe000
// 007a85cb  7410                 je 0x7a85dd
// 007a85cd  8b542440             mov edx, dword ptr [esp + 0x40]
// 007a85d1  c7421814ee8600       mov dword ptr [edx + 0x18], 0x86ee14
// 007a85d8  e98b110000           jmp 0x7a9768
// 007a85dd  8b4f20               mov ecx, dword ptr [edi + 0x20]
// 007a85e0  85c9                 test ecx, ecx
// 007a85e2  740a                 je 0x7a85ee
// 007a85e4  8bd3                 mov edx, ebx
// 007a85e6  c1ea08               shr edx, 8
// 007a85e9  83e201               and edx, 1
// 007a85ec  8911                 mov dword ptr [ecx], edx
// 007a85ee  f7471000020000       test dword ptr [edi + 0x10], 0x200
// 007a85f5  7422                 je 0x7a8619
// 007a85f7  885c2420             mov byte ptr [esp + 0x20], bl
// 007a85fb  c1eb08               shr ebx, 8
// 007a85fe  6a02                 push 2
// 007a8600  8d442424             lea eax, [esp + 0x24]
// 007a8604  885c2425             mov byte ptr [esp + 0x25], bl
// 007a8608  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 007a860b  50                   push eax
// 007a860c  51                   push ecx
// 007a860d  e8fefaffff           call 0x7a8110
// 007a8612  894718               mov dword ptr [edi + 0x18], eax
// 007a8615  8b442410             mov eax, dword ptr [esp + 0x10]
// 007a8619  33db                 xor ebx, ebx
// 007a861b  33f6                 xor esi, esi
// 007a861d  c70702000000         mov dword ptr [edi], 2
// 007a8623  eb0b                 jmp 0x7a8630
// 007a8625  83fe20               cmp esi, 0x20
// 007a8628  732a                 jae 0x7a8654
// 007a862a  8d9b00000000         lea ebx, [ebx]
// 007a8630  85c0                 test eax, eax
// 007a8632  0f8494110000         je 0x7a97cc
// 007a8638  0fb65500             movzx edx, byte ptr [ebp]
// 007a863c  8bce                 mov ecx, esi
// 007a863e  d3e2                 shl edx, cl
// 007a8640  83e801               sub eax, 1
// 007a8643  83c608               add esi, 8
// 007a8646  83c501               add ebp, 1
// 007a8649  03da                 add ebx, edx
// 007a864b  83fe20               cmp esi, 0x20
// 007a864e  89442410             mov dword ptr [esp + 0x10], eax
// 007a8652  72dc                 jb 0x7a8630
// 007a8654  8b4f20               mov ecx, dword ptr [edi + 0x20]
// 007a8657  85c9                 test ecx, ecx
// 007a8659  7403                 je 0x7a865e
// 007a865b  895904               mov dword ptr [ecx + 4], ebx
// 007a865e  f7471000020000       test dword ptr [edi + 0x10], 0x200
// 007a8665  7434                 je 0x7a869b
// 007a8667  885c2420             mov byte ptr [esp + 0x20], bl
// 007a866b  8bc3                 mov eax, ebx
// 007a866d  8bcb                 mov ecx, ebx
// 007a866f  c1e808               shr eax, 8
// 007a8672  c1e910               shr ecx, 0x10
// 007a8675  c1eb18               shr ebx, 0x18
// 007a8678  6a04                 push 4
// 007a867a  8d542424             lea edx, [esp + 0x24]
// 007a867e  88442425             mov byte ptr [esp + 0x25], al
// 007a8682  884c2426             mov byte ptr [esp + 0x26], cl
// 007a8686  885c2427             mov byte ptr [esp + 0x27], bl
// 007a868a  8b4718               mov eax, dword ptr [edi + 0x18]
// 007a868d  52                   push edx
// 007a868e  50                   push eax
// 007a868f  e87cfaffff           call 0x7a8110
// 007a8694  894718               mov dword ptr [edi + 0x18], eax
// 007a8697  8b442410             mov eax, dword ptr [esp + 0x10]
// 007a869b  33db                 xor ebx, ebx
// 007a869d  33f6                 xor esi, esi
// 007a869f  c70703000000         mov dword ptr [edi], 3
// 007a86a5  eb09                 jmp 0x7a86b0
// 007a86a7  83fe10               cmp esi, 0x10
// 007a86aa  7328                 jae 0x7a86d4
// 007a86ac  8d642400             lea esp, [esp]
// 007a86b0  85c0                 test eax, eax
// 007a86b2  0f8414110000         je 0x7a97cc
// 007a86b8  0fb65500             movzx edx, byte ptr [ebp]
// 007a86bc  8bce                 mov ecx, esi
// 007a86be  d3e2                 shl edx, cl
// 007a86c0  83e801               sub eax, 1
// 007a86c3  83c608               add esi, 8
// 007a86c6  83c501               add ebp, 1
// 007a86c9  03da                 add ebx, edx
// 007a86cb  83fe10               cmp esi, 0x10
// 007a86ce  89442410             mov dword ptr [esp + 0x10], eax
// 007a86d2  72dc                 jb 0x7a86b0
// 007a86d4  8b4f20               mov ecx, dword ptr [edi + 0x20]
// 007a86d7  85c9                 test ecx, ecx
// 007a86d9  7416                 je 0x7a86f1
// 007a86db  8bd3                 mov edx, ebx
// 007a86dd  81e2ff000000         and edx, 0xff
// 007a86e3  895108               mov dword ptr [ecx + 8], edx
// 007a86e6  8b5720               mov edx, dword ptr [edi + 0x20]
// 007a86e9  8bcb                 mov ecx, ebx
// 007a86eb  c1e908               shr ecx, 8
// 007a86ee  894a0c               mov dword ptr [edx + 0xc], ecx
// 007a86f1  f7471000020000       test dword ptr [edi + 0x10], 0x200
// 007a86f8  7422                 je 0x7a871c
// 007a86fa  885c2420             mov byte ptr [esp + 0x20], bl
// 007a86fe  c1eb08               shr ebx, 8
// 007a8701  6a02                 push 2
// 007a8703  8d442424             lea eax, [esp + 0x24]
// 007a8707  885c2425             mov byte ptr [esp + 0x25], bl
// 007a870b  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 007a870e  50                   push eax
// 007a870f  51                   push ecx
// 007a8710  e8fbf9ffff           call 0x7a8110
// 007a8715  894718               mov dword ptr [edi + 0x18], eax
// 007a8718  8b442410             mov eax, dword ptr [esp + 0x10]
// 007a871c  33db                 xor ebx, ebx
// 007a871e  895c2418             mov dword ptr [esp + 0x18], ebx
// 007a8722  33f6                 xor esi, esi
// 007a8724  c70704000000         mov dword ptr [edi], 4
// 007a872a  f7471000040000       test dword ptr [edi + 0x10], 0x400
// 007a8731  746b                 je 0x7a879e
// 007a8733  83fe10               cmp esi, 0x10
// 007a8736  7324                 jae 0x7a875c
// 007a8738  85c0                 test eax, eax
// 007a873a  0f848c100000         je 0x7a97cc
// 007a8740  0fb65500             movzx edx, byte ptr [ebp]
// 007a8744  8bce                 mov ecx, esi
// 007a8746  d3e2                 shl edx, cl
// 007a8748  83e801               sub eax, 1
// 007a874b  83c608               add esi, 8
// 007a874e  83c501               add ebp, 1
// 007a8751  03da                 add ebx, edx
// 007a8753  83fe10               cmp esi, 0x10
// 007a8756  89442410             mov dword ptr [esp + 0x10], eax
// 007a875a  72dc                 jb 0x7a8738
// 007a875c  8b4f20               mov ecx, dword ptr [edi + 0x20]
// 007a875f  85c9                 test ecx, ecx
// 007a8761  895f40               mov dword ptr [edi + 0x40], ebx
// 007a8764  7403                 je 0x7a8769
// 007a8766  895914               mov dword ptr [ecx + 0x14], ebx
// 007a8769  f7471000020000       test dword ptr [edi + 0x10], 0x200
// 007a8770  7422                 je 0x7a8794
// 007a8772  885c2420             mov byte ptr [esp + 0x20], bl
// 007a8776  c1eb08               shr ebx, 8
// 007a8779  6a02                 push 2
// 007a877b  8d442424             lea eax, [esp + 0x24]
// 007a877f  885c2425             mov byte ptr [esp + 0x25], bl
// 007a8783  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 007a8786  50                   push eax
// 007a8787  51                   push ecx
// 007a8788  e883f9ffff           call 0x7a8110
// 007a878d  894718               mov dword ptr [edi + 0x18], eax
// 007a8790  8b442410             mov eax, dword ptr [esp + 0x10]
// 007a8794  33db                 xor ebx, ebx
// 007a8796  895c2418             mov dword ptr [esp + 0x18], ebx
// 007a879a  33f6                 xor esi, esi
// 007a879c  eb0e                 jmp 0x7a87ac
// 007a879e  8b4f20               mov ecx, dword ptr [edi + 0x20]
// 007a87a1  85c9                 test ecx, ecx
// 007a87a3  7407                 je 0x7a87ac
// 007a87a5  c7411000000000       mov dword ptr [ecx + 0x10], 0
// 007a87ac  c70705000000         mov dword ptr [edi], 5
// 007a87b2  f7471000040000       test dword ptr [edi + 0x10], 0x400
// 007a87b9  0f849f000000         je 0x7a885e
// 007a87bf  8b4f40               mov ecx, dword ptr [edi + 0x40]
// 007a87c2  3bc8                 cmp ecx, eax
// 007a87c4  894c2414             mov dword ptr [esp + 0x14], ecx
// 007a87c8  7606                 jbe 0x7a87d0
// 007a87ca  8bc8                 mov ecx, eax
// 007a87cc  89442414             mov dword ptr [esp + 0x14], eax
// 007a87d0  85c9                 test ecx, ecx
// 007a87d2  0f847c000000         je 0x7a8854
// 007a87d8  8b5720               mov edx, dword ptr [edi + 0x20]
// 007a87db  85d2                 test edx, edx
// 007a87dd  7447                 je 0x7a8826
// 007a87df  8b5210               mov edx, dword ptr [edx + 0x10]
// 007a87e2  85d2                 test edx, edx
// 007a87e4  89542434             mov dword ptr [esp + 0x34], edx
// 007a87e8  743c                 je 0x7a8826
// 007a87ea  8b4720               mov eax, dword ptr [edi + 0x20]
// 007a87ed  8b4014               mov eax, dword ptr [eax + 0x14]
// 007a87f0  2b4740               sub eax, dword ptr [edi + 0x40]
// 007a87f3  8b5720               mov edx, dword ptr [edi + 0x20]
// 007a87f6  8b5218               mov edx, dword ptr [edx + 0x18]
// 007a87f9  89442424             mov dword ptr [esp + 0x24], eax
// 007a87fd  03c1                 add eax, ecx
// 007a87ff  3bc2                 cmp eax, edx
// 007a8801  7606                 jbe 0x7a8809
// 007a8803  2b542424             sub edx, dword ptr [esp + 0x24]
// 007a8807  8bca                 mov ecx, edx
// 007a8809  8b542424             mov edx, dword ptr [esp + 0x24]
// 007a880d  51                   push ecx
// 007a880e  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 007a8812  03ca                 add ecx, edx
// 007a8814  55                   push ebp
// 007a8815  51                   push ecx
// 007a8816  e8c58fefff           call 0x6a17e0
// 007a881b  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 007a881f  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 007a8823  83c40c               add esp, 0xc
// 007a8826  f7471000020000       test dword ptr [edi + 0x10], 0x200
// 007a882d  741a                 je 0x7a8849
// 007a882f  8b442414             mov eax, dword ptr [esp + 0x14]
// 007a8833  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 007a8836  50                   push eax
// 007a8837  55                   push ebp
// 007a8838  51                   push ecx
// 007a8839  e8d2f8ffff           call 0x7a8110
// 007a883e  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 007a8842  894718               mov dword ptr [edi + 0x18], eax
// 007a8845  8b442410             mov eax, dword ptr [esp + 0x10]
// 007a8849  2bc1                 sub eax, ecx
// 007a884b  03e9                 add ebp, ecx
// 007a884d  294f40               sub dword ptr [edi + 0x40], ecx
// 007a8850  89442410             mov dword ptr [esp + 0x10], eax
// 007a8854  837f4000             cmp dword ptr [edi + 0x40], 0
// 007a8858  0f856e0f0000         jne 0x7a97cc
// 007a885e  c7474000000000       mov dword ptr [edi + 0x40], 0
// 007a8865  c70706000000         mov dword ptr [edi], 6
// 007a886b  f7471000080000       test dword ptr [edi + 0x10], 0x800
// 007a8872  0f848d000000         je 0x7a8905
// 007a8878  85c0                 test eax, eax
// 007a887a  0f844c0f0000         je 0x7a97cc
// 007a8880  33c9                 xor ecx, ecx
// 007a8882  0fb61429             movzx edx, byte ptr [ecx + ebp]
// 007a8886  83c101               add ecx, 1
// 007a8889  894c2414             mov dword ptr [esp + 0x14], ecx
// 007a888d  8b4f20               mov ecx, dword ptr [edi + 0x20]
// 007a8890  85c9                 test ecx, ecx
// 007a8892  89542424             mov dword ptr [esp + 0x24], edx
// 007a8896  7426                 je 0x7a88be
// 007a8898  8b511c               mov edx, dword ptr [ecx + 0x1c]
// 007a889b  85d2                 test edx, edx
// 007a889d  89542434             mov dword ptr [esp + 0x34], edx
// 007a88a1  741b                 je 0x7a88be
// 007a88a3  8b5740               mov edx, dword ptr [edi + 0x40]
// 007a88a6  3b5120               cmp edx, dword ptr [ecx + 0x20]
// 007a88a9  7313                 jae 0x7a88be
// 007a88ab  8b442434             mov eax, dword ptr [esp + 0x34]
// 007a88af  8a4c2424             mov cl, byte ptr [esp + 0x24]
// 007a88b3  880c10               mov byte ptr [eax + edx], cl
// 007a88b6  83474001             add dword ptr [edi + 0x40], 1
// 007a88ba  8b442410             mov eax, dword ptr [esp + 0x10]
// 007a88be  837c242400           cmp dword ptr [esp + 0x24], 0
// 007a88c3  7408                 je 0x7a88cd
// 007a88c5  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 007a88c9  3bc8                 cmp ecx, eax
// 007a88cb  72b5                 jb 0x7a8882
// 007a88cd  f7471000020000       test dword ptr [edi + 0x10], 0x200
// 007a88d4  7416                 je 0x7a88ec
// 007a88d6  8b542414             mov edx, dword ptr [esp + 0x14]
// 007a88da  8b4718               mov eax, dword ptr [edi + 0x18]
// 007a88dd  52                   push edx
// 007a88de  55                   push ebp
// 007a88df  50                   push eax
// 007a88e0  e82bf8ffff           call 0x7a8110
// 007a88e5  894718               mov dword ptr [edi + 0x18], eax
// 007a88e8  8b442410             mov eax, dword ptr [esp + 0x10]
// 007a88ec  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 007a88f0  2bc1                 sub eax, ecx
// 007a88f2  03e9                 add ebp, ecx
// 007a88f4  837c242400           cmp dword ptr [esp + 0x24], 0
// 007a88f9  89442410             mov dword ptr [esp + 0x10], eax
// 007a88fd  0f85c90e0000         jne 0x7a97cc
// 007a8903  eb0e                 jmp 0x7a8913
// 007a8905  8b4f20               mov ecx, dword ptr [edi + 0x20]
// 007a8908  85c9                 test ecx, ecx
// 007a890a  7407                 je 0x7a8913
// 007a890c  c7411c00000000       mov dword ptr [ecx + 0x1c], 0
// 007a8913  c7474000000000       mov dword ptr [edi + 0x40], 0
// 007a891a  c70707000000         mov dword ptr [edi], 7
// 007a8920  f7471000100000       test dword ptr [edi + 0x10], 0x1000
// 007a8927  0f8496000000         je 0x7a89c3
// 007a892d  85c0                 test eax, eax
// 007a892f  0f84970e0000         je 0x7a97cc
// 007a8935  33c9                 xor ecx, ecx
// 007a8937  eb07                 jmp 0x7a8940
// 007a8939  8da42400000000       lea esp, [esp]
// 007a8940  0fb61429             movzx edx, byte ptr [ecx + ebp]
// 007a8944  83c101               add ecx, 1
// 007a8947  894c2414             mov dword ptr [esp + 0x14], ecx
// 007a894b  8b4f20               mov ecx, dword ptr [edi + 0x20]
// 007a894e  85c9                 test ecx, ecx
// 007a8950  89542424             mov dword ptr [esp + 0x24], edx
// 007a8954  7426                 je 0x7a897c
// 007a8956  8b5124               mov edx, dword ptr [ecx + 0x24]
// 007a8959  85d2                 test edx, edx
// 007a895b  89542434             mov dword ptr [esp + 0x34], edx
// 007a895f  741b                 je 0x7a897c
// 007a8961  8b5740               mov edx, dword ptr [edi + 0x40]
// 007a8964  3b5128               cmp edx, dword ptr [ecx + 0x28]
// 007a8967  7313                 jae 0x7a897c
// 007a8969  8b442434             mov eax, dword ptr [esp + 0x34]
// 007a896d  8a4c2424             mov cl, byte ptr [esp + 0x24]
// 007a8971  880c10               mov byte ptr [eax + edx], cl
// 007a8974  83474001             add dword ptr [edi + 0x40], 1
// 007a8978  8b442410             mov eax, dword ptr [esp + 0x10]
// 007a897c  837c242400           cmp dword ptr [esp + 0x24], 0
// 007a8981  7408                 je 0x7a898b
// 007a8983  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 007a8987  3bc8                 cmp ecx, eax
// 007a8989  72b5                 jb 0x7a8940
// 007a898b  f7471000020000       test dword ptr [edi + 0x10], 0x200
// 007a8992  7416                 je 0x7a89aa
// 007a8994  8b542414             mov edx, dword ptr [esp + 0x14]
// 007a8998  8b4718               mov eax, dword ptr [edi + 0x18]
// 007a899b  52                   push edx
// 007a899c  55                   push ebp
// 007a899d  50                   push eax
// 007a899e  e86df7ffff           call 0x7a8110
// 007a89a3  894718               mov dword ptr [edi + 0x18], eax
// 007a89a6  8b442410             mov eax, dword ptr [esp + 0x10]
// 007a89aa  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 007a89ae  2bc1                 sub eax, ecx
// 007a89b0  03e9                 add ebp, ecx
// 007a89b2  837c242400           cmp dword ptr [esp + 0x24], 0
// 007a89b7  89442410             mov dword ptr [esp + 0x10], eax
// 007a89bb  0f850b0e0000         jne 0x7a97cc
// 007a89c1  eb0e                 jmp 0x7a89d1
// 007a89c3  8b4f20               mov ecx, dword ptr [edi + 0x20]
// 007a89c6  85c9                 test ecx, ecx
// 007a89c8  7407                 je 0x7a89d1
// 007a89ca  c7412400000000       mov dword ptr [ecx + 0x24], 0
// 007a89d1  c70708000000         mov dword ptr [edi], 8
// 007a89d7  f7471000020000       test dword ptr [edi + 0x10], 0x200
// 007a89de  744d                 je 0x7a8a2d
// 007a89e0  83fe10               cmp esi, 0x10
// 007a89e3  7328                 jae 0x7a8a0d
// 007a89e5  85c0                 test eax, eax
// 007a89e7  0f84df0d0000         je 0x7a97cc
// 007a89ed  0fb65500             movzx edx, byte ptr [ebp]
// 007a89f1  8bce                 mov ecx, esi
// 007a89f3  d3e2                 shl edx, cl
// 007a89f5  83e801               sub eax, 1
// 007a89f8  83c608               add esi, 8
// 007a89fb  83c501               add ebp, 1
// 007a89fe  03da                 add ebx, edx
// 007a8a00  83fe10               cmp esi, 0x10
// 007a8a03  89442410             mov dword ptr [esp + 0x10], eax
// 007a8a07  895c2418             mov dword ptr [esp + 0x18], ebx
// 007a8a0b  72d8                 jb 0x7a89e5
// 007a8a0d  0fb74f18             movzx ecx, word ptr [edi + 0x18]
// 007a8a11  3bd9                 cmp ebx, ecx
// 007a8a13  7410                 je 0x7a8a25
// 007a8a15  8b542440             mov edx, dword ptr [esp + 0x40]
// 007a8a19  c7421800ee8600       mov dword ptr [edx + 0x18], 0x86ee00
// 007a8a20  e9430d0000           jmp 0x7a9768
// 007a8a25  33db                 xor ebx, ebx
// 007a8a27  895c2418             mov dword ptr [esp + 0x18], ebx
// 007a8a2b  33f6                 xor esi, esi
// 007a8a2d  8b4720               mov eax, dword ptr [edi + 0x20]
// 007a8a30  85c0                 test eax, eax
// 007a8a32  7416                 je 0x7a8a4a
// 007a8a34  8b4f10               mov ecx, dword ptr [edi + 0x10]
// 007a8a37  c1f909               sar ecx, 9
// 007a8a3a  83e101               and ecx, 1
// 007a8a3d  89482c               mov dword ptr [eax + 0x2c], ecx
// 007a8a40  8b5720               mov edx, dword ptr [edi + 0x20]
// 007a8a43  c7423001000000       mov dword ptr [edx + 0x30], 1
// 007a8a4a  6a00                 push 0
// 007a8a4c  6a00                 push 0
// 007a8a4e  6a00                 push 0
// 007a8a50  e8bbf6ffff           call 0x7a8110
// 007a8a55  8b4c2440             mov ecx, dword ptr [esp + 0x40]
// 007a8a59  894718               mov dword ptr [edi + 0x18], eax
// 007a8a5c  894130               mov dword ptr [ecx + 0x30], eax
// 007a8a5f  8b442410             mov eax, dword ptr [esp + 0x10]
// 007a8a63  c7070b000000         mov dword ptr [edi], 0xb
// 007a8a69  e9000d0000           jmp 0x7a976e
// 007a8a6e  83fe20               cmp esi, 0x20
// 007a8a71  7328                 jae 0x7a8a9b
// 007a8a73  85c0                 test eax, eax
// 007a8a75  0f84510d0000         je 0x7a97cc
// 007a8a7b  0fb65500             movzx edx, byte ptr [ebp]
// 007a8a7f  8bce                 mov ecx, esi
// 007a8a81  d3e2                 shl edx, cl
// 007a8a83  83e801               sub eax, 1
// 007a8a86  83c608               add esi, 8
// 007a8a89  83c501               add ebp, 1
// 007a8a8c  03da                 add ebx, edx
// 007a8a8e  83fe20               cmp esi, 0x20
// 007a8a91  89442410             mov dword ptr [esp + 0x10], eax
// 007a8a95  895c2418             mov dword ptr [esp + 0x18], ebx
// 007a8a99  72d8                 jb 0x7a8a73
// 007a8a9b  8bcb                 mov ecx, ebx
// 007a8a9d  81e100ff0000         and ecx, 0xff00
// 007a8aa3  8bd3                 mov edx, ebx
// 007a8aa5  c1e210               shl edx, 0x10
// 007a8aa8  03ca                 add ecx, edx
// 007a8aaa  33d2                 xor edx, edx
// 007a8aac  8a74241a             mov dh, byte ptr [esp + 0x1a]
// 007a8ab0  c1e108               shl ecx, 8
// 007a8ab3  c1eb18               shr ebx, 0x18
// 007a8ab6  03ca                 add ecx, edx
// 007a8ab8  8b542440             mov edx, dword ptr [esp + 0x40]
// 007a8abc  03cb                 add ecx, ebx
// 007a8abe  894f18               mov dword ptr [edi + 0x18], ecx
// 007a8ac1  894a30               mov dword ptr [edx + 0x30], ecx
// 007a8ac4  33db                 xor ebx, ebx
// 007a8ac6  33f6                 xor esi, esi
// 007a8ac8  c7070a000000         mov dword ptr [edi], 0xa
// 007a8ace  837f0c00             cmp dword ptr [edi + 0xc], 0
// 007a8ad2  0f84b00c0000         je 0x7a9788
// 007a8ad8  6a00                 push 0
// 007a8ada  6a00                 push 0
// 007a8adc  6a00                 push 0
// 007a8ade  e8cd0e0000           call 0x7a99b0
// 007a8ae3  8b4c2440             mov ecx, dword ptr [esp + 0x40]
// 007a8ae7  894718               mov dword ptr [edi + 0x18], eax
// 007a8aea  894130               mov dword ptr [ecx + 0x30], eax
// 007a8aed  8b442410             mov eax, dword ptr [esp + 0x10]
// 007a8af1  c7070b000000         mov dword ptr [edi], 0xb
// 007a8af7  837c244405           cmp dword ptr [esp + 0x44], 5
// 007a8afc  0f84ca0c0000         je 0x7a97cc
// 007a8b02  837f0400             cmp dword ptr [edi + 4], 0
// 007a8b06  7418                 je 0x7a8b20
// 007a8b08  8bce                 mov ecx, esi
// 007a8b0a  83e107               and ecx, 7
// 007a8b0d  d3eb                 shr ebx, cl
// 007a8b0f  2bf1                 sub esi, ecx
// 007a8b11  c70718000000         mov dword ptr [edi], 0x18
// 007a8b17  895c2418             mov dword ptr [esp + 0x18], ebx
// 007a8b1b  e94e0c0000           jmp 0x7a976e
// 007a8b20  83fe03               cmp esi, 3
// 007a8b23  7324                 jae 0x7a8b49
// 007a8b25  85c0                 test eax, eax
// 007a8b27  0f849f0c0000         je 0x7a97cc
// 007a8b2d  0fb65500             movzx edx, byte ptr [ebp]
// 007a8b31  8bce                 mov ecx, esi
// 007a8b33  d3e2                 shl edx, cl
// 007a8b35  83e801               sub eax, 1
// 007a8b38  83c608               add esi, 8
// 007a8b3b  83c501               add ebp, 1
// 007a8b3e  03da                 add ebx, edx
// 007a8b40  83fe03               cmp esi, 3
// 007a8b43  89442410             mov dword ptr [esp + 0x10], eax
// 007a8b47  72dc                 jb 0x7a8b25
// 007a8b49  8bcb                 mov ecx, ebx
// 007a8b4b  83e101               and ecx, 1
// 007a8b4e  d1eb                 shr ebx, 1
// 007a8b50  894f04               mov dword ptr [edi + 4], ecx
// 007a8b53  8bcb                 mov ecx, ebx
// 007a8b55  83e103               and ecx, 3
// 007a8b58  83ee01               sub esi, 1
// 007a8b5b  83f903               cmp ecx, 3
// 007a8b5e  7773                 ja 0x7a8bd3
// 007a8b60  ff248d50997a00       jmp dword ptr [ecx*4 + 0x7a9950]
// 007a8b67  c1eb02               shr ebx, 2
// 007a8b6a  c7070d000000         mov dword ptr [edi], 0xd
// 007a8b70  895c2418             mov dword ptr [esp + 0x18], ebx
// 007a8b74  83ee02               sub esi, 2
// 007a8b77  e9f20b0000           jmp 0x7a976e
// 007a8b7c  c1eb02               shr ebx, 2
// 007a8b7f  c7474c78408700       mov dword ptr [edi + 0x4c], 0x874078
// 007a8b86  c7475409000000       mov dword ptr [edi + 0x54], 9
// 007a8b8d  c7475078488700       mov dword ptr [edi + 0x50], 0x874878
// 007a8b94  c7475805000000       mov dword ptr [edi + 0x58], 5
// 007a8b9b  c70712000000         mov dword ptr [edi], 0x12
// 007a8ba1  895c2418             mov dword ptr [esp + 0x18], ebx
// 007a8ba5  83ee02               sub esi, 2
// 007a8ba8  e9c10b0000           jmp 0x7a976e
// 007a8bad  c1eb02               shr ebx, 2
// 007a8bb0  c7070f000000         mov dword ptr [edi], 0xf
// 007a8bb6  895c2418             mov dword ptr [esp + 0x18], ebx
// 007a8bba  83ee02               sub esi, 2
// 007a8bbd  e9ac0b0000           jmp 0x7a976e
// 007a8bc2  8b542440             mov edx, dword ptr [esp + 0x40]
// 007a8bc6  c74218eced8600       mov dword ptr [edx + 0x18], 0x86edec
// 007a8bcd  c7071b000000         mov dword ptr [edi], 0x1b
// 007a8bd3  c1eb02               shr ebx, 2
// 007a8bd6  895c2418             mov dword ptr [esp + 0x18], ebx
// 007a8bda  83ee02               sub esi, 2
// 007a8bdd  e98c0b0000           jmp 0x7a976e
// 007a8be2  8bce                 mov ecx, esi
// 007a8be4  83e107               and ecx, 7
// 007a8be7  d3eb                 shr ebx, cl
// 007a8be9  2bf1                 sub esi, ecx
// 007a8beb  83fe20               cmp esi, 0x20
// 007a8bee  895c2418             mov dword ptr [esp + 0x18], ebx
// 007a8bf2  7328                 jae 0x7a8c1c
// 007a8bf4  85c0                 test eax, eax
// 007a8bf6  0f84d00b0000         je 0x7a97cc
// 007a8bfc  0fb65500             movzx edx, byte ptr [ebp]
// 007a8c00  8bce                 mov ecx, esi
// 007a8c02  d3e2                 shl edx, cl
// 007a8c04  83e801               sub eax, 1
// 007a8c07  83c608               add esi, 8
// 007a8c0a  83c501               add ebp, 1
// 007a8c0d  03da                 add ebx, edx
// 007a8c0f  83fe20               cmp esi, 0x20
// 007a8c12  89442410             mov dword ptr [esp + 0x10], eax
// 007a8c16  895c2418             mov dword ptr [esp + 0x18], ebx
// 007a8c1a  72d8                 jb 0x7a8bf4
// 007a8c1c  8bd3                 mov edx, ebx
// 007a8c1e  8bcb                 mov ecx, ebx
// 007a8c20  f7d2                 not edx
// 007a8c22  81e1ffff0000         and ecx, 0xffff
// 007a8c28  c1ea10               shr edx, 0x10
// 007a8c2b  3bca                 cmp ecx, edx
// 007a8c2d  7410                 je 0x7a8c3f
// 007a8c2f  8b4c2440             mov ecx, dword ptr [esp + 0x40]
// 007a8c33  c74118cced8600       mov dword ptr [ecx + 0x18], 0x86edcc
// 007a8c3a  e9290b0000           jmp 0x7a9768
// 007a8c3f  33db                 xor ebx, ebx
// 007a8c41  894f40               mov dword ptr [edi + 0x40], ecx
// 007a8c44  895c2418             mov dword ptr [esp + 0x18], ebx
// 007a8c48  33f6                 xor esi, esi
// 007a8c4a  c7070e000000         mov dword ptr [edi], 0xe
// 007a8c50  8b4f40               mov ecx, dword ptr [edi + 0x40]
// 007a8c53  85c9                 test ecx, ecx
// 007a8c55  894c2414             mov dword ptr [esp + 0x14], ecx
// 007a8c59  0f84ab060000         je 0x7a930a
// 007a8c5f  3bc8                 cmp ecx, eax
// 007a8c61  7606                 jbe 0x7a8c69
// 007a8c63  8bc8                 mov ecx, eax
// 007a8c65  89442414             mov dword ptr [esp + 0x14], eax
// 007a8c69  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 007a8c6d  3bca                 cmp ecx, edx
// 007a8c6f  7606                 jbe 0x7a8c77
// 007a8c71  8bca                 mov ecx, edx
// 007a8c73  894c2414             mov dword ptr [esp + 0x14], ecx
// 007a8c77  85c9                 test ecx, ecx
// 007a8c79  0f844d0b0000         je 0x7a97cc
// 007a8c7f  8b542414             mov edx, dword ptr [esp + 0x14]
// 007a8c83  8b442428             mov eax, dword ptr [esp + 0x28]
// 007a8c87  52                   push edx
// 007a8c88  55                   push ebp
// 007a8c89  50                   push eax
// 007a8c8a  e8518befff           call 0x6a17e0
// 007a8c8f  8b442420             mov eax, dword ptr [esp + 0x20]
// 007a8c93  2944241c             sub dword ptr [esp + 0x1c], eax
// 007a8c97  29442428             sub dword ptr [esp + 0x28], eax
// 007a8c9b  01442434             add dword ptr [esp + 0x34], eax
// 007a8c9f  03e8                 add ebp, eax
// 007a8ca1  83c40c               add esp, 0xc
// 007a8ca4  294740               sub dword ptr [edi + 0x40], eax
// 007a8ca7  8b442410             mov eax, dword ptr [esp + 0x10]
// 007a8cab  e9be0a0000           jmp 0x7a976e
// 007a8cb0  83fe0e               cmp esi, 0xe
// 007a8cb3  7324                 jae 0x7a8cd9
// 007a8cb5  85c0                 test eax, eax
// 007a8cb7  0f840f0b0000         je 0x7a97cc
// 007a8cbd  0fb65500             movzx edx, byte ptr [ebp]
// 007a8cc1  8bce                 mov ecx, esi
// 007a8cc3  d3e2                 shl edx, cl
// 007a8cc5  83e801               sub eax, 1
// 007a8cc8  83c608               add esi, 8
// 007a8ccb  83c501               add ebp, 1
// 007a8cce  03da                 add ebx, edx
// 007a8cd0  83fe0e               cmp esi, 0xe
// 007a8cd3  89442410             mov dword ptr [esp + 0x10], eax
// 007a8cd7  72dc                 jb 0x7a8cb5
// 007a8cd9  8bcb                 mov ecx, ebx
// 007a8cdb  83e11f               and ecx, 0x1f
// 007a8cde  c1eb05               shr ebx, 5
// 007a8ce1  81c101010000         add ecx, 0x101
// 007a8ce7  8bd3                 mov edx, ebx
// 007a8ce9  894f60               mov dword ptr [edi + 0x60], ecx
// 007a8cec  c1eb05               shr ebx, 5
// 007a8cef  8bcb                 mov ecx, ebx
// 007a8cf1  83e21f               and edx, 0x1f
// 007a8cf4  83e10f               and ecx, 0xf
// 007a8cf7  83c201               add edx, 1
// 007a8cfa  83c104               add ecx, 4
// 007a8cfd  c1eb04               shr ebx, 4
// 007a8d00  83ee0e               sub esi, 0xe
// 007a8d03  817f601e010000       cmp dword ptr [edi + 0x60], 0x11e
// 007a8d0a  895764               mov dword ptr [edi + 0x64], edx
// 007a8d0d  894f5c               mov dword ptr [edi + 0x5c], ecx
// 007a8d10  895c2418             mov dword ptr [esp + 0x18], ebx
// 007a8d14  0f87ec000000         ja 0x7a8e06
// 007a8d1a  83fa1e               cmp edx, 0x1e
// 007a8d1d  0f87e3000000         ja 0x7a8e06
// 007a8d23  c7476800000000       mov dword ptr [edi + 0x68], 0
// 007a8d2a  c70710000000         mov dword ptr [edi], 0x10
// 007a8d30  8b4f68               mov ecx, dword ptr [edi + 0x68]
// 007a8d33  3b4f5c               cmp ecx, dword ptr [edi + 0x5c]
// 007a8d36  7358                 jae 0x7a8d90
// 007a8d38  83fe03               cmp esi, 3
// 007a8d3b  7327                 jae 0x7a8d64
// 007a8d3d  8d4900               lea ecx, [ecx]
// 007a8d40  85c0                 test eax, eax
// 007a8d42  0f84840a0000         je 0x7a97cc
// 007a8d48  0fb65500             movzx edx, byte ptr [ebp]
// 007a8d4c  8bce                 mov ecx, esi
// 007a8d4e  d3e2                 shl edx, cl
// 007a8d50  83e801               sub eax, 1
// 007a8d53  83c608               add esi, 8
// 007a8d56  83c501               add ebp, 1
// 007a8d59  03da                 add ebx, edx
// 007a8d5b  83fe03               cmp esi, 3
// 007a8d5e  89442410             mov dword ptr [esp + 0x10], eax
// 007a8d62  72dc                 jb 0x7a8d40
// 007a8d64  8b5768               mov edx, dword ptr [edi + 0x68]
// 007a8d67  0fb71455f8488700     movzx edx, word ptr [edx*2 + 0x8748f8]
// 007a8d6f  0fb6cb               movzx ecx, bl
// 007a8d72  83e107               and ecx, 7
// 007a8d75  66894c5770           mov word ptr [edi + edx*2 + 0x70], cx
// 007a8d7a  83476801             add dword ptr [edi + 0x68], 1
// 007a8d7e  8b4f68               mov ecx, dword ptr [edi + 0x68]
// 007a8d81  c1eb03               shr ebx, 3
// 007a8d84  83ee03               sub esi, 3
// 007a8d87  3b4f5c               cmp ecx, dword ptr [edi + 0x5c]
// 007a8d8a  895c2418             mov dword ptr [esp + 0x18], ebx
// 007a8d8e  72a8                 jb 0x7a8d38
// 007a8d90  b913000000           mov ecx, 0x13
// 007a8d95  394f68               cmp dword ptr [edi + 0x68], ecx
// 007a8d98  7320                 jae 0x7a8dba
// 007a8d9a  b801000000           mov eax, 1
// 007a8d9f  90                   nop 
// 007a8da0  8b5768               mov edx, dword ptr [edi + 0x68]
// 007a8da3  0fb71455f8488700     movzx edx, word ptr [edx*2 + 0x8748f8]
// 007a8dab  66c74457700000       mov word ptr [edi + edx*2 + 0x70], 0
// 007a8db2  014768               add dword ptr [edi + 0x68], eax
// 007a8db5  394f68               cmp dword ptr [edi + 0x68], ecx
// 007a8db8  72e6                 jb 0x7a8da0
// 007a8dba  8d8730050000         lea eax, [edi + 0x530]
// 007a8dc0  8d4f6c               lea ecx, [edi + 0x6c]
// 007a8dc3  8901                 mov dword ptr [ecx], eax
// 007a8dc5  89474c               mov dword ptr [edi + 0x4c], eax
// 007a8dc8  8d97f0020000         lea edx, [edi + 0x2f0]
// 007a8dce  52                   push edx
// 007a8dcf  8d4754               lea eax, [edi + 0x54]
// 007a8dd2  50                   push eax
// 007a8dd3  51                   push ecx
// 007a8dd4  c70007000000         mov dword ptr [eax], 7
// 007a8dda  6a13                 push 0x13
// 007a8ddc  8d4770               lea eax, [edi + 0x70]
// 007a8ddf  50                   push eax
// 007a8de0  6a00                 push 0
// 007a8de2  e849a9ffff           call 0x7a3730
// 007a8de7  83c418               add esp, 0x18
// 007a8dea  89442430             mov dword ptr [esp + 0x30], eax
// 007a8dee  85c0                 test eax, eax
// 007a8df0  8b442410             mov eax, dword ptr [esp + 0x10]
// 007a8df4  7420                 je 0x7a8e16
// 007a8df6  8b4c2440             mov ecx, dword ptr [esp + 0x40]
// 007a8dfa  c74118b0ed8600       mov dword ptr [ecx + 0x18], 0x86edb0
// 007a8e01  e962090000           jmp 0x7a9768
// 007a8e06  8b542440             mov edx, dword ptr [esp + 0x40]
// 007a8e0a  c742188ced8600       mov dword ptr [edx + 0x18], 0x86ed8c
// 007a8e11  e952090000           jmp 0x7a9768
// 007a8e16  c7476800000000       mov dword ptr [edi + 0x68], 0
// 007a8e1d  c70711000000         mov dword ptr [edi], 0x11
// 007a8e23  8b5764               mov edx, dword ptr [edi + 0x64]
// 007a8e26  035760               add edx, dword ptr [edi + 0x60]
// 007a8e29  395768               cmp dword ptr [edi + 0x68], edx
// 007a8e2c  0f8337020000         jae 0x7a9069
// 007a8e32  8b4f54               mov ecx, dword ptr [edi + 0x54]
// 007a8e35  ba01000000           mov edx, 1
// 007a8e3a  d3e2                 shl edx, cl
// 007a8e3c  8b4f4c               mov ecx, dword ptr [edi + 0x4c]
// 007a8e3f  83ea01               sub edx, 1
// 007a8e42  23d3                 and edx, ebx
// 007a8e44  8b0c91               mov ecx, dword ptr [ecx + edx*4]
// 007a8e47  8bd1                 mov edx, ecx
// 007a8e49  c1ea08               shr edx, 8
// 007a8e4c  0fb6d2               movzx edx, dl
// 007a8e4f  3bd6                 cmp edx, esi
// 007a8e51  894c2414             mov dword ptr [esp + 0x14], ecx
// 007a8e55  7644                 jbe 0x7a8e9b
// 007a8e57  85c0                 test eax, eax
// 007a8e59  0f846d090000         je 0x7a97cc
// 007a8e5f  0fb65500             movzx edx, byte ptr [ebp]
// 007a8e63  8bce                 mov ecx, esi
// 007a8e65  d3e2                 shl edx, cl
// 007a8e67  8b4f54               mov ecx, dword ptr [edi + 0x54]
// 007a8e6a  83e801               sub eax, 1
// 007a8e6d  83c608               add esi, 8
// 007a8e70  03da                 add ebx, edx
// 007a8e72  ba01000000           mov edx, 1
// 007a8e77  d3e2                 shl edx, cl
// 007a8e79  8b4f4c               mov ecx, dword ptr [edi + 0x4c]
// 007a8e7c  83c501               add ebp, 1
// 007a8e7f  89442410             mov dword ptr [esp + 0x10], eax
// 007a8e83  83ea01               sub edx, 1
// 007a8e86  23d3                 and edx, ebx
// 007a8e88  8b0c91               mov ecx, dword ptr [ecx + edx*4]
// 007a8e8b  8bd1                 mov edx, ecx
// 007a8e8d  c1ea08               shr edx, 8
// 007a8e90  0fb6d2               movzx edx, dl
// 007a8e93  3bd6                 cmp edx, esi
// 007a8e95  894c2414             mov dword ptr [esp + 0x14], ecx
// 007a8e99  77bc                 ja 0x7a8e57
// 007a8e9b  8bd1                 mov edx, ecx
// 007a8e9d  c1ea10               shr edx, 0x10
// 007a8ea0  83fa10               cmp edx, 0x10
// 007a8ea3  7357                 jae 0x7a8efc
// 007a8ea5  8bd1                 mov edx, ecx
// 007a8ea7  c1ea08               shr edx, 8
// 007a8eaa  0fb6d2               movzx edx, dl
// 007a8ead  3bf2                 cmp esi, edx
// 007a8eaf  732a                 jae 0x7a8edb
// 007a8eb1  85c0                 test eax, eax
// 007a8eb3  0f8413090000         je 0x7a97cc
// 007a8eb9  0fb65500             movzx edx, byte ptr [ebp]
// 007a8ebd  8bce                 mov ecx, esi
// 007a8ebf  d3e2                 shl edx, cl
// 007a8ec1  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 007a8ec5  83e801               sub eax, 1
// 007a8ec8  83c608               add esi, 8
// 007a8ecb  03da                 add ebx, edx
// 007a8ecd  0fb6d5               movzx edx, ch
// 007a8ed0  83c501               add ebp, 1
// 007a8ed3  3bf2                 cmp esi, edx
// 007a8ed5  89442410             mov dword ptr [esp + 0x10], eax
// 007a8ed9  72d6                 jb 0x7a8eb1
// 007a8edb  668b542416           mov dx, word ptr [esp + 0x16]
// 007a8ee0  0fb6cd               movzx ecx, ch
// 007a8ee3  d3eb                 shr ebx, cl
// 007a8ee5  2bf1                 sub esi, ecx
// 007a8ee7  8b4f68               mov ecx, dword ptr [edi + 0x68]
// 007a8eea  6689544f70           mov word ptr [edi + ecx*2 + 0x70], dx
// 007a8eef  83476801             add dword ptr [edi + 0x68], 1
// 007a8ef3  895c2418             mov dword ptr [esp + 0x18], ebx
// 007a8ef7  e95e010000           jmp 0x7a905a
// 007a8efc  668b542416           mov dx, word ptr [esp + 0x16]
// 007a8f01  6683fa10             cmp dx, 0x10
// 007a8f05  0fb6cd               movzx ecx, ch
// 007a8f08  894c2424             mov dword ptr [esp + 0x24], ecx
// 007a8f0c  7564                 jne 0x7a8f72
// 007a8f0e  8d5102               lea edx, [ecx + 2]
// 007a8f11  3bf2                 cmp esi, edx
// 007a8f13  732a                 jae 0x7a8f3f
// 007a8f15  85c0                 test eax, eax
// 007a8f17  0f84af080000         je 0x7a97cc
// 007a8f1d  0fb65500             movzx edx, byte ptr [ebp]
// 007a8f21  8bce                 mov ecx, esi
// 007a8f23  d3e2                 shl edx, cl
// 007a8f25  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 007a8f29  83e801               sub eax, 1
// 007a8f2c  83c608               add esi, 8
// 007a8f2f  03da                 add ebx, edx
// 007a8f31  8d5102               lea edx, [ecx + 2]
// 007a8f34  83c501               add ebp, 1
// 007a8f37  3bf2                 cmp esi, edx
// 007a8f39  89442410             mov dword ptr [esp + 0x10], eax
// 007a8f3d  72d6                 jb 0x7a8f15
// 007a8f3f  d3eb                 shr ebx, cl
// 007a8f41  2bf1                 sub esi, ecx
// 007a8f43  8b4f68               mov ecx, dword ptr [edi + 0x68]
// 007a8f46  85c9                 test ecx, ecx
// 007a8f48  895c2418             mov dword ptr [esp + 0x18], ebx
// 007a8f4c  0f846e010000         je 0x7a90c0
// 007a8f52  0fb74c4f6e           movzx ecx, word ptr [edi + ecx*2 + 0x6e]
// 007a8f57  894c2424             mov dword ptr [esp + 0x24], ecx
// 007a8f5b  8bcb                 mov ecx, ebx
// 007a8f5d  83e103               and ecx, 3
// 007a8f60  83c103               add ecx, 3
// 007a8f63  c1eb02               shr ebx, 2
// 007a8f66  894c2414             mov dword ptr [esp + 0x14], ecx
// 007a8f6a  83ee02               sub esi, 2
// 007a8f6d  e9ae000000           jmp 0x7a9020
// 007a8f72  6683fa11             cmp dx, 0x11
// 007a8f76  754a                 jne 0x7a8fc2
// 007a8f78  8d5103               lea edx, [ecx + 3]
// 007a8f7b  3bf2                 cmp esi, edx
// 007a8f7d  732b                 jae 0x7a8faa
// 007a8f7f  90                   nop 
// 007a8f80  85c0                 test eax, eax
// 007a8f82  0f8444080000         je 0x7a97cc
// 007a8f88  0fb65500             movzx edx, byte ptr [ebp]
// 007a8f8c  8bce                 mov ecx, esi
// 007a8f8e  d3e2                 shl edx, cl
// 007a8f90  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 007a8f94  83e801               sub eax, 1
// 007a8f97  83c608               add esi, 8
// 007a8f9a  03da                 add ebx, edx
// 007a8f9c  8d5103               lea edx, [ecx + 3]
// 007a8f9f  83c501               add ebp, 1
// 007a8fa2  3bf2                 cmp esi, edx
// 007a8fa4  89442410             mov dword ptr [esp + 0x10], eax
// 007a8fa8  72d6                 jb 0x7a8f80
// 007a8faa  d3eb                 shr ebx, cl
// 007a8fac  8bd3                 mov edx, ebx
// 007a8fae  83e207               and edx, 7
// 007a8fb1  83c203               add edx, 3
// 007a8fb4  89542414             mov dword ptr [esp + 0x14], edx
// 007a8fb8  c1eb03               shr ebx, 3
// 007a8fbb  bafdffffff           mov edx, 0xfffffffd
// 007a8fc0  eb4e                 jmp 0x7a9010
// 007a8fc2  8d5107               lea edx, [ecx + 7]
// 007a8fc5  3bf2                 cmp esi, edx
// 007a8fc7  7331                 jae 0x7a8ffa
// 007a8fc9  8da42400000000       lea esp, [esp]
// 007a8fd0  85c0                 test eax, eax
// 007a8fd2  0f84f4070000         je 0x7a97cc
// 007a8fd8  0fb65500             movzx edx, byte ptr [ebp]
// 007a8fdc  8bce                 mov ecx, esi
// 007a8fde  d3e2                 shl edx, cl
// 007a8fe0  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 007a8fe4  83e801               sub eax, 1
// 007a8fe7  83c608               add esi, 8
// 007a8fea  03da                 add ebx, edx
// 007a8fec  8d5107               lea edx, [ecx + 7]
// 007a8fef  83c501               add ebp, 1
// 007a8ff2  3bf2                 cmp esi, edx
// 007a8ff4  89442410             mov dword ptr [esp + 0x10], eax
// 007a8ff8  72d6                 jb 0x7a8fd0
// 007a8ffa  d3eb                 shr ebx, cl
// 007a8ffc  8bd3                 mov edx, ebx
// 007a8ffe  83e27f               and edx, 0x7f
// 007a9001  83c20b               add edx, 0xb
// 007a9004  89542414             mov dword ptr [esp + 0x14], edx
// 007a9008  c1eb07               shr ebx, 7
// 007a900b  baf9ffffff           mov edx, 0xfffffff9
// 007a9010  2bd1                 sub edx, ecx
// 007a9012  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 007a9016  03f2                 add esi, edx
// 007a9018  c744242400000000     mov dword ptr [esp + 0x24], 0
// 007a9020  8b5768               mov edx, dword ptr [edi + 0x68]
// 007a9023  03d1                 add edx, ecx
// 007a9025  8b4f64               mov ecx, dword ptr [edi + 0x64]
// 007a9028  034f60               add ecx, dword ptr [edi + 0x60]
// 007a902b  895c2418             mov dword ptr [esp + 0x18], ebx
// 007a902f  3bd1                 cmp edx, ecx
// 007a9031  0f8799000000         ja 0x7a90d0
// 007a9037  837c241400           cmp dword ptr [esp + 0x14], 0
// 007a903c  741c                 je 0x7a905a
// 007a903e  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 007a9042  8b5768               mov edx, dword ptr [edi + 0x68]
// 007a9045  836c241401           sub dword ptr [esp + 0x14], 1
// 007a904a  66894c5770           mov word ptr [edi + edx*2 + 0x70], cx
// 007a904f  83476801             add dword ptr [edi + 0x68], 1
// 007a9053  837c241400           cmp dword ptr [esp + 0x14], 0
// 007a9058  75e8                 jne 0x7a9042
// 007a905a  8b4f64               mov ecx, dword ptr [edi + 0x64]
// 007a905d  034f60               add ecx, dword ptr [edi + 0x60]
// 007a9060  394f68               cmp dword ptr [edi + 0x68], ecx
// 007a9063  0f82c9fdffff         jb 0x7a8e32
// 007a9069  833f1b               cmp dword ptr [edi], 0x1b
// 007a906c  0f84fc060000         je 0x7a976e
// 007a9072  8d8730050000         lea eax, [edi + 0x530]
// 007a9078  8d4f6c               lea ecx, [edi + 0x6c]
// 007a907b  8901                 mov dword ptr [ecx], eax
// 007a907d  89474c               mov dword ptr [edi + 0x4c], eax
// 007a9080  8d97f0020000         lea edx, [edi + 0x2f0]
// 007a9086  52                   push edx
// 007a9087  8b5760               mov edx, dword ptr [edi + 0x60]
// 007a908a  8d4754               lea eax, [edi + 0x54]
// 007a908d  50                   push eax
// 007a908e  51                   push ecx
// 007a908f  c70009000000         mov dword ptr [eax], 9
// 007a9095  52                   push edx
// 007a9096  8d4770               lea eax, [edi + 0x70]
// 007a9099  50                   push eax
// 007a909a  6a01                 push 1
// 007a909c  e88fa6ffff           call 0x7a3730
// 007a90a1  83c418               add esp, 0x18
// 007a90a4  85c0                 test eax, eax
// 007a90a6  89442430             mov dword ptr [esp + 0x30], eax
// 007a90aa  7434                 je 0x7a90e0
// 007a90ac  8b4c2440             mov ecx, dword ptr [esp + 0x40]
// 007a90b0  8b442410             mov eax, dword ptr [esp + 0x10]
// 007a90b4  c7411870ed8600       mov dword ptr [ecx + 0x18], 0x86ed70
// 007a90bb  e9a8060000           jmp 0x7a9768
// 007a90c0  8b542440             mov edx, dword ptr [esp + 0x40]
// 007a90c4  c7421854ed8600       mov dword ptr [edx + 0x18], 0x86ed54
// 007a90cb  e998060000           jmp 0x7a9768
// 007a90d0  8b4c2440             mov ecx, dword ptr [esp + 0x40]
// 007a90d4  c7411854ed8600       mov dword ptr [ecx + 0x18], 0x86ed54
// 007a90db  e988060000           jmp 0x7a9768
// 007a90e0  8b576c               mov edx, dword ptr [edi + 0x6c]
// 007a90e3  8d4f6c               lea ecx, [edi + 0x6c]
// 007a90e6  895750               mov dword ptr [edi + 0x50], edx
// 007a90e9  8d97f0020000         lea edx, [edi + 0x2f0]
// 007a90ef  52                   push edx
// 007a90f0  8d4758               lea eax, [edi + 0x58]
// 007a90f3  50                   push eax
// 007a90f4  51                   push ecx
// 007a90f5  8b4f60               mov ecx, dword ptr [edi + 0x60]
// 007a90f8  c70006000000         mov dword ptr [eax], 6
// 007a90fe  8b4764               mov eax, dword ptr [edi + 0x64]
// 007a9101  50                   push eax
// 007a9102  8d544f70             lea edx, [edi + ecx*2 + 0x70]
// 007a9106  52                   push edx
// 007a9107  6a02                 push 2
// 007a9109  e822a6ffff           call 0x7a3730
// 007a910e  83c418               add esp, 0x18
// 007a9111  85c0                 test eax, eax
// 007a9113  89442430             mov dword ptr [esp + 0x30], eax
// 007a9117  7414                 je 0x7a912d
// 007a9119  8b442440             mov eax, dword ptr [esp + 0x40]
// 007a911d  c740183ced8600       mov dword ptr [eax + 0x18], 0x86ed3c
// 007a9124  8b442410             mov eax, dword ptr [esp + 0x10]
// 007a9128  e93b060000           jmp 0x7a9768
// 007a912d  8b442410             mov eax, dword ptr [esp + 0x10]
// 007a9131  c70712000000         mov dword ptr [edi], 0x12
// 007a9137  83f806               cmp eax, 6
// 007a913a  7263                 jb 0x7a919f
// 007a913c  817c241c02010000     cmp dword ptr [esp + 0x1c], 0x102
// 007a9144  7259                 jb 0x7a919f
// 007a9146  8b442440             mov eax, dword ptr [esp + 0x40]
// 007a914a  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 007a914e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 007a9152  895010               mov dword ptr [eax + 0x10], edx
// 007a9155  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 007a9159  89480c               mov dword ptr [eax + 0xc], ecx
// 007a915c  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007a9160  52                   push edx
// 007a9161  8928                 mov dword ptr [eax], ebp
// 007a9163  894804               mov dword ptr [eax + 4], ecx
// 007a9166  50                   push eax
// 007a9167  895f38               mov dword ptr [edi + 0x38], ebx
// 007a916a  89773c               mov dword ptr [edi + 0x3c], esi
// 007a916d  e85ea1ffff           call 0x7a32d0
// 007a9172  8b442448             mov eax, dword ptr [esp + 0x48]
// 007a9176  8b480c               mov ecx, dword ptr [eax + 0xc]
// 007a9179  8b5010               mov edx, dword ptr [eax + 0x10]
// 007a917c  8b28                 mov ebp, dword ptr [eax]
// 007a917e  8b4004               mov eax, dword ptr [eax + 4]
// 007a9181  8b5f38               mov ebx, dword ptr [edi + 0x38]
// 007a9184  8b773c               mov esi, dword ptr [edi + 0x3c]
// 007a9187  83c408               add esp, 8
// 007a918a  894c2428             mov dword ptr [esp + 0x28], ecx
// 007a918e  8954241c             mov dword ptr [esp + 0x1c], edx
// 007a9192  89442410             mov dword ptr [esp + 0x10], eax
// 007a9196  895c2418             mov dword ptr [esp + 0x18], ebx
// 007a919a  e9cf050000           jmp 0x7a976e
// 007a919f  8b4f54               mov ecx, dword ptr [edi + 0x54]
// 007a91a2  ba01000000           mov edx, 1
// 007a91a7  d3e2                 shl edx, cl
// 007a91a9  8b4f4c               mov ecx, dword ptr [edi + 0x4c]
// 007a91ac  83ea01               sub edx, 1
// 007a91af  23d3                 and edx, ebx
// 007a91b1  8b1491               mov edx, dword ptr [ecx + edx*4]
// 007a91b4  8bca                 mov ecx, edx
// 007a91b6  c1e908               shr ecx, 8
// 007a91b9  0fb6c9               movzx ecx, cl
// 007a91bc  3bce                 cmp ecx, esi
// 007a91be  89542414             mov dword ptr [esp + 0x14], edx
// 007a91c2  7644                 jbe 0x7a9208
// 007a91c4  85c0                 test eax, eax
// 007a91c6  0f8400060000         je 0x7a97cc
// 007a91cc  0fb65500             movzx edx, byte ptr [ebp]
// 007a91d0  8bce                 mov ecx, esi
// 007a91d2  d3e2                 shl edx, cl
// 007a91d4  8b4f54               mov ecx, dword ptr [edi + 0x54]
// 007a91d7  83e801               sub eax, 1
// 007a91da  83c608               add esi, 8
// 007a91dd  03da                 add ebx, edx
// 007a91df  ba01000000           mov edx, 1
// 007a91e4  d3e2                 shl edx, cl
// 007a91e6  8b4f4c               mov ecx, dword ptr [edi + 0x4c]
// 007a91e9  83c501               add ebp, 1
// 007a91ec  89442410             mov dword ptr [esp + 0x10], eax
// 007a91f0  83ea01               sub edx, 1
// 007a91f3  23d3                 and edx, ebx
// 007a91f5  8b1491               mov edx, dword ptr [ecx + edx*4]
// 007a91f8  8bca                 mov ecx, edx
// 007a91fa  c1e908               shr ecx, 8
// 007a91fd  0fb6c9               movzx ecx, cl
// 007a9200  3bce                 cmp ecx, esi
// 007a9202  89542414             mov dword ptr [esp + 0x14], edx
// 007a9206  77bc                 ja 0x7a91c4
// 007a9208  84d2                 test dl, dl
// 007a920a  0f84ca000000         je 0x7a92da
// 007a9210  f6c2f0               test dl, 0xf0
// 007a9213  0f85c1000000         jne 0x7a92da
// 007a9219  8bca                 mov ecx, edx
// 007a921b  c1e908               shr ecx, 8
// 007a921e  894c2434             mov dword ptr [esp + 0x34], ecx
// 007a9222  0fb6c9               movzx ecx, cl
// 007a9225  894c2424             mov dword ptr [esp + 0x24], ecx
// 007a9229  0fb6ca               movzx ecx, dl
// 007a922c  034c2424             add ecx, dword ptr [esp + 0x24]
// 007a9230  89542418             mov dword ptr [esp + 0x18], edx
// 007a9234  ba01000000           mov edx, 1
// 007a9239  d3e2                 shl edx, cl
// 007a923b  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 007a923f  83ea01               sub edx, 1
// 007a9242  23d3                 and edx, ebx
// 007a9244  d3ea                 shr edx, cl
// 007a9246  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 007a924a  c1e910               shr ecx, 0x10
// 007a924d  03d1                 add edx, ecx
// 007a924f  8b4f4c               mov ecx, dword ptr [edi + 0x4c]
// 007a9252  8b0c91               mov ecx, dword ptr [ecx + edx*4]
// 007a9255  894c2414             mov dword ptr [esp + 0x14], ecx
// 007a9259  c1e908               shr ecx, 8
// 007a925c  0fb6d1               movzx edx, cl
// 007a925f  0fb64c2434           movzx ecx, byte ptr [esp + 0x34]
// 007a9264  03d1                 add edx, ecx
// 007a9266  3bd6                 cmp edx, esi
// 007a9268  7663                 jbe 0x7a92cd
// 007a926a  8d9b00000000         lea ebx, [ebx]
// 007a9270  85c0                 test eax, eax
// 007a9272  0f8454050000         je 0x7a97cc
// 007a9278  0fb65500             movzx edx, byte ptr [ebp]
// 007a927c  8bce                 mov ecx, esi
// 007a927e  d3e2                 shl edx, cl
// 007a9280  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 007a9284  83e801               sub eax, 1
// 007a9287  83c608               add esi, 8
// 007a928a  03da                 add ebx, edx
// 007a928c  0fb6d5               movzx edx, ch
// 007a928f  03ca                 add ecx, edx
// 007a9291  89542424             mov dword ptr [esp + 0x24], edx
// 007a9295  ba01000000           mov edx, 1
// 007a929a  d3e2                 shl edx, cl
// 007a929c  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 007a92a0  83c501               add ebp, 1
// 007a92a3  89442410             mov dword ptr [esp + 0x10], eax
// 007a92a7  83ea01               sub edx, 1
// 007a92aa  23d3                 and edx, ebx
// 007a92ac  d3ea                 shr edx, cl
// 007a92ae  0fb74c241a           movzx ecx, word ptr [esp + 0x1a]
// 007a92b3  03d1                 add edx, ecx
// 007a92b5  8b4f4c               mov ecx, dword ptr [edi + 0x4c]
// 007a92b8  8b0c91               mov ecx, dword ptr [ecx + edx*4]
// 007a92bb  894c2414             mov dword ptr [esp + 0x14], ecx
// 007a92bf  c1e908               shr ecx, 8
// 007a92c2  0fb6d1               movzx edx, cl
// 007a92c5  03542424             add edx, dword ptr [esp + 0x24]
// 007a92c9  3bd6                 cmp edx, esi
// 007a92cb  77a3                 ja 0x7a9270
// 007a92cd  0fb64c2419           movzx ecx, byte ptr [esp + 0x19]
// 007a92d2  8b542414             mov edx, dword ptr [esp + 0x14]
// 007a92d6  d3eb                 shr ebx, cl
// 007a92d8  2bf1                 sub esi, ecx
// 007a92da  8bca                 mov ecx, edx
// 007a92dc  c1e908               shr ecx, 8
// 007a92df  0fb6c9               movzx ecx, cl
// 007a92e2  d3eb                 shr ebx, cl
// 007a92e4  2bf1                 sub esi, ecx
// 007a92e6  894c2424             mov dword ptr [esp + 0x24], ecx
// 007a92ea  8bca                 mov ecx, edx
// 007a92ec  c1e910               shr ecx, 0x10
// 007a92ef  84d2                 test dl, dl
// 007a92f1  895c2418             mov dword ptr [esp + 0x18], ebx
// 007a92f5  894f40               mov dword ptr [edi + 0x40], ecx
// 007a92f8  750b                 jne 0x7a9305
// 007a92fa  c70717000000         mov dword ptr [edi], 0x17
// 007a9300  e969040000           jmp 0x7a976e
// 007a9305  f6c220               test dl, 0x20
// 007a9308  740b                 je 0x7a9315
// 007a930a  c7070b000000         mov dword ptr [edi], 0xb
// 007a9310  e959040000           jmp 0x7a976e
// 007a9315  f6c240               test dl, 0x40
// 007a9318  7410                 je 0x7a932a
// 007a931a  8b542440             mov edx, dword ptr [esp + 0x40]
// 007a931e  c7421820ed8600       mov dword ptr [edx + 0x18], 0x86ed20
// 007a9325  e93e040000           jmp 0x7a9768
// 007a932a  83e20f               and edx, 0xf
// 007a932d  895748               mov dword ptr [edi + 0x48], edx
// 007a9330  c70713000000         mov dword ptr [edi], 0x13
// 007a9336  8b4f48               mov ecx, dword ptr [edi + 0x48]
// 007a9339  85c9                 test ecx, ecx
// 007a933b  743e                 je 0x7a937b
// 007a933d  3bf1                 cmp esi, ecx
// 007a933f  7324                 jae 0x7a9365
// 007a9341  85c0                 test eax, eax
// 007a9343  0f8483040000         je 0x7a97cc
// 007a9349  0fb65500             movzx edx, byte ptr [ebp]
// 007a934d  8bce                 mov ecx, esi
// 007a934f  d3e2                 shl edx, cl
// 007a9351  83e801               sub eax, 1
// 007a9354  83c608               add esi, 8
// 007a9357  83c501               add ebp, 1
// 007a935a  03da                 add ebx, edx
// 007a935c  3b7748               cmp esi, dword ptr [edi + 0x48]
// 007a935f  89442410             mov dword ptr [esp + 0x10], eax
// 007a9363  72dc                 jb 0x7a9341
// 007a9365  8b4f48               mov ecx, dword ptr [edi + 0x48]
// 007a9368  ba01000000           mov edx, 1
// 007a936d  d3e2                 shl edx, cl
// 007a936f  83ea01               sub edx, 1
// 007a9372  23d3                 and edx, ebx
// 007a9374  015740               add dword ptr [edi + 0x40], edx
// 007a9377  d3eb                 shr ebx, cl
// 007a9379  2bf1                 sub esi, ecx
// 007a937b  c70714000000         mov dword ptr [edi], 0x14
// 007a9381  8b4f58               mov ecx, dword ptr [edi + 0x58]
// 007a9384  ba01000000           mov edx, 1
// 007a9389  d3e2                 shl edx, cl
// 007a938b  8b4f50               mov ecx, dword ptr [edi + 0x50]
// 007a938e  83ea01               sub edx, 1
// 007a9391  23d3                 and edx, ebx
// 007a9393  8b1491               mov edx, dword ptr [ecx + edx*4]
// 007a9396  8bca                 mov ecx, edx
// 007a9398  c1e908               shr ecx, 8
// 007a939b  0fb6c9               movzx ecx, cl
// 007a939e  3bce                 cmp ecx, esi
// 007a93a0  89542414             mov dword ptr [esp + 0x14], edx
// 007a93a4  7644                 jbe 0x7a93ea
// 007a93a6  85c0                 test eax, eax
// 007a93a8  0f841e040000         je 0x7a97cc
// 007a93ae  0fb65500             movzx edx, byte ptr [ebp]
// 007a93b2  8bce                 mov ecx, esi
// 007a93b4  d3e2                 shl edx, cl
// 007a93b6  8b4f58               mov ecx, dword ptr [edi + 0x58]
// 007a93b9  83e801               sub eax, 1
// 007a93bc  83c608               add esi, 8
// 007a93bf  03da                 add ebx, edx
// 007a93c1  ba01000000           mov edx, 1
// 007a93c6  d3e2                 shl edx, cl
// 007a93c8  8b4f50               mov ecx, dword ptr [edi + 0x50]
// 007a93cb  83c501               add ebp, 1
// 007a93ce  89442410             mov dword ptr [esp + 0x10], eax
// 007a93d2  83ea01               sub edx, 1
// 007a93d5  23d3                 and edx, ebx
// 007a93d7  8b1491               mov edx, dword ptr [ecx + edx*4]
// 007a93da  8bca                 mov ecx, edx
// 007a93dc  c1e908               shr ecx, 8
// 007a93df  0fb6c9               movzx ecx, cl
// 007a93e2  3bce                 cmp ecx, esi
// 007a93e4  89542414             mov dword ptr [esp + 0x14], edx
// 007a93e8  77bc                 ja 0x7a93a6
// 007a93ea  f6c2f0               test dl, 0xf0
// 007a93ed  0f85bb000000         jne 0x7a94ae
// 007a93f3  8bca                 mov ecx, edx
// 007a93f5  c1e908               shr ecx, 8
// 007a93f8  894c2434             mov dword ptr [esp + 0x34], ecx
// 007a93fc  0fb6c9               movzx ecx, cl
// 007a93ff  894c2424             mov dword ptr [esp + 0x24], ecx
// 007a9403  0fb6ca               movzx ecx, dl
// 007a9406  034c2424             add ecx, dword ptr [esp + 0x24]
// 007a940a  89542418             mov dword ptr [esp + 0x18], edx
// 007a940e  ba01000000           mov edx, 1
// 007a9413  d3e2                 shl edx, cl
// 007a9415  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 007a9419  83ea01               sub edx, 1
// 007a941c  23d3                 and edx, ebx
// 007a941e  d3ea                 shr edx, cl
// 007a9420  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 007a9424  c1e910               shr ecx, 0x10
// 007a9427  03d1                 add edx, ecx
// 007a9429  8b4f50               mov ecx, dword ptr [edi + 0x50]
// 007a942c  8b0c91               mov ecx, dword ptr [ecx + edx*4]
// 007a942f  894c2414             mov dword ptr [esp + 0x14], ecx
// 007a9433  c1e908               shr ecx, 8
// 007a9436  0fb6d1               movzx edx, cl
// 007a9439  0fb64c2434           movzx ecx, byte ptr [esp + 0x34]
// 007a943e  03d1                 add edx, ecx
// 007a9440  3bd6                 cmp edx, esi
// 007a9442  765d                 jbe 0x7a94a1
// 007a9444  85c0                 test eax, eax
// 007a9446  0f8480030000         je 0x7a97cc
// 007a944c  0fb65500             movzx edx, byte ptr [ebp]
// 007a9450  8bce                 mov ecx, esi
// 007a9452  d3e2                 shl edx, cl
// 007a9454  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 007a9458  83e801               sub eax, 1
// 007a945b  83c608               add esi, 8
// 007a945e  03da                 add ebx, edx
// 007a9460  0fb6d5               movzx edx, ch
// 007a9463  03ca                 add ecx, edx
// 007a9465  89542424             mov dword ptr [esp + 0x24], edx
// 007a9469  ba01000000           mov edx, 1
// 007a946e  d3e2                 shl edx, cl
// 007a9470  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 007a9474  83c501               add ebp, 1
// 007a9477  89442410             mov dword ptr [esp + 0x10], eax
// 007a947b  83ea01               sub edx, 1
// 007a947e  23d3                 and edx, ebx
// 007a9480  d3ea                 shr edx, cl
// 007a9482  0fb74c241a           movzx ecx, word ptr [esp + 0x1a]
// 007a9487  03d1                 add edx, ecx
// 007a9489  8b4f50               mov ecx, dword ptr [edi + 0x50]
// 007a948c  8b0c91               mov ecx, dword ptr [ecx + edx*4]
// 007a948f  894c2414             mov dword ptr [esp + 0x14], ecx
// 007a9493  c1e908               shr ecx, 8
// 007a9496  0fb6d1               movzx edx, cl
// 007a9499  03542424             add edx, dword ptr [esp + 0x24]
// 007a949d  3bd6                 cmp edx, esi
// 007a949f  77a3                 ja 0x7a9444
// 007a94a1  0fb64c2419           movzx ecx, byte ptr [esp + 0x19]
// 007a94a6  8b542414             mov edx, dword ptr [esp + 0x14]
// 007a94aa  d3eb                 shr ebx, cl
// 007a94ac  2bf1                 sub esi, ecx
// 007a94ae  8bca                 mov ecx, edx
// 007a94b0  c1e908               shr ecx, 8
// 007a94b3  0fb6c9               movzx ecx, cl
// 007a94b6  d3eb                 shr ebx, cl
// 007a94b8  2bf1                 sub esi, ecx
// 007a94ba  f6c240               test dl, 0x40
// 007a94bd  894c2424             mov dword ptr [esp + 0x24], ecx
// 007a94c1  895c2418             mov dword ptr [esp + 0x18], ebx
// 007a94c5  7410                 je 0x7a94d7
// 007a94c7  8b542440             mov edx, dword ptr [esp + 0x40]
// 007a94cb  c7421808ed8600       mov dword ptr [edx + 0x18], 0x86ed08
// 007a94d2  e991020000           jmp 0x7a9768
// 007a94d7  8bca                 mov ecx, edx
// 007a94d9  c1e910               shr ecx, 0x10
// 007a94dc  83e20f               and edx, 0xf
// 007a94df  894f44               mov dword ptr [edi + 0x44], ecx
// 007a94e2  895748               mov dword ptr [edi + 0x48], edx
// 007a94e5  c70715000000         mov dword ptr [edi], 0x15
// 007a94eb  8b4f48               mov ecx, dword ptr [edi + 0x48]
// 007a94ee  85c9                 test ecx, ecx
// 007a94f0  7442                 je 0x7a9534
// 007a94f2  3bf1                 cmp esi, ecx
// 007a94f4  7324                 jae 0x7a951a
// 007a94f6  85c0                 test eax, eax
// 007a94f8  0f84ce020000         je 0x7a97cc
// 007a94fe  0fb65500             movzx edx, byte ptr [ebp]
// 007a9502  8bce                 mov ecx, esi
// 007a9504  d3e2                 shl edx, cl
// 007a9506  83e801               sub eax, 1
// 007a9509  83c608               add esi, 8
// 007a950c  83c501               add ebp, 1
// 007a950f  03da                 add ebx, edx
// 007a9511  3b7748               cmp esi, dword ptr [edi + 0x48]
// 007a9514  89442410             mov dword ptr [esp + 0x10], eax
// 007a9518  72dc                 jb 0x7a94f6
// 007a951a  8b4f48               mov ecx, dword ptr [edi + 0x48]
// 007a951d  ba01000000           mov edx, 1
// 007a9522  d3e2                 shl edx, cl
// 007a9524  83ea01               sub edx, 1
// 007a9527  23d3                 and edx, ebx
// 007a9529  015744               add dword ptr [edi + 0x44], edx
// 007a952c  d3eb                 shr ebx, cl
// 007a952e  2bf1                 sub esi, ecx
// 007a9530  895c2418             mov dword ptr [esp + 0x18], ebx
// 007a9534  8b4f2c               mov ecx, dword ptr [edi + 0x2c]
// 007a9537  2b4c241c             sub ecx, dword ptr [esp + 0x1c]
// 007a953b  034c242c             add ecx, dword ptr [esp + 0x2c]
// 007a953f  394f44               cmp dword ptr [edi + 0x44], ecx
// 007a9542  7610                 jbe 0x7a9554
// 007a9544  8b542440             mov edx, dword ptr [esp + 0x40]
// 007a9548  c74218e8ec8600       mov dword ptr [edx + 0x18], 0x86ece8
// 007a954f  e914020000           jmp 0x7a9768
// 007a9554  c70716000000         mov dword ptr [edi], 0x16
// 007a955a  837c241c00           cmp dword ptr [esp + 0x1c], 0
// 007a955f  0f8467020000         je 0x7a97cc
// 007a9565  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 007a9569  2b54241c             sub edx, dword ptr [esp + 0x1c]
// 007a956d  8b4f44               mov ecx, dword ptr [edi + 0x44]
// 007a9570  3bca                 cmp ecx, edx
// 007a9572  763c                 jbe 0x7a95b0
// 007a9574  2bca                 sub ecx, edx
// 007a9576  8b5730               mov edx, dword ptr [edi + 0x30]
// 007a9579  3bca                 cmp ecx, edx
// 007a957b  894c2414             mov dword ptr [esp + 0x14], ecx
// 007a957f  7610                 jbe 0x7a9591
// 007a9581  2bca                 sub ecx, edx
// 007a9583  8b5734               mov edx, dword ptr [edi + 0x34]
// 007a9586  035728               add edx, dword ptr [edi + 0x28]
// 007a9589  894c2414             mov dword ptr [esp + 0x14], ecx
// 007a958d  2bd1                 sub edx, ecx
// 007a958f  eb0c                 jmp 0x7a959d
// 007a9591  8b5734               mov edx, dword ptr [edi + 0x34]
// 007a9594  2bd1                 sub edx, ecx
// 007a9596  035730               add edx, dword ptr [edi + 0x30]
// 007a9599  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 007a959d  89542424             mov dword ptr [esp + 0x24], edx
// 007a95a1  8b5740               mov edx, dword ptr [edi + 0x40]
// 007a95a4  3bca                 cmp ecx, edx
// 007a95a6  89542434             mov dword ptr [esp + 0x34], edx
// 007a95aa  7619                 jbe 0x7a95c5
// 007a95ac  8bca                 mov ecx, edx
// 007a95ae  eb11                 jmp 0x7a95c1
// 007a95b0  8b542428             mov edx, dword ptr [esp + 0x28]
// 007a95b4  2bd1                 sub edx, ecx
// 007a95b6  8b4f40               mov ecx, dword ptr [edi + 0x40]
// 007a95b9  89542424             mov dword ptr [esp + 0x24], edx
// 007a95bd  894c2434             mov dword ptr [esp + 0x34], ecx
// 007a95c1  894c2414             mov dword ptr [esp + 0x14], ecx
// 007a95c5  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 007a95c9  3bca                 cmp ecx, edx
// 007a95cb  7606                 jbe 0x7a95d3
// 007a95cd  8bca                 mov ecx, edx
// 007a95cf  894c2414             mov dword ptr [esp + 0x14], ecx
// 007a95d3  2bd1                 sub edx, ecx
// 007a95d5  8954241c             mov dword ptr [esp + 0x1c], edx
// 007a95d9  8b542434             mov edx, dword ptr [esp + 0x34]
// 007a95dd  2bd1                 sub edx, ecx
// 007a95df  895740               mov dword ptr [edi + 0x40], edx
// 007a95e2  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 007a95e6  8a11                 mov dl, byte ptr [ecx]
// 007a95e8  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 007a95ec  8811                 mov byte ptr [ecx], dl
// 007a95ee  ba01000000           mov edx, 1
// 007a95f3  01542424             add dword ptr [esp + 0x24], edx
// 007a95f7  03ca                 add ecx, edx
// 007a95f9  29542414             sub dword ptr [esp + 0x14], edx
// 007a95fd  894c2428             mov dword ptr [esp + 0x28], ecx
// 007a9601  75df                 jne 0x7a95e2
// 007a9603  837f4000             cmp dword ptr [edi + 0x40], 0
// 007a9607  0f8561010000         jne 0x7a976e
// 007a960d  c70712000000         mov dword ptr [edi], 0x12
// 007a9613  e956010000           jmp 0x7a976e
// 007a9618  837c241c00           cmp dword ptr [esp + 0x1c], 0
// 007a961d  0f84a9010000         je 0x7a97cc
// 007a9623  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 007a9627  8a5740               mov dl, byte ptr [edi + 0x40]
// 007a962a  8811                 mov byte ptr [ecx], dl
// 007a962c  83c101               add ecx, 1
// 007a962f  836c241c01           sub dword ptr [esp + 0x1c], 1
// 007a9634  894c2428             mov dword ptr [esp + 0x28], ecx
// 007a9638  c70712000000         mov dword ptr [edi], 0x12
// 007a963e  e92b010000           jmp 0x7a976e
// 007a9643  837f0800             cmp dword ptr [edi + 8], 0
// 007a9647  0f84be000000         je 0x7a970b
// 007a964d  83fe20               cmp esi, 0x20
// 007a9650  7328                 jae 0x7a967a
// 007a9652  85c0                 test eax, eax
// 007a9654  0f8472010000         je 0x7a97cc
// 007a965a  0fb65500             movzx edx, byte ptr [ebp]
// 007a965e  8bce                 mov ecx, esi
// 007a9660  d3e2                 shl edx, cl
// 007a9662  83e801               sub eax, 1
// 007a9665  83c608               add esi, 8
// 007a9668  83c501               add ebp, 1
// 007a966b  03da                 add ebx, edx
// 007a966d  83fe20               cmp esi, 0x20
// 007a9670  89442410             mov dword ptr [esp + 0x10], eax
// 007a9674  895c2418             mov dword ptr [esp + 0x18], ebx
// 007a9678  72d8                 jb 0x7a9652
// 007a967a  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 007a967e  2b4c241c             sub ecx, dword ptr [esp + 0x1c]
// 007a9682  8b542440             mov edx, dword ptr [esp + 0x40]
// 007a9686  014a14               add dword ptr [edx + 0x14], ecx
// 007a9689  014f1c               add dword ptr [edi + 0x1c], ecx
// 007a968c  85c9                 test ecx, ecx
// 007a968e  894c242c             mov dword ptr [esp + 0x2c], ecx
// 007a9692  742e                 je 0x7a96c2
// 007a9694  8b5718               mov edx, dword ptr [edi + 0x18]
// 007a9697  8bc1                 mov eax, ecx
// 007a9699  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 007a969d  50                   push eax
// 007a969e  2bc8                 sub ecx, eax
// 007a96a0  837f1000             cmp dword ptr [edi + 0x10], 0
// 007a96a4  51                   push ecx
// 007a96a5  52                   push edx
// 007a96a6  7407                 je 0x7a96af
// 007a96a8  e863eaffff           call 0x7a8110
// 007a96ad  eb05                 jmp 0x7a96b4
// 007a96af  e8fc020000           call 0x7a99b0
// 007a96b4  8b4c2440             mov ecx, dword ptr [esp + 0x40]
// 007a96b8  894718               mov dword ptr [edi + 0x18], eax
// 007a96bb  894130               mov dword ptr [ecx + 0x30], eax
// 007a96be  8b442410             mov eax, dword ptr [esp + 0x10]
// 007a96c2  837f1000             cmp dword ptr [edi + 0x10], 0
// 007a96c6  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 007a96ca  8954242c             mov dword ptr [esp + 0x2c], edx
// 007a96ce  8bcb                 mov ecx, ebx
// 007a96d0  751f                 jne 0x7a96f1
// 007a96d2  81e100ff0000         and ecx, 0xff00
// 007a96d8  8bd3                 mov edx, ebx
// 007a96da  c1e210               shl edx, 0x10
// 007a96dd  03ca                 add ecx, edx
// 007a96df  33d2                 xor edx, edx
// 007a96e1  8a74241a             mov dh, byte ptr [esp + 0x1a]
// 007a96e5  c1e108               shl ecx, 8
// 007a96e8  03ca                 add ecx, edx
// 007a96ea  8bd3                 mov edx, ebx
// 007a96ec  c1ea18               shr edx, 0x18
// 007a96ef  03ca                 add ecx, edx
// 007a96f1  3b4f18               cmp ecx, dword ptr [edi + 0x18]
// 007a96f4  740d                 je 0x7a9703
// 007a96f6  8b4c2440             mov ecx, dword ptr [esp + 0x40]
// 007a96fa  c74118d0ec8600       mov dword ptr [ecx + 0x18], 0x86ecd0
// 007a9701  eb65                 jmp 0x7a9768
// 007a9703  33db                 xor ebx, ebx
// 007a9705  895c2418             mov dword ptr [esp + 0x18], ebx
// 007a9709  33f6                 xor esi, esi
// 007a970b  c70719000000         mov dword ptr [edi], 0x19
// 007a9711  837f0800             cmp dword ptr [edi + 8], 0
// 007a9715  0f8499000000         je 0x7a97b4
// 007a971b  837f1000             cmp dword ptr [edi + 0x10], 0
// 007a971f  0f848f000000         je 0x7a97b4
// 007a9725  83fe20               cmp esi, 0x20
// 007a9728  732e                 jae 0x7a9758
// 007a972a  8d9b00000000         lea ebx, [ebx]
// 007a9730  85c0                 test eax, eax
// 007a9732  0f8494000000         je 0x7a97cc
// 007a9738  0fb65500             movzx edx, byte ptr [ebp]
// 007a973c  8bce                 mov ecx, esi
// 007a973e  d3e2                 shl edx, cl
// 007a9740  83e801               sub eax, 1
// 007a9743  83c608               add esi, 8
// 007a9746  83c501               add ebp, 1
// 007a9749  03da                 add ebx, edx
// 007a974b  83fe20               cmp esi, 0x20
// 007a974e  89442410             mov dword ptr [esp + 0x10], eax
// 007a9752  895c2418             mov dword ptr [esp + 0x18], ebx
// 007a9756  72d8                 jb 0x7a9730
// 007a9758  3b5f1c               cmp ebx, dword ptr [edi + 0x1c]
// 007a975b  7453                 je 0x7a97b0
// 007a975d  8b4c2440             mov ecx, dword ptr [esp + 0x40]
// 007a9761  c74118b8ec8600       mov dword ptr [ecx + 0x18], 0x86ecb8
// 007a9768  c7071b000000         mov dword ptr [edi], 0x1b
// 007a976e  8b0f                 mov ecx, dword ptr [edi]
// 007a9770  83f91c               cmp ecx, 0x1c
// 007a9773  0f8697ecffff         jbe 0x7a8410
// 007a9779  5e                   pop esi
// 007a977a  5d                   pop ebp
// 007a977b  5b                   pop ebx
// 007a977c  b8feffffff           mov eax, 0xfffffffe
// 007a9781  5f                   pop edi
// 007a9782  83c42c               add esp, 0x2c
// 007a9785  c20800               ret 8
// 007a9788  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 007a978c  894a0c               mov dword ptr [edx + 0xc], ecx
// 007a978f  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 007a9793  892a                 mov dword ptr [edx], ebp
// 007a9795  894204               mov dword ptr [edx + 4], eax
// 007a9798  894a10               mov dword ptr [edx + 0x10], ecx
// 007a979b  89773c               mov dword ptr [edi + 0x3c], esi
// 007a979e  5e                   pop esi
// 007a979f  5d                   pop ebp
// 007a97a0  895f38               mov dword ptr [edi + 0x38], ebx
// 007a97a3  5b                   pop ebx
// 007a97a4  b802000000           mov eax, 2
// 007a97a9  5f                   pop edi
// 007a97aa  83c42c               add esp, 0x2c
// 007a97ad  c20800               ret 8
// 007a97b0  33db                 xor ebx, ebx
// 007a97b2  33f6                 xor esi, esi
// 007a97b4  c7071a000000         mov dword ptr [edi], 0x1a
// 007a97ba  c744243001000000     mov dword ptr [esp + 0x30], 1
// 007a97c2  eb08                 jmp 0x7a97cc
// 007a97c4  c7442430fdffffff     mov dword ptr [esp + 0x30], 0xfffffffd
// 007a97cc  8b4c2440             mov ecx, dword ptr [esp + 0x40]
// 007a97d0  8b542428             mov edx, dword ptr [esp + 0x28]
// 007a97d4  89510c               mov dword ptr [ecx + 0xc], edx
// 007a97d7  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 007a97db  895110               mov dword ptr [ecx + 0x10], edx
// 007a97de  8929                 mov dword ptr [ecx], ebp
// 007a97e0  894104               mov dword ptr [ecx + 4], eax
// 007a97e3  837f2800             cmp dword ptr [edi + 0x28], 0
// 007a97e7  895f38               mov dword ptr [edi + 0x38], ebx
// 007a97ea  89773c               mov dword ptr [edi + 0x3c], esi
// 007a97ed  750e                 jne 0x7a97fd
// 007a97ef  833f18               cmp dword ptr [edi], 0x18
// 007a97f2  7d2f                 jge 0x7a9823
// 007a97f4  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 007a97f8  3b4110               cmp eax, dword ptr [ecx + 0x10]
// 007a97fb  7426                 je 0x7a9823
// 007a97fd  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 007a9801  8b5c2440             mov ebx, dword ptr [esp + 0x40]
// 007a9805  e886eaffff           call 0x7a8290
// 007a980a  85c0                 test eax, eax
// 007a980c  7415                 je 0x7a9823
// 007a980e  c7071c000000         mov dword ptr [edi], 0x1c
// 007a9814  5e                   pop esi
// 007a9815  5d                   pop ebp
// 007a9816  5b                   pop ebx
// 007a9817  b8fcffffff           mov eax, 0xfffffffc
// 007a981c  5f                   pop edi
// 007a981d  83c42c               add esp, 0x2c
// 007a9820  c20800               ret 8
// 007a9823  8b742440             mov esi, dword ptr [esp + 0x40]
// 007a9827  8b6c2438             mov ebp, dword ptr [esp + 0x38]
// 007a982b  2b6e04               sub ebp, dword ptr [esi + 4]
// 007a982e  8b5c242c             mov ebx, dword ptr [esp + 0x2c]
// 007a9832  2b5e10               sub ebx, dword ptr [esi + 0x10]
// 007a9835  016e08               add dword ptr [esi + 8], ebp
// 007a9838  015e14               add dword ptr [esi + 0x14], ebx
// 007a983b  015f1c               add dword ptr [edi + 0x1c], ebx
// 007a983e  837f0800             cmp dword ptr [edi + 8], 0
// 007a9842  7431                 je 0x7a9875
// 007a9844  85db                 test ebx, ebx
// 007a9846  742d                 je 0x7a9875
// 007a9848  837f1000             cmp dword ptr [edi + 0x10], 0
// 007a984c  53                   push ebx
// 007a984d  7411                 je 0x7a9860
// 007a984f  8b560c               mov edx, dword ptr [esi + 0xc]
// 007a9852  8b4718               mov eax, dword ptr [edi + 0x18]
// 007a9855  2bd3                 sub edx, ebx
// 007a9857  52                   push edx
// 007a9858  50                   push eax
// 007a9859  e8b2e8ffff           call 0x7a8110
// 007a985e  eb0f                 jmp 0x7a986f
// 007a9860  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 007a9863  8b5718               mov edx, dword ptr [edi + 0x18]
// 007a9866  2bcb                 sub ecx, ebx
// 007a9868  51                   push ecx
// 007a9869  52                   push edx
// 007a986a  e841010000           call 0x7a99b0
// 007a986f  894718               mov dword ptr [edi + 0x18], eax
// 007a9872  894630               mov dword ptr [esi + 0x30], eax
// 007a9875  8b4704               mov eax, dword ptr [edi + 4]
// 007a9878  f7d8                 neg eax
// 007a987a  1bc0                 sbb eax, eax
// 007a987c  83e040               and eax, 0x40
// 007a987f  33c9                 xor ecx, ecx
// 007a9881  833f0b               cmp dword ptr [edi], 0xb
// 007a9884  0f95c1               setne cl
// 007a9887  83e901               sub ecx, 1
// 007a988a  81e180000000         and ecx, 0x80
// 007a9890  03c1                 add eax, ecx
// 007a9892  03473c               add eax, dword ptr [edi + 0x3c]
// 007a9895  85ed                 test ebp, ebp
// 007a9897  89462c               mov dword ptr [esi + 0x2c], eax
// 007a989a  7504                 jne 0x7a98a0
// 007a989c  85db                 test ebx, ebx
// 007a989e  7407                 je 0x7a98a7
// 007a98a0  837c244404           cmp dword ptr [esp + 0x44], 4
// 007a98a5  751b                 jne 0x7a98c2
// 007a98a7  8b442430             mov eax, dword ptr [esp + 0x30]
// 007a98ab  85c0                 test eax, eax
// 007a98ad  0f854cebffff         jne 0x7a83ff
// 007a98b3  5e                   pop esi
// 007a98b4  5d                   pop ebp
// 007a98b5  5b                   pop ebx
// 007a98b6  b8fbffffff           mov eax, 0xfffffffb
// 007a98bb  5f                   pop edi
// 007a98bc  83c42c               add esp, 0x2c
// 007a98bf  c20800               ret 8
// 007a98c2  8b442430             mov eax, dword ptr [esp + 0x30]
// 007a98c6  5e                   pop esi
// 007a98c7  5d                   pop ebp
// 007a98c8  5b                   pop ebx
// 007a98c9  5f                   pop edi
// 007a98ca  83c42c               add esp, 0x2c
// 007a98cd  c20800               ret 8
// 007a98d0  b8feffffff           mov eax, 0xfffffffe
// 007a98d5  5f                   pop edi
// 007a98d6  83c42c               add esp, 0x2c
// 007a98d9  c20800               ret 8
// 007a98dc  1b847a0080857a       sbb eax, dword ptr [edx + edi*2 + 0x7a858000]
// 007a98e3  0025867a00a7         add byte ptr [0xa7007a86], ah
// 007a98e9  867a00               xchg byte ptr [edx], bh
// 007a98ec  2a877a00b287         sub al, byte ptr [edi - 0x784dff86]
// 007a98f2  7a00                 jp 0x7a98f4
// 007a98f4  6b887a0020897a       imul ecx, dword ptr [eax - 0x76dfff86], 0x7a
// 007a98fb  00d7                 add bh, dl
// 007a98fd  897a00               mov dword ptr [edx], edi
// 007a9900  6e                   outsb dx, byte ptr [esi]
// 007a9901  8a7a00               mov bh, byte ptr [edx]
// 007a9904  ce                   into 
// 007a9905  8a7a00               mov bh, byte ptr [edx]
// 007a9908  f78a7a00028b7a00e28b test dword ptr [edx - 0x74fdff86], 0x8be2007a
// 007a9912  7a00                 jp 0x7a9914
// 007a9914  50                   push eax

void func_007a8380()
{
}
