// from server: 100% by auto
// roc 2010-06 007906c0  unit: RBX::GroupDragTool  size: 192 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007906c0
//
// 007906c0  56                   push esi
// 007906c1  57                   push edi
// 007906c2  e819f7ffff           call 0x78fde0
// 007906c7  8b06                 mov eax, dword ptr [esi]
// 007906c9  48                   dec eax
// 007906ca  83c408               add esp, 8
// 007906cd  83f80b               cmp eax, 0xb
// 007906d0  776a                 ja 0x79073c
// 007906d2  0fb68074077900       movzx eax, byte ptr [eax + 0x790774]
// 007906d9  ff248560077900       jmp dword ptr [eax*4 + 0x790760]
// 007906e0  c70602000000         mov dword ptr [esi], 2
// 007906e6  eb54                 jmp 0x79073c
// 007906e8  c70603000000         mov dword ptr [esi], 3
// 007906ee  eb4c                 jmp 0x79073c
// 007906f0  8bc6                 mov eax, esi
// 007906f2  8bcf                 mov ecx, edi
// 007906f4  e857f2ffff           call 0x78f950
// 007906f9  eb41                 jmp 0x79073c
// 007906fb  56                   push esi
// 007906fc  8bc7                 mov eax, edi
// 007906fe  e8edf8ffff           call 0x78fff0
// 00790703  83c404               add esp, 4
// 00790706  833e0c               cmp dword ptr [esi], 0xc
// 00790709  7515                 jne 0x790720
// 0079070b  8b4608               mov eax, dword ptr [esi + 8]
// 0079070e  a900010000           test eax, 0x100
// 00790713  750b                 jne 0x790720
// 00790715  0fb64f32             movzx ecx, byte ptr [edi + 0x32]
// 00790719  3bc1                 cmp eax, ecx
// 0079071b  7c03                 jl 0x790720
// 0079071d  ff4f24               dec dword ptr [edi + 0x24]
// 00790720  8b5608               mov edx, dword ptr [esi + 8]
// 00790723  6a00                 push 0
// 00790725  52                   push edx
// 00790726  6a00                 push 0
// 00790728  6a13                 push 0x13
// 0079072a  57                   push edi
// 0079072b  e830f4ffff           call 0x78fb60
// 00790730  83c414               add esp, 0x14
// 00790733  894608               mov dword ptr [esi + 8], eax
// 00790736  c7060b000000         mov dword ptr [esi], 0xb
// 0079073c  8b4614               mov eax, dword ptr [esi + 0x14]
// 0079073f  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 00790742  894610               mov dword ptr [esi + 0x10], eax
// 00790745  57                   push edi
// 00790746  8bc1                 mov eax, ecx
// 00790748  894e14               mov dword ptr [esi + 0x14], ecx
// 0079074b  e890edffff           call 0x78f4e0
// 00790750  8b4610               mov eax, dword ptr [esi + 0x10]
// 00790753  57                   push edi
// 00790754  e887edffff           call 0x78f4e0
// 00790759  83c408               add esp, 8
// 0079075c  c3                   ret 
// 0079075d  8d4900               lea ecx, [ecx]
// 00790760  e006                 loopne 0x790768
// 00790762  7900                 jns 0x790764
// 00790764  e8067900f0           call 0xf079806f
// 00790769  06                   push es
// 0079076a  7900                 jns 0x79076c
// 0079076c  fb                   sti 
// 0079076d  06                   push es
// 0079076e  7900                 jns 0x790770
// 00790770  3c07                 cmp al, 7
// 00790772  7900                 jns 0x790774
// 00790774  0001                 add byte ptr [ecx], al
// 00790776  0001                 add byte ptr [ecx], al
// 00790778  010404               add dword ptr [esp + eax], eax
// 0079077b  0404                 add al, 4
// 0079077d  0203                 add al, byte ptr [ebx]
// library lua-5.1/lcode.c (function _codenot)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lcode.c
