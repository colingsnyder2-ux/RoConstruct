// from server: 100% by auto
// roc 2009-12 00602b00  unit: seg_00600000  size: 181 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00602b00
//
// 00602b00  57                   push edi
// 00602b01  8b7c2408             mov edi, dword ptr [esp + 8]
// 00602b05  85ff                 test edi, edi
// 00602b07  0f84a6000000         je 0x602bb3
// 00602b0d  56                   push esi
// 00602b0e  8b742410             mov esi, dword ptr [esp + 0x10]
// 00602b12  85f6                 test esi, esi
// 00602b14  0f8498000000         je 0x602bb2
// 00602b1a  53                   push ebx
// 00602b1b  8b5c241c             mov ebx, dword ptr [esp + 0x1c]
// 00602b1f  85db                 test ebx, ebx
// 00602b21  7c08                 jl 0x602b2b
// 00602b23  81fb00010000         cmp ebx, 0x100
// 00602b29  7e14                 jle 0x602b3f
// 00602b2b  807e1903             cmp byte ptr [esi + 0x19], 3
// 00602b2f  6834369c00           push 0x9c3634
// 00602b34  57                   push edi
// 00602b35  7572                 jne 0x602ba9
// 00602b37  e854d60000           call 0x610190
// 00602b3c  83c408               add esp, 8
// 00602b3f  6a00                 push 0
// 00602b41  6800100000           push 0x1000
// 00602b46  56                   push esi
// 00602b47  57                   push edi
// 00602b48  e8730b0000           call 0x6036c0
// 00602b4d  6800030000           push 0x300
// 00602b52  57                   push edi
// 00602b53  e828e10000           call 0x610c80
// 00602b58  6800030000           push 0x300
// 00602b5d  6a00                 push 0
// 00602b5f  50                   push eax
// 00602b60  898714010000         mov dword ptr [edi + 0x114], eax
// 00602b66  e8391f1f00           call 0x7f4aa4
// 00602b6b  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 00602b6f  8b9714010000         mov edx, dword ptr [edi + 0x114]
// 00602b75  8d045b               lea eax, [ebx + ebx*2]
// 00602b78  50                   push eax
// 00602b79  51                   push ecx
// 00602b7a  52                   push edx
// 00602b7b  e866211f00           call 0x7f4ce6
// 00602b80  8b8714010000         mov eax, dword ptr [edi + 0x114]
// 00602b86  83c430               add esp, 0x30
// 00602b89  894610               mov dword ptr [esi + 0x10], eax
// 00602b8c  66899f18010000       mov word ptr [edi + 0x118], bx
// 00602b93  818eb800000000100000 or dword ptr [esi + 0xb8], 0x1000
// 00602b9d  834e0808             or dword ptr [esi + 8], 8
// 00602ba1  66895e14             mov word ptr [esi + 0x14], bx
// 00602ba5  5b                   pop ebx
// 00602ba6  5e                   pop esi
// 00602ba7  5f                   pop edi
// 00602ba8  c3                   ret 
// 00602ba9  e892d60000           call 0x610240
// 00602bae  83c408               add esp, 8
// 00602bb1  5b                   pop ebx
// 00602bb2  5e                   pop esi
// 00602bb3  5f                   pop edi
// 00602bb4  c3                   ret 
// library libpng-1.2.10/pngset.c (function _png_set_PLTE)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.10 pngset.c
