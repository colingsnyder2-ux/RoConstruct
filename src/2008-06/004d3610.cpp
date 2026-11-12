// from server: 100% by auto
// roc 2008-06 004d3610  unit: seg_004d0000  size: 1314 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004d3610
//
// 004d3610  83ec18               sub esp, 0x18
// 004d3613  53                   push ebx
// 004d3614  8b5c2430             mov ebx, dword ptr [esp + 0x30]
// 004d3618  55                   push ebp
// 004d3619  8b6c2438             mov ebp, dword ptr [esp + 0x38]
// 004d361d  56                   push esi
// 004d361e  8bf1                 mov esi, ecx
// 004d3620  8b86d4040000         mov eax, dword ptr [esi + 0x4d4]
// 004d3626  3be8                 cmp ebp, eax
// 004d3628  8b8ed0040000         mov ecx, dword ptr [esi + 0x4d0]
// 004d362e  7f1b                 jg 0x4d364b
// 004d3630  7c04                 jl 0x4d3636
// 004d3632  3bd9                 cmp ebx, ecx
// 004d3634  7715                 ja 0x4d364b
// 004d3636  899ed0040000         mov dword ptr [esi + 0x4d0], ebx
// 004d363c  89aed4040000         mov dword ptr [esi + 0x4d4], ebp
// 004d3642  5e                   pop esi
// 004d3643  5d                   pop ebp
// 004d3644  5b                   pop ebx
// 004d3645  83c418               add esp, 0x18
// 004d3648  c22000               ret 0x20
// 004d364b  57                   push edi
// 004d364c  8bfb                 mov edi, ebx
// 004d364e  2bf9                 sub edi, ecx
// 004d3650  8bd5                 mov edx, ebp
// 004d3652  1bd0                 sbb edx, eax
// 004d3654  80be8c07000000       cmp byte ptr [esi + 0x78c], 0
// 004d365b  89542424             mov dword ptr [esp + 0x24], edx
// 004d365f  899ed0040000         mov dword ptr [esi + 0x4d0], ebx
// 004d3665  89aed4040000         mov dword ptr [esi + 0x4d4], ebp
// 004d366b  7407                 je 0x4d3674
// 004d366d  c6868c07000000       mov byte ptr [esi + 0x78c], 0
// 004d3674  837e4c00             cmp dword ptr [esi + 0x4c], 0
// 004d3678  7422                 je 0x4d369c
// 004d367a  55                   push ebp
// 004d367b  53                   push ebx
// 004d367c  8bce                 mov ecx, esi
// 004d367e  e8edb5ffff           call 0x4cec70
// 004d3683  84c0                 test al, al
// 004d3685  7411                 je 0x4d3698
// 004d3687  5f                   pop edi
// 004d3688  c686d403000001       mov byte ptr [esi + 0x3d4], 1
// 004d368f  5e                   pop esi
// 004d3690  5d                   pop ebp
// 004d3691  5b                   pop ebx
// 004d3692  83c418               add esp, 0x18
// 004d3695  c22000               ret 0x20
// 004d3698  8b542424             mov edx, dword ptr [esp + 0x24]
// 004d369c  8b8ea8040000         mov ecx, dword ptr [esi + 0x4a8]
// 004d36a2  8b86ac040000         mov eax, dword ptr [esi + 0x4ac]
// 004d36a8  81c180969800         add ecx, 0x989680
// 004d36ae  83d000               adc eax, 0
// 004d36b1  3be8                 cmp ebp, eax
// 004d36b3  0f8c80000000         jl 0x4d3739
// 004d36b9  7f04                 jg 0x4d36bf
// 004d36bb  3bd9                 cmp ebx, ecx
// 004d36bd  727a                 jb 0x4d3739
// 004d36bf  8b86f0040000         mov eax, dword ptr [esi + 0x4f0]
// 004d36c5  8b8ef4040000         mov ecx, dword ptr [esi + 0x4f4]
// 004d36cb  8bd0                 mov edx, eax
// 004d36cd  0bd1                 or edx, ecx
// 004d36cf  899ea8040000         mov dword ptr [esi + 0x4a8], ebx
// 004d36d5  89aeac040000         mov dword ptr [esi + 0x4ac], ebp
// 004d36db  c786b004000000000000 mov dword ptr [esi + 0x4b0], 0
// 004d36e5  7417                 je 0x4d36fe
// 004d36e7  51                   push ecx
// 004d36e8  8b8ee8040000         mov ecx, dword ptr [esi + 0x4e8]
// 004d36ee  50                   push eax
// 004d36ef  8b86ec040000         mov eax, dword ptr [esi + 0x4ec]
// 004d36f5  50                   push eax
// 004d36f6  51                   push ecx
// 004d36f7  e834e51c00           call 0x6a1c30
// 004d36fc  eb0c                 jmp 0x4d370a
// 004d36fe  8b86f8040000         mov eax, dword ptr [esi + 0x4f8]
// 004d3704  8b96fc040000         mov edx, dword ptr [esi + 0x4fc]
// 004d370a  6a00                 push 0
// 004d370c  6a64                 push 0x64
// 004d370e  52                   push edx
// 004d370f  50                   push eax
// 004d3710  e8bbdf1c00           call 0x6a16d0
// 004d3715  8996ec040000         mov dword ptr [esi + 0x4ec], edx
// 004d371b  8b542424             mov edx, dword ptr [esp + 0x24]
// 004d371f  8986e8040000         mov dword ptr [esi + 0x4e8], eax
// 004d3725  c786f004000064000000 mov dword ptr [esi + 0x4f0], 0x64
// 004d372f  c786f404000000000000 mov dword ptr [esi + 0x4f4], 0
// 004d3739  837c244400           cmp dword ptr [esp + 0x44], 0
// 004d373e  744a                 je 0x4d378a
// 004d3740  8b8624050000         mov eax, dword ptr [esi + 0x524]
// 004d3746  8b8e20050000         mov ecx, dword ptr [esi + 0x520]
// 004d374c  85c0                 test eax, eax
// 004d374e  7c3a                 jl 0x4d378a
// 004d3750  7f04                 jg 0x4d3756
// 004d3752  85c9                 test ecx, ecx
// 004d3754  7634                 jbe 0x4d378a
// 004d3756  2bcf                 sub ecx, edi
// 004d3758  1bc2                 sbb eax, edx
// 004d375a  898624050000         mov dword ptr [esi + 0x524], eax
// 004d3760  33c0                 xor eax, eax
// 004d3762  398624050000         cmp dword ptr [esi + 0x524], eax
// 004d3768  898e20050000         mov dword ptr [esi + 0x520], ecx
// 004d376e  0f8f04010000         jg 0x4d3878
// 004d3774  7c08                 jl 0x4d377e
// 004d3776  3bc8                 cmp ecx, eax
// 004d3778  0f83fa000000         jae 0x4d3878
// 004d377e  898620050000         mov dword ptr [esi + 0x520], eax
// 004d3784  898624050000         mov dword ptr [esi + 0x524], eax
// 004d378a  8b86e4040000         mov eax, dword ptr [esi + 0x4e4]
// 004d3790  3be8                 cmp ebp, eax
// 004d3792  8b8ee0040000         mov ecx, dword ptr [esi + 0x4e0]
// 004d3798  0f8c2a020000         jl 0x4d39c8
// 004d379e  7f08                 jg 0x4d37a8
// 004d37a0  3bd9                 cmp ebx, ecx
// 004d37a2  0f8220020000         jb 0x4d39c8
// 004d37a8  33d2                 xor edx, edx
// 004d37aa  52                   push edx
// 004d37ab  8bfb                 mov edi, ebx
// 004d37ad  2bf9                 sub edi, ecx
// 004d37af  8954241c             mov dword ptr [esp + 0x1c], edx
// 004d37b3  89542420             mov dword ptr [esp + 0x20], edx
// 004d37b7  8b96dc040000         mov edx, dword ptr [esi + 0x4dc]
// 004d37bd  6a64                 push 0x64
// 004d37bf  8bdd                 mov ebx, ebp
// 004d37c1  1bd8                 sbb ebx, eax
// 004d37c3  8b86d8040000         mov eax, dword ptr [esi + 0x4d8]
// 004d37c9  52                   push edx
// 004d37ca  50                   push eax
// 004d37cb  897c2430             mov dword ptr [esp + 0x30], edi
// 004d37cf  e8fcde1c00           call 0x6a16d0
// 004d37d4  3bda                 cmp ebx, edx
// 004d37d6  7c1e                 jl 0x4d37f6
// 004d37d8  7f04                 jg 0x4d37de
// 004d37da  3bf8                 cmp edi, eax
// 004d37dc  7618                 jbe 0x4d37f6
// 004d37de  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 004d37e2  89442420             mov dword ptr [esp + 0x20], eax
// 004d37e6  8bda                 mov ebx, edx
// 004d37e8  898ee0040000         mov dword ptr [esi + 0x4e0], ecx
// 004d37ee  89aee4040000         mov dword ptr [esi + 0x4e4], ebp
// 004d37f4  8bf8                 mov edi, eax
// 004d37f6  85db                 test ebx, ebx
// 004d37f8  0f8c8c010000         jl 0x4d398a
// 004d37fe  7f08                 jg 0x4d3808
// 004d3800  85ff                 test edi, edi
// 004d3802  0f8682010000         jbe 0x4d398a
// 004d3808  8daec0000000         lea ebp, [esi + 0xc0]
// 004d380e  8bff                 mov edi, edi
// 004d3810  8bcd                 mov ecx, ebp
// 004d3812  e8a919fdff           call 0x4a51c0
// 004d3817  8b542448             mov edx, dword ptr [esp + 0x48]
// 004d381b  8b442434             mov eax, dword ptr [esp + 0x34]
// 004d381f  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 004d3823  52                   push edx
// 004d3824  8b542444             mov edx, dword ptr [esp + 0x44]
// 004d3828  50                   push eax
// 004d3829  8b442444             mov eax, dword ptr [esp + 0x44]
// 004d382d  51                   push ecx
// 004d382e  52                   push edx
// 004d382f  8b542448             mov edx, dword ptr [esp + 0x48]
// 004d3833  50                   push eax
// 004d3834  8d4c2427             lea ecx, [esp + 0x27]
// 004d3838  51                   push ecx
// 004d3839  52                   push edx
// 004d383a  55                   push ebp
// 004d383b  8bce                 mov ecx, esi
// 004d383d  e8aee1ffff           call 0x4d19f0
// 004d3842  84c0                 test al, al
// 004d3844  0f843c010000         je 0x4d3986
// 004d384a  83bea807000000       cmp dword ptr [esi + 0x7a8], 0
// 004d3851  7731                 ja 0x4d3884
// 004d3853  83beac07000000       cmp dword ptr [esi + 0x7ac], 0
// 004d385a  7728                 ja 0x4d3884
// 004d385c  8b442434             mov eax, dword ptr [esp + 0x34]
// 004d3860  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 004d3864  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 004d3868  55                   push ebp
// 004d3869  50                   push eax
// 004d386a  51                   push ecx
// 004d386b  52                   push edx
// 004d386c  8bce                 mov ecx, esi
// 004d386e  e8edb2ffff           call 0x4ceb60
// 004d3873  e995000000           jmp 0x4d390d
// 004d3878  c6860405000000       mov byte ptr [esi + 0x504], 0
// 004d387f  e9e3010000           jmp 0x4d3a67
// 004d3884  68e0050000           push 0x5e0
// 004d3889  e892d01c00           call 0x6a0920
// 004d388e  8b8ecc000000         mov ecx, dword ptr [esi + 0xcc]
// 004d3894  8bf8                 mov edi, eax
// 004d3896  8b4500               mov eax, dword ptr [ebp]
// 004d3899  83c007               add eax, 7
// 004d389c  c1f803               sar eax, 3
// 004d389f  50                   push eax
// 004d38a0  51                   push ecx
// 004d38a1  57                   push edi
// 004d38a2  e839df1c00           call 0x6a17e0
// 004d38a7  8b5500               mov edx, dword ptr [ebp]
// 004d38aa  83c207               add edx, 7
// 004d38ad  c1fa03               sar edx, 3
// 004d38b0  8997d4050000         mov dword ptr [edi + 0x5d4], edx
// 004d38b6  8b86a8070000         mov eax, dword ptr [esi + 0x7a8]
// 004d38bc  b9e8030000           mov ecx, 0x3e8
// 004d38c1  f7e1                 mul ecx
// 004d38c3  83c410               add esp, 0x10
// 004d38c6  0344243c             add eax, dword ptr [esp + 0x3c]
// 004d38ca  13542440             adc edx, dword ptr [esp + 0x40]
// 004d38ce  8987d8050000         mov dword ptr [edi + 0x5d8], eax
// 004d38d4  8997dc050000         mov dword ptr [edi + 0x5dc], edx
// 004d38da  83beac07000000       cmp dword ptr [esi + 0x7ac], 0
// 004d38e1  761a                 jbe 0x4d38fd
// 004d38e3  e838080000           call 0x4d4120
// 004d38e8  33d2                 xor edx, edx
// 004d38ea  f7b6ac070000         div dword ptr [esi + 0x7ac]
// 004d38f0  0197d8050000         add dword ptr [edi + 0x5d8], edx
// 004d38f6  8397dc05000000       adc dword ptr [edi + 0x5dc], 0
// 004d38fd  57                   push edi
// 004d38fe  8d8e90070000         lea ecx, [esi + 0x790]
// 004d3904  e81788feff           call 0x4bc120
// 004d3909  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004d390d  8b442444             mov eax, dword ptr [esp + 0x44]
// 004d3911  85c0                 test eax, eax
// 004d3913  7643                 jbe 0x4d3958
// 004d3915  db4500               fild dword ptr [ebp]
// 004d3918  89442414             mov dword ptr [esp + 0x14], eax
// 004d391c  dc0df0ee8100         fmul qword ptr [0x81eef0]
// 004d3922  db442414             fild dword ptr [esp + 0x14]
// 004d3926  7d06                 jge 0x4d392e
// 004d3928  dc0540128100         fadd qword ptr [0x811240]
// 004d392e  def9                 fdivp st(1)
// 004d3930  e8f1de1c00           call 0x6a1826
// 004d3935  018620050000         add dword ptr [esi + 0x520], eax
// 004d393b  119624050000         adc dword ptr [esi + 0x524], edx
// 004d3941  83be2405000000       cmp dword ptr [esi + 0x524], 0
// 004d3948  7f3c                 jg 0x4d3986
// 004d394a  7c0c                 jl 0x4d3958
// 004d394c  81be2005000030750000 cmp dword ptr [esi + 0x520], 0x7530
// 004d3956  772e                 ja 0x4d3986
// 004d3958  8b96d8040000         mov edx, dword ptr [esi + 0x4d8]
// 004d395e  01542418             add dword ptr [esp + 0x18], edx
// 004d3962  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004d3966  8b8edc040000         mov ecx, dword ptr [esi + 0x4dc]
// 004d396c  13c1                 adc eax, ecx
// 004d396e  3bc3                 cmp eax, ebx
// 004d3970  8944241c             mov dword ptr [esp + 0x1c], eax
// 004d3974  0f8c96feffff         jl 0x4d3810
// 004d397a  7f0a                 jg 0x4d3986
// 004d397c  397c2418             cmp dword ptr [esp + 0x18], edi
// 004d3980  0f828afeffff         jb 0x4d3810
// 004d3986  8b6c2440             mov ebp, dword ptr [esp + 0x40]
// 004d398a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004d398e  018ee0040000         add dword ptr [esi + 0x4e0], ecx
// 004d3994  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004d3998  1186e4040000         adc dword ptr [esi + 0x4e4], eax
// 004d399e  3bc3                 cmp eax, ebx
// 004d39a0  7c16                 jl 0x4d39b8
// 004d39a2  7f04                 jg 0x4d39a8
// 004d39a4  3bcf                 cmp ecx, edi
// 004d39a6  7210                 jb 0x4d39b8
// 004d39a8  8b5c243c             mov ebx, dword ptr [esp + 0x3c]
// 004d39ac  c6860405000001       mov byte ptr [esi + 0x504], 1
// 004d39b3  e9af000000           jmp 0x4d3a67
// 004d39b8  8b5c243c             mov ebx, dword ptr [esp + 0x3c]
// 004d39bc  c6860405000000       mov byte ptr [esi + 0x504], 0
// 004d39c3  e99f000000           jmp 0x4d3a67
// 004d39c8  837e2000             cmp dword ptr [esi + 0x20], 0
// 004d39cc  0f8695000000         jbe 0x4d3a67
// 004d39d2  8dbec0000000         lea edi, [esi + 0xc0]
// 004d39d8  8bcf                 mov ecx, edi
// 004d39da  e8e117fdff           call 0x4a51c0
// 004d39df  8bcf                 mov ecx, edi
// 004d39e1  e87a1bfdff           call 0x4a5560
// 004d39e6  8b9600050000         mov edx, dword ptr [esi + 0x500]
// 004d39ec  6a01                 push 1
// 004d39ee  6a20                 push 0x20
// 004d39f0  8d442450             lea eax, [esp + 0x50]
// 004d39f4  50                   push eax
// 004d39f5  8bcf                 mov ecx, edi
// 004d39f7  89542454             mov dword ptr [esp + 0x54], edx
// 004d39fb  e8001cfdff           call 0x4a5600
// 004d3a00  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 004d3a04  6a01                 push 1
// 004d3a06  8d14cd1fffffff       lea edx, [ecx*8 - 0xe1]
// 004d3a0d  52                   push edx
// 004d3a0e  57                   push edi
// 004d3a0f  8d4e1c               lea ecx, [esi + 0x1c]
// 004d3a12  e8e9cfffff           call 0x4d0a00
// 004d3a17  01862c040000         add dword ptr [esi + 0x42c], eax
// 004d3a1d  8b442434             mov eax, dword ptr [esp + 0x34]
// 004d3a21  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 004d3a25  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 004d3a29  57                   push edi
// 004d3a2a  50                   push eax
// 004d3a2b  51                   push ecx
// 004d3a2c  52                   push edx
// 004d3a2d  8bce                 mov ecx, esi
// 004d3a2f  e82cb1ffff           call 0x4ceb60
// 004d3a34  8b442444             mov eax, dword ptr [esp + 0x44]
// 004d3a38  85c0                 test eax, eax
// 004d3a3a  762b                 jbe 0x4d3a67
// 004d3a3c  db07                 fild dword ptr [edi]
// 004d3a3e  89442444             mov dword ptr [esp + 0x44], eax
// 004d3a42  dc0df0ee8100         fmul qword ptr [0x81eef0]
// 004d3a48  db442444             fild dword ptr [esp + 0x44]
// 004d3a4c  7d06                 jge 0x4d3a54
// 004d3a4e  dc0540128100         fadd qword ptr [0x811240]
// 004d3a54  def9                 fdivp st(1)
// 004d3a56  e8cbdd1c00           call 0x6a1826
// 004d3a5b  018620050000         add dword ptr [esi + 0x520], eax
// 004d3a61  119624050000         adc dword ptr [esi + 0x524], edx
// 004d3a67  33ff                 xor edi, edi
// 004d3a69  39be94070000         cmp dword ptr [esi + 0x794], edi
// 004d3a6f  0f86b3000000         jbe 0x4d3b28
// 004d3a75  eb09                 jmp 0x4d3a80
// 004d3a77  8da42400000000       lea esp, [esp]
// 004d3a7e  8bff                 mov edi, edi
// 004d3a80  8b8690070000         mov eax, dword ptr [esi + 0x790]
// 004d3a86  8b04b8               mov eax, dword ptr [eax + edi*4]
// 004d3a89  8b88dc050000         mov ecx, dword ptr [eax + 0x5dc]
// 004d3a8f  3bcd                 cmp ecx, ebp
// 004d3a91  0f8f84000000         jg 0x4d3b1b
// 004d3a97  7c0a                 jl 0x4d3aa3
// 004d3a99  8b90d8050000         mov edx, dword ptr [eax + 0x5d8]
// 004d3a9f  3bd3                 cmp edx, ebx
// 004d3aa1  7378                 jae 0x4d3b1b
// 004d3aa3  8daec0000000         lea ebp, [esi + 0xc0]
// 004d3aa9  8bcd                 mov ecx, ebp
// 004d3aab  e81017fdff           call 0x4a51c0
// 004d3ab0  8b8690070000         mov eax, dword ptr [esi + 0x790]
// 004d3ab6  8b04b8               mov eax, dword ptr [eax + edi*4]
// 004d3ab9  8b88d4050000         mov ecx, dword ptr [eax + 0x5d4]
// 004d3abf  51                   push ecx
// 004d3ac0  50                   push eax
// 004d3ac1  8bcd                 mov ecx, ebp
// 004d3ac3  e8381cfdff           call 0x4a5700
// 004d3ac8  8b542434             mov edx, dword ptr [esp + 0x34]
// 004d3acc  8b442430             mov eax, dword ptr [esp + 0x30]
// 004d3ad0  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 004d3ad4  55                   push ebp
// 004d3ad5  52                   push edx
// 004d3ad6  50                   push eax
// 004d3ad7  51                   push ecx
// 004d3ad8  8bce                 mov ecx, esi
// 004d3ada  e881b0ffff           call 0x4ceb60
// 004d3adf  8b9690070000         mov edx, dword ptr [esi + 0x790]
// 004d3ae5  8b04ba               mov eax, dword ptr [edx + edi*4]
// 004d3ae8  50                   push eax
// 004d3ae9  e88ccb1c00           call 0x6a067a
// 004d3aee  8b8694070000         mov eax, dword ptr [esi + 0x794]
// 004d3af4  8d48ff               lea ecx, [eax - 1]
// 004d3af7  83c404               add esp, 4
// 004d3afa  3bf9                 cmp edi, ecx
// 004d3afc  740d                 je 0x4d3b0b
// 004d3afe  8b8e90070000         mov ecx, dword ptr [esi + 0x790]
// 004d3b04  8b5481fc             mov edx, dword ptr [ecx + eax*4 - 4]
// 004d3b08  8914b9               mov dword ptr [ecx + edi*4], edx
// 004d3b0b  ff8e94070000         dec dword ptr [esi + 0x794]
// 004d3b11  8b6c2440             mov ebp, dword ptr [esp + 0x40]
// 004d3b15  8b5c243c             mov ebx, dword ptr [esp + 0x3c]
// 004d3b19  eb01                 jmp 0x4d3b1c
// 004d3b1b  47                   inc edi
// 004d3b1c  3bbe94070000         cmp edi, dword ptr [esi + 0x794]
// 004d3b22  0f8258ffffff         jb 0x4d3a80
// 004d3b28  5f                   pop edi
// 004d3b29  5e                   pop esi
// 004d3b2a  5d                   pop ebp
// 004d3b2b  5b                   pop ebx
// 004d3b2c  83c418               add esp, 0x18
// 004d3b2f  c22000               ret 0x20
// library openrbx-raknet/ReliabilityLayer.cpp (function ?Update@ReliabilityLayer@@QAEXIUSystemAddress@@H_JIAAV?$List@PAVPluginInterface@@@DataStructures@@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet ReliabilityLayer.cpp
