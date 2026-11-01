// from server: 100% by auto
// roc 2009-12 007ce030  unit: RBX::PartDropTool  size: 158 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007ce030
//
// 007ce030  53                   push ebx
// 007ce031  55                   push ebp
// 007ce032  56                   push esi
// 007ce033  8b742410             mov esi, dword ptr [esp + 0x10]
// 007ce037  2b4620               sub eax, dword ptr [esi + 0x20]
// 007ce03a  57                   push edi
// 007ce03b  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 007ce03f  8b2f                 mov ebp, dword ptr [edi]
// 007ce041  8bd8                 mov ebx, eax
// 007ce043  8b4608               mov eax, dword ptr [esi + 8]
// 007ce046  8928                 mov dword ptr [eax], ebp
// 007ce048  8b6f04               mov ebp, dword ptr [edi + 4]
// 007ce04b  896804               mov dword ptr [eax + 4], ebp
// 007ce04e  8b7f08               mov edi, dword ptr [edi + 8]
// 007ce051  897808               mov dword ptr [eax + 8], edi
// 007ce054  8b3a                 mov edi, dword ptr [edx]
// 007ce056  8b4608               mov eax, dword ptr [esi + 8]
// 007ce059  897810               mov dword ptr [eax + 0x10], edi
// 007ce05c  8b7a04               mov edi, dword ptr [edx + 4]
// 007ce05f  83c010               add eax, 0x10
// 007ce062  897804               mov dword ptr [eax + 4], edi
// 007ce065  8b5208               mov edx, dword ptr [edx + 8]
// 007ce068  895008               mov dword ptr [eax + 8], edx
// 007ce06b  8b4608               mov eax, dword ptr [esi + 8]
// 007ce06e  8b11                 mov edx, dword ptr [ecx]
// 007ce070  83c020               add eax, 0x20
// 007ce073  8910                 mov dword ptr [eax], edx
// 007ce075  8b5104               mov edx, dword ptr [ecx + 4]
// 007ce078  895004               mov dword ptr [eax + 4], edx
// 007ce07b  8b4908               mov ecx, dword ptr [ecx + 8]
// 007ce07e  894808               mov dword ptr [eax + 8], ecx
// 007ce081  8b561c               mov edx, dword ptr [esi + 0x1c]
// 007ce084  2b5608               sub edx, dword ptr [esi + 8]
// 007ce087  83fa30               cmp edx, 0x30
// 007ce08a  7f0b                 jg 0x7ce097
// 007ce08c  6a03                 push 3
// 007ce08e  56                   push esi
// 007ce08f  e89c92fcff           call 0x797330
// 007ce094  83c408               add esp, 8
// 007ce097  83460830             add dword ptr [esi + 8], 0x30
// 007ce09b  8b4608               mov eax, dword ptr [esi + 8]
// 007ce09e  6a01                 push 1
// 007ce0a0  83c0d0               add eax, -0x30
// 007ce0a3  50                   push eax
// 007ce0a4  56                   push esi
// 007ce0a5  e8569afcff           call 0x797b00
// 007ce0aa  834608f0             add dword ptr [esi + 8], -0x10
// 007ce0ae  8b4608               mov eax, dword ptr [esi + 8]
// 007ce0b1  8b7620               mov esi, dword ptr [esi + 0x20]
// 007ce0b4  8b08                 mov ecx, dword ptr [eax]
// 007ce0b6  03f3                 add esi, ebx
// 007ce0b8  890e                 mov dword ptr [esi], ecx
// 007ce0ba  8b5004               mov edx, dword ptr [eax + 4]
// 007ce0bd  83c40c               add esp, 0xc
// 007ce0c0  895604               mov dword ptr [esi + 4], edx
// 007ce0c3  8b4008               mov eax, dword ptr [eax + 8]
// 007ce0c6  5f                   pop edi
// 007ce0c7  894608               mov dword ptr [esi + 8], eax
// 007ce0ca  5e                   pop esi
// 007ce0cb  5d                   pop ebp
// 007ce0cc  5b                   pop ebx
// 007ce0cd  c3                   ret 
// library lua-5.1/lvm.c (function _callTMres)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lvm.c
