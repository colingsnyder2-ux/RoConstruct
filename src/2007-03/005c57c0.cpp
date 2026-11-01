// from server: 100% by auto
// roc 2007-03 005c57c0  unit: seg_005c0000  size: 75 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c57c0
//
// 005c57c0  53                   push ebx
// 005c57c1  55                   push ebp
// 005c57c2  8b6c240c             mov ebp, dword ptr [esp + 0xc]
// 005c57c6  56                   push esi
// 005c57c7  8bf0                 mov esi, eax
// 005c57c9  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 005c57cc  85db                 test ebx, ebx
// 005c57ce  57                   push edi
// 005c57cf  7509                 jne 0x5c57da
// 005c57d1  85ed                 test ebp, ebp
// 005c57d3  7405                 je 0x5c57da
// 005c57d5  bb01000000           mov ebx, 1
// 005c57da  8b4608               mov eax, dword ptr [esi + 8]
// 005c57dd  68f09f7b00           push 0x7b9ff0
// 005c57e2  53                   push ebx
// 005c57e3  50                   push eax
// 005c57e4  e8f743ffff           call 0x5b9be0
// 005c57e9  83c40c               add esp, 0xc
// 005c57ec  33ff                 xor edi, edi
// 005c57ee  85db                 test ebx, ebx
// 005c57f0  7e12                 jle 0x5c5804
// 005c57f2  8b442418             mov eax, dword ptr [esp + 0x18]
// 005c57f6  8bcd                 mov ecx, ebp
// 005c57f8  e843ffffff           call 0x5c5740
// 005c57fd  83c701               add edi, 1
// 005c5800  3bfb                 cmp edi, ebx
// 005c5802  7cee                 jl 0x5c57f2
// 005c5804  5f                   pop edi
// 005c5805  5e                   pop esi
// 005c5806  5d                   pop ebp
// 005c5807  8bc3                 mov eax, ebx
// 005c5809  5b                   pop ebx
// 005c580a  c3                   ret 
// library lua-5.1.1/lstrlib.c (function _push_captures)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lstrlib.c
