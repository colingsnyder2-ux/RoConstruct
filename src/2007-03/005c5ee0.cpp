// from server: 100% by auto
// roc 2007-03 005c5ee0  unit: seg_005c0000  size: 345 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c5ee0
//
// 005c5ee0  51                   push ecx
// 005c5ee1  53                   push ebx
// 005c5ee2  57                   push edi
// 005c5ee3  8d442408             lea eax, [esp + 8]
// 005c5ee7  50                   push eax
// 005c5ee8  51                   push ecx
// 005c5ee9  52                   push edx
// 005c5eea  e8d146ffff           call 0x5ba5c0
// 005c5eef  8d9e0c020000         lea ebx, [esi + 0x20c]
// 005c5ef5  83c40c               add esp, 0xc
// 005c5ef8  391e                 cmp dword ptr [esi], ebx
// 005c5efa  8bf8                 mov edi, eax
// 005c5efc  7209                 jb 0x5c5f07
// 005c5efe  56                   push esi
// 005c5eff  e83c3fffff           call 0x5b9e40
// 005c5f04  83c404               add esp, 4
// 005c5f07  8b06                 mov eax, dword ptr [esi]
// 005c5f09  c60022               mov byte ptr [eax], 0x22
// 005c5f0c  830601               add dword ptr [esi], 1
// 005c5f0f  837c240800           cmp dword ptr [esp + 8], 0
// 005c5f14  0f8493000000         je 0x5c5fad
// 005c5f1a  8d9b00000000         lea ebx, [ebx]
// 005c5f20  836c240801           sub dword ptr [esp + 8], 1
// 005c5f25  0fbe07               movsx eax, byte ptr [edi]
// 005c5f28  83f85c               cmp eax, 0x5c
// 005c5f2b  775c                 ja 0x5c5f89
// 005c5f2d  0fb688dc5f5c00       movzx ecx, byte ptr [eax + 0x5c5fdc]
// 005c5f34  ff248dcc5f5c00       jmp dword ptr [ecx*4 + 0x5c5fcc]
// 005c5f3b  391e                 cmp dword ptr [esi], ebx
// 005c5f3d  7209                 jb 0x5c5f48
// 005c5f3f  56                   push esi
// 005c5f40  e8fb3effff           call 0x5b9e40
// 005c5f45  83c404               add esp, 4
// 005c5f48  8b16                 mov edx, dword ptr [esi]
// 005c5f4a  c6025c               mov byte ptr [edx], 0x5c
// 005c5f4d  830601               add dword ptr [esi], 1
// 005c5f50  391e                 cmp dword ptr [esi], ebx
// 005c5f52  7209                 jb 0x5c5f5d
// 005c5f54  56                   push esi
// 005c5f55  e8e63effff           call 0x5b9e40
// 005c5f5a  83c404               add esp, 4
// 005c5f5d  8b06                 mov eax, dword ptr [esi]
// 005c5f5f  8a0f                 mov cl, byte ptr [edi]
// 005c5f61  8808                 mov byte ptr [eax], cl
// 005c5f63  eb37                 jmp 0x5c5f9c
// 005c5f65  6a02                 push 2
// 005c5f67  682c037a00           push 0x7a032c
// 005c5f6c  56                   push esi
// 005c5f6d  e80e3fffff           call 0x5b9e80
// 005c5f72  83c40c               add esp, 0xc
// 005c5f75  eb28                 jmp 0x5c5f9f
// 005c5f77  6a04                 push 4
// 005c5f79  68bca07b00           push 0x7ba0bc
// 005c5f7e  56                   push esi
// 005c5f7f  e8fc3effff           call 0x5b9e80
// 005c5f84  83c40c               add esp, 0xc
// 005c5f87  eb16                 jmp 0x5c5f9f
// 005c5f89  391e                 cmp dword ptr [esi], ebx
// 005c5f8b  7209                 jb 0x5c5f96
// 005c5f8d  56                   push esi
// 005c5f8e  e8ad3effff           call 0x5b9e40
// 005c5f93  83c404               add esp, 4
// 005c5f96  8b16                 mov edx, dword ptr [esi]
// 005c5f98  8a07                 mov al, byte ptr [edi]
// 005c5f9a  8802                 mov byte ptr [edx], al
// 005c5f9c  830601               add dword ptr [esi], 1
// 005c5f9f  83c701               add edi, 1
// 005c5fa2  837c240800           cmp dword ptr [esp + 8], 0
// 005c5fa7  0f8573ffffff         jne 0x5c5f20
// 005c5fad  836c240801           sub dword ptr [esp + 8], 1
// 005c5fb2  391e                 cmp dword ptr [esi], ebx
// 005c5fb4  5f                   pop edi
// 005c5fb5  5b                   pop ebx
// 005c5fb6  7209                 jb 0x5c5fc1
// 005c5fb8  56                   push esi
// 005c5fb9  e8823effff           call 0x5b9e40
// 005c5fbe  83c404               add esp, 4
// 005c5fc1  8b0e                 mov ecx, dword ptr [esi]
// 005c5fc3  c60122               mov byte ptr [ecx], 0x22
// 005c5fc6  830601               add dword ptr [esi], 1
// 005c5fc9  59                   pop ecx
// 005c5fca  c3                   ret 
// 005c5fcb  90                   nop 
// 005c5fcc  775f                 ja 0x5c602d
// 005c5fce  5c                   pop esp
// 005c5fcf  003b                 add byte ptr [ebx], bh
// 005c5fd1  5f                   pop edi
// 005c5fd2  5c                   pop esp
// 005c5fd3  00655f               add byte ptr [ebp + 0x5f], ah
// 005c5fd6  5c                   pop esp
// 005c5fd7  00895f5c0000         add byte ptr [ecx + 0x5c5f], cl
// 005c5fdd  0303                 add eax, dword ptr [ebx]
// 005c5fdf  0303                 add eax, dword ptr [ebx]
// 005c5fe1  0303                 add eax, dword ptr [ebx]
// 005c5fe3  0303                 add eax, dword ptr [ebx]
// 005c5fe5  0301                 add eax, dword ptr [ecx]
// 005c5fe7  0303                 add eax, dword ptr [ebx]
// 005c5fe9  0203                 add al, byte ptr [ebx]
// 005c5feb  0303                 add eax, dword ptr [ebx]
// 005c5fed  0303                 add eax, dword ptr [ebx]
// 005c5fef  0303                 add eax, dword ptr [ebx]
// 005c5ff1  0303                 add eax, dword ptr [ebx]
// 005c5ff3  0303                 add eax, dword ptr [ebx]
// 005c5ff5  0303                 add eax, dword ptr [ebx]
// 005c5ff7  0303                 add eax, dword ptr [ebx]
// 005c5ff9  0303                 add eax, dword ptr [ebx]
// 005c5ffb  0303                 add eax, dword ptr [ebx]
// 005c5ffd  0301                 add eax, dword ptr [ecx]
// 005c5fff  0303                 add eax, dword ptr [ebx]
// 005c6001  0303                 add eax, dword ptr [ebx]
// 005c6003  0303                 add eax, dword ptr [ebx]
// 005c6005  0303                 add eax, dword ptr [ebx]
// 005c6007  0303                 add eax, dword ptr [ebx]
// 005c6009  0303                 add eax, dword ptr [ebx]
// 005c600b  0303                 add eax, dword ptr [ebx]
// 005c600d  0303                 add eax, dword ptr [ebx]
// 005c600f  0303                 add eax, dword ptr [ebx]
// 005c6011  0303                 add eax, dword ptr [ebx]
// 005c6013  0303                 add eax, dword ptr [ebx]
// 005c6015  0303                 add eax, dword ptr [ebx]
// 005c6017  0303                 add eax, dword ptr [ebx]
// 005c6019  0303                 add eax, dword ptr [ebx]
// 005c601b  0303                 add eax, dword ptr [ebx]
// 005c601d  0303                 add eax, dword ptr [ebx]
// 005c601f  0303                 add eax, dword ptr [ebx]
// 005c6021  0303                 add eax, dword ptr [ebx]
// 005c6023  0303                 add eax, dword ptr [ebx]
// 005c6025  0303                 add eax, dword ptr [ebx]
// 005c6027  0303                 add eax, dword ptr [ebx]
// 005c6029  0303                 add eax, dword ptr [ebx]
// 005c602b  0303                 add eax, dword ptr [ebx]
// 005c602d  0303                 add eax, dword ptr [ebx]
// 005c602f  0303                 add eax, dword ptr [ebx]
// 005c6031  0303                 add eax, dword ptr [ebx]
// 005c6033  0303                 add eax, dword ptr [ebx]
// 005c6035  0303                 add eax, dword ptr [ebx]
// 005c6037  0301                 add eax, dword ptr [ecx]
// library lua-5.1.1/lstrlib.c (function _addquoted)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lstrlib.c
