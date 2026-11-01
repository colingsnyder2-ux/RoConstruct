// from server: 100% by auto
// roc 2009-12 007d04a0  unit: RBX::PartDropTool  size: 158 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007d04a0
//
// 007d04a0  53                   push ebx
// 007d04a1  55                   push ebp
// 007d04a2  8b6c240c             mov ebp, dword ptr [esp + 0xc]
// 007d04a6  56                   push esi
// 007d04a7  8bf0                 mov esi, eax
// 007d04a9  8bde                 mov ebx, esi
// 007d04ab  46                   inc esi
// 007d04ac  56                   push esi
// 007d04ad  55                   push ebp
// 007d04ae  e89dfdffff           call 0x7d0250
// 007d04b3  83c408               add esp, 8
// 007d04b6  83780800             cmp dword ptr [eax + 8], 0
// 007d04ba  7420                 je 0x7d04dc
// 007d04bc  8d642400             lea esp, [esp]
// 007d04c0  8bde                 mov ebx, esi
// 007d04c2  03f6                 add esi, esi
// 007d04c4  81fefdffff7f         cmp esi, 0x7ffffffd
// 007d04ca  7733                 ja 0x7d04ff
// 007d04cc  56                   push esi
// 007d04cd  55                   push ebp
// 007d04ce  e87dfdffff           call 0x7d0250
// 007d04d3  83c408               add esp, 8
// 007d04d6  83780800             cmp dword ptr [eax + 8], 0
// 007d04da  75e4                 jne 0x7d04c0
// 007d04dc  8bc6                 mov eax, esi
// 007d04de  2bc3                 sub eax, ebx
// 007d04e0  83f801               cmp eax, 1
// 007d04e3  7653                 jbe 0x7d0538
// 007d04e5  57                   push edi
// 007d04e6  8d3c33               lea edi, [ebx + esi]
// 007d04e9  d1ef                 shr edi, 1
// 007d04eb  57                   push edi
// 007d04ec  55                   push ebp
// 007d04ed  e85efdffff           call 0x7d0250
// 007d04f2  83c408               add esp, 8
// 007d04f5  83780800             cmp dword ptr [eax + 8], 0
// 007d04f9  7531                 jne 0x7d052c
// 007d04fb  8bf7                 mov esi, edi
// 007d04fd  eb2f                 jmp 0x7d052e
// 007d04ff  be01000000           mov esi, 1
// 007d0504  56                   push esi
// 007d0505  55                   push ebp
// 007d0506  e845fdffff           call 0x7d0250
// 007d050b  83c408               add esp, 8
// 007d050e  83780800             cmp dword ptr [eax + 8], 0
// 007d0512  7411                 je 0x7d0525
// 007d0514  46                   inc esi
// 007d0515  56                   push esi
// 007d0516  55                   push ebp
// 007d0517  e834fdffff           call 0x7d0250
// 007d051c  83c408               add esp, 8
// 007d051f  83780800             cmp dword ptr [eax + 8], 0
// 007d0523  75ef                 jne 0x7d0514
// 007d0525  8d46ff               lea eax, [esi - 1]
// 007d0528  5e                   pop esi
// 007d0529  5d                   pop ebp
// 007d052a  5b                   pop ebx
// 007d052b  c3                   ret 
// 007d052c  8bdf                 mov ebx, edi
// 007d052e  8bce                 mov ecx, esi
// 007d0530  2bcb                 sub ecx, ebx
// 007d0532  83f901               cmp ecx, 1
// 007d0535  77af                 ja 0x7d04e6
// 007d0537  5f                   pop edi
// 007d0538  5e                   pop esi
// 007d0539  5d                   pop ebp
// 007d053a  8bc3                 mov eax, ebx
// 007d053c  5b                   pop ebx
// 007d053d  c3                   ret 
// library lua-5.1/ltable.c (function _unbound_search)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 ltable.c
