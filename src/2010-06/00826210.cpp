// from server: 100% by auto
// roc 2010-06 00826210  unit: CXTPControlGalleryPaintManager  size: 302 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00826210
//
// 00826210  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00826214  8b442410             mov eax, dword ptr [esp + 0x10]
// 00826218  83ec08               sub esp, 8
// 0082621b  53                   push ebx
// 0082621c  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 00826220  56                   push esi
// 00826221  57                   push edi
// 00826222  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00826226  2bc3                 sub eax, ebx
// 00826228  2bcf                 sub ecx, edi
// 0082622a  3bc1                 cmp eax, ecx
// 0082622c  8bf0                 mov esi, eax
// 0082622e  7c02                 jl 0x826232
// 00826230  8bf1                 mov esi, ecx
// 00826232  83fe06               cmp esi, 6
// 00826235  0f8cfc000000         jl 0x826337
// 0082623b  2bc6                 sub eax, esi
// 0082623d  99                   cdq 
// 0082623e  2bc2                 sub eax, edx
// 00826240  d1f8                 sar eax, 1
// 00826242  55                   push ebp
// 00826243  8d6c1802             lea ebp, [eax + ebx + 2]
// 00826247  8bc1                 mov eax, ecx
// 00826249  2bc6                 sub eax, esi
// 0082624b  99                   cdq 
// 0082624c  2bc2                 sub eax, edx
// 0082624e  d1f8                 sar eax, 1
// 00826250  8d443802             lea eax, [eax + edi + 2]
// 00826254  83ee04               sub esi, 4
// 00826257  837c243800           cmp dword ptr [esp + 0x38], 0
// 0082625c  89442410             mov dword ptr [esp + 0x10], eax
// 00826260  7404                 je 0x826266
// 00826262  33ff                 xor edi, edi
// 00826264  eb0a                 jmp 0x826270
// 00826266  6a10                 push 0x10
// 00826268  ff1504ba9e00         call dword ptr [0x9eba04]
// 0082626e  8bf8                 mov edi, eax
// 00826270  68c855a600           push 0xa655c8
// 00826275  6a00                 push 0
// 00826277  6a00                 push 0
// 00826279  6a00                 push 0
// 0082627b  6a00                 push 0
// 0082627d  6a02                 push 2
// 0082627f  6a00                 push 0
// 00826281  6a00                 push 0
// 00826283  6a00                 push 0
// 00826285  6890010000           push 0x190
// 0082628a  6a00                 push 0
// 0082628c  6a00                 push 0
// 0082628e  6a00                 push 0
// 00826290  56                   push esi
// 00826291  ff1574a19e00         call dword ptr [0x9ea174]
// 00826297  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 0082629b  8bd8                 mov ebx, eax
// 0082629d  85f6                 test esi, esi
// 0082629f  7504                 jne 0x8262a5
// 008262a1  33c0                 xor eax, eax
// 008262a3  eb03                 jmp 0x8262a8
// 008262a5  8b4604               mov eax, dword ptr [esi + 4]
// 008262a8  53                   push ebx
// 008262a9  50                   push eax
// 008262aa  ff15c8a09e00         call dword ptr [0x9ea0c8]
// 008262b0  89442414             mov dword ptr [esp + 0x14], eax
// 008262b4  85f6                 test esi, esi
// 008262b6  7504                 jne 0x8262bc
// 008262b8  33c0                 xor eax, eax
// 008262ba  eb03                 jmp 0x8262bf
// 008262bc  8b4604               mov eax, dword ptr [esi + 4]
// 008262bf  57                   push edi
// 008262c0  50                   push eax
// 008262c1  ff1548a19e00         call dword ptr [0x9ea148]
// 008262c7  6a01                 push 1
// 008262c9  8bce                 mov ecx, esi
// 008262cb  e8e46a1500           call 0x97cdb4
// 008262d0  837c243000           cmp dword ptr [esp + 0x30], 0
// 008262d5  7415                 je 0x8262ec
// 008262d7  837c243400           cmp dword ptr [esp + 0x34], 0
// 008262dc  7407                 je 0x8262e5
// 008262de  b9bcbca400           mov ecx, 0xa4bcbc
// 008262e3  eb18                 jmp 0x8262fd
// 008262e5  b910b3a000           mov ecx, 0xa0b310
// 008262ea  eb11                 jmp 0x8262fd
// 008262ec  837c243400           cmp dword ptr [esp + 0x34], 0
// 008262f1  b9b8bca400           mov ecx, 0xa4bcb8
// 008262f6  7505                 jne 0x8262fd
// 008262f8  b9b4bca400           mov ecx, 0xa4bcb4
// 008262fd  85f6                 test esi, esi
// 008262ff  7504                 jne 0x826305
// 00826301  33c0                 xor eax, eax
// 00826303  eb03                 jmp 0x826308
// 00826305  8b4604               mov eax, dword ptr [esi + 4]
// 00826308  6a01                 push 1
// 0082630a  51                   push ecx
// 0082630b  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0082630f  51                   push ecx
// 00826310  55                   push ebp
// 00826311  50                   push eax
// 00826312  ff1534a19e00         call dword ptr [0x9ea134]
// 00826318  5d                   pop ebp
// 00826319  85f6                 test esi, esi
// 0082631b  7504                 jne 0x826321
// 0082631d  33f6                 xor esi, esi
// 0082631f  eb03                 jmp 0x826324
// 00826321  8b7604               mov esi, dword ptr [esi + 4]
// 00826324  8b542410             mov edx, dword ptr [esp + 0x10]
// 00826328  52                   push edx
// 00826329  56                   push esi
// 0082632a  ff15c8a09e00         call dword ptr [0x9ea0c8]
// 00826330  53                   push ebx
// 00826331  ff15d4a09e00         call dword ptr [0x9ea0d4]
// 00826337  5f                   pop edi
// 00826338  5e                   pop esi
// 00826339  5b                   pop ebx
// 0082633a  83c408               add esp, 8
// 0082633d  c3                   ret 
// library xtp-13.2.1/Source\Controls\XTPScrollBar.cpp (function ?DrawArrowGlyph@@YAXPAVCDC@@VCRect@@HHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTPScrollBar.cpp
