// from server: 100% by auto
// roc 2008-06 0065ec10  unit: seg_00650000  size: 158 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0065ec10
//
// 0065ec10  53                   push ebx
// 0065ec11  55                   push ebp
// 0065ec12  8b6c240c             mov ebp, dword ptr [esp + 0xc]
// 0065ec16  56                   push esi
// 0065ec17  8bf0                 mov esi, eax
// 0065ec19  8bde                 mov ebx, esi
// 0065ec1b  46                   inc esi
// 0065ec1c  56                   push esi
// 0065ec1d  55                   push ebp
// 0065ec1e  e8adfdffff           call 0x65e9d0
// 0065ec23  83c408               add esp, 8
// 0065ec26  83780800             cmp dword ptr [eax + 8], 0
// 0065ec2a  7420                 je 0x65ec4c
// 0065ec2c  8d642400             lea esp, [esp]
// 0065ec30  8bde                 mov ebx, esi
// 0065ec32  03f6                 add esi, esi
// 0065ec34  81fefdffff7f         cmp esi, 0x7ffffffd
// 0065ec3a  7733                 ja 0x65ec6f
// 0065ec3c  56                   push esi
// 0065ec3d  55                   push ebp
// 0065ec3e  e88dfdffff           call 0x65e9d0
// 0065ec43  83c408               add esp, 8
// 0065ec46  83780800             cmp dword ptr [eax + 8], 0
// 0065ec4a  75e4                 jne 0x65ec30
// 0065ec4c  8bc6                 mov eax, esi
// 0065ec4e  2bc3                 sub eax, ebx
// 0065ec50  83f801               cmp eax, 1
// 0065ec53  7653                 jbe 0x65eca8
// 0065ec55  57                   push edi
// 0065ec56  8d3c33               lea edi, [ebx + esi]
// 0065ec59  d1ef                 shr edi, 1
// 0065ec5b  57                   push edi
// 0065ec5c  55                   push ebp
// 0065ec5d  e86efdffff           call 0x65e9d0
// 0065ec62  83c408               add esp, 8
// 0065ec65  83780800             cmp dword ptr [eax + 8], 0
// 0065ec69  7531                 jne 0x65ec9c
// 0065ec6b  8bf7                 mov esi, edi
// 0065ec6d  eb2f                 jmp 0x65ec9e
// 0065ec6f  be01000000           mov esi, 1
// 0065ec74  56                   push esi
// 0065ec75  55                   push ebp
// 0065ec76  e855fdffff           call 0x65e9d0
// 0065ec7b  83c408               add esp, 8
// 0065ec7e  83780800             cmp dword ptr [eax + 8], 0
// 0065ec82  7411                 je 0x65ec95
// 0065ec84  46                   inc esi
// 0065ec85  56                   push esi
// 0065ec86  55                   push ebp
// 0065ec87  e844fdffff           call 0x65e9d0
// 0065ec8c  83c408               add esp, 8
// 0065ec8f  83780800             cmp dword ptr [eax + 8], 0
// 0065ec93  75ef                 jne 0x65ec84
// 0065ec95  8d46ff               lea eax, [esi - 1]
// 0065ec98  5e                   pop esi
// 0065ec99  5d                   pop ebp
// 0065ec9a  5b                   pop ebx
// 0065ec9b  c3                   ret 
// 0065ec9c  8bdf                 mov ebx, edi
// 0065ec9e  8bce                 mov ecx, esi
// 0065eca0  2bcb                 sub ecx, ebx
// 0065eca2  83f901               cmp ecx, 1
// 0065eca5  77af                 ja 0x65ec56
// 0065eca7  5f                   pop edi
// 0065eca8  5e                   pop esi
// 0065eca9  5d                   pop ebp
// 0065ecaa  8bc3                 mov eax, ebx
// 0065ecac  5b                   pop ebx
// 0065ecad  c3                   ret 
// library lua-5.1/ltable.c (function _unbound_search)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 ltable.c
