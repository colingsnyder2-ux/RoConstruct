// from server: 100% by auto
// roc 2009-06 00811910  unit: CXTPRibbonGroup  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00811910
//
// 00811910  53                   push ebx
// 00811911  55                   push ebp
// 00811912  57                   push edi
// 00811913  8be9                 mov ebp, ecx
// 00811915  e826ffffff           call 0x811840
// 0081191a  6a01                 push 1
// 0081191c  33ff                 xor edi, edi
// 0081191e  57                   push edi
// 0081191f  8bcd                 mov ecx, ebp
// 00811921  8bd8                 mov ebx, eax
// 00811923  e878f8ffff           call 0x8111a0
// 00811928  83f802               cmp eax, 2
// 0081192b  7d06                 jge 0x811933
// 0081192d  5f                   pop edi
// 0081192e  5d                   pop ebp
// 0081192f  33c0                 xor eax, eax
// 00811931  5b                   pop ebx
// 00811932  c3                   ret 
// 00811933  7447                 je 0x81197c
// 00811935  85db                 test ebx, ebx
// 00811937  7e43                 jle 0x81197c
// 00811939  56                   push esi
// 0081193a  8d9b00000000         lea ebx, [ebx]
// 00811940  8d041f               lea eax, [edi + ebx]
// 00811943  99                   cdq 
// 00811944  2bc2                 sub eax, edx
// 00811946  8bf0                 mov esi, eax
// 00811948  6a01                 push 1
// 0081194a  d1fe                 sar esi, 1
// 0081194c  56                   push esi
// 0081194d  8bcd                 mov ecx, ebp
// 0081194f  e84cf8ffff           call 0x8111a0
// 00811954  83f802               cmp eax, 2
// 00811957  7f04                 jg 0x81195d
// 00811959  8bde                 mov ebx, esi
// 0081195b  eb06                 jmp 0x811963
// 0081195d  3bfe                 cmp edi, esi
// 0081195f  7410                 je 0x811971
// 00811961  8bfe                 mov edi, esi
// 00811963  3bfb                 cmp edi, ebx
// 00811965  7cd9                 jl 0x811940
// 00811967  5e                   pop esi
// 00811968  5f                   pop edi
// 00811969  5d                   pop ebp
// 0081196a  b801000000           mov eax, 1
// 0081196f  5b                   pop ebx
// 00811970  c3                   ret 
// 00811971  6a01                 push 1
// 00811973  53                   push ebx
// 00811974  8bcd                 mov ecx, ebp
// 00811976  e825f8ffff           call 0x8111a0
// 0081197b  5e                   pop esi
// 0081197c  5f                   pop edi
// 0081197d  5d                   pop ebp
// 0081197e  b801000000           mov eax, 1
// 00811983  5b                   pop ebx
// 00811984  c3                   ret 
// library xtp-15.2.1/Source\Ribbon\XTPRibbonGroups.cpp (function ?_FindBestWrapSpecialDynamicSize@CXTPRibbonGroup@@AAEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Ribbon/XTPRibbonGroups.cpp
