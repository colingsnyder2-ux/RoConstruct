// from server: 100% by auto
// roc 2009-12 007ce410  unit: RBX::PartDropTool  size: 115 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007ce410
//
// 007ce410  55                   push ebp
// 007ce411  8b6c240c             mov ebp, dword ptr [esp + 0xc]
// 007ce415  56                   push esi
// 007ce416  57                   push edi
// 007ce417  8bf0                 mov esi, eax
// 007ce419  8b442410             mov eax, dword ptr [esp + 0x10]
// 007ce41d  55                   push ebp
// 007ce41e  50                   push eax
// 007ce41f  56                   push esi
// 007ce420  e85bfaffff           call 0x7cde80
// 007ce425  8bf8                 mov edi, eax
// 007ce427  83c40c               add esp, 0xc
// 007ce42a  837f0800             cmp dword ptr [edi + 8], 0
// 007ce42e  7507                 jne 0x7ce437
// 007ce430  5f                   pop edi
// 007ce431  5e                   pop esi
// 007ce432  83c8ff               or eax, 0xffffffff
// 007ce435  5d                   pop ebp
// 007ce436  c3                   ret 
// 007ce437  55                   push ebp
// 007ce438  53                   push ebx
// 007ce439  56                   push esi
// 007ce43a  e841faffff           call 0x7cde80
// 007ce43f  50                   push eax
// 007ce440  57                   push edi
// 007ce441  e8eabcfcff           call 0x79a130
// 007ce446  83c414               add esp, 0x14
// 007ce449  85c0                 test eax, eax
// 007ce44b  74e3                 je 0x7ce430
// 007ce44d  8b542410             mov edx, dword ptr [esp + 0x10]
// 007ce451  8b4608               mov eax, dword ptr [esi + 8]
// 007ce454  57                   push edi
// 007ce455  56                   push esi
// 007ce456  8bcb                 mov ecx, ebx
// 007ce458  e8d3fbffff           call 0x7ce030
// 007ce45d  8b7608               mov esi, dword ptr [esi + 8]
// 007ce460  8b4608               mov eax, dword ptr [esi + 8]
// 007ce463  83c408               add esp, 8
// 007ce466  85c0                 test eax, eax
// 007ce468  7413                 je 0x7ce47d
// 007ce46a  83f801               cmp eax, 1
// 007ce46d  7505                 jne 0x7ce474
// 007ce46f  833e00               cmp dword ptr [esi], 0
// 007ce472  7409                 je 0x7ce47d
// 007ce474  5f                   pop edi
// 007ce475  5e                   pop esi
// 007ce476  b801000000           mov eax, 1
// 007ce47b  5d                   pop ebp
// 007ce47c  c3                   ret 
// 007ce47d  5f                   pop edi
// 007ce47e  5e                   pop esi
// 007ce47f  33c0                 xor eax, eax
// 007ce481  5d                   pop ebp
// 007ce482  c3                   ret 
// library lua-5.1/lvm.c (function _call_orderTM)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lvm.c
