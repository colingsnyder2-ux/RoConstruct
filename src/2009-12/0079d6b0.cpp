// from server: 100% by auto
// roc 2009-12 0079d6b0  unit: seg_00790000  size: 138 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0079d6b0
//
// 0079d6b0  83c0cf               add eax, -0x31
// 0079d6b3  55                   push ebp
// 0079d6b4  8b6c2408             mov ebp, dword ptr [esp + 8]
// 0079d6b8  56                   push esi
// 0079d6b9  57                   push edi
// 0079d6ba  8bf1                 mov esi, ecx
// 0079d6bc  780c                 js 0x79d6ca
// 0079d6be  3b460c               cmp eax, dword ptr [esi + 0xc]
// 0079d6c1  7d07                 jge 0x79d6ca
// 0079d6c3  837cc614ff           cmp dword ptr [esi + eax*8 + 0x14], -1
// 0079d6c8  7511                 jne 0x79d6db
// 0079d6ca  8b4608               mov eax, dword ptr [esi + 8]
// 0079d6cd  68b8b09e00           push 0x9eb0b8
// 0079d6d2  50                   push eax
// 0079d6d3  e818c6feff           call 0x789cf0
// 0079d6d8  83c408               add esp, 8
// 0079d6db  8b4e04               mov ecx, dword ptr [esi + 4]
// 0079d6de  8b7cc614             mov edi, dword ptr [esi + eax*8 + 0x14]
// 0079d6e2  2bcd                 sub ecx, ebp
// 0079d6e4  3bcf                 cmp ecx, edi
// 0079d6e6  724c                 jb 0x79d734
// 0079d6e8  8b74c610             mov esi, dword ptr [esi + eax*8 + 0x10]
// 0079d6ec  8bcf                 mov ecx, edi
// 0079d6ee  8bd5                 mov edx, ebp
// 0079d6f0  83ff04               cmp edi, 4
// 0079d6f3  7214                 jb 0x79d709
// 0079d6f5  8b06                 mov eax, dword ptr [esi]
// 0079d6f7  3b02                 cmp eax, dword ptr [edx]
// 0079d6f9  7539                 jne 0x79d734
// 0079d6fb  83e904               sub ecx, 4
// 0079d6fe  83c204               add edx, 4
// 0079d701  83c604               add esi, 4
// 0079d704  83f904               cmp ecx, 4
// 0079d707  73ec                 jae 0x79d6f5
// 0079d709  85c9                 test ecx, ecx
// 0079d70b  7420                 je 0x79d72d
// 0079d70d  8a02                 mov al, byte ptr [edx]
// 0079d70f  3a06                 cmp al, byte ptr [esi]
// 0079d711  7521                 jne 0x79d734
// 0079d713  83f901               cmp ecx, 1
// 0079d716  7615                 jbe 0x79d72d
// 0079d718  8a4201               mov al, byte ptr [edx + 1]
// 0079d71b  3a4601               cmp al, byte ptr [esi + 1]
// 0079d71e  7514                 jne 0x79d734
// 0079d720  83f902               cmp ecx, 2
// 0079d723  7608                 jbe 0x79d72d
// 0079d725  8a4a02               mov cl, byte ptr [edx + 2]
// 0079d728  3a4e02               cmp cl, byte ptr [esi + 2]
// 0079d72b  7507                 jne 0x79d734
// 0079d72d  8d042f               lea eax, [edi + ebp]
// 0079d730  5f                   pop edi
// 0079d731  5e                   pop esi
// 0079d732  5d                   pop ebp
// 0079d733  c3                   ret 
// 0079d734  5f                   pop edi
// 0079d735  5e                   pop esi
// 0079d736  33c0                 xor eax, eax
// 0079d738  5d                   pop ebp
// 0079d739  c3                   ret 
// library lua-5.1/lstrlib.c (function _match_capture)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lstrlib.c
