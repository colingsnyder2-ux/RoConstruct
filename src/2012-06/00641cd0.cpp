// from server: 100% by auto
// roc 2012-06 00641cd0  unit: G3D::Sphere  size: 269 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00641cd0
//
// 00641cd0  51                   push ecx
// 00641cd1  53                   push ebx
// 00641cd2  55                   push ebp
// 00641cd3  56                   push esi
// 00641cd4  8bf0                 mov esi, eax
// 00641cd6  8a06                 mov al, byte ptr [esi]
// 00641cd8  57                   push edi
// 00641cd9  3c21                 cmp al, 0x21
// 00641cdb  740e                 je 0x641ceb
// 00641cdd  3c5e                 cmp al, 0x5e
// 00641cdf  740a                 je 0x641ceb
// 00641ce1  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00641ce9  eb09                 jmp 0x641cf4
// 00641ceb  c744241001000000     mov dword ptr [esp + 0x10], 1
// 00641cf3  46                   inc esi
// 00641cf4  8b6c241c             mov ebp, dword ptr [esp + 0x1c]
// 00641cf8  83e510               and ebp, 0x10
// 00641cfb  7417                 je 0x641d14
// 00641cfd  0fb6442418           movzx eax, byte ptr [esp + 0x18]
// 00641d02  50                   push eax
// 00641d03  ff155c29b200         call dword ptr [0xb2295c]
// 00641d09  8ac8                 mov cl, al
// 00641d0b  83c404               add esp, 4
// 00641d0e  884c2418             mov byte ptr [esp + 0x18], cl
// 00641d12  eb04                 jmp 0x641d18
// 00641d14  8a4c2418             mov cl, byte ptr [esp + 0x18]
// 00641d18  8a1e                 mov bl, byte ptr [esi]
// 00641d1a  33ff                 xor edi, edi
// 00641d1c  46                   inc esi
// 00641d1d  8d4900               lea ecx, [ecx]
// 00641d20  80fb5c               cmp bl, 0x5c
// 00641d23  750a                 jne 0x641d2f
// 00641d25  f644241c01           test byte ptr [esp + 0x1c], 1
// 00641d2a  751b                 jne 0x641d47
// 00641d2c  8a1e                 mov bl, byte ptr [esi]
// 00641d2e  46                   inc esi
// 00641d2f  84db                 test bl, bl
// 00641d31  0f8495000000         je 0x641dcc
// 00641d37  80fb2f               cmp bl, 0x2f
// 00641d3a  750b                 jne 0x641d47
// 00641d3c  f644241c02           test byte ptr [esp + 0x1c], 2
// 00641d41  0f858e000000         jne 0x641dd5
// 00641d47  85ed                 test ebp, ebp
// 00641d49  7413                 je 0x641d5e
// 00641d4b  0fb6cb               movzx ecx, bl
// 00641d4e  51                   push ecx
// 00641d4f  ff155c29b200         call dword ptr [0xb2295c]
// 00641d55  8a4c241c             mov cl, byte ptr [esp + 0x1c]
// 00641d59  83c404               add esp, 4
// 00641d5c  8ad8                 mov bl, al
// 00641d5e  803e2d               cmp byte ptr [esi], 0x2d
// 00641d61  753f                 jne 0x641da2
// 00641d63  8a4601               mov al, byte ptr [esi + 1]
// 00641d66  84c0                 test al, al
// 00641d68  7438                 je 0x641da2
// 00641d6a  3c5d                 cmp al, 0x5d
// 00641d6c  7434                 je 0x641da2
// 00641d6e  83c602               add esi, 2
// 00641d71  3c5c                 cmp al, 0x5c
// 00641d73  750a                 jne 0x641d7f
// 00641d75  f644241c01           test byte ptr [esp + 0x1c], 1
// 00641d7a  7507                 jne 0x641d83
// 00641d7c  8a06                 mov al, byte ptr [esi]
// 00641d7e  46                   inc esi
// 00641d7f  84c0                 test al, al
// 00641d81  7449                 je 0x641dcc
// 00641d83  85ed                 test ebp, ebp
// 00641d85  7411                 je 0x641d98
// 00641d87  0fb6d0               movzx edx, al
// 00641d8a  52                   push edx
// 00641d8b  ff155c29b200         call dword ptr [0xb2295c]
// 00641d91  8a4c241c             mov cl, byte ptr [esp + 0x1c]
// 00641d95  83c404               add esp, 4
// 00641d98  3ad9                 cmp bl, cl
// 00641d9a  7f0f                 jg 0x641dab
// 00641d9c  3ac8                 cmp cl, al
// 00641d9e  7f0b                 jg 0x641dab
// 00641da0  eb04                 jmp 0x641da6
// 00641da2  3ad9                 cmp bl, cl
// 00641da4  7505                 jne 0x641dab
// 00641da6  bf01000000           mov edi, 1
// 00641dab  8a1e                 mov bl, byte ptr [esi]
// 00641dad  46                   inc esi
// 00641dae  80fb5d               cmp bl, 0x5d
// 00641db1  0f8569ffffff         jne 0x641d20
// 00641db7  8b442420             mov eax, dword ptr [esp + 0x20]
// 00641dbb  8930                 mov dword ptr [eax], esi
// 00641dbd  33c0                 xor eax, eax
// 00641dbf  3b7c2410             cmp edi, dword ptr [esp + 0x10]
// 00641dc3  5f                   pop edi
// 00641dc4  5e                   pop esi
// 00641dc5  5d                   pop ebp
// 00641dc6  0f95c0               setne al
// 00641dc9  5b                   pop ebx
// 00641dca  59                   pop ecx
// 00641dcb  c3                   ret 
// 00641dcc  5f                   pop edi
// 00641dcd  5e                   pop esi
// 00641dce  5d                   pop ebp
// 00641dcf  83c8ff               or eax, 0xffffffff
// 00641dd2  5b                   pop ebx
// 00641dd3  59                   pop ecx
// 00641dd4  c3                   ret 
// 00641dd5  5f                   pop edi
// 00641dd6  5e                   pop esi
// 00641dd7  5d                   pop ebp
// 00641dd8  33c0                 xor eax, eax
// 00641dda  5b                   pop ebx
// 00641ddb  59                   pop ecx
// 00641ddc  c3                   ret 
// library rbx2016-g3d/g3dfnmatch.cpp (function ?rangematch@G3D@@YAHPBDDHPAPAD@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-g3d g3dfnmatch.cpp
