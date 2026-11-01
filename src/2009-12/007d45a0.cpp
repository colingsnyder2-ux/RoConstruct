// from server: 100% by auto
// roc 2009-12 007d45a0  unit: seg_007d0000  size: 164 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007d45a0
//
// 007d45a0  56                   push esi
// 007d45a1  8b742408             mov esi, dword ptr [esp + 8]
// 007d45a5  8b4634               mov eax, dword ptr [esi + 0x34]
// 007d45a8  66ff4034             inc word ptr [eax + 0x34]
// 007d45ac  8b4634               mov eax, dword ptr [esi + 0x34]
// 007d45af  b9c8000000           mov ecx, 0xc8
// 007d45b4  57                   push edi
// 007d45b5  66394834             cmp word ptr [eax + 0x34], cx
// 007d45b9  7615                 jbe 0x7d45d0
// 007d45bb  6a00                 push 0
// 007d45bd  6890ee9e00           push 0x9eee90
// 007d45c2  56                   push esi
// 007d45c3  e8d80c0000           call 0x7d52a0
// 007d45c8  83c40c               add esp, 0xc
// 007d45cb  eb03                 jmp 0x7d45d0
// 007d45cd  8d4900               lea ecx, [ecx]
// 007d45d0  8b4610               mov eax, dword ptr [esi + 0x10]
// 007d45d3  05fcfeffff           add eax, 0xfffffefc
// 007d45d8  83f81b               cmp eax, 0x1b
// 007d45db  770e                 ja 0x7d45eb
// 007d45dd  0fb69028467d00       movzx edx, byte ptr [eax + 0x7d4628]
// 007d45e4  ff249520467d00       jmp dword ptr [edx*4 + 0x7d4620]
// 007d45eb  8bc6                 mov eax, esi
// 007d45ed  e85efeffff           call 0x7d4450
// 007d45f2  837e103b             cmp dword ptr [esi + 0x10], 0x3b
// 007d45f6  8bf8                 mov edi, eax
// 007d45f8  7509                 jne 0x7d4603
// 007d45fa  56                   push esi
// 007d45fb  e830210000           call 0x7d6730
// 007d4600  83c404               add esp, 4
// 007d4603  8b4630               mov eax, dword ptr [esi + 0x30]
// 007d4606  0fb64832             movzx ecx, byte ptr [eax + 0x32]
// 007d460a  894824               mov dword ptr [eax + 0x24], ecx
// 007d460d  85ff                 test edi, edi
// 007d460f  74bf                 je 0x7d45d0
// 007d4611  8b7634               mov esi, dword ptr [esi + 0x34]
// 007d4614  baffff0000           mov edx, 0xffff
// 007d4619  66015634             add word ptr [esi + 0x34], dx
// 007d461d  5f                   pop edi
// 007d461e  5e                   pop esi
// 007d461f  c3                   ret 
// 007d4620  11467d               adc dword ptr [esi + 0x7d], eax
// 007d4623  00eb                 add bl, ch
// 007d4625  45                   inc ebp
// 007d4626  7d00                 jge 0x7d4628
// 007d4628  0000                 add byte ptr [eax], al
// 007d462a  0001                 add byte ptr [ecx], al
// 007d462c  0101                 add dword ptr [ecx], eax
// 007d462e  0101                 add dword ptr [ecx], eax
// 007d4630  0101                 add dword ptr [ecx], eax
// 007d4632  0101                 add dword ptr [ecx], eax
// 007d4634  0101                 add dword ptr [ecx], eax
// 007d4636  0101                 add dword ptr [ecx], eax
// 007d4638  0001                 add byte ptr [ecx], al
// 007d463a  0101                 add dword ptr [ecx], eax
// 007d463c  0101                 add dword ptr [ecx], eax
// 007d463e  0101                 add dword ptr [ecx], eax
// 007d4640  0101                 add dword ptr [ecx], eax
// 007d4642  0100                 add dword ptr [eax], eax
// library lua-5.1/lparser.c (function _chunk)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lparser.c
