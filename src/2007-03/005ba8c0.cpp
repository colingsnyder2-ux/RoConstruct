// from server: 100% by auto
// roc 2007-03 005ba8c0  unit: seg_005b0000  size: 171 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005ba8c0
//
// 005ba8c0  53                   push ebx
// 005ba8c1  55                   push ebp
// 005ba8c2  8b6c240c             mov ebp, dword ptr [esp + 0xc]
// 005ba8c6  56                   push esi
// 005ba8c7  8b742418             mov esi, dword ptr [esp + 0x18]
// 005ba8cb  85f6                 test esi, esi
// 005ba8cd  57                   push edi
// 005ba8ce  741b                 je 0x5ba8eb
// 005ba8d0  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 005ba8d4  57                   push edi
// 005ba8d5  55                   push ebp
// 005ba8d6  e865e3ffff           call 0x5b8c40
// 005ba8db  83c408               add esp, 8
// 005ba8de  85c0                 test eax, eax
// 005ba8e0  7f04                 jg 0x5ba8e6
// 005ba8e2  8bc6                 mov eax, esi
// 005ba8e4  eb15                 jmp 0x5ba8fb
// 005ba8e6  6a00                 push 0
// 005ba8e8  57                   push edi
// 005ba8e9  eb07                 jmp 0x5ba8f2
// 005ba8eb  8b442418             mov eax, dword ptr [esp + 0x18]
// 005ba8ef  6a00                 push 0
// 005ba8f1  50                   push eax
// 005ba8f2  55                   push ebp
// 005ba8f3  e8c8fcffff           call 0x5ba5c0
// 005ba8f8  83c40c               add esp, 0xc
// 005ba8fb  8b742420             mov esi, dword ptr [esp + 0x20]
// 005ba8ff  8b0e                 mov ecx, dword ptr [esi]
// 005ba901  33ff                 xor edi, edi
// 005ba903  85c9                 test ecx, ecx
// 005ba905  743d                 je 0x5ba944
// 005ba907  8bd0                 mov edx, eax
// 005ba909  8da42400000000       lea esp, [esp]
// 005ba910  8a19                 mov bl, byte ptr [ecx]
// 005ba912  3a1a                 cmp bl, byte ptr [edx]
// 005ba914  751a                 jne 0x5ba930
// 005ba916  84db                 test bl, bl
// 005ba918  7412                 je 0x5ba92c
// 005ba91a  8a5901               mov bl, byte ptr [ecx + 1]
// 005ba91d  3a5a01               cmp bl, byte ptr [edx + 1]
// 005ba920  750e                 jne 0x5ba930
// 005ba922  83c102               add ecx, 2
// 005ba925  83c202               add edx, 2
// 005ba928  84db                 test bl, bl
// 005ba92a  75e4                 jne 0x5ba910
// 005ba92c  33c9                 xor ecx, ecx
// 005ba92e  eb05                 jmp 0x5ba935
// 005ba930  1bc9                 sbb ecx, ecx
// 005ba932  83d9ff               sbb ecx, -1
// 005ba935  85c9                 test ecx, ecx
// 005ba937  742b                 je 0x5ba964
// 005ba939  8b4cbe04             mov ecx, dword ptr [esi + edi*4 + 4]
// 005ba93d  83c701               add edi, 1
// 005ba940  85c9                 test ecx, ecx
// 005ba942  75c3                 jne 0x5ba907
// 005ba944  50                   push eax
// 005ba945  6828927b00           push 0x7b9228
// 005ba94a  55                   push ebp
// 005ba94b  e810e8ffff           call 0x5b9160
// 005ba950  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 005ba954  50                   push eax
// 005ba955  51                   push ecx
// 005ba956  55                   push ebp
// 005ba957  e894faffff           call 0x5ba3f0
// 005ba95c  83c418               add esp, 0x18
// 005ba95f  5f                   pop edi
// 005ba960  5e                   pop esi
// 005ba961  5d                   pop ebp
// 005ba962  5b                   pop ebx
// 005ba963  c3                   ret 
// 005ba964  8bc7                 mov eax, edi
// 005ba966  5f                   pop edi
// 005ba967  5e                   pop esi
// 005ba968  5d                   pop ebp
// 005ba969  5b                   pop ebx
// 005ba96a  c3                   ret 
// library lua-5.1.1/lauxlib.c (function _luaL_checkoption)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lauxlib.c
