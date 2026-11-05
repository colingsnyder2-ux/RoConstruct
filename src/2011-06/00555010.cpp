// from server: 100% by auto
// roc 2011-06 00555010  unit: G3D::LineSegment  size: 269 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00555010
//
// 00555010  51                   push ecx
// 00555011  53                   push ebx
// 00555012  55                   push ebp
// 00555013  56                   push esi
// 00555014  8bf0                 mov esi, eax
// 00555016  8a06                 mov al, byte ptr [esi]
// 00555018  57                   push edi
// 00555019  3c21                 cmp al, 0x21
// 0055501b  740e                 je 0x55502b
// 0055501d  3c5e                 cmp al, 0x5e
// 0055501f  740a                 je 0x55502b
// 00555021  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00555029  eb09                 jmp 0x555034
// 0055502b  c744241001000000     mov dword ptr [esp + 0x10], 1
// 00555033  46                   inc esi
// 00555034  8b6c241c             mov ebp, dword ptr [esp + 0x1c]
// 00555038  83e510               and ebp, 0x10
// 0055503b  7417                 je 0x555054
// 0055503d  0fb6442418           movzx eax, byte ptr [esp + 0x18]
// 00555042  50                   push eax
// 00555043  ff155c09a400         call dword ptr [0xa4095c]
// 00555049  8ac8                 mov cl, al
// 0055504b  83c404               add esp, 4
// 0055504e  884c2418             mov byte ptr [esp + 0x18], cl
// 00555052  eb04                 jmp 0x555058
// 00555054  8a4c2418             mov cl, byte ptr [esp + 0x18]
// 00555058  8a1e                 mov bl, byte ptr [esi]
// 0055505a  33ff                 xor edi, edi
// 0055505c  46                   inc esi
// 0055505d  8d4900               lea ecx, [ecx]
// 00555060  80fb5c               cmp bl, 0x5c
// 00555063  750a                 jne 0x55506f
// 00555065  f644241c01           test byte ptr [esp + 0x1c], 1
// 0055506a  751b                 jne 0x555087
// 0055506c  8a1e                 mov bl, byte ptr [esi]
// 0055506e  46                   inc esi
// 0055506f  84db                 test bl, bl
// 00555071  0f8495000000         je 0x55510c
// 00555077  80fb2f               cmp bl, 0x2f
// 0055507a  750b                 jne 0x555087
// 0055507c  f644241c02           test byte ptr [esp + 0x1c], 2
// 00555081  0f858e000000         jne 0x555115
// 00555087  85ed                 test ebp, ebp
// 00555089  7413                 je 0x55509e
// 0055508b  0fb6cb               movzx ecx, bl
// 0055508e  51                   push ecx
// 0055508f  ff155c09a400         call dword ptr [0xa4095c]
// 00555095  8a4c241c             mov cl, byte ptr [esp + 0x1c]
// 00555099  83c404               add esp, 4
// 0055509c  8ad8                 mov bl, al
// 0055509e  803e2d               cmp byte ptr [esi], 0x2d
// 005550a1  753f                 jne 0x5550e2
// 005550a3  8a4601               mov al, byte ptr [esi + 1]
// 005550a6  84c0                 test al, al
// 005550a8  7438                 je 0x5550e2
// 005550aa  3c5d                 cmp al, 0x5d
// 005550ac  7434                 je 0x5550e2
// 005550ae  83c602               add esi, 2
// 005550b1  3c5c                 cmp al, 0x5c
// 005550b3  750a                 jne 0x5550bf
// 005550b5  f644241c01           test byte ptr [esp + 0x1c], 1
// 005550ba  7507                 jne 0x5550c3
// 005550bc  8a06                 mov al, byte ptr [esi]
// 005550be  46                   inc esi
// 005550bf  84c0                 test al, al
// 005550c1  7449                 je 0x55510c
// 005550c3  85ed                 test ebp, ebp
// 005550c5  7411                 je 0x5550d8
// 005550c7  0fb6d0               movzx edx, al
// 005550ca  52                   push edx
// 005550cb  ff155c09a400         call dword ptr [0xa4095c]
// 005550d1  8a4c241c             mov cl, byte ptr [esp + 0x1c]
// 005550d5  83c404               add esp, 4
// 005550d8  3ad9                 cmp bl, cl
// 005550da  7f0f                 jg 0x5550eb
// 005550dc  3ac8                 cmp cl, al
// 005550de  7f0b                 jg 0x5550eb
// 005550e0  eb04                 jmp 0x5550e6
// 005550e2  3ad9                 cmp bl, cl
// 005550e4  7505                 jne 0x5550eb
// 005550e6  bf01000000           mov edi, 1
// 005550eb  8a1e                 mov bl, byte ptr [esi]
// 005550ed  46                   inc esi
// 005550ee  80fb5d               cmp bl, 0x5d
// 005550f1  0f8569ffffff         jne 0x555060
// 005550f7  8b442420             mov eax, dword ptr [esp + 0x20]
// 005550fb  8930                 mov dword ptr [eax], esi
// 005550fd  33c0                 xor eax, eax
// 005550ff  3b7c2410             cmp edi, dword ptr [esp + 0x10]
// 00555103  5f                   pop edi
// 00555104  5e                   pop esi
// 00555105  5d                   pop ebp
// 00555106  0f95c0               setne al
// 00555109  5b                   pop ebx
// 0055510a  59                   pop ecx
// 0055510b  c3                   ret 
// 0055510c  5f                   pop edi
// 0055510d  5e                   pop esi
// 0055510e  5d                   pop ebp
// 0055510f  83c8ff               or eax, 0xffffffff
// 00555112  5b                   pop ebx
// 00555113  59                   pop ecx
// 00555114  c3                   ret 
// 00555115  5f                   pop edi
// 00555116  5e                   pop esi
// 00555117  5d                   pop ebp
// 00555118  33c0                 xor eax, eax
// 0055511a  5b                   pop ebx
// 0055511b  59                   pop ecx
// 0055511c  c3                   ret 
// library rbx2016-g3d/g3dfnmatch.cpp (function ?rangematch@G3D@@YAHPBDDHPAPAD@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-g3d g3dfnmatch.cpp
