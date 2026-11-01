// from server: 100% by auto
// roc 2009-06 007317a0  unit: CXTPCommandBar  size: 535 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007317a0
//
// 007317a0  83ec58               sub esp, 0x58
// 007317a3  56                   push esi
// 007317a4  8b3564e18900         mov esi, dword ptr [0x89e164]
// 007317aa  57                   push edi
// 007317ab  8d442430             lea eax, [esp + 0x30]
// 007317af  50                   push eax
// 007317b0  8bf9                 mov edi, ecx
// 007317b2  8b4c2468             mov ecx, dword ptr [esp + 0x68]
// 007317b6  6a18                 push 0x18
// 007317b8  51                   push ecx
// 007317b9  ffd6                 call esi
// 007317bb  85c0                 test eax, eax
// 007317bd  0f84ea010000         je 0x7319ad
// 007317c3  8b44246c             mov eax, dword ptr [esp + 0x6c]
// 007317c7  8d542448             lea edx, [esp + 0x48]
// 007317cb  52                   push edx
// 007317cc  6a18                 push 0x18
// 007317ce  50                   push eax
// 007317cf  ffd6                 call esi
// 007317d1  85c0                 test eax, eax
// 007317d3  0f84d4010000         je 0x7319ad
// 007317d9  8b542474             mov edx, dword ptr [esp + 0x74]
// 007317dd  8d4c2418             lea ecx, [esp + 0x18]
// 007317e1  51                   push ecx
// 007317e2  6a18                 push 0x18
// 007317e4  52                   push edx
// 007317e5  ffd6                 call esi
// 007317e7  85c0                 test eax, eax
// 007317e9  0f84be010000         je 0x7319ad
// 007317ef  8d442448             lea eax, [esp + 0x48]
// 007317f3  50                   push eax
// 007317f4  8d4c2434             lea ecx, [esp + 0x34]
// 007317f8  51                   push ecx
// 007317f9  8bcf                 mov ecx, edi
// 007317fb  e8b0fcffff           call 0x7314b0
// 00731800  85c0                 test eax, eax
// 00731802  0f84a5010000         je 0x7319ad
// 00731808  8d542418             lea edx, [esp + 0x18]
// 0073180c  52                   push edx
// 0073180d  8d442434             lea eax, [esp + 0x34]
// 00731811  50                   push eax
// 00731812  8bcf                 mov ecx, edi
// 00731814  e897fcffff           call 0x7314b0
// 00731819  85c0                 test eax, eax
// 0073181b  0f848c010000         je 0x7319ad
// 00731821  66837c244220         cmp word ptr [esp + 0x42], 0x20
// 00731827  0f8580010000         jne 0x7319ad
// 0073182d  66837c244001         cmp word ptr [esp + 0x40], 1
// 00731833  0f8574010000         jne 0x7319ad
// 00731839  8b442444             mov eax, dword ptr [esp + 0x44]
// 0073183d  85c0                 test eax, eax
// 0073183f  0f8468010000         je 0x7319ad
// 00731845  8b54245c             mov edx, dword ptr [esp + 0x5c]
// 00731849  85d2                 test edx, edx
// 0073184b  0f845c010000         je 0x7319ad
// 00731851  8b74242c             mov esi, dword ptr [esp + 0x2c]
// 00731855  85f6                 test esi, esi
// 00731857  0f8450010000         je 0x7319ad
// 0073185d  837c242000           cmp dword ptr [esp + 0x20], 0
// 00731862  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00731866  894c2414             mov dword ptr [esp + 0x14], ecx
// 0073186a  89442464             mov dword ptr [esp + 0x64], eax
// 0073186e  89542474             mov dword ptr [esp + 0x74], edx
// 00731872  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 0073187a  0f8e20010000         jle 0x7319a0
// 00731880  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00731884  53                   push ebx
// 00731885  8d7e01               lea edi, [esi + 1]
// 00731888  55                   push ebp
// 00731889  897c2410             mov dword ptr [esp + 0x10], edi
// 0073188d  8d4900               lea ecx, [ecx]
// 00731890  33ed                 xor ebp, ebp
// 00731892  85c0                 test eax, eax
// 00731894  0f8edd000000         jle 0x731977
// 0073189a  8b4c246c             mov ecx, dword ptr [esp + 0x6c]
// 0073189e  8bda                 mov ebx, edx
// 007318a0  2bca                 sub ecx, edx
// 007318a2  895c2474             mov dword ptr [esp + 0x74], ebx
// 007318a6  894c2418             mov dword ptr [esp + 0x18], ecx
// 007318aa  eb0c                 jmp 0x7318b8
// 007318ac  8d642400             lea esp, [esp]
// 007318b0  8b5c2474             mov ebx, dword ptr [esp + 0x74]
// 007318b4  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 007318b8  837c247000           cmp dword ptr [esp + 0x70], 0
// 007318bd  740e                 je 0x7318cd
// 007318bf  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 007318c3  8bc8                 mov ecx, eax
// 007318c5  2bcd                 sub ecx, ebp
// 007318c7  8d4c8efc             lea ecx, [esi + ecx*4 - 4]
// 007318cb  eb02                 jmp 0x7318cf
// 007318cd  03cb                 add ecx, ebx
// 007318cf  837c247800           cmp dword ptr [esp + 0x78], 0
// 007318d4  7406                 je 0x7318dc
// 007318d6  2bc5                 sub eax, ebp
// 007318d8  8d5c82fc             lea ebx, [edx + eax*4 - 4]
// 007318dc  0fb65103             movzx edx, byte ptr [ecx + 3]
// 007318e0  0fb67302             movzx esi, byte ptr [ebx + 2]
// 007318e4  b8ff000000           mov eax, 0xff
// 007318e9  2bc2                 sub eax, edx
// 007318eb  0faff0               imul esi, eax
// 007318ee  b881808080           mov eax, 0x80808081
// 007318f3  f7ee                 imul esi
// 007318f5  03d6                 add edx, esi
// 007318f7  c1fa07               sar edx, 7
// 007318fa  8bc2                 mov eax, edx
// 007318fc  c1e81f               shr eax, 0x1f
// 007318ff  03c2                 add eax, edx
// 00731901  024102               add al, byte ptr [ecx + 2]
// 00731904  8344247404           add dword ptr [esp + 0x74], 4
// 00731909  884701               mov byte ptr [edi + 1], al
// 0073190c  0fb65103             movzx edx, byte ptr [ecx + 3]
// 00731910  0fb67301             movzx esi, byte ptr [ebx + 1]
// 00731914  b8ff000000           mov eax, 0xff
// 00731919  2bc2                 sub eax, edx
// 0073191b  0faff0               imul esi, eax
// 0073191e  b881808080           mov eax, 0x80808081
// 00731923  f7ee                 imul esi
// 00731925  03d6                 add edx, esi
// 00731927  c1fa07               sar edx, 7
// 0073192a  8bc2                 mov eax, edx
// 0073192c  c1e81f               shr eax, 0x1f
// 0073192f  03c2                 add eax, edx
// 00731931  024101               add al, byte ptr [ecx + 1]
// 00731934  beff000000           mov esi, 0xff
// 00731939  8807                 mov byte ptr [edi], al
// 0073193b  0fb65103             movzx edx, byte ptr [ecx + 3]
// 0073193f  0fb603               movzx eax, byte ptr [ebx]
// 00731942  2bf2                 sub esi, edx
// 00731944  0faff0               imul esi, eax
// 00731947  b881808080           mov eax, 0x80808081
// 0073194c  f7ee                 imul esi
// 0073194e  03d6                 add edx, esi
// 00731950  c1fa07               sar edx, 7
// 00731953  8bc2                 mov eax, edx
// 00731955  c1e81f               shr eax, 0x1f
// 00731958  03c2                 add eax, edx
// 0073195a  0201                 add al, byte ptr [ecx]
// 0073195c  8b54247c             mov edx, dword ptr [esp + 0x7c]
// 00731960  8847ff               mov byte ptr [edi - 1], al
// 00731963  8b442424             mov eax, dword ptr [esp + 0x24]
// 00731967  45                   inc ebp
// 00731968  83c704               add edi, 4
// 0073196b  3be8                 cmp ebp, eax
// 0073196d  0f8c3dffffff         jl 0x7318b0
// 00731973  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00731977  8b742414             mov esi, dword ptr [esp + 0x14]
// 0073197b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0073197f  014c246c             add dword ptr [esp + 0x6c], ecx
// 00731983  46                   inc esi
// 00731984  03d1                 add edx, ecx
// 00731986  03f9                 add edi, ecx
// 00731988  3b742428             cmp esi, dword ptr [esp + 0x28]
// 0073198c  8954247c             mov dword ptr [esp + 0x7c], edx
// 00731990  897c2410             mov dword ptr [esp + 0x10], edi
// 00731994  89742414             mov dword ptr [esp + 0x14], esi
// 00731998  0f8cf2feffff         jl 0x731890
// 0073199e  5d                   pop ebp
// 0073199f  5b                   pop ebx
// 007319a0  5f                   pop edi
// 007319a1  b801000000           mov eax, 1
// 007319a6  5e                   pop esi
// 007319a7  83c458               add esp, 0x58
// 007319aa  c21400               ret 0x14
// 007319ad  5f                   pop edi
// 007319ae  33c0                 xor eax, eax
// 007319b0  5e                   pop esi
// 007319b1  83c458               add esp, 0x58
// 007319b4  c21400               ret 0x14
// library xtp-15.2.1/Source\Common\XTPImageManager.cpp (function ?BlendImages@CXTPImageManager@@ABEHPAUHBITMAP__@@H0H0@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPImageManager.cpp
