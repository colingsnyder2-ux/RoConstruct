// from server: 100% by auto
// roc 2009-06 006c6200  unit: lua_exception  size: 256 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006c6200
//
// 006c6200  53                   push ebx
// 006c6201  55                   push ebp
// 006c6202  56                   push esi
// 006c6203  8bf1                 mov esi, ecx
// 006c6205  8b6e08               mov ebp, dword ptr [esi + 8]
// 006c6208  6a03                 push 3
// 006c620a  55                   push ebp
// 006c620b  8bd8                 mov ebx, eax
// 006c620d  e85e2dffff           call 0x6b8f70
// 006c6212  83c0fd               add eax, -3
// 006c6215  83c408               add esp, 8
// 006c6218  83f803               cmp eax, 3
// 006c621b  775c                 ja 0x6c6279
// 006c621d  ff2485f0626c00       jmp dword ptr [eax*4 + 0x6c62f0]
// 006c6224  8b442414             mov eax, dword ptr [esp + 0x14]
// 006c6228  53                   push ebx
// 006c6229  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 006c622d  50                   push eax
// 006c622e  8bc6                 mov eax, esi
// 006c6230  e8ebfeffff           call 0x6c6120
// 006c6235  83c408               add esp, 8
// 006c6238  5e                   pop esi
// 006c6239  5d                   pop ebp
// 006c623a  5b                   pop ebx
// 006c623b  c3                   ret 
// 006c623c  6a03                 push 3
// 006c623e  55                   push ebp
// 006c623f  e8fc2cffff           call 0x6b8f40
// 006c6244  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 006c6248  53                   push ebx
// 006c6249  51                   push ecx
// 006c624a  8bc6                 mov eax, esi
// 006c624c  e8dffaffff           call 0x6c5d30
// 006c6251  6a01                 push 1
// 006c6253  50                   push eax
// 006c6254  55                   push ebp
// 006c6255  e84638ffff           call 0x6b9aa0
// 006c625a  83c41c               add esp, 0x1c
// 006c625d  eb1a                 jmp 0x6c6279
// 006c625f  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 006c6263  57                   push edi
// 006c6264  8bc3                 mov eax, ebx
// 006c6266  33ff                 xor edi, edi
// 006c6268  e843faffff           call 0x6c5cb0
// 006c626d  6a03                 push 3
// 006c626f  55                   push ebp
// 006c6270  e82b33ffff           call 0x6b95a0
// 006c6275  83c408               add esp, 8
// 006c6278  5f                   pop edi
// 006c6279  6aff                 push -1
// 006c627b  55                   push ebp
// 006c627c  e8cf2effff           call 0x6b9150
// 006c6281  83c408               add esp, 8
// 006c6284  85c0                 test eax, eax
// 006c6286  752a                 jne 0x6c62b2
// 006c6288  6afe                 push -2
// 006c628a  55                   push ebp
// 006c628b  e8002bffff           call 0x6b8d90
// 006c6290  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006c6294  2bd8                 sub ebx, eax
// 006c6296  53                   push ebx
// 006c6297  50                   push eax
// 006c6298  55                   push ebp
// 006c6299  e8e230ffff           call 0x6b9380
// 006c629e  8b542424             mov edx, dword ptr [esp + 0x24]
// 006c62a2  83c414               add esp, 0x14
// 006c62a5  52                   push edx
// 006c62a6  e85543ffff           call 0x6ba600
// 006c62ab  83c404               add esp, 4
// 006c62ae  5e                   pop esi
// 006c62af  5d                   pop ebp
// 006c62b0  5b                   pop ebx
// 006c62b1  c3                   ret 
// 006c62b2  6aff                 push -1
// 006c62b4  55                   push ebp
// 006c62b5  e8662dffff           call 0x6b9020
// 006c62ba  83c408               add esp, 8
// 006c62bd  85c0                 test eax, eax
// 006c62bf  751e                 jne 0x6c62df
// 006c62c1  6aff                 push -1
// 006c62c3  55                   push ebp
// 006c62c4  e8a72cffff           call 0x6b8f70
// 006c62c9  50                   push eax
// 006c62ca  55                   push ebp
// 006c62cb  e8c02cffff           call 0x6b8f90
// 006c62d0  50                   push eax
// 006c62d1  6898bc8e00           push 0x8ebc98
// 006c62d6  55                   push ebp
// 006c62d7  e8643fffff           call 0x6ba240
// 006c62dc  83c41c               add esp, 0x1c
// 006c62df  8b542410             mov edx, dword ptr [esp + 0x10]
// 006c62e3  52                   push edx
// 006c62e4  e81743ffff           call 0x6ba600
// 006c62e9  83c404               add esp, 4
// 006c62ec  5e                   pop esi
// 006c62ed  5d                   pop ebp
// 006c62ee  5b                   pop ebx
// 006c62ef  c3                   ret 
// 006c62f0  2462                 and al, 0x62
// 006c62f2  6c                   insb byte ptr es:[edi], dx
// 006c62f3  002462               add byte ptr [edx], ah
// 006c62f6  6c                   insb byte ptr es:[edi], dx
// 006c62f7  005f62               add byte ptr [edi + 0x62], bl
// 006c62fa  6c                   insb byte ptr es:[edi], dx
// 006c62fb  003c62               add byte ptr [edx], bh
// 006c62fe  6c                   insb byte ptr es:[edi], dx
// library lua-5.1.3/lstrlib.c (function _add_value)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.3 lstrlib.c
