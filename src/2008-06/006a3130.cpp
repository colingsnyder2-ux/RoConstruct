// from server: 100% by auto
// roc 2008-06 006a3130  unit: CRobloxControlColorSelector  size: 80 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006a3130
//
// 006a3130  53                   push ebx
// 006a3131  56                   push esi
// 006a3132  8bf1                 mov esi, ecx
// 006a3134  57                   push edi
// 006a3135  8b7e04               mov edi, dword ptr [esi + 4]
// 006a3138  33db                 xor ebx, ebx
// 006a313a  3bfb                 cmp edi, ebx
// 006a313c  7421                 je 0x6a315f
// 006a313e  395e08               cmp dword ptr [esi + 8], ebx
// 006a3141  761c                 jbe 0x6a315f
// 006a3143  8b5608               mov edx, dword ptr [esi + 8]
// 006a3146  8bcf                 mov ecx, edi
// 006a3148  8b01                 mov eax, dword ptr [ecx]
// 006a314a  3bc3                 cmp eax, ebx
// 006a314c  7409                 je 0x6a3157
// 006a314e  8bff                 mov edi, edi
// 006a3150  8b4008               mov eax, dword ptr [eax + 8]
// 006a3153  3bc3                 cmp eax, ebx
// 006a3155  75f9                 jne 0x6a3150
// 006a3157  83c104               add ecx, 4
// 006a315a  83ea01               sub edx, 1
// 006a315d  75e9                 jne 0x6a3148
// 006a315f  57                   push edi
// 006a3160  e8e5d7ffff           call 0x6a094a
// 006a3165  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 006a3168  83c404               add esp, 4
// 006a316b  895e04               mov dword ptr [esi + 4], ebx
// 006a316e  895e0c               mov dword ptr [esi + 0xc], ebx
// 006a3171  895e10               mov dword ptr [esi + 0x10], ebx
// 006a3174  e89fdfffff           call 0x6a1118
// 006a3179  5f                   pop edi
// 006a317a  895e14               mov dword ptr [esi + 0x14], ebx
// 006a317d  5e                   pop esi
// 006a317e  5b                   pop ebx
// 006a317f  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ?RemoveAll@?$CMap@PAUHICON__@@PAU1@HH@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
