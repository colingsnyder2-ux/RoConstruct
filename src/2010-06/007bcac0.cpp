// from server: 100% by auto
// roc 2010-06 007bcac0  unit: CXTPCommandBar  size: 535 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007bcac0
//
// 007bcac0  83ec58               sub esp, 0x58
// 007bcac3  56                   push esi
// 007bcac4  8b35bca09e00         mov esi, dword ptr [0x9ea0bc]
// 007bcaca  57                   push edi
// 007bcacb  8d442430             lea eax, [esp + 0x30]
// 007bcacf  50                   push eax
// 007bcad0  8bf9                 mov edi, ecx
// 007bcad2  8b4c2468             mov ecx, dword ptr [esp + 0x68]
// 007bcad6  6a18                 push 0x18
// 007bcad8  51                   push ecx
// 007bcad9  ffd6                 call esi
// 007bcadb  85c0                 test eax, eax
// 007bcadd  0f84ea010000         je 0x7bcccd
// 007bcae3  8b44246c             mov eax, dword ptr [esp + 0x6c]
// 007bcae7  8d542448             lea edx, [esp + 0x48]
// 007bcaeb  52                   push edx
// 007bcaec  6a18                 push 0x18
// 007bcaee  50                   push eax
// 007bcaef  ffd6                 call esi
// 007bcaf1  85c0                 test eax, eax
// 007bcaf3  0f84d4010000         je 0x7bcccd
// 007bcaf9  8b542474             mov edx, dword ptr [esp + 0x74]
// 007bcafd  8d4c2418             lea ecx, [esp + 0x18]
// 007bcb01  51                   push ecx
// 007bcb02  6a18                 push 0x18
// 007bcb04  52                   push edx
// 007bcb05  ffd6                 call esi
// 007bcb07  85c0                 test eax, eax
// 007bcb09  0f84be010000         je 0x7bcccd
// 007bcb0f  8d442448             lea eax, [esp + 0x48]
// 007bcb13  50                   push eax
// 007bcb14  8d4c2434             lea ecx, [esp + 0x34]
// 007bcb18  51                   push ecx
// 007bcb19  8bcf                 mov ecx, edi
// 007bcb1b  e8b0fcffff           call 0x7bc7d0
// 007bcb20  85c0                 test eax, eax
// 007bcb22  0f84a5010000         je 0x7bcccd
// 007bcb28  8d542418             lea edx, [esp + 0x18]
// 007bcb2c  52                   push edx
// 007bcb2d  8d442434             lea eax, [esp + 0x34]
// 007bcb31  50                   push eax
// 007bcb32  8bcf                 mov ecx, edi
// 007bcb34  e897fcffff           call 0x7bc7d0
// 007bcb39  85c0                 test eax, eax
// 007bcb3b  0f848c010000         je 0x7bcccd
// 007bcb41  66837c244220         cmp word ptr [esp + 0x42], 0x20
// 007bcb47  0f8580010000         jne 0x7bcccd
// 007bcb4d  66837c244001         cmp word ptr [esp + 0x40], 1
// 007bcb53  0f8574010000         jne 0x7bcccd
// 007bcb59  8b442444             mov eax, dword ptr [esp + 0x44]
// 007bcb5d  85c0                 test eax, eax
// 007bcb5f  0f8468010000         je 0x7bcccd
// 007bcb65  8b54245c             mov edx, dword ptr [esp + 0x5c]
// 007bcb69  85d2                 test edx, edx
// 007bcb6b  0f845c010000         je 0x7bcccd
// 007bcb71  8b74242c             mov esi, dword ptr [esp + 0x2c]
// 007bcb75  85f6                 test esi, esi
// 007bcb77  0f8450010000         je 0x7bcccd
// 007bcb7d  837c242000           cmp dword ptr [esp + 0x20], 0
// 007bcb82  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 007bcb86  894c2414             mov dword ptr [esp + 0x14], ecx
// 007bcb8a  89442464             mov dword ptr [esp + 0x64], eax
// 007bcb8e  89542474             mov dword ptr [esp + 0x74], edx
// 007bcb92  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 007bcb9a  0f8e20010000         jle 0x7bccc0
// 007bcba0  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 007bcba4  53                   push ebx
// 007bcba5  8d7e01               lea edi, [esi + 1]
// 007bcba8  55                   push ebp
// 007bcba9  897c2410             mov dword ptr [esp + 0x10], edi
// 007bcbad  8d4900               lea ecx, [ecx]
// 007bcbb0  33ed                 xor ebp, ebp
// 007bcbb2  85c0                 test eax, eax
// 007bcbb4  0f8edd000000         jle 0x7bcc97
// 007bcbba  8b4c246c             mov ecx, dword ptr [esp + 0x6c]
// 007bcbbe  8bda                 mov ebx, edx
// 007bcbc0  2bca                 sub ecx, edx
// 007bcbc2  895c2474             mov dword ptr [esp + 0x74], ebx
// 007bcbc6  894c2418             mov dword ptr [esp + 0x18], ecx
// 007bcbca  eb0c                 jmp 0x7bcbd8
// 007bcbcc  8d642400             lea esp, [esp]
// 007bcbd0  8b5c2474             mov ebx, dword ptr [esp + 0x74]
// 007bcbd4  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 007bcbd8  837c247000           cmp dword ptr [esp + 0x70], 0
// 007bcbdd  740e                 je 0x7bcbed
// 007bcbdf  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 007bcbe3  8bc8                 mov ecx, eax
// 007bcbe5  2bcd                 sub ecx, ebp
// 007bcbe7  8d4c8efc             lea ecx, [esi + ecx*4 - 4]
// 007bcbeb  eb02                 jmp 0x7bcbef
// 007bcbed  03cb                 add ecx, ebx
// 007bcbef  837c247800           cmp dword ptr [esp + 0x78], 0
// 007bcbf4  7406                 je 0x7bcbfc
// 007bcbf6  2bc5                 sub eax, ebp
// 007bcbf8  8d5c82fc             lea ebx, [edx + eax*4 - 4]
// 007bcbfc  0fb65103             movzx edx, byte ptr [ecx + 3]
// 007bcc00  0fb67302             movzx esi, byte ptr [ebx + 2]
// 007bcc04  b8ff000000           mov eax, 0xff
// 007bcc09  2bc2                 sub eax, edx
// 007bcc0b  0faff0               imul esi, eax
// 007bcc0e  b881808080           mov eax, 0x80808081
// 007bcc13  f7ee                 imul esi
// 007bcc15  03d6                 add edx, esi
// 007bcc17  c1fa07               sar edx, 7
// 007bcc1a  8bc2                 mov eax, edx
// 007bcc1c  c1e81f               shr eax, 0x1f
// 007bcc1f  03c2                 add eax, edx
// 007bcc21  024102               add al, byte ptr [ecx + 2]
// 007bcc24  8344247404           add dword ptr [esp + 0x74], 4
// 007bcc29  884701               mov byte ptr [edi + 1], al
// 007bcc2c  0fb65103             movzx edx, byte ptr [ecx + 3]
// 007bcc30  0fb67301             movzx esi, byte ptr [ebx + 1]
// 007bcc34  b8ff000000           mov eax, 0xff
// 007bcc39  2bc2                 sub eax, edx
// 007bcc3b  0faff0               imul esi, eax
// 007bcc3e  b881808080           mov eax, 0x80808081
// 007bcc43  f7ee                 imul esi
// 007bcc45  03d6                 add edx, esi
// 007bcc47  c1fa07               sar edx, 7
// 007bcc4a  8bc2                 mov eax, edx
// 007bcc4c  c1e81f               shr eax, 0x1f
// 007bcc4f  03c2                 add eax, edx
// 007bcc51  024101               add al, byte ptr [ecx + 1]
// 007bcc54  beff000000           mov esi, 0xff
// 007bcc59  8807                 mov byte ptr [edi], al
// 007bcc5b  0fb65103             movzx edx, byte ptr [ecx + 3]
// 007bcc5f  0fb603               movzx eax, byte ptr [ebx]
// 007bcc62  2bf2                 sub esi, edx
// 007bcc64  0faff0               imul esi, eax
// 007bcc67  b881808080           mov eax, 0x80808081
// 007bcc6c  f7ee                 imul esi
// 007bcc6e  03d6                 add edx, esi
// 007bcc70  c1fa07               sar edx, 7
// 007bcc73  8bc2                 mov eax, edx
// 007bcc75  c1e81f               shr eax, 0x1f
// 007bcc78  03c2                 add eax, edx
// 007bcc7a  0201                 add al, byte ptr [ecx]
// 007bcc7c  8b54247c             mov edx, dword ptr [esp + 0x7c]
// 007bcc80  8847ff               mov byte ptr [edi - 1], al
// 007bcc83  8b442424             mov eax, dword ptr [esp + 0x24]
// 007bcc87  45                   inc ebp
// 007bcc88  83c704               add edi, 4
// 007bcc8b  3be8                 cmp ebp, eax
// 007bcc8d  0f8c3dffffff         jl 0x7bcbd0
// 007bcc93  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 007bcc97  8b742414             mov esi, dword ptr [esp + 0x14]
// 007bcc9b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 007bcc9f  014c246c             add dword ptr [esp + 0x6c], ecx
// 007bcca3  46                   inc esi
// 007bcca4  03d1                 add edx, ecx
// 007bcca6  03f9                 add edi, ecx
// 007bcca8  3b742428             cmp esi, dword ptr [esp + 0x28]
// 007bccac  8954247c             mov dword ptr [esp + 0x7c], edx
// 007bccb0  897c2410             mov dword ptr [esp + 0x10], edi
// 007bccb4  89742414             mov dword ptr [esp + 0x14], esi
// 007bccb8  0f8cf2feffff         jl 0x7bcbb0
// 007bccbe  5d                   pop ebp
// 007bccbf  5b                   pop ebx
// 007bccc0  5f                   pop edi
// 007bccc1  b801000000           mov eax, 1
// 007bccc6  5e                   pop esi
// 007bccc7  83c458               add esp, 0x58
// 007bccca  c21400               ret 0x14
// 007bcccd  5f                   pop edi
// 007bccce  33c0                 xor eax, eax
// 007bccd0  5e                   pop esi
// 007bccd1  83c458               add esp, 0x58
// 007bccd4  c21400               ret 0x14
// library xtp-13.2.1/Source\Common\XTPImageManager.cpp (function ?BlendImages@CXTPImageManager@@ABEHPAUHBITMAP__@@H0H0@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPImageManager.cpp
