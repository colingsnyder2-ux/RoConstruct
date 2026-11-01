// from server: 100% by auto
// roc 2007-08 005bdae0  unit: RBX::VPVInstance::?$EnumPropDescriptor  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005bdae0
//
// 005bdae0  56                   push esi
// 005bdae1  8b74240c             mov esi, dword ptr [esp + 0xc]
// 005bdae5  57                   push edi
// 005bdae6  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 005bdaea  8bc6                 mov eax, esi
// 005bdaec  8bcf                 mov ecx, edi
// 005bdaee  e83df9ffff           call 0x5bd430
// 005bdaf3  8b4808               mov ecx, dword ptr [eax + 8]
// 005bdaf6  83c1fe               add ecx, -2
// 005bdaf9  83f906               cmp ecx, 6
// 005bdafc  772a                 ja 0x5bdb28
// 005bdafe  ff248d30db5b00       jmp dword ptr [ecx*4 + 0x5bdb30]
// 005bdb05  8b00                 mov eax, dword ptr [eax]
// 005bdb07  5f                   pop edi
// 005bdb08  5e                   pop esi
// 005bdb09  c3                   ret 
// 005bdb0a  8bc6                 mov eax, esi
// 005bdb0c  8bcf                 mov ecx, edi
// 005bdb0e  e81df9ffff           call 0x5bd430
// 005bdb13  8b4808               mov ecx, dword ptr [eax + 8]
// 005bdb16  83e902               sub ecx, 2
// 005bdb19  74ea                 je 0x5bdb05
// 005bdb1b  83e905               sub ecx, 5
// 005bdb1e  7508                 jne 0x5bdb28
// 005bdb20  8b00                 mov eax, dword ptr [eax]
// 005bdb22  5f                   pop edi
// 005bdb23  83c018               add eax, 0x18
// 005bdb26  5e                   pop esi
// 005bdb27  c3                   ret 
// 005bdb28  5f                   pop edi
// 005bdb29  33c0                 xor eax, eax
// 005bdb2b  5e                   pop esi
// 005bdb2c  c3                   ret 
// 005bdb2d  8d4900               lea ecx, [ecx]
// 005bdb30  0adb                 or bl, bl
// 005bdb32  5b                   pop ebx
// 005bdb33  0028                 add byte ptr [eax], ch
// 005bdb35  db5b00               fistp dword ptr [ebx]
// 005bdb38  28db                 sub bl, bl
// 005bdb3a  5b                   pop ebx
// 005bdb3b  0005db5b0005         add byte ptr [0x5005bdb], al
// 005bdb41  db5b00               fistp dword ptr [ebx]
// 005bdb44  0adb                 or bl, bl
// 005bdb46  5b                   pop ebx
// library lua-5.1/lapi.c (function _lua_topointer)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
