// from server: 100% by auto
// roc 2010-06 0077d6f0  unit: RBX::PartDropTool  size: 158 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0077d6f0
//
// 0077d6f0  53                   push ebx
// 0077d6f1  55                   push ebp
// 0077d6f2  8b6c240c             mov ebp, dword ptr [esp + 0xc]
// 0077d6f6  56                   push esi
// 0077d6f7  8bf0                 mov esi, eax
// 0077d6f9  8bde                 mov ebx, esi
// 0077d6fb  46                   inc esi
// 0077d6fc  56                   push esi
// 0077d6fd  55                   push ebp
// 0077d6fe  e89dfdffff           call 0x77d4a0
// 0077d703  83c408               add esp, 8
// 0077d706  83780800             cmp dword ptr [eax + 8], 0
// 0077d70a  7420                 je 0x77d72c
// 0077d70c  8d642400             lea esp, [esp]
// 0077d710  8bde                 mov ebx, esi
// 0077d712  03f6                 add esi, esi
// 0077d714  81fefdffff7f         cmp esi, 0x7ffffffd
// 0077d71a  7733                 ja 0x77d74f
// 0077d71c  56                   push esi
// 0077d71d  55                   push ebp
// 0077d71e  e87dfdffff           call 0x77d4a0
// 0077d723  83c408               add esp, 8
// 0077d726  83780800             cmp dword ptr [eax + 8], 0
// 0077d72a  75e4                 jne 0x77d710
// 0077d72c  8bc6                 mov eax, esi
// 0077d72e  2bc3                 sub eax, ebx
// 0077d730  83f801               cmp eax, 1
// 0077d733  7653                 jbe 0x77d788
// 0077d735  57                   push edi
// 0077d736  8d3c33               lea edi, [ebx + esi]
// 0077d739  d1ef                 shr edi, 1
// 0077d73b  57                   push edi
// 0077d73c  55                   push ebp
// 0077d73d  e85efdffff           call 0x77d4a0
// 0077d742  83c408               add esp, 8
// 0077d745  83780800             cmp dword ptr [eax + 8], 0
// 0077d749  7531                 jne 0x77d77c
// 0077d74b  8bf7                 mov esi, edi
// 0077d74d  eb2f                 jmp 0x77d77e
// 0077d74f  be01000000           mov esi, 1
// 0077d754  56                   push esi
// 0077d755  55                   push ebp
// 0077d756  e845fdffff           call 0x77d4a0
// 0077d75b  83c408               add esp, 8
// 0077d75e  83780800             cmp dword ptr [eax + 8], 0
// 0077d762  7411                 je 0x77d775
// 0077d764  46                   inc esi
// 0077d765  56                   push esi
// 0077d766  55                   push ebp
// 0077d767  e834fdffff           call 0x77d4a0
// 0077d76c  83c408               add esp, 8
// 0077d76f  83780800             cmp dword ptr [eax + 8], 0
// 0077d773  75ef                 jne 0x77d764
// 0077d775  8d46ff               lea eax, [esi - 1]
// 0077d778  5e                   pop esi
// 0077d779  5d                   pop ebp
// 0077d77a  5b                   pop ebx
// 0077d77b  c3                   ret 
// 0077d77c  8bdf                 mov ebx, edi
// 0077d77e  8bce                 mov ecx, esi
// 0077d780  2bcb                 sub ecx, ebx
// 0077d782  83f901               cmp ecx, 1
// 0077d785  77af                 ja 0x77d736
// 0077d787  5f                   pop edi
// 0077d788  5e                   pop esi
// 0077d789  5d                   pop ebp
// 0077d78a  8bc3                 mov eax, ebx
// 0077d78c  5b                   pop ebx
// 0077d78d  c3                   ret 
// library lua-5.1/ltable.c (function _unbound_search)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 ltable.c
