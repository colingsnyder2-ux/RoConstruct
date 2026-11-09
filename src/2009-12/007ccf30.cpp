// from server: 100% by auto
// roc 2009-12 007ccf30  unit: RBX::PartDropTool  size: 145 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007ccf30
//
// 007ccf30  8b442404             mov eax, dword ptr [esp + 4]
// 007ccf34  53                   push ebx
// 007ccf35  55                   push ebp
// 007ccf36  8b6810               mov ebp, dword ptr [eax + 0x10]
// 007ccf39  56                   push esi
// 007ccf3a  57                   push edi
// 007ccf3b  8b7d70               mov edi, dword ptr [ebp + 0x70]
// 007ccf3e  8b37                 mov esi, dword ptr [edi]
// 007ccf40  33db                 xor ebx, ebx
// 007ccf42  85f6                 test esi, esi
// 007ccf44  7474                 je 0x7ccfba
// 007ccf46  8a4605               mov al, byte ptr [esi + 5]
// 007ccf49  a803                 test al, 3
// 007ccf4b  7507                 jne 0x7ccf54
// 007ccf4d  837c241800           cmp dword ptr [esp + 0x18], 0
// 007ccf52  7404                 je 0x7ccf58
// 007ccf54  a808                 test al, 8
// 007ccf56  7404                 je 0x7ccf5c
// 007ccf58  8bfe                 mov edi, esi
// 007ccf5a  eb58                 jmp 0x7ccfb4
// 007ccf5c  8b4608               mov eax, dword ptr [esi + 8]
// 007ccf5f  85c0                 test eax, eax
// 007ccf61  7423                 je 0x7ccf86
// 007ccf63  f6400604             test byte ptr [eax + 6], 4
// 007ccf67  751d                 jne 0x7ccf86
// 007ccf69  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 007ccf6d  8b5110               mov edx, dword ptr [ecx + 0x10]
// 007ccf70  8b8ac4000000         mov ecx, dword ptr [edx + 0xc4]
// 007ccf76  51                   push ecx
// 007ccf77  6a02                 push 2
// 007ccf79  50                   push eax
// 007ccf7a  e8d10e0000           call 0x7cde50
// 007ccf7f  83c40c               add esp, 0xc
// 007ccf82  85c0                 test eax, eax
// 007ccf84  7508                 jne 0x7ccf8e
// 007ccf86  804e0508             or byte ptr [esi + 5], 8
// 007ccf8a  8bfe                 mov edi, esi
// 007ccf8c  eb26                 jmp 0x7ccfb4
// 007ccf8e  804e0508             or byte ptr [esi + 5], 8
// 007ccf92  8b06                 mov eax, dword ptr [esi]
// 007ccf94  8b5610               mov edx, dword ptr [esi + 0x10]
// 007ccf97  8907                 mov dword ptr [edi], eax
// 007ccf99  8b4530               mov eax, dword ptr [ebp + 0x30]
// 007ccf9c  8d5c1318             lea ebx, [ebx + edx + 0x18]
// 007ccfa0  85c0                 test eax, eax
// 007ccfa2  7504                 jne 0x7ccfa8
// 007ccfa4  8936                 mov dword ptr [esi], esi
// 007ccfa6  eb09                 jmp 0x7ccfb1
// 007ccfa8  8b08                 mov ecx, dword ptr [eax]
// 007ccfaa  890e                 mov dword ptr [esi], ecx
// 007ccfac  8b5530               mov edx, dword ptr [ebp + 0x30]
// 007ccfaf  8932                 mov dword ptr [edx], esi
// 007ccfb1  897530               mov dword ptr [ebp + 0x30], esi
// 007ccfb4  8b37                 mov esi, dword ptr [edi]
// 007ccfb6  85f6                 test esi, esi
// 007ccfb8  758c                 jne 0x7ccf46
// 007ccfba  5f                   pop edi
// 007ccfbb  5e                   pop esi
// 007ccfbc  5d                   pop ebp
// 007ccfbd  8bc3                 mov eax, ebx
// 007ccfbf  5b                   pop ebx
// 007ccfc0  c3                   ret 
// library lua-5.1/lgc.c (function _luaC_separateudata)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lgc.c
