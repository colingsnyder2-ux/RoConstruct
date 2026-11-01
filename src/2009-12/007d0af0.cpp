// from server: 100% by auto
// roc 2009-12 007d0af0  unit: RBX::PartDropTool  size: 145 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007d0af0
//
// 007d0af0  55                   push ebp
// 007d0af1  8b6c240c             mov ebp, dword ptr [esp + 0xc]
// 007d0af5  8d4701               lea eax, [edi + 1]
// 007d0af8  56                   push esi
// 007d0af9  83f8ed               cmp eax, -0x13
// 007d0afc  7609                 jbe 0x7d0b07
// 007d0afe  53                   push ebx
// 007d0aff  e88c0c0000           call 0x7d1790
// 007d0b04  83c404               add esp, 4
// 007d0b07  8d4f11               lea ecx, [edi + 0x11]
// 007d0b0a  51                   push ecx
// 007d0b0b  6a00                 push 0
// 007d0b0d  6a00                 push 0
// 007d0b0f  53                   push ebx
// 007d0b10  e89b0c0000           call 0x7d17b0
// 007d0b15  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 007d0b19  8bf0                 mov esi, eax
// 007d0b1b  897e0c               mov dword ptr [esi + 0xc], edi
// 007d0b1e  896e08               mov dword ptr [esi + 8], ebp
// 007d0b21  8b5310               mov edx, dword ptr [ebx + 0x10]
// 007d0b24  8a4214               mov al, byte ptr [edx + 0x14]
// 007d0b27  57                   push edi
// 007d0b28  51                   push ecx
// 007d0b29  8d5610               lea edx, [esi + 0x10]
// 007d0b2c  2403                 and al, 3
// 007d0b2e  52                   push edx
// 007d0b2f  884605               mov byte ptr [esi + 5], al
// 007d0b32  c6460404             mov byte ptr [esi + 4], 4
// 007d0b36  c6460600             mov byte ptr [esi + 6], 0
// 007d0b3a  e8a7410200           call 0x7f4ce6
// 007d0b3f  c6443e1000           mov byte ptr [esi + edi + 0x10], 0
// 007d0b44  8b4310               mov eax, dword ptr [ebx + 0x10]
// 007d0b47  8b4808               mov ecx, dword ptr [eax + 8]
// 007d0b4a  8b10                 mov edx, dword ptr [eax]
// 007d0b4c  49                   dec ecx
// 007d0b4d  23e9                 and ebp, ecx
// 007d0b4f  8b0caa               mov ecx, dword ptr [edx + ebp*4]
// 007d0b52  890e                 mov dword ptr [esi], ecx
// 007d0b54  8b10                 mov edx, dword ptr [eax]
// 007d0b56  8934aa               mov dword ptr [edx + ebp*4], esi
// 007d0b59  ff4004               inc dword ptr [eax + 4]
// 007d0b5c  8b4804               mov ecx, dword ptr [eax + 4]
// 007d0b5f  8b4008               mov eax, dword ptr [eax + 8]
// 007d0b62  83c41c               add esp, 0x1c
// 007d0b65  3bc8                 cmp ecx, eax
// 007d0b67  7613                 jbe 0x7d0b7c
// 007d0b69  3dfeffff3f           cmp eax, 0x3ffffffe
// 007d0b6e  7f0c                 jg 0x7d0b7c
// 007d0b70  03c0                 add eax, eax
// 007d0b72  50                   push eax
// 007d0b73  53                   push ebx
// 007d0b74  e8b7feffff           call 0x7d0a30
// 007d0b79  83c408               add esp, 8
// 007d0b7c  8bc6                 mov eax, esi
// 007d0b7e  5e                   pop esi
// 007d0b7f  5d                   pop ebp
// 007d0b80  c3                   ret 
// library lua-5.1/lstring.c (function _newlstr)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lstring.c
