// roc 2012-06 00832020  unit: RBX::PAVPrimitive::$$A6AXU?$pair::?$signal::Vslot::?$callable  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00832020
//
// 00832020  56                   push esi
// 00832021  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00832025  57                   push edi
// 00832026  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0083202a  8bc6                 mov eax, esi
// 0083202c  8bcf                 mov ecx, edi
// 0083202e  e80df9ffff           call 0x831940
// 00832033  8b4808               mov ecx, dword ptr [eax + 8]
// 00832036  83c1fe               add ecx, -2
// 00832039  83f906               cmp ecx, 6
// 0083203c  772a                 ja 0x832068
// 0083203e  ff248d70208300       jmp dword ptr [ecx*4 + 0x832070]
// 00832045  8b00                 mov eax, dword ptr [eax]
// 00832047  5f                   pop edi
// 00832048  5e                   pop esi
// 00832049  c3                   ret 
// 0083204a  8bc6                 mov eax, esi
// 0083204c  8bcf                 mov ecx, edi
// 0083204e  e8edf8ffff           call 0x831940
// 00832053  8b4808               mov ecx, dword ptr [eax + 8]
// 00832056  83e902               sub ecx, 2
// 00832059  74ea                 je 0x832045
// 0083205b  83e905               sub ecx, 5
// 0083205e  7508                 jne 0x832068
// 00832060  8b00                 mov eax, dword ptr [eax]
// 00832062  5f                   pop edi
// 00832063  83c018               add eax, 0x18
// 00832066  5e                   pop esi
// 00832067  c3                   ret 
// 00832068  5f                   pop edi
// 00832069  33c0                 xor eax, eax
// 0083206b  5e                   pop esi
// 0083206c  c3                   ret 
// 0083206d  8d4900               lea ecx, [ecx]
// 00832070  4a                   dec edx
// 00832071  208300682083         and byte ptr [ebx - 0x7cdf9800], al
// 00832077  006820               add byte ptr [eax + 0x20], ch
// 0083207a  830045               add dword ptr [eax], 0x45
// 0083207d  208300452083         and byte ptr [ebx - 0x7cdfbb00], al
// 00832083  004a20               add byte ptr [edx + 0x20], cl
// 00832086  830045               add dword ptr [eax], 0x45
// library lua-5.1/lapi.c (function _lua_topointer)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
