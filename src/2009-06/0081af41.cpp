// from server: 70% by EspClaude
// from server: 100% by colin
// roc 2008-06 007a5c4f  unit: CXTIconHandle  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 007a5c4f
//
// 007a5c4f  8bff                 mov edi, edi
// 007a5c51  56                   push esi
// 007a5c52  8bf1                 mov esi, ecx
// 007a5c54  8d4e14               lea ecx, [esi + 0x14]
// 007a5c57  e8e4bbc5ff           call 0x401840
// 007a5c5c  33c0                 xor eax, eax
// 007a5c5e  89462c               mov dword ptr [esi + 0x2c], eax
// 007a5c61  894630               mov dword ptr [esi + 0x30], eax
// 007a5c64  894634               mov dword ptr [esi + 0x34], eax
// 007a5c67  8bc6                 mov eax, esi
// 007a5c69  5e                   pop esi
// 007a5c6a  c3                   ret 
// 007a5c6b  8bff                 mov edi, edi
// 007a5c6d  56                   push esi
// 007a5c6e  8bf1                 mov esi, ecx
// 007a5c70  8d4614               lea eax, [esi + 0x14]
// 007a5c73  50                   push eax
// 007a5c74  ff15dc228000         call dword ptr [0x8022dc]
// 007a5c7a  8d4e2c               lea ecx, [esi + 0x2c]
// 007a5c7d  5e                   pop esi
// 007a5c7e  e981ffffff           jmp 0x7a5c04

// from server: 70% by EspClaude
// from server: 61% by atomic.potato
// roc 2008-06 007a5c4f  unit: CXTIconHandle  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 007a5c4f
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-archive: msvc-atlmfc-rtm atls.lib/f:/dd/vctools/vc7libs/ship/atlmfc/src/atl/atls/staticrelease/obj1r/i386/atlbase.obj
