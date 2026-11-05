// from server: 100% by auto
// roc 2009-12 007dc800  unit: RBX::GroupDragTool  size: 91 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007dc800
//
// 007dc800  c1e009               shl eax, 9
// 007dc803  0b44240c             or eax, dword ptr [esp + 0xc]
// 007dc807  56                   push esi
// 007dc808  c1e008               shl eax, 8
// 007dc80b  0b44240c             or eax, dword ptr [esp + 0xc]
// 007dc80f  8bf1                 mov esi, ecx
// 007dc811  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 007dc814  8b5108               mov edx, dword ptr [ecx + 8]
// 007dc817  c1e006               shl eax, 6
// 007dc81a  0b442408             or eax, dword ptr [esp + 8]
// 007dc81e  57                   push edi
// 007dc81f  52                   push edx
// 007dc820  50                   push eax
// 007dc821  e83afdffff           call 0x7dc560
// 007dc826  8b7e20               mov edi, dword ptr [esi + 0x20]
// 007dc829  8b460c               mov eax, dword ptr [esi + 0xc]
// 007dc82c  c74620ffffffff       mov dword ptr [esi + 0x20], 0xffffffff
// 007dc833  8b4808               mov ecx, dword ptr [eax + 8]
// 007dc836  51                   push ecx
// 007dc837  681680ff7f           push 0x7fff8016
// 007dc83c  e81ffdffff           call 0x7dc560
// 007dc841  57                   push edi
// 007dc842  8d542428             lea edx, [esp + 0x28]
// 007dc846  52                   push edx
// 007dc847  56                   push esi
// 007dc848  89442430             mov dword ptr [esp + 0x30], eax
// 007dc84c  e87ff8ffff           call 0x7dc0d0
// 007dc851  8b442430             mov eax, dword ptr [esp + 0x30]
// 007dc855  83c41c               add esp, 0x1c
// 007dc858  5f                   pop edi
// 007dc859  5e                   pop esi
// 007dc85a  c3                   ret 
// library lua-5.1/lcode.c (function _condjump)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lcode.c
