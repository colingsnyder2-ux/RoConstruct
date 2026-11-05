// from server: 100% by auto
// roc 2009-06 004470d0  unit: CBrowserDocManager  size: 775 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004470d0
//
// 004470d0  55                   push ebp
// 004470d1  8d6c2494             lea ebp, [esp - 0x6c]
// 004470d5  81ec24010000         sub esp, 0x124
// 004470db  53                   push ebx
// 004470dc  8b5d78               mov ebx, dword ptr [ebp + 0x78]
// 004470df  56                   push esi
// 004470e0  57                   push edi
// 004470e1  c7456800000000       mov dword ptr [ebp + 0x68], 0
// 004470e8  85db                 test ebx, ebx
// 004470ea  0f84d3020000         je 0x4473c3
// 004470f0  8b7d74               mov edi, dword ptr [ebp + 0x74]
// 004470f3  8b07                 mov eax, dword ptr [edi]
// 004470f5  3b0580128f00         cmp eax, dword ptr [0x8f1280]
// 004470fb  7525                 jne 0x447122
// 004470fd  8b4f04               mov ecx, dword ptr [edi + 4]
// 00447100  3b0d84128f00         cmp ecx, dword ptr [0x8f1284]
// 00447106  751a                 jne 0x447122
// 00447108  8b5708               mov edx, dword ptr [edi + 8]
// 0044710b  3b1588128f00         cmp edx, dword ptr [0x8f1288]
// 00447111  750f                 jne 0x447122
// 00447113  8b470c               mov eax, dword ptr [edi + 0xc]
// 00447116  3b058c128f00         cmp eax, dword ptr [0x8f128c]
// 0044711c  0f84a1020000         je 0x4473c3
// 00447122  8d4d68               lea ecx, [ebp + 0x68]
// 00447125  51                   push ecx
// 00447126  689c718b00           push 0x8b719c
// 0044712b  6a01                 push 1
// 0044712d  6a00                 push 0
// 0044712f  6850128f00           push 0x8f1250
// 00447134  ff1500038a00         call dword ptr [0x8a0300]
// 0044713a  85c0                 test eax, eax
// 0044713c  7d27                 jge 0x447165
// 0044713e  8b4568               mov eax, dword ptr [ebp + 0x68]
// 00447141  85c0                 test eax, eax
// 00447143  0f847a020000         je 0x4473c3
// 00447149  8b10                 mov edx, dword ptr [eax]
// 0044714b  50                   push eax
// 0044714c  8b4208               mov eax, dword ptr [edx + 8]
// 0044714f  ffd0                 call eax
// 00447151  33c0                 xor eax, eax
// 00447153  8da53cffffff         lea esp, [ebp - 0xc4]
// 00447159  5f                   pop edi
// 0044715a  5e                   pop esi
// 0044715b  5b                   pop ebx
// 0044715c  83c56c               add ebp, 0x6c
// 0044715f  8be5                 mov esp, ebp
// 00447161  5d                   pop ebp
// 00447162  c20c00               ret 0xc
// 00447165  833b00               cmp dword ptr [ebx], 0
// 00447168  747c                 je 0x4471e6
// 0044716a  837d7c00             cmp dword ptr [ebp + 0x7c], 0
// 0044716e  8b4304               mov eax, dword ptr [ebx + 4]
// 00447171  8b08                 mov ecx, dword ptr [eax]
// 00447173  894d48               mov dword ptr [ebp + 0x48], ecx
// 00447176  8b5004               mov edx, dword ptr [eax + 4]
// 00447179  89554c               mov dword ptr [ebp + 0x4c], edx
// 0044717c  8b4808               mov ecx, dword ptr [eax + 8]
// 0044717f  894d50               mov dword ptr [ebp + 0x50], ecx
// 00447182  8b500c               mov edx, dword ptr [eax + 0xc]
// 00447185  8b4568               mov eax, dword ptr [ebp + 0x68]
// 00447188  895554               mov dword ptr [ebp + 0x54], edx
// 0044718b  8b08                 mov ecx, dword ptr [eax]
// 0044718d  8d5548               lea edx, [ebp + 0x48]
// 00447190  52                   push edx
// 00447191  6a01                 push 1
// 00447193  57                   push edi
// 00447194  50                   push eax
// 00447195  7438                 je 0x4471cf
// 00447197  833b01               cmp dword ptr [ebx], 1
// 0044719a  7505                 jne 0x4471a1
// 0044719c  8b4114               mov eax, dword ptr [ecx + 0x14]
// 0044719f  eb03                 jmp 0x4471a4
// 004471a1  8b411c               mov eax, dword ptr [ecx + 0x1c]
// 004471a4  ffd0                 call eax
// 004471a6  8bf0                 mov esi, eax
// 004471a8  85f6                 test esi, esi
// 004471aa  7d32                 jge 0x4471de
// 004471ac  8b4568               mov eax, dword ptr [ebp + 0x68]
// 004471af  85c0                 test eax, eax
// 004471b1  7408                 je 0x4471bb
// 004471b3  8b08                 mov ecx, dword ptr [eax]
// 004471b5  8b5108               mov edx, dword ptr [ecx + 8]
// 004471b8  50                   push eax
// 004471b9  ffd2                 call edx
// 004471bb  8bc6                 mov eax, esi
// 004471bd  8da53cffffff         lea esp, [ebp - 0xc4]
// 004471c3  5f                   pop edi
// 004471c4  5e                   pop esi
// 004471c5  5b                   pop ebx
// 004471c6  83c56c               add ebp, 0x6c
// 004471c9  8be5                 mov esp, ebp
// 004471cb  5d                   pop ebp
// 004471cc  c20c00               ret 0xc
// 004471cf  833b01               cmp dword ptr [ebx], 1
// 004471d2  7505                 jne 0x4471d9
// 004471d4  8b4118               mov eax, dword ptr [ecx + 0x18]
// 004471d7  eb03                 jmp 0x4471dc
// 004471d9  8b4120               mov eax, dword ptr [ecx + 0x20]
// 004471dc  ffd0                 call eax
// 004471de  83c308               add ebx, 8
// 004471e1  833b00               cmp dword ptr [ebx], 0
// 004471e4  7584                 jne 0x44716a
// 004471e6  837d7c00             cmp dword ptr [ebp + 0x7c], 0
// 004471ea  0f85c4010000         jne 0x4473b4
// 004471f0  6a40                 push 0x40
// 004471f2  8d8548ffffff         lea eax, [ebp - 0xb8]
// 004471f8  50                   push eax
// 004471f9  57                   push edi
// 004471fa  ff15f0028a00         call dword ptr [0x8a02f0]
// 00447200  8d8d48ffffff         lea ecx, [ebp - 0xb8]
// 00447206  51                   push ecx
// 00447207  c7457800000000       mov dword ptr [ebp + 0x78], 0
// 0044720e  ff1500e28900         call dword ptr [0x89e200]
// 00447214  40                   inc eax
// 00447215  6a02                 push 2
// 00447217  50                   push eax
// 00447218  8d557c               lea edx, [ebp + 0x7c]
// 0044721b  52                   push edx
// 0044721c  89457c               mov dword ptr [ebp + 0x7c], eax
// 0044721f  e88cbbfbff           call 0x402db0
// 00447224  83c40c               add esp, 0xc
// 00447227  85c0                 test eax, eax
// 00447229  0f8c7d010000         jl 0x4473ac
// 0044722f  8b757c               mov esi, dword ptr [ebp + 0x7c]
// 00447232  81fe00040000         cmp esi, 0x400
// 00447238  7f18                 jg 0x447252
// 0044723a  56                   push esi
// 0044723b  e8f0cbfbff           call 0x403e30
// 00447240  83c404               add esp, 4
// 00447243  84c0                 test al, al
// 00447245  740b                 je 0x447252
// 00447247  8bc6                 mov eax, esi
// 00447249  e8c2292d00           call 0x719c10
// 0044724e  8bc4                 mov eax, esp
// 00447250  eb09                 jmp 0x44725b
// 00447252  56                   push esi
// 00447253  8d4d78               lea ecx, [ebp + 0x78]
// 00447256  e875d1fbff           call 0x4043d0
// 0044725b  6a03                 push 3
// 0044725d  56                   push esi
// 0044725e  8d8d48ffffff         lea ecx, [ebp - 0xb8]
// 00447264  51                   push ecx
// 00447265  50                   push eax
// 00447266  e8d5bbfbff           call 0x402e40
// 0044726b  8bf0                 mov esi, eax
// 0044726d  85f6                 test esi, esi
// 0044726f  0f8437010000         je 0x4473ac
// 00447275  6894718b00           push 0x8b7194
// 0044727a  8d55c8               lea edx, [ebp - 0x38]
// 0044727d  6880000000           push 0x80
// 00447282  52                   push edx
// 00447283  e808d9ffff           call 0x444b90
// 00447288  56                   push esi
// 00447289  8d45c8               lea eax, [ebp - 0x38]
// 0044728c  6880000000           push 0x80
// 00447291  50                   push eax
// 00447292  e819d9ffff           call 0x444bb0
// 00447297  687c718b00           push 0x8b717c
// 0044729c  8d4dc8               lea ecx, [ebp - 0x38]
// 0044729f  6880000000           push 0x80
// 004472a4  51                   push ecx
// 004472a5  e806d9ffff           call 0x444bb0
// 004472aa  83c424               add esp, 0x24
// 004472ad  6819000200           push 0x20019
// 004472b2  8d55c8               lea edx, [ebp - 0x38]
// 004472b5  33ff                 xor edi, edi
// 004472b7  52                   push edx
// 004472b8  6800000080           push 0x80000000
// 004472bd  8d4d60               lea ecx, [ebp + 0x60]
// 004472c0  c7455800000080       mov dword ptr [ebp + 0x58], 0x80000000
// 004472c7  897d5c               mov dword ptr [ebp + 0x5c], edi
// 004472ca  897d60               mov dword ptr [ebp + 0x60], edi
// 004472cd  897d64               mov dword ptr [ebp + 0x64], edi
// 004472d0  897d7c               mov dword ptr [ebp + 0x7c], edi
// 004472d3  e8c8befbff           call 0x4031a0
// 004472d8  85c0                 test eax, eax
// 004472da  7537                 jne 0x447313
// 004472dc  8b4d60               mov ecx, dword ptr [ebp + 0x60]
// 004472df  57                   push edi
// 004472e0  57                   push edi
// 004472e1  57                   push edi
// 004472e2  57                   push edi
// 004472e3  57                   push edi
// 004472e4  57                   push edi
// 004472e5  57                   push edi
// 004472e6  8d457c               lea eax, [ebp + 0x7c]
// 004472e9  50                   push eax
// 004472ea  57                   push edi
// 004472eb  57                   push edi
// 004472ec  57                   push edi
// 004472ed  51                   push ecx
// 004472ee  ff1518e08900         call dword ptr [0x89e018]
// 004472f4  8d4d60               lea ecx, [ebp + 0x60]
// 004472f7  8bd8                 mov ebx, eax
// 004472f9  e872befbff           call 0x403170
// 004472fe  3bdf                 cmp ebx, edi
// 00447300  7511                 jne 0x447313
// 00447302  397d7c               cmp dword ptr [ebp + 0x7c], edi
// 00447305  750c                 jne 0x447313
// 00447307  8d55c8               lea edx, [ebp - 0x38]
// 0044730a  52                   push edx
// 0044730b  8d4d58               lea ecx, [ebp + 0x58]
// 0044730e  e8fdbdfbff           call 0x403110
// 00447313  6894718b00           push 0x8b7194
// 00447318  8d45c8               lea eax, [ebp - 0x38]
// 0044731b  6880000000           push 0x80
// 00447320  50                   push eax
// 00447321  e86ad8ffff           call 0x444b90
// 00447326  56                   push esi
// 00447327  8d4dc8               lea ecx, [ebp - 0x38]
// 0044732a  6880000000           push 0x80
// 0044732f  51                   push ecx
// 00447330  e87bd8ffff           call 0x444bb0
// 00447335  6864718b00           push 0x8b7164
// 0044733a  8d55c8               lea edx, [ebp - 0x38]
// 0044733d  6880000000           push 0x80
// 00447342  52                   push edx
// 00447343  e868d8ffff           call 0x444bb0
// 00447348  83c424               add esp, 0x24
// 0044734b  6819000200           push 0x20019
// 00447350  8d45c8               lea eax, [ebp - 0x38]
// 00447353  50                   push eax
// 00447354  6800000080           push 0x80000000
// 00447359  8d4d60               lea ecx, [ebp + 0x60]
// 0044735c  e83fbefbff           call 0x4031a0
// 00447361  85c0                 test eax, eax
// 00447363  7537                 jne 0x44739c
// 00447365  8b5560               mov edx, dword ptr [ebp + 0x60]
// 00447368  57                   push edi
// 00447369  57                   push edi
// 0044736a  57                   push edi
// 0044736b  57                   push edi
// 0044736c  57                   push edi
// 0044736d  57                   push edi
// 0044736e  57                   push edi
// 0044736f  8d4d7c               lea ecx, [ebp + 0x7c]
// 00447372  51                   push ecx
// 00447373  57                   push edi
// 00447374  57                   push edi
// 00447375  57                   push edi
// 00447376  52                   push edx
// 00447377  ff1518e08900         call dword ptr [0x89e018]
// 0044737d  8d4d60               lea ecx, [ebp + 0x60]
// 00447380  8bf0                 mov esi, eax
// 00447382  e8e9bdfbff           call 0x403170
// 00447387  3bf7                 cmp esi, edi
// 00447389  7511                 jne 0x44739c
// 0044738b  397d7c               cmp dword ptr [ebp + 0x7c], edi
// 0044738e  750c                 jne 0x44739c
// 00447390  8d45c8               lea eax, [ebp - 0x38]
// 00447393  50                   push eax
// 00447394  8d4d58               lea ecx, [ebp + 0x58]
// 00447397  e874bdfbff           call 0x403110
// 0044739c  8d4d60               lea ecx, [ebp + 0x60]
// 0044739f  e83ccdfbff           call 0x4040e0
// 004473a4  8d4d58               lea ecx, [ebp + 0x58]
// 004473a7  e834cdfbff           call 0x4040e0
// 004473ac  8d4d78               lea ecx, [ebp + 0x78]
// 004473af  e8fcc7fbff           call 0x403bb0
// 004473b4  8b4568               mov eax, dword ptr [ebp + 0x68]
// 004473b7  85c0                 test eax, eax
// 004473b9  7408                 je 0x4473c3
// 004473bb  8b08                 mov ecx, dword ptr [eax]
// 004473bd  8b5108               mov edx, dword ptr [ecx + 8]
// 004473c0  50                   push eax
// 004473c1  ffd2                 call edx
// 004473c3  33c0                 xor eax, eax
// 004473c5  8da53cffffff         lea esp, [ebp - 0xc4]
// 004473cb  5f                   pop edi
// 004473cc  5e                   pop esi
// 004473cd  5b                   pop ebx
// 004473ce  83c56c               add ebp, 0x6c
// 004473d1  8be5                 mov esp, ebp
// 004473d3  5d                   pop ebp
// 004473d4  c20c00               ret 0xc
// library atl-9.0/atl.cpp (function _AtlRegisterClassCategoriesHelper@12)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
