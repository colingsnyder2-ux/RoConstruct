// from server: 100% by auto
// roc 2009-12 007d26f0  unit: seg_007d0000  size: 323 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007d26f0
//
// 007d26f0  81ec3c020000         sub esp, 0x23c
// 007d26f6  53                   push ebx
// 007d26f7  55                   push ebp
// 007d26f8  8bac2450020000       mov ebp, dword ptr [esp + 0x250]
// 007d26ff  56                   push esi
// 007d2700  8bd8                 mov ebx, eax
// 007d2702  57                   push edi
// 007d2703  8d442410             lea eax, [esp + 0x10]
// 007d2707  e824f8ffff           call 0x7d1f30
// 007d270c  8b442410             mov eax, dword ptr [esp + 0x10]
// 007d2710  89683c               mov dword ptr [eax + 0x3c], ebp
// 007d2713  837b1028             cmp dword ptr [ebx + 0x10], 0x28
// 007d2717  7421                 je 0x7d273a
// 007d2719  6a28                 push 0x28
// 007d271b  53                   push ebx
// 007d271c  e81f2b0000           call 0x7d5240
// 007d2721  8b4b34               mov ecx, dword ptr [ebx + 0x34]
// 007d2724  50                   push eax
// 007d2725  68d0ed9e00           push 0x9eedd0
// 007d272a  51                   push ecx
// 007d272b  e8507efcff           call 0x79a580
// 007d2730  50                   push eax
// 007d2731  53                   push ebx
// 007d2732  e8092c0000           call 0x7d5340
// 007d2737  83c41c               add esp, 0x1c
// 007d273a  53                   push ebx
// 007d273b  e8f03f0000           call 0x7d6730
// 007d2740  83c404               add esp, 4
// 007d2743  83bc245402000000     cmp dword ptr [esp + 0x254], 0
// 007d274b  7468                 je 0x7d27b5
// 007d274d  6a04                 push 4
// 007d274f  6800ef9e00           push 0x9eef00
// 007d2754  53                   push ebx
// 007d2755  e8062c0000           call 0x7d5360
// 007d275a  8b7330               mov esi, dword ptr [ebx + 0x30]
// 007d275d  0fb65632             movzx edx, byte ptr [esi + 0x32]
// 007d2761  42                   inc edx
// 007d2762  83c40c               add esp, 0xc
// 007d2765  81fac8000000         cmp edx, 0xc8
// 007d276b  8bf8                 mov edi, eax
// 007d276d  7e0f                 jle 0x7d277e
// 007d276f  b974ee9e00           mov ecx, 0x9eee74
// 007d2774  bac8000000           mov edx, 0xc8
// 007d2779  e812f1ffff           call 0x7d1890
// 007d277e  57                   push edi
// 007d277f  53                   push ebx
// 007d2780  e84bf2ffff           call 0x7d19d0
// 007d2785  0fb64e32             movzx ecx, byte ptr [esi + 0x32]
// 007d2789  6689844eac000000     mov word ptr [esi + ecx*2 + 0xac], ax
// 007d2791  8b4330               mov eax, dword ptr [ebx + 0x30]
// 007d2794  83c408               add esp, 8
// 007d2797  fe4032               inc byte ptr [eax + 0x32]
// 007d279a  0fb65032             movzx edx, byte ptr [eax + 0x32]
// 007d279e  0fb78c50aa000000     movzx ecx, word ptr [eax + edx*2 + 0xaa]
// 007d27a6  8b10                 mov edx, dword ptr [eax]
// 007d27a8  8b5218               mov edx, dword ptr [edx + 0x18]
// 007d27ab  8b4018               mov eax, dword ptr [eax + 0x18]
// 007d27ae  8d0c49               lea ecx, [ecx + ecx*2]
// 007d27b1  89448a04             mov dword ptr [edx + ecx*4 + 4], eax
// 007d27b5  8bfb                 mov edi, ebx
// 007d27b7  e8f4fdffff           call 0x7d25b0
// 007d27bc  837b1029             cmp dword ptr [ebx + 0x10], 0x29
// 007d27c0  7421                 je 0x7d27e3
// 007d27c2  6a29                 push 0x29
// 007d27c4  53                   push ebx
// 007d27c5  e8762a0000           call 0x7d5240
// 007d27ca  8b4b34               mov ecx, dword ptr [ebx + 0x34]
// 007d27cd  50                   push eax
// 007d27ce  68d0ed9e00           push 0x9eedd0
// 007d27d3  51                   push ecx
// 007d27d4  e8a77dfcff           call 0x79a580
// 007d27d9  50                   push eax
// 007d27da  53                   push ebx
// 007d27db  e8602b0000           call 0x7d5340
// 007d27e0  83c41c               add esp, 0x1c
// 007d27e3  53                   push ebx
// 007d27e4  e8473f0000           call 0x7d6730
// 007d27e9  53                   push ebx
// 007d27ea  e8b11d0000           call 0x7d45a0
// 007d27ef  8b442418             mov eax, dword ptr [esp + 0x18]
// 007d27f3  8b5304               mov edx, dword ptr [ebx + 4]
// 007d27f6  895040               mov dword ptr [eax + 0x40], edx
// 007d27f9  6809010000           push 0x109
// 007d27fe  8bc5                 mov eax, ebp
// 007d2800  bf06010000           mov edi, 0x106
// 007d2805  8bf3                 mov esi, ebx
// 007d2807  e8d4f0ffff           call 0x7d18e0
// 007d280c  53                   push ebx
// 007d280d  e8cef7ffff           call 0x7d1fe0
// 007d2812  8b8c2460020000       mov ecx, dword ptr [esp + 0x260]
// 007d2819  51                   push ecx
// 007d281a  8d542424             lea edx, [esp + 0x24]
// 007d281e  52                   push edx
// 007d281f  53                   push ebx
// 007d2820  e80bf6ffff           call 0x7d1e30
// 007d2825  83c41c               add esp, 0x1c
// 007d2828  5f                   pop edi
// 007d2829  5e                   pop esi
// 007d282a  5d                   pop ebp
// 007d282b  5b                   pop ebx
// 007d282c  81c43c020000         add esp, 0x23c
// 007d2832  c3                   ret 
// library lua-5.1/lparser.c (function _body)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lparser.c
