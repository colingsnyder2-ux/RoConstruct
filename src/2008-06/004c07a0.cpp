// from server: 100% by auto
// roc 2008-06 004c07a0  unit: ProfiledRakPeer  size: 199 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004c07a0
//
// 004c07a0  81ecc0000000         sub esp, 0xc0
// 004c07a6  33c0                 xor eax, eax
// 004c07a8  56                   push esi
// 004c07a9  57                   push edi
// 004c07aa  8944240c             mov dword ptr [esp + 0xc], eax
// 004c07ae  89442410             mov dword ptr [esp + 0x10], eax
// 004c07b2  89442414             mov dword ptr [esp + 0x14], eax
// 004c07b6  89442418             mov dword ptr [esp + 0x18], eax
// 004c07ba  8944241c             mov dword ptr [esp + 0x1c], eax
// 004c07be  89442420             mov dword ptr [esp + 0x20], eax
// 004c07c2  89442424             mov dword ptr [esp + 0x24], eax
// 004c07c6  c744240801000000     mov dword ptr [esp + 8], 1
// 004c07ce  b908000000           mov ecx, 8
// 004c07d3  8d742408             lea esi, [esp + 8]
// 004c07d7  8d7c2468             lea edi, [esp + 0x68]
// 004c07db  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 004c07dd  8bb424cc000000       mov esi, dword ptr [esp + 0xcc]
// 004c07e4  b908000000           mov ecx, 8
// 004c07e9  8d7c2408             lea edi, [esp + 8]
// 004c07ed  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 004c07ef  89442448             mov dword ptr [esp + 0x48], eax
// 004c07f3  8944244c             mov dword ptr [esp + 0x4c], eax
// 004c07f7  89442450             mov dword ptr [esp + 0x50], eax
// 004c07fb  89442454             mov dword ptr [esp + 0x54], eax
// 004c07ff  89442458             mov dword ptr [esp + 0x58], eax
// 004c0803  8944245c             mov dword ptr [esp + 0x5c], eax
// 004c0807  89442460             mov dword ptr [esp + 0x60], eax
// 004c080b  89442464             mov dword ptr [esp + 0x64], eax
// 004c080f  89442428             mov dword ptr [esp + 0x28], eax
// 004c0813  8944242c             mov dword ptr [esp + 0x2c], eax
// 004c0817  89442430             mov dword ptr [esp + 0x30], eax
// 004c081b  89442434             mov dword ptr [esp + 0x34], eax
// 004c081f  89442438             mov dword ptr [esp + 0x38], eax
// 004c0823  8944243c             mov dword ptr [esp + 0x3c], eax
// 004c0827  89442440             mov dword ptr [esp + 0x40], eax
// 004c082b  89442444             mov dword ptr [esp + 0x44], eax
// 004c082f  8d842488000000       lea eax, [esp + 0x88]
// 004c0836  50                   push eax
// 004c0837  8d4c240c             lea ecx, [esp + 0xc]
// 004c083b  51                   push ecx
// 004c083c  8d542450             lea edx, [esp + 0x50]
// 004c0840  52                   push edx
// 004c0841  e83ad7ffff           call 0x4bdf80
// 004c0846  8bbc24dc000000       mov edi, dword ptr [esp + 0xdc]
// 004c084d  83c40c               add esp, 0xc
// 004c0850  b908000000           mov ecx, 8
// 004c0855  8db42488000000       lea esi, [esp + 0x88]
// 004c085c  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 004c085e  5f                   pop edi
// 004c085f  5e                   pop esi
// 004c0860  81c4c0000000         add esp, 0xc0
// 004c0866  c3                   ret 
// library openrbx-raknet/RakPeer.cpp (function ??$rModn@$$BY07I@big@@YAXAAY07I0@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
