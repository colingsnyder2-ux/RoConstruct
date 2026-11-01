// from server: 100% by auto
// roc 2009-12 007ce0d0  unit: RBX::PartDropTool  size: 144 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007ce0d0
//
// 007ce0d0  53                   push ebx
// 007ce0d1  8b5c2408             mov ebx, dword ptr [esp + 8]
// 007ce0d5  55                   push ebp
// 007ce0d6  8b2b                 mov ebp, dword ptr [ebx]
// 007ce0d8  57                   push edi
// 007ce0d9  8bf8                 mov edi, eax
// 007ce0db  8b4608               mov eax, dword ptr [esi + 8]
// 007ce0de  8928                 mov dword ptr [eax], ebp
// 007ce0e0  8b6b04               mov ebp, dword ptr [ebx + 4]
// 007ce0e3  896804               mov dword ptr [eax + 4], ebp
// 007ce0e6  8b5b08               mov ebx, dword ptr [ebx + 8]
// 007ce0e9  895808               mov dword ptr [eax + 8], ebx
// 007ce0ec  8b1f                 mov ebx, dword ptr [edi]
// 007ce0ee  8b4608               mov eax, dword ptr [esi + 8]
// 007ce0f1  895810               mov dword ptr [eax + 0x10], ebx
// 007ce0f4  8b5f04               mov ebx, dword ptr [edi + 4]
// 007ce0f7  895814               mov dword ptr [eax + 0x14], ebx
// 007ce0fa  8b7f08               mov edi, dword ptr [edi + 8]
// 007ce0fd  897818               mov dword ptr [eax + 0x18], edi
// 007ce100  8b3a                 mov edi, dword ptr [edx]
// 007ce102  83c010               add eax, 0x10
// 007ce105  8b4608               mov eax, dword ptr [esi + 8]
// 007ce108  897820               mov dword ptr [eax + 0x20], edi
// 007ce10b  8b7a04               mov edi, dword ptr [edx + 4]
// 007ce10e  897824               mov dword ptr [eax + 0x24], edi
// 007ce111  8b5208               mov edx, dword ptr [edx + 8]
// 007ce114  83c020               add eax, 0x20
// 007ce117  895008               mov dword ptr [eax + 8], edx
// 007ce11a  8b4608               mov eax, dword ptr [esi + 8]
// 007ce11d  8b11                 mov edx, dword ptr [ecx]
// 007ce11f  83c030               add eax, 0x30
// 007ce122  8910                 mov dword ptr [eax], edx
// 007ce124  8b5104               mov edx, dword ptr [ecx + 4]
// 007ce127  895004               mov dword ptr [eax + 4], edx
// 007ce12a  8b4908               mov ecx, dword ptr [ecx + 8]
// 007ce12d  894808               mov dword ptr [eax + 8], ecx
// 007ce130  8b561c               mov edx, dword ptr [esi + 0x1c]
// 007ce133  2b5608               sub edx, dword ptr [esi + 8]
// 007ce136  5f                   pop edi
// 007ce137  83fa40               cmp edx, 0x40
// 007ce13a  5d                   pop ebp
// 007ce13b  5b                   pop ebx
// 007ce13c  7f0b                 jg 0x7ce149
// 007ce13e  6a04                 push 4
// 007ce140  56                   push esi
// 007ce141  e8ea91fcff           call 0x797330
// 007ce146  83c408               add esp, 8
// 007ce149  83460840             add dword ptr [esi + 8], 0x40
// 007ce14d  8b4608               mov eax, dword ptr [esi + 8]
// 007ce150  6a00                 push 0
// 007ce152  83c0c0               add eax, -0x40
// 007ce155  50                   push eax
// 007ce156  56                   push esi
// 007ce157  e8a499fcff           call 0x797b00
// 007ce15c  83c40c               add esp, 0xc
// 007ce15f  c3                   ret 
// library lua-5.1/lvm.c (function _callTM)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lvm.c
