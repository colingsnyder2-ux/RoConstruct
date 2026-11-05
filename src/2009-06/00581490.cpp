// from server: 100% by auto
// roc 2009-06 00581490  unit: seg_00580000  size: 336 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00581490
//
// 00581490  51                   push ecx
// 00581491  53                   push ebx
// 00581492  8b5c240c             mov ebx, dword ptr [esp + 0xc]
// 00581496  85db                 test ebx, ebx
// 00581498  0f843f010000         je 0x5815dd
// 0058149e  55                   push ebp
// 0058149f  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 005814a3  85ed                 test ebp, ebp
// 005814a5  0f8431010000         je 0x5815dc
// 005814ab  57                   push edi
// 005814ac  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 005814b0  85ff                 test edi, edi
// 005814b2  0f8423010000         je 0x5815db
// 005814b8  8b85c0000000         mov eax, dword ptr [ebp + 0xc0]
// 005814be  03c7                 add eax, edi
// 005814c0  8d0480               lea eax, [eax + eax*4]
// 005814c3  03c0                 add eax, eax
// 005814c5  56                   push esi
// 005814c6  03c0                 add eax, eax
// 005814c8  50                   push eax
// 005814c9  53                   push ebx
// 005814ca  e811d80000           call 0x58ece0
// 005814cf  8bf0                 mov esi, eax
// 005814d1  83c408               add esp, 8
// 005814d4  89742410             mov dword ptr [esp + 0x10], esi
// 005814d8  85f6                 test esi, esi
// 005814da  7514                 jne 0x5814f0
// 005814dc  68e8c88c00           push 0x8cc8e8
// 005814e1  53                   push ebx
// 005814e2  e829cd0000           call 0x58e210
// 005814e7  83c408               add esp, 8
// 005814ea  5e                   pop esi
// 005814eb  5f                   pop edi
// 005814ec  5d                   pop ebp
// 005814ed  5b                   pop ebx
// 005814ee  59                   pop ecx
// 005814ef  c3                   ret 
// 005814f0  8b85c0000000         mov eax, dword ptr [ebp + 0xc0]
// 005814f6  8b95bc000000         mov edx, dword ptr [ebp + 0xbc]
// 005814fc  8d0c80               lea ecx, [eax + eax*4]
// 005814ff  03c9                 add ecx, ecx
// 00581501  03c9                 add ecx, ecx
// 00581503  51                   push ecx
// 00581504  52                   push edx
// 00581505  56                   push esi
// 00581506  e8ab891900           call 0x719eb6
// 0058150b  8b85bc000000         mov eax, dword ptr [ebp + 0xbc]
// 00581511  50                   push eax
// 00581512  53                   push ebx
// 00581513  e898d70000           call 0x58ecb0
// 00581518  33c9                 xor ecx, ecx
// 0058151a  83c414               add esp, 0x14
// 0058151d  3bf9                 cmp edi, ecx
// 0058151f  898dbc000000         mov dword ptr [ebp + 0xbc], ecx
// 00581525  894c2418             mov dword ptr [esp + 0x18], ecx
// 00581529  0f8e95000000         jle 0x5815c4
// 0058152f  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00581533  83c70c               add edi, 0xc
// 00581536  eb08                 jmp 0x581540
// 00581538  8da42400000000       lea esp, [esp]
// 0058153f  90                   nop 
// 00581540  8b85c0000000         mov eax, dword ptr [ebp + 0xc0]
// 00581546  8b57f4               mov edx, dword ptr [edi - 0xc]
// 00581549  03c1                 add eax, ecx
// 0058154b  8d0c80               lea ecx, [eax + eax*4]
// 0058154e  8d348e               lea esi, [esi + ecx*4]
// 00581551  8916                 mov dword ptr [esi], edx
// 00581553  c6460400             mov byte ptr [esi + 4], 0
// 00581557  8b0f                 mov ecx, dword ptr [edi]
// 00581559  894e0c               mov dword ptr [esi + 0xc], ecx
// 0058155c  8a5368               mov dl, byte ptr [ebx + 0x68]
// 0058155f  885610               mov byte ptr [esi + 0x10], dl
// 00581562  833f00               cmp dword ptr [edi], 0
// 00581565  7509                 jne 0x581570
// 00581567  c7460800000000       mov dword ptr [esi + 8], 0
// 0058156e  eb3a                 jmp 0x5815aa
// 00581570  8b07                 mov eax, dword ptr [edi]
// 00581572  50                   push eax
// 00581573  53                   push ebx
// 00581574  e867d70000           call 0x58ece0
// 00581579  83c408               add esp, 8
// 0058157c  894608               mov dword ptr [esi + 8], eax
// 0058157f  85c0                 test eax, eax
// 00581581  7517                 jne 0x58159a
// 00581583  68e8c88c00           push 0x8cc8e8
// 00581588  53                   push ebx
// 00581589  e882cc0000           call 0x58e210
// 0058158e  83c408               add esp, 8
// 00581591  c7460c00000000       mov dword ptr [esi + 0xc], 0
// 00581598  eb10                 jmp 0x5815aa
// 0058159a  8b0f                 mov ecx, dword ptr [edi]
// 0058159c  8b57fc               mov edx, dword ptr [edi - 4]
// 0058159f  51                   push ecx
// 005815a0  52                   push edx
// 005815a1  50                   push eax
// 005815a2  e80f891900           call 0x719eb6
// 005815a7  83c40c               add esp, 0xc
// 005815aa  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 005815ae  8b742410             mov esi, dword ptr [esp + 0x10]
// 005815b2  41                   inc ecx
// 005815b3  83c714               add edi, 0x14
// 005815b6  3b4c2424             cmp ecx, dword ptr [esp + 0x24]
// 005815ba  894c2418             mov dword ptr [esp + 0x18], ecx
// 005815be  7c80                 jl 0x581540
// 005815c0  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 005815c4  01bdc0000000         add dword ptr [ebp + 0xc0], edi
// 005815ca  818db800000000020000 or dword ptr [ebp + 0xb8], 0x200
// 005815d4  89b5bc000000         mov dword ptr [ebp + 0xbc], esi
// 005815da  5e                   pop esi
// 005815db  5f                   pop edi
// 005815dc  5d                   pop ebp
// 005815dd  5b                   pop ebx
// 005815de  59                   pop ecx
// 005815df  c3                   ret 
// library libpng-1.2.29/pngset.c (function _png_set_unknown_chunks)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.29 pngset.c
