// from server: 100% by auto
// roc 2009-12 00808920  unit: CXTPCommandBar  size: 535 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00808920
//
// 00808920  83ec58               sub esp, 0x58
// 00808923  56                   push esi
// 00808924  8b355cb19800         mov esi, dword ptr [0x98b15c]
// 0080892a  57                   push edi
// 0080892b  8d442430             lea eax, [esp + 0x30]
// 0080892f  50                   push eax
// 00808930  8bf9                 mov edi, ecx
// 00808932  8b4c2468             mov ecx, dword ptr [esp + 0x68]
// 00808936  6a18                 push 0x18
// 00808938  51                   push ecx
// 00808939  ffd6                 call esi
// 0080893b  85c0                 test eax, eax
// 0080893d  0f84ea010000         je 0x808b2d
// 00808943  8b44246c             mov eax, dword ptr [esp + 0x6c]
// 00808947  8d542448             lea edx, [esp + 0x48]
// 0080894b  52                   push edx
// 0080894c  6a18                 push 0x18
// 0080894e  50                   push eax
// 0080894f  ffd6                 call esi
// 00808951  85c0                 test eax, eax
// 00808953  0f84d4010000         je 0x808b2d
// 00808959  8b542474             mov edx, dword ptr [esp + 0x74]
// 0080895d  8d4c2418             lea ecx, [esp + 0x18]
// 00808961  51                   push ecx
// 00808962  6a18                 push 0x18
// 00808964  52                   push edx
// 00808965  ffd6                 call esi
// 00808967  85c0                 test eax, eax
// 00808969  0f84be010000         je 0x808b2d
// 0080896f  8d442448             lea eax, [esp + 0x48]
// 00808973  50                   push eax
// 00808974  8d4c2434             lea ecx, [esp + 0x34]
// 00808978  51                   push ecx
// 00808979  8bcf                 mov ecx, edi
// 0080897b  e8b0fcffff           call 0x808630
// 00808980  85c0                 test eax, eax
// 00808982  0f84a5010000         je 0x808b2d
// 00808988  8d542418             lea edx, [esp + 0x18]
// 0080898c  52                   push edx
// 0080898d  8d442434             lea eax, [esp + 0x34]
// 00808991  50                   push eax
// 00808992  8bcf                 mov ecx, edi
// 00808994  e897fcffff           call 0x808630
// 00808999  85c0                 test eax, eax
// 0080899b  0f848c010000         je 0x808b2d
// 008089a1  66837c244220         cmp word ptr [esp + 0x42], 0x20
// 008089a7  0f8580010000         jne 0x808b2d
// 008089ad  66837c244001         cmp word ptr [esp + 0x40], 1
// 008089b3  0f8574010000         jne 0x808b2d
// 008089b9  8b442444             mov eax, dword ptr [esp + 0x44]
// 008089bd  85c0                 test eax, eax
// 008089bf  0f8468010000         je 0x808b2d
// 008089c5  8b54245c             mov edx, dword ptr [esp + 0x5c]
// 008089c9  85d2                 test edx, edx
// 008089cb  0f845c010000         je 0x808b2d
// 008089d1  8b74242c             mov esi, dword ptr [esp + 0x2c]
// 008089d5  85f6                 test esi, esi
// 008089d7  0f8450010000         je 0x808b2d
// 008089dd  837c242000           cmp dword ptr [esp + 0x20], 0
// 008089e2  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 008089e6  894c2414             mov dword ptr [esp + 0x14], ecx
// 008089ea  89442464             mov dword ptr [esp + 0x64], eax
// 008089ee  89542474             mov dword ptr [esp + 0x74], edx
// 008089f2  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 008089fa  0f8e20010000         jle 0x808b20
// 00808a00  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00808a04  53                   push ebx
// 00808a05  8d7e01               lea edi, [esi + 1]
// 00808a08  55                   push ebp
// 00808a09  897c2410             mov dword ptr [esp + 0x10], edi
// 00808a0d  8d4900               lea ecx, [ecx]
// 00808a10  33ed                 xor ebp, ebp
// 00808a12  85c0                 test eax, eax
// 00808a14  0f8edd000000         jle 0x808af7
// 00808a1a  8b4c246c             mov ecx, dword ptr [esp + 0x6c]
// 00808a1e  8bda                 mov ebx, edx
// 00808a20  2bca                 sub ecx, edx
// 00808a22  895c2474             mov dword ptr [esp + 0x74], ebx
// 00808a26  894c2418             mov dword ptr [esp + 0x18], ecx
// 00808a2a  eb0c                 jmp 0x808a38
// 00808a2c  8d642400             lea esp, [esp]
// 00808a30  8b5c2474             mov ebx, dword ptr [esp + 0x74]
// 00808a34  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00808a38  837c247000           cmp dword ptr [esp + 0x70], 0
// 00808a3d  740e                 je 0x808a4d
// 00808a3f  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 00808a43  8bc8                 mov ecx, eax
// 00808a45  2bcd                 sub ecx, ebp
// 00808a47  8d4c8efc             lea ecx, [esi + ecx*4 - 4]
// 00808a4b  eb02                 jmp 0x808a4f
// 00808a4d  03cb                 add ecx, ebx
// 00808a4f  837c247800           cmp dword ptr [esp + 0x78], 0
// 00808a54  7406                 je 0x808a5c
// 00808a56  2bc5                 sub eax, ebp
// 00808a58  8d5c82fc             lea ebx, [edx + eax*4 - 4]
// 00808a5c  0fb65103             movzx edx, byte ptr [ecx + 3]
// 00808a60  0fb67302             movzx esi, byte ptr [ebx + 2]
// 00808a64  b8ff000000           mov eax, 0xff
// 00808a69  2bc2                 sub eax, edx
// 00808a6b  0faff0               imul esi, eax
// 00808a6e  b881808080           mov eax, 0x80808081
// 00808a73  f7ee                 imul esi
// 00808a75  03d6                 add edx, esi
// 00808a77  c1fa07               sar edx, 7
// 00808a7a  8bc2                 mov eax, edx
// 00808a7c  c1e81f               shr eax, 0x1f
// 00808a7f  03c2                 add eax, edx
// 00808a81  024102               add al, byte ptr [ecx + 2]
// 00808a84  8344247404           add dword ptr [esp + 0x74], 4
// 00808a89  884701               mov byte ptr [edi + 1], al
// 00808a8c  0fb65103             movzx edx, byte ptr [ecx + 3]
// 00808a90  0fb67301             movzx esi, byte ptr [ebx + 1]
// 00808a94  b8ff000000           mov eax, 0xff
// 00808a99  2bc2                 sub eax, edx
// 00808a9b  0faff0               imul esi, eax
// 00808a9e  b881808080           mov eax, 0x80808081
// 00808aa3  f7ee                 imul esi
// 00808aa5  03d6                 add edx, esi
// 00808aa7  c1fa07               sar edx, 7
// 00808aaa  8bc2                 mov eax, edx
// 00808aac  c1e81f               shr eax, 0x1f
// 00808aaf  03c2                 add eax, edx
// 00808ab1  024101               add al, byte ptr [ecx + 1]
// 00808ab4  beff000000           mov esi, 0xff
// 00808ab9  8807                 mov byte ptr [edi], al
// 00808abb  0fb65103             movzx edx, byte ptr [ecx + 3]
// 00808abf  0fb603               movzx eax, byte ptr [ebx]
// 00808ac2  2bf2                 sub esi, edx
// 00808ac4  0faff0               imul esi, eax
// 00808ac7  b881808080           mov eax, 0x80808081
// 00808acc  f7ee                 imul esi
// 00808ace  03d6                 add edx, esi
// 00808ad0  c1fa07               sar edx, 7
// 00808ad3  8bc2                 mov eax, edx
// 00808ad5  c1e81f               shr eax, 0x1f
// 00808ad8  03c2                 add eax, edx
// 00808ada  0201                 add al, byte ptr [ecx]
// 00808adc  8b54247c             mov edx, dword ptr [esp + 0x7c]
// 00808ae0  8847ff               mov byte ptr [edi - 1], al
// 00808ae3  8b442424             mov eax, dword ptr [esp + 0x24]
// 00808ae7  45                   inc ebp
// 00808ae8  83c704               add edi, 4
// 00808aeb  3be8                 cmp ebp, eax
// 00808aed  0f8c3dffffff         jl 0x808a30
// 00808af3  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00808af7  8b742414             mov esi, dword ptr [esp + 0x14]
// 00808afb  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00808aff  014c246c             add dword ptr [esp + 0x6c], ecx
// 00808b03  46                   inc esi
// 00808b04  03d1                 add edx, ecx
// 00808b06  03f9                 add edi, ecx
// 00808b08  3b742428             cmp esi, dword ptr [esp + 0x28]
// 00808b0c  8954247c             mov dword ptr [esp + 0x7c], edx
// 00808b10  897c2410             mov dword ptr [esp + 0x10], edi
// 00808b14  89742414             mov dword ptr [esp + 0x14], esi
// 00808b18  0f8cf2feffff         jl 0x808a10
// 00808b1e  5d                   pop ebp
// 00808b1f  5b                   pop ebx
// 00808b20  5f                   pop edi
// 00808b21  b801000000           mov eax, 1
// 00808b26  5e                   pop esi
// 00808b27  83c458               add esp, 0x58
// 00808b2a  c21400               ret 0x14
// 00808b2d  5f                   pop edi
// 00808b2e  33c0                 xor eax, eax
// 00808b30  5e                   pop esi
// 00808b31  83c458               add esp, 0x58
// 00808b34  c21400               ret 0x14
// library xtp-15.2.1/Source\Common\XTPImageManager.cpp (function ?BlendImages@CXTPImageManager@@ABEHPAUHBITMAP__@@H0H0@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPImageManager.cpp
