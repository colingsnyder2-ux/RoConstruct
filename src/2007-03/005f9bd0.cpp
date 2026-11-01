// from server: 100% by auto
// roc 2007-03 005f9bd0  unit: seg_005f0000  size: 158 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005f9bd0
//
// 005f9bd0  53                   push ebx
// 005f9bd1  55                   push ebp
// 005f9bd2  56                   push esi
// 005f9bd3  8b742410             mov esi, dword ptr [esp + 0x10]
// 005f9bd7  2b4620               sub eax, dword ptr [esi + 0x20]
// 005f9bda  57                   push edi
// 005f9bdb  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 005f9bdf  8b2f                 mov ebp, dword ptr [edi]
// 005f9be1  8bd8                 mov ebx, eax
// 005f9be3  8b4608               mov eax, dword ptr [esi + 8]
// 005f9be6  8928                 mov dword ptr [eax], ebp
// 005f9be8  8b6f04               mov ebp, dword ptr [edi + 4]
// 005f9beb  896804               mov dword ptr [eax + 4], ebp
// 005f9bee  8b7f08               mov edi, dword ptr [edi + 8]
// 005f9bf1  897808               mov dword ptr [eax + 8], edi
// 005f9bf4  8b3a                 mov edi, dword ptr [edx]
// 005f9bf6  8b4608               mov eax, dword ptr [esi + 8]
// 005f9bf9  897810               mov dword ptr [eax + 0x10], edi
// 005f9bfc  8b7a04               mov edi, dword ptr [edx + 4]
// 005f9bff  83c010               add eax, 0x10
// 005f9c02  897804               mov dword ptr [eax + 4], edi
// 005f9c05  8b5208               mov edx, dword ptr [edx + 8]
// 005f9c08  895008               mov dword ptr [eax + 8], edx
// 005f9c0b  8b4608               mov eax, dword ptr [esi + 8]
// 005f9c0e  8b11                 mov edx, dword ptr [ecx]
// 005f9c10  83c020               add eax, 0x20
// 005f9c13  8910                 mov dword ptr [eax], edx
// 005f9c15  8b5104               mov edx, dword ptr [ecx + 4]
// 005f9c18  895004               mov dword ptr [eax + 4], edx
// 005f9c1b  8b4908               mov ecx, dword ptr [ecx + 8]
// 005f9c1e  894808               mov dword ptr [eax + 8], ecx
// 005f9c21  8b561c               mov edx, dword ptr [esi + 0x1c]
// 005f9c24  2b5608               sub edx, dword ptr [esi + 8]
// 005f9c27  83fa30               cmp edx, 0x30
// 005f9c2a  7f0b                 jg 0x5f9c37
// 005f9c2c  6a03                 push 3
// 005f9c2e  56                   push esi
// 005f9c2f  e8bc60fcff           call 0x5bfcf0
// 005f9c34  83c408               add esp, 8
// 005f9c37  83460830             add dword ptr [esi + 8], 0x30
// 005f9c3b  8b4608               mov eax, dword ptr [esi + 8]
// 005f9c3e  6a01                 push 1
// 005f9c40  83c0d0               add eax, -0x30
// 005f9c43  50                   push eax
// 005f9c44  56                   push esi
// 005f9c45  e86668fcff           call 0x5c04b0
// 005f9c4a  834608f0             add dword ptr [esi + 8], -0x10
// 005f9c4e  8b4608               mov eax, dword ptr [esi + 8]
// 005f9c51  8b7620               mov esi, dword ptr [esi + 0x20]
// 005f9c54  8b08                 mov ecx, dword ptr [eax]
// 005f9c56  03f3                 add esi, ebx
// 005f9c58  890e                 mov dword ptr [esi], ecx
// 005f9c5a  8b5004               mov edx, dword ptr [eax + 4]
// 005f9c5d  83c40c               add esp, 0xc
// 005f9c60  895604               mov dword ptr [esi + 4], edx
// 005f9c63  8b4008               mov eax, dword ptr [eax + 8]
// 005f9c66  5f                   pop edi
// 005f9c67  894608               mov dword ptr [esi + 8], eax
// 005f9c6a  5e                   pop esi
// 005f9c6b  5d                   pop ebp
// 005f9c6c  5b                   pop ebx
// 005f9c6d  c3                   ret 
// library lua-5.1.1/lvm.c (function _callTMres)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lvm.c
