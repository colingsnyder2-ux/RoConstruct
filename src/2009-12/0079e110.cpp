// from server: 100% by auto
// roc 2009-12 0079e110  unit: seg_00790000  size: 398 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0079e110
//
// 0079e110  81ec2c030000         sub esp, 0x32c
// 0079e116  53                   push ebx
// 0079e117  8b9c2434030000       mov ebx, dword ptr [esp + 0x334]
// 0079e11e  55                   push ebp
// 0079e11f  56                   push esi
// 0079e120  57                   push edi
// 0079e121  8d44241c             lea eax, [esp + 0x1c]
// 0079e125  50                   push eax
// 0079e126  6a01                 push 1
// 0079e128  53                   push ebx
// 0079e129  e842c6feff           call 0x78a770
// 0079e12e  6a00                 push 0
// 0079e130  6a02                 push 2
// 0079e132  53                   push ebx
// 0079e133  8bf0                 mov esi, eax
// 0079e135  e836c6feff           call 0x78a770
// 0079e13a  6a03                 push 3
// 0079e13c  53                   push ebx
// 0079e13d  8be8                 mov ebp, eax
// 0079e13f  e84ca8feff           call 0x788990
// 0079e144  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 0079e148  41                   inc ecx
// 0079e149  51                   push ecx
// 0079e14a  6a04                 push 4
// 0079e14c  53                   push ebx
// 0079e14d  8bf8                 mov edi, eax
// 0079e14f  e8ccc7feff           call 0x78a920
// 0079e154  83c42c               add esp, 0x2c
// 0079e157  807d005e             cmp byte ptr [ebp], 0x5e
// 0079e15b  89442418             mov dword ptr [esp + 0x18], eax
// 0079e15f  750b                 jne 0x79e16c
// 0079e161  45                   inc ebp
// 0079e162  c744241401000000     mov dword ptr [esp + 0x14], 1
// 0079e16a  eb08                 jmp 0x79e174
// 0079e16c  c744241400000000     mov dword ptr [esp + 0x14], 0
// 0079e174  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0079e17c  83ff03               cmp edi, 3
// 0079e17f  741f                 je 0x79e1a0
// 0079e181  83ff04               cmp edi, 4
// 0079e184  741a                 je 0x79e1a0
// 0079e186  83ff06               cmp edi, 6
// 0079e189  7415                 je 0x79e1a0
// 0079e18b  83ff05               cmp edi, 5
// 0079e18e  7410                 je 0x79e1a0
// 0079e190  68ecb19e00           push 0x9eb1ec
// 0079e195  6a03                 push 3
// 0079e197  53                   push ebx
// 0079e198  e8e3c3feff           call 0x78a580
// 0079e19d  83c40c               add esp, 0xc
// 0079e1a0  8d942430010000       lea edx, [esp + 0x130]
// 0079e1a7  52                   push edx
// 0079e1a8  53                   push ebx
// 0079e1a9  e882bffeff           call 0x78a130
// 0079e1ae  8b442424             mov eax, dword ptr [esp + 0x24]
// 0079e1b2  03c6                 add eax, esi
// 0079e1b4  83c408               add esp, 8
// 0079e1b7  837c241800           cmp dword ptr [esp + 0x18], 0
// 0079e1bc  895c2428             mov dword ptr [esp + 0x28], ebx
// 0079e1c0  89742420             mov dword ptr [esp + 0x20], esi
// 0079e1c4  89442424             mov dword ptr [esp + 0x24], eax
// 0079e1c8  0f8e94000000         jle 0x79e262
// 0079e1ce  8bff                 mov edi, edi
// 0079e1d0  55                   push ebp
// 0079e1d1  8d4c2424             lea ecx, [esp + 0x24]
// 0079e1d5  56                   push esi
// 0079e1d6  51                   push ecx
// 0079e1d7  c744243800000000     mov dword ptr [esp + 0x38], 0
// 0079e1df  e85cf5ffff           call 0x79d740
// 0079e1e4  8bf8                 mov edi, eax
// 0079e1e6  83c40c               add esp, 0xc
// 0079e1e9  85ff                 test edi, edi
// 0079e1eb  7421                 je 0x79e20e
// 0079e1ed  ff442410             inc dword ptr [esp + 0x10]
// 0079e1f1  8d942430010000       lea edx, [esp + 0x130]
// 0079e1f8  56                   push esi
// 0079e1f9  52                   push edx
// 0079e1fa  8d4c2428             lea ecx, [esp + 0x28]
// 0079e1fe  e80dfeffff           call 0x79e010
// 0079e203  83c408               add esp, 8
// 0079e206  3bfe                 cmp edi, esi
// 0079e208  7604                 jbe 0x79e20e
// 0079e20a  8bf7                 mov esi, edi
// 0079e20c  eb3b                 jmp 0x79e249
// 0079e20e  8b442424             mov eax, dword ptr [esp + 0x24]
// 0079e212  3bf0                 cmp esi, eax
// 0079e214  734c                 jae 0x79e262
// 0079e216  8d84243c030000       lea eax, [esp + 0x33c]
// 0079e21d  39842430010000       cmp dword ptr [esp + 0x130], eax
// 0079e224  7210                 jb 0x79e236
// 0079e226  8d8c2430010000       lea ecx, [esp + 0x130]
// 0079e22d  51                   push ecx
// 0079e22e  e89dbdfeff           call 0x789fd0
// 0079e233  83c404               add esp, 4
// 0079e236  8a16                 mov dl, byte ptr [esi]
// 0079e238  8b842430010000       mov eax, dword ptr [esp + 0x130]
// 0079e23f  8810                 mov byte ptr [eax], dl
// 0079e241  ff842430010000       inc dword ptr [esp + 0x130]
// 0079e248  46                   inc esi
// 0079e249  837c241400           cmp dword ptr [esp + 0x14], 0
// 0079e24e  750e                 jne 0x79e25e
// 0079e250  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0079e254  394c2410             cmp dword ptr [esp + 0x10], ecx
// 0079e258  0f8c72ffffff         jl 0x79e1d0
// 0079e25e  8b442424             mov eax, dword ptr [esp + 0x24]
// 0079e262  2bc6                 sub eax, esi
// 0079e264  50                   push eax
// 0079e265  8d942434010000       lea edx, [esp + 0x134]
// 0079e26c  56                   push esi
// 0079e26d  52                   push edx
// 0079e26e  e89dbdfeff           call 0x78a010
// 0079e273  8d84243c010000       lea eax, [esp + 0x13c]
// 0079e27a  50                   push eax
// 0079e27b  e8f0bdfeff           call 0x78a070
// 0079e280  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0079e284  51                   push ecx
// 0079e285  53                   push ebx
// 0079e286  e8f5aafeff           call 0x788d80
// 0079e28b  83c418               add esp, 0x18
// 0079e28e  5f                   pop edi
// 0079e28f  5e                   pop esi
// 0079e290  5d                   pop ebp
// 0079e291  b802000000           mov eax, 2
// 0079e296  5b                   pop ebx
// 0079e297  81c42c030000         add esp, 0x32c
// 0079e29d  c3                   ret 
// library lua-5.1.3/lstrlib.c (function _str_gsub)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.3 lstrlib.c
