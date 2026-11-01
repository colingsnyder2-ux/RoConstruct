// from server: 100% by auto
// roc 2007-03 005f8aa0  unit: seg_005f0000  size: 145 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005f8aa0
//
// 005f8aa0  8b442404             mov eax, dword ptr [esp + 4]
// 005f8aa4  53                   push ebx
// 005f8aa5  55                   push ebp
// 005f8aa6  8b6810               mov ebp, dword ptr [eax + 0x10]
// 005f8aa9  56                   push esi
// 005f8aaa  57                   push edi
// 005f8aab  8b7d70               mov edi, dword ptr [ebp + 0x70]
// 005f8aae  8b37                 mov esi, dword ptr [edi]
// 005f8ab0  33db                 xor ebx, ebx
// 005f8ab2  85f6                 test esi, esi
// 005f8ab4  7474                 je 0x5f8b2a
// 005f8ab6  8a4605               mov al, byte ptr [esi + 5]
// 005f8ab9  a803                 test al, 3
// 005f8abb  7507                 jne 0x5f8ac4
// 005f8abd  837c241800           cmp dword ptr [esp + 0x18], 0
// 005f8ac2  7404                 je 0x5f8ac8
// 005f8ac4  a808                 test al, 8
// 005f8ac6  7404                 je 0x5f8acc
// 005f8ac8  8bfe                 mov edi, esi
// 005f8aca  eb58                 jmp 0x5f8b24
// 005f8acc  8b4608               mov eax, dword ptr [esi + 8]
// 005f8acf  85c0                 test eax, eax
// 005f8ad1  7423                 je 0x5f8af6
// 005f8ad3  f6400604             test byte ptr [eax + 6], 4
// 005f8ad7  751d                 jne 0x5f8af6
// 005f8ad9  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 005f8add  8b5110               mov edx, dword ptr [ecx + 0x10]
// 005f8ae0  8b8ac4000000         mov ecx, dword ptr [edx + 0xc4]
// 005f8ae6  51                   push ecx
// 005f8ae7  6a02                 push 2
// 005f8ae9  50                   push eax
// 005f8aea  e8010f0000           call 0x5f99f0
// 005f8aef  83c40c               add esp, 0xc
// 005f8af2  85c0                 test eax, eax
// 005f8af4  7508                 jne 0x5f8afe
// 005f8af6  804e0508             or byte ptr [esi + 5], 8
// 005f8afa  8bfe                 mov edi, esi
// 005f8afc  eb26                 jmp 0x5f8b24
// 005f8afe  804e0508             or byte ptr [esi + 5], 8
// 005f8b02  8b06                 mov eax, dword ptr [esi]
// 005f8b04  8b5610               mov edx, dword ptr [esi + 0x10]
// 005f8b07  8907                 mov dword ptr [edi], eax
// 005f8b09  8b4530               mov eax, dword ptr [ebp + 0x30]
// 005f8b0c  85c0                 test eax, eax
// 005f8b0e  8d5c1318             lea ebx, [ebx + edx + 0x18]
// 005f8b12  7504                 jne 0x5f8b18
// 005f8b14  8936                 mov dword ptr [esi], esi
// 005f8b16  eb09                 jmp 0x5f8b21
// 005f8b18  8b08                 mov ecx, dword ptr [eax]
// 005f8b1a  890e                 mov dword ptr [esi], ecx
// 005f8b1c  8b5530               mov edx, dword ptr [ebp + 0x30]
// 005f8b1f  8932                 mov dword ptr [edx], esi
// 005f8b21  897530               mov dword ptr [ebp + 0x30], esi
// 005f8b24  8b37                 mov esi, dword ptr [edi]
// 005f8b26  85f6                 test esi, esi
// 005f8b28  758c                 jne 0x5f8ab6
// 005f8b2a  5f                   pop edi
// 005f8b2b  5e                   pop esi
// 005f8b2c  5d                   pop ebp
// 005f8b2d  8bc3                 mov eax, ebx
// 005f8b2f  5b                   pop ebx
// 005f8b30  c3                   ret 
// library lua-5.1.1/lgc.c (function _luaC_separateudata)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lgc.c
