// from server: 100% by auto
// roc 2007-03 005fc680  unit: seg_005f0000  size: 148 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005fc680
//
// 005fc680  55                   push ebp
// 005fc681  8b6c240c             mov ebp, dword ptr [esp + 0xc]
// 005fc685  8d4701               lea eax, [edi + 1]
// 005fc688  83f8ed               cmp eax, -0x13
// 005fc68b  56                   push esi
// 005fc68c  7609                 jbe 0x5fc697
// 005fc68e  53                   push ebx
// 005fc68f  e8ec0c0000           call 0x5fd380
// 005fc694  83c404               add esp, 4
// 005fc697  8d4f11               lea ecx, [edi + 0x11]
// 005fc69a  51                   push ecx
// 005fc69b  6a00                 push 0
// 005fc69d  6a00                 push 0
// 005fc69f  53                   push ebx
// 005fc6a0  e8fb0c0000           call 0x5fd3a0
// 005fc6a5  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 005fc6a9  8bf0                 mov esi, eax
// 005fc6ab  897e0c               mov dword ptr [esi + 0xc], edi
// 005fc6ae  896e08               mov dword ptr [esi + 8], ebp
// 005fc6b1  8b5310               mov edx, dword ptr [ebx + 0x10]
// 005fc6b4  8a4214               mov al, byte ptr [edx + 0x14]
// 005fc6b7  57                   push edi
// 005fc6b8  51                   push ecx
// 005fc6b9  8d5610               lea edx, [esi + 0x10]
// 005fc6bc  2403                 and al, 3
// 005fc6be  52                   push edx
// 005fc6bf  884605               mov byte ptr [esi + 5], al
// 005fc6c2  c6460404             mov byte ptr [esi + 4], 4
// 005fc6c6  c6460600             mov byte ptr [esi + 6], 0
// 005fc6ca  e8132b0200           call 0x61f1e2
// 005fc6cf  c6443e1000           mov byte ptr [esi + edi + 0x10], 0
// 005fc6d4  8b4310               mov eax, dword ptr [ebx + 0x10]
// 005fc6d7  8b4808               mov ecx, dword ptr [eax + 8]
// 005fc6da  8b10                 mov edx, dword ptr [eax]
// 005fc6dc  83e901               sub ecx, 1
// 005fc6df  23e9                 and ebp, ecx
// 005fc6e1  8b0caa               mov ecx, dword ptr [edx + ebp*4]
// 005fc6e4  890e                 mov dword ptr [esi], ecx
// 005fc6e6  8b10                 mov edx, dword ptr [eax]
// 005fc6e8  8934aa               mov dword ptr [edx + ebp*4], esi
// 005fc6eb  83400401             add dword ptr [eax + 4], 1
// 005fc6ef  8b4804               mov ecx, dword ptr [eax + 4]
// 005fc6f2  8b4008               mov eax, dword ptr [eax + 8]
// 005fc6f5  83c41c               add esp, 0x1c
// 005fc6f8  3bc8                 cmp ecx, eax
// 005fc6fa  7613                 jbe 0x5fc70f
// 005fc6fc  3dfeffff3f           cmp eax, 0x3ffffffe
// 005fc701  7f0c                 jg 0x5fc70f
// 005fc703  03c0                 add eax, eax
// 005fc705  50                   push eax
// 005fc706  53                   push ebx
// 005fc707  e8b4feffff           call 0x5fc5c0
// 005fc70c  83c408               add esp, 8
// 005fc70f  8bc6                 mov eax, esi
// 005fc711  5e                   pop esi
// 005fc712  5d                   pop ebp
// 005fc713  c3                   ret 
// library lua-5.1.1/lstring.c (function _newlstr)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lstring.c
