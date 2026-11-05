// roc 2009-12 007cd5e0  unit: RBX::PartDropTool  size: 148 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007cd5e0
//
// 007cd5e0  0fb65004             movzx edx, byte ptr [eax + 4]
// 007cd5e4  83c2fc               add edx, -4
// 007cd5e7  83fa06               cmp edx, 6
// 007cd5ea  776b                 ja 0x7cd657
// 007cd5ec  ff249558d67c00       jmp dword ptr [edx*4 + 0x7cd658]
// 007cd5f3  50                   push eax
// 007cd5f4  51                   push ecx
// 007cd5f5  e8a6390000           call 0x7d0fa0
// 007cd5fa  83c408               add esp, 8
// 007cd5fd  c3                   ret 
// 007cd5fe  50                   push eax
// 007cd5ff  51                   push ecx
// 007cd600  e83b3a0000           call 0x7d1040
// 007cd605  83c408               add esp, 8
// 007cd608  c3                   ret 
// 007cd609  50                   push eax
// 007cd60a  51                   push ecx
// 007cd60b  e840380000           call 0x7d0e50
// 007cd610  83c408               add esp, 8
// 007cd613  c3                   ret 
// 007cd614  50                   push eax
// 007cd615  51                   push ecx
// 007cd616  e8d52b0000           call 0x7d01f0
// 007cd61b  83c408               add esp, 8
// 007cd61e  c3                   ret 
// 007cd61f  50                   push eax
// 007cd620  51                   push ecx
// 007cd621  e89ae3fcff           call 0x79b9c0
// 007cd626  83c408               add esp, 8
// 007cd629  c3                   ret 
// 007cd62a  8b5110               mov edx, dword ptr [ecx + 0x10]
// 007cd62d  ff4a04               dec dword ptr [edx + 4]
// 007cd630  8b500c               mov edx, dword ptr [eax + 0xc]
// 007cd633  6a00                 push 0
// 007cd635  83c211               add edx, 0x11
// 007cd638  52                   push edx
// 007cd639  50                   push eax
// 007cd63a  51                   push ecx
// 007cd63b  e870410000           call 0x7d17b0
// 007cd640  83c410               add esp, 0x10
// 007cd643  c3                   ret 
// 007cd644  8b5010               mov edx, dword ptr [eax + 0x10]
// 007cd647  6a00                 push 0
// 007cd649  83c218               add edx, 0x18
// 007cd64c  52                   push edx
// 007cd64d  50                   push eax
// 007cd64e  51                   push ecx
// 007cd64f  e85c410000           call 0x7d17b0
// 007cd654  83c410               add esp, 0x10
// 007cd657  c3                   ret 
// 007cd658  2ad6                 sub dl, dh
// 007cd65a  7c00                 jl 0x7cd65c
// 007cd65c  14d6                 adc al, 0xd6
// 007cd65e  7c00                 jl 0x7cd660
// library lua-5.1/lgc.c (function _freeobj)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lgc.c
