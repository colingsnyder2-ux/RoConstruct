// from server: 100% by auto
// roc 2011-06 007d9b20  unit: seg_007d0000  size: 158 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 007d9b20
//
// 007d9b20  53                   push ebx
// 007d9b21  55                   push ebp
// 007d9b22  8b6c240c             mov ebp, dword ptr [esp + 0xc]
// 007d9b26  56                   push esi
// 007d9b27  8bf0                 mov esi, eax
// 007d9b29  8bde                 mov ebx, esi
// 007d9b2b  46                   inc esi
// 007d9b2c  56                   push esi
// 007d9b2d  55                   push ebp
// 007d9b2e  e89dfdffff           call 0x7d98d0
// 007d9b33  83c408               add esp, 8
// 007d9b36  83780800             cmp dword ptr [eax + 8], 0
// 007d9b3a  7420                 je 0x7d9b5c
// 007d9b3c  8d642400             lea esp, [esp]
// 007d9b40  8bde                 mov ebx, esi
// 007d9b42  03f6                 add esi, esi
// 007d9b44  81fefdffff7f         cmp esi, 0x7ffffffd
// 007d9b4a  7733                 ja 0x7d9b7f
// 007d9b4c  56                   push esi
// 007d9b4d  55                   push ebp
// 007d9b4e  e87dfdffff           call 0x7d98d0
// 007d9b53  83c408               add esp, 8
// 007d9b56  83780800             cmp dword ptr [eax + 8], 0
// 007d9b5a  75e4                 jne 0x7d9b40
// 007d9b5c  8bc6                 mov eax, esi
// 007d9b5e  2bc3                 sub eax, ebx
// 007d9b60  83f801               cmp eax, 1
// 007d9b63  7653                 jbe 0x7d9bb8
// 007d9b65  57                   push edi
// 007d9b66  8d3c33               lea edi, [ebx + esi]
// 007d9b69  d1ef                 shr edi, 1
// 007d9b6b  57                   push edi
// 007d9b6c  55                   push ebp
// 007d9b6d  e85efdffff           call 0x7d98d0
// 007d9b72  83c408               add esp, 8
// 007d9b75  83780800             cmp dword ptr [eax + 8], 0
// 007d9b79  7531                 jne 0x7d9bac
// 007d9b7b  8bf7                 mov esi, edi
// 007d9b7d  eb2f                 jmp 0x7d9bae
// 007d9b7f  be01000000           mov esi, 1
// 007d9b84  56                   push esi
// 007d9b85  55                   push ebp
// 007d9b86  e845fdffff           call 0x7d98d0
// 007d9b8b  83c408               add esp, 8
// 007d9b8e  83780800             cmp dword ptr [eax + 8], 0
// 007d9b92  7411                 je 0x7d9ba5
// 007d9b94  46                   inc esi
// 007d9b95  56                   push esi
// 007d9b96  55                   push ebp
// 007d9b97  e834fdffff           call 0x7d98d0
// 007d9b9c  83c408               add esp, 8
// 007d9b9f  83780800             cmp dword ptr [eax + 8], 0
// 007d9ba3  75ef                 jne 0x7d9b94
// 007d9ba5  8d46ff               lea eax, [esi - 1]
// 007d9ba8  5e                   pop esi
// 007d9ba9  5d                   pop ebp
// 007d9baa  5b                   pop ebx
// 007d9bab  c3                   ret 
// 007d9bac  8bdf                 mov ebx, edi
// 007d9bae  8bce                 mov ecx, esi
// 007d9bb0  2bcb                 sub ecx, ebx
// 007d9bb2  83f901               cmp ecx, 1
// 007d9bb5  77af                 ja 0x7d9b66
// 007d9bb7  5f                   pop edi
// 007d9bb8  5e                   pop esi
// 007d9bb9  5d                   pop ebp
// 007d9bba  8bc3                 mov eax, ebx
// 007d9bbc  5b                   pop ebx
// 007d9bbd  c3                   ret 
// library lua-5.1/ltable.c (function _unbound_search)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 ltable.c
