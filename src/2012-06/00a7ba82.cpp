// roc 2012-06 00a7ba82  unit: CXTIconHandle  size: 181 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a7ba82
//
// 00a7ba82  6a0c                 push 0xc
// 00a7ba84  ff158023b200         call dword ptr [0xb22380]
// 00a7ba8a  85c0                 test eax, eax
// 00a7ba8c  7507                 jne 0xa7ba95
// 00a7ba8e  40                   inc eax
// 00a7ba8f  a3b8a4e500           mov dword ptr [0xe5a4b8], eax
// 00a7ba94  c3                   ret 
// 00a7ba95  53                   push ebx
// 00a7ba96  56                   push esi
// 00a7ba97  57                   push edi
// 00a7ba98  68cc2db700           push 0xb72dcc
// 00a7ba9d  ff154822b200         call dword ptr [0xb22248]
// 00a7baa3  8bf8                 mov edi, eax
// 00a7baa5  33db                 xor ebx, ebx
// 00a7baa7  3bfb                 cmp edi, ebx
// 00a7baa9  7420                 je 0xa7bacb
// 00a7baab  8b35b021b200         mov esi, dword ptr [0xb221b0]
// 00a7bab1  6824bbc200           push 0xc2bb24
// 00a7bab6  57                   push edi
// 00a7bab7  ffd6                 call esi
// 00a7bab9  6808bbc200           push 0xc2bb08
// 00a7babe  57                   push edi
// 00a7babf  a3bca4e500           mov dword ptr [0xe5a4bc], eax
// 00a7bac4  ffd6                 call esi
// 00a7bac6  a3c0a4e500           mov dword ptr [0xe5a4c0], eax
// 00a7bacb  391dbca4e500         cmp dword ptr [0xe5a4bc], ebx
// 00a7bad1  745e                 je 0xa7bb31
// 00a7bad3  391dc0a4e500         cmp dword ptr [0xe5a4c0], ebx
// 00a7bad9  7456                 je 0xa7bb31
// 00a7badb  64a118000000         mov eax, dword ptr fs:[0x18]
// 00a7bae1  8b7030               mov esi, dword ptr [eax + 0x30]
// 00a7bae4  83c634               add esi, 0x34
// 00a7bae7  8b06                 mov eax, dword ptr [esi]
// 00a7bae9  3bc3                 cmp eax, ebx
// 00a7baeb  753a                 jne 0xa7bb27
// 00a7baed  6a08                 push 8
// 00a7baef  53                   push ebx
// 00a7baf0  8b1dac22b200         mov ebx, dword ptr [0xb222ac]
// 00a7baf6  ffd3                 call ebx
// 00a7baf8  50                   push eax
// 00a7baf9  ff15a422b200         call dword ptr [0xb222a4]
// 00a7baff  8bf8                 mov edi, eax
// 00a7bb01  33c0                 xor eax, eax
// 00a7bb03  3bf8                 cmp edi, eax
// 00a7bb05  742a                 je 0xa7bb31
// 00a7bb07  50                   push eax
// 00a7bb08  57                   push edi
// 00a7bb09  56                   push esi
// 00a7bb0a  8907                 mov dword ptr [edi], eax
// 00a7bb0c  894704               mov dword ptr [edi + 4], eax
// 00a7bb0f  ff15f821b200         call dword ptr [0xb221f8]
// 00a7bb15  85c0                 test eax, eax
// 00a7bb17  740c                 je 0xa7bb25
// 00a7bb19  57                   push edi
// 00a7bb1a  6a00                 push 0
// 00a7bb1c  ffd3                 call ebx
// 00a7bb1e  50                   push eax
// 00a7bb1f  ff15a822b200         call dword ptr [0xb222a8]
// 00a7bb25  8b06                 mov eax, dword ptr [esi]
// 00a7bb27  a3b8a4e500           mov dword ptr [0xe5a4b8], eax
// 00a7bb2c  33c0                 xor eax, eax
// 00a7bb2e  40                   inc eax
// 00a7bb2f  eb02                 jmp 0xa7bb33
// 00a7bb31  33c0                 xor eax, eax
// 00a7bb33  5f                   pop edi
// 00a7bb34  5e                   pop esi
// 00a7bb35  5b                   pop ebx
// 00a7bb36  c3                   ret 
// copied from an identical function in another client (function ?__InitializeThunkPool@@YAHXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-archive: msvc-atlmfc-rtm atls.lib/f:/dd/vctools/vc7libs/ship/atlmfc/src/atl/atls/staticrelease/obj1r/i386/atlthunk.obj