// from server: 100% by auto
// roc 2009-12 0079cdc0  unit: seg_00790000  size: 147 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0079cdc0
//
// 0079cdc0  81ec10020000         sub esp, 0x210
// 0079cdc6  53                   push ebx
// 0079cdc7  56                   push esi
// 0079cdc8  8bb4241c020000       mov esi, dword ptr [esp + 0x21c]
// 0079cdcf  57                   push edi
// 0079cdd0  8d44240c             lea eax, [esp + 0xc]
// 0079cdd4  50                   push eax
// 0079cdd5  bb01000000           mov ebx, 1
// 0079cdda  53                   push ebx
// 0079cddb  56                   push esi
// 0079cddc  e88fd9feff           call 0x78a770
// 0079cde1  8d4c241c             lea ecx, [esp + 0x1c]
// 0079cde5  51                   push ecx
// 0079cde6  56                   push esi
// 0079cde7  8bf8                 mov edi, eax
// 0079cde9  e842d3feff           call 0x78a130
// 0079cdee  83c414               add esp, 0x14
// 0079cdf1  837c240c00           cmp dword ptr [esp + 0xc], 0
// 0079cdf6  743e                 je 0x79ce36
// 0079cdf8  eb06                 jmp 0x79ce00
// 0079cdfa  8d9b00000000         lea ebx, [ebx]
// 0079ce00  295c240c             sub dword ptr [esp + 0xc], ebx
// 0079ce04  8d94241c020000       lea edx, [esp + 0x21c]
// 0079ce0b  39542410             cmp dword ptr [esp + 0x10], edx
// 0079ce0f  720d                 jb 0x79ce1e
// 0079ce11  8d442410             lea eax, [esp + 0x10]
// 0079ce15  50                   push eax
// 0079ce16  e8b5d1feff           call 0x789fd0
// 0079ce1b  83c404               add esp, 4
// 0079ce1e  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0079ce22  8a1439               mov dl, byte ptr [ecx + edi]
// 0079ce25  8b442410             mov eax, dword ptr [esp + 0x10]
// 0079ce29  8810                 mov byte ptr [eax], dl
// 0079ce2b  015c2410             add dword ptr [esp + 0x10], ebx
// 0079ce2f  837c240c00           cmp dword ptr [esp + 0xc], 0
// 0079ce34  75ca                 jne 0x79ce00
// 0079ce36  295c240c             sub dword ptr [esp + 0xc], ebx
// 0079ce3a  8d4c2410             lea ecx, [esp + 0x10]
// 0079ce3e  51                   push ecx
// 0079ce3f  e82cd2feff           call 0x78a070
// 0079ce44  83c404               add esp, 4
// 0079ce47  5f                   pop edi
// 0079ce48  5e                   pop esi
// 0079ce49  8bc3                 mov eax, ebx
// 0079ce4b  5b                   pop ebx
// 0079ce4c  81c410020000         add esp, 0x210
// 0079ce52  c3                   ret 
// library lua-5.1/lstrlib.c (function _str_reverse)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lstrlib.c
