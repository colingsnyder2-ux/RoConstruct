// from server: 100% by auto
// roc 2012-06 00935c30  unit: RBX::BallCellContact  size: 158 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00935c30
//
// 00935c30  53                   push ebx
// 00935c31  55                   push ebp
// 00935c32  8b6c240c             mov ebp, dword ptr [esp + 0xc]
// 00935c36  56                   push esi
// 00935c37  8bf0                 mov esi, eax
// 00935c39  8bde                 mov ebx, esi
// 00935c3b  46                   inc esi
// 00935c3c  56                   push esi
// 00935c3d  55                   push ebp
// 00935c3e  e89dfdffff           call 0x9359e0
// 00935c43  83c408               add esp, 8
// 00935c46  83780800             cmp dword ptr [eax + 8], 0
// 00935c4a  7420                 je 0x935c6c
// 00935c4c  8d642400             lea esp, [esp]
// 00935c50  8bde                 mov ebx, esi
// 00935c52  03f6                 add esi, esi
// 00935c54  81fefdffff7f         cmp esi, 0x7ffffffd
// 00935c5a  7733                 ja 0x935c8f
// 00935c5c  56                   push esi
// 00935c5d  55                   push ebp
// 00935c5e  e87dfdffff           call 0x9359e0
// 00935c63  83c408               add esp, 8
// 00935c66  83780800             cmp dword ptr [eax + 8], 0
// 00935c6a  75e4                 jne 0x935c50
// 00935c6c  8bc6                 mov eax, esi
// 00935c6e  2bc3                 sub eax, ebx
// 00935c70  83f801               cmp eax, 1
// 00935c73  7653                 jbe 0x935cc8
// 00935c75  57                   push edi
// 00935c76  8d3c33               lea edi, [ebx + esi]
// 00935c79  d1ef                 shr edi, 1
// 00935c7b  57                   push edi
// 00935c7c  55                   push ebp
// 00935c7d  e85efdffff           call 0x9359e0
// 00935c82  83c408               add esp, 8
// 00935c85  83780800             cmp dword ptr [eax + 8], 0
// 00935c89  7531                 jne 0x935cbc
// 00935c8b  8bf7                 mov esi, edi
// 00935c8d  eb2f                 jmp 0x935cbe
// 00935c8f  be01000000           mov esi, 1
// 00935c94  56                   push esi
// 00935c95  55                   push ebp
// 00935c96  e845fdffff           call 0x9359e0
// 00935c9b  83c408               add esp, 8
// 00935c9e  83780800             cmp dword ptr [eax + 8], 0
// 00935ca2  7411                 je 0x935cb5
// 00935ca4  46                   inc esi
// 00935ca5  56                   push esi
// 00935ca6  55                   push ebp
// 00935ca7  e834fdffff           call 0x9359e0
// 00935cac  83c408               add esp, 8
// 00935caf  83780800             cmp dword ptr [eax + 8], 0
// 00935cb3  75ef                 jne 0x935ca4
// 00935cb5  8d46ff               lea eax, [esi - 1]
// 00935cb8  5e                   pop esi
// 00935cb9  5d                   pop ebp
// 00935cba  5b                   pop ebx
// 00935cbb  c3                   ret 
// 00935cbc  8bdf                 mov ebx, edi
// 00935cbe  8bce                 mov ecx, esi
// 00935cc0  2bcb                 sub ecx, ebx
// 00935cc2  83f901               cmp ecx, 1
// 00935cc5  77af                 ja 0x935c76
// 00935cc7  5f                   pop edi
// 00935cc8  5e                   pop esi
// 00935cc9  5d                   pop ebp
// 00935cca  8bc3                 mov eax, ebx
// 00935ccc  5b                   pop ebx
// 00935ccd  c3                   ret 
// library lua-5.1/ltable.c (function _unbound_search)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 ltable.c
