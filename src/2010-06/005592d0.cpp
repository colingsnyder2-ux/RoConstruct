// from server: 100% by auto
// roc 2010-06 005592d0  unit: G3D::BinaryInput  size: 389 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005592d0
//
// 005592d0  55                   push ebp
// 005592d1  56                   push esi
// 005592d2  8bf1                 mov esi, ecx
// 005592d4  8b460c               mov eax, dword ptr [esi + 0xc]
// 005592d7  57                   push edi
// 005592d8  85c0                 test eax, eax
// 005592da  7504                 jne 0x5592e0
// 005592dc  33ed                 xor ebp, ebp
// 005592de  eb05                 jmp 0x5592e5
// 005592e0  8b6e14               mov ebp, dword ptr [esi + 0x14]
// 005592e3  2be8                 sub ebp, eax
// 005592e5  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 005592e9  85ff                 test edi, edi
// 005592eb  0f845e010000         je 0x55944f
// 005592f1  53                   push ebx
// 005592f2  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 005592f5  8bc8                 mov ecx, eax
// 005592f7  2bcb                 sub ecx, ebx
// 005592f9  49                   dec ecx
// 005592fa  3bcf                 cmp ecx, edi
// 005592fc  7305                 jae 0x559303
// 005592fe  e8edaaecff           call 0x423df0
// 00559303  8bd3                 mov edx, ebx
// 00559305  2bd0                 sub edx, eax
// 00559307  8d043a               lea eax, [edx + edi]
// 0055930a  3be8                 cmp ebp, eax
// 0055930c  0f83a5000000         jae 0x5593b7
// 00559312  8bcd                 mov ecx, ebp
// 00559314  d1e9                 shr ecx, 1
// 00559316  83caff               or edx, 0xffffffff
// 00559319  2bd1                 sub edx, ecx
// 0055931b  3bd5                 cmp edx, ebp
// 0055931d  7304                 jae 0x559323
// 0055931f  33ed                 xor ebp, ebp
// 00559321  eb02                 jmp 0x559325
// 00559323  03e9                 add ebp, ecx
// 00559325  3be8                 cmp ebp, eax
// 00559327  0f42e8               cmovb ebp, eax
// 0055932a  6a00                 push 0
// 0055932c  55                   push ebp
// 0055932d  e8fef9ffff           call 0x558d30
// 00559332  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00559336  8bd8                 mov ebx, eax
// 00559338  8b442420             mov eax, dword ptr [esp + 0x20]
// 0055933c  2b460c               sub eax, dword ptr [esi + 0xc]
// 0055933f  83c408               add esp, 8
// 00559342  51                   push ecx
// 00559343  03c3                 add eax, ebx
// 00559345  57                   push edi
// 00559346  50                   push eax
// 00559347  8bce                 mov ecx, esi
// 00559349  89442428             mov dword ptr [esp + 0x28], eax
// 0055934d  e8eefeffff           call 0x559240
// 00559352  8b542418             mov edx, dword ptr [esp + 0x18]
// 00559356  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 00559359  8bc2                 mov eax, edx
// 0055935b  2bc1                 sub eax, ecx
// 0055935d  7411                 je 0x559370
// 0055935f  50                   push eax
// 00559360  51                   push ecx
// 00559361  50                   push eax
// 00559362  53                   push ebx
// 00559363  ff1580a89e00         call dword ptr [0x9ea880]
// 00559369  8b542428             mov edx, dword ptr [esp + 0x28]
// 0055936d  83c410               add esp, 0x10
// 00559370  8b4610               mov eax, dword ptr [esi + 0x10]
// 00559373  2bc2                 sub eax, edx
// 00559375  7413                 je 0x55938a
// 00559377  50                   push eax
// 00559378  52                   push edx
// 00559379  8b542424             mov edx, dword ptr [esp + 0x24]
// 0055937d  50                   push eax
// 0055937e  03d7                 add edx, edi
// 00559380  52                   push edx
// 00559381  ff1580a89e00         call dword ptr [0x9ea880]
// 00559387  83c410               add esp, 0x10
// 0055938a  8b460c               mov eax, dword ptr [esi + 0xc]
// 0055938d  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 00559390  2bc8                 sub ecx, eax
// 00559392  03f9                 add edi, ecx
// 00559394  85c0                 test eax, eax
// 00559396  7409                 je 0x5593a1
// 00559398  50                   push eax
// 00559399  e8fce52400           call 0x7a799a
// 0055939e  83c404               add esp, 4
// 005593a1  8d142b               lea edx, [ebx + ebp]
// 005593a4  8d043b               lea eax, [ebx + edi]
// 005593a7  895e0c               mov dword ptr [esi + 0xc], ebx
// 005593aa  5b                   pop ebx
// 005593ab  5f                   pop edi
// 005593ac  895614               mov dword ptr [esi + 0x14], edx
// 005593af  894610               mov dword ptr [esi + 0x10], eax
// 005593b2  5e                   pop esi
// 005593b3  5d                   pop ebp
// 005593b4  c21000               ret 0x10
// 005593b7  8b442418             mov eax, dword ptr [esp + 0x18]
// 005593bb  8b542420             mov edx, dword ptr [esp + 0x20]
// 005593bf  8bcb                 mov ecx, ebx
// 005593c1  2bc8                 sub ecx, eax
// 005593c3  3bcf                 cmp ecx, edi
// 005593c5  734e                 jae 0x559415
// 005593c7  8a0a                 mov cl, byte ptr [edx]
// 005593c9  8d1438               lea edx, [eax + edi]
// 005593cc  52                   push edx
// 005593cd  53                   push ebx
// 005593ce  884c2428             mov byte ptr [esp + 0x28], cl
// 005593d2  50                   push eax
// 005593d3  8bce                 mov ecx, esi
// 005593d5  e8a6fcffff           call 0x559080
// 005593da  8b4610               mov eax, dword ptr [esi + 0x10]
// 005593dd  8b542418             mov edx, dword ptr [esp + 0x18]
// 005593e1  8d4c2420             lea ecx, [esp + 0x20]
// 005593e5  51                   push ecx
// 005593e6  2bd0                 sub edx, eax
// 005593e8  03d7                 add edx, edi
// 005593ea  52                   push edx
// 005593eb  50                   push eax
// 005593ec  8bce                 mov ecx, esi
// 005593ee  e84dfeffff           call 0x559240
// 005593f3  017e10               add dword ptr [esi + 0x10], edi
// 005593f6  8b7610               mov esi, dword ptr [esi + 0x10]
// 005593f9  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 005593fd  8d442420             lea eax, [esp + 0x20]
// 00559401  50                   push eax
// 00559402  2bf7                 sub esi, edi
// 00559404  56                   push esi
// 00559405  51                   push ecx
// 00559406  e885fbffff           call 0x558f90
// 0055940b  83c40c               add esp, 0xc
// 0055940e  5b                   pop ebx
// 0055940f  5f                   pop edi
// 00559410  5e                   pop esi
// 00559411  5d                   pop ebp
// 00559412  c21000               ret 0x10
// 00559415  8a02                 mov al, byte ptr [edx]
// 00559417  53                   push ebx
// 00559418  8beb                 mov ebp, ebx
// 0055941a  53                   push ebx
// 0055941b  2bef                 sub ebp, edi
// 0055941d  55                   push ebp
// 0055941e  8bce                 mov ecx, esi
// 00559420  8844242c             mov byte ptr [esp + 0x2c], al
// 00559424  e857fcffff           call 0x559080
// 00559429  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0055942d  53                   push ebx
// 0055942e  55                   push ebp
// 0055942f  51                   push ecx
// 00559430  894610               mov dword ptr [esi + 0x10], eax
// 00559433  e878fbffff           call 0x558fb0
// 00559438  8b442424             mov eax, dword ptr [esp + 0x24]
// 0055943c  8d54242c             lea edx, [esp + 0x2c]
// 00559440  52                   push edx
// 00559441  8d0c38               lea ecx, [eax + edi]
// 00559444  51                   push ecx
// 00559445  50                   push eax
// 00559446  e845fbffff           call 0x558f90
// 0055944b  83c418               add esp, 0x18
// 0055944e  5b                   pop ebx
// 0055944f  5f                   pop edi
// 00559450  5e                   pop esi
// 00559451  5d                   pop ebp
// 00559452  c21000               ret 0x10
// library rbx2016-g3d/BinaryInput.cpp (function ?_Insert_n@?$vector@EV?$allocator@E@std@@@std@@IAEXV?$_Vector_const_iterator@EV?$allocator@E@std@@@2@IABE@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d BinaryInput.cpp
