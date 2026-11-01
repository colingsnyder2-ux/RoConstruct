// from server: 100% by auto
// roc 2007-03 005167d0  unit: seg_00510000  size: 192 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005167d0
//
// 005167d0  51                   push ecx
// 005167d1  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005167d5  f6c102               test cl, 2
// 005167d8  53                   push ebx
// 005167d9  56                   push esi
// 005167da  57                   push edi
// 005167db  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 005167df  744c                 je 0x51682d
// 005167e1  83f903               cmp ecx, 3
// 005167e4  b308                 mov bl, 8
// 005167e6  7406                 je 0x5167ee
// 005167e8  8a9f28010000         mov bl, byte ptr [edi + 0x128]
// 005167ee  8b742418             mov esi, dword ptr [esp + 0x18]
// 005167f2  8a16                 mov dl, byte ptr [esi]
// 005167f4  84d2                 test dl, dl
// 005167f6  0f8481000000         je 0x51687d
// 005167fc  3ad3                 cmp dl, bl
// 005167fe  777d                 ja 0x51687d
// 00516800  8a4e01               mov cl, byte ptr [esi + 1]
// 00516803  84c9                 test cl, cl
// 00516805  7476                 je 0x51687d
// 00516807  3acb                 cmp cl, bl
// 00516809  7772                 ja 0x51687d
// 0051680b  8a4602               mov al, byte ptr [esi + 2]
// 0051680e  84c0                 test al, al
// 00516810  746b                 je 0x51687d
// 00516812  3ac3                 cmp al, bl
// 00516814  7767                 ja 0x51687d
// 00516816  884c240d             mov byte ptr [esp + 0xd], cl
// 0051681a  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0051681e  8844240e             mov byte ptr [esp + 0xe], al
// 00516822  8854240c             mov byte ptr [esp + 0xc], dl
// 00516826  b803000000           mov eax, 3
// 0051682b  eb1c                 jmp 0x516849
// 0051682d  8b742418             mov esi, dword ptr [esp + 0x18]
// 00516831  8a4603               mov al, byte ptr [esi + 3]
// 00516834  84c0                 test al, al
// 00516836  7445                 je 0x51687d
// 00516838  3a8728010000         cmp al, byte ptr [edi + 0x128]
// 0051683e  773d                 ja 0x51687d
// 00516840  8844240c             mov byte ptr [esp + 0xc], al
// 00516844  b801000000           mov eax, 1
// 00516849  f6c104               test cl, 4
// 0051684c  7416                 je 0x516864
// 0051684e  8a4e04               mov cl, byte ptr [esi + 4]
// 00516851  84c9                 test cl, cl
// 00516853  7428                 je 0x51687d
// 00516855  3a8f28010000         cmp cl, byte ptr [edi + 0x128]
// 0051685b  7720                 ja 0x51687d
// 0051685d  884c040c             mov byte ptr [esp + eax + 0xc], cl
// 00516861  83c001               add eax, 1
// 00516864  50                   push eax
// 00516865  8d442410             lea eax, [esp + 0x10]
// 00516869  50                   push eax
// 0051686a  680c0f7a00           push 0x7a0f0c
// 0051686f  57                   push edi
// 00516870  e86bf7ffff           call 0x515fe0
// 00516875  83c410               add esp, 0x10
// 00516878  5f                   pop edi
// 00516879  5e                   pop esi
// 0051687a  5b                   pop ebx
// 0051687b  59                   pop ecx
// 0051687c  c3                   ret 
// 0051687d  6810327a00           push 0x7a3210
// 00516882  57                   push edi
// 00516883  e8481b0000           call 0x5183d0
// 00516888  83c408               add esp, 8
// 0051688b  5f                   pop edi
// 0051688c  5e                   pop esi
// 0051688d  5b                   pop ebx
// 0051688e  59                   pop ecx
// 0051688f  c3                   ret 
// library libpng-1.2.7/pngwutil.c (function _png_write_sBIT)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.7 pngwutil.c
