// from server: 100% by auto
// roc 2007-03 00508a40  unit: seg_00500000  size: 784 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00508a40
//
// 00508a40  51                   push ecx
// 00508a41  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00508a45  83f803               cmp eax, 3
// 00508a48  7c14                 jl 0x508a5e
// 00508a4a  8b442408             mov eax, dword ptr [esp + 8]
// 00508a4e  6890087a00           push 0x7a0890
// 00508a53  50                   push eax
// 00508a54  e877f90000           call 0x5183d0
// 00508a59  83c408               add esp, 8
// 00508a5c  59                   pop ecx
// 00508a5d  c3                   ret 
// 00508a5e  85c0                 test eax, eax
// 00508a60  7505                 jne 0x508a67
// 00508a62  b801000000           mov eax, 1
// 00508a67  53                   push ebx
// 00508a68  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 00508a6c  85db                 test ebx, ebx
// 00508a6e  55                   push ebp
// 00508a6f  8b6c241c             mov ebp, dword ptr [esp + 0x1c]
// 00508a73  56                   push esi
// 00508a74  57                   push edi
// 00508a75  7c09                 jl 0x508a80
// 00508a77  85ed                 test ebp, ebp
// 00508a79  7405                 je 0x508a80
// 00508a7b  83f801               cmp eax, 1
// 00508a7e  7502                 jne 0x508a82
// 00508a80  33db                 xor ebx, ebx
// 00508a82  85db                 test ebx, ebx
// 00508a84  dd05584f7900         fld qword ptr [0x794f58]
// 00508a8a  8b742418             mov esi, dword ptr [esp + 0x18]
// 00508a8e  889ef9010000         mov byte ptr [esi + 0x1f9], bl
// 00508a94  8886f8010000         mov byte ptr [esi + 0x1f8], al
// 00508a9a  0f8e45010000         jle 0x508be5
// 00508aa0  83befc01000000       cmp dword ptr [esi + 0x1fc], 0
// 00508aa7  752f                 jne 0x508ad8
// 00508aa9  53                   push ebx
// 00508aaa  ddd8                 fstp st(0)
// 00508aac  56                   push esi
// 00508aad  e8ee040100           call 0x518fa0
// 00508ab2  8986fc010000         mov dword ptr [esi + 0x1fc], eax
// 00508ab8  83c408               add esp, 8
// 00508abb  33c0                 xor eax, eax
// 00508abd  85db                 test ebx, ebx
// 00508abf  7e11                 jle 0x508ad2
// 00508ac1  8b8efc010000         mov ecx, dword ptr [esi + 0x1fc]
// 00508ac7  c60408ff             mov byte ptr [eax + ecx], 0xff
// 00508acb  83c001               add eax, 1
// 00508ace  3bc3                 cmp eax, ebx
// 00508ad0  7cef                 jl 0x508ac1
// 00508ad2  dd05584f7900         fld qword ptr [0x794f58]
// 00508ad8  83be0002000000       cmp dword ptr [esi + 0x200], 0
// 00508adf  7554                 jne 0x508b35
// 00508ae1  8d3c1b               lea edi, [ebx + ebx]
// 00508ae4  ddd8                 fstp st(0)
// 00508ae6  57                   push edi
// 00508ae7  56                   push esi
// 00508ae8  e8b3040100           call 0x518fa0
// 00508aed  57                   push edi
// 00508aee  56                   push esi
// 00508aef  898600020000         mov dword ptr [esi + 0x200], eax
// 00508af5  e8a6040100           call 0x518fa0
// 00508afa  898604020000         mov dword ptr [esi + 0x204], eax
// 00508b00  83c410               add esp, 0x10
// 00508b03  33c0                 xor eax, eax
// 00508b05  85db                 test ebx, ebx
// 00508b07  7e26                 jle 0x508b2f
// 00508b09  8da42400000000       lea esp, [esp]
// 00508b10  8b9600020000         mov edx, dword ptr [esi + 0x200]
// 00508b16  66c704420001         mov word ptr [edx + eax*2], 0x100
// 00508b1c  8b8e04020000         mov ecx, dword ptr [esi + 0x204]
// 00508b22  66c704410001         mov word ptr [ecx + eax*2], 0x100
// 00508b28  83c001               add eax, 1
// 00508b2b  3bc3                 cmp eax, ebx
// 00508b2d  7ce1                 jl 0x508b10
// 00508b2f  dd05584f7900         fld qword ptr [0x794f58]
// 00508b35  33c9                 xor ecx, ecx
// 00508b37  85db                 test ebx, ebx
// 00508b39  0f8ea6000000         jle 0x508be5
// 00508b3f  dd0518fd7900         fld qword ptr [0x79fd18]
// 00508b45  d9ee                 fldz 
// 00508b47  dc54cd00             fcom qword ptr [ebp + ecx*8]
// 00508b4b  dfe0                 fnstsw ax
// 00508b4d  f6c441               test ah, 0x41
// 00508b50  751a                 jne 0x508b6c
// 00508b52  8b9600020000         mov edx, dword ptr [esi + 0x200]
// 00508b58  66c7044a0001         mov word ptr [edx + ecx*2], 0x100
// 00508b5e  8b8604020000         mov eax, dword ptr [esi + 0x204]
// 00508b64  66c704480001         mov word ptr [eax + ecx*2], 0x100
// 00508b6a  eb6a                 jmp 0x508bd6
// 00508b6c  dd44cd00             fld qword ptr [ebp + ecx*8]
// 00508b70  d97c241c             fnstcw word ptr [esp + 0x1c]
// 00508b74  0fb744241c           movzx eax, word ptr [esp + 0x1c]
// 00508b79  d8ca                 fmul st(2)
// 00508b7b  0d000c0000           or eax, 0xc00
// 00508b80  89442410             mov dword ptr [esp + 0x10], eax
// 00508b84  8b8604020000         mov eax, dword ptr [esi + 0x204]
// 00508b8a  d8c3                 fadd st(3)
// 00508b8c  d96c2410             fldcw word ptr [esp + 0x10]
// 00508b90  db5c2410             fistp dword ptr [esp + 0x10]
// 00508b94  0fb7542410           movzx edx, word ptr [esp + 0x10]
// 00508b99  66891448             mov word ptr [eax + ecx*2], dx
// 00508b9d  d96c241c             fldcw word ptr [esp + 0x1c]
// 00508ba1  d9c1                 fld st(1)
// 00508ba3  dc74cd00             fdiv qword ptr [ebp + ecx*8]
// 00508ba7  d97c241c             fnstcw word ptr [esp + 0x1c]
// 00508bab  d8c3                 fadd st(3)
// 00508bad  0fb744241c           movzx eax, word ptr [esp + 0x1c]
// 00508bb2  0d000c0000           or eax, 0xc00
// 00508bb7  89442410             mov dword ptr [esp + 0x10], eax
// 00508bbb  8b8600020000         mov eax, dword ptr [esi + 0x200]
// 00508bc1  d96c2410             fldcw word ptr [esp + 0x10]
// 00508bc5  db5c2410             fistp dword ptr [esp + 0x10]
// 00508bc9  0fb7542410           movzx edx, word ptr [esp + 0x10]
// 00508bce  66891448             mov word ptr [eax + ecx*2], dx
// 00508bd2  d96c241c             fldcw word ptr [esp + 0x1c]
// 00508bd6  83c101               add ecx, 1
// 00508bd9  3bcb                 cmp ecx, ebx
// 00508bdb  0f8c66ffffff         jl 0x508b47
// 00508be1  ddd9                 fstp st(1)
// 00508be3  ddd8                 fstp st(0)
// 00508be5  83be0802000000       cmp dword ptr [esi + 0x208], 0
// 00508bec  bf08000000           mov edi, 8
// 00508bf1  0f8589000000         jne 0x508c80
// 00508bf7  6a0a                 push 0xa
// 00508bf9  ddd8                 fstp st(0)
// 00508bfb  56                   push esi
// 00508bfc  e89f030100           call 0x518fa0
// 00508c01  6a0a                 push 0xa
// 00508c03  56                   push esi
// 00508c04  898608020000         mov dword ptr [esi + 0x208], eax
// 00508c0a  e891030100           call 0x518fa0
// 00508c0f  dd05584f7900         fld qword ptr [0x794f58]
// 00508c15  8b8e08020000         mov ecx, dword ptr [esi + 0x208]
// 00508c1b  89860c020000         mov dword ptr [esi + 0x20c], eax
// 00508c21  668939               mov word ptr [ecx], di
// 00508c24  8b960c020000         mov edx, dword ptr [esi + 0x20c]
// 00508c2a  66893a               mov word ptr [edx], di
// 00508c2d  8b8608020000         mov eax, dword ptr [esi + 0x208]
// 00508c33  66897802             mov word ptr [eax + 2], di
// 00508c37  8b8e0c020000         mov ecx, dword ptr [esi + 0x20c]
// 00508c3d  66897902             mov word ptr [ecx + 2], di
// 00508c41  8b9608020000         mov edx, dword ptr [esi + 0x208]
// 00508c47  66897a04             mov word ptr [edx + 4], di
// 00508c4b  8b860c020000         mov eax, dword ptr [esi + 0x20c]
// 00508c51  66897804             mov word ptr [eax + 4], di
// 00508c55  8b8e08020000         mov ecx, dword ptr [esi + 0x208]
// 00508c5b  66897906             mov word ptr [ecx + 6], di
// 00508c5f  8b960c020000         mov edx, dword ptr [esi + 0x20c]
// 00508c65  66897a06             mov word ptr [edx + 6], di
// 00508c69  8b8608020000         mov eax, dword ptr [esi + 0x208]
// 00508c6f  66897808             mov word ptr [eax + 8], di
// 00508c73  8b8e0c020000         mov ecx, dword ptr [esi + 0x20c]
// 00508c79  83c410               add esp, 0x10
// 00508c7c  66897908             mov word ptr [ecx + 8], di
// 00508c80  8b5c2428             mov ebx, dword ptr [esp + 0x28]
// 00508c84  d9e8                 fld1 
// 00508c86  dd0588087a00         fld qword ptr [0x7a0888]
// 00508c8c  33c9                 xor ecx, ecx
// 00508c8e  d9ee                 fldz 
// 00508c90  8bd3                 mov edx, ebx
// 00508c92  eb02                 jmp 0x508c96
// 00508c94  d9ca                 fxch st(2)
// 00508c96  85db                 test ebx, ebx
// 00508c98  0f8480000000         je 0x508d1e
// 00508c9e  dc12                 fcom qword ptr [edx]
// 00508ca0  dfe0                 fnstsw ax
// 00508ca2  f6c441               test ah, 0x41
// 00508ca5  7477                 je 0x508d1e
// 00508ca7  d9ca                 fxch st(2)
// 00508ca9  dc12                 fcom qword ptr [edx]
// 00508cab  dfe0                 fnstsw ax
// 00508cad  f6c441               test ah, 0x41
// 00508cb0  0f8a7e000000         jp 0x508d34
// 00508cb6  d9c1                 fld st(1)
// 00508cb8  8bae0c020000         mov ebp, dword ptr [esi + 0x20c]
// 00508cbe  dc32                 fdiv qword ptr [edx]
// 00508cc0  d97c241c             fnstcw word ptr [esp + 0x1c]
// 00508cc4  d8c4                 fadd st(4)
// 00508cc6  0fb744241c           movzx eax, word ptr [esp + 0x1c]
// 00508ccb  0d000c0000           or eax, 0xc00
// 00508cd0  89442410             mov dword ptr [esp + 0x10], eax
// 00508cd4  d96c2410             fldcw word ptr [esp + 0x10]
// 00508cd8  db5c2410             fistp dword ptr [esp + 0x10]
// 00508cdc  0fb7442410           movzx eax, word ptr [esp + 0x10]
// 00508ce1  66890429             mov word ptr [ecx + ebp], ax
// 00508ce5  8bae08020000         mov ebp, dword ptr [esi + 0x208]
// 00508ceb  d96c241c             fldcw word ptr [esp + 0x1c]
// 00508cef  dd02                 fld qword ptr [edx]
// 00508cf1  d97c241c             fnstcw word ptr [esp + 0x1c]
// 00508cf5  d8ca                 fmul st(2)
// 00508cf7  0fb744241c           movzx eax, word ptr [esp + 0x1c]
// 00508cfc  0d000c0000           or eax, 0xc00
// 00508d01  89442410             mov dword ptr [esp + 0x10], eax
// 00508d05  d8c4                 fadd st(4)
// 00508d07  d96c2410             fldcw word ptr [esp + 0x10]
// 00508d0b  db5c2410             fistp dword ptr [esp + 0x10]
// 00508d0f  0fb7442410           movzx eax, word ptr [esp + 0x10]
// 00508d14  66890429             mov word ptr [ecx + ebp], ax
// 00508d18  d96c241c             fldcw word ptr [esp + 0x1c]
// 00508d1c  eb16                 jmp 0x508d34
// 00508d1e  8b8608020000         mov eax, dword ptr [esi + 0x208]
// 00508d24  d9ca                 fxch st(2)
// 00508d26  66893c01             mov word ptr [ecx + eax], di
// 00508d2a  8b860c020000         mov eax, dword ptr [esi + 0x20c]
// 00508d30  66893c01             mov word ptr [ecx + eax], di
// 00508d34  83c102               add ecx, 2
// 00508d37  03d7                 add edx, edi
// 00508d39  83f90a               cmp ecx, 0xa
// 00508d3c  0f8c52ffffff         jl 0x508c94
// 00508d42  dddb                 fstp st(3)
// 00508d44  5f                   pop edi
// 00508d45  ddd8                 fstp st(0)
// 00508d47  5e                   pop esi
// 00508d48  ddd9                 fstp st(1)
// 00508d4a  5d                   pop ebp
// 00508d4b  ddd8                 fstp st(0)
// 00508d4d  5b                   pop ebx
// 00508d4e  59                   pop ecx
// 00508d4f  c3                   ret 
// library libpng-1.2.7/pngwrite.c (function _png_set_filter_heuristics)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.7 pngwrite.c
