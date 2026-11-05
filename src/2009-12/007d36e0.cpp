// from server: 100% by auto
// roc 2009-12 007d36e0  unit: seg_007d0000  size: 413 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007d36e0
//
// 007d36e0  83ec0c               sub esp, 0xc
// 007d36e3  53                   push ebx
// 007d36e4  55                   push ebp
// 007d36e5  56                   push esi
// 007d36e6  57                   push edi
// 007d36e7  8bf8                 mov edi, eax
// 007d36e9  8b7730               mov esi, dword ptr [edi + 0x30]
// 007d36ec  b903000000           mov ecx, 3
// 007d36f1  004e32               add byte ptr [esi + 0x32], cl
// 007d36f4  0fb64632             movzx eax, byte ptr [esi + 0x32]
// 007d36f8  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 007d36fb  2bc1                 sub eax, ecx
// 007d36fd  83e901               sub ecx, 1
// 007d3700  0fb78446ac000000     movzx eax, word ptr [esi + eax*2 + 0xac]
// 007d3708  8d1440               lea edx, [eax + eax*2]
// 007d370b  8b06                 mov eax, dword ptr [esi]
// 007d370d  8b4018               mov eax, dword ptr [eax + 0x18]
// 007d3710  895c9004             mov dword ptr [eax + edx*4 + 4], ebx
// 007d3714  75de                 jne 0x7d36f4
// 007d3716  817f1003010000       cmp dword ptr [edi + 0x10], 0x103
// 007d371d  7424                 je 0x7d3743
// 007d371f  6803010000           push 0x103
// 007d3724  57                   push edi
// 007d3725  e8161b0000           call 0x7d5240
// 007d372a  8b4f34               mov ecx, dword ptr [edi + 0x34]
// 007d372d  50                   push eax
// 007d372e  68d0ed9e00           push 0x9eedd0
// 007d3733  51                   push ecx
// 007d3734  e8476efcff           call 0x79a580
// 007d3739  50                   push eax
// 007d373a  57                   push edi
// 007d373b  e8001c0000           call 0x7d5340
// 007d3740  83c41c               add esp, 0x1c
// 007d3743  57                   push edi
// 007d3744  e8e72f0000           call 0x7d6730
// 007d3749  33db                 xor ebx, ebx
// 007d374b  83c404               add esp, 4
// 007d374e  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 007d3752  7417                 je 0x7d376b
// 007d3754  8b542420             mov edx, dword ptr [esp + 0x20]
// 007d3758  68feff0100           push 0x1fffe
// 007d375d  52                   push edx
// 007d375e  6a20                 push 0x20
// 007d3760  56                   push esi
// 007d3761  e8ca8e0000           call 0x7dc630
// 007d3766  83c410               add esp, 0x10
// 007d3769  eb09                 jmp 0x7d3774
// 007d376b  56                   push esi
// 007d376c  e81f900000           call 0x7dc790
// 007d3771  83c404               add esp, 4
// 007d3774  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 007d377c  885c241a             mov byte ptr [esp + 0x1a], bl
// 007d3780  8be8                 mov ebp, eax
// 007d3782  8a4632               mov al, byte ptr [esi + 0x32]
// 007d3785  88442418             mov byte ptr [esp + 0x18], al
// 007d3789  885c2419             mov byte ptr [esp + 0x19], bl
// 007d378d  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 007d3790  8d542410             lea edx, [esp + 0x10]
// 007d3794  894c2410             mov dword ptr [esp + 0x10], ecx
// 007d3798  895614               mov dword ptr [esi + 0x14], edx
// 007d379b  8b542428             mov edx, dword ptr [esp + 0x28]
// 007d379f  8bc7                 mov eax, edi
// 007d37a1  e8cae2ffff           call 0x7d1a70
// 007d37a6  8b442428             mov eax, dword ptr [esp + 0x28]
// 007d37aa  50                   push eax
// 007d37ab  56                   push esi
// 007d37ac  e8af890000           call 0x7dc160
// 007d37b1  83c408               add esp, 8
// 007d37b4  8bc7                 mov eax, edi
// 007d37b6  e805faffff           call 0x7d31c0
// 007d37bb  8b7e14               mov edi, dword ptr [esi + 0x14]
// 007d37be  8b0f                 mov ecx, dword ptr [edi]
// 007d37c0  8b460c               mov eax, dword ptr [esi + 0xc]
// 007d37c3  894e14               mov dword ptr [esi + 0x14], ecx
// 007d37c6  0fb65708             movzx edx, byte ptr [edi + 8]
// 007d37ca  e8e1e2ffff           call 0x7d1ab0
// 007d37cf  385f09               cmp byte ptr [edi + 9], bl
// 007d37d2  7412                 je 0x7d37e6
// 007d37d4  0fb65708             movzx edx, byte ptr [edi + 8]
// 007d37d8  53                   push ebx
// 007d37d9  53                   push ebx
// 007d37da  52                   push edx
// 007d37db  6a23                 push 0x23
// 007d37dd  56                   push esi
// 007d37de  e81d8e0000           call 0x7dc600
// 007d37e3  83c414               add esp, 0x14
// 007d37e6  0fb64632             movzx eax, byte ptr [esi + 0x32]
// 007d37ea  894624               mov dword ptr [esi + 0x24], eax
// 007d37ed  8b4f04               mov ecx, dword ptr [edi + 4]
// 007d37f0  51                   push ecx
// 007d37f1  56                   push esi
// 007d37f2  e869900000           call 0x7dc860
// 007d37f7  55                   push ebp
// 007d37f8  56                   push esi
// 007d37f9  e862900000           call 0x7dc860
// 007d37fe  83c410               add esp, 0x10
// 007d3801  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 007d3805  7417                 je 0x7d381e
// 007d3807  8b542420             mov edx, dword ptr [esp + 0x20]
// 007d380b  68feff0100           push 0x1fffe
// 007d3810  52                   push edx
// 007d3811  6a1f                 push 0x1f
// 007d3813  56                   push esi
// 007d3814  e8178e0000           call 0x7dc630
// 007d3819  83c410               add esp, 0x10
// 007d381c  eb16                 jmp 0x7d3834
// 007d381e  8b442428             mov eax, dword ptr [esp + 0x28]
// 007d3822  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 007d3826  50                   push eax
// 007d3827  53                   push ebx
// 007d3828  51                   push ecx
// 007d3829  6a21                 push 0x21
// 007d382b  56                   push esi
// 007d382c  e8cf8d0000           call 0x7dc600
// 007d3831  83c414               add esp, 0x14
// 007d3834  8b542424             mov edx, dword ptr [esp + 0x24]
// 007d3838  52                   push edx
// 007d3839  56                   push esi
// 007d383a  8bf8                 mov edi, eax
// 007d383c  e8ff8c0000           call 0x7dc540
// 007d3841  83c408               add esp, 8
// 007d3844  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 007d3848  7416                 je 0x7d3860
// 007d384a  45                   inc ebp
// 007d384b  8bc7                 mov eax, edi
// 007d384d  55                   push ebp
// 007d384e  50                   push eax
// 007d384f  56                   push esi
// 007d3850  e8fb9e0000           call 0x7dd750
// 007d3855  83c40c               add esp, 0xc
// 007d3858  5f                   pop edi
// 007d3859  5e                   pop esi
// 007d385a  5d                   pop ebp
// 007d385b  5b                   pop ebx
// 007d385c  83c40c               add esp, 0xc
// 007d385f  c3                   ret 
// 007d3860  56                   push esi
// 007d3861  e82a8f0000           call 0x7dc790
// 007d3866  83c404               add esp, 4
// 007d3869  45                   inc ebp
// 007d386a  55                   push ebp
// 007d386b  50                   push eax
// 007d386c  56                   push esi
// 007d386d  e8de9e0000           call 0x7dd750
// 007d3872  83c40c               add esp, 0xc
// 007d3875  5f                   pop edi
// 007d3876  5e                   pop esi
// 007d3877  5d                   pop ebp
// 007d3878  5b                   pop ebx
// 007d3879  83c40c               add esp, 0xc
// 007d387c  c3                   ret 
// library lua-5.1/lparser.c (function _forbody)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lparser.c
